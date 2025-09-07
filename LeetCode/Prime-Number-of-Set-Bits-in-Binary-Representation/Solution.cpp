public int CountPrimeSetBits(int left, int right) {
    int noOfPrimes = 0;
    Dictionary<int , int> bin = new Dictionary<int,int>{
        {0,0},
        {1,1}
    };
    bool[] seive = new bool[33];
    Array.Fill(seive,true);
    seive[0] = seive[1] = false;
    for(int i = 2; i<= 32;i++){
        for(int j = i * i ; j <=32;j = j + i ){
            if(j%i == 0){
                seive[j] = false;
            }
        }
    }
    for(int i = left;i<= right; i++){
        int count = 0;
        int num = i;
        while(num != 0){
            
            count = count+bin[num&1];
         
            num = num >>> 1;
        }
        if(seive[count]){
            noOfPrimes++;
        }
    }
    return noOfPrimes;
}