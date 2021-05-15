// sub_51933C 
 
void __fastcall sub_51933C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // r6
  int v11; // r9
  unsigned int v12; // r10
  int v13; // r4
  char v14; // r0
  char v15; // r3

  if ( v12 > 1 )
    a10 = a4;
  v13 = ViAvlTableIndex(v11);
  if ( (*(_BYTE *)(v10 + 5) & 1) == 0 )
  {
    v14 = KfRaiseIrql(2);
    v15 = *(_BYTE *)(v10 + 5);
    *(_BYTE *)(v10 + 4) = v14;
    *(_BYTE *)(v10 + 5) = v15 | 1;
  }
  ViAvlAcquireTableLockAtDpcLevelSafe(*(_DWORD *)(v11 + 8) + (v13 << 8), v10);
  if ( !RtlLookupElementGenericTableFullAvl(*(_DWORD *)(v11 + 8) + (v13 << 8), (int)&a9, &a7, &a6) )
  {
    ViAvlReleaseTableLockFromDpcLevel((unsigned int *)(*(_DWORD *)(v11 + 8) + (v13 << 8)), v10);
    JUMPOUT(0x4DABC4);
  }
  JUMPOUT(0x4DAC2A);
}
