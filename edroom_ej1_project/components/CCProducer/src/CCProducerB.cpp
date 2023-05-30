#include <public/ccproducer_iface_v1.h>

// ***********************************************************************

// class EDROOM_CTX_Top_0

// ***********************************************************************



	// CONSTRUCTORS***********************************************

CCProducer::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(CCProducer &act,
	 TEDROOMByte & EDROOMpVarVaux,
	 CEDROOMPOOLTEDROOMByte & EDROOMpPoolTEDROOMByte ):

	EDROOMcomponent(act),
	Msg(EDROOMcomponent.Msg),
	MsgBack(EDROOMcomponent.MsgBack),
	pOut(EDROOMcomponent.pOut),
	VauxLimit('z'),
	Vaux(EDROOMpVarVaux),
	EDROOMPoolTEDROOMByte(EDROOMpPoolTEDROOMByte)
{
}

CCProducer::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(EDROOM_CTX_Top_0 &context):

	EDROOMcomponent(context.EDROOMcomponent),
	Msg(context.Msg),
	MsgBack(context.MsgBack),
	pOut(context.pOut),
	VauxLimit('z'),
	Vaux(context.Vaux),
	EDROOMPoolTEDROOMByte(context.EDROOMPoolTEDROOMByte )
{

}

	// EDROOMSearchContextTrans********************************************

bool CCProducer::EDROOM_CTX_Top_0::EDROOMSearchContextTrans(
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

void	CCProducer::EDROOM_CTX_Top_0::FResetData()

{

Vaux='a';

}



void	CCProducer::EDROOM_CTX_Top_0::FSendData()

{
   //Allocate data from pool
  TEDROOMByte * pSData_Data = EDROOMPoolTEDROOMByte.AllocData();
	
		// Complete Data 
	
	*pSData_Data=Vaux;
	Vaux++;
   //Send message 
   pOut.send(SData,pSData_Data,&EDROOMPoolTEDROOMByte); 
}



bool	CCProducer::EDROOM_CTX_Top_0::GNeedReset()

{

return (Vaux>VauxLimit);

}



	//********************************** Pools *************************************

	//CEDROOMPOOLTEDROOMByte

CCProducer::EDROOM_CTX_Top_0::CEDROOMPOOLTEDROOMByte::CEDROOMPOOLTEDROOMByte(
			TEDROOMUInt32 elemCount,TEDROOMByte* pMem,bool * pMemMarks):
				CEDROOMProtectedMemoryPool(elemCount, pMem, pMemMarks,
					sizeof(TEDROOMByte))
{
}

TEDROOMByte *	CCProducer::EDROOM_CTX_Top_0::CEDROOMPOOLTEDROOMByte::AllocData()
{
	return(TEDROOMByte*)CEDROOMProtectedMemoryPool::AllocData();
}



// ***********************************************************************

// class EDROOM_SUB_Top_0

// ***********************************************************************



	// CONSTRUCTOR*************************************************

CCProducer::EDROOM_SUB_Top_0::EDROOM_SUB_Top_0 (CCProducer&act
	,CEDROOMMemory *pEDROOMMemory):
		EDROOM_CTX_Top_0(act,
			Vaux,
			EDROOMPoolTEDROOMByte),
		Vaux('a'),
		EDROOMPoolTEDROOMByte(
			10, pEDROOMMemory->poolTEDROOMByte,
			pEDROOMMemory->poolMarkTEDROOMByte)
{

}

	//***************************** EDROOMBehaviour ********************************

void CCProducer::EDROOM_SUB_Top_0::EDROOMBehaviour()
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
			//To Choice Point SendData
			case (SendData):

				//Send Asynchronous Message 
				FSendData();
				//Evaluate Branch ReseTData
				if( GNeedReset() )
				{
					//Execute Action 
					FResetData();

					//Branch taken is SendData_ReseTData
					edroomCurrentTrans.localId =
						SendData_ReseTData;

					//Next State is Ready
					edroomNextState = Ready;
				 } 
				//Default Branch DatoOk
				else
				{

					//Branch taken is SendData_DatoOk
					edroomCurrentTrans.localId =
						SendData_DatoOk;

					//Next State is Ready
					edroomNextState = Ready;
				 } 
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

void CCProducer::EDROOM_SUB_Top_0::EDROOMInit()
{

edroomCurrentState=I;

}



//	 ***********************************************************************

//	 SubState I

//	 ***********************************************************************



TEDROOMTransId CCProducer::EDROOM_SUB_Top_0::EDROOMIArrival()
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



TEDROOMTransId CCProducer::EDROOM_SUB_Top_0::EDROOMReadyArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (SConReady): 

				 if (*Msg->GetPInterface() == pOut)
				{

					//Next transition is  SendData
					edroomCurrentTrans.localId = SendData;
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



