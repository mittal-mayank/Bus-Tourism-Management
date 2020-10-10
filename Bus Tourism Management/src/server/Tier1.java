package server;

import java.util.HashSet;

public class Tier1 extends Bus {
	private static final int rows = 5;
	private static final int columns = 2;

	public Tier1() {
		ac = true;
		food = true;
		sleeper = true;
		toilet = true;
		tv = true;
		seats = new HashSet<Seat>();
	}
}
