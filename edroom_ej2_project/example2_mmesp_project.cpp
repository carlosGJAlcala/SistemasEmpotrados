//##############################################################################
//###############     This file has been generated by EDROOM     ###############
//##############################################################################
 
#include <public/edroom_glue.h>
 
 
//******************************************************************************
// include deployment edroom components
 
#include <public/ccserver_iface_v1.h>
#include <public/ccclient_iface_v1.h>
#include <public/ccclient_iface_v1.h>
#include <public/ccclient_iface_v1.h>
#include <public/ccclient_iface_v1.h>
 
#ifdef CONFIG_EDROOMBP_DEPLOYMENT_NEED_TASK
 
	CEDROOMSystemDeployment systemDeployment;
 
#endif
 
 
 
rtems_task Init (uint32_t arg){
 
 
 
#ifndef CONFIG_EDROOMBP_DEPLOYMENT_NEED_TASK
 
	CEDROOMSystemDeployment systemDeployment;
 
#endif
 
 
	CCServer	comp2(2, 10, EDROOMprioNormal, 1024, systemDeployment.GetComp2Memory());
	CCClient	comp3(3, 14, EDROOMprioNormal, 1024, systemDeployment.GetComp3Memory());
	CCClient	comp4(4, 14, EDROOMprioNormal, 1024, systemDeployment.GetComp4Memory());
	CCClient	comp5(5, 14, EDROOMprioNormal, 1024, systemDeployment.GetComp5Memory());
	CCClient	comp6(6, 14, EDROOMprioNormal, 1024, systemDeployment.GetComp6Memory());
 
	systemDeployment.Config(&comp2, &comp3, &comp4, &comp5, &comp6);
 
	systemDeployment.Start();
 
	;
 
}
