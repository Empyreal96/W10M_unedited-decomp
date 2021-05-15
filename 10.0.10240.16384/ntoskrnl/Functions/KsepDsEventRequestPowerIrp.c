// KsepDsEventRequestPowerIrp 
 
int __fastcall KsepDsEventRequestPowerIrp(int result, int a2, int a3, int a4)
{
  __int64 v4; // r4
  int varg_r0; // [sp+80h] [bp+8h]

  varg_r0 = result;
  v4 = KseEtwHandle;
  if ( KseEtwHandle )
  {
    result = EtwEventEnabled(KseEtwHandle, SHIDWORD(KseEtwHandle), (int)KseDsEventRequestPowerIrp);
    if ( result )
      result = EtwWrite(v4, SHIDWORD(v4), (int)KseDsEventRequestPowerIrp, 0);
  }
  return result;
}
