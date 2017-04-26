package pl.com.training;

public class TestJNI {

    public native void helloWorld();

    public native String returnHelloWorld();

    public native String sayHelloToName(String name);

    public native User createUser();

    public native void sayHelloToUser(User user);
}
