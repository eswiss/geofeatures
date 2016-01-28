//  (C) Copyright Jeremy Siek 2004
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROPERTY_HPP
#define BOOST_PROPERTY_HPP

#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/has_xxx.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits.hpp>
#include <boost/static_assert.hpp>

namespace geofeatures_boost {} namespace boost = geofeatures_boost; namespace geofeatures_boost {

  struct no_property {};

  template <class Tag, class T, class Base = no_property>
  struct property {
    typedef Base next_type;
    typedef Tag tag_type;
    typedef T value_type;
    property(const T& v = T()) : m_value(v) { }
    property(const T& v, const Base& b) : m_value(v), m_base(b) { }
    // copy constructor and assignment operator will be generated by compiler

    T m_value;
    Base m_base;
  };

  // Kinds of properties
  namespace graph_introspect_detail {
    BOOST_MPL_HAS_XXX_TRAIT_DEF(kind)
    template <typename T, bool Cond> struct get_kind {typedef void type;};
    template <typename T> struct get_kind<T, true> {typedef typename T::kind type;};
  }

  // Having a default is to make this trait work for any type, not just valid
  // properties, to work around VC++ <= 10 bugs related to SFINAE in
  // compressed_sparse_row_graph's get functions and similar
  template <class PropertyTag>
  struct property_kind:
    graph_introspect_detail::get_kind<PropertyTag, graph_introspect_detail::has_kind<PropertyTag>::value>
  {};

  // Some standard properties defined independently of Boost.Graph:
  enum vertex_all_t {vertex_all};
  enum edge_all_t {edge_all};
  enum graph_all_t {graph_all};
  enum vertex_bundle_t {vertex_bundle};
  enum edge_bundle_t {edge_bundle};
  enum graph_bundle_t {graph_bundle};

  // Code to look up one property in a property list:
  template <typename PList, typename PropName, typename Enable = void>
  struct lookup_one_property_internal {BOOST_STATIC_CONSTANT(bool, found = false); typedef void type;};

  // Special-case properties (vertex_all, edge_all, graph_all)
#define BGL_ALL_PROP(tag) \
  template <typename T> \
  struct lookup_one_property_internal<T, tag> { \
    BOOST_STATIC_CONSTANT(bool, found = true); \
    typedef T type; \
    static T& lookup(T& x, tag) {return x;} \
    static const T& lookup(const T& x, tag) {return x;} \
  }; \
  template <typename Tag, typename T, typename Base> \
  struct lookup_one_property_internal<property<Tag, T, Base>, tag> { /* Avoid ambiguity */ \
    BOOST_STATIC_CONSTANT(bool, found = true); \
    typedef property<Tag, T, Base> type; \
    static type& lookup(type& x, tag) {return x;} \
    static const type& lookup(const type& x, tag) {return x;} \
  };

  BGL_ALL_PROP(vertex_all_t)
  BGL_ALL_PROP(edge_all_t)
  BGL_ALL_PROP(graph_all_t)
#undef BGL_ALL_PROP

  // *_bundled; these need to be macros rather than inheritance to resolve ambiguities
  #define BGL_DO_ONE_BUNDLE_TYPE(kind) \
  template <typename T> \
  struct lookup_one_property_internal<T, BOOST_JOIN(kind, _bundle_t)> { \
    BOOST_STATIC_CONSTANT(bool, found = true); \
    typedef T type; \
    static T& lookup(T& x, BOOST_JOIN(kind, _bundle_t)) {return x;} \
    static const T& lookup(const T& x, BOOST_JOIN(kind, _bundle_t)) {return x;} \
  }; \
 \
  template <typename Tag, typename T, typename Base> \
  struct lookup_one_property_internal<property<Tag, T, Base>, BOOST_JOIN(kind, _bundle_t)>: lookup_one_property_internal<Base, BOOST_JOIN(kind, _bundle_t)> { \
    private: \
    typedef lookup_one_property_internal<Base, BOOST_JOIN(kind, _bundle_t)> base_type; \
    public: \
    template <typename BundleTag> \
    static typename lazy_enable_if_c<(base_type::found && (is_same<BundleTag, BOOST_JOIN(kind, _bundle_t)>::value)), \
                                     add_reference<typename base_type::type> >::type \
    lookup(property<Tag, T, Base>& p, BundleTag) {return base_type::lookup(p.m_base, BOOST_JOIN(kind, _bundle_t)());} \
    template <typename BundleTag> \
    static typename lazy_enable_if_c<(base_type::found && (is_same<BundleTag, BOOST_JOIN(kind, _bundle_t)>::value)), \
                                     add_reference<const typename base_type::type> >::type \
    lookup(const property<Tag, T, Base>& p, BundleTag) {return base_type::lookup(p.m_base, BOOST_JOIN(kind, _bundle_t)());} \
  }; \

  BGL_DO_ONE_BUNDLE_TYPE(vertex)
  BGL_DO_ONE_BUNDLE_TYPE(edge)
  BGL_DO_ONE_BUNDLE_TYPE(graph)
#undef BGL_DO_ONE_BUNDLE_TYPE

  // Normal old-style properties; second case also handles chaining of bundled property accesses
  template <typename Tag, typename T, typename Base>
  struct lookup_one_property_internal<geofeatures_boost::property<Tag, T, Base>, Tag> {
    BOOST_STATIC_CONSTANT(bool, found = true);
    typedef property<Tag, T, Base> prop;
    typedef T type;
    template <typename U>
    static typename enable_if<is_same<prop, U>, T&>::type
    lookup(U& prop, const Tag&) {return prop.m_value;}
    template <typename U>
    static typename enable_if<is_same<prop, U>, const T&>::type
    lookup(const U& prop, const Tag&) {return prop.m_value;}
  };

  template <typename Tag, typename T, typename Base, typename PropName>
  struct lookup_one_property_internal<geofeatures_boost::property<Tag, T, Base>, PropName>: lookup_one_property_internal<Base, PropName> {
    private:
    typedef lookup_one_property_internal<Base, PropName> base_type;
    public:
    template <typename PL>
    static typename lazy_enable_if<is_same<PL, geofeatures_boost::property<Tag, T, Base> >,
                                   add_reference<typename base_type::type> >::type
    lookup(PL& prop, const PropName& tag) {
      return base_type::lookup(prop.m_base, tag);
    }
    template <typename PL>
    static typename lazy_enable_if<is_same<PL, geofeatures_boost::property<Tag, T, Base> >,
                                   add_reference<const typename base_type::type> >::type
    lookup(const PL& prop, const PropName& tag) {
      return base_type::lookup(prop.m_base, tag);
    }
  };

  // Pointer-to-member access to bundled properties
#ifndef BOOST_GRAPH_NO_BUNDLED_PROPERTIES
  template <typename T, typename TMaybeBase, typename R>
  struct lookup_one_property_internal<T, R TMaybeBase::*, typename enable_if<is_base_of<TMaybeBase, T> >::type> {
    BOOST_STATIC_CONSTANT(bool, found = true);
    typedef R type;
    static R& lookup(T& x, R TMaybeBase::*ptr) {return x.*ptr;}
    static const R& lookup(const T& x, R TMaybeBase::*ptr) {return x.*ptr;}
  };
#endif

  // Version of above handling const property lists properly
  template <typename T, typename Tag>
  struct lookup_one_property: lookup_one_property_internal<T, Tag> {};

  template <typename T, typename Tag>
  struct lookup_one_property<const T, Tag> {
    BOOST_STATIC_CONSTANT(bool, found = (lookup_one_property_internal<T, Tag>::found));
    typedef const typename lookup_one_property_internal<T, Tag>::type type;
    template <typename U>
    static typename lazy_enable_if<is_same<T, U>,
                                   add_reference<const typename lookup_one_property_internal<T, Tag>::type> >::type
    lookup(const U& p, Tag tag) {
      return lookup_one_property_internal<T, Tag>::lookup(p, tag);
    }
  };

  // The BGL properties specialize property_kind and
  // property_num, and use enum's for the Property type (see
  // graph/properties.hpp), but the user may want to use a class
  // instead with a nested kind type and num.  Also, we may want to
  // switch BGL back to using class types for properties at some point.

  template <class P>
  struct has_property : geofeatures_boost::mpl::true_ {};
  template <>
  struct has_property<no_property> : geofeatures_boost::mpl::false_ {};

} // namespace geofeatures_boost

#include <boost/pending/detail/property.hpp>

namespace geofeatures_boost {} namespace boost = geofeatures_boost; namespace geofeatures_boost {

  template <class PropertyList, class Tag>
  struct property_value: lookup_one_property<PropertyList, Tag> {};

  template <class PropertyList, class Tag>
  inline typename lookup_one_property<PropertyList, Tag>::type&
  get_property_value(PropertyList& p, Tag tag) {
    return lookup_one_property<PropertyList, Tag>::lookup(p, tag);
  }

  template <class PropertyList, class Tag>
  inline const typename lookup_one_property<PropertyList, Tag>::type&
  get_property_value(const PropertyList& p, Tag tag) {
    return lookup_one_property<PropertyList, Tag>::lookup(p, tag);
  }

 namespace detail {

     /** This trait returns true if T is no_property. */
    template <typename T>
    struct is_no_property
        : mpl::bool_<is_same<T, no_property>::value>
    { };

    template <typename PList, typename Tag>
    class lookup_one_property_f;

    template <typename PList, typename Tag, typename F> struct lookup_one_property_f_result;

    template <typename PList, typename Tag>
    struct lookup_one_property_f_result<PList, Tag, const lookup_one_property_f<PList, Tag>(PList)> {
      typedef typename lookup_one_property<PList, Tag>::type type;
    };

    template <typename PList, typename Tag>
    struct lookup_one_property_f_result<PList, Tag, const lookup_one_property_f<PList, Tag>(PList&)> {
      typedef typename lookup_one_property<PList, Tag>::type& type;
    };

    template <typename PList, typename Tag>
    struct lookup_one_property_f_result<PList, Tag, const lookup_one_property_f<PList, Tag>(const PList&)> {
      typedef const typename lookup_one_property<PList, Tag>::type& type;
    };

    template <typename PList, typename Tag>
    class lookup_one_property_f {
      Tag tag;
      public:
      lookup_one_property_f(Tag tag): tag(tag) {}
      template <typename F> struct result: lookup_one_property_f_result<PList, Tag, F> {};

      typename lookup_one_property_f_result<PList, Tag, const lookup_one_property_f(PList&)>::type
      operator()(PList& pl) const {
        return lookup_one_property<PList, Tag>::lookup(pl, tag);
      }
    };

} // namespace detail

namespace detail {
  // Stuff for directed_graph and undirected_graph to skip over their first
  // vertex_index and edge_index properties when providing vertex_all and
  // edge_all; make sure you know the exact structure of your properties if you
  // use there.
  struct remove_first_property {
    template <typename F>
    struct result {
      typedef typename geofeatures_boost::function_traits<F>::arg1_type a1;
      typedef typename geofeatures_boost::remove_reference<a1>::type non_ref;
      typedef typename non_ref::next_type nx;
      typedef typename geofeatures_boost::mpl::if_<geofeatures_boost::is_const<non_ref>, geofeatures_boost::add_const<nx>, nx>::type with_const;
      typedef typename geofeatures_boost::add_reference<with_const>::type type;
    };
    template <typename Prop>
    typename Prop::next_type& operator()(Prop& p) const {return p.m_base;}
    template <typename Prop>
    const typename Prop::next_type& operator()(const Prop& p) const {return p.m_base;}
  };
}

} // namesapce boost

#endif /* BOOST_PROPERTY_HPP */
