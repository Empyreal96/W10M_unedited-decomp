// KsepDsEventDevicePowerIrp 
 
int __fastcall KsepDsEventDevicePowerIrp(int result, int a2, int a3, int a4)
{
  __int64 v4; // r4
  int varg_r0; // [sp+90h] [bp+8h]

  varg_r0 = result;
  v4 = KseEtwHandle;
  if ( KseEtwHandle )
  {
    result = EtwEventEnabled(KseEtwHandle, SHIDWORD(KseEtwHandle), (int)KseDsEventDevicePowerIrp);
    if ( result )
      result = EtwWrite(v4, SHIDWORD(v4), (int)KseDsEventDevicePowerIrp, 0);
  }
  return result;
}
