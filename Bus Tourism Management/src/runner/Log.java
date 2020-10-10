package runner;

import java.util.ArrayList;
import java.util.HashMap;

import server.Tier1;
import server.Tier2;
import server.Tier3;

public class Log {
	HashMap<String, Ticket> mapTicket;
	HashMap<String, ArrayList<Trip>> mapTrips;

	public Log() {
		mapTicket = new HashMap<String, Ticket>();
		mapTrips = new HashMap<String, ArrayList<Trip>>();
		mapTrips.put("Mumbai", mumbaiList());
		mapTrips.put("Jaipur", jaipurList());
		mapTrips.put("Chennai", chennaiList());
		mapTrips.put("Kolkata", kolkataList());
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
