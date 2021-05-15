// MiZeroPhysicalPage 
 
int __fastcall MiZeroPhysicalPage(int a1, int a2, int a3, int a4)
{
  char v4; // r6
  unsigned int v6; // r5
  int v7; // r10
  int v8; // r3
  int result; // r0
  int v10; // r6
  int v11; // r4
  int v12; // r3
  unsigned int v13; // r2
  int v14; // r3
  int v15; // r4
  _DWORD *v16; // r4
  int v17; // r0
  int v18; // [sp+0h] [bp-28h] BYREF
  int v19; // [sp+4h] [bp-24h]
  int v20; // [sp+8h] [bp-20h]

  v18 = a2;
  v20 = a4;
  v19 = a3;
  v4 = a2;
  if ( (a2 & 1) != 0 && (v6 = MiReservePtes(&dword_634D58, 1u)) != 0 )
  {
    v7 = MmPfnDatabase + 24 * a1;
    if ( (v4 & 2) != 0 )
      goto LABEL_7;
    v8 = *(unsigned __int8 *)(v7 + 18) >> 6;
    if ( !v8 )
      return sub_50E310();
    if ( v8 != 2 || (MiFlags & 0x4000) == 0 || (MiChangePageAttribute(MmPfnDatabase + 24 * a1, 1, 0), v19 == 1) )
LABEL_7:
      v10 = 0;
    else
      v10 = 2;
    v11 = 4;
    v12 = *(unsigned __int8 *)(v7 + 18) >> 6;
    if ( v12 )
    {
      if ( v12 == 2 )
        v11 = 28;
    }
    else
    {
      v11 = 12;
    }
    v13 = (MiDetermineUserGlobalPteMask(v6) | MmProtectToPteMask[v11] & 0x1ED | (a1 << 12)) & 0xFFFFF1FF | 0x12;
    if ( v6 + 0x40000000 > 0x3FFFFF )
    {
      *(_DWORD *)v6 = v13;
    }
    else
    {
      v14 = *(_DWORD *)v6;
      v15 = 0;
      __dmb(0xBu);
      if ( (v14 & 2) == 0 )
        v15 = 1;
      *(_DWORD *)v6 = v13;
      if ( v6 >= 0xC0300000 && v6 <= 0xC0300FFF )
      {
        v17 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v17, (_DWORD *)(v17 + 4 * (v6 & 0xFFF)), v13);
      }
      if ( v15 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    KeZeroPages((_DWORD *)(v6 << 10), 0x1000u);
    result = MiReleasePtes(&dword_634D58, v6, 1);
    if ( v10 )
      result = MiChangePageAttribute(v7, 2, 0);
  }
  else
  {
    v16 = (_DWORD *)MiMapPageInHyperSpaceWorker(a1, (int)&v18, 0x80000000);
    KeZeroPages(v16, 0x1000u);
    result = MiUnmapPageInHyperSpaceWorker((int)v16, (unsigned __int8)v18, 0x80000000);
  }
  return result;
}
