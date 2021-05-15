// SeQueryServerSiloToken 
 
int __fastcall SeQueryServerSiloToken(int *a1, _DWORD *a2)
{
  unsigned int v4; // r2
  int v5; // r0
  int v7; // r0
  unsigned int v8; // r1
  __int16 v9; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = ExAcquireResourceSharedLite(a1[12], 1);
  if ( (a1[44] & 0x20) != 0 )
    return sub_7EA850(v5);
  *a2 = *(_DWORD *)(a1[48] + 88);
  v7 = ExReleaseResourceLite(a1[12]);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x134) + 1;
  *(_WORD *)(v8 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    KiCheckForKernelApcDelivery(v7);
  return 0;
}
