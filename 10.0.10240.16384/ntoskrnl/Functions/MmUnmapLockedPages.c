// MmUnmapLockedPages 
 
_DWORD *__fastcall MmUnmapLockedPages(unsigned int a1, int a2, int a3)
{
  unsigned int v6; // r7
  int v7; // r5
  int v8; // r2

  if ( (*(_WORD *)(a2 + 6) & 0x200) != 0 )
    return (_DWORD *)sub_542680(0);
  if ( a1 <= MmHighestUserAddress )
    return MiUnmapLockedPagesInUserSpace(a1, (_DWORD *)a2, a3, MmHighestUserAddress);
  v6 = ((((unsigned __int16)*(_DWORD *)(a2 + 24) + (unsigned __int16)*(_DWORD *)(a2 + 16)) & 0xFFFu)
      + *(_DWORD *)(a2 + 20)
      + 4095) >> 12;
  v7 = (a1 >> 10) & 0x3FFFFC;
  *(_WORD *)(a2 + 6) &= 0xFFDEu;
  v8 = *(_DWORD *)(((a1 >> 20) & 0xFFC) - 1070596096);
  if ( (v8 & 0x400) == 0 )
    v8 = *(_DWORD *)(v7 - 0x40000000);
  if ( (v8 & 0x100) != 0 )
    MiZeroAndFlushPtes(a1, v6);
  if ( MmProtectFreedNonPagedPool == 1 )
    ++v6;
  if ( (dword_681258 & 1) != 0 )
    MiRemovePteTracker(a2, a1, v6);
  return (_DWORD *)MiReleasePtes(&dword_634D58, v7 - 0x40000000, v6);
}
