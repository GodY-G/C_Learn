int maxProfit(int* prices, int pricesSize) {
    int min_price = prices[0];
    int profit = 0;
    
    for(int i = 0;i < pricesSize;++i){
        if(prices[i] < min_price){
            min_price = prices[i];
        }else{
            int temp_profit = prices[i] - min_price;
            if(temp_profit > profit){
                profit = temp_profit;
            }
        }
    }

    return profit;

}