// MmGetTotalCommittedPages 
 
int MmGetTotalCommittedPages()
{
  int result; // r0

  result = *(_DWORD *)(*(_DWORD *)dword_634340 + 3844);
  __dmb(0xBu);
  return result;
}
