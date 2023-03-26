/*** @author Elijah Garmon
 *   @id 0424
 *   @date 3/20/23
 *  Basic class for a celestial body
 */
package solarsystem;
import exceptions.DuplicateCelestialBodyException;

import java.util.ArrayList;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import panes.ErrorPane;

public class CelestialBody extends Circle{
    //Declaring variables
    private String name;
    private String type;

    private ArrayList<CelestialBody> children = new ArrayList<CelestialBody>();

    //Constructor
    public CelestialBody(String name, String type, Color color, double radius) {
        this.name = name;
        this.type = type;
        this.setFill(color);
        this.setRadius(radius);
    }

    //Getter
    public String getName() {
        return name;
    }

    public String getType() {
        return type;
    }

    public void getInformation() {
        System.out.println("This is the " + type + " " + name);
    }

    public ArrayList<CelestialBody> getChildren() {
        return children;
    }

    //Set a celestial body to orbit another
    public void add(CelestialBody child) throws DuplicateCelestialBodyException {
        if (!(children.contains(child))) {
            this.children.add(child);
            System.out.println("The " + child.getType() + " " + child.getName() + " was added successfully to " + this.name);
        } else {
            ErrorPane error = new ErrorPane("The " + child.getType() + " " + child.getName() + " is already in this collection");
            throw new DuplicateCelestialBodyException("The " + child.getType() + " " + child.getName() + " is already in this collection");
        }
    }
}
