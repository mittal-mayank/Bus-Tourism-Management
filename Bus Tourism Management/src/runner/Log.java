package runner;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Set;
import java.util.UUID;

import entities.Bus;
import entities.Seat;
import entities.Tier1;
import entities.Tier2;
import entities.Tier3;

public class Log implements java.io.Serializable {
	private static final long serialVersionUID = 1L;
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
		System.out.println();
		System.out.print("Enter your bus tier: ");
		int tier = Main.scan.nextInt();
		Trip trip = mapTrips.get(location).get(tier - 1);
		Seat seat = trip.bookTrip();
		System.out.println();
		Ticket ticket = new Ticket(location, trip, seat);
		System.out.println();
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
				System.out.println();
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
		System.out.println("Your previous ticket will be cancelled and new ticket will be booked");
		System.out.print("Please enter the ticket number: ");
		String ticketNumber = Main.scan.next();
		if (mapTicket.containsKey(ticketNumber)) {
			System.out.print("Are you sure, You want to re-schedule the trip? Press Y or N: ");
			char choice = Main.scan.next().charAt(0);
			if (choice == 'Y') {
				Ticket ticket = mapTicket.get(ticketNumber);
				ticket.cancelTicket();
				System.out.println();
				mapTicket.remove(ticketNumber);
				booking();
			} else if (choice == 'N') {
				System.out.println("Ticket not re-scheduled!");
			}
		} else {
			System.out.println("The ticket number does not exist in our database!");
		}
		System.out.println();
	}

	void printBus() {
		System.out.print("Enter bus tier: ");
		int tier = Main.scan.nextInt();
		if (tier == 1) {
			Tier1.printInfo();
		} else if (tier == 2) {
			Tier2.printInfo();
		} else if (tier == 3) {
			Tier3.printInfo();
		} else {
			System.out.println("Tier does not exist!");
		}
		System.out.println();
	}

	void printTrip() {
		System.out.print("Enter destination: ");
		String location = Main.scan.next();
		System.out.print("Enter bus tier: ");
		int tier = Main.scan.nextInt();
		ArrayList<Trip> trips = mapTrips.get(location);
		Trip trip = trips.get(tier - 1);
		trip.displayTrip();
		System.out.println();
	}

	void printTrips() {
		System.out.print("Enter destination: ");
		String location = Main.scan.next();
		displayTrips(location);
	}

	void printLogs() {
		Set<String> locations = mapTrips.keySet();
		for (String location : locations) {
			System.out.println("Destination: " + location);
			displayTrips(location);
		}
	}

	void printTicket() {
		System.out.print("Please enter the ticket number: ");
		String ticketNumber = Main.scan.next();
		if (mapTicket.containsKey(ticketNumber)) {
			Ticket ticket = mapTicket.get(ticketNumber);
			ticket.displayTicket();
		} else {
			System.out.println("The ticket number does not exist in our database!");
		}
		System.out.println();
	}

	void editBus() {
		System.out.print("Enter tier: ");
		int tier = Main.scan.nextInt();
		if (tier == 1) {
			Tier1.changeBus();
		} else if (tier == 2) {
			Tier2.changeBus();
		} else if (tier == 3) {
			Tier3.changeBus();
		} else {
			System.out.println("Tier does not exist!");
		}
		System.out.println();
	}

	void resetTrip() {
		System.out.print("Enter destination: ");
		String location = Main.scan.next();
		System.out.print("Enter bus tier: ");
		int tier = Main.scan.nextInt();
		ArrayList<Trip> trips = mapTrips.get(location);
		Trip trip = trips.get(tier - 1);
		trip.clearTrip();
		System.out.println();
	}

	void addDestination() {
		System.out.print("Enter destination: ");
		String location = Main.scan.next();
		mapTrips.put(location, destinationList());
		System.out.println("Destination added!");
		System.out.println();
	}
	
	void removeDestination() {
		System.out.print("Enter destination: ");
		String loaction = Main.scan.next();
		if(mapTrips.containsKey(loaction)) {
			mapTrips.remove(loaction);
			System.out.println("Destination removed!");
		}else {
			System.out.println("Destination not present!");
		}
		System.out.println();
	}

	void editTrip() {
		System.out.print("Enter destination: ");
		String location = Main.scan.next();
		System.out.print("Enter bus tier: ");
		int tier = Main.scan.nextInt();
		ArrayList<Trip> trips = mapTrips.get(location);
		Trip trip = trips.get(tier - 1);
		trip.editTrip();
		System.out.println();
	}

	private ArrayList<Trip> destinationList() {
		ArrayList<Trip> trips = new ArrayList<Trip>();
		for (int i = 1; i <= 3; i++) {
			System.out.println("Enter details for tier: " + i);
			System.out.print("Enter start day: ");
			String startDay = Main.scan.next();
			System.out.print("Enter start time: ");
			String startTime = Main.scan.next();
			System.out.print("Enter end day: ");
			String endDay = Main.scan.next();
			System.out.print("Enter end time: ");
			String endTime = Main.scan.next();
			System.out.print("Enter fare: ");
			int fare = Main.scan.nextInt();
			trips.add(new Trip(getTierBus(i), startDay, startTime, endDay, endTime, fare));
			System.out.println("Trip added!");
			System.out.println();
		}
		return trips;
	}

	private Bus getTierBus(int tier) {
		Bus bus;
		if (tier == 1) {
			bus = new Tier1();
		} else if (tier == 2) {
			bus = new Tier2();
		}
		bus = new Tier3();
		return bus;
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
