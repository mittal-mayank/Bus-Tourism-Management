package runner;

import entities.Seat;

public class Ticket implements java.io.Serializable {
	private static final long serialVersionUID = 1L;

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
		seat.displaySeat();
		System.out.println();
	}

	void cancelTicket() {
		trip.cancelTrip(seat);
	}

	private void setFare() {
		fare = trip.discount();
	}
}
