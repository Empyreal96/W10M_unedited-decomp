// MiRevertValidPte 
 
int __fastcall MiRevertValidPte(int a1, unsigned int a2, unsigned int a3, unsigned int a4, int a5)
{
  int v6; // r6
  unsigned int v8; // r8
  int v9; // r1
  int result; // r0
  unsigned int v12; // r9
  int v13; // r7
  int v14; // r4
  int v15; // r0

  v6 = *(_DWORD *)a2;
  v8 = a3;
  v9 = (*(_DWORD *)a2 >> 2) & 3;
  if ( v9 == 3 )
  {
    if ( (a3 & 0x18) != 24 )
      v8 = a3 | 0x18;
  }
  else
  {
    if ( v9 == 1 )
      return sub_543418();
    if ( (a3 & 0x18) != 0 )
      v8 = a3 & 0xFFFFFFE7;
  }
  v12 = (MmProtectToPteMask[v8] | (a4 << 12)) & 0xFFFFFBFF | 0x832;
  if ( MI_IS_PFN(a4) )
  {
    v13 = MmPfnDatabase + 24 * a4;
  }
  else
  {
    v13 = 0;
    if ( (v8 & 4) != 0 )
      v12 &= 0xFFFFFDFF;
  }
  if ( a2 + 0x40000000 > 0x3FFFFF )
  {
    *(_DWORD *)a2 = v12;
  }
  else
  {
    v14 = 0;
    __dmb(0xBu);
    *(_DWORD *)a2 = v12;
    if ( (v6 & 2) == 0 && (v12 & 2) != 0 )
      v14 = 1;
    if ( a2 >= 0xC0300000 && a2 <= 0xC0300FFF )
    {
      v15 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v15, (_DWORD *)(v15 + 4 * (a2 & 0xFFF)), v12);
    }
    if ( v14 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  result = MiInsertTbFlushEntry(a5, a2 << 10, 1, 0);
  if ( (v6 & 0x200) == 0 )
  {
    if ( v13 )
    {
      if ( (*(_DWORD *)(a1 + 28) & 7) != 6 || (result = MiRotatedToFrameBuffer(a2)) != 0 )
        result = MiLockPageAndSetDirty(v13, 1);
    }
    if ( (*(_DWORD *)(a1 + 28) & 7) == 4 )
      result = (int)MiCaptureWriteWatchDirtyBit(
                      *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74),
                      a2 << 10,
                      a1);
  }
  return result;
}
