void deleteNode(Node *node)
{
    int t = node->data;
    node->data = node->next->data;
    node->next->data = t;
    
    Node *temp = node->next;
    node->next = node->next->next;
    
    delete temp;
}
