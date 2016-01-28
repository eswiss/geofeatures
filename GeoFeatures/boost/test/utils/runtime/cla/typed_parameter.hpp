//  (C) Copyright Gennadiy Rozental 2005-2014.
//  Use, modification, and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision$
//
//  Description : generic typed parameter model
// ***************************************************************************

#ifndef BOOST_TEST_UTILS_RUNTIME_CLA_TYPED_PARAMETER_HPP
#define BOOST_TEST_UTILS_RUNTIME_CLA_TYPED_PARAMETER_HPP

// Boost.Runtime.Parameter
#include <boost/test/utils/runtime/config.hpp>

#include <boost/test/utils/runtime/fwd.hpp>
#include <boost/test/utils/runtime/validation.hpp>

#include <boost/test/utils/runtime/cla/parameter.hpp>
#include <boost/test/utils/runtime/cla/argument_factory.hpp>

// Boost.Test
#include <boost/test/utils/rtti.hpp>

namespace geofeatures_boost {} namespace boost = geofeatures_boost; namespace geofeatures_boost {

namespace BOOST_TEST_UTILS_RUNTIME_PARAM_NAMESPACE {

namespace cla {

// ************************************************************************** //
// **************         runtime::cla::typed_parameter        ************** //
// ************************************************************************** //

template<typename T>
class typed_parameter : public cla::parameter {
public:
    explicit typed_parameter( identification_policy& ID )
    : cla::parameter( ID, m_arg_factory, rtti::type_id<T>() == rtti::type_id<bool>() )
    {}

    // parameter properties modification
    template<typename Modifier>
    void    accept_modifier( Modifier const& m )
    {
        cla::parameter::accept_modifier( m );

        m_arg_factory.accept_modifier( m );

        BOOST_TEST_UTILS_RUNTIME_PARAM_VALIDATE_LOGIC( !p_optional || !m_arg_factory.m_value_generator,
            BOOST_TEST_UTILS_RUNTIME_PARAM_LITERAL( "can't define a value generator for optional parameter " ) << id_2_report() );
    }

private:
    // Data members
    typed_argument_factory<T>   m_arg_factory;
};

} // namespace cla

} // namespace BOOST_TEST_UTILS_RUNTIME_PARAM_NAMESPACE

} // namespace geofeatures_boost

#endif // BOOST_TEST_UTILS_RUNTIME_CLA_TYPED_PARAMETER_HPP
