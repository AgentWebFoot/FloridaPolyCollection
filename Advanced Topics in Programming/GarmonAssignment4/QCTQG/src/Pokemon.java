/*** @author Elijah Garmon
 *   0424
 *   4/17/23
 *  Create Pokemon Class
 */
import java.util.UUID;
import java.io.Serializable;

public class Pokemon implements Serializable {
    //Declaring All Variables
    private UUID pokemonID;
    private String pokemonType;
    private String name;
    private boolean checkedIn;

    //Constructor
    public Pokemon(String pokemonType, String name) {
        this.pokemonID = UUID.randomUUID();
        this.pokemonType = pokemonType;
        this.name = name;
    }

    //Getter
    public UUID getPokemonID() {
        return pokemonID;
    }

    public String getPokemonType() {
        return pokemonType;
    }

    public String getName() {
        return name;
    }

    public boolean isCheckedIn() {
        return checkedIn;
    }

    //Setters
    public void checkedIn() {
        this.checkedIn = true;
    }

    public void checkedOut() {
        this.checkedIn = false;
    }
}
