// MiEmptyKernelStackCache 
 
void MiEmptyKernelStackCache()
{
  unsigned int v0; // r6
  int v1; // r4
  int v2; // r5
  int v3; // r7
  int v4; // r10
  int v5; // r0

  if ( (MiFlags & 0x800) != 0 )
  {
    v0 = 0;
    if ( KeNumberNodes )
    {
      v1 = 0;
      do
      {
        v2 = 0;
        v3 = v1;
        do
        {
          v4 = v3 + dword_6337E8;
          while ( 1 )
          {
            v5 = RtlpInterlockedPopEntrySList((unsigned __int64 *)(v4 + 56));
            if ( !v5 )
              break;
            if ( *(_DWORD *)(v5 - 8) != (dword_634C80 ^ (v5 - 4088)) )
              sub_55569C();
            MiDeleteKernelStack((((unsigned int)(v5 - 4088) >> 10) & 0x3FFFFC) - 0x40000000, 0);
          }
          ++v2;
          v3 += 24;
        }
        while ( v2 < 2 );
        ++v0;
        v1 += 176;
      }
      while ( v0 < (unsigned __int16)KeNumberNodes );
    }
    MiDeleteNoBlockStacks(1);
  }
}
