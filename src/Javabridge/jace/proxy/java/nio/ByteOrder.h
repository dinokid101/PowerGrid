
#ifndef JACE_PROXY_JAVA_NIO_BYTEORDER_H
#define JACE_PROXY_JAVA_NIO_BYTEORDER_H

#ifndef JACE_OS_DEP_H
#include "jace/os_dep.h"
#endif

#ifndef JACE_NAMESPACE_H
#include "jace/namespace.h"
#endif

#ifndef JACE_JOBJECT_H
#include "jace/proxy/JObject.h"
#endif

#ifndef JACE_JENLISTER_H
#include "jace/JEnlister.h"
#endif

#ifndef JACE_JARRAY_H
#include "jace/JArray.h"
#endif

#ifndef JACE_JFIELD_PROXY_H
#include "jace/JFieldProxy.h"
#endif

/**
 * The super class for this class.
 *
 */
#ifndef JACE_PROXY_JAVA_LANG_OBJECT_H
#include "jace/proxy/java/lang/Object.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )

/**
 * The Jace C++ proxy class for java/nio/ByteOrder.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class ByteOrder : public virtual ::jace::proxy::java::lang::Object {

public: 

/**
 * nativeOrder
 *
 */
static ::jace::proxy::java::nio::ByteOrder nativeOrder();

/**
 * toString
 *
 */
::jace::proxy::java::lang::String toString();

/**
 * public static final BIG_ENDIAN_Jace
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::nio::ByteOrder > BIG_ENDIAN_Jace();

/**
 * public static final LITTLE_ENDIAN_Jace
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::nio::ByteOrder > LITTLE_ENDIAN_Jace();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
ByteOrder( jvalue value );
ByteOrder( jobject object );
ByteOrder( const ByteOrder& object );
ByteOrder( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< ByteOrder> enlister;
};

END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::nio::ByteOrder>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::nio::ByteOrder>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::ByteOrder>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::nio::ByteOrder>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::ByteOrder( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::ByteOrder>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::ByteOrder>& proxy ) : 
    ::jace::proxy::java::nio::ByteOrder( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::nio::ByteOrder>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::ByteOrder>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::ByteOrder>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::ByteOrder>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::nio::ByteOrder>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::ByteOrder( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::ByteOrder>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::ByteOrder( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::ByteOrder>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::ByteOrder>& object ) : 
    ::jace::proxy::java::nio::ByteOrder( object.getJavaJniValue() ), Object( NO_OP ) {

    fieldID = object.fieldID; 

    if ( object.parent ) {
      JNIEnv* env = ::jace::helper::attach();
      parent = ::jace::helper::newGlobalRef( env, object.parent );
    }
    else {
      parent = 0;
    }

    if ( object.parentClass ) {
      JNIEnv* env = ::jace::helper::attach();
      parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, object.parentClass ) );
    }
    else {
      parentClass = 0;
    }
  }
#endif

END_NAMESPACE( jace )

#endif // #ifndef JACE_PROXY_JAVA_NIO_BYTEORDER_H

