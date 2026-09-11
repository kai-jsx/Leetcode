class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int possible = 0;
        vector<int> count(10, 0);
        
        // Step 1: Count inventory
        for (int d : digits) {
            count[d] += 1;
        }

        // Step 2: Loop through all 3-digit even numbers
        for (int i = 100; i < 1000; i += 2) {
            int u = i % 10;
            int t = (i / 10) % 10;
            int h = i / 100;

            // Step 3: Track what digits this specific number needs
            vector<int> req(10, 0);
            req[u]++;
            req[t]++;
            req[h]++;

            // Step 4: Verify if we have enough in our inventory
            bool canBuild = true;
            for (int j = 0; j < 10; j++) { // Use 'j' here so 'i' isn't ruined!
                if (count[j] < req[j]) {
                    canBuild = false;
                    break;
                }
            }

            // Step 5: If valid, increment our counter
            if (canBuild) {
                possible++;
            }
        }

        return possible;
    }
};