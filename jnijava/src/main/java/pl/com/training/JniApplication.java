package pl.com.training;

public class JniApplication {

	static {
		System.loadLibrary("jni-native"); // hello.dll (Windows) or libhello.so (Unixes)
	}

	public static void main(String[] args) {
		TestJNI testJNI = new TestJNI();

		testJNI.helloWorld();
		System.out.println(testJNI.returnHelloWorld());
		System.out.println(testJNI.sayHelloToName("Foo"));

		User user = new User("John Foo", 10);
		testJNI.sayHelloToUser(user);

		User user2 = testJNI.createUser();
		System.out.println("Created user in c = " + user2);
	}
}
