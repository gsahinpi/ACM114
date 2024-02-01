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
 TPrice getDeltaTickAsk(TPrice prospectAskPrice) 
 {
            TPrice  deltaTickprice=0;
        if (prospectAskPrice < 2000) // < for deltaASK
        {
        deltaTickprice = 1;
        }
            else if (prospectAskPrice < 5000)
            {
            deltaTickprice = 2;
            }
        else if (prospectAskPrice < 10000)
        {
        deltaTickprice = 5;
        }
            else if (prospectAskPrice < 25000)
            {
            deltaTickprice = 10;
            }
            else if (prospectAskPrice < 50000)
            {
            deltaTickprice = 25;
            }
            else if (prospectAskPrice < 100000)
            {
            deltaTickprice = 50;
            }
            else if (prospectAskPrice < 25000)
            {
            deltaTickprice = 100;
            }
                    else
                    {
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

                           printborder
                      prevTob[0].bid=currTob[0].bid;      
                    break;
                   }
                case 'a':
                {
                    cout << "Previous ask = " << prevTob[0].ask << endl;
                  cout << "Enter the current ask price: ";
                  std::cin >> currTob[0].ask;
                  TPrice baseAskPrice = (currTob[0].ask)/10 + askswap;
                      printborder
                    cout<<"\t\t\t"<<"#include qouoteaskprospects.cc"<<endl;
                    printborder
                  calculateaskprospects(baseAskPrice);
                  printborder
                    loadaskmemorymap();//Loading map to qoute Bid orders
                      
                    printborder
                    processAskFoundlings();
                    printborder
                         orderMAchineAsk();
                        printborder
                      loadamemoryBack();     

                           printborder

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

void printMAps()

{
    cout << "printing qoute orders" << endl;
    for (uint8_t i = 0; i < QOUTEORDERS; i++)
    {
        cout << "quoteOrdersMap[" << (int)mapID << "][" << (int)i << "]." << "price = " << quoteOrdersMap[mapID][i].price << endl;
    }
    cout << "done printing qoute orders" << endl;
};
void printqouteorders()
{
 printborder
    cout << "printing qoute orders" << endl;
    for (uint8_t i = 0; i < QOUTEORDERS; i++)
    { 
      cout<<BOLDGREEN;
      coutT;
       cout<<TOrderItemToString(allQuoteOrders[i])<<RESET;

      
    }
    cout << "done printing qoute orders" << endl;
     printborder
};
 void loadaskmemorymap()
 {
TOrderItem  quoteAskorder;
cout<<RED<<"Loading map to qoute Ask orders"<<RESET<<endl;
 for (uint8_t i = 0; i < QOUTEASKORDERS; i++) 
    {
        foundInAskProspect[i] = 0xff;
        quoteAskorder= quoteOrdersMap [mapID][i+QOUTEBIDORDERS];
     quoteAskorders[i] = quoteAskorder;
              for (uint8_t p = 0; p<QOUTEBIDORDERS; p++)
                {

                    if (prospectAskPrice[p] == quoteAskorder.price) 
                    {
                        foundInAskProspect[i] = p;
                        break;
                    }   
                }


    }

                        for (uint8_t i = 0; i < QOUTEASKORDERS; i++)
                        {  
                            prospectfoundInQuoteAsk[i] = 0xff;
                        for(uint8_t p = 0; p < QOUTEASKORDERS; p++)
                            {   
    
                            if (prospectAskPrice[i]==quoteAskorders[p].price )
                            {   
                            prospectfoundInQuoteAsk[i] = p;
                            break;
                            }
                        }
            
        
        }

 };

 void loadamemoryBack()
 {

   TOrderItem  quoteAskorder;
            cout<<"current ask: "<<currTob[0].ask<<" prev: "<< prevTob[0].ask<<endl;
     cout<<"\t\t\t\t\t\t\tINITIAL\t\t\tPROSPECTASK"<<"\t\t\t\t"<<"FINAL"<<"\t\t\t(price,id,status)"<<endl;
     cout<<BOLDYELLOW<<"\t\t\t\t\t\t\t\t\t\t------"<<"\t\t\t\t"<<"------"<<RESET<<endl;
                for (uint8_t i = 0; i < QOUTEASKORDERS; i++) 
                {
     cout<<"fInAPros. [" << (int)i << "] = " <<BOLDRED<< (int)foundInAskProspect[i] << RESET <<"\t";
     cout<<"prosfInQ. [" << (int)i << "] = " <<BOLDRED<< (int)prospectfoundInQuoteAsk[i] << RESET <<"\t";
     cout<<"quoteOrdersMap"<<BOLDRED<<"[" << (int)mapID  << "][" << (int)(i+QOUTEBIDORDERS) << "]." <<RESET<< "price = "<< BOLDBLUE  <<quoteOrdersMap [mapID][i+QOUTEBIDORDERS].price<< RESET <<"\t";
     cout<< "prospectAskPrice[" << (int)i << "] = " <<BOLDGREEN<< prospectAskPrice[i] << RESET <<"\t";  

                quoteAskorder= quoteAskorders[i];
                quoteOrdersMap [mapID][i+QOUTEBIDORDERS].copy(quoteAskorder);
        cout<<"quoteOrdersMap"<<BOLDRED<<"[" << (int)mapID  << "][" << (int)(i+QOUTEBIDORDERS) << "]." <<RESET<< "(price,id,status) = ("<< BOLDBLUE  <<quoteOrdersMap [mapID][i+QOUTEBIDORDERS].price<<","<<
        quoteOrdersMap [mapID][i+QOUTEBIDORDERS].orderId<<", "<< TOrderItemStatusToString(quoteOrdersMap [mapID][i+QOUTEBIDORDERS].status) <<")" <<RESET <<endl;
                }







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
     cout<<"\t\t\t\t\t\t\tINITIAL\t\t\tPROSPECTBID"<<"\t\t\t\t"<<"FINAL"<<"\t\t\t(price,id,status)"<<endl;
     cout<<BOLDYELLOW<<"\t\t\t\t\t\t\t\t\t\t------"<<"\t\t\t\t"<<"------"<<RESET<<endl;
                for (uint8_t i = 0; i < QOUTEBIDORDERS; i++) 
                {
     cout<<"fInBPros. [" << (int)i << "] = " <<BOLDRED<< (int)foundInBidProspect[i] << RESET <<"\t";
     cout<<"prosfInQ. [" << (int)i << "] = " <<BOLDRED<< (int)prospectfoundInQuote[i] << RESET <<"\t";
     cout<<"quoteOrdersMap"<<BOLDRED<<"[" << (int)mapID  << "][" << (int)i << "]." <<RESET<< "price = "<< BOLDBLUE  <<quoteOrdersMap [mapID][i].price<< RESET <<"\t";
     cout<< "prospectBidPrice[" << (int)i << "] = " <<BOLDGREEN<< prospectBidPrice[i] << RESET <<"\t";  

                quoteBidorder= quoteBidorders[i];
                quoteOrdersMap [mapID][i].copy(quoteBidorder);
        cout<<"quoteOrdersMap"<<BOLDRED<<"[" << (int)mapID  << "][" << (int)i << "]." <<RESET<< "(price,id,status) = ("<< BOLDBLUE  <<quoteOrdersMap [mapID][i].price<<","<<
        quoteOrdersMap [mapID][i].orderId<<", "<< TOrderItemStatusToString(quoteOrdersMap [mapID][i].status) <<")" <<RESET <<endl;
 
                


                }
            cout<<GREEN<<"\t copied back"<<RESET<<endl;

 };
 void processAskFoundlings()
 {
    cout<<RED<<"processing ASk foundlings"<<RESET<<endl;

 for (uint8_t p = 0; p < QOUTEBIDORDERS; p++)
                                        {
                                        if (prospectfoundInQuoteAsk [p] != 0xff)
                                        {
std::cout<< MAGENTA<<"prospect is in the ask order array !DO NOTHING prospectfoundInQuote ["<< (int)p << "] = " <<(int) prospectfoundInQuoteAsk[p] <<RESET<<endl;
                                

                                        }
        else
                                      {

 for (uint8_t i = 0; i < QOUTEASKORDERS; i++)
                                            {
                                               
                                                if (foundInAskProspect[i] == 0xff)
                                                {

 cout<<BOLDBLUE<<"\t Trying copying prospect price "<<RESET<<CYAN<< (int)p<<" to quoteaskorder "<<(int) i<<RESET<<endl;          
                                              if ( isQuoteOrderAvailable (quoteAskorders[i]))
                                              {                                                
                                                 quoteAskorders[i].price = prospectAskPrice[p];
                                              }
                                               foundInAskProspect[i] = p;
                                                    prospectfoundInQuoteAsk[p] = i; 
                                                       break;
                                                }
                                            }



                                      }
                                        }

 };

 void processFoundlings(){
    
    cout<<GREEN<<"processing bid foundlings"<<RESET<<endl;
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
                                               //continue;     
                                                    


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
       coutT;
       coutT;
       cout <<RED<<"QO["<<(int)i<<"] "<<" "<<RESET;
       cout<<BOLDYELLOW;
       cout<<TOrderItemToString(allQuoteOrders[i]);
       cout<<RESET<<endl;
       /*
       cout <<BOLDRED<<"\tallQuoteOrders["<< (int)i << "] :" <<RESET<< " id = "<< BOLDBLUE  <<allQuoteOrders[i].orderId<< RESET ;
       cout <<" price = "<< BOLDBLUE  <<allQuoteOrders[i].price<< RESET ;
      cout  << " size = "<< BOLDBLUE  <<allQuoteOrders[i].size<< RESET ;
      cout<<BOLDRED<<"status"<<TOrderItemStatusToString(allQuoteOrders[i].status) <<RESET <<endl;*/
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
  void orderMAchineAsk(){
 TOrderItem  quoteAskorder;
                for (uint8_t i = 0; i < QOUTEASKORDERS; i++) 
                    {
                    
                                quoteAskorder= quoteAskorders[i];
                                if (isqouteORDERable(quoteAskorder))
                                {  
                                cout <<"\tORDERABLE will make order: "<<(int)i<<endl;
                                  quoteAskorder.side=SIDE_SELL; 
                                quoteAskorder.size=100;

                                quoteAskorder.order_Message_type=quoteAskorder.orderId==0?MSG_NEW_ORDER:MSG_REPLACE_ORDER;
                                quoteAskorder.status=quoteAskorder.orderId==0?STATUSSENT: quoteAskorder.status;
                               
                               
                                  pergroup_params_tmp[0]++;
                                
                                quoteAskorder.orderId=pergroup_params_tmp[0];
                               
                                quoteAskorders[i]=quoteAskorder;
                                cout <<BOLDGREEN<<"\t id is set to: "<<pergroup_params_tmp[0]<<RESET<<endl;
                                



                                   


                                }else
                                {
                                cout <<"\t"<<(int) i <<" NOT ORDERABLE "<<endl;
                                }
                    }




  };
 
 void  orderMAchine()
 {
    TOrderItem  quoteBidorder;
                for (uint8_t i = 0; i < QOUTEBIDORDERS; i++) 
                    {
                    
                                quoteBidorder= quoteBidorders[i];
                                if (isqouteORDERable(quoteBidorder))
                                {  
                                cout <<"\tORDERABLE will make order: "<<(int)i<<endl;
                                  quoteBidorder.side=SIDE_BUY; 
                                quoteBidorder.size=100;

                                quoteBidorder.order_Message_type=quoteBidorder.orderId==0?MSG_NEW_ORDER:MSG_REPLACE_ORDER;
                                quoteBidorder.status=quoteBidorder.orderId==0?STATUSSENT: quoteBidorder.status;
                               
                               
                                  pergroup_params_tmp[0]++;
                                
                                quoteBidorder.orderId=pergroup_params_tmp[0];
                               
                                quoteBidorders[i]=quoteBidorder;
                                cout <<BOLDYELLOW<<"\t id is set to: "<<pergroup_params_tmp[0]<<RESET<<endl;
                                



                                   


                                }else
                                {
                                cout <<"\t"<<(int) i <<" NOT ORDERABLE "<<endl;
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
     cout<<BOLDRED<<"\t\t "<<  TOrderItemStatusToString(quoteOrder.status)<<RESET<<endl;
    return false;


 };

 void hedgeouch()
 {
 int choice;
      cout << "Enter 0 to accept an order, 1 to execute an  order, 2 to reject  an order, you will need an order  id ";

      std::cin >> choice;
        switch (choice) {   
        case 0:
            {
            cout << "Accepting order..." << endl;
             uint64_t AcceptedOrderId=0;
                                    cout << "enter order id or 0 to quit" << endl;
                                    std::cin>> AcceptedOrderId; 
                                    if (AcceptedOrderId==0)
                                    {
                                        cout << "!AcceptedOrderId==0" << endl;
                                        break;
                                    }

                                     
                                    cout << "AcceptedOrderId" << (int) AcceptedOrderId << endl;
                                    acceptOrder(AcceptedOrderId);

                                                     



                       //#include "findackedindexandsetorderstatus.inc"

            break;
            }

        case 1: 
        {/*  INTRO*/
            cout << "Executing order..." << endl;
              uint64_t exeutedOrderId=0;
                                    cout << "enter order id to"<<BOLDBLUE <<"EXECUTE or 0 to quit" <<RESET<<endl;
                                    std::cin>> exeutedOrderId; 
                                    if (exeutedOrderId==0)
                                    {
                                        cout << "!exeutedOrderId==0" << endl;
                                        break;
                                    }
                                   cout<<TOrderItemToString(allQuoteOrders[exeutedOrderId])<<endl; 


 uint64_t executedOrdersize=0;
                                    cout << "size to"<<BOLDBLUE <<"EXECUTE or 0 to quit" <<RESET<<endl;
                                    std::cin>> executedOrdersize; 
                                    if (executedOrdersize==0)
                                    {
                                        cout << "!executedOrdersize==0" << endl;
                                        break;
                                    }



                      executedOrder(exeutedOrderId,executedOrdersize);  
                      //preparehedgeorder();             
                    /*****End of intro*/                
            break;
        }
            case 2:
            {
            cout << "Rejecting order..." << endl;
            uint64_t rejectOrderId=0;
                                    cout << "enter order id to"<<BOLDBLUE <<"REJECT or 0 to quit" <<RESET<<endl;
                                    std::cin>> rejectOrderId; 
                                    if (rejectOrderId==0)
                                    {
                                        cout << "!rejectOrderId==0" << endl;
                                        break;
                                    }
                rejectedOrder(rejectOrderId);

            break;
            }
        default:    
                {
            cout << "Invalid choice. Please try again." << endl;
            break; 
                } 

        }
          

 };
void executedOrder(uint64_t quoteOrderid, TSize executedsize ){
    cout<<"tobe implemented"<<quoteOrderid<<endl;
    uint8_t foundindex=0xff;
for (int i=0; i< QOUTEORDERS ;i++)
 {
   
       if (allQuoteOrders[i].orderId==quoteOrderid )
           {
            foundindex=i;
            break;
           }
     
 }
   //= Order_ExecTraded_Quantity;
    TPrice executedPrice= allQuoteOrders[foundindex].price;

if (foundindex!=0xff)
{
     cout << "foundindex" << (int) foundindex <<"will be  set to EXECUTED" ;
   
    //executedsize   = Order_ExecTraded_Quantity;
    executedPrice = allQuoteOrders[foundindex].price;
    TSize previousize=allQuoteOrders[foundindex].size;
    cout << "previousize" << (int) previousize <<"-" << "executedsize" << (int) executedsize <<" = "<<previousize-executedsize<< endl;
    cout << "executedPrice" << (int) executedPrice <<endl;
    if (previousize==executedsize)
    {
          cout <<" FULLY EXECUTED" <<endl;
        allQuoteOrders[foundindex].status=  STATUSEXECUTEDFULL;
        allQuoteOrders[foundindex].orderId=0;
        allQuoteOrders[foundindex].size=0;
        allQuoteOrders[foundindex].side=0x00;
        quoteOrdersMap[mapID][foundindex].copy(allQuoteOrders[foundindex]);
    }else
    {     cout <<" PARTIALLY EXECUTED" <<endl;
        allQuoteOrders[foundindex].status=  STATUSEXECUTEDPARTIAL;
        allQuoteOrders[foundindex].size -= executedsize;
        allQuoteOrders[foundindex].executed_qty += executedsize; 
         quoteOrdersMap[mapID][foundindex].copy(allQuoteOrders[foundindex]);

    }

 
}




}  ;

 void   acceptOrder(u_int64_t AcceptedOrderId)
 {

 uint8_t foundindex = 0xff;
                                                          for (int i=0; i< QOUTEORDERS ;i++)
                                                                    {
                                                                  if (allQuoteOrders[i].orderId==AcceptedOrderId)
                                                                            {
                                                                                foundindex=i;
                                                                                break;
                                                                            }
                                                                        
                                                                    }
                                                            if (foundindex!=0xff)
                                                            {

                                                            allQuoteOrders[foundindex].status=STATUSACCEPTED;
                                                            quoteOrdersMap[mapID][foundindex].status=STATUSACCEPTED;
                                                            cout << "\n found @" <<(int) foundindex<<" and set to Accepted" <<endl;
                                                            }
                                                            else
                                                            {
                                                                cout << "not found" << endl;
                                                            }



 };

 


void rejectedOrder(uint64_t quoteOrderid) {
    cout << "Rejecting order " << quoteOrderid << endl;
    uint8_t foundindex = 0xff;
    for (int i=0; i< QOUTEORDERS ;i++)
        {
       
            if (allQuoteOrders[i].orderId==quoteOrderid )
                {
                    foundindex=i;
                    break;
                }
            
        }
if (foundindex!=0xff)
{
 allQuoteOrders[foundindex].status=STATUSREJECTED;
 allQuoteOrders[foundindex].orderId=0;
  quoteOrdersMap[mapID][foundindex]=allQuoteOrders[foundindex];
}


};


  void calculateaskprospects( TPrice baseAskPrice)
  {
 
TPrice deltaTickprice = 0;
int distance=0;

for (int ind = 0; ind < QOUTEASKORDERS; ++ind)
{
    if (ind == 0)
    {
        prospectAskPrice[ind] = baseAskPrice;
    }
    else
    {
         deltaTickprice = getDeltaTickAsk(prospectAskPrice[ind - 1]);
     distance+=deltaTickprice;
     prospectAskPrice[ind] = prospectAskPrice[ind - 1] + deltaTickprice;
   

      }
   cout << "\t prospectaskPrice[" << ind << "] = " <<BOLDBLUE<< prospectAskPrice[ind] <<RESET<< " deltatick " << deltaTickprice << RESET<<endl;
       

}
cout << "\t \tequivalant to a  distance of : " <<RED<< distance << RESET<<endl;
printborder

                  };  
