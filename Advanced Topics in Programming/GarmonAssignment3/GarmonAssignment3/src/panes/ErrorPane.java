package panes;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import javafx.stage.Stage;

/*** @author Elijah Garmon
 *   0424
 *   3/26/23
 *  Create Error Pane
 */

public class ErrorPane extends VBox{
    public ErrorPane(String errorMessage){
        Stage stage2 = new Stage();
        Pane pane = new Pane();
        VBox vBox = new VBox();
        vBox.setPadding(new Insets(15, 5, 5, 5));
        vBox.getChildren().addAll(new Text(errorMessage));
        pane.getChildren().add(vBox);
        Scene error = new Scene(pane, 250, 100);
        stage2.setScene(error);
        stage2.show();
    }
}
