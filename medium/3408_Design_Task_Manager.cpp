class TaskManager {
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& t: tasks) {
            int u = t[0], i = t[1], p = t[2];
            add(u, i, p);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        Node node{priority, taskId, userId};
        auto it = top_.insert(node).first;
        where_[taskId] = it;
    }
    
    void edit(int taskId, int newPriority) {
        auto it = where_[taskId];
        Node n = *it;                 
        top_.erase(it);               
        n.priority = newPriority;     
        auto it2 = top_.insert(n).first;
        where_[taskId] = it2;       
    }
    
    void rmv(int taskId) {
        auto it = where_[taskId];
        top_.erase(it);
        where_.erase(taskId);
    }
    
    int execTop() {
        if (top_.empty()) return -1;
        const Node& n = *top_.begin();  
        int uid = n.userId;
        where_.erase(n.taskId);
        top_.erase(top_.begin());
        return uid;
    }

private:
    struct Node {
        int priority;
        int taskId;
        int userId;
    };

    struct Compare{
        bool operator() (const Node& a, const Node& b) const {
            if (a.priority != b.priority) return a.priority > b.priority;
            else return a.taskId > b.taskId;
        }
    };

    using Set = set<Node, Compare>;

    Set top_;
    unordered_map<int, Set::iterator> where_;
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */