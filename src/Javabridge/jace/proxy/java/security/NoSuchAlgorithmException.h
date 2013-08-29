
#ifndef JACE_PROXY_JAVA_SECURITY_NOSUCHALGORITHMEXCEPTION_H
#define JACE_PROXY_JAVA_SECURITY_NOSUCHALGORITHMEXCEPTION_H

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
#ifndef JACE_PROXY_JAVA_SECURITY_GENERALSECURITYEXCEPTION_H
#include "jace/proxy/java/security/GeneralSecurityException.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Throwable;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, security )

/**
 * The Jace C++ proxy class for java/security/NoSuchAlgorithmException.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class NoSuchAlgorithmException : public ::jace::proxy::java::security::GeneralSecurityException {

public: 

/**
 * NoSuchAlgorithmException
 *
 */
NoSuchAlgorithmException();

/**
 * NoSuchAlgorithmException
 *
 */
NoSuchAlgorithmException( ::jace::proxy::java::lang::String p0 );

/**
 * NoSuchAlgorithmException
 *
 */
NoSuchAlgorithmException( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::Throwable p1 );

/**
 * NoSuchAlgorithmException
 *
 */
NoSuchAlgorithmException( ::jace::proxy::java::lang::Throwable p0 );

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
NoSuchAlgorithmException( jvalue value );
NoSuchAlgorithmException( jobject object );
NoSuchAlgorithmException( const NoSuchAlgorithmException& object );
NoSuchAlgorithmException( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< NoSuchAlgorithmException> enlister;
};

END_NAMESPACE_4( jace, proxy, java, security )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::security::NoSuchAlgorithmException>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::security::NoSuchAlgorithmException>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::security::NoSuchAlgorithmException>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::security::NoSuchAlgorithmException>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::security::NoSuchAlgorithmException( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::security::NoSuchAlgorithmException>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::security::NoSuchAlgorithmException>& proxy ) : 
    ::jace::proxy::java::security::NoSuchAlgorithmException( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::security::NoSuchAlgorithmException>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::security::NoSuchAlgorithmException>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::security::NoSuchAlgorithmException>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::security::NoSuchAlgorithmException>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::security::NoSuchAlgorithmException>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::security::NoSuchAlgorithmException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::NoSuchAlgorithmException>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::security::NoSuchAlgorithmException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::NoSuchAlgorithmException>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::security::NoSuchAlgorithmException>& object ) : 
    ::jace::proxy::java::security::NoSuchAlgorithmException( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_SECURITY_NOSUCHALGORITHMEXCEPTION_H

