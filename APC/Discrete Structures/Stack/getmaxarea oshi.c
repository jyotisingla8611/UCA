int Solution::largestRectangleArea(vector<int> &a) {
    int i;
    stack<int>s;
    int max = 0;
    int t;
    int ca;
     int n = a.size();
    while (i < n)
    {
        if (s.empty() || a[s.top()] <= a[i])
            s.push(i++);
        else
        {
            t = s.top();
            s.pop();
            ca = a[t] * (s.empty() ? i : i - s.top() - 1);
            if (max < ca)
                max = ca;
        }
    }
    while (s.empty() == false)
    {
        t = s.top();
        s.pop();
        ca = a[t] * (s.empty() ? i :
                                i - s.top() - 1);

        if (max < ca)
            max = ca;
    }

    return max;
}

