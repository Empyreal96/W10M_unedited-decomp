// PsIsCurrentThreadPrefetching 
 
int PsIsCurrentThreadPrefetching()
{
  return (unsigned __int8)(*(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C8) & 0x40) >> 6;
}
