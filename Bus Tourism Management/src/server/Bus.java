package server;

import customer.Passenger;

public class Bus {
	final class Seat {
		Passenger passenger;
		int row;
		char column;
	}

	boolean ac;
	boolean food;
	boolean toilet;
	boolean tv;
	boolean sleeper;
	Seat[][] seats;
}
