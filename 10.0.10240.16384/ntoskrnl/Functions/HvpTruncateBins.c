// HvpTruncateBins 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall HvpTruncateBins(int a1)
{
  int i; // r6
  int v3; // r9
  unsigned int v4; // r4
  int v5; // r0
  unsigned int v7; // r8
  int v8; // r3
  unsigned int v9; // r10
  int v10; // r0
  int v11; // r0
  _DWORD *v12; // r1
  _DWORD *v13; // r5
  int v14; // r1 OVERLAPPED
  _DWORD *v15; // r2 OVERLAPPED
  int v16; // r0
  _BYTE *v17; // r0
  unsigned int v18; // r5
  int v19; // r4
  int v20; // r3
  int v21; // r3
  int v22; // r4
  int v23; // r2
  unsigned int v24; // r1
  unsigned int v25; // [sp+8h] [bp-20h]

  for ( i = 0; i < 2; ++i )
  {
    v3 = a1 + 412 * i;
    v4 = *(_DWORD *)(v3 + 952);
    if ( v4 )
    {
      v5 = HvpGetCellMap(a1, v4 + (i << 31) - 4096);
      if ( !v5 )
        KeBugCheckEx(81, 1, a1, v4 + (i << 31) - 4096, 5430);
      if ( HvpMapEntryGetFreeBin(v5) )
        return sub_7D3ED0();
    }
    if ( i || v4 + 0x10000 <= *(_DWORD *)(a1 + 1936) && ExIsResourceAcquiredExclusiveLite((int)&CmpRegistryLock) )
    {
      v7 = v4;
      v25 = *(_DWORD *)(v3 + 952);
      if ( v4 != v25 )
      {
        v8 = -i;
        do
        {
          v9 = v7;
          v10 = HvpGetCellMap(a1, v7 + (v8 << 31));
          if ( !v10 )
            KeBugCheckEx(81, 1, a1, v7 + (i << 31), 375);
          v11 = HvpMapEntryGetFreeBin(v10);
          v13 = (_DWORD *)v11;
          if ( v11 )
          {
            if ( (*(_DWORD *)(v11 + 16) & 1) != 0 )
              HvpFreeBin(a1, *(_DWORD *)(v11 + 8), i, v12[1] & 0xFFFFFFF0, v12[2] & 0xFFFFFFF0);
            else
              CmpReleaseGlobalQuota(*(_DWORD *)(v11 + 8));
            *(_QWORD *)&v14 = *(_QWORD *)v13;
            if ( *(_DWORD **)(*v13 + 4) != v13 || (_DWORD *)*v15 != v13 )
              __fastfail(3u);
            *v15 = v14;
            *(_DWORD *)(v14 + 4) = v15;
            v7 += v13[2];
            CmpFree(v13, 20);
          }
          else
          {
            v16 = v12[4];
            v7 += v16;
            if ( v16 )
              HvpFreeBin(a1, v16, i, v12[1] & 0xFFFFFFF0, v12[2] & 0xFFFFFFF0);
          }
          do
          {
            v17 = (_BYTE *)HvpGetCellMap(a1, v9 + (i << 31));
            if ( !v17 )
              KeBugCheckEx(81, 1, a1, v9 + (i << 31), 435);
            memset(v17, 0, 20);
            v9 += 4096;
          }
          while ( v9 < v7 );
          v8 = -i;
        }
        while ( v7 < v25 );
        HvpFreeMap(
          a1,
          *(_DWORD *)(v3 + 956),
          *(_DWORD *)(v3 + 952) + 1,
          (unsigned int)((*(_DWORD *)(v3 + 952) >> 12) - 1) >> 9);
        if ( !i )
          CmpUpdateSystemHiveHysteresis(a1, v4 & 0x7FFFFFFF, *(_DWORD *)(a1 + 952));
        *(_DWORD *)(v3 + 952) = v4 & 0x7FFFFFFF;
        if ( !i )
        {
          v18 = v4 >> 9;
          v19 = *(_DWORD *)(a1 + 36);
          RtlClearBits((_BYTE *)(a1 + 36), v18, v19 - v18);
          RtlClearBits((_BYTE *)(a1 + 52), v18, v19 - v18);
          v20 = *(_DWORD *)(a1 + 40);
          *(_DWORD *)(a1 + 36) = v18;
          *(_DWORD *)(a1 + 40) = v20;
          v21 = *(_DWORD *)(a1 + 56);
          *(_DWORD *)(a1 + 52) = v18;
          *(_DWORD *)(a1 + 56) = v21;
          v22 = *(_DWORD *)(a1 + 44);
          *(_DWORD *)(a1 + 44) = RtlNumberOfSetBits((unsigned int *)(a1 + 36));
          *(_DWORD *)(a1 + 60) = RtlNumberOfSetBits((unsigned int *)(a1 + 52));
          __dmb(0xBu);
          v23 = *(_DWORD *)(a1 + 44) - v22;
          do
            v24 = __ldrex((unsigned int *)&CmpDirtySectorCount);
          while ( __strex(v24 + v23, (unsigned int *)&CmpDirtySectorCount) );
          __dmb(0xBu);
        }
        HvpAdjustHiveFreeDisplay(a1, *(_DWORD *)(v3 + 952), i);
      }
    }
  }
  return 0;
}
