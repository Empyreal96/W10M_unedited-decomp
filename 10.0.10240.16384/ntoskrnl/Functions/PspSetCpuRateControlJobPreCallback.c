// PspSetCpuRateControlJobPreCallback 
 
int __fastcall PspSetCpuRateControlJobPreCallback(int a1, int a2)
{
  int v2; // r3

  if ( a2 )
    v2 = a2 + 128;
  else
    v2 = 0;
  *(_DWORD *)(a1 + 536) = v2;
  return 0;
}
