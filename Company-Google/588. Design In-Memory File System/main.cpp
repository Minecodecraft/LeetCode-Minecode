//
//  main.cpp
//  588. Design In-Memory File System
//
//  Created by Jaylen Bian on 3/29/21.
//  Copyright © 2021 边俊林. All rights reserved.
//

#include <map>
#include <set>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class FileSystem {
    struct Node {
        string name;
        map<string, Node *> subdirs;
        bool isDir;
        string content;

        Node(string name, bool isDir) : name(name), isDir(isDir) {
            this->subdirs = {};
            this->content = "";
        }
    };
    Node* root;

    Node* getNode(string path, bool createIfMissed, bool filePath) {
        path += "/";
        int p = 1, nxt = path.find("/", p+1);
        Node *pNode = root;
        while (p < path.length() && nxt != string::npos) {
            string subpath = path.substr(p, nxt-p);
            if (pNode->subdirs.count(subpath) == 0) {
                if (createIfMissed)
                    pNode->subdirs[subpath] = new Node(subpath, !filePath || nxt+1 < path.length());
                else
                    return NULL;
            }
            pNode = pNode->subdirs[subpath];
            p = nxt+1;
            nxt = path.find("/", p+1);
        }
        return pNode;
    }

public:
    FileSystem() {
        root = new Node("root", true);
    }

    vector<string> ls(string path) {
        Node* node = getNode(path, false, false);
        if (node == NULL)
            return {};
        if (node->isDir) {
            vector<string> res;
            for (auto subnode: node->subdirs)
                res.push_back(subnode.first);
            return res;
        } else {
            return {node->name};
        }
    }

    void mkdir(string path) {
        int p = (int)path.rfind('/');
        string subpath = path.substr(0, p);
        string dirname = path.substr(p+1);
        Node* node = getNode(subpath, true, false);
        for (auto subnode: node->subdirs) {
            if (subnode.first == dirname)
                return;
        }
        node->subdirs[dirname] = new Node(dirname, true);
    }

    void addContentToFile(string filePath, string content) {
        Node* node = getNode(filePath, true, true);
        if (node == NULL || node->isDir)
            return;
        node->content += content;
    }

    string readContentFromFile(string filePath) {
        Node* node = getNode(filePath, true, true);
        if (node == NULL || node->isDir)
            return "";
        return node->content;
    }

    void printNode() {
        queue<Node *> q;
        q.push(root);
        int depth = 0;
        while (q.size()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                Node *pNode = q.front();
                q.pop();
                cout << string(depth * 2, '-') << pNode->name << endl;
                if (pNode->isDir) {
                    for (auto subdir: pNode->subdirs)
                        q.push(subdir.second);
                }
            }
            depth++;
        }
    }
};

int main() {
    FileSystem fs = FileSystem();

    vector<string> ls = fs.ls("/");
    cout << "{";
    for_each(ls.begin(), ls.end(), [](string s) { cout << s << ", " ; });
    cout << "}" << endl;

    fs.mkdir("/a/b/c");

    fs.addContentToFile("/a/b/c/d", "hello");
    vector<string> ls2 = fs.ls("/a/b");
    cout << "{";
    for_each(ls2.begin(), ls2.end(), [](string s) { cout << s << ", "; });
    cout << "}" << endl;

    string content = fs.readContentFromFile("/a/b/c/d");
    cout << content << endl;

//    fs.printNode();

    return 0;
}
