package server;

import java.util.HashSet;

public class Tier3 extends Bus {
	private static final int rows = 10;
	private static final int columns = 4;

	public Tier3() {
		ac = false;
		food = false;
		sleeper = false;
		toilet = false;
		tv = false;
		seats = new HashSet<Seat>();
	}
}
