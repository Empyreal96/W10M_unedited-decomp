// MiInsertLargePageInNodeList 
 
int __fastcall MiInsertLargePageInNodeList(unsigned int a1, unsigned int a2, int a3, int a4)
{
  unsigned int v7; // r4
  unsigned int v8; // r10
  int v9; // r8
  int result; // r0
  int v11; // r5
  unsigned int *v12; // r2
  unsigned int v13; // r0
  int v14; // r0
  unsigned int *v15; // r1
  unsigned int v16; // r0
  unsigned int *v17; // r2
  unsigned int *v18; // r2
  int v19; // [sp+0h] [bp-28h] BYREF
  unsigned int *v20; // [sp+4h] [bp-24h]
  int v21; // [sp+8h] [bp-20h]

  v19 = a2;
  v20 = (unsigned int *)a3;
  v21 = a4;
  v7 = MmPfnDatabase + 24 * a1;
  v8 = v7 + 24 * a2;
  v9 = dword_63F718 + 104 * MiPageToNode();
  if ( a1 >= 0x100000 )
    return sub_50EF68();
  v11 = v9 + 8 * (a3 + 3);
  KeAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)(v9 + 100), &v19);
  if ( (MiFlags & 0x30) != 0 )
  {
    *(_BYTE *)(v7 + 18) ^= (*(_BYTE *)(v7 + 18) ^ a3) & 7;
    v12 = *(unsigned int **)(v11 + 4);
    *(_DWORD *)v7 = v11;
    *(_DWORD *)(v7 + 4) = v12;
    if ( *v12 != v11 )
      __fastfail(3u);
    *v12 = v7;
    *(_DWORD *)(v11 + 4) = v7;
  }
  else
  {
    while ( v7 < v8 )
    {
      v18 = *(unsigned int **)(v11 + 4);
      *(_DWORD *)v7 = v11;
      *(_DWORD *)(v7 + 4) = v18;
      if ( *v18 != v11 )
        __fastfail(3u);
      *v18 = v7;
      *(_DWORD *)(v11 + 4) = v7;
      v7 += 24576;
    }
  }
  *(_DWORD *)(v9 + 4 * (a3 + 12)) += a2 >> 10;
  *(_DWORD *)(v9 + 4 * a3) += a2 >> 10;
  if ( a3 )
  {
    do
      v16 = __ldrex((unsigned int *)&dword_63FC00);
    while ( __strex(v16 + a2, (unsigned int *)&dword_63FC00) );
  }
  else
  {
    do
      v13 = __ldrex((unsigned int *)&dword_63FB80);
    while ( __strex(v13 + a2, (unsigned int *)&dword_63FB80) );
  }
  MiIncreaseAvailablePages();
  if ( (dword_682604 & 0x10000) != 0 )
    return KiReleaseQueuedSpinLockInstrumented(&v19);
  v14 = v19;
  if ( v19 )
    goto LABEL_18;
  v15 = v20;
  __dmb(0xBu);
  do
    result = __ldrex(v15);
  while ( (int *)result == &v19 && __strex(0, v15) );
  if ( (int *)result != &v19 )
  {
    v14 = KxWaitForLockChainValid(&v19);
LABEL_18:
    v19 = 0;
    __dmb(0xBu);
    v17 = (unsigned int *)(v14 + 4);
    do
      result = __ldrex(v17);
    while ( __strex(result ^ 1, v17) );
  }
  return result;
}
