package entities;

import java.util.HashSet;

public abstract class Bus implements java.io.Serializable {
	private static final long serialVersionUID = 1L;

	static boolean ac;
	static boolean food;
	static boolean sleeper;
	static boolean toilet;
	static boolean tv;

	HashSet<Seat> seats;
	
	public abstract void displayVacantSeats();

	public abstract Seat bookSeat();

	public abstract void cancelSeat(Seat seat);
	
	public abstract void clearBus();
}
