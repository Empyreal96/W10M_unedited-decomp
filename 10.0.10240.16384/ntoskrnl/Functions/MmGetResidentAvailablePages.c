// MmGetResidentAvailablePages 
 
int MmGetResidentAvailablePages()
{
  int result; // r0

  result = *(_DWORD *)(*(_DWORD *)dword_634340 + 3840);
  __dmb(0xBu);
  return result;
}
