package sever;

public abstract class Bus {
	class Seat {
		Passenger passenger;
		int row;
		int column;
	}

	boolean ac;
	boolean food;
	boolean sleeper;
	boolean toilet;
	boolean tv;
	Seat[][] seats;
}
