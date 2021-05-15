// KeDetachProcess 
 
int KeDetachProcess()
{
  unsigned int v0; // r2
  int result; // r0

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_BYTE *)(v0 + 0x16A) )
    result = KiDetachProcess(v0 + 372, 0);
  return result;
}
