#include "mouse.h"
#include "java/awt/event/mouseevent.h"
#include "jace/MappingUnavailableException.h"

using java::awt::event::MouseEvent;
using jace::MappingUnavailableException;

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(Mouse)
IMPL_RSCLASS_GET(Mouse)

// Remember: these are methods, not fields
void Mouse::mouseClicked(MouseEvent e) {
    jclass mouseClass = Mouse::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(mouseClass, "mouseClicked", "(Ljava/awt/event/MouseEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("Mouse.mouseClicked(MouseEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

void Mouse::mousePressed(MouseEvent e) {
    jclass mouseClass = Mouse::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(mouseClass, "mousePressed", "(Ljava/awt/event/MouseEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("Mouse.mousePressed(MouseEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

void Mouse::mouseReleased(MouseEvent e) {
    jclass mouseClass = Mouse::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(mouseClass, "mouseReleased", "(Ljava/awt/event/MouseEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("Mouse.mouseReleased(MouseEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

void Mouse::mouseMoved(MouseEvent e) {
    jclass mouseClass = Mouse::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(mouseClass, "mouseMoved", "(Ljava/awt/event/MouseEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("Mouse.mouseMoved(MouseEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

void Mouse::mouseEntered(MouseEvent e) {
    jclass mouseClass = Mouse::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(mouseClass, "mouseEntered", "(Ljava/awt/event/MouseEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("Mouse.mouseEntered(MouseEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

void Mouse::mouseExited(MouseEvent e) {
    jclass mouseClass = Mouse::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(mouseClass, "mouseExited", "(Ljava/awt/event/MouseEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("Mouse.mouseExited(MouseEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

void Mouse::mouseDragged(MouseEvent e) {
    jclass mouseClass = Mouse::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(mouseClass, "mouseDragged", "(Ljava/awt/event/MouseEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("Mouse.mouseDragged(MouseEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

void Mouse::mouseWheel(MouseEvent e) {
    jclass mouseClass = Mouse::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(mouseClass, "mouseWheel", "(Ljava/awt/event/MouseEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("Mouse.mouseWheel(MouseEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}


} // namespace bridge
} // namespace api
