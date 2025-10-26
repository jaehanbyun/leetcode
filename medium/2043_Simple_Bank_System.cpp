class Bank {
public:
    Bank(vector<long long>& balance) {
        this->balance_ = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (!isValid(account1) || !isValid(account2)) return false;
        long long &from = balance_[account1 - 1];
        long long &to   = balance_[account2 - 1];
        if (from < money) return false;
        from -= money;
        to   += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (!isValid(account)) return false;
        balance_[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (!isValid(account)) return false;
        long long &bal = balance_[account - 1];
        if (bal < money) return false;
        bal -= money;
        return true;
    }
private:
    vector<long long> balance_;
    bool isValid(int account) {
        return account <= balance_.size();
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */