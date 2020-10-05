package server;

public class Tier1 extends Bus {
	private static final int rows = 5;
	private static final int columns = 2;
	
	public Tier1() {
		ac = true;
		food = true;
		toilet = true;
		tv = true;
		sleeper = true;
		seats = new Seat[rows][columns];
	}
}
