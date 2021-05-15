// PopThermalStandbyNotify 
 
int __fastcall PopThermalStandbyNotify(int a1)
{
  if ( a1 )
    PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_THERMAL_STANDBY_NOTIFICATION);
  return ZwUpdateWnfStateData();
}
