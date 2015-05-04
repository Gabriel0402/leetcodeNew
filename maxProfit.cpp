int maxProfit(vector<int> &prices){
	if(prices.size()<2) return 0;
	int profit = 0;
	int cur_min=prices[0];
	for(int i=1;i<prices.size();++i){
		proft=max(profit,prices[i]-cur_min);
		cur_min=min(cur_min,prices[i]);
	}
	return profit;
}

int maxProfit(vector<int> &prices){
	int sum=0;
	for(int i=1;i<prices.size();i++){
		int diff=prices[i]-prices[i-1];
		if(diff>0) sum+=diff;
	}
	return sum;
}