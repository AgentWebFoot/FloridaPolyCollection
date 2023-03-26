/*** @author Elijah Garmon
 *   0424
 *   2/22/23
 *  Exception for when a duplicated celestial body is made
 */
package exceptions;

public class DuplicateCelestialBodyException extends Exception {
    public DuplicateCelestialBodyException(String argMessage) {
        super(argMessage);
    }
}
