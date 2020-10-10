package customer;

import java.util.Scanner;

public class Passenger {
	String name;
	int age;
	String gender;
	String phone;
	String email;

	public Passenger(Scanner scan) {
		System.out.print("Name: ");
		name = scan.next();
		System.out.print("Age: ");
		age = scan.nextInt();
		System.out.print("Gener: ");
		gender = scan.next();
		System.out.print("Phone No: ");
		phone = scan.next();
		System.out.print("E-mail: ");
		email = scan.next();
	}
}
