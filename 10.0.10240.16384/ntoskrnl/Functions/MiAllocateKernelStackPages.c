// MiAllocateKernelStackPages 
 
int __fastcall MiAllocateKernelStackPages(unsigned int a1, int a2, int a3, __int16 a4)
{
  int v4; // r6
  unsigned int v5; // r4
  _DWORD *v6; // r5
  int v7; // r8
  _WORD *v8; // r10
  __int16 v9; // r2
  __int16 v10; // r3
  int v11; // r0
  _DWORD *v13; // r7
  int v14; // r5
  _DWORD *v15; // r8
  int v16; // r3
  int v17; // r6
  int v18; // r0
  unsigned int v19; // [sp+0h] [bp-38h]
  unsigned int v21; // [sp+8h] [bp-30h]
  _WORD *v22; // [sp+10h] [bp-28h] BYREF
  __int16 v23; // [sp+14h] [bp-24h]
  unsigned __int16 v24; // [sp+16h] [bp-22h]

  v4 = a2;
  v5 = a1;
  if ( a2 )
  {
    v19 = a1 + 4 * a2;
    v6 = 0;
    MI_INITIALIZE_COLOR_BASE(0, (unsigned __int16)(a4 + 1), &v22);
    v7 = v24;
    v8 = v22;
    do
    {
      v9 = v23;
      v10 = *v8 + 1;
      *v8 = v10;
      v11 = MiGetPage((int)MiSystemPartition, (unsigned __int16)(v10 & v9) | v7, 0);
      if ( v11 == -1 )
        return sub_53DB5C();
      --v4;
      v13 = (_DWORD *)(MmPfnDatabase + 24 * v11);
      *v13 = v6;
      v6 = v13;
    }
    while ( v4 );
    v21 = v5;
    LOWORD(v14) = (MiDetermineUserGlobalPteMask(v5) | dword_681120) & 0x1ED | 0xF012;
    v22 = (_WORD *)KfRaiseIrql(2);
    do
    {
      v15 = (_DWORD *)*v13;
      v14 = v14 & 0xFFF | ((((int)v13 - MmPfnDatabase) / 24) << 12);
      MiInitializePfn(v13, v5, 4, 20);
      if ( v5 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)v5 = v14;
      }
      else
      {
        v16 = *(_DWORD *)v5;
        v17 = 0;
        __dmb(0xBu);
        *(_DWORD *)v5 = v14;
        if ( (v16 & 2) == 0 && (v14 & 2) != 0 )
          v17 = 1;
        if ( v5 >= 0xC0300000 && v5 <= 0xC0300FFF )
        {
          v18 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v18, (_DWORD *)(v18 + 4 * (v5 & 0xFFF)), v14);
        }
        if ( v17 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
      }
      v5 += 4;
      v13 = v15;
    }
    while ( v5 < v19 );
    MiMarkKernelStack(v21, v19, a3);
    KfLowerIrql(v22);
  }
  return 1;
}
