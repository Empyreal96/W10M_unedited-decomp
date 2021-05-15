// MmEnoughMemoryForWrite 
 
int MmEnoughMemoryForWrite()
{
  unsigned int v0; // r2
  unsigned int v1; // r3
  int result; // r0

  if ( (_BYTE)dword_681280 )
    v0 = 0x4000;
  else
    v0 = 450;
  v1 = dword_640580;
  __dmb(0xBu);
  if ( v1 > v0 )
    result = 1;
  else
    result = sub_53D66C();
  return result;
}
