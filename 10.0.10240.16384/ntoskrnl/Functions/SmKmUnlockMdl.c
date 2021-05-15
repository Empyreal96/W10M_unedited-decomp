// SmKmUnlockMdl 
 
_DWORD *__fastcall SmKmUnlockMdl(unsigned int a1, int a2, int a3)
{
  if ( (*(_WORD *)(a1 + 6) & 1) != 0 )
  {
    if ( a2 )
      SmFpFree(a2, 4, a3, a1);
    else
      MmUnmapLockedPages(*(_DWORD *)(a1 + 12), a1, a3);
  }
  return MiUnlockStoreLockedPages((_DWORD *)a1);
}
