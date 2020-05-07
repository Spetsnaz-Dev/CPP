// You are in a party of N people, where only one person is known to everyone. Such a person may be present in the party, if yes, (s)he doesn’t know anyone in the party. Your task is to find the stranger (celebrity) in party.
int getId(int party[MAX][MAX], int n)
{
    stack<int> st;
    for(int i=0; i<n; i++){
        st.push(i);
    }
    
    while(st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        
        if(party[a][b] == 0 and party[b][a] == 1)
            st.push(a);
        else if(party[a][b] == 1 and party[b][a] == 0)
            st.push(b);
    }
    if(st.size() == 0)
        return -1;
    int celeb = st.top();
    st.pop();
    
    for(int i=0; i<n; i++){
        if(i == celeb)
            continue;
        if(party[i][celeb] == 0 or party[celeb][i] == 1)
            return -1;
    }
    return celeb;
}