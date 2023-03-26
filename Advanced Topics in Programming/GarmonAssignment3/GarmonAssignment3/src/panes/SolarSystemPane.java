package panes;

import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import solarsystem.Moon;
import solarsystem.Planet;
import solarsystem.Star;

/*** @author Elijah Garmon
 *   0424
 *   3/26/23
 *  Create Pane for the solar system
 */

public class SolarSystemPane extends Pane {
    public static Pane SolarSystem = new Pane();
    public static Scene scene = new Scene(SolarSystem, 1500, 800);

    public SolarSystemPane() {
        scene.setFill(Color.color(0,0,0));
    }

    public void addStar(Star star){
        Circle circle = new Circle(0, 0,star.getRadius());
        SolarSystem.getChildren().addAll(circle);
        star.setCenterX(circle.getCenterX());
        star.setCenterY(circle.getCenterY());
        circle.setFill(Color.YELLOW);
        circle.requestFocus();
    }

    public void addPlanet(Planet planet, double distance){
        //Create Orbit
        Circle orbit = new Circle(planet.getOrbit().getCenterX(), planet.getOrbit().getCenterY(), distance);
        SolarSystem.getChildren().add(orbit);
        orbit.setStroke(Color.WHITE);
        orbit.setFill(Color.TRANSPARENT);

        //Create Planet
        Circle circle = new Circle(distance+planet.getOrbit().getCenterX(), distance+planet.getOrbit().getCenterY(), planet.getRadius());
        SolarSystem.getChildren().add(circle);
        planet.setCenterX(circle.getCenterX());
        planet.setCenterY(circle.getCenterY());
        circle.setFill(planet.getFill());

        //Show Planet and Orbit
        orbit.setRadius(Math.sqrt(Math.pow(planet.getOrbit().getLayoutX() - distance, 2) + Math.pow(planet.getOrbit().getLayoutY()-distance, 2)));
        orbit.requestFocus();
        circle.requestFocus();
        orbit.setMouseTransparent(true);

        //Change to Transparent
        circle.setOnMousePressed(e -> {
            planet.getOrbitInformation();
        });
    }

    public void addMoon(Moon moon, double distance){
        //Create Orbit
        Circle orbit = new Circle(moon.getOrbit().getCenterX(), moon.getOrbit().getCenterY(), distance);
        SolarSystem.getChildren().add(orbit);
        orbit.setStroke(Color.WHITE);
        orbit.setFill(Color.TRANSPARENT);

        //Create Planet
        Circle circle = new Circle(distance+moon.getOrbit().getCenterX(), distance+moon.getOrbit().getCenterY(), moon.getRadius());
        SolarSystem.getChildren().add(circle);
        circle.setFill(moon.getFill());

        //Show Planet and Orbit
        orbit.setRadius(Math.sqrt(Math.pow(moon.getOrbit().getLayoutX() - distance, 2) + Math.pow(moon.getOrbit().getLayoutY()-distance, 2)));
        orbit.requestFocus();
        circle.requestFocus();
        orbit.setMouseTransparent(true);

        //Change to Transparent
        circle.setOnMousePressed(e -> {
            moon.getOrbitInformation();
        });
    }
}
