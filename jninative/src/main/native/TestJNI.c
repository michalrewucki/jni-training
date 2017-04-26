#include <jni.h>
#include <string.h>
#include "TestJNI.h"

JNIEXPORT void JNICALL Java_pl_com_training_TestJNI_helloWorld(JNIEnv * env, jobject self) {
    printf("Hello world printed in c!\n");
}

JNIEXPORT jstring JNICALL Java_pl_com_training_TestJNI_returnHelloWorld(JNIEnv * env, jobject self) {
    return (*env)->NewStringUTF(env, "Hello world returned from c!");
}

JNIEXPORT jstring JNICALL Java_pl_com_training_TestJNI_sayHelloToName(JNIEnv * env, jobject self, jstring name) {
    const char *cName = (*env)->GetStringUTFChars(env, name, NULL);
    char msg[120] = "Hello ";
    char regards[10] = " from c!";
    strcat(msg, cName);
    strcat(msg, regards);

    return (*env)->NewStringUTF(env, msg);
}

JNIEXPORT jobject JNICALL Java_pl_com_training_TestJNI_createUser(JNIEnv * env, jobject self) {
    jclass userClass = (*env)->FindClass(env, "pl/com/training/User");
    jmethodID userConstructor = (*env)->GetMethodID(env, userClass, "<init>", "(Ljava/lang/String;I)V");

    jstring name = (*env)->NewStringUTF(env, "cFoo");

    jvalue *args;
    args = malloc(2 * sizeof(jvalue));

    args[0].l = (jobject) name;
    args[1].i = 5;

    return (*env)->NewObjectA(env, userClass, userConstructor, args);
}

JNIEXPORT void JNICALL Java_pl_com_training_TestJNI_sayHelloToUser(JNIEnv * env, jobject self, jobject user) {
    jclass userClass = (*env)->GetObjectClass(env, user);
    jmethodID toStringMethod = (*env)->GetMethodID(env, userClass, "toString", "()Ljava/lang/String;");
    jstring toStringObject = (jstring) ((*env)->CallObjectMethod(env, user, toStringMethod));
    const char *userToString = (*env)->GetStringUTFChars(env, toStringObject,  NULL);

    char msg[120] = "Hello from c! ";
    strcat(msg, userToString);
    strcat(msg, "\n");
    printf(msg);
}