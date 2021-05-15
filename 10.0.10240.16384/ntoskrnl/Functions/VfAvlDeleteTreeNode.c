// VfAvlDeleteTreeNode 
 
int __fastcall VfAvlDeleteTreeNode(_DWORD *a1, int a2, int a3, int a4)
{
  int v6; // r0
  int v7; // r7
  int v9; // r2
  unsigned int *v10; // r2
  unsigned int v11; // r1
  int v12; // r3
  int v13; // r4
  int v14; // [sp+0h] [bp-18h] BYREF
  int v15; // [sp+4h] [bp-14h]

  v15 = a4;
  v14 = a3;
  if ( !a4 )
    a4 = *a1;
  v15 = a4;
  v6 = ViAvlTableIndex((int)a1);
  v7 = v6;
  if ( (*(_BYTE *)(a2 + 5) & 1) == 0 )
    return sub_519320();
  ViAvlAcquireTableLockAtDpcLevelSafe(a1[2] + (v6 << 8), a2);
  RtlDeleteElementGenericTableAvl(a1[2] + (v7 << 8), (int)&v14, v9, a1[2]);
  __dmb(0xBu);
  v10 = a1 + 1;
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 - 1, v10) );
  __dmb(0xBu);
  v12 = a1[2] + (v7 << 8);
  v13 = *(_DWORD *)(v12 + 60);
  *(_DWORD *)(v12 + 60) = 0;
  ViAvlReleaseTableLockFromDpcLevel((unsigned int *)(a1[2] + (v7 << 8)), a2);
  return v13;
}
