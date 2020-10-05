package server;

public class Tier3 extends Bus {
	private static final int rows = 10;
	private static final int columns = 4;

	public Tier3() {
		ac = false;
		food = false;
		toilet = false;
		tv = false;
		sleeper = false;
		seats = new Seat[rows][columns];
	}
}
