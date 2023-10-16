import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> row = new ArrayList<>();
        
        for (int i = 0; i <= rowIndex; i++) {
            row.add(1); // The first and last elements are always 1.
            for (int j = i - 1; j > 0; j--) {
                // Calculate the middle elements using the values from the previous row.
                row.set(j, row.get(j) + row.get(j - 1));
            }
        }
        
        return row;
    }
}