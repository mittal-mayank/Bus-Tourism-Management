package server;

import customer.Passenger;

public class Seat {
	Passenger passenger;
	int row;
	int column;

	public Seat(Passenger passenger, int row, int column) {
		this.passenger = passenger;
		this.row = row;
		this.column = column;
	}
}
