#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    string Head;
    string Number;
};

Node MakeNode(const string& file)
{
    string Head, Number, Tail;
    int idx = 0;
    for (char c : file)
    {
        if (idx == 0)
        {
            if (!isdigit(c))
            {
                Head.push_back(tolower(c));
            }
            else
            {
                idx++;
                Number.push_back(c);
            }
        }
        else if (idx == 1)
        {
            if (Number.size() < 5 && isdigit(c))
            {
                Number.push_back(c);
            }
            else
            {
                break;
            }
        }
    }
    
    Node result;
    result.Head = Head;
    result.Number = Number;
    return result;
}

bool comp(const string& a, const string& b)
{
    Node na = MakeNode(a);
    Node nb = MakeNode(b);
    
    if (na.Head != nb.Head)
    {
        return na.Head < nb.Head;
    }
    int NumA = stoi(na.Number);
    int NumB = stoi(nb.Number);
    if (NumA != NumB)
    {
        return NumA < NumB;
    }
    else
    {
        true;
    }
}

vector<string> solution(vector<string> files) {    
    stable_sort(files.begin(), files.end(), comp);
    return files;
}