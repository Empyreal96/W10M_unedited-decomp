// IopCancelAlertedRequest 
 
int __fastcall IopCancelAlertedRequest(unsigned int a1, int a2)
{
  int v4; // r0
  int v5; // r6
  int v6; // r4
  int result; // r0
  unsigned int v8[6]; // [sp+8h] [bp-18h] BYREF

  v4 = KfRaiseIrql(1);
  v5 = v4;
  if ( *(_DWORD *)(a1 + 4) )
    return KfLowerIrql(v4);
  v6 = IoCancelIrp(a2);
  result = KfLowerIrql(v5);
  if ( !v6 )
    return KeWaitForSingleObject(a1, 0, 0, 0, 0);
  v8[0] = -100000;
  v8[1] = -1;
  while ( !*(_DWORD *)(a1 + 4) )
    result = KeDelayExecutionThread(0, 0, v8);
  return result;
}
