// MiAllocateHardwarePageDirectories 
 
int MiAllocateHardwarePageDirectories()
{
  int v0; // r0
  unsigned int v1; // r4
  int *v2; // r10
  int v3; // r7
  unsigned int v4; // r9
  unsigned int i; // r6
  int v6; // r0
  int *v7; // r5
  __int16 v8; // r0
  int v9; // r1
  int v10; // r8
  unsigned int v11; // r2
  int v12; // t1
  int v13; // r3
  int v14; // r10
  unsigned int v15; // r5
  int v17; // r3
  int v18; // r1
  int v19; // r2
  int *v20; // [sp+18h] [bp-30h]
  _DWORD *v21; // [sp+1Ch] [bp-2Ch]
  int v22; // [sp+20h] [bp-28h]
  int *v23; // [sp+24h] [bp-24h]
  int v24; // [sp+28h] [bp-20h]

  v0 = MmAllocatePagesForMdlEx(0, 0, -1, -1, 0x4000, 0, 0x20000, 1, 49);
  v1 = v0;
  v24 = v0;
  if ( !v0 )
    return sub_7BFC10();
  v2 = (int *)(v0 + 28);
  v3 = 1;
  v4 = *(_DWORD *)(v0 + 20) >> 12;
  v23 = (int *)(v0 + 28);
  for ( i = 0; i < v4; v23 = v2 )
  {
    v6 = MiReservePtes(&dword_634D58, 4u);
    v7 = (int *)v6;
    if ( !v6 )
      break;
    v8 = MiDetermineUserGlobalPteMask(v6);
    v9 = 4;
    v22 = 4;
    LOWORD(v10) = (dword_681120 | v8) & 0x1ED | 0xF012;
    v11 = (unsigned int)(v7 + 0x10000000);
    v21 = v7 + 0x10000000;
    do
    {
      v12 = *v2++;
      v10 = v10 & 0xFFF | (v12 << 12);
      v20 = v2;
      if ( v11 > 0x3FFFFF )
      {
        *v7 = v10;
      }
      else
      {
        v13 = *v7;
        v14 = 0;
        __dmb(0xBu);
        *v7 = v10;
        if ( (v13 & 2) == 0 && (v10 & 2) != 0 )
          v14 = 1;
        if ( (unsigned int)v7 >= 0xC0300000 && (unsigned int)v7 <= 0xC0300FFF )
        {
          MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v10, (__int16)v7);
          v11 = (unsigned int)v21;
          v9 = v22;
        }
        if ( v14 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
        v2 = v20;
      }
      ++v7;
      v11 += 4;
      --v9;
      v21 = (_DWORD *)v11;
      v22 = v9;
    }
    while ( v9 );
    v1 = v24;
    v3 = 1;
    v15 = (unsigned int)(v7 - 4);
    if ( (unsigned __int16)word_620D24 >= 8u )
    {
      MiReleasePtes(&dword_634D58, v15, 4u);
      v2 = v23;
      break;
    }
    RtlpInterlockedPushEntrySList((unsigned __int64 *)&MiArmPageDirectorySlist, (_DWORD *)(v15 << 10));
    i += 4;
  }
  if ( i != v4 )
  {
    memmove(v1 + 28, (int)v2, 4 * (v4 - i));
    v17 = *(_DWORD *)(v1 + 20) - (i << 12);
    *(_DWORD *)(v1 + 20) = v17;
    MmFreePagesFromMdl(v1, v18, v19, v17);
    if ( !i )
      v3 = 0;
  }
  ExFreePoolWithTag(v1);
  return v3;
}
