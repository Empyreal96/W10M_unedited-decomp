// ExpRemovePoolTrackerExpansion 
 
int __fastcall ExpRemovePoolTrackerExpansion(int a1, int a2, int a3, int a4)
{
  char v6; // r5
  unsigned int v7; // r2
  int v8; // r4
  int v9; // r2
  int v10; // r3
  int *v11; // r0
  int v12; // r1
  int v13; // t1
  int v14; // r1
  int v15; // r2
  _DWORD *v16; // r2
  int result; // r0
  unsigned int *v18; // r4
  unsigned int *v19; // r2
  unsigned int v20; // r1
  unsigned int *v21; // r2
  unsigned int v22; // r4
  unsigned int *v23; // r2
  unsigned int v24; // r1
  unsigned int *v25; // r2
  unsigned int v26; // r4
  _DWORD v27[8]; // [sp+0h] [bp-20h] BYREF

  v27[0] = a2;
  v27[1] = a3;
  v27[2] = a4;
  v6 = a3;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&ExpTaggedPoolLock, (unsigned int)v27);
  if ( (v6 & 0x20) != 0 )
  {
    v9 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
    v8 = *(_DWORD *)(v9 + 8372);
    v7 = *(_DWORD *)(v9 + 8376);
  }
  else
  {
    v7 = PoolTrackTableExpansionSize;
    v8 = PoolTrackTableExpansion;
  }
  v10 = 0;
  if ( v7 )
  {
    v11 = (int *)v8;
    while ( 1 )
    {
      v13 = *v11;
      v11 += 7;
      v12 = v13;
      if ( v13 == a1 )
        break;
      if ( v12 )
      {
        if ( ++v10 < v7 )
          continue;
      }
      goto LABEL_9;
    }
    v16 = (_DWORD *)(v8 + 28 * v10);
    if ( (v6 & 1) != 0 )
    {
      ++v16[5];
      v16[6] -= a2;
    }
    else
    {
      ++v16[2];
      v16[3] -= a2;
    }
    result = KeReleaseInStackQueuedSpinLock((int)v27);
  }
  else
  {
LABEL_9:
    KeReleaseInStackQueuedSpinLock((int)v27);
    if ( (v6 & 0x20) != 0 )
    {
      v15 = ExpSessionPoolTrackTable;
      v14 = ExpSessionPoolTrackTableSize - 1;
    }
    else
    {
      v14 = PoolTrackTableSize - 1;
      v15 = ExPoolTagTables[*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594)];
    }
    v18 = (unsigned int *)(v15 + 28 * v14);
    if ( (v6 & 1) != 0 )
    {
      v23 = v18 + 5;
      do
        v24 = __ldrex(v23);
      while ( __strex(v24 + 1, v23) );
      result = -a2;
      v25 = v18 + 6;
      do
        v26 = __ldrex(v25);
      while ( __strex(v26 - a2, v25) );
    }
    else
    {
      v19 = v18 + 2;
      do
        v20 = __ldrex(v19);
      while ( __strex(v20 + 1, v19) );
      result = -a2;
      v21 = v18 + 3;
      do
        v22 = __ldrex(v21);
      while ( __strex(v22 - a2, v21) );
    }
  }
  return result;
}
