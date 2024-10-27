# I got the OA mail 6 days back on 25 Sep, Completed it today (30 Sep). All testcases passed 🤓🎊, will I get an interview ?

**Q1.** The course has n chapters, each chapter has memory[i] memory points, which a student gains or loses while reading that chapter.

The course has a requirement: in order to study the ith chapter, the student must revisit all the previous chapters. A student gains memory[0] + memory[1] + ... + memory[i] memory points for reading the ith chapter. The total memory points is the sum of memory points gained while reading each chapter.

Students can read the chapters in any order, and want to maximize their total memory points. Find the maximum total memory points a student can score ensuring that all the chapters are read.

`Input:  [3, 4, 5]`
`Output: 26`

**Solution**
```
int maxMemoryPoints(vector<int>& memory) {
    sort(memory.begin(), memory.end(), greater<int>());
    int totalMemoryPoints = 0;
    int currentSum = 0;
    for (int mem : memory) {
        currentSum += mem;
        totalMemoryPoints += currentSum;
    }
    return totalMemoryPoints;
}
```


**Q2.** Data analysts at Amazon are analyzing time-series data. It was concluded that the data of the nth item was dependent on the data of some xth day if there is a positive integer k such that floor(n/k) = x, where floor(z) represents the largest integer less than or equal to z.

Given n, find the sum of all the days' numbers on which the data of the xth ( 0≤ x ≤n) will be dependent.

**Solution**

```
long long sumOfUniqueDays(long long n) {
    long long sum = 0;
    long long sqrt_n = floor(sqrt((double)n));

    for(long long k = 1; k <= sqrt_n; ++k){
        long long x = n / k;
        sum += x;
    }

    long long max_d = n / (sqrt_n + 1);
    for(long long d = 1; d <= max_d; ++d){
        sum += d;
    }
	
    return sum;
}
```

