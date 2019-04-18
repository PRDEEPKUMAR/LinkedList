
#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node* next;
};
void append(struct Node** headRef, int newData)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *headRef;
	new_node->data = newData;
	new_node->next = NULL;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}
int modularNode(Node* head, int k);
int modularNode(Node* head, int k)
{
    Node* n=head;
    int last=-1,count=1;
    while(n!=NULL)
    {
        if(count%k==0)
            last=n->data;
        n=n->next;
        count++;

    }
    return last;

}
int main()
{
    int t;
    cin>>t;
    while(t--){
        struct Node* head = NULL;
        int n, tmp, k;
        cin>>n;
        while(n--){
            cin>>tmp;
            append(&head, tmp);
        }
        cin>>k;
        cout<<modularNode(head, k)<<endl;
    }
	return 0;
}

