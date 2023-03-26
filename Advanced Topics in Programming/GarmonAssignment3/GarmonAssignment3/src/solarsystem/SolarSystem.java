/*** @author Elijah Garmon
 *   0424
 *   3/26/23
 *  Main file for the solar system
 */
package solarsystem;
import exceptions.DuplicateCelestialBodyException;
import exceptions.InvalidCelestialBodyException;
import javafx.application.Application;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import panes.SolarSystemPane;

public class SolarSystem extends Application {
    public static void main(String[] args) {
        //Launch Stage
        launch(args);
    }

    public void start(Stage primaryStage) throws InvalidCelestialBodyException, DuplicateCelestialBodyException {
        //Declaring Solar System
        SolarSystemPane solarSystem = new SolarSystemPane();

        //Declaring Stars
        Star sun = new Star("Sun", 5778000, Color.YELLOW, 100);
        solarSystem.addStar(sun);

        //Declaring Planets
        Planet mercury = new Planet("Mercury", sun, Color.LIGHTSTEELBLUE, 10);
        sun.add(mercury);
        solarSystem.addPlanet(mercury, 110);

        Planet venus = new Planet("Venus", sun, Color.LIGHTSALMON, 20);
        sun.add(venus);
        solarSystem.addPlanet(venus, 150);

        Planet earth = new Planet("Earth", sun, Color.GREEN, 20);
        sun.add(earth);
        solarSystem.addPlanet(earth, 200);

        Planet mars = new Planet("Mars", sun, Color.RED, 15);
        sun.add(mars);
        solarSystem.addPlanet(mars, 275);

        Planet jupiter = new Planet("Jupiter", sun, Color.ORANGERED, 70);
        sun.add(jupiter);
        solarSystem.addPlanet(jupiter, 400);

        Planet saturn = new Planet("Saturn", sun, Color.MOCCASIN, 60);
        sun.add(saturn);
        solarSystem.addPlanet(saturn, 500);

        Planet uranus = new Planet("Uranus", sun, Color.PALETURQUOISE, 50);
        sun.add(uranus);
        solarSystem.addPlanet(uranus, 600);

        Planet neptune = new Planet("Neptune", sun, Color.BLUE, 50);
        sun.add(neptune);
        solarSystem.addPlanet(neptune, 700);

        //Declaring Moons
        Moon moon = new Moon("Moon", earth, Color.SILVER, 5);
        earth.add(moon);
        solarSystem.addMoon(moon, 20);

        Moon phobos = new Moon("Phobos", mars, Color.TAN, 10);
        mars.add(phobos);
        solarSystem.addMoon(phobos, 25);

        Moon deimos = new Moon("Deimos", mars, Color.WHEAT, 10);
        mars.add(deimos);
        solarSystem.addMoon(deimos, 40);

        //Initialize Stage
        primaryStage.setTitle("SolarSystem");
        primaryStage.setScene(solarSystem.scene);
        primaryStage.show();
    }
}