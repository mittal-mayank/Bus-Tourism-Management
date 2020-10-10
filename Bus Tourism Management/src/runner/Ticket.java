package runner;

import server.Seat;

public class Ticket {
	private static final String source = "Delhi";

	String destination;
	Trip detail;
	Seat seat;

	public Ticket(String destination, Trip detail, Seat seat) {
		this.destination = destination;
		this.detail = detail;
		this.seat = seat;
	}
}
