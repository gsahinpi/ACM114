#include "itch.h"
 TPrice getDeltaTick(TPrice prospectBidPrice){
    TPrice deltaTickprice = 0;
    if (prospectBidPrice <= 2000) {
        deltaTickprice = 1;
    }
    else if (prospectBidPrice <= 5000) {
        deltaTickprice = 2;
    }
    else if (prospectBidPrice <= 10000) {
        deltaTickprice = 5;
    }
    else if (prospectBidPrice <= 25000) {
        deltaTickprice = 10;
    }
    else if (prospectBidPrice <= 50000) {
        deltaTickprice = 25;
    }
    else if (prospectBidPrice <= 100000) {
        deltaTickprice = 50;
    }
    else if (prospectBidPrice <= 250000) {
        deltaTickprice = 100;
    }
    else {
        deltaTickprice = 250;
    }
    return deltaTickprice;
};
void ItchdAlgo(char ch)
{
    cout << "ITch algo..." << endl;
    ITCH_TRIGbyHEDGESTATES itchHedgeState = HEDGE_START;
    uint64_t quoteId = 1382256;
    uint64_t hedgeId = 71536;
    persymbolrw_params_tmp[2] = 100; // bidswap;
    persymbolrw_params_tmp[3] = 300; // askswap persymbolro_params[3];
    persymbolrw_params_tmp[4] = 100; // persymbolro_params[4];
    uint32_t bidswap = persymbolrw_params_tmp[2];
    uint32_t askswap = persymbolrw_params_tmp[3];
    uint32_t orderSizefromRO4 = persymbolrw_params_tmp[4];
    TPrice baseBidPrice = -1;
    TPrice baseAskPrice = -1;
    uint8_t infomessagetype = 0xff;
    TPrice bidswapHedge = persymbolrw_params_tmp[2];
    TSize q_targetHedge = 0;
    TPrice p_targetHedge = 0;
    TOrderItem quoteorder;
cout << "    bidswap   askswap orderSizefromRO4  baseBidPric  BaseAskPrice " << endl;
cout << "\t" << bidswap << "\t" << askswap << "\t" << orderSizefromRO4 << "\t\t" << baseBidPrice << "\t\t" << baseAskPrice << endl;

    if (pergroup_params_tmp[0] == 0)
    {
        initializeMAPS();
    }
     

                switch (ch)
                {
                case 'b':
                   {
                    int64_t curbidprc;
                  cout << "Previous bid = " << prevTob[0].bid << endl;
                  cout << "Enter the current bid price: ";
                  std::cin >> currTob[0].bid;
                 // TPrice prospectBidPrice[QOUTEBIDORDERS] = {0};
                 TPrice   baseBidPrice = (currTob[0].bid)/10 + bidswap;
                   printborder
                    cout<<"\t\t\t"<<"#include qouotebidprospects.cc"<<endl;
                    #include "qouotebidprospects.cc"
                  
                      printborder
                     
                    loadbidmemorymap();//Loading map to qoute Bid orders
                      printborder
                 
                  processFoundlings();
                     printborder
                    orderMAchine();
                   
                   
                          
                          
                           printborder
                      loadbmemoryBack();

                      prevTob[0].bid=currTob[0].bid;      
                    break;
                   }
                case 'a':
                {
                    cout << "Previous ask = " << prevTob[0].ask << endl;
                  cout << "Enter the current ask price: ";
                  std::cin >> currTob[0].ask;
                  TPrice baseAskPrice = (currTob[0].ask)/10 + askswap;
                   prevTob[0].ask=currTob[0].ask;
                    break; 
                }
                default:
                    break;
                } 
};
void initializeMAPS(){

 
        pergroup_params_tmp[0]++;
        TOrderItem initializerqouteOrderItem;
        initializerqouteOrderItem.executed_qty = 0;
        initializerqouteOrderItem.order_Message_type = MSG_CANCEL_ORDER; // 0x00 unfortunately
        initializerqouteOrderItem.orderId = 0;
        initializerqouteOrderItem.price = 0;
        initializerqouteOrderItem.side = 0x00; // SIDE_UNSET = 0x00, SIDE_BUY=0x01,SIDE_SELL= 0x02 order_enums
        initializerqouteOrderItem.size = 0;
        // initializerqouteOrderItem.status=STATUSNOTSENT;
        initializerqouteOrderItem.threshold = 0;
        initializerqouteOrderItem.user_tag = 69;

        for (uint8_t i = 0; i < QOUTEORDERS; i++)
        {
            quoteOrdersMap[mapID][i].copy(initializerqouteOrderItem);
        }

        for (uint8_t i = 0; i < HEDGEORDERS; i++)
        {
            hedgeOrdersMap[mapID][i].copy(initializerqouteOrderItem);
        }
        

cout << "\033[31m"<<"initializing memory maps "<<"\033[0m" <<endl;    



 };



 void loadbidmemorymap()
 {
TOrderItem  quoteBidorder;
cout<<GREEN<<"Loading map to qoute Bid orders"<<RESET<<endl;
          //  lastfoundinprospectindex = 0xff;
          //  firstfoundinprospectindex=0xff;




    for (uint8_t i = 0; i < QOUTEBIDORDERS; i++) 
    {
     foundInBidProspect[i] = 0xff;
            
    quoteBidorder= quoteOrdersMap [mapID][i];
     quoteBidorders[i] = quoteBidorder;


                for (uint8_t p = 0; p<QOUTEBIDORDERS; p++)
                {
            // cout << "\t prospectBidPrice[" << (int)p << "] = " <<BOLDBLUE<< prospectBidPrice[p] <<  " i= "<<(int)i<<"  quoteBidorder.price " <<  quoteBidorder.price << RESET<<endl;
                    if (prospectBidPrice[p] == quoteBidorder.price) 
                    {
                        foundInBidProspect[i] = p;
                     
                      //  lastfoundinprospectindex = i;
                      /*  if (firstfoundinprospectindex == 0xff)
                        {
                            firstfoundinprospectindex = i;
                        }*/
                        break;
                       
                            
                    }
                }
    }


                    
                     for (uint8_t i = 0; i < QOUTEBIDORDERS; i++)
                    {  
                        prospectfoundInQuote[i] = 0xff;
                    for(uint8_t p = 0; p < QOUTEBIDORDERS; p++)
                        {   

                        if (prospectBidPrice[i]==quoteBidorders[p].price )
                        {   
                        prospectfoundInQuote[i] = p;
                        break;
                        }
                    }
        
     
    }
       


 
 };
 void loadbmemoryBack()
 {
            TOrderItem  quoteBidorder;
            cout<<"current bid: "<<currTob[0].bid<<" prev: "<< prevTob[0].bid<<endl;
     cout<<"\t\t\t\t\t\t\tINITIAL\t\t\tPROSPECTBID"<<"\t\t\t\t"<<"FINAL"<<endl;
     cout<<BOLDYELLOW<<"\t\t\t\t\t\t\t\t\t\t------"<<"\t\t\t\t"<<"------"<<RESET<<endl;
                for (uint8_t i = 0; i < QOUTEBIDORDERS; i++) 
                {
     cout<<"fInBPros. [" << (int)i << "] = " <<BOLDRED<< (int)foundInBidProspect[i] << RESET <<"\t";
     cout<<"prosfInQ. [" << (int)i << "] = " <<BOLDRED<< (int)prospectfoundInQuote[i] << RESET <<"\t";
     cout<<"quoteOrdersMap"<<BOLDRED<<"[" << (int)mapID  << "][" << (int)i << "]." <<RESET<< "price = "<< BOLDBLUE  <<quoteOrdersMap [mapID][i].price<< RESET <<"\t";
     cout<< "prospectBidPrice[" << (int)i << "] = " <<BOLDGREEN<< prospectBidPrice[i] << RESET <<"\t";  

                quoteBidorder= quoteBidorders[i];
                quoteOrdersMap [mapID][i].copy(quoteBidorder);
        cout<<"quoteOrdersMap"<<BOLDRED<<"[" << (int)mapID  << "][" << (int)i << "]." <<RESET<< "price = "<< BOLDBLUE  <<quoteOrdersMap [mapID][i].price<< RESET <<endl;
 
                


                }
            cout<<GREEN<<"\t copied back"<<RESET<<endl;

 };

 void processFoundlings(){
    cout<<GREEN<<"processing foundlings"<<RESET<<endl;
      for (uint8_t p = 0; p < QOUTEBIDORDERS; p++)
                                        {
                                      if (prospectfoundInQuote [p] != 0xff)
                                      {
                                std::cout<< MAGENTA<<"prospect is in the order array !DO NOTHING prospectfoundInQuote ["<< (int)p << "] = " <<(int) prospectfoundInQuote[p] <<RESET<<endl;
                                      }else
                                      {
                // std::cout<< BOLDRED<<"prospect price "<<prospectBidPrice[p]<<" is not in the order array -> finding the first notfound order index "<<RESET<<endl;

                                         for (uint8_t i = 0; i < QOUTEBIDORDERS; i++)
                                            {
                                               
                                                if (foundInBidProspect[i] == 0xff)
                                                {
                                                   
                                // std::cout<< BOLDRED<<"foundInBidProspect["<< (int)i << "] = " <<(int) foundInBidProspect[i] <<RESET<<endl;
                                cout<<BOLDBLUE<<"\t Trying copying prospect price "<<RESET<<CYAN<< (int)p<<" to quoteorder "<<(int) i<<RESET<<endl;          
                                              if ( isQuoteOrderAvailable (quoteBidorders[i]))
                                              {                                                
                                                 quoteBidorders[i].price = prospectBidPrice[p];
                                              }
                                             // cout<<"setting the found indexes"<<endl;
                                                    foundInBidProspect[i] = p;
                                                    prospectfoundInQuote[p] = i;   
                                                 /* char wait; 
                                                 cin>>  wait;*/
                                                   break;
                                                   
                                                    }
                                               continue;     
                                                    


                                      }



                                        }

                                        }




    
 };



 void   loadQordersfromMap()
 {

cout<<GREEN<<"Loading q orders from map"<<RESET<<endl;
    for (uint8_t i = 0; i < QOUTEORDERS; i++)
    {
       allQuoteOrders[i]= quoteOrdersMap[mapID][i];
       cout <<BOLDRED<<"\tallQuoteOrders["<< (int)i << "] :" <<RESET<< " id = "<< BOLDBLUE  <<allQuoteOrders[i].orderId<< RESET ;
       cout <<" price = "<< BOLDBLUE  <<allQuoteOrders[i].price<< RESET ;
      cout  << " size = "<< BOLDBLUE  <<allQuoteOrders[i].size<< RESET <<endl;
    }
    cout<<GREEN<<"loaded"<<RESET<<endl;
 };
 void   loadQordersToMap()
 {


                cout<<RED<<"Loading q orders TO  map"<<RESET<<endl;
    for (uint8_t i = 0; i < QOUTEORDERS; i++)
       {
        quoteOrdersMap[mapID][i]= allQuoteOrders[i];
        cout <<BOLDGREEN<<"\tallQuoteOrders["<< (int)i << "] :" <<RESET<< " id = "<< BOLDBLUE  <<allQuoteOrders[i].orderId<< RESET ;
       cout <<" price = "<< BOLDBLUE  <<allQuoteOrders[i].price<< RESET ;
      cout  << " size = "<< BOLDBLUE  <<allQuoteOrders[i].size<< RESET <<endl;


       }

 };
//////

 bool isQuoteOrderAvailable (TOrderItem quoteOrder)
 {

    if (quoteOrder.orderId == 0)
    {
        cout<<GREEN<<"\t\tAvailable: order id is 0 "<<RESET<<endl;
        return true;
    }else if(quoteOrder.status == STATUSACCEPTED | quoteOrder.status == STATUSEXECUTEDPARTIAL | quoteOrder.status == STATUSEXECUTEDFULL)
    {
        cout<<GREEN<<"\t\tAvailable: order status is STATUSACCEPTED |STATUSEXECUTEDPARTIAL | STATUSEXECUTEDFULL "<<RESET<<endl;
        return true;
    }
   
        cout<<RED<<"\t\tNOT AVAILABLE"<<RESET<<endl;
        return false;
    
    
 };
 
 void  orderMAchine()
 {
    TOrderItem  quoteBidorder;
                for (uint8_t i = 0; i < QOUTEBIDORDERS; i++) 
                    {
                    
                                quoteBidorder= quoteBidorders[i];
                                if (isqouteORDERable(quoteBidorder))
                                {  
                                cout <<"ORDERABLE will make order: "<<(int)i<<endl;
                                  quoteBidorder.side=SIDE_BUY; 
                                quoteBidorder.size=100;
                                quoteBidorder.order_Message_type=quoteBidorder.orderId==0?MSG_NEW_ORDER:MSG_REPLACE_ORDER;
                                  pergroup_params_tmp[0]++;
                                quoteBidorder.orderId=pergroup_params_tmp[0];
                                quoteBidorder.status=STATUSSENT;
                                


                                   


                                }else
                                {
                                cout <<"NOT ORDERABLE "<<endl;
                                }
                    }



 };
 bool isqouteORDERable(TOrderItem quoteOrder)
 { if (quoteOrder.orderId == 0)
    {
        cout<<BOLDYELLOW<<"\t\tAvailable: order id is 0 "<<RESET<<endl;
        return true;
    }
    if (quoteOrder.status == STATUSACCEPTED | quoteOrder.status == STATUSEXECUTEDPARTIAL | quoteOrder.status == STATUSEXECUTEDFULL)
    {
        cout<<BOLDYELLOW<<"\t\tAvailable: order status is STATUSACCEPTED |STATUSEXECUTEDPARTIAL | STATUSEXECUTEDFULL "<<RESET<<endl;
        return true;
    }

    return false;


 };