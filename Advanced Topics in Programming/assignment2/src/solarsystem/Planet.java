/*** @author Elijah Garmon
 *   0424
 *   2/22/23
 *  Class for planets
 */
package solarsystem;
import exceptions.InvalidCelestialBodyException;

public class Planet  extends CelestialBody  implements IOrbit {
    //Declaring Variables
    private static final String type = "Planet";
    private CelestialBody orbits;

    //Constructor
    public Planet(String name, CelestialBody orbits) throws InvalidCelestialBodyException {
        super(name, type);
        if (orbits.getType() == "Star") {
            this.orbits = orbits;
        }
        else {
            throw new InvalidCelestialBodyException("A planet must orbit a star.");
        }
    }

    public void getOrbit() {
        System.out.println(getName() + " is orbiting the " + orbits.getType() + " " + orbits.getName());
    }
}
