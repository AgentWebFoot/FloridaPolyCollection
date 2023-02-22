/*** @author Elijah Garmon
 *   0424
 *   2/22/23
 *  Exception for when a celestial body orbits the wrong type of object
 */
package exceptions;

public class InvalidCelestialBodyException extends Exception {
    public InvalidCelestialBodyException(String argMessage) { super(argMessage);}
}
