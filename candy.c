int candy(int* ratings, int n){
    if(n == 1) return 1;

    int total = 1, up = 0, down = 0, peak = 0;

    for(int i = 1; i < n; i++){
        if(ratings[i] > ratings[i-1]){
            up++;
            peak = up;
            down = 0;
            total += 1 + up;
        }
        else if(ratings[i] == ratings[i-1]){
            up = down = peak = 0;
            total += 1;
        }
        else{
            down++;
            up = 0;
            total += 1 + down;
            if(down > peak) total++;
        }
    }
    return total;
}
