// sub_9689D8 
 
void __fastcall sub_9689D8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, char a9, int a10, int *a11, int a12, int a13, int *a14)
{
  int v14; // r7
  __int64 v15; // r4
  __int64 v16; // r4

  a7 = v14;
  v15 = PnpEtwHandle;
  if ( PnpEtwHandle
    && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_EarlyLaunch_StatusNotification_Start) )
  {
    a11 = &a7;
    a12 = 0;
    a13 = 4;
    a14 = 0;
    EtwWrite(v15, SHIDWORD(v15), (int)KMPnPEvt_EarlyLaunch_StatusNotification_Start, 0);
  }
  a11 = (int *)PnpEarlyLaunchStatusNotificationPreProcess;
  a12 = 0;
  a13 = 0;
  a14 = &a8;
  a8 = v14;
  ExNotifyWithProcessing(PnpBootDriverCallbackObject, 0, (int)&a9, (int)&a11);
  v16 = PnpEtwHandle;
  a7 = v14;
  if ( PnpEtwHandle )
  {
    if ( EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_EarlyLaunch_StatusNotification_Stop) )
    {
      a11 = &a7;
      a12 = 0;
      a13 = 4;
      a14 = 0;
      EtwWrite(v16, SHIDWORD(v16), (int)KMPnPEvt_EarlyLaunch_StatusNotification_Stop, 0);
    }
  }
  JUMPOUT(0x9505BE);
}
