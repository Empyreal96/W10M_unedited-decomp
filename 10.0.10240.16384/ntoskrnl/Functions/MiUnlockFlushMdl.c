// MiUnlockFlushMdl 
 
int __fastcall MiUnlockFlushMdl(int a1, int a2, int a3)
{
  int result; // r0

  if ( (*(_WORD *)(a1 + 6) & 0x200) != 0 )
    return sub_522B88();
  if ( (*(_WORD *)(a1 + 6) & 1) != 0 )
    MmUnmapLockedPages(*(_DWORD *)(a1 + 12), a1);
  MiUnlockMdlWritePages(
    a1 + 28,
    a1
  + 28
  + 4
  * ((*(_DWORD *)(a1 + 20)
    + (((unsigned __int16)*(_DWORD *)(a1 + 24) + (unsigned __int16)*(_DWORD *)(a1 + 16)) & 0xFFFu)
    + 4095) >> 12),
    a3);
  result = MiDecrementModifiedWriteCount(a2, 0);
  if ( result )
    result = MiReleaseControlAreaWaiters(result);
  return result;
}
