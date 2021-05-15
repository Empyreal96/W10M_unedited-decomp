// MmCanThreadFault 
 
BOOL MmCanThreadFault()
{
  BOOL v0; // r0
  unsigned int v1; // r0
  unsigned int v2; // r2
  BOOL result; // r0

  v0 = KeAreInterruptsEnabled();
  if ( v0 )
    v1 = KeGetCurrentIrql(v0);
  else
    v1 = 15;
  result = 0;
  if ( v1 < 2 )
  {
    v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( (*(_DWORD *)(v2 + 0x3C4) & 2) == 0
      && MmPhysicalMemoryBlock
      && dword_6404B8
      && v2 != *(_DWORD *)(dword_6404B8 + 68) )
    {
      result = 1;
    }
  }
  return result;
}
