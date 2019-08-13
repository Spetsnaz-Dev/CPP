void nArrayTree::MirrorOfNArrayTree(nArrayNode *temp)

{

//cout<<"\nEntering findMirrorImage\n";

queue<narraynode *> q;

q.push(temp);//Root element is push to the Q

while(!q.empty())

{

//cout<<"Inside while(!q.empty())\n";

nArrayNode *itr = q.front();//fetch front node from the q

int cCount = 0;

if(itr != NULL)

cCount = itr->child.size();//Finding the number of childs to this Node

//cout<<itr->data<<" nodes childs are getting reversed\n";

if(cCount > 1)//atlease two childs are needed to perform the reverse

reverse(itr->child.begin(), itr->child.end());//This has reverse the child vectors of this Node, node is fetched from Q

//cout<<"After performing reverse\n";

if(cCount >= 1)//If no childs then nothing to push to the Q

{

for(int x = 0; x<cCount; x++)
    q.push(itr->child[x]);

}

//cout<<"After Inserting all childs\n";

q.pop();//Remove the processed node from queue and all child are inseted

}

}