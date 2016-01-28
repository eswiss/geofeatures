//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2012. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_INTERPROCESS_FWD_HPP
#define BOOST_INTERPROCESS_FWD_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost/config.hpp>
#endif
#
#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost/interprocess/detail/std_fwd.hpp>

//! \file
//! This header file forward declares the basic interprocess types:
//!   - geofeatures_boost::interprocess::offset_ptr;
//!   - geofeatures_boost::interprocess::permissions;
//!   - geofeatures_boost::interprocess::mapped_region;
//!   - geofeatures_boost::interprocess::file_mapping;
//!   - geofeatures_boost::interprocess::shared_memory_object;
//!   - geofeatures_boost::interprocess::windows_shared_memory;
//!   - geofeatures_boost::interprocess::xsi_shared_memory;
//!
//! The following synchronization mechanisms and locks:
//!   - geofeatures_boost::interprocess::null_mutex;
//!   - geofeatures_boost::interprocess::interprocess_mutex;
//!   - geofeatures_boost::interprocess::interprocess_recursive_mutex;
//!   - geofeatures_boost::interprocess::interprocess_semaphore;
//!   - geofeatures_boost::interprocess::named_mutex;
//!   - geofeatures_boost::interprocess::named_recursive_mutex;
//!   - geofeatures_boost::interprocess::named_semaphore;
//!   - geofeatures_boost::interprocess::interprocess_sharable_mutex;
//!   - geofeatures_boost::interprocess::interprocess_condition;
//!   - geofeatures_boost::interprocess::scoped_lock;
//!   - geofeatures_boost::interprocess::sharable_lock;
//!   - geofeatures_boost::interprocess::upgradable_lock;
//!
//! The following mutex families:
//!   - geofeatures_boost::interprocess::mutex_family;
//!   - geofeatures_boost::interprocess::null_mutex_family;
//!
//! The following allocators:
//!   - geofeatures_boost::interprocess::allocator;
//!   - geofeatures_boost::interprocess::node_allocator;
//!   - geofeatures_boost::interprocess::private_node_allocator;
//!   - geofeatures_boost::interprocess::cached_node_allocator;
//!   - geofeatures_boost::interprocess::adaptive_pool;
//!   - geofeatures_boost::interprocess::private_adaptive_pool;
//!   - geofeatures_boost::interprocess::cached_adaptive_pool;
//!
//! The following allocation algorithms:
//!   - geofeatures_boost::interprocess::simple_seq_fit;
//!   - geofeatures_boost::interprocess::rbtree_best_fit;
//!
//! The following index types:
//!   - geofeatures_boost::interprocess::flat_map_index;
//!   - geofeatures_boost::interprocess::iset_index;
//!   - geofeatures_boost::interprocess::iunordered_set_index;
//!   - geofeatures_boost::interprocess::map_index;
//!   - geofeatures_boost::interprocess::null_index;
//!   - geofeatures_boost::interprocess::unordered_map_index;
//!
//! The following managed memory types:
//!   - geofeatures_boost::interprocess::segment_manager;
//!   - geofeatures_boost::interprocess::basic_managed_external_buffer
//!   - geofeatures_boost::interprocess::managed_external_buffer
//!   - geofeatures_boost::interprocess::wmanaged_external_buffer
//!   - geofeatures_boost::interprocess::basic_managed_shared_memory
//!   - geofeatures_boost::interprocess::managed_shared_memory
//!   - geofeatures_boost::interprocess::wmanaged_shared_memory
//!   - geofeatures_boost::interprocess::basic_managed_windows_shared_memory
//!   - geofeatures_boost::interprocess::managed_windows_shared_memory
//!   - geofeatures_boost::interprocess::wmanaged_windows_shared_memory
//!   - geofeatures_boost::interprocess::basic_managed_xsi_shared_memory
//!   - geofeatures_boost::interprocess::managed_xsi_shared_memory
//!   - geofeatures_boost::interprocess::wmanaged_xsi_shared_memory
//!   - geofeatures_boost::interprocess::fixed_managed_shared_memory
//!   - geofeatures_boost::interprocess::wfixed_managed_shared_memory
//!   - geofeatures_boost::interprocess::basic_managed_heap_memory
//!   - geofeatures_boost::interprocess::managed_heap_memory
//!   - geofeatures_boost::interprocess::wmanaged_heap_memory
//!   - geofeatures_boost::interprocess::basic_managed_mapped_file
//!   - geofeatures_boost::interprocess::managed_mapped_file
//!   - geofeatures_boost::interprocess::wmanaged_mapped_file
//!
//! The following exception types:
//!   - geofeatures_boost::interprocess::interprocess_exception
//!   - geofeatures_boost::interprocess::lock_exception
//!   - geofeatures_boost::interprocess::bad_alloc
//!
//! The following stream types:
//!   - geofeatures_boost::interprocess::basic_bufferbuf
//!   - geofeatures_boost::interprocess::basic_ibufferstream
//!   - geofeatures_boost::interprocess::basic_obufferstream
//!   - geofeatures_boost::interprocess::basic_bufferstream
//!   - geofeatures_boost::interprocess::basic_vectorbuf
//!   - geofeatures_boost::interprocess::basic_ivectorstream
//!   - geofeatures_boost::interprocess::basic_ovectorstream
//!   - geofeatures_boost::interprocess::basic_vectorstream
//!
//! The following smart pointer types:
//!   - geofeatures_boost::interprocess::scoped_ptr
//!   - geofeatures_boost::interprocess::intrusive_ptr
//!   - geofeatures_boost::interprocess::shared_ptr
//!   - geofeatures_boost::interprocess::weak_ptr
//!
//! The following interprocess communication types:
//!   - geofeatures_boost::interprocess::message_queue_t;
//!   - geofeatures_boost::interprocess::message_queue;

#include <boost/interprocess/detail/config_begin.hpp>
#include <boost/interprocess/detail/workaround.hpp>

#if !defined(BOOST_INTERPROCESS_DOXYGEN_INVOKED)

#include <cstddef>

//////////////////////////////////////////////////////////////////////////////
//                        Standard predeclarations
//////////////////////////////////////////////////////////////////////////////

namespace geofeatures_boost {} namespace boost = geofeatures_boost; namespace geofeatures_boost{  namespace intrusive{ }  }
namespace geofeatures_boost {} namespace boost = geofeatures_boost; namespace geofeatures_boost{  namespace interprocess{ namespace bi = geofeatures_boost::intrusive; }  }

namespace geofeatures_boost {} namespace boost = geofeatures_boost; namespace geofeatures_boost { namespace interprocess {

//////////////////////////////////////////////////////////////////////////////
//                            permissions
//////////////////////////////////////////////////////////////////////////////

class permissions;

//////////////////////////////////////////////////////////////////////////////
//                            shared_memory
//////////////////////////////////////////////////////////////////////////////

class shared_memory_object;

#if defined (BOOST_INTERPROCESS_WINDOWS)
class windows_shared_memory;
#endif   //#if defined (BOOST_INTERPROCESS_WINDOWS)

#if defined(BOOST_INTERPROCESS_XSI_SHARED_MEMORY_OBJECTS)
class xsi_shared_memory;
#endif   //#if defined (BOOST_INTERPROCESS_WINDOWS)

//////////////////////////////////////////////////////////////////////////////
//              file mapping / mapped region
//////////////////////////////////////////////////////////////////////////////

class file_mapping;
class mapped_region;

//////////////////////////////////////////////////////////////////////////////
//                               Mutexes
//////////////////////////////////////////////////////////////////////////////

class null_mutex;

class interprocess_mutex;
class interprocess_recursive_mutex;

class named_mutex;
class named_recursive_mutex;

class interprocess_semaphore;
class named_semaphore;

//////////////////////////////////////////////////////////////////////////////
//                         Mutex families
//////////////////////////////////////////////////////////////////////////////

struct mutex_family;
struct null_mutex_family;

//////////////////////////////////////////////////////////////////////////////
//                   Other synchronization classes
//////////////////////////////////////////////////////////////////////////////

class interprocess_sharable_mutex;
class interprocess_condition;

//////////////////////////////////////////////////////////////////////////////
//                              Locks
//////////////////////////////////////////////////////////////////////////////

template <class Mutex>
class scoped_lock;

template <class SharableMutex>
class sharable_lock;

template <class UpgradableMutex>
class upgradable_lock;

//////////////////////////////////////////////////////////////////////////////
//                      STL compatible allocators
//////////////////////////////////////////////////////////////////////////////

template<class T, class SegmentManager>
class allocator;

template<class T, class SegmentManager, std::size_t NodesPerBlock = 64>
class node_allocator;

template<class T, class SegmentManager, std::size_t NodesPerBlock = 64>
class private_node_allocator;

template<class T, class SegmentManager, std::size_t NodesPerBlock = 64>
class cached_node_allocator;

template< class T, class SegmentManager, std::size_t NodesPerBlock = 64
        , std::size_t MaxFreeBlocks = 2, unsigned char OverheadPercent = 5 >
class adaptive_pool;

template< class T, class SegmentManager, std::size_t NodesPerBlock = 64
        , std::size_t MaxFreeBlocks = 2, unsigned char OverheadPercent = 5 >
class private_adaptive_pool;

template< class T, class SegmentManager, std::size_t NodesPerBlock = 64
        , std::size_t MaxFreeBlocks = 2, unsigned char OverheadPercent = 5 >
class cached_adaptive_pool;


//////////////////////////////////////////////////////////////////////////////
//                            offset_ptr
//////////////////////////////////////////////////////////////////////////////

static const std::size_t offset_type_alignment = 0;

template < class T, class DifferenceType = std::ptrdiff_t
         , class OffsetType = std::size_t, std::size_t Alignment = offset_type_alignment>
class offset_ptr;

//////////////////////////////////////////////////////////////////////////////
//                    Memory allocation algorithms
//////////////////////////////////////////////////////////////////////////////

//Single segment memory allocation algorithms
template<class MutexFamily, class VoidMutex = offset_ptr<void> >
class simple_seq_fit;

template<class MutexFamily, class VoidMutex = offset_ptr<void>, std::size_t MemAlignment = 0>
class rbtree_best_fit;

//////////////////////////////////////////////////////////////////////////////
//                         Index Types
//////////////////////////////////////////////////////////////////////////////

template<class IndexConfig> class flat_map_index;
template<class IndexConfig> class iset_index;
template<class IndexConfig> class iunordered_set_index;
template<class IndexConfig> class map_index;
template<class IndexConfig> class null_index;
template<class IndexConfig> class unordered_map_index;

//////////////////////////////////////////////////////////////////////////////
//                         Segment manager
//////////////////////////////////////////////////////////////////////////////

template <class CharType
         ,class MemoryAlgorithm
         ,template<class IndexConfig> class IndexType>
class segment_manager;

//////////////////////////////////////////////////////////////////////////////
//                  External buffer managed memory classes
//////////////////////////////////////////////////////////////////////////////

template <class CharType
         ,class MemoryAlgorithm
         ,template<class IndexConfig> class IndexType>
class basic_managed_external_buffer;

typedef basic_managed_external_buffer
   <char
   ,rbtree_best_fit<null_mutex_family>
   ,iset_index>
managed_external_buffer;

typedef basic_managed_external_buffer
   <wchar_t
   ,rbtree_best_fit<null_mutex_family>
   ,iset_index>
wmanaged_external_buffer;

//////////////////////////////////////////////////////////////////////////////
//                      managed memory classes
//////////////////////////////////////////////////////////////////////////////

template <class CharType
         ,class MemoryAlgorithm
         ,template<class IndexConfig> class IndexType>
class basic_managed_shared_memory;

typedef basic_managed_shared_memory
   <char
   ,rbtree_best_fit<mutex_family>
   ,iset_index>
managed_shared_memory;

typedef basic_managed_shared_memory
   <wchar_t
   ,rbtree_best_fit<mutex_family>
   ,iset_index>
wmanaged_shared_memory;


//////////////////////////////////////////////////////////////////////////////
//                      Windows shared memory managed memory classes
//////////////////////////////////////////////////////////////////////////////

#if defined (BOOST_INTERPROCESS_WINDOWS)

template <class CharType
         ,class MemoryAlgorithm
         ,template<class IndexConfig> class IndexType>
class basic_managed_windows_shared_memory;

typedef basic_managed_windows_shared_memory
   <char
   ,rbtree_best_fit<mutex_family>
   ,iset_index>
managed_windows_shared_memory;

typedef basic_managed_windows_shared_memory
   <wchar_t
   ,rbtree_best_fit<mutex_family>
   ,iset_index>
wmanaged_windows_shared_memory;

#endif   //#if defined (BOOST_INTERPROCESS_WINDOWS)

#if defined(BOOST_INTERPROCESS_XSI_SHARED_MEMORY_OBJECTS)

template <class CharType
         ,class MemoryAlgorithm
         ,template<class IndexConfig> class IndexType>
class basic_managed_xsi_shared_memory;

typedef basic_managed_xsi_shared_memory
   <char
   ,rbtree_best_fit<mutex_family>
   ,iset_index>
managed_xsi_shared_memory;

typedef basic_managed_xsi_shared_memory
   <wchar_t
   ,rbtree_best_fit<mutex_family>
   ,iset_index>
wmanaged_xsi_shared_memory;

#endif //#if defined(BOOST_INTERPROCESS_XSI_SHARED_MEMORY_OBJECTS)

//////////////////////////////////////////////////////////////////////////////
//                      Fixed address shared memory
//////////////////////////////////////////////////////////////////////////////

typedef basic_managed_shared_memory
   <char
   ,rbtree_best_fit<mutex_family, void*>
   ,iset_index>
fixed_managed_shared_memory;

typedef basic_managed_shared_memory
   <wchar_t
   ,rbtree_best_fit<mutex_family, void*>
   ,iset_index>
wfixed_managed_shared_memory;

//////////////////////////////////////////////////////////////////////////////
//                      Heap memory managed memory classes
//////////////////////////////////////////////////////////////////////////////

template
   <class CharType
   ,class MemoryAlgorithm
   ,template<class IndexConfig> class IndexType>
class basic_managed_heap_memory;

typedef basic_managed_heap_memory
   <char
   ,rbtree_best_fit<null_mutex_family>
   ,iset_index>
managed_heap_memory;

typedef basic_managed_heap_memory
   <wchar_t
   ,rbtree_best_fit<null_mutex_family>
   ,iset_index>
wmanaged_heap_memory;

//////////////////////////////////////////////////////////////////////////////
//                         Mapped file managed memory classes
//////////////////////////////////////////////////////////////////////////////

template
   <class CharType
   ,class MemoryAlgorithm
   ,template<class IndexConfig> class IndexType>
class basic_managed_mapped_file;

typedef basic_managed_mapped_file
   <char
   ,rbtree_best_fit<mutex_family>
   ,iset_index>
managed_mapped_file;

typedef basic_managed_mapped_file
   <wchar_t
   ,rbtree_best_fit<mutex_family>
   ,iset_index>
wmanaged_mapped_file;

//////////////////////////////////////////////////////////////////////////////
//                            Exceptions
//////////////////////////////////////////////////////////////////////////////

class interprocess_exception;
class lock_exception;
class bad_alloc;

//////////////////////////////////////////////////////////////////////////////
//                            Bufferstream
//////////////////////////////////////////////////////////////////////////////

//bufferstream
template <class CharT
         ,class CharTraits = std::char_traits<CharT> >
class basic_bufferbuf;

template <class CharT
         ,class CharTraits = std::char_traits<CharT> >
class basic_ibufferstream;

template <class CharT
         ,class CharTraits = std::char_traits<CharT> >
class basic_obufferstream;

template <class CharT
         ,class CharTraits = std::char_traits<CharT> >
class basic_bufferstream;

//////////////////////////////////////////////////////////////////////////////
//                            Vectorstream
//////////////////////////////////////////////////////////////////////////////

template <class CharVector
         ,class CharTraits = std::char_traits<typename CharVector::value_type> >
class basic_vectorbuf;

template <class CharVector
         ,class CharTraits = std::char_traits<typename CharVector::value_type> >
class basic_ivectorstream;

template <class CharVector
         ,class CharTraits = std::char_traits<typename CharVector::value_type> >
class basic_ovectorstream;

template <class CharVector
         ,class CharTraits = std::char_traits<typename CharVector::value_type> >
class basic_vectorstream;

//////////////////////////////////////////////////////////////////////////////
//                             Smart pointers
//////////////////////////////////////////////////////////////////////////////

template<class T, class Deleter>
class scoped_ptr;

template<class T, class VoidPointer>
class intrusive_ptr;

template<class T, class VoidAllocator, class Deleter>
class shared_ptr;

template<class T, class VoidAllocator, class Deleter>
class weak_ptr;

//////////////////////////////////////////////////////////////////////////////
//                                  IPC
//////////////////////////////////////////////////////////////////////////////

template<class VoidPointer>
class message_queue_t;

typedef message_queue_t<offset_ptr<void> > message_queue;

}}  //namespace geofeatures_boost {} namespace boost = geofeatures_boost; namespace geofeatures_boost { namespace interprocess {

#endif   //#if !defined(BOOST_INTERPROCESS_DOXYGEN_INVOKED)

#include <boost/interprocess/detail/config_end.hpp>

#endif //#ifndef BOOST_INTERPROCESS_FWD_HPP
