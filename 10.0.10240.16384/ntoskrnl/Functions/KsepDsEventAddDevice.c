// KsepDsEventAddDevice 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KsepDsEventAddDevice(int result, int a2, int a3, int a4)
{
  int v4; // r5 OVERLAPPED
  int v5; // r6 OVERLAPPED
  int varg_r0; // [sp+90h] [bp+8h]

  varg_r0 = result;
  *(_QWORD *)&v4 = KseEtwHandle;
  if ( KseEtwHandle )
  {
    result = EtwEventEnabled(KseEtwHandle, SHIDWORD(KseEtwHandle), (int)KseDsEventAddDevice);
    if ( result )
      result = EtwWrite(v4, v5, (int)KseDsEventAddDevice, 0);
  }
  return result;
}
