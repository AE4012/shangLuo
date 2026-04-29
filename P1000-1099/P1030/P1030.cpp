#include<iostream>

using namespace std;

string getPreOrder(const string &inorder, const string &postorder){
    if(inorder.empty()){
        return "";
    }
    else{
        char root = postorder[postorder.size() - 1];
        int k = inorder.find(root);
        string left = getPreOrder(inorder.substr(0,k), postorder.substr(0,k));
        string right = getPreOrder(inorder.substr(k+1), postorder.substr(k, inorder.size()-k-1));
        return root + left + right;
    }
}

int main(){
    string inorder, postorder;

    cin >> inorder >> postorder;
    
    cout << getPreOrder(inorder, postorder) << endl;

    return 0;
}