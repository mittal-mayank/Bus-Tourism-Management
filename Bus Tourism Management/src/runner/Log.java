package runner;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.UUID;

import entities.Seat;
import entities.Tier1;
import entities.Tier2;
import entities.Tier3;

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

	void booking() {
		System.out.print("Enter destination: ");
		String location = Main.scan.next();
		System.out.println("Available choices:-");
		displayTrips(location);
		System.out.print("Enter your bus tier: ");
		int tier = Main.scan.nextInt();
		Trip trip = mapTrips.get(location).get(tier - 1);
		Seat seat = trip.bookTrip();
		Ticket ticket = new Ticket(location, trip, seat);
		String uniqueID = UUID.randomUUID().toString();
		mapTicket.put(uniqueID, ticket);
		System.out.println("Ticket Number: " + uniqueID);
		ticket.displayTicket();
		System.out.println();
	}

	void cancelling() {
		System.out.print("Please enter the ticket number: ");
		String ticketNumber = Main.scan.next();
		if (mapTicket.containsKey(ticketNumber)) {
			System.out.print("Are you sure, You want to cancel the trip? Press Y or N: ");
			char choice = Main.scan.next().charAt(0);
			if (choice == 'Y') {
				Ticket ticket = mapTicket.get(ticketNumber);
				ticket.cancelTicket();
				mapTicket.remove(ticketNumber);
			} else if (choice == 'N') {
				System.out.println("Ticket not cancelled!");
			}
		} else {
			System.out.println("The ticket number does not exist in our database!");
		}
		System.out.println();
	}

	void rescheduling() {
	}

	private void displayTrips(String location) {
		ArrayList<Trip> trips = mapTrips.get(location);
		for (Trip trip : trips) {
			trip.displayTrip();
			System.out.println();
		}
	}

	private ArrayList<Trip> mumbaiList() {
		ArrayList<Trip> trips = new ArrayList<Trip>();
		trips.add(new Trip(new Tier1(), "Tuesday", "1200", "Thursday", "1200", 5000));
		trips.add(new Trip(new Tier2(), "Saturday", "1200", "Monday", "1200", 3000));
		trips.add(new Trip(new Tier3(), "Thursday", "1800", "Saturday", "1800", 1700));
		return trips;
	}

	private ArrayList<Trip> jaipurList() {
		ArrayList<Trip> trips = new ArrayList<Trip>();
		trips.add(new Trip(new Tier1(), "Wednesday", "1200", "Thursday", "1200", 3500));
		trips.add(new Trip(new Tier2(), "Sunday", "1200", "Monday", "1200", 2500));
		trips.add(new Trip(new Tier3(), "Friday", "1800", "Saturday", "1800", 1000));
		return trips;
	}

	private ArrayList<Trip> chennaiList() {
		ArrayList<Trip> trips = new ArrayList<Trip>();
		trips.add(new Trip(new Tier1(), "Thursday", "1200", "Sunday", "1200", 7500));
		trips.add(new Trip(new Tier2(), "Tuesday", "1800", "Friday", "1800", 5000));
		trips.add(new Trip(new Tier3(), "Saturday", "1800", "Tuesday", "1800", 3500));
		return trips;
	}

	private ArrayList<Trip> kolkataList() {
		ArrayList<Trip> trips = new ArrayList<Trip>();
		trips.add(new Trip(new Tier1(), "Friday", "1200", "Sunday", "1200", 5500));
		trips.add(new Trip(new Tier2(), "Wednesday", "1800", "Friday", "1800", 4000));
		trips.add(new Trip(new Tier3(), "Sunday", "1800", "Tuesday", "1800", 2500));
		return trips;
	}
}
