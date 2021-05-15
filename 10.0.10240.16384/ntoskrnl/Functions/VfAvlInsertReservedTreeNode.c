// VfAvlInsertReservedTreeNode 
 
int __fastcall VfAvlInsertReservedTreeNode(int a1, int a2, _DWORD *a3, int a4)
{
  int v7; // r7
  char v8; // r0
  char v9; // r3
  unsigned int *v10; // r2
  unsigned int v11; // r1
  _DWORD v13[6]; // [sp+0h] [bp-18h] BYREF

  v13[0] = a3;
  v13[1] = a4;
  v7 = ViAvlTableIndex(a1, *a3);
  if ( (*(_BYTE *)(a2 + 5) & 1) == 0 )
  {
    v8 = KfRaiseIrql(2);
    v9 = *(_BYTE *)(a2 + 5);
    *(_BYTE *)(a2 + 4) = v8;
    *(_BYTE *)(a2 + 5) = v9 | 1;
  }
  ViAvlAcquireTableLockAtDpcLevelSafe(*(_DWORD *)(a1 + 8) + (v7 << 8), a2);
  *(_DWORD *)(*(_DWORD *)(a1 + 8) + (v7 << 8) + 56) = a3;
  RtlInsertElementGenericTableAvl(*(_DWORD *)(a1 + 8) + (v7 << 8), (int)a3, 4, (int)v13);
  __dmb(0xBu);
  v10 = (unsigned int *)(a1 + 4);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 + 1, v10) );
  __dmb(0xBu);
  return ViAvlReleaseTableLockFromDpcLevel(*(_DWORD *)(a1 + 8) + (v7 << 8), a2);
}
