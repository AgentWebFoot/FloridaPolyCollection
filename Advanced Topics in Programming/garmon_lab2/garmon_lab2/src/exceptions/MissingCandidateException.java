package exceptions;

public class MissingCandidateException extends Exception{
    public MissingCandidateException(String argMessage){
        super (argMessage);
    }
}
