// PnpCompleteSystemStartProcess 
 
int PnpCompleteSystemStartProcess()
{
  __int64 v0; // r4
  int result; // r0
  __int64 v2; // r4
  int v3; // r0
  int v4; // r0
  int v5; // r0
  __int64 v6; // r4

  v0 = PnpEtwHandle;
  if ( PnpEtwHandle )
  {
    if ( EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_SystemStartLegacyEnum_Start) )
      return sub_552BA0();
    if ( v0 && EtwEventEnabled(v0, SHIDWORD(v0), (int)KMPnPEvt_SystemStartDriverReinit_Start) )
      EtwWrite(v0, SHIDWORD(v0), (int)KMPnPEvt_SystemStartDriverReinit_Start, 0);
  }
  IopCallDriverReinitializationRoutines(1);
  v2 = PnpEtwHandle;
  if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_SystemStartDriverReinit_Stop) )
    EtwWrite(v2, SHIDWORD(v2), (int)KMPnPEvt_SystemStartDriverReinit_Stop, 0);
  PnPInitialized = 1;
  v3 = KeSetEvent((int)&PnpSystemDeviceEnumerationComplete, 0, 0);
  v4 = PiInitReleaseCachedGroupInformation(v3);
  v5 = PpReleaseBootDDB(v4);
  result = KseShimDatabaseBootRelease(v5);
  v6 = PnpEtwHandle;
  if ( PnpEtwHandle )
  {
    result = EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_SystemStartLegacyEnum_Stop);
    if ( result )
    {
      result = EtwWrite(v6, SHIDWORD(v6), (int)KMPnPEvt_SystemStartLegacyEnum_Stop, 0);
      v6 = PnpEtwHandle;
    }
    if ( v6 )
      result = EtwWriteEndScenario(v6, HIDWORD(v6), KMPnPEvt_DriverInitPhase_Stop, &PnpDriverInitPhaseActivityId);
  }
  return result;
}
