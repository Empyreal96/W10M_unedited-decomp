// SeQuerySecurityAttributesToken 
 
int __fastcall SeQuerySecurityAttributesToken(int a1, int a2, int a3, int a4, int a5, int a6)
{
  unsigned int v10; // r2
  int v11; // r1
  int v12; // r4
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3

  if ( !a5 )
    return sub_7C513C();
  if ( !a4 )
    return -1073741811;
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v10 + 308);
  ExAcquireResourceSharedLite(*(_DWORD *)(a1 + 48), 1);
  v12 = SepInternalQuerySecurityAttributesTokenEx(a1, v11, a2, a3, a4, a5, a6);
  v13 = ExReleaseResourceLite(*(_DWORD *)(a1 + 48));
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_WORD *)(v14 + 0x134) + 1;
  *(_WORD *)(v14 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
    KiCheckForKernelApcDelivery(v13);
  return v12;
}
