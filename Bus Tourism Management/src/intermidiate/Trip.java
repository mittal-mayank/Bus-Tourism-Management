package intermidiate;

import client.Bus;

public class Trip {
	private Bus bus;
	private String startDay;
	private String startTime;
	private String endDay;
	private String endTime;
	// fares

	public Trip(Bus bus, String startDay, String startTime, String endDay, String endTime) {
		this.bus = bus;
		this.startDay = startDay;
		this.startTime = startTime;
		this.endDay = endDay;
		this.endTime = endTime;
	}

	public Bus getBus() {
		return bus;
	}
	
	public void discount() {
		// input and calc
		// discount = 10
		// fares  = fares*(100-dis)/100;
	}

	public void display() {
		String busClass = bus.getClass().toString();
		System.out.println("Bus tier: " + busClass.charAt(busClass.length() - 1));
		System.out.println("Start day: " + startDay);
		System.out.println("Start time: " + startTime);
		System.out.println("End day: " + endDay);
		System.out.println("End time: " + endTime);
		bus.seatsVacant();
		System.out.println();
	}
}
