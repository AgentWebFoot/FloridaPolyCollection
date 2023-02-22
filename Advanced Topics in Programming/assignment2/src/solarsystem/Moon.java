/*** @author Elijah Garmon
 *   0424
 *   2/22/23
 *  Class for moons
 */
package solarsystem;
import exceptions.InvalidCelestialBodyException;

public class Moon  extends CelestialBody implements IOrbit {
    //Declaring Variables
    private static final String type = "Moon";
    private CelestialBody orbits;

    //Constructor
    public Moon(String name, CelestialBody orbits) throws InvalidCelestialBodyException {
        super(name, type);
        if (orbits.getType() == "Planet") {
            this.orbits = orbits;
        }
        else {
            throw new InvalidCelestialBodyException("A planet must orbit a planet.");
        }
    }

    public void getOrbit() {
        System.out.println(getName() + " is orbiting the " + orbits.getType() + " " + orbits.getName());
    }
}
