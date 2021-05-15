// MmAllocateIndependentPages 
 
int __fastcall MmAllocateIndependentPages(unsigned int a1, int a2)
{
  int v3; // r5
  unsigned int v4; // r4
  int v6; // r6
  __int16 v7; // r1
  int v8; // r10
  _WORD *v9; // r2
  unsigned int v10; // r9
  __int16 v11; // r3
  int v12; // r8
  int v13; // r0
  int v14; // r3
  int v15; // r8
  unsigned int v16; // [sp+0h] [bp-30h]
  _WORD *v17; // [sp+8h] [bp-28h] BYREF
  __int16 v18; // [sp+Ch] [bp-24h]
  unsigned __int16 v19; // [sp+Eh] [bp-22h]

  v3 = ((a1 & 0xFFF) != 0) + (a1 >> 12);
  v4 = MiReservePtes(&dword_634D58, v3);
  if ( !v4 )
    JUMPOUT(0x7D09BA);
  if ( !MiObtainNonPagedPoolCharges(v3) )
    return sub_7D09B0();
  v16 = v4 << 10;
  LOWORD(v6) = (MiDetermineUserGlobalPteMask(v4) | dword_681120) & 0x1ED | 0xF012;
  MI_INITIALIZE_COLOR_BASE(0, a2 + 1, (int)&v17);
  v7 = v18;
  v8 = v19;
  v9 = v17;
  v10 = v4 + 0x40000000;
  do
  {
    v11 = *v9 + 1;
    *v9 = v11;
    v12 = (unsigned __int16)(v11 & v7);
    while ( 1 )
    {
      v13 = MiGetPage((int)MiSystemPartition, v12 | v8, 8);
      if ( v13 != -1 )
        break;
      MiWaitForFreePage((int)MiSystemPartition);
    }
    v6 = v6 & 0xFFF | (v13 << 12);
    MiInitializePfn(MmPfnDatabase + 24 * v13, (int *)v4, 4u, 4);
    if ( v10 > 0x3FFFFF )
    {
      *(_DWORD *)v4 = v6;
    }
    else
    {
      v14 = *(_DWORD *)v4;
      v15 = 0;
      __dmb(0xBu);
      *(_DWORD *)v4 = v6;
      if ( (v14 & 2) == 0 && (v6 & 2) != 0 )
        v15 = 1;
      if ( v4 >= 0xC0300000 && v4 <= 0xC0300FFF )
        MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v6, v4);
      if ( v15 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    v9 = v17;
    v7 = v18;
    v4 += 4;
    --v3;
    v10 += 4;
  }
  while ( v3 );
  return v16;
}
