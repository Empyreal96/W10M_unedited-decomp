// MmGetAvailablePages 
 
int MmGetAvailablePages()
{
  int result; // r0

  result = *(_DWORD *)(*(_DWORD *)dword_634340 + 3712);
  __dmb(0xBu);
  return result;
}
