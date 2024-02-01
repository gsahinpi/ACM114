TPrice  deltaTickprice=0;
int distance=0;


for (int ind = 0; ind < QOUTEBIDORDERS; ++ind) {
    if (ind == 0) {
        prospectBidPrice[ind] = baseBidPrice;
    }
    else {
        deltaTickprice = getDeltaTick(prospectBidPrice[ind - 1]);
        distance+=deltaTickprice;
        prospectBidPrice[ind] = prospectBidPrice[ind - 1] - deltaTickprice;
    }
    cout << "\t prospectBidPrice[" << ind << "] = " <<BOLDBLUE<< prospectBidPrice[ind] <<RESET<< " deltatick " << deltaTickprice << RESET<<endl;
    
}
cout << "\t \tequivalant to a  distance of : " <<RED<< distance << RESET<<endl;
printborder