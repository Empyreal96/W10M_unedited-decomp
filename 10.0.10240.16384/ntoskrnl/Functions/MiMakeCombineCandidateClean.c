// MiMakeCombineCandidateClean 
 
_DWORD *__fastcall MiMakeCombineCandidateClean(unsigned int a1, int a2)
{
  int v4; // r1
  int v5; // r8
  int v6; // r5
  int v7; // r9
  _DWORD *result; // r0
  int v9; // r0

  v4 = *(_DWORD *)a1;
  v5 = 3 * (*(_DWORD *)a1 >> 12);
  v6 = *(_DWORD *)a1 | 0x200;
  v7 = MmPfnDatabase;
  if ( (*(_BYTE *)a1 & 0x10) == 0 )
    v6 = *(_DWORD *)a1 | 0x210;
  if ( a1 + 0x40000000 > 0x3FFFFF )
  {
    *(_DWORD *)a1 = v6;
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)a1 = v6;
    if ( (v4 & 2) == 0 )
      return (_DWORD *)sub_54F104();
    if ( a1 >= 0xC0300000 && a1 <= 0xC0300FFF )
    {
      v9 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v9, (_DWORD *)(v9 + 4 * (a1 & 0xFFF)), v6);
    }
  }
  result = (_DWORD *)MiLockPageAndSetDirty(v7 + 8 * v5, 1);
  if ( a2 )
  {
    if ( (*(_DWORD *)(a2 + 28) & 7) == 4 )
      result = MiCaptureWriteWatchDirtyBit(*(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), a1 << 10, a2);
  }
  return result;
}
