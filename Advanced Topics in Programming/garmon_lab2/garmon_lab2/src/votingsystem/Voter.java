/*** @author Elijah Garmon
 *   0424
 *   2/10/23
 *  An abstract class for a Voter
 */
package votingsystem;

import exceptions.MinimumAgeException;

public class Voter extends Person{
    //Voter Variables
    private int voterId;
    private boolean voted;

    //Voter Constructor
    public Voter(int voterId,int age, char gender, String firstName, String lastName, String politicalParty) throws MinimumAgeException {
        super(age, gender, firstName, lastName, politicalParty);
        if (age < 18){
            throw new MinimumAgeException("Candidate's age cannot be less than 25");
        }
        else {
            this.voterId = voterId;
        }
    }

    //Voter Getters
    public int getVoterId() {
        return voterId;
    }

    public boolean hasVoted() {
        return voted;
    }

    public void voted() {
        voted = true;
    }

    public String getFullName() {
        return firstName + " " + lastName;
    }
}
