/*** @author Elijah Garmon
 *   0424
 *   2/10/23
 *  An abstract class for a candidate
 */
package votingsystem;

import exceptions.MinimumAgeException;

public class Candidate extends Person{
    //Candidate Variables
    private int voteCount;

    //Constructor
    public Candidate(int age, char gender, String firstName, String lastName, String politicalParty) throws MinimumAgeException {
        super(age, gender, firstName, lastName, politicalParty);
        if (age < 25){
            throw new MinimumAgeException("Candidate's age cannot be less than 25");
        }
        else {
            this.voteCount = 0;
        }
    }
    //get the amount of votes for a candidate
    public int getVoteCount() {
        return voteCount;
    }

    //give a candidate one more vote
    public void incrementVoteCount() {
        voteCount++;
    }

    //give the full name and party of a candidate
    public String getFullName() {
        if (politicalParty.equals("Democrat")) {
            return firstName + " " + lastName + " - D";
        }
        else if (politicalParty.equals("Republican")){
            return firstName + " " + lastName + " - R";
        }
        else if (politicalParty.equals("Non-Affiliate")){
            return firstName + " " + lastName + " - NA";
        }
        else {
            return firstName + " " + lastName;
        }
    }
}
