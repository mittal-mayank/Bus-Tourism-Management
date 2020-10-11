package client;

import java.util.HashSet;

import intermidiate.Passenger;
import intermidiate.Seat;
import server.Main;

public class Tier1 extends Bus {
	private static final int rows = 5;
	private static final int columns = 2;

	public Tier1() {
		ac = true;
		food = true;
		sleeper = true;
		toilet = true;
		tv = true;
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
		Seat seat = new Seat(new Passenger(), row, column);
		seats.add(seat);
		System.out.println("Seat booked");
		return seat;
	}
}
