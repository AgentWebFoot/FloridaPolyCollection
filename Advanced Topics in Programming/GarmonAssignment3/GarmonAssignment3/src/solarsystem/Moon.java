/*** @author Elijah Garmon
 *   0424
 *   3/26/23
 *  Class for moons
 */
package solarsystem;
import exceptions.InvalidCelestialBodyException;
import javafx.scene.paint.Color;
import panes.ErrorPane;

public class Moon  extends CelestialBody implements IOrbit {
    //Declaring Variables
    private static final String type = "Moon";
    private CelestialBody orbits;

    //Constructor
    public Moon(String name, CelestialBody orbits, Color color, double radius) throws InvalidCelestialBodyException {
        super(name, type, color, radius);
        if (orbits.getType() == "Planet") {
            this.orbits = orbits;
        }
        else {
            throw new InvalidCelestialBodyException("A planet must orbit a planet.");
        }
    }

    public CelestialBody getOrbit() {
        return orbits;
    }
    public void getOrbitInformation() {
        ErrorPane error = new ErrorPane(getName() + " is orbiting the " + orbits.getType() + " " + orbits.getName());
    }
}
