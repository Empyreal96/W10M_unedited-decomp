// InitializePagedPool 
 
int InitializePagedPool()
{
  int result; // r0
  int v1; // r3
  int v2; // r8
  int v3; // r0
  int *v4; // r5
  unsigned int v5; // r8
  int *v6; // r9
  int v7; // r6
  _DWORD *v8; // r4
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r0
  int v13; // r4
  int v14; // r5
  unsigned int *v15; // r2
  unsigned int v16; // r1
  unsigned int *v17; // r2
  unsigned int v18; // r0
  unsigned int v19; // r5
  int v20; // r1
  int *v21; // r0
  unsigned int v22; // r1
  unsigned int v23; // r1
  int v24; // [sp+10h] [bp-38h]
  int v25; // [sp+14h] [bp-34h]
  int v26; // [sp+18h] [bp-30h]
  int v27; // [sp+1Ch] [bp-2Ch] BYREF
  char v28[40]; // [sp+20h] [bp-28h] BYREF

  if ( (unsigned __int16)KeNumberNodes > 1u )
    return sub_96AB3C();
  v1 = ExpNumberOfPagedPools;
  if ( (unsigned int)ExpNumberOfPagedPools > 0x10 )
  {
    v1 = 16;
    ExpNumberOfPagedPools = 16;
  }
  if ( (unsigned __int16)KeNumberNodes > 1u )
  {
    v19 = 0;
    do
    {
      if ( v19 )
        v20 = v19 - 1;
      else
        v20 = 0;
      v21 = (int *)MmAllocateIndependentPages(0x1280u, v20);
      if ( !v21 )
        KeBugCheckEx(65, 4736, -1, -1, -1);
      ExpPagedPoolDescriptor[v19] = (int)v21;
      if ( !v19 )
        dword_6825F4 = (int)v21;
      ExInitializePoolDescriptor(v21, 1, v19++);
    }
    while ( v19 < ExpNumberOfPagedPools + 1 );
  }
  else
  {
    v2 = v1 + 1;
    v3 = ExAllocatePoolWithTag(512, 4736 * (v1 + 1), 1819242320);
    v4 = (int *)v3;
    if ( !v3 )
      KeBugCheckEx(65, 4736 * v2, -1, -1, -1);
    v5 = 0;
    dword_6825F4 = v3;
    if ( ExpNumberOfPagedPools != -1 )
    {
      v6 = ExpPagedPoolDescriptor;
      do
      {
        *v6++ = (int)v4;
        ExInitializePoolDescriptor(v4, 1, v5++);
        v4 += 1184;
      }
      while ( v5 < ExpNumberOfPagedPools + 1 );
    }
  }
  v7 = (28 * PoolTrackTableSize + 4095) & 0xFFFFF000;
  if ( PoolHitTag == 1819242320 )
    __debugbreak();
  if ( (dword_682604 & 0x41) != 0 )
    EtwTracePool(3616, 512, 1819242320, PoolTrackTable, (28 * PoolTrackTableSize + 4095) & 0xFFFFF000);
  v12 = PoolTrackTableSize;
  v13 = ExPoolTagTables[*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594)];
  v27 = PoolTrackTableSize;
  v24 = v13;
  v11 = PoolTrackTableMask;
  v25 = PoolTrackTableMask;
  v14 = PoolTrackTableMask & 0x2F53638;
  v10 = PoolTrackTableMask & 0x2F53638;
  v26 = PoolTrackTableMask & 0x2F53638;
  while ( 1 )
  {
    v8 = (_DWORD *)(v13 + 28 * v14);
    if ( *v8 == 1819242320 )
      break;
    if ( *v8 )
      goto LABEL_20;
    v9 = *(_DWORD *)(PoolTrackTable + 28 * v14);
    if ( v9 )
    {
      *v8 = v9;
      goto LABEL_19;
    }
    if ( v14 == v12 - 1 )
    {
LABEL_20:
      v14 = (v14 + 1) & v11;
      v13 = v24;
      if ( v14 == v10 )
      {
        ExpInsertPoolTrackerExpansion(1819242320, v7, 512);
        goto LABEL_42;
      }
    }
    else
    {
      KeAcquireInStackQueuedSpinLock((unsigned int *)&ExpTaggedPoolLock, (unsigned int)v28);
      if ( !*(_DWORD *)(PoolTrackTable + 28 * v14) )
      {
        *(_DWORD *)(PoolTrackTable + 28 * v14) = 1819242320;
        *v8 = 1819242320;
      }
      KeReleaseInStackQueuedSpinLock((int)v28);
      v11 = v25;
      v10 = v26;
      v12 = v27;
LABEL_19:
      v13 = v24;
    }
  }
  v15 = v8 + 1;
  do
    v16 = __ldrex(v15);
  while ( __strex(v16 + 1, v15) );
  v17 = v8 + 3;
  do
    v18 = __ldrex(v17);
  while ( __strex(v18 + v7, v17) );
LABEL_42:
  __dmb(0xBu);
  do
    v22 = __ldrex((unsigned int *)&ExpPoolFlags);
  while ( __strex(v22 | 0x100, (unsigned int *)&ExpPoolFlags) );
  __dmb(0xBu);
  KeInitializeTimerEx(ExpBootFinishedTimer, 0);
  ExpBootFinishedTimerDpc = 19;
  byte_61A5A1 = 1;
  word_61A5A2 = 0;
  dword_61A5AC = (int)ExpBootFinishedDispatch;
  dword_61A5B0 = 0;
  dword_61A5BC = 0;
  dword_61A5A8 = 0;
  result = KiSetTimerEx((int)ExpBootFinishedTimer, 0, -1200000000i64, 0, 0, (int)&ExpBootFinishedTimerDpc);
  if ( *(_DWORD *)(*(_DWORD *)dword_634340 + 3592) >= 0x1FC00u && !MmSpecialPoolTag )
  {
    result = MmIsVerifierEnabled(&v27);
    if ( result < 0 )
    {
      __dmb(0xBu);
      do
        v23 = __ldrex((unsigned int *)&ExpPoolFlags);
      while ( __strex(v23 | 0x200, (unsigned int *)&ExpPoolFlags) );
      __dmb(0xBu);
    }
  }
  return result;
}
