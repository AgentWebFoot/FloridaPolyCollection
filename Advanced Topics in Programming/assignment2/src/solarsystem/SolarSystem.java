/*** @author Elijah Garmon
 *   0424
 *   2/22/23
 *  Main file for the solar system
 */
package solarsystem;
import exceptions.DuplicateCelestialBodyException;
import exceptions.InvalidCelestialBodyException;

public class SolarSystem {
    public static void main(String[] args) throws DuplicateCelestialBodyException, InvalidCelestialBodyException {
        //Declaring Stars
        Star sun = new Star("Sun", 5778000);

        //Declaring Planets
        Planet mercury = new Planet("Mercury", sun);
        sun.add(mercury);
        Planet venus = new Planet("Venus", sun);
        sun.add(venus);
        Planet earth = new Planet("Earth", sun);
        sun.add(earth);
        Planet mars = new Planet("Mars", sun);
        sun.add(mars);
        Planet jupiter = new Planet("Jupiter", sun);
        sun.add(jupiter);
        Planet saturn = new Planet("Saturn", sun);
        sun.add(saturn);
        Planet uranus = new Planet("Uranus", sun);
        sun.add(uranus);
        Planet neptune = new Planet("Neptune", sun);
        sun.add(neptune);

        //Declaring Moons
        Moon moon = new Moon("Moon", earth);
        earth.add(moon);
        Moon phobos = new Moon("Phobos", mars);
        mars.add(phobos);
        Moon deimos = new Moon("Deimos", mars);
        mars.add(deimos);
    }
}