/*** @author Elijah Garmon
 *   0424
 *   2/10/23
 *  Main file for the voting system
 */
package votingsystem;
import exceptions.MinimumAgeException;
import exceptions.MissingCandidateException;

public class Election {
    public static void main(String[] args) throws MinimumAgeException, MissingCandidateException {
        //Create Candidates
        Candidate c1 = new Candidate(40, 'M', "Some", "Candidate", "Non-Affiliate");
        Candidate c2 = new Candidate(37, 'M', "John", "Smith", "Republican");
        Candidate c3 = new Candidate(36, 'F', "Jane", "Doe", "Democrat");

        //Create array of Candidates
        Candidate[] candidates= {c1, c2, c3};

        //Create Voting Machine
        VotingMachine vm = new VotingMachine(candidates);

        //Create Voters
        Voter v1 = new Voter(1, 20, 'M',"Elijah", "Garmon", "Republican");
        Voter v2 = new Voter(2, 18, 'M',"Colin", "Brown", "Non-Affiliate");
        Voter v3 = new Voter(3, 19, 'M',"Sam", "Barrett", "Democrat");
        Voter v4 = new Voter(4, 22, 'M',"Matthew", "Guinta", "Republican");
        Voter v5 = new Voter(5, 18, 'F',"Rileigh", "Garmon", "Republican");

        //All Voters Vote
        vm.vote(v1,c2);
        vm.vote(v1,c1);
        vm.vote(v2,c1);
        vm.vote(v3,c3);
        vm.vote(v4,c2);
        vm.vote(v5,c2);

        //Tally Votes
        vm.tally();
    }
}
