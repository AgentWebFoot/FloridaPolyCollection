/**
 * @author E. Garmon 
 * Student number: 0424 
 * date: 2/6/2023 
 * EXPLAINATION OF HOW CODE WORKS 
 */

import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        //Array
        int array[][] = {{5, 3, 4, 0, 7, 8, 9, 1, 2},
                {6, 7, 0, 1, 9, 5, 3, 4, 8},
                {1, 9, 8, 3, 4, 2, 5, 0, 7},
                {8, 0, 9, 7, 6, 1, 4, 2, 3},
                {4, 2, 6, 8, 0, 3, 7, 9, 0},
                {7, 1, 3, 9, 2, 4, 8, 5, 6},
                {9, 0, 1, 5, 3, 7, 2, 8, 4},
                {2, 8, 7, 4, 1, 9, 6, 0, 5},
                {3, 4, 5, 2, 8, 6, 1, 7, 9}};
        Scanner input = new Scanner(System.in);

        while (endGame()) {
            //Output Array
            display(array);
            //Row Input 
            System.out.print("Insert a row: ");
            int row = input.nextInt();
            if (isValidValue(row)) {
                //Column Input 
                System.out.print("Insert a column: ");
                int column = input.nextInt();
                if (isValidValue(column)) {
                    if (isRowColumnValid(array, row, column)) {
                        //Value Input 
                        System.out.print("Insert a value: ");
                        int value = input.nextInt();
                        //Is Answer Correct 
                        if (isValidValue(value)) {
                            if (isEntryCorrect(row, column, value, array)) {
                                array[row-1][column-1] = value;
                                //Is the program solved? 
                                if (isSolved(array)){
                                    System.out.print("Congratulations the array has been solved");
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    public static boolean endGame() {
        //Taking Input 
        Scanner input = new Scanner(System.in);
        System.out.println("Would you to continue playing? (Y/N)");
        String end = input.nextLine();
        //Continue Loop 
        if ((end.toUpperCase()).equals("Y")){
            return true;
        }
        //End Loop 
        else if ((end.toUpperCase()).equals("N")){
            System.out.println("Ending Game");
            return false;
        }
        else {
            return endGame();
        }
    }
    public static boolean isValidValue(int value){
        //Determine if input is greater than or equal to 1 and less than or equal to 9 
        if (value >= 1){
            if (value <= 9) return true;
            else {
                System.out.println("Invalid");
                return false;
            }
        }
        else {
            System.out.println("Invalid");
            return false;
        }
    }

    public static void display(int array[][]){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                System.out.print(array[i][j]+" ");
                if (((j+1) % 3) == 0){
                    if ((j+1) != 9) {
                        System.out.print("| ");
                    }
                }
            }
            System.out.println();
            if (((i+1) % 3) == 0){
                if ((i+1) != 9) {
                    System.out.println("------+-------+-------");
                }
            }
        }
        System.out.println();
    }

    //Determine if the position has a value of 0
    public static boolean isRowColumnValid(int array[][], int row, int column){
        if (array[row-1][column-1] == 0) {
            return true;
        }
        else {
            System.out.println("Position is not a 0");
            return false;
        }
    }

    //Determine if any 0s are left
    public static boolean isSolved(int array[][]){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (array[i][j] == 0){
                    return false;
                }
            }
        }
        return true;
    }

    //Determine if there is a repeated number
    public static boolean isEntryCorrect(int row, int column, int value, int array[][]){
        //Determine if there is a repeat in the row
        for (int i = 0; i < 9; i++){
            if (value == array[row - 1][i]){
                System.out.println("The number "+value+" is already in this row");
                return false;
            }
        }
        //Determine if there is a repeat in the column
        for (int i = 0; i < 9; i++) {
            if (value == array[i][column - 1]) {
                System.out.println("The number "+value+" is already in this column");
                return false;
            }
        }
        //Determine if there is a repeat in the box
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (value == array[(row / 3) + i][column / 3]+j) {
                    System.out.println("The number " + value + " is already in this box");
                    return false;
                }
            }
        }
        System.out.println("Correct");
        return true;
    }
} 