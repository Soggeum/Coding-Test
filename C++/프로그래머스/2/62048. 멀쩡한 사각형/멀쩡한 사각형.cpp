using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return GCD(b, a % b);
}

long long solution(int w,int h) {
    return 1ll * w * h - (1ll*w + h - GCD(w, h));
}