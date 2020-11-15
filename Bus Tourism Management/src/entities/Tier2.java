package entities;

import java.util.HashSet;

import runner.Main;

public class Tier2 extends Bus implements java.io.Serializable {
	private static final long serialVersionUID = 1L;
	private static final int rows = 10;
	private static final int columns = 4;

	public Tier2() {
		ac = true;
		food = true;
		sleeper = false;
		toilet = false;
		tv = false;

		seats = new HashSet<Seat>();
	}

	public static void printInfo() {
		System.out.println("Number of rows: " + rows);
		System.out.println("Number of columns: " + columns);
		System.out.println("AC: " + ac);
		System.out.println("Food: " + food);
		System.out.println("Sleeper: " + sleeper);
		System.out.println("Toilet: " + toilet);
		System.out.println("TV: " + tv);
	}

	public static void changeBus() {
		System.out.println("Enter new details:-");
		System.out.print("AC: ");
		ac = Main.scan.nextBoolean();
		System.out.print("Food: ");
		food = Main.scan.nextBoolean();
		System.out.print("Sleeper: ");
		sleeper = Main.scan.nextBoolean();
		System.out.print("Toilet: ");
		toilet = Main.scan.nextBoolean();
		System.out.print("TV: ");
		tv = Main.scan.nextBoolean();
		System.out.println("Bus updated!");
	}

	@Override
	public void clearBus() {
		seats = new HashSet<Seat>();
		System.out.println("Bus resetted!");
	}

	@Override
	public void displayVacantSeats() {
		System.out.println("Seats range, Rows: " + rows + ", Columns: " + columns);
		System.out.println("Non-vacant seats:-");
		if (seats.isEmpty()) {
			System.out.println("All vacant!");
		} else {
			for (Seat seat : seats) {
				seat.displayCoordinates();
			}
		}
	}

	@Override
	public Seat bookSeat() {
		System.out.println("Enter seat co-ordinates:-");
		System.out.print("Row: ");
		int row = Main.scan.nextInt();
		System.out.print("Column: ");
		int column = Main.scan.nextInt();
		Seat seat = new Seat(new Passenger(), row, column);
		seats.add(seat);
		System.out.println("Seat booked!");
		return seat;
	}

	@Override
	public void cancelSeat(Seat seat) {
		seats.remove(seat);
		System.out.println("Seat cancelled!");
	}
}
