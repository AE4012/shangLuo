#include<iostream>
#include<vector>

using namespace std;
int predict, index;
int baseCost, baseVolume;
int price, volume;
int decreaseRate;    
int maxProfit = -1e9, bestSubsidy = 0;
int p;

struct PriceVolume{
    int price, volume;
};

int main(){
    cin >> predict;
    cin >> baseCost >> baseVolume;  //起始

    vector<PriceVolume> data;
    data.push_back({baseCost, baseVolume});
    index = 0;

    while(cin >> price >> volume, price != -1 && volume != -1){
        if (price - data[index].price > 1)
        {
            int temp = (data[index].volume - volume)/(price - data[index].price);
            while(price - data[index].price > 1){
                data.push_back({data[index].price + 1, data[index].volume - temp});
                index++;
            }
        }
        data.push_back({price, volume});
        index++;        
    }

    cin >> decreaseRate;

    int zero = data[index].volume;
    while(zero > 0){
        if(zero - decreaseRate < 0) break;
        else{
            zero -= decreaseRate;
            data.push_back({data[index++].price + 1, zero});
        }
    }

    // for(auto it : data){
    //     cout << it.price << " " << it.volume << '\n';
    // }

    for(int j = 1; j <= 10000; ++j){
        for(int k = 0; k <= index; ++k){
            int num = (data[k].price - baseCost + j)*data[k].volume;
            if(num >= maxProfit){
                maxProfit = num;
                price = data[k].price;
                p = 1;
            }
        }
        if(price == predict){
            cout << j*p << endl;
            return 0;
        }
        maxProfit = -1e9;
        for(int k = 0; k <= index; ++k){
            int num = (data[k].price - baseCost - j)*data[k].volume;
            if(num >= maxProfit){
                maxProfit = num;
                price = data[k].price;
                p = -1;
            }
        }
        if(price == predict){
            cout << j*p << endl;
            return 0;
        }
    }
    cout << "NO SOLUTION" << endl;
    // cout << index << endl;

    return 0;
}