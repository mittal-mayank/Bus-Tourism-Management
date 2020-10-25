package runner;

import entities.Seat;

public class Ticket {
	private static final String source = "Delhi";

	private String destination;
	private Trip trip;
	private Seat seat;
	private int fare;

	Ticket(String destination, Trip trip, Seat seat) {
		this.destination = destination;
		this.trip = trip;
		this.seat = seat;
		setFare();
	}

	void displayTicket() {
		System.out.println("Source: " + source);
		System.out.println("Destination: " + destination);
		trip.displayTrip();
		System.out.println("Discounted fare: " + fare);
		seat.display();
		System.out.println();
	}

	void cancelTicket() {
		trip.cancelTrip(seat);
	}

	void setFare() {
		fare = trip.discount();
	}
}
