package server;

import intermidiate.Seat;
import intermidiate.Trip;

public class Ticket {
	private static final String source = "Delhi";

	private String destination;
	private Trip trip;
	private Seat seat;

	Ticket(String destination, Trip trip, Seat seat) {
		this.destination = destination;
		this.trip = trip;
		this.seat = seat;
	}

	void display() {
		System.out.println("Source: " + source);
		System.out.println("Destination: " + destination);
		trip.display();
		seat.display();
	}
}
