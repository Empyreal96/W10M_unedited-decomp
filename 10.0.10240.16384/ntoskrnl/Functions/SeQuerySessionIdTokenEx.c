// SeQuerySessionIdTokenEx 
 
int __fastcall SeQuerySessionIdTokenEx(int a1, _DWORD *a2, _BYTE *a3)
{
  unsigned int v6; // r4
  int v7; // r0
  int v8; // r4
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3

  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = ExAcquireResourceSharedLite(*(_DWORD *)(a1 + 48), 1);
  v8 = *(_DWORD *)(a1 + 120);
  *a2 = v8;
  if ( v8 )
    return sub_7C74D4(v7);
  *a3 = 1;
  v10 = ExReleaseResourceLite(*(_DWORD *)(a1 + 48));
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(v10);
  return 0;
}
