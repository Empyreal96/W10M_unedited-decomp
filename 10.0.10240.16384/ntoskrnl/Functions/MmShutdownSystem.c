// MmShutdownSystem 
 
int __fastcall MmShutdownSystem(int a1)
{
  __int16 *v2; // r4
  int v3; // r5
  int v4; // r2

  if ( !a1 )
    return MiShutdownSystem();
  if ( a1 == 1 )
  {
    if ( (unsigned int)dword_634350 < 2 )
    {
      dword_634350 = 2;
      if ( (PopShutdownCleanly & 2) != 0 )
      {
        MmTrimAllSystemPagableMemory(1);
        v2 = MiSystemPartition;
        v3 = dword_64050C;
        __dmb(0xBu);
        for ( ; v3; --v3 )
        {
          v4 = *((_DWORD *)v2 + 900);
          if ( (*(_WORD *)(v4 + 96) & 0x40) == 0 )
            ObfDereferenceObject(*(_DWORD *)(v4 + 32));
          v2 += 2;
        }
      }
    }
  }
  else if ( (unsigned int)dword_634350 < 3 )
  {
    dword_634350 = 3;
  }
  return 1;
}
