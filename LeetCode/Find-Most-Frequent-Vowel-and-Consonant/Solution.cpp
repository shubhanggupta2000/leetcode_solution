class Solution {
public:
    int maxFreqSum(string s) {
        // Define sets for vowels
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        // Frequency array for all lowercase letters
        vector<int> freq(26, 0);

        // Count frequencies of each character in the string
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int maxVowelFreq = 0;
        int maxConsonantFreq = 0;

        for (int i = 0; i < 26; ++i) {
            char ch = 'a' + i;
            if (vowels.count(ch)) {
                maxVowelFreq = max(maxVowelFreq, freq[i]);
            } else {
                maxConsonantFreq = max(maxConsonantFreq, freq[i]);
            }
        }

        return maxVowelFreq + maxConsonantFreq;
    }
};
