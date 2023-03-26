/*** @author Elijah Garmon
 *   0424
 *   3/26/23
 *  Class for planets
 */
package solarsystem;
import exceptions.InvalidCelestialBodyException;
import javafx.scene.paint.Color;
import panes.ErrorPane;

public class Planet  extends CelestialBody  implements IOrbit {
    //Declaring Variables
    private static final String type = "Planet";
    private CelestialBody orbits;

    //Constructor
    public Planet(String name, CelestialBody orbits, Color color, double radius) throws InvalidCelestialBodyException {
        super(name, type, color, radius);
        if (orbits.getType() == "Star") {
            this.orbits = orbits;
        }
        else {
            throw new InvalidCelestialBodyException("A planet must orbit a star.");
        }
    }

    public CelestialBody getOrbit() {
        return orbits;
    }
    public void getOrbitInformation() {
       ErrorPane error = new ErrorPane(getName() + " is orbiting the " + orbits.getType() + " " + orbits.getName());
    }


}
