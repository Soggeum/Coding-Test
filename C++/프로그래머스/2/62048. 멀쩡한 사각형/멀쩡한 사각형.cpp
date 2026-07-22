using namespace std;

int GCD(int a, int b)
{
    while(b)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long solution(int w,int h) {
    return 1ll * w * h - (w + h - GCD(w, h));
}