package server;

public class Tier2 extends Bus {
	private static final int rows = 10;
	private static final int columns = 4;

	public Tier2() {
		ac = true;
		food = true;
		toilet = false;
		tv = false;
		sleeper = false;
		seats = new Seat[rows][columns];
	}
}
