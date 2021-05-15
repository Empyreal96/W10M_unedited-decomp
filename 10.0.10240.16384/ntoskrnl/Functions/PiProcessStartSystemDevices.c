// PiProcessStartSystemDevices 
 
int __fastcall PiProcessStartSystemDevices(int a1, int a2, int a3)
{
  int v5; // r0
  __int64 v6; // r4
  int v7; // [sp+10h] [bp-20h] BYREF
  char v8; // [sp+14h] [bp-1Ch]

  if ( PnpEtwHandle )
    return sub_81C584(a1, a2, a3, PnpEtwHandle | HIDWORD(PnpEtwHandle));
  v5 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 176) + 20);
  v7 = 3;
  v8 = PnPBootDriversInitialized;
  PipProcessDevNodeTree(v5, a1, (int)&v7, 0, 0, 0, 0);
  v6 = PnpEtwHandle;
  if ( PnpEtwHandle )
  {
    if ( EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_SystemStartPnPEnum_Stop) )
      EtwWrite(v6, SHIDWORD(v6), (int)KMPnPEvt_SystemStartPnPEnum_Stop, 0);
  }
  return 0;
}
