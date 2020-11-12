package entities;

import java.util.HashSet;

import runner.Main;

public class Tier2 extends Bus {
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
		System.out.println();
		return seat;
	}

	@Override
	public void cancelSeat(Seat seat) {
		seats.remove(seat);
		System.out.println("Seat cancelled!");
		System.out.println();
	}
}
