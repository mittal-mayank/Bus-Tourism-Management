package runner;

import server.Bus;

public class Trip {
	Bus bus;
	String startDay;
	String startTime;
	String endDay;
	String endTime;

	public Trip(Bus bus, String startDay, String startTime, String endDay, String endTime) {
		this.bus = bus;
		this.startDay = startDay;
		this.startTime = startTime;
		this.endDay = endDay;
		this.endTime = endTime;
	}
}
