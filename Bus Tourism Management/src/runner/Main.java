package runner;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Scanner;

public class Main {
	public static final Scanner scan = new Scanner(System.in);

	private static Log log = new Log();

	public static void main(String[] args) {
		readLogs();
		int choice;
		do {
			System.out.println();
			System.out.println("Log in as:-");
			System.out.println("1. Admin");
			System.out.println("2. Customer");
			System.out.println("3. Exit");
			System.out.print("Enter your choice: ");
			choice = scan.nextInt();
			System.out.println();
			switch (choice) {
			case 1:
				adminMode();
				break;
			case 2:
				customerMode();
				break;
			case 3:
				writeLogs();
				System.out.println("Exited");
				break;
			default:
				System.out.println("Choice doesn't match options, try again");
				break;
			}
		} while (choice != 3);
	}

	private static void readLogs() {
		File file = new File("logs.dat");
		try {
			if (file.exists()) {
				FileInputStream fileIn = new FileInputStream(file);
				ObjectInputStream in = new ObjectInputStream(fileIn);
				try {
					log = (Log) in.readObject();
				} catch (ClassNotFoundException ex) {
					ex.printStackTrace();
				} finally {
					fileIn.close();
					in.close();
				}
			}
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}

	private static void writeLogs() {
		File file = new File("logs.dat");
		try {
			if (file.exists()) {
				file.delete();
			}
			file.createNewFile();
			FileOutputStream fileOut = new FileOutputStream(file);
			ObjectOutputStream out = new ObjectOutputStream(fileOut);
			try {
				out.writeObject(log);
			} finally {
				fileOut.close();
				out.close();
			}
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}

	private static void customerMode() {
		int choice;
		do {
			System.out.println();
			System.out.println("1. Booking");
			System.out.println("2. Cancelling");
			System.out.println("3. Re-schedule/edit details");
			System.out.println("4. Print bus information");
			System.out.println("5. Print a trip");
			System.out.println("6. Print all trips to a location");
			System.out.println("7. Print all logs");
			System.out.println("8. Print ticket");
			System.out.println("9. Log out");
			System.out.print("Enter your choice: ");
			choice = scan.nextInt();
			System.out.println();
			switch (choice) {
			case 1:
				log.booking();
				break;
			case 2:
				log.cancelling();
				break;
			case 3:
				log.rescheduling();
				break;
			case 4:
				log.printBus();
				break;
			case 5:
				log.printTrip();
				break;
			case 6:
				log.printTrips();
				break;
			case 7:
				log.printLogs();
				break;
			case 8:
				log.printTicket();
				break;
			case 9:
				System.out.println("Logged out");
				break;
			default:
				System.out.println("Choice doesn't match options, try again");
				break;
			}
		} while (choice != 9);
	}

	private static void adminMode() {
		deafaultPassword();
		System.out.print("Enter admin password: ");
		String password = scan.next();
		if (!getPassword().equals(password)) {
			System.out.println("Wrong password entered, entry denied!");
			return;
		}
		int choice;
		do {
			System.out.println();
			System.out.println("1. Booking");
			System.out.println("2. Cancelling");
			System.out.println("3. Re-schedule/edit details");
			System.out.println("4. Print bus information");
			System.out.println("5. Print a trip");
			System.out.println("6. Print all trips to a location");
			System.out.println("7. Print all logs");
			System.out.println("8. Print ticket");
			System.out.println("9. Change password");
			System.out.println("10. Edit bus information");
			System.out.println("11. Reset bus/trip");
			System.out.println("12. Add new destination");
			System.out.println("13. Remove destination");
			System.out.println("14. Reset logs");
			System.out.println("15. Edit trip");
			System.out.println("16. Log out");
			System.out.print("Enter your choice: ");
			choice = scan.nextInt();
			System.out.println();
			switch (choice) {
			case 1:
				log.booking();
				break;
			case 2:
				log.cancelling();
				break;
			case 3:
				log.rescheduling();
				break;
			case 4:
				log.printBus();
				break;
			case 5:
				log.printTrip();
				break;
			case 6:
				log.printTrips();
				break;
			case 7:
				log.printLogs();
				break;
			case 8:
				log.printTicket();
				break;
			case 9:
				changePassword();
				break;
			case 10:
				log.editBus();
				break;
			case 11:
				log.resetTrip();
				break;
			case 12:
				log.addDestination();
				break;
			case 13:
				log.removeDestination();
				break;
			case 14:
				log = new Log();
				break;
			case 15:
				log.editTrip();
				break;
			case 16:
				System.out.println("Logged out");
				break;
			default:
				System.out.println("Choice doesn't match options, try again");
				break;
			}
		} while (choice != 16);
	}

	private static void deafaultPassword() {
		File file = new File("password.dat");
		try {
			if (!file.exists()) {
				file.createNewFile();
				FileOutputStream fileOut = new FileOutputStream(file);
				ObjectOutputStream out = new ObjectOutputStream(fileOut);
				try {
					String password = "abcd";
					out.writeObject(password);
				} finally {
					fileOut.close();
					out.close();
				}
			}
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}

	private static void changePassword() {
		System.out.print("Enter new password: ");
		String password = scan.next();
		File file = new File("password.dat");
		try {
			if (file.exists()) {
				file.delete();
			}
			file.createNewFile();
			FileOutputStream fileOut = new FileOutputStream(file);
			ObjectOutputStream out = new ObjectOutputStream(fileOut);
			try {
				out.writeObject(password);
			} finally {
				fileOut.close();
				out.close();
			}
		} catch (IOException ex) {
			ex.printStackTrace();
		}
		System.out.println("Password changed!");
		System.out.println();
	}

	private static String getPassword() {
		String password = null;
		File file = new File("password.dat");
		try {
			FileInputStream fileIn = new FileInputStream(file);
			ObjectInputStream in = new ObjectInputStream(fileIn);
			try {
				password = (String) in.readObject();
			} catch (ClassNotFoundException ex) {
				ex.printStackTrace();
			} finally {
				fileIn.close();
				in.close();
			}
		} catch (IOException ex) {
			ex.printStackTrace();
		}
		return password;
	}
}
