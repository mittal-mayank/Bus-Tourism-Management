package server;

import java.util.HashSet;

public abstract class Bus {
	boolean ac;
	boolean food;
	boolean sleeper;
	boolean toilet;
	boolean tv;
	HashSet<Seat> seats;
}
