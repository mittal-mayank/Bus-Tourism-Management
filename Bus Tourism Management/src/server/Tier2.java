package server;

import java.util.HashSet;

public class Tier2 extends Bus {
	private static final int rows = 10;
	private static final int columns = 4;

	public Tier2() {
		ac = true;
		food = true;
		sleeper = false;
		toilet = false;
		tv = false;
		seats = new HashSet<Seat>();
	}
}
