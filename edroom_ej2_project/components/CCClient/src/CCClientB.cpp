#include <public/ccclient_iface_v1.h>

// ***********************************************************************

// class EDROOM_CTX_Top_0

// ***********************************************************************



	// CONSTRUCTORS***********************************************

CCClient::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(CCClient &act ):

	EDROOMcomponent(act),
	Msg(EDROOMcomponent.Msg),
	MsgBack(EDROOMcomponent.MsgBack),
	pSerReq(EDROOMcomponent.pSerReq),
	Timer(EDROOMcomponent.Timer)
{
}

CCClient::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(EDROOM_CTX_Top_0 &context):

	EDROOMcomponent(context.EDROOMcomponent),
	Msg(context.Msg),
	MsgBack(context.MsgBack),
	pSerReq(context.pSerReq),
	Timer(context.Timer)
{

}

	// EDROOMSearchContextTrans********************************************

bool CCClient::EDROOM_CTX_Top_0::EDROOMSearchContextTrans(
			TEDROOMTransId &edroomCurrentTrans)
			{

	bool edroomValidMsg=false; 

	 switch(Msg->signal)
	{

		 case ( EDROOMSignalDestroy ): 

			 edroomValidMsg=true;
			 edroomCurrentTrans.distanceToContext = 0 ;
			 edroomCurrentTrans.localId = -1 ;
			 break;

	}

	return(edroomValidMsg);

}

	// User-defined Functions   ****************************

void	CCClient::EDROOM_CTX_Top_0::FFreeRes()

{

   //Send message 
   pSerReq.send(SFreeRes); 
}



void	CCClient::EDROOM_CTX_Top_0::FProgRequest()

{
   //Define interval
  Pr_Time interval;
	
 
	interval = Pr_Time(3,0); // interval of X sec + Y microsec
	printf("%s is waiting \n",EDROOMcomponent.EDROOMName);
 
   //Program relative timer 
   Timer.InformIn( interval ); 
}



void	CCClient::EDROOM_CTX_Top_0::FProgWait()

{
   //Define interval
  Pr_Time interval;
	 
	//Timing Service useful methods
	 
	interval = Pr_Time(1,0); // interval of X sec + Y microsec
	printf("%s is waiting \n",EDROOMcomponent.EDROOMName);
   //Program relative timer 
   Timer.InformIn( interval ); 
}



void	CCClient::EDROOM_CTX_Top_0::FProgWorking()

{
   //Define interval
  Pr_Time interval;
	
	//Timing Service useful methods
	 
	//interval = Pr_Time(X,Y); // interval of X sec + Y microsec
 
	interval = Pr_Time(2,0); // interval of X sec + Y microsec
	printf("%s is waiting \n",EDROOMcomponent.EDROOMName);
   //Program relative timer 
   Timer.InformIn( interval ); 
}



void	CCClient::EDROOM_CTX_Top_0::FResRequest()

{

   //Invoke synchronous communication 
   MsgBack=pSerReq.invoke(SResReq); 
}



bool	CCClient::EDROOM_CTX_Top_0::GIsAck()

{

return(MsgBack>signal==SResAck);

}



	//********************************** Pools *************************************



// ***********************************************************************

// class EDROOM_SUB_Top_0

// ***********************************************************************



	// CONSTRUCTOR*************************************************

CCClient::EDROOM_SUB_Top_0::EDROOM_SUB_Top_0 (CCClient&act):
		EDROOM_CTX_Top_0(act)
{

}

	//***************************** EDROOMBehaviour ********************************

void CCClient::EDROOM_SUB_Top_0::EDROOMBehaviour()
{

	TEDROOMTransId edroomCurrentTrans;

	//Behaviour starts from Init State

	edroomCurrentTrans = EDROOMIArrival();

	do
	{

		//Take next transition

		switch(edroomCurrentTrans.localId)
		{

			//Next Transition is Init
			case (Init):
				//Next State is Idl
				edroomNextState = Idl;
				break;
			//To Choice Point ReqRes
			case (ReqRes):

				//Invoke Synchronous Message 
				FResRequest();
				//Evaluate Branch Ack
				if( GIsAck() )
				{

					//Branch taken is ReqRes_Ack
					edroomCurrentTrans.localId =
						ReqRes_Ack;

					//Next State is Working
					edroomNextState = Working;
				 } 
				//Default Branch Nack
				else
				{

					//Branch taken is ReqRes_Nack
					edroomCurrentTrans.localId =
						ReqRes_Nack;

					//Next State is wait
					edroomNextState = wait;
				 } 
				break;
			//To Choice Point TryAgaing
			case (TryAgaing):

				//Send Asynchronous Message 
				FFreeRes();
				//Evaluate Branch Ack
				if( GIsAck() )
				{

					//Branch taken is TryAgaing_Ack
					edroomCurrentTrans.localId =
						TryAgaing_Ack;

					//Next State is Working
					edroomNextState = Working;
				 } 
				//Default Branch Nack
				else
				{

					//Branch taken is TryAgaing_Nack
					edroomCurrentTrans.localId =
						TryAgaing_Nack;

					//Next State is wait
					edroomNextState = wait;
				 } 
				break;
			//Next Transition is FreeRes
			case (FreeRes):
				//Send Asynchronous Message 
				FFreeRes();
				//Next State is Idl
				edroomNextState = Idl;
				break;
		}

		//Entry into the Next State 
		switch(edroomNextState)
		{

				//Go to the state I
			case (I):
				//Arrival to state I
				edroomCurrentTrans=EDROOMIArrival();
				break;

				//Go to the state Idl
			case (Idl):
				//Execute Entry Action 
				FProgRequest();
				//Arrival to state Idl
				edroomCurrentTrans=EDROOMIdlArrival();
				break;

				//Go to the state wait
			case (wait):
				//Execute Entry Action 
				FProgWait();
				//Arrival to state wait
				edroomCurrentTrans=EDROOMwaitArrival();
				break;

				//Go to the state Working
			case (Working):
				//Execute Entry Action 
				FProgWorking();
				//Arrival to state Working
				edroomCurrentTrans=EDROOMWorkingArrival();
				break;

		}

		edroomCurrentState=edroomNextState;

	}while(Msg->signal != EDROOMSignalDestroy);

}



	// Context Init**********************************************

void CCClient::EDROOM_SUB_Top_0::EDROOMInit()
{

edroomCurrentState=I;

}



//	 ***********************************************************************

//	 SubState I

//	 ***********************************************************************



TEDROOMTransId CCClient::EDROOM_SUB_Top_0::EDROOMIArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	//Next transition is  Init
	edroomCurrentTrans.localId = Init;
	edroomCurrentTrans.distanceToContext = 0;
	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  Idl

	// ***********************************************************************



TEDROOMTransId CCClient::EDROOM_SUB_Top_0::EDROOMIdlArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (EDROOMSignalTimeout): 

				 if (*Msg->GetPInterface() == Timer)
				{

					//Next transition is  ReqRes
					edroomCurrentTrans.localId = ReqRes;
					edroomCurrentTrans.distanceToContext = 0 ;
					edroomValidMsg=true;
				 }

				break;

		};

		if (false == edroomValidMsg)
		{
			 edroomValidMsg = EDROOMSearchContextTrans(edroomCurrentTrans);

		}

	} while (false == edroomValidMsg);

	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  wait

	// ***********************************************************************



TEDROOMTransId CCClient::EDROOM_SUB_Top_0::EDROOMwaitArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (EDROOMSignalTimeout): 

				 if (*Msg->GetPInterface() == Timer)
				{

					//Next transition is  TryAgaing
					edroomCurrentTrans.localId = TryAgaing;
					edroomCurrentTrans.distanceToContext = 0 ;
					edroomValidMsg=true;
				 }

				break;

		};

		if (false == edroomValidMsg)
		{
			 edroomValidMsg = EDROOMSearchContextTrans(edroomCurrentTrans);

		}

	} while (false == edroomValidMsg);

	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  Working

	// ***********************************************************************



TEDROOMTransId CCClient::EDROOM_SUB_Top_0::EDROOMWorkingArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (EDROOMSignalTimeout): 

				 if (*Msg->GetPInterface() == Timer)
				{

					//Next transition is  FreeRes
					edroomCurrentTrans.localId= FreeRes;
					edroomCurrentTrans.distanceToContext = 0;
					edroomValidMsg=true;
				 }

				break;

		};

		if (false == edroomValidMsg)
		{
			 edroomValidMsg = EDROOMSearchContextTrans(edroomCurrentTrans);

		}

	} while (false == edroomValidMsg);

	return(edroomCurrentTrans);

}



