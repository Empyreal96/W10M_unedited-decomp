// SepRefDerefLuidToIndexEntryIfNecessary 
 
int __fastcall SepRefDerefLuidToIndexEntryIfNecessary(int a1, int a2)
{
  unsigned int v4; // r4
  int v5; // r4
  int v6; // r0
  int v7; // r2
  int v8; // r1
  int v9; // r3
  int v10; // r0
  int result; // r0
  int v12; // [sp+0h] [bp-20h] BYREF
  int v13[6]; // [sp+8h] [bp-18h] BYREF

  v13[0] = 0;
  v13[1] = 0;
  v12 = 0;
  if ( (SepTokenSingletonAttributesConfig & 3) != 3 )
    return 0;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  ExAcquireResourceSharedLite(*(_DWORD *)(a1 + 48), 1);
  v5 = SepGetProcUniqueLuidAndIndexFromAttributeInfo(*(_DWORD *)(a1 + 476), &v12, v13);
  ExReleaseResourceLite(*(_DWORD *)(a1 + 48));
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(unsigned __int16 *)(v6 + 0x134);
  v8 = v7 + 1;
  v9 = (__int16)(v7 + 1);
  *(_WORD *)(v6 + 308) = v9;
  if ( (_WORD)v7 == 0xFFFF )
  {
    v9 = *(_DWORD *)(v6 + 100);
    v7 = v6 + 100;
    if ( v9 != v6 + 100 )
    {
      v9 = *(__int16 *)(v6 + 310);
      if ( !*(_WORD *)(v6 + 310) )
        KiCheckForKernelApcDelivery(v6);
    }
  }
  if ( v5 >= 0 )
  {
    if ( a2 )
      v10 = SepDereferenceLuidToIndexEntry((int)v13, v8, v7, v9);
    else
      v10 = SepReferenceLuidToIndexEntry((int)v13, v8, v7, v9);
    v5 = v10;
  }
  if ( v5 == -1073741275 )
    result = 0;
  else
    result = v5;
  return result;
}
