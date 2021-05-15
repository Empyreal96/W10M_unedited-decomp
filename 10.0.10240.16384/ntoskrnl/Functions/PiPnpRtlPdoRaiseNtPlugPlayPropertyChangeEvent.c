// PiPnpRtlPdoRaiseNtPlugPlayPropertyChangeEvent 
 
int __fastcall PiPnpRtlPdoRaiseNtPlugPlayPropertyChangeEvent(int result, int a2)
{
  int v2; // r2

  if ( !result )
    JUMPOUT(0x81180C);
  v2 = *(_DWORD *)(*(_DWORD *)(result + 176) + 20);
  if ( !v2 || (*(_DWORD *)(v2 + 268) & 0x20000) != 0 )
    sub_81176C();
  if ( v2 != -20 )
    result = PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, *(_DWORD *)(v2 + 24), a2);
  return result;
}
