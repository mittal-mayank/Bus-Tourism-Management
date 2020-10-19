package server;

import java.util.*;

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
		trip.discount();
		
		Ticket ticket = new Ticket(location, trip, seat);
		String uniqueID = UUID.randomUUID().toString();
		mapTicket.put(uniqueID, ticket);
		System.out.println("Ticket No: " + uniqueID);
	}
	
	void cancelling() {
		// get ticket no
		System.out.println();
		System.out.println("Please enter the ticket number :");
		
		Scanner sc = new Scanner (System.in);
		
		int ticketNumber = sc.nextInt();
		
		if (mapTicket.containsKey(ticketNumber)) {
			
			System.out.println();
			System.out.println("Are you sure, You want to cancel the trip? Press 1 to cancel else 0.");
			
			int choice  = sc.nextInt();
			
			if(choice == 1) {
				
				
				
			}
			else if (choice ==0) {
				
				//Redirect to the Booking function.
				booking();
			}
			else {
				System.out.println("Wrong input.. Please Try again!");
			}
			
			
		}
		else {
			System.out.println("The ticket number does not exist in our Database. Please try again!");
		}
		
		// Ticket t = mapTicket.get(ticketno);
		
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
		trips.add(new Trip(new Tier1(), "Wednesday", "1200", "Thursday", "1200" , 3500));
		trips.add(new Trip(new Tier2(), "Sunday", "1200", "Monday", "1200", 2500));
		trips.add(new Trip(new Tier3(), "Friday", "1800", "Saturday", "1800", 1000));
		return trips;
	}

	private ArrayList<Trip> chennaiList() {
		ArrayList<Trip> trips = new ArrayList<Trip>();
		trips.add(new Trip(new Tier1(), "Thursday", "1200", "Sunday", "1200" , 7500));
		trips.add(new Trip(new Tier2(), "Tuesday", "1800", "Friday", "1800" , 5000));
		trips.add(new Trip(new Tier3(), "Saturday", "1800", "Tuesday", "1800", 3500));
		return trips;
	}

	private ArrayList<Trip> kolkataList() {
		ArrayList<Trip> trips = new ArrayList<Trip>();
		trips.add(new Trip(new Tier1(), "Friday", "1200", "Sunday", "1200", 5500));
		trips.add(new Trip(new Tier2(), "Wednesday", "1800", "Friday", "1800" , 4000));
		trips.add(new Trip(new Tier3(), "Sunday", "1800", "Tuesday", "1800" , 2500));
		return trips;
	}
}
