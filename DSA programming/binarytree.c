#include <stdio.h>

int main(){
    search(1, 1);
}

struct node *search(int key, struct node *leaf) {
    if( leaf != 0 )
    {
        if(key==leaf->key_value) {
            return leaf;
        }
        else if(key<leaf->key_value) {
            return search(key, leaf->left);
        }
        else {
            return search(key, leaf->right);
        }
    }
    else return 0;
}