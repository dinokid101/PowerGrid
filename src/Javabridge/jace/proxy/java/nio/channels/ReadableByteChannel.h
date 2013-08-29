
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_READABLEBYTECHANNEL_H
#define JACE_PROXY_JAVA_NIO_CHANNELS_READABLEBYTECHANNEL_H

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
 * The interfaces implemented by this class.
 *
 */
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_CHANNEL_H
#include "jace/proxy/java/nio/channels/Channel.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )
class ByteBuffer;
END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class IOException;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )

/**
 * The Jace C++ proxy class for java/nio/channels/ReadableByteChannel.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class ReadableByteChannel : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::nio::channels::Channel {

public: 

/**
 * read
 *
 */
::jace::proxy::types::JInt read( ::jace::proxy::java::nio::ByteBuffer p0 );

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
/**
 * Special no arg constructor for interface virtual inheritance
 *
 */
ReadableByteChannel();
ReadableByteChannel( jvalue value );
ReadableByteChannel( jobject object );
ReadableByteChannel( const ReadableByteChannel& object );
ReadableByteChannel( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< ReadableByteChannel> enlister;
};

END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::nio::channels::ReadableByteChannel>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::nio::channels::ReadableByteChannel>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::ReadableByteChannel>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::ReadableByteChannel>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::channels::ReadableByteChannel( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::ReadableByteChannel>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::ReadableByteChannel>& proxy ) : 
    ::jace::proxy::java::nio::channels::ReadableByteChannel( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::nio::channels::ReadableByteChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::channels::ReadableByteChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::channels::ReadableByteChannel>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::ReadableByteChannel>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::ReadableByteChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::channels::ReadableByteChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::ReadableByteChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::channels::ReadableByteChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::ReadableByteChannel>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::ReadableByteChannel>& object ) : 
    ::jace::proxy::java::nio::channels::ReadableByteChannel( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_NIO_CHANNELS_READABLEBYTECHANNEL_H

