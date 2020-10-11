package server;

import java.util.Scanner;

public class Main {
	public static final Scanner scan = new Scanner(System.in);
	private static final Log log = new Log();

	public static void main(String[] args) {
		int choice;
		do {
			System.out.println("1. Booking");
			System.out.println("2. Cancelling");
			System.out.println("3. Re-scheduling");
			System.out.println("4. Exit");
			System.out.print("Enter your choice: ");
			choice = scan.nextInt();
			switch (choice) {
			case 1:
				log.booking();
				break;

			case 4:
				System.out.println("Exited");
				break;

			default:
				System.out.println("Choice doesn't match options, try again");
				break;
			}
		} while (choice != 4);
	}
}
