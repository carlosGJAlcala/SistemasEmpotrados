#include <public/ccserver_iface_v1.h>

// ***********************************************************************

// class EDROOM_CTX_Top_0

// ***********************************************************************



	// CONSTRUCTORS***********************************************

CCServer::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(CCServer &act,
	 TEDROOMUInt8 & EDROOMpVarVresFreeNumber ):

	EDROOMcomponent(act),
	Msg(EDROOMcomponent.Msg),
	MsgBack(EDROOMcomponent.MsgBack),
	pService4(EDROOMcomponent.pService4),
	pService3(EDROOMcomponent.pService3),
	pService2(EDROOMcomponent.pService2),
	pService1(EDROOMcomponent.pService1),
	VresFreeNumber(EDROOMpVarVresFreeNumber)
{
}

CCServer::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(EDROOM_CTX_Top_0 &context):

	EDROOMcomponent(context.EDROOMcomponent),
	Msg(context.Msg),
	MsgBack(context.MsgBack),
	pService4(context.pService4),
	pService3(context.pService3),
	pService2(context.pService2),
	pService1(context.pService1),
	VresFreeNumber(context.VresFreeNumber)
{

}

	// EDROOMSearchContextTrans********************************************

bool CCServer::EDROOM_CTX_Top_0::EDROOMSearchContextTrans(
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

void	CCServer::EDROOM_CTX_Top_0::FAck()

{

VresFreeNumber --;
   //Reply synchronous communication
   Msg->reply(SResAck); 
}



void	CCServer::EDROOM_CTX_Top_0::FFreeResource()

{

VresFreeNumber ++;

}



void	CCServer::EDROOM_CTX_Top_0::FNack()

{

   //Reply synchronous communication
   Msg->reply(SResAck); 
}



bool	CCServer::EDROOM_CTX_Top_0::GResAvailable()

{

return VresFreeNumber;

}



	//********************************** Pools *************************************



// ***********************************************************************

// class EDROOM_SUB_Top_0

// ***********************************************************************



	// CONSTRUCTOR*************************************************

CCServer::EDROOM_SUB_Top_0::EDROOM_SUB_Top_0 (CCServer&act):
		EDROOM_CTX_Top_0(act,
			VresFreeNumber),
		VresFreeNumber(2)
{

}

	//***************************** EDROOMBehaviour ********************************

void CCServer::EDROOM_SUB_Top_0::EDROOMBehaviour()
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
				//Next State is Ready
				edroomNextState = Ready;
				break;
			//To Choice Point ResRequest
			case (ResRequest):

				//Evaluate Branch Ack
				if( GResAvailable() )
				{
					//Invoke Synchronous Message 
					FAck();

					//Branch taken is ResRequest_Ack
					edroomCurrentTrans.localId =
						ResRequest_Ack;

					//Next State is Ready
					edroomNextState = Ready;
				 } 
				//Default Branch Nack
				else
				{
					//Invoke Synchronous Message 
					FNack();

					//Branch taken is ResRequest_Nack
					edroomCurrentTrans.localId =
						ResRequest_Nack;

					//Next State is Ready
					edroomNextState = Ready;
				 } 
				break;
			//Next Transition is FreeResource
			case (FreeResource):
				//Execute Action 
				FFreeResource();
				//Next State is Ready
				edroomNextState = Ready;
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

				//Go to the state Ready
			case (Ready):
				//Arrival to state Ready
				edroomCurrentTrans=EDROOMReadyArrival();
				break;

		}

		edroomCurrentState=edroomNextState;

	}while(Msg->signal != EDROOMSignalDestroy);

}



	// Context Init**********************************************

void CCServer::EDROOM_SUB_Top_0::EDROOMInit()
{

edroomCurrentState=I;

}



//	 ***********************************************************************

//	 SubState I

//	 ***********************************************************************



TEDROOMTransId CCServer::EDROOM_SUB_Top_0::EDROOMIArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	//Next transition is  Init
	edroomCurrentTrans.localId = Init;
	edroomCurrentTrans.distanceToContext = 0;
	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  Ready

	// ***********************************************************************



TEDROOMTransId CCServer::EDROOM_SUB_Top_0::EDROOMReadyArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (SResReq): 

				 {
					//Next transition is  ResRequest
					edroomCurrentTrans.localId = ResRequest;
					edroomCurrentTrans.distanceToContext = 0 ;
					edroomValidMsg=true;
				 }

				break;

			case (SFreeRes): 

				 {
					//Next transition is  FreeResource
					edroomCurrentTrans.localId= FreeResource;
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



