package votingsystem;
/*** @author Elijah Garmon
 *   0424
 *   2/10/23
 *   An abstract class to describe a general person
 */
public abstract class Person {
    //Default variables
    private int age;
    private char gender;
    protected String firstName;
    protected String lastName;
    protected String politicalParty;

    //Basic Constructors
    public Person(int age, char gender, String firstName, String lastName, String politicalParty) {
        this.age = age;
        this.gender = gender;
        this.firstName = firstName;
        this.lastName = lastName;
        this.politicalParty = politicalParty;
    }

    //All Getters
    public int getAge() {
        return age;
    }

    public char getGender() {
        return gender;
    }

    public String getFullName() {
        return firstName+" "+lastName;
    }
}
