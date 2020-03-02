#include <iostream>
using namespace std;
#include<map>
//超出时间限制
//其实没超时 因为题目描述问题 树中是不能存在.的 也是自己不了解正则匹配

class WordDictionary {
private:
	class Node
	{
	public:
		bool isWord;
		map<char, Node*> dict;
		Node()
		{
			this->isWord = false;
		}
	};
	int size;
	Node* root;
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		size = 0;
		root = new Node();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		Node* move = root;
		for (auto c : word)
		{
			if (move->dict.find(c) == move->dict.end())
			{
				move->dict.insert(pair<char, Node*>(c, new Node()));
			}
			move = move->dict[c];
		}
		if (move->isWord == false)
		{
			move->isWord = true;
			size++;
		}
	}
	bool search(Node* node, string word)
	{
		if (word.size() == 0) return node->isWord;
		if (word[0] == '.')
		{
			string newword = word.substr(1);
			bool res = false;
			for (map<char, Node*>::iterator it = node->dict.begin(); it != node->dict.end(); it++)
			{
				res = res || search(node->dict[(*it).first], newword);
			}
			return res;
		}
		else
		{
			string newword = word.substr(1);
			if (node->dict.find('.') != node->dict.end() && node->dict.find(word[0]) == node->dict.end())
			{
				return search(node->dict['.'], newword);
			}
			else if (node->dict.find(word[0]) != node->dict.end() && node->dict.find('.') == node->dict.end())
			{
				return search(node->dict[word[0]], newword);
			}
			else if (node->dict.find('.') != node->dict.end() && node->dict.find(word[0]) != node->dict.end())
			{
				return search(node->dict['.'], newword) || search(node->dict[word[0]], newword);
			}
			else return false;

		}

	}
	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return search(root, word);
	}
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary* obj = new WordDictionary();
* obj->addWord(word);
* bool param_2 = obj->search(word);
*/