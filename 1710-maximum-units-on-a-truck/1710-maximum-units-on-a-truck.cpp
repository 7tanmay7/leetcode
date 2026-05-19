class Solution {
public:
    int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) {
        // Step 1: Sort box types by units per box in descending order
        std::sort(boxTypes.begin(), boxTypes.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] > b[1]; 
        });
        
        int totalUnits = 0;
        
        // Step 2: Loop through the sorted box types
        for (const auto& box : boxTypes) {
            int numBoxes = box[0];
            int unitsPerBox = box[1];
            
            if (truckSize <= 0) break; // Truck is completely full
            
            // Take either all available boxes of this type, or whatever space is left on the truck
            int boxesToTake = std::min(numBoxes, truckSize);
            
            totalUnits += boxesToTake * unitsPerBox;
            truckSize -= boxesToTake; // Reduce remaining capacity
        }
        
        return totalUnits;
    }
};