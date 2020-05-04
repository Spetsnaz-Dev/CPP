LRUCache::LRUCache(int N)
{
capacity = N;
umap.reserve(capacity);
l.clear();
umap.clear();
//Your code here
}
/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y)
{
unordered_map<int, int="">::iterator it;
it = umap.find(x);
if (it == umap.end())
{ if (l.size() == capacity)
{
int temp = l.front();
l.pop_front();
umap.erase(temp);
}
} else
{
// Update on already stores key
l.remove(x);
umap.erase(x);
}
l.push_back(x);
umap[x] = y;
//umap.insert(make_pair(x,y));
}
/*Returns the value of the key x if
present else returns -1 */
int LRUCache::get(int x)
{

unordered_map<int, int="">::iterator it;
it = umap.find(x);

if(it == umap.end() )
{
return -1;
} else
{
l.remove(x);
l.push_back(x);
return it->second;
}
}