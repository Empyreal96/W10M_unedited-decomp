// PspSetRateControlJobPreCallback 
 
int __fastcall PspSetRateControlJobPreCallback(_DWORD *a1, int a2)
{
  int v4; // r4

  v4 = 0;
  PspSetEffectiveRateControlJob(a1, *(_DWORD *)(a2 + 12), *(_DWORD *)(a2 + 16));
  if ( *(_DWORD *)a2 )
    v4 = (*(int (__fastcall **)(_DWORD *, _DWORD))a2)(a1, *(_DWORD *)(a2 + 8));
  return v4;
}
