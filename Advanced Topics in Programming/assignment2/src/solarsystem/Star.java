/*** @author Elijah Garmon
 *   0424
 *   2/22/23
 *  Class for stars
 */
package solarsystem;

public class Star extends CelestialBody {
    //Declaring Variables
    private static final String type = "Star";
    private int surfaceTemp;

    //Constructor
    public Star(String name, int surfaceTemp) {
        super(name, type);
        this.surfaceTemp = surfaceTemp;
    }

    //Getter
    public int getSurfaceTemp() {
        return surfaceTemp;
    }
}
