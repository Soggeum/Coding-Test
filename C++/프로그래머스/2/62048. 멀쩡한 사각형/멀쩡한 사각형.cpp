using namespace std;

int GCD(int w, int h)
{
    if (h == 0)
    {
        return w;
    }
    return GCD(h, w % h);
}

long long solution(int w,int h) {
    long long answer = 1ll * w * h - (w + h - GCD(w, h));
    return answer;
}