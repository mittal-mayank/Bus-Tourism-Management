package entities;

import runner.Main;

public class Passenger {
	private String name;
	private int age;
	private String gender;
	private String phone;
	private String email;

	Passenger() {
		System.out.println("Enter your details:-");
		System.out.print("Name: ");
		name = Main.scan.next();
		System.out.print("Age: ");
		age = Main.scan.nextInt();
		System.out.print("Gender: ");
		gender = Main.scan.next();
		System.out.print("Phone No: ");
		phone = Main.scan.next();
		System.out.print("E-mail: ");
		email = Main.scan.next();
	}

	void displayPassenger() {
		System.out.println("Name: " + name);
		System.out.println("Age: " + age);
		System.out.println("Gender: " + gender);
		System.out.println("Phone No: " + phone);
		System.out.println("E-mail: " + email);
	}
}
