class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encodedString = "";

        for (auto& s: strs) {
            for (char c: s) {
                if (c == '/') encodedString += "//";
                else encodedString += c;
            }
            encodedString += "/:";
        }

        return encodedString;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decodedStrings;
        string currentString;
        
        for (int i=0; i<s.size(); ++i) {
            if (i < s.size()-1 && s[i] == '/' && s[i+1] == ':') {
                decodedStrings.push_back(currentString);
                currentString.clear();
                i += 1;
            } else if (i < s.size()-1 && s[i] == '/' && s[i+1] == '/') {
                currentString += '/';
                i += 1;
            } else {
                currentString += s[i];
            }
        }
        
        return decodedStrings;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));