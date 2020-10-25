package entities;

import java.util.HashSet;

public abstract class Bus {
	boolean ac;
	boolean food;
	boolean sleeper;
	boolean toilet;
	boolean tv;
	HashSet<Seat> seats;

	public abstract void displayVacantSeats();
	public abstract Seat bookSeat();
	public abstract void cancelSeat(Seat seat);
}
