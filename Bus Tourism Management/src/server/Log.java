package server;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.UUID;

import client.Tier1;
import client.Tier2;
import client.Tier3;
import intermidiate.Seat;
import intermidiate.Trip;

public class Log {
	private HashMap<String, Ticket> mapTicket;
	private HashMap<String, ArrayList<Trip>> mapTrips;

	Log() {
		mapTicket = new HashMap<String, Ticket>();
		mapTrips = new HashMap<String, ArrayList<Trip>>();
		mapTrips.put("Mumbai", mumbaiList());
		mapTrips.put("Jaipur", jaipurList());
		mapTrips.put("Chennai", chennaiList());
		mapTrips.put("Kolkata", kolkataList());
	}

	void displayTrips(String location) {
		ArrayList<Trip> trips = mapTrips.get(location);
		for (Trip trip : trips) {
			trip.display();
		}
	}

	void displayTable() {
		displayTrips("Mumbai");
		displayTrips("Jaipur");
		displayTrips("Chennai");
		displayTrips("Chennai");
	}

	void booking() {
		System.out.print("Enter destination: ");
		String location = Main.scan.next();
		System.out.println("Available choices...");
		displayTrips(location);
		System.out.print("Enter your bus tier: ");
		int tier = Main.scan.nextInt();
		Trip trip = mapTrips.get(location).get(tier - 1);
		// trip.discount();
		Seat seat = trip.getBus().book();
		Ticket ticket = new Ticket(location, trip, seat);
		String uniqueID = UUID.randomUUID().toString();
		mapTicket.put(uniqueID, ticket);
		System.out.println("Ticket No: " + uniqueID);
	}
	
	void cancelling() {
		// get ticket no
		// Ticket t = mapTicket.get(ticketno);
		
	}

	private ArrayList<Trip> mumbaiList() {
		ArrayList<Trip> trips = new ArrayList<Trip>();
		trips.add(new Trip(new Tier1(), "Tuesday", "1200", "Thursday", "1200"));
		trips.add(new Trip(new Tier2(), "Saturday", "1200", "Monday", "1200"));
		trips.add(new Trip(new Tier3(), "Thursday", "1800", "Saturday", "1800"));
		return trips;
	}

	private ArrayList<Trip> jaipurList() {
		ArrayList<Trip> trips = new ArrayList<Trip>();
		trips.add(new Trip(new Tier1(), "Wednesday", "1200", "Thursday", "1200"));
		trips.add(new Trip(new Tier2(), "Sunday", "1200", "Monday", "1200"));
		trips.add(new Trip(new Tier3(), "Friday", "1800", "Saturday", "1800"));
		return trips;
	}

	private ArrayList<Trip> chennaiList() {
		ArrayList<Trip> trips = new ArrayList<Trip>();
		trips.add(new Trip(new Tier1(), "Thursday", "1200", "Sunday", "1200"));
		trips.add(new Trip(new Tier2(), "Tuesday", "1800", "Friday", "1800"));
		trips.add(new Trip(new Tier3(), "Saturday", "1800", "Tuesday", "1800"));
		return trips;
	}

	private ArrayList<Trip> kolkataList() {
		ArrayList<Trip> trips = new ArrayList<Trip>();
		trips.add(new Trip(new Tier1(), "Friday", "1200", "Sunday", "1200"));
		trips.add(new Trip(new Tier2(), "Wednesday", "1800", "Friday", "1800"));
		trips.add(new Trip(new Tier3(), "Sunday", "1800", "Tuesday", "1800"));
		return trips;
	}
}
