package votingsystem;
import exceptions.MissingCandidateException;
import java.util.ArrayList;

public class VotingMachine {
    public ArrayList<Candidate> candidates = new ArrayList<Candidate>();

    public VotingMachine(Candidate[] candidates) throws MissingCandidateException {
        for (int i = 0; i < candidates.length; i++) {
            this.candidates.add(candidates[i]);
        }
        if (candidates == null) {
            throw new MissingCandidateException("The candidate list cannot be null or empty");
        }
    }

    public void vote(Voter v, Candidate c) throws MissingCandidateException{
        if (!v.hasVoted()){
            if (candidates.contains(c)) {
                c.incrementVoteCount();
                v.voted();
            }
            else {
                throw new MissingCandidateException("Candidate does not exist in the candidates collection");
            }
        }
    }
    public void tally(){
        for (int i = 0; i < candidates.size();i++){
            System.out.println(candidates.get(i).getFullName() + " has "+ candidates.get(i).getVoteCount() + " votes");
        }
    }
}