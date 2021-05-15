// MiUnlinkFreeOrZeroedPage 
 
int __fastcall MiUnlinkFreeOrZeroedPage(int a1, _DWORD *a2)
{
  _DWORD *v2; // r5
  int v3; // r9
  int v4; // r6
  int v5; // r4
  int v6; // r10
  int v7; // r3
  unsigned int *v8; // r2
  unsigned int v9; // r1
  int result; // r0
  int v11; // r2
  int v12; // r1
  int v13; // r5
  int v14; // r0
  unsigned int *v15; // r1
  int *v16; // r0
  unsigned int *v17; // r2
  unsigned int v18; // r1
  int v19; // r3
  unsigned int *v20; // r2
  unsigned int v21; // r4
  int v22; // r3
  bool v23; // zf
  unsigned int v24; // [sp+0h] [bp-30h]
  int v25; // [sp+4h] [bp-2Ch]
  int var28[11]; // [sp+8h] [bp-28h] BYREF

  v2 = a2;
  v3 = a1;
  v4 = MmPfnDatabase + 24 * a1;
  v5 = *(_BYTE *)(v4 + 18) & 7;
  v25 = v5;
  v6 = *(_DWORD *)(v4 + 20) >> 28;
  v24 = (v6 << byte_6337F5) | dword_633814 & a1;
  if ( a2 )
  {
    v6 = -1;
  }
  else
  {
    v7 = *(_DWORD *)&MiSystemPartition[2 * v5 + 512];
    v2 = (_DWORD *)(v7 + 20 * ((v6 << byte_6337F5) | dword_633814 & a1));
    a1 = KeAcquireInStackQueuedSpinLockAtDpcLevel(v2 + 4, var28, 5 * ((v6 << byte_6337F5) | dword_633814 & a1), v7);
  }
  v8 = *(unsigned int **)&MiSystemPartition[2 * v5 + 1226];
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 - 1, v8) );
  if ( dword_634380 == 1 )
    return sub_53BC54(a1);
  --*v2;
  if ( v2[2] == v3 )
  {
    v22 = *(_DWORD *)v4;
    v12 = 0xFFFFF;
    v23 = *(_DWORD *)v4 == 0xFFFFF;
    v2[2] = *(_DWORD *)v4;
    if ( !v23 )
    {
      v11 = 3 * v22;
      goto LABEL_10;
    }
    v2[3] = 0xFFFFF;
  }
  else
  {
    *(_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)(v4 + 12) & 0xFFFFF)) = *(_DWORD *)v4;
    if ( *(_DWORD *)v4 != 0xFFFFF )
    {
      v11 = 3 * *(_DWORD *)v4;
      v12 = *(_DWORD *)(v4 + 12) & 0xFFFFF;
LABEL_10:
      MiSetPfnBlink(MmPfnDatabase + 8 * v11, v12, 0);
      goto LABEL_11;
    }
    v2[3] = *(_DWORD *)(v4 + 12) & 0xFFFFF;
  }
LABEL_11:
  *(_BYTE *)(v4 + 18) = *(_BYTE *)(v4 + 18) & 0xF8 | 5;
  v13 = (unsigned __int8)byte_634378;
  if ( v6 != -1 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(var28);
    }
    else
    {
      v14 = var28[0];
      if ( !var28[0] )
      {
        v15 = (unsigned int *)var28[1];
        __dmb(0xBu);
        do
          v16 = (int *)__ldrex(v15);
        while ( v16 == var28 && __strex(0, v15) );
        if ( v16 == var28 )
          goto LABEL_18;
        v14 = KxWaitForLockChainValid(var28);
      }
      var28[0] = 0;
      __dmb(0xBu);
      v20 = (unsigned int *)(v14 + 4);
      do
        v21 = __ldrex(v20);
      while ( __strex(v21 ^ 1, v20) );
    }
  }
LABEL_18:
  v17 = (unsigned int *)(dword_63F718 + 4 * (v25 + 26 * (v24 >> byte_6337F5) + 14));
  do
    v18 = __ldrex(v17);
  while ( __strex(v18 - 1, v17) );
  result = MiDecreaseAvailablePages((int)MiSystemPartition, 1);
  v19 = *(_DWORD *)(v4 + 12);
  *(_DWORD *)v4 = 0;
  *(_DWORD *)(v4 + 8) = 0;
  *(_DWORD *)(v4 + 12) = v19 & 0xFFF00000;
  if ( v25 == 1 || v13 == 1 )
    *(_DWORD *)(v4 + 8) = 128;
  return result;
}
