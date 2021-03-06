/*
现有一圆环形路，路上有n个加油站，第i个加油站储存有Ni升容量的油，每两个加油站之间有一定的距离（km），
一汽车初始无油，该车每公里消耗w升油，请问该车从哪个加油站出发可以绕该环形路行驶一圈。给出所有的算法及时间的复杂度。
eg:
加油站油量：{2 1 4 1 5 5}
加油站距离：{3 2 2 4 4 3}
净剩余：{-1 -1 2 -3 1 2}  
*/

// 思路： 先让汽车油箱里装好足够多的油，随便从哪个加油站出发试跑一圈。车每到一个加油站时，记录此时油箱里剩下的油量，
// 然后把那个加油站的油全部装上。试跑完一圈后，检查刚才路上到哪个加油站时剩的油量最少，那么空着油箱从那里出发显然一定能跑完全程 


int selectGasStation_1(const vector<int> &a, const vector<int> &g, const int n) {
    int res = 0, min = N[0] - g[0], sum = min;
    for (int i = 1; i < n; ++i)
    {
        sum += N[i] - g[i];
        if (sum < min) {
            min = sum;
            res = i;
        }
    }
    return sum >= 0 ? (res + 1) % n : -1;
}


