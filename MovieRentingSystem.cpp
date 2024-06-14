#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
private:
    unordered_map<int, set<tuple<int, int>>> availableMovies;
    set<tuple<int, int, int>> rentedMovies;
    unordered_map<int, unordered_map<int, int>> moviePrice;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (const auto& entry : entries) {
            int shop = entry[0], movie = entry[1], price = entry[2];
            availableMovies[movie].emplace(price, shop);
            moviePrice[shop][movie] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> result;
        if (availableMovies.find(movie) == availableMovies.end()) return result;
        auto& movieSet = availableMovies[movie];
        int count = 0;
        for (auto it = movieSet.begin(); it != movieSet.end() && count < 5; ++it, ++count) {
            result.push_back(get<1>(*it));
        }
        return result;
    }

    void rent(int shop, int movie) {
        int price = moviePrice[shop][movie];
        availableMovies[movie].erase(make_tuple(price, shop));
        rentedMovies.emplace(price, shop, movie);
    }

    void drop(int shop, int movie) {
        int price = moviePrice[shop][movie];
        rentedMovies.erase(make_tuple(price, shop, movie));
        availableMovies[movie].emplace(price, shop);
    }

    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        for (auto it = rentedMovies.begin(); it != rentedMovies.end() && count < 5; ++it, ++count) {
            result.push_back({get<1>(*it), get<2>(*it)});
        }
        return result;
    }
};

int main(){
    
    return 0;
}