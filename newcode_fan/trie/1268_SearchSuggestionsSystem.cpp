//
//  1268_SearchSuggestionsSystem.cpp
//  leetcode
//
//  Created by Wenjing Fan on 2020/12/25.
//

#include <vector>
#include <iostream>
using namespace std;

struct Trie {
    vector<Trie*> nodes;
    vector<const string*> words;
    
    Trie(): nodes(26) {}
    ~Trie() {
        for (auto node : nodes) {
            delete node;
        }
    }
    
    void addWord(Trie* root, const string &word) {
        for (char c : word) {
            if (root->nodes[c - 'a'] == nullptr) root->nodes[c - 'a'] = new Trie();
            root = root->nodes[c - 'a'];
            // add sorted words and keep only 3 words
            if (root->words.size() < 3) root->words.push_back(&word);
        }
    }
    
    vector<vector<string>> getWords(Trie* root, const string& prefix) {
        vector<vector<string>> ans(prefix.size());
        for (int i = 0; i < prefix.size(); ++i) {
            char c = prefix[i];
            root = root->nodes[c - 'a'];
            if (root == nullptr) break;
            for (auto word : root->words) ans[i].push_back(*word);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(begin(products), end(products));
        Trie root;
        for (const auto& product : products) root.addWord(&root, product);
        return root.getWords(&root, searchWord);
    }
};
