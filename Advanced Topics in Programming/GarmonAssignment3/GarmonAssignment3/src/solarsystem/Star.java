/*** @author Elijah Garmon
 *   0424
 *   3/26/23
 *  Class for stars
 */
package solarsystem;

import javafx.scene.paint.Color;

public class Star extends CelestialBody {
    //Declaring Variables
    private static final String type = "Star";
    private int surfaceTemp;

    //Constructor
    public Star(String name, int surfaceTemp, Color color, double radius) {
        super(name, type, color, radius);
        this.surfaceTemp = surfaceTemp;
    }

    //Getter
    public int getSurfaceTemp() {
        return surfaceTemp;
    }
}
