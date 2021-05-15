// PspReferenceJobSilo 
 
int __fastcall PspReferenceJobSilo(int a1, int a2, int a3, int a4)
{
  int v6; // r0
  int v8; // r0
  __int16 v9; // r3

  if ( a2 )
  {
    a4 = *(__int16 *)(a2 + 310) - 1;
    *(_WORD *)(a2 + 310) = a4;
  }
  v6 = ExAcquireResourceExclusiveLite(a1 + 32, 1, a3, a4);
  if ( *(_DWORD *)(a1 + 720) )
    return sub_7EB1DC(v6);
  v8 = ExReleaseResourceLite(a1 + 32);
  if ( a2 )
  {
    v9 = *(_WORD *)(a2 + 310) + 1;
    *(_WORD *)(a2 + 310) = v9;
    if ( !v9 && *(_DWORD *)(a2 + 100) != a2 + 100 )
      KiCheckForKernelApcDelivery(v8);
  }
  return 0;
}
