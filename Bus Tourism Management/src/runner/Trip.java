package runner;

import entities.Bus;
import entities.Seat;

public class Trip implements java.io.Serializable {
	private static final long serialVersionUID = 1L;
	private Bus bus;
	private String startDay;
	private String startTime;
	private String endDay;
	private String endTime;
	private int fare;

	Trip(Bus bus, String startDay, String startTime, String endDay, String endTime, int fare) {
		this.bus = bus;
		this.startDay = startDay;
		this.startTime = startTime;
		this.endDay = endDay;
		this.endTime = endTime;
		this.fare = fare;
	}

	Seat bookTrip() {
		System.out.println();
		return bus.bookSeat();
	}

	void cancelTrip(Seat seat) {
		System.out.println();
		bus.cancelSeat(seat);
	}

	void displayTrip() {
		String busClass = bus.getClass().toString();
		System.out.println("Bus tier: " + busClass.charAt(busClass.length() - 1));
		System.out.println("Start day: " + startDay);
		System.out.println("Start time: " + startTime);
		System.out.println("End day: " + endDay);
		System.out.println("End time: " + endTime);
		bus.displayVacantSeats();
		System.out.println("Orignal fare: " + fare);
	}

	int discount() {
		System.out.println(
				"You have been selected for a discount round wherein you will have to perform a simple task and on the basis of that you will be awarded a discount on fare");
		System.out.println("Enter 2 numbers from 1 to 10:-");
		System.out.print("First number: ");
		int a = Main.scan.nextInt();
		System.out.print("Second number: ");
		int b = Main.scan.nextInt();
		int discount;
		int prevFare = fare;
		int c = a | b;
		if (c > 13) {
			System.out.println("Congratulations! You have got a flat 10% reduction in fares");
			discount = 10;
			prevFare = fare * (100 - discount) / 100;
		} else if (c < 13 | c > 9) {
			System.out.println("Congratulations! You have got a flat 7% reduction in fares");
			discount = 7;
			prevFare = fare * (100 - discount) / 100;
		} else if (c < 9 | c > 5) {
			System.out.println("Congratulations! You have got a flat 5% reduction in fares");
			discount = 5;
			prevFare = fare * (100 - discount) / 100;
		} else if (c < 5 & c > 0) {
			System.out.println("You have got no reduction in fares! Better luck next time!");
		}
		System.out.println();
		return prevFare;
	}

	void editTrip() {
		System.out.print("Enter start day: ");
		startDay = Main.scan.next();
		System.out.print("Enter start time: ");
		startTime = Main.scan.next();
		System.out.print("Enter end day: ");
		endDay = Main.scan.next();
		System.out.print("Enter end time: ");
		endTime = Main.scan.next();
		System.out.print("Enter fare: ");
		fare = Main.scan.nextInt();
	}

	void clearTrip() {
		bus.clearBus();
	}
}
