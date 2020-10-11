package client;

import java.util.HashSet;

import intermidiate.Passenger;
import intermidiate.Seat;
import server.Main;

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
	public void seatsVacant() {
		System.out.println("Seats range, " + "Rows: " + rows + " Columns: " + columns);
		System.out.println("Non-vacant seats...");
		if (seats.isEmpty()) {
			System.out.println("All vacant");
		} else {
			for (Seat seat : seats) {
				System.out.println("Row: " + seat.getRow() + " Column: " + seat.getColumn());
			}
		}
	}

	@Override
	public Seat book() {
		System.out.println("Enter seat co-ordinates...");
		System.out.print("Row: ");
		int row = Main.scan.nextInt();
		System.out.print("Column: ");
		int column = Main.scan.nextInt();
		Seat bookedSeat = new Seat(new Passenger(), row, column);
		seats.add(bookedSeat);
		System.out.println("Seat booked");
		return bookedSeat;
	}
}
