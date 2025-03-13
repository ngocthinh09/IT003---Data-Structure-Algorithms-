#include <bits/stdc++.h>  
using namespace std;  
 
static const string SPECIAL_CHARS = "!@#$%^&*?~-";  

static const string INVALID_CHARS = " ,/.'\"";  
 
const int BASE_SCORE      = 40;  
const int BONUS_EXCESS    = 3;   
const int BONUS_UPPER     = 4; 
const int BONUS_NUMBER    = 5;  
const int BONUS_SYMBOLS   = 5;   

bool containsChar(const string& s, char c) {  
    return (s.find(c) != string::npos);  
}  

int checkPasswordScore(const string& password) {  
    int lengthPwd = password.size();  
    
    int countUpper   = 0;  
    int countNumber  = 0;  
    int countSymbol  = 0;  
    
    bool allLower    = true;  
    bool allDigits   = true;  
    
    for (char c : password) {  
        if (isupper((unsigned char)c)) {  
            countUpper++;  
            allLower  = false;   
            allDigits = false;  
        }  
        else if (isdigit((unsigned char)c)) {  
            countNumber++;  
            allLower  = false;   
        }  
        else if (isalpha((unsigned char)c)) {  
        
            allDigits = false;  
        }  
        
        if (containsChar(SPECIAL_CHARS, c)) {  
            countSymbol++;  
            allLower  = false;  
            allDigits = false;  
        }  
    }  
    
    int score = BASE_SCORE;  
    
    int numExcess = max(0, lengthPwd - 8);  
    score += numExcess * BONUS_EXCESS;  
    
    score += countUpper  * BONUS_UPPER;    
    score += countNumber * BONUS_NUMBER;   
    score += countSymbol * BONUS_SYMBOLS;  
    
    int activeGroups = 0;  
    if (countUpper  > 0) activeGroups++;  
    if (countNumber > 0) activeGroups++;  
    if (countSymbol > 0) activeGroups++;  
    
    int bonusCombo = 0;  
    if (activeGroups == 3) bonusCombo = 25;  
    else if (activeGroups == 2) bonusCombo = 15;  
    score += bonusCombo;  
    
    if (allLower)  score -= 15;  
    if (allDigits) score -= 35; 
    
    return score;  
}   
string evaluatePassword(int score) {   
    if (score < 50)        return "Yeu";  
    else if (score < 75)   return "Vua";  
    else if (score < 100)  return "Manh";  
    else                   return "RatManh";  
}  

int main(){  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr); 
    // freopen("test.inp","r",stdin);
    // freopen("test.out","w",stdout); 
     
    string password;  
    cin >> password;  
    
    if ((int)password.length() < 8) {  
        cout << "KhongHopLe\n";  
        return 0;  
    }  
      
    for (char c : password) {  
        if (containsChar(INVALID_CHARS, c)) {  
            cout << "KhongHopLe\n";  
            return 0;  
        }  
    }  
 
    int score = checkPasswordScore(password);  

    string result = evaluatePassword(score);  
    cout << result << "\n";  
    
    return 0;  
}  