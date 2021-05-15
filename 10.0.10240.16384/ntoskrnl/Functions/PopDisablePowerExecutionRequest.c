// PopDisablePowerExecutionRequest 
 
int __fastcall PopDisablePowerExecutionRequest(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r3
  int result; // r0

  v5 = *(_DWORD *)(a1 + 36);
  if ( v5 && a2 || !*(_DWORD *)(a1 + 64) )
    result = 0;
  else
    result = sub_7BF1A8(a1, a2, a3, v5, a5);
  return result;
}
