// ExSystemExceptionFilter 
 
BOOL ExSystemExceptionFilter()
{
  return *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) != 0;
}
