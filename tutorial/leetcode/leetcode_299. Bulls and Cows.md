## 题意
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 

Please note that both secret number and friend's guess may contain duplicate digits.
```
Example 1:

Input: secret = "1807", guess = "7810"

Output: "1A3B"

Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
Example 2:

Input: secret = "1123", guess = "0111"

Output: "1A1B"

Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
```
## 思路 & 实现

### 1. hash_map 思想
定义一个长度为10的vector ctnr,并定义bulls和cows来存储最终结果，之后按照如下方法依次遍历secret和guess，得到最终结果。
1. 遍历secret，如果`secret[i] == guess[i]`，则++cows,否则`++ctnr[(int)secret[i]]`。
2. 遍历guess，如果`secret[i] != guess[i]`且`ctnr[(int)guess[i]] > 0`，则++bulls，且`--ctnr[(int)guess[i]]`

上述过程的核心环节在于第二步，如果`secret[i] != guess[i]`且`ctnr[(int)guess[i]] > 0`，这代表`guess[i]`在secret除了i位置之外的其他位置出现过，那么++bulls。而这时必然要`--ctnr[(int)guess[i]]`才能保证如果下次出现`guess[j] == guess[i]`时，ctnr的状态是对的，即ctnr中guess[i]的状态已经被抹除掉了。

如下是C++的实现方式。

```C++
class Solution {
public:
    string getHint(string secret, string guess) {
        int length_s = secret.size();
        int length_g = secret.size();
        if (length_s != length_g) {
            return "";
        }
        
        std::vector<int> ctnr(10);
        int cows = 0;
        for (int i = 0; i < length_s; ++i) {
            if (secret[i] == guess[i]) {
                ++cows;
            } else {
                ++ctnr[secret[i] - '0'];
            }
        }
        
        int bulls = 0;
        for (int i = 0; i < length_g; ++i) {
            int pos = guess[i] - '0';
            if (secret[i] != guess[i] && ctnr[pos] > 0) {
                --ctnr[pos];
                ++bulls;
            }
        }
        return std::to_string(cows) + "A" + std::to_string(bulls) + "B";
    }
};
```

> 时间复杂度：O(2n)

> 空间复杂度：O(n)

