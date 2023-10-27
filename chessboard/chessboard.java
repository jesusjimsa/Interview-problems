/* 
    ## Description

    The chessboard bellow has 64 squares, 8 rows and 8 columns. Each row is labeled from 1 to 8 and each column is
    labeled from a to h (lowercase).  
    A square is located at the intersection of a row and of a column, like square 2C it's the intersection of the row 2
    and column C.

    Positioning a pawn to a starting square, you need to find out where it will be the end square after moving it R
    times (rows) vertically to the top and C times (columns) horizontally to the right. If during the moves the pawn
    reaches the end of the board, it will start again from the opposite direction like in the examples below.

    #### INPUT
    ```
    string    startPosition
    number    rows
    number    columns
    ```

    #### OUTPUT
    ```
    string    endPosition
    ```

    #### EXAMPLE 1
    **Input**
    ```
    startPosition: 2b, rows: 3, columns: 2
    ```

    **Output**
    ```
    5d
    ```

    #### EXAMPLE 2
    **Input**
    ```
    startPosition: 5h, rows: 11, columns: 25
    ```

    **Output**
    ```
    8a
    ```

 */


public class Solution {

    private static int getColumnNum(char columnPos) {
        int col = 0;

        switch (columnPos) {
            case 'a':
                col = 1;
                break;
            case 'b':
                col = 2;
                break;
            case 'c':
                col = 3;
                break;
            case 'd':
                col = 4;
                break;
            case 'e':
                col = 5;
                break;
            case 'f':
                col = 6;
                break;
            case 'g':
                col = 7;
                break;
            case 'h':
                col = 8;
                break;
            default:
                col = -1;
                break;
        }

        return col;
    }

    private static char getColumnLetter(int columnPos) {
        char col = 'a';

        switch (columnPos) {
            case 1:
                col = 'a';
                break;
            case 2:
                col = 'b';
                break;
            case 3:
                col = 'c';
                break;
            case 4:
                col = 'd';
                break;
            case 5:
                col = 'e';
                break;
            case 6:
                col = 'f';
                break;
            case 7:
                col = 'g';
                break;
            case 8:
                col = 'h';
                break;
            default:
                col = 'a';
                break;
        }

        return col;
    }

	public static String run(String startPosition, int rows, int columns) {
		/*
		* Write your code below; return type and arguments should be according to the problem's requirements
		*/

        String endPosition = "";
        int initR = startPosition.charAt(0) - '0';  // Get rows position integer
        int initC = getColumnNum(startPosition.charAt(1));  // Get column int equivalent

        if (initC == -1) {
            return "";
        }

        // Calculate new row position
    	int newRow = (initR + rows - 1) % 8 + 1;
    
		// Calculate new column position
		int newCol = (initC + columns - 1) % 8 + 1;

        endPosition = Integer.toString(newRow) + getColumnLetter(newCol);

        endPosition = Integer.toString(initR) + getColumnLetter(initC);

		return endPosition;
	}
}

public class Main {
    public static void main(String[] args) {
        String startPosition = "2b"; // Starting position
        int rows = 3; // Number of rows to move
        int columns = 2; // Number of columns to move

        // Call the run method from the Solution class
        String endPosition = Solution.run(startPosition, rows, columns);

        // Print the end position
        System.out.println("End Position: " + endPosition);
    }
}
