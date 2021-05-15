// MiInitializeRelocations 
 
int MiInitializeRelocations()
{
  int v0; // r0

  v0 = ExAllocatePoolWithTag(1, 1280, 1767009613);
  if ( !v0 )
    return 0;
  dword_632EC8 = 10240;
  dword_632ECC = v0;
  RtlClearAllBits((int)&dword_632EC8);
  dword_632EC0 = (unsigned __int8)ExGenRandom(1);
  return 1;
}
