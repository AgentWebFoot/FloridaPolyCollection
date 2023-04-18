/*** @author Elijah Garmon
 *   0424
 *   4/18/23
 *  Create Server
 */

import java.io.*;
import java.net.*;
import java.util.Date;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.scene.Scene;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextArea;
import javafx.stage.Stage;

public class PokemonDayCare extends Application {
    //Amount of Connection
    int connection = 0;

    // FX rea
    private TextArea ta = new TextArea();

    // Override the start method in the Application class
    @Override
    public void start(Stage primaryStage) {
        //
        Scene scene = new Scene(new ScrollPane(ta), 450, 200);
        primaryStage.setTitle("PokemonDayCare");
        primaryStage.setScene(scene);
        primaryStage.show();

        //Create New Client Thread
        new Thread( () -> {
            try {
                ServerSocket serverSocket = new ServerSocket(8000);
                ta.appendText("Server started at "
                        + new Date() + '\n');

                while (true) {
                    Socket socket = serverSocket.accept();
                    //Increase connection amount
                    connection++;
                    Platform.runLater( () -> {
                        ta.appendText("New connection made with trainer. Total connections = " + connection + '\n');

                        InetAddress inetAddress = socket.getInetAddress();
                        ta.appendText("Trainer's IP Address is "
                                + inetAddress.getHostAddress() + "\n");
                    });
                    new Thread(new connectToClient(socket)).start();
                }
            }
            catch(IOException ex) {
                System.err.println(ex);
            }
        }).start();
    }

    //Connect to Client
    class connectToClient implements Runnable{
        private Socket socket;
        public connectToClient(Socket socket) {
            this.socket = socket;
        }
        //Print Stored Pokemon
        public void run() {
            try {
                ObjectInputStream isFromClient = new ObjectInputStream(
                        socket.getInputStream());

                while (true) {
                    Pokemon poke = (Pokemon) isFromClient.readObject();

                    if (poke.isCheckedIn())
                        ta.appendText("Pokemon " + poke.getName() + " has been checked in. \n");
                    else
                        ta.appendText("Pokemon " + poke.getName() + " has been checked out. \n");
                }

            } catch (IOException ex) {
                System.err.println(ex);
            } catch (ClassNotFoundException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public static void main(String[] args) {
        launch(args);
    }
}
