// HvpMarkDirty 
 
int __fastcall HvpMarkDirty(int a1, unsigned int a2, unsigned int a3)
{
  unsigned int v5; // r6
  unsigned int v6; // r7
  int v7; // r5
  int v8; // r4
  unsigned int v9; // r0
  unsigned int v10; // r5
  unsigned int v11; // r0
  unsigned int v12; // r3
  int v13; // r10
  unsigned int v14; // r1
  unsigned int v16; // r6
  int v17; // r4
  int v18; // r0
  unsigned int v19; // r1
  signed int v20; // r1
  __int64 v21; // r0
  unsigned int v22; // r7
  unsigned int v23; // r9
  int v24; // r3
  unsigned int v25; // r2
  unsigned __int64 v27[13]; // [sp+14h] [bp-68h] BYREF

  if ( (*(_DWORD *)(a1 + 92) & 1) != 0 || (a2 & 0x80000000) != 0 )
    return 1;
  v5 = *(_DWORD *)(a1 + 68);
  v6 = a2 + a3 - 1;
  if ( v5 <= 1 )
  {
    v9 = a2 >> 9;
    v8 = v6 >> 9;
  }
  else
  {
    v7 = ~(v5 - 1);
    v8 = ((v5 + (v6 >> 9)) & v7) - 1;
    v9 = v7 & (a2 >> 9);
  }
  v10 = (v9 + 8) & 0xFFFFFFF8;
  v11 = ((v8 + 16) & 0xFFFFFFF8) - 9;
  if ( v10 )
    v10 -= 8;
  v12 = *(_DWORD *)(a1 + 952) >> 9;
  if ( v11 >= v12 )
    v11 = v12 - 1;
  v13 = 0;
  v14 = v10;
  if ( v10 <= v11 )
  {
    do
    {
      if ( ((*(int *)(*(_DWORD *)(a1 + 40) + 4 * (v14 >> 5)) >> (v14 & 0x1F)) & 1) == 0 )
        ++v13;
      ++v14;
    }
    while ( v14 <= v11 );
    if ( v13 )
    {
      v16 = v11 - v10;
      if ( !HvpSetRangeProtection(a1, v10 << 9, (v11 - v10 + 1) << 9, 4) )
        return 0;
      v17 = *(_DWORD *)(a1 + 44);
      *(_DWORD *)(a1 + 44) = v17 + v13;
      RtlSetBits((_BYTE *)(a1 + 36), v10, v16 + 1);
      v18 = CmpLogDirtyVectorUse(a1, 0, a2, a3);
      if ( (dword_682608 & 0x1000000) != 0 )
        return sub_80439C(v18);
      if ( !v17 )
      {
        do
        {
          v21 = MEMORY[0xFFFF93B0];
          while ( 1 )
          {
            v22 = MEMORY[0xFFFF900C];
            __dmb(0xBu);
            v23 = MEMORY[0xFFFF9008];
            __dmb(0xBu);
            if ( v22 == MEMORY[0xFFFF9010] )
              break;
            __dmb(0xAu);
            __yield();
          }
        }
        while ( v21 != MEMORY[0xFFFF93B0] );
        *(_QWORD *)(a1 + 3240) = __PAIR64__(v22, v23) - v21;
        CmpIssueNewDirtyCallback();
      }
      __dmb(0xBu);
      do
      {
        v19 = __ldrex((unsigned int *)&CmpDirtySectorCount);
        v20 = v19 + v13;
      }
      while ( __strex(v20, (unsigned int *)&CmpDirtySectorCount) );
      __dmb(0xBu);
      if ( v20 >= 0x8000 && !CmpNoWrite )
      {
        if ( CmpWorkerDataInitialized )
        {
          v24 = CmpForceFlushPending;
          __dmb(0xBu);
          if ( !v24 )
          {
            __dmb(0xBu);
            do
              v25 = __ldrex((unsigned int *)&CmpForceFlushPending);
            while ( !v25 && __strex(1u, (unsigned int *)&CmpForceFlushPending) );
            __dmb(0xBu);
            if ( !v25 )
              ExQueueWorkItem(&CmpForceFlushWorkItem, 1);
          }
        }
      }
    }
  }
  if ( (*(_DWORD *)(a1 + 92) & 2) == 0 )
  {
    v27[0] = (unsigned int)CmpLazyFlushIntervalInSeconds * (unsigned __int64)(unsigned int)dword_989680
           + *(_QWORD *)(a1 + 3240);
    CmpArmLazyWriter(0, (__int64 *)v27, 0);
  }
  return 1;
}
