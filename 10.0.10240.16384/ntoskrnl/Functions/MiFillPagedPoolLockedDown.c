// MiFillPagedPoolLockedDown 
 
int __fastcall MiFillPagedPoolLockedDown(unsigned int a1, int a2, int a3, int a4)
{
  int v5; // r10
  unsigned int v6; // r7
  int v7; // r8
  int result; // r0
  __int16 v9; // r1
  int v10; // r5
  _WORD *v11; // r2
  __int16 v12; // r3
  int v13; // r4
  int v14; // r0
  int v15; // r9
  int v16; // r0
  int v17; // r4
  int v18; // r6
  int v19; // r5
  int v20; // r4
  int v21; // r3
  int v22; // r4
  _WORD *v23; // [sp+0h] [bp-28h] BYREF
  int v24; // [sp+4h] [bp-24h]
  int v25; // [sp+8h] [bp-20h]

  v23 = (_WORD *)a2;
  v24 = a3;
  v25 = a4;
  v5 = a2;
  v6 = a1;
  LOWORD(v7) = (MiDetermineUserGlobalPteMask(a1) | dword_681120) & 0x1ED | 0xF012;
  result = MI_INITIALIZE_COLOR_BASE(0, a3 + 1, (int)&v23);
  if ( v5 )
  {
    v9 = v24;
    v10 = HIWORD(v24);
    v11 = v23;
    do
    {
      v12 = *v11 + 1;
      *v11 = v12;
      v13 = (unsigned __int16)(v12 & v9);
      while ( 1 )
      {
        v14 = MiGetPage((int)MiSystemPartition, v13 | v10, 0);
        v15 = v14;
        if ( v14 != -1 )
          break;
        MiWaitForFreePage((int)MiSystemPartition);
      }
      v16 = MmPfnDatabase + 24 * v14;
      *(_DWORD *)(v16 + 8) = 128;
      v17 = *(_DWORD *)(((v6 >> 10) & 0x3FFFFC) - 0x40000000) >> 12;
      *(_DWORD *)(v16 + 20) = v17 | *(_DWORD *)(v16 + 20) & 0xF7F00000;
      MiSetPfnOwnedAndActive(v16, v6, 1, 1);
      v18 = 3 * v17;
      v19 = MmPfnDatabase;
      v20 = MiLockPage(MmPfnDatabase + 24 * v17);
      MiUpdateShareCount(v19 + 8 * v18, 1);
      result = MiUnlockPage(v19 + 8 * v18, v20);
      v7 = v7 & 0xFFF | (v15 << 12);
      if ( v6 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)v6 = v7;
      }
      else
      {
        v21 = *(_DWORD *)v6;
        v22 = 0;
        __dmb(0xBu);
        *(_DWORD *)v6 = v7;
        if ( (v21 & 2) == 0 && (v7 & 2) != 0 )
          v22 = 1;
        if ( v6 + 1070596096 <= 0xFFF )
          result = MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v7, v6);
        if ( v22 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
      }
      v10 = HIWORD(v24);
      v11 = v23;
      v9 = v24;
      v6 += 4;
      --v5;
    }
    while ( v5 );
  }
  return result;
}
