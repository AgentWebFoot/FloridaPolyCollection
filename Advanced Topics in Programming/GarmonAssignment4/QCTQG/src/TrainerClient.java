/*** @author Elijah Garmon
 *   0424
 *   4/18/23
 *  Create Client
 */

import java.io.*;
import java.net.Socket;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;
public class TrainerClient extends Application {
    //Create Fields
    private final Button btSend = new Button("Send to day care");
    private final Button btCollect = new Button("Pick up from day care");
    private final TextField tfpokemonName = new TextField();
    ObservableList<String> types = FXCollections.observableArrayList("Bulbasaur", "Charmander", "Squirtle", "Pikachu");
    private final ComboBox<String> ddPokemonType = new ComboBox<String>(types);

    ObjectOutputStream toServer;

    @Override
    public void start(Stage primaryStage){
        //Place Fields on Pane
        GridPane gridPane = new GridPane();
        gridPane.add(new Label("Choose a Pokemon Type"), 0, 0);
        gridPane.add(ddPokemonType, 1, 0);
        gridPane.add(new Label("Pokemon's Name"), 0, 1);
        gridPane.add(tfpokemonName, 1, 1);
        gridPane.add(btSend, 0, 2);
        gridPane.add(btCollect, 1, 2);

        BorderPane pane = new BorderPane();
        pane.setTop(gridPane);

        //Create Scene
        Scene scene = new Scene(pane, 450, 200);
        primaryStage.setTitle("Trainer Client");
        primaryStage.setScene(scene);
        primaryStage.show();

        try {
            Socket connectToServer = new Socket("localhost", 8000);
            toServer = new ObjectOutputStream(connectToServer.getOutputStream());
        }
        catch (IOException ex){
            System.err.println(ex);
        }

        btSend.setOnAction(e->sendExchangeDataWithServer());
        btCollect.setOnAction(e->receiveExchangeDataWithServer());
        btCollect.setDisable(true);
    }
    //Send Pokemon Away
    public void sendExchangeDataWithServer() {
        try {
            Pokemon poke = new Pokemon(ddPokemonType.getTypeSelector(), tfpokemonName.getText().trim());
            poke.checkedIn();
            btSend.setDisable(true);
            btCollect.setDisable(false);
            ddPokemonType.setDisable(true);
            tfpokemonName.setDisable(true);
            toServer.writeObject(poke);
            toServer.flush();
            toServer.reset();
        }
        catch (IOException ex){
            System.err.println(ex);
        }
    }

    //Take Pokemon Back
    public void receiveExchangeDataWithServer() {
        try {
            Pokemon poke = new Pokemon(ddPokemonType.getTypeSelector(), tfpokemonName.getText().trim());
            poke.checkedOut();
            btSend.setDisable(false);
            btCollect.setDisable(true);
            ddPokemonType.setDisable(false);
            tfpokemonName.setDisable(false);
            toServer.writeObject(poke);
            toServer.flush();
            toServer.reset();
        }
        catch (IOException ex){
            System.err.println(ex);
        }
    }

    public static void main(String[] args){
        launch(args);
    }
}