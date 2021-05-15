// SeQuerySessionIdToken 
 
int __fastcall SeQuerySessionIdToken(int a1, _DWORD *a2)
{
  unsigned int v4; // r2
  int v5; // r0
  unsigned int v6; // r1
  __int16 v7; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  ExAcquireResourceSharedLite(*(_DWORD *)(a1 + 48), 1);
  *a2 = *(_DWORD *)(a1 + 120);
  v5 = ExReleaseResourceLite(*(_DWORD *)(a1 + 48));
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_WORD *)(v6 + 0x134) + 1;
  *(_WORD *)(v6 + 308) = v7;
  if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    KiCheckForKernelApcDelivery(v5);
  return 0;
}
