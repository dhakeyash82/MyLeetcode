class Solution {
public:
    bool canAliceWin(int n) {
        int stonesToRemove = 10;
        bool aliceTurn = true; // true if it's Alice's turn, false for Bob
        
        while (n >= stonesToRemove) {
            n -= stonesToRemove;
            stonesToRemove--;
            aliceTurn = !aliceTurn; // Switch turn
        }
        
        return !aliceTurn;
    }
};