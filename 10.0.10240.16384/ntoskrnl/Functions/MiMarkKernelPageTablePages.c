// MiMarkKernelPageTablePages 
 
int MiMarkKernelPageTablePages()
{
  unsigned int v0; // r0
  unsigned int v1; // r1
  int v2; // r2
  unsigned int v3; // r0
  unsigned int v4; // r1
  int v5; // r2

  v0 = MmSystemRangeStart;
  if ( (unsigned int)MmSystemRangeStart < 0xC0000000 )
  {
    v1 = -1073741825;
    v2 = 2;
    do
    {
      v0 = ((v0 >> 10) & 0x3FFFFC) - 0x40000000;
      v1 = ((v1 >> 10) & 0x3FFFFC) - 0x40000000;
      --v2;
    }
    while ( v2 );
    MiMarkKernelPageTablesHelper(v0, v1, 2);
  }
  v3 = -1069547520;
  v4 = -1;
  v5 = 2;
  do
  {
    v3 = ((v3 >> 10) & 0x3FFFFC) - 0x40000000;
    v4 = ((v4 >> 10) & 0x3FFFFC) - 0x40000000;
    --v5;
  }
  while ( v5 );
  return MiMarkKernelPageTablesHelper(v3, v4, 2);
}
