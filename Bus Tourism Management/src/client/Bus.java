package client;

import java.util.HashSet;

import intermidiate.Seat;

public abstract class Bus {
	boolean ac;
	boolean food;
	boolean sleeper;
	boolean toilet;
	boolean tv;
	HashSet<Seat> seats;

	public abstract void seatsVacant();
	public abstract Seat book();
}
