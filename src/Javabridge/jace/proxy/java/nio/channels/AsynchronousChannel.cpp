
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_ASYNCHRONOUSCHANNEL_H
#include "jace/proxy/java/nio/channels/AsynchronousChannel.h"
#endif

/**
 * Standard Jace headers needed to implement this class.
 *
 */
#ifndef JACE_JARGUMENTS_H
#include "jace/JArguments.h"
#endif
using jace::JArguments;

#ifndef JACE_JMETHOD_H
#include "jace/JMethod.h"
#endif
using jace::JMethod;

#ifndef JACE_JFIELD_H
#include "jace/JField.h"
#endif
using jace::JField;

#ifndef JACE_JCLASS_IMPL_H
#include "jace/JClassImpl.h"
#endif
using jace::JClassImpl;


/**
 * Headers for the classes that this class uses.
 *
 */
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )

/**
 * The Jace C++ proxy class source for java/nio/channels/AsynchronousChannel.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define AsynchronousChannel_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define AsynchronousChannel_INITIALIZER
#endif

void AsynchronousChannel::close() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "close" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
/**
 * Special no arg constructor for interface virtual inheritance
 *
 */
AsynchronousChannel::AsynchronousChannel() : Object( NO_OP ) { 
}

AsynchronousChannel::AsynchronousChannel( jvalue value ) AsynchronousChannel_INITIALIZER {
  setJavaJniValue( value );
}

AsynchronousChannel::AsynchronousChannel( jobject object ) AsynchronousChannel_INITIALIZER {
  setJavaJniObject( object );
}

AsynchronousChannel::AsynchronousChannel( const AsynchronousChannel& object ) AsynchronousChannel_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

AsynchronousChannel::AsynchronousChannel( const NoOp& noOp ) AsynchronousChannel_INITIALIZER {
}

const JClass* AsynchronousChannel::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/channels/AsynchronousChannel" );
  return &javaClass;
}

const JClass* AsynchronousChannel::getJavaJniClass() const throw ( JNIException ) {
  return AsynchronousChannel::staticGetJavaJniClass();
}

JEnlister< AsynchronousChannel> AsynchronousChannel::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::AsynchronousChannel>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::channels::AsynchronousChannel( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::AsynchronousChannel>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::AsynchronousChannel>& proxy ) : 
    ::jace::proxy::java::nio::channels::AsynchronousChannel( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::AsynchronousChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::channels::AsynchronousChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::AsynchronousChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::channels::AsynchronousChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::AsynchronousChannel>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::AsynchronousChannel>& object ) : 
    ::jace::proxy::java::nio::channels::AsynchronousChannel( object.getJavaJniValue() ), Object( NO_OP ) {

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

