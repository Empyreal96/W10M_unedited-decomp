// PnpGetStableSystemBootTime 
 
int __fastcall PnpGetStableSystemBootTime(_QWORD *a1)
{
  int result; // r0
  __int64 v3; // [sp+0h] [bp-40h]
  __int64 v4; // [sp+20h] [bp-20h]

  result = PipHardwareConfigGetLastUseTime((int)a1, (int)a1);
  if ( result < 0 )
  {
    result = ZwQuerySystemInformation();
    if ( result >= 0 )
      *a1 = v3 - v4;
  }
  return result;
}
