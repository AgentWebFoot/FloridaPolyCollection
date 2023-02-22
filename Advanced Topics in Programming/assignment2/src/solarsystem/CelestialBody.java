/*** @author Elijah Garmon
 *   0424
 *   2/22/23
 *  Basic class for a celestial body
 */
package solarsystem;
import exceptions.DuplicateCelestialBodyException;

import java.util.ArrayList;

public class CelestialBody {
    //Declaring variables
    private String name;
    private String type;
    private ArrayList<CelestialBody> children = new ArrayList<CelestialBody>();

    //Constructor
    public CelestialBody(String name, String type) {
        this.name = name;
        this.type = type;
    }

    //Getter
    public String getName() {
        return name;
    }

    public String getType() {
        return type;
    }

    public ArrayList<CelestialBody> getChildren() {
        return children;
    }

    //Set a celestial body to orbit another
    public void add(CelestialBody child) throws DuplicateCelestialBodyException {
        if (!(children.contains(child))) {
            this.children.add(child);
            System.out.println("The " + child.getType() + " " + child.getName() + " was added successfully to " + this.name);
        }
        else {
            throw new DuplicateCelestialBodyException("The " + child.getType() + " " + child.getName() + "is already in this collection");
        }
    }
}
