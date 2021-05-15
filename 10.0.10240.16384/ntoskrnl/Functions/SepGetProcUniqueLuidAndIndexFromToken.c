// SepGetProcUniqueLuidAndIndexFromToken 
 
int __fastcall SepGetProcUniqueLuidAndIndexFromToken(int a1, _DWORD *a2, _DWORD *a3)
{
  int v3; // r4
  unsigned int v7; // r4
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3

  v3 = -1073741275;
  if ( (SepTokenSingletonAttributesConfig & 3) == 3 )
  {
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v7 + 308);
    ExAcquireResourceSharedLite(*(_DWORD *)(a1 + 48), 1);
    v3 = SepGetProcUniqueLuidAndIndexFromAttributeInfo(*(_DWORD *)(a1 + 476), a2, a3);
    v8 = ExReleaseResourceLite(*(_DWORD *)(a1 + 48));
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = *(_WORD *)(v9 + 0x134) + 1;
    *(_WORD *)(v9 + 308) = v10;
    if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
      KiCheckForKernelApcDelivery(v8);
  }
  return v3;
}
