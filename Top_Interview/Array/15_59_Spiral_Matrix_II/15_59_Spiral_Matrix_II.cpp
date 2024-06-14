#include <iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<vector<int>> generateMatrix(int n){

        //Define a 2D array using `vector`
        vector<vector<int>> res(n, vector<int>(n, 0));

        //Each layer loops a few times. 
        //For example, if n is an odd number, such as 3, then loop = 1 means looping through one layer. 
        //The center value of the matrix needs to be handled separately
        int loop = n / 2 ;

        //Define starting point in X and Y in the beginning.
        int startX = 0;
        int startY = 0;

        
        //It's necessary to control the traversal length of each edge. 
        //The right boundary shrinks by one position in each loop.
        int offset = 1;

        //Used to assign a value to each cell in the matrix.
        int count = 1;

        //If n % 2 != 0, n is an odd number, 
        //the center position of the matrix needs to be assigned a value separately.
        int mid = n / 2;


        while(loop--){

            int i = startX;
            int j = startY;

            //Simulate filling the top row from left to right (left-closed, right-closed)
            for(j; j < n - offset; j++){
                res[i][j] = count++;
            }

            //Simulate filling the right row from top to down
            for(i; i < n - offset; i++){
                res[i][j] = count++;
            }

            //Simulate filling the bottom row from right to left
            for(j; j > startY; j--){
                res[i][j] = count++;
            }

            //Simulate filling the left row from down to top
            for(i; i > startX; i--){
                res[i][j] = count++;
            }

            //When starting the second layer, the starting position increases by 1 for both coordinates.
            //For example, the starting position for the first layer is (0, 0), and for the second layer, it is (1, 1).
            startX++;
            startY++;
            //`offset` controls the traversal length of each edge in each layer.
            offset++;
        }

        //If n % 2 != 0, n is an odd number.
        //Need to fill the last position in the middle
        if(n % 2){
            res[mid][mid] = n * n;
        }
        return res;
    };
};




int main(){
    Solution solution;
    int n = 3;

    vector<vector<int>> res = solution.generateMatrix(n);

    //Print 2D array
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<< res[i][j] << endl;
        }
        cout <<endl;
    }

    return 0;

}