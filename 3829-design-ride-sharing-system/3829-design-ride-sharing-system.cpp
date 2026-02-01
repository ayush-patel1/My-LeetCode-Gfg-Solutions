class RideSharingSystem {
public:
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> rpq, dpq;
    unordered_set<int> d, r;
    int tr, td;

    RideSharingSystem() {
        tr = 0;
        td = 0;
    }

    void addRider(int riderId) {
        tr++;
        rpq.push({tr, riderId});
        r.insert(riderId);
    }

    void addDriver(int driverId) {
        td++;
        dpq.push({td, driverId});
        d.insert(driverId);
    }

    vector<int> matchDriverWithRider() {
        int rider = -1, driver = -1;

        while (!rpq.empty() && rider == -1) {
            int id = rpq.top().second;
            if (r.find(id) == r.end()) rpq.pop();
            else rider = id;
        }

        while (!dpq.empty() && driver == -1) {
            int id = dpq.top().second;
            if (d.find(id) == d.end()) dpq.pop();
            else driver = id;
        }

        if (rider == -1 || driver == -1) return {-1, -1};

        r.erase(rider);
        d.erase(driver);
        rpq.pop();
        dpq.pop();

        return {driver, rider};
    }

    void cancelRider(int riderId) {
        if (r.find(riderId) != r.end()) r.erase(riderId);
    }
};
