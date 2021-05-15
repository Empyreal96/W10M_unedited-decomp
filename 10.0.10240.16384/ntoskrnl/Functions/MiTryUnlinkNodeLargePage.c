// MiTryUnlinkNodeLargePage 
 
int __fastcall MiTryUnlinkNodeLargePage(int a1, int a2, int a3, int a4)
{
  int v5; // r5
  int v6; // r4
  int v7; // r9
  unsigned __int8 *v8; // r1
  unsigned int v9; // r2
  int v11; // r7
  int v12; // r5
  unsigned int v13; // r2
  int v14; // r1
  int v15; // r0
  unsigned int *v16; // r2
  unsigned int v17; // r0
  unsigned int *v18; // r2
  unsigned int v19; // r0
  unsigned int *v20; // r1
  int *v21; // r0
  int v22; // r0
  unsigned int *v23; // r1
  int *v24; // r0
  unsigned int *v25; // r2
  unsigned int v26; // r0
  unsigned int *v27; // r2
  unsigned int v28; // r0
  int v29; // [sp+0h] [bp-28h] BYREF
  unsigned int *v30; // [sp+4h] [bp-24h]
  int v31; // [sp+8h] [bp-20h]
  int v32; // [sp+Ch] [bp-1Ch]

  v29 = a1;
  v30 = (unsigned int *)a2;
  v31 = a3;
  v32 = a4;
  v5 = MiPageToNode();
  v6 = MmPfnDatabase + 24 * a1;
  v7 = KfRaiseIrql(2);
  v8 = (unsigned __int8 *)(v6 + 15);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 | 0x80, v8) );
  __dmb(0xBu);
  if ( v9 >> 7 )
    return sub_550060();
  v11 = dword_63F718 + 104 * v5;
  KeAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)(v11 + 100), &v29);
  v12 = *(_BYTE *)(v6 + 18) & 7;
  if ( (*(_DWORD *)(v6 + 20) & 0xFFFFF) != 1048574
    || (*(_BYTE *)(v6 + 18) & 7u) > 1
    || (v13 = *(_DWORD *)(v6 + 4), (v13 & 0x80000000) == 0) )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(&v29);
    }
    else
    {
      v22 = v29;
      if ( !v29 )
      {
        v23 = v30;
        __dmb(0xBu);
        do
          v24 = (int *)__ldrex(v23);
        while ( v24 == &v29 && __strex(0, v23) );
        if ( v24 == &v29 )
          goto LABEL_35;
        v22 = KxWaitForLockChainValid(&v29);
      }
      v29 = 0;
      __dmb(0xBu);
      v25 = (unsigned int *)(v22 + 4);
      do
        v26 = __ldrex(v25);
      while ( __strex(v26 ^ 1, v25) );
    }
LABEL_35:
    __dmb(0xBu);
    v27 = (unsigned int *)(v6 + 12);
    do
      v28 = __ldrex(v27);
    while ( __strex(v28 & 0x7FFFFFFF, v27) );
    KfLowerIrql(v7);
    return 5;
  }
  v14 = *(_DWORD *)v6;
  if ( *(_DWORD *)(*(_DWORD *)v6 + 4) != v6 || *(_DWORD *)v13 != v6 )
    __fastfail(3u);
  *(_DWORD *)v13 = v14;
  *(_DWORD *)(v14 + 4) = v13;
  MiUnlinkNodeLargePageHelper(v11, v6, v12, 0);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(&v29);
  }
  else
  {
    v15 = v29;
    if ( !v29 )
    {
      v20 = v30;
      __dmb(0xBu);
      do
        v21 = (int *)__ldrex(v20);
      while ( v21 == &v29 && __strex(0, v20) );
      if ( v21 == &v29 )
        goto LABEL_14;
      v15 = KxWaitForLockChainValid(&v29);
    }
    v29 = 0;
    __dmb(0xBu);
    v16 = (unsigned int *)(v15 + 4);
    do
      v17 = __ldrex(v16);
    while ( __strex(v17 ^ 1, v16) );
  }
LABEL_14:
  __dmb(0xBu);
  v18 = (unsigned int *)(v6 + 12);
  do
    v19 = __ldrex(v18);
  while ( __strex(v19 & 0x7FFFFFFF, v18) );
  KfLowerIrql(v7);
  return v12;
}
