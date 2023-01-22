/**
 * @Author- Elijah Garmon
 * Student Number - 0424
 * Date- 1/22/23
 * This class calculates the sum between the num * random and limit * random
 * The class also contains the main method
 */
import java.util.Scanner;
import static java.lang.Math.random;

public class Main {
    public static void main(String[] args) {
        // Input
        Scanner input = new Scanner(System.in);
        System.out.println("Enter a Number");
        int num = input.nextInt();

        //Determine if limit is greater than num, otherwise ask for a new limit value
        int limit = 0;
        while (limit < num) {
            System.out.println("Enter a Limit");

            limit = input.nextInt();
            if (limit < num) {
                System.out.println("Limit must be greater than the first number");
            }
        }
        // Output
        System.out.println("The sum of integers between these numbers is " + sum(num, limit));
    }

    static int sum (int num, int limit){
        // Choose random numbers for rand1 and random2 between 3 and 8
        int rand1 = (int) ((random()*5)+3);
        int rand2 = (int) ((random()*5)+3);

        // Determine the difference between limit*rand2 and rand1*num
        int sum = (limit*rand2) - (rand1*num);

        //Determine the absolute value of the difference
        sum = Math.abs(sum);

        //Output difference
        return sum;
    }
}

