// IopConstructInMemoryDumpHeader 
 
int IopConstructInMemoryDumpHeader()
{
  unsigned int v0; // r2
  unsigned int *v1; // r6
  unsigned int *v2; // r5
  int result; // r0
  unsigned int v4; // r1
  unsigned int v5; // r2

  __dmb(0xBu);
  do
    v0 = __ldrex((unsigned int *)&InMemData);
  while ( __strex(1u, (unsigned int *)&InMemData) );
  __dmb(0xBu);
  if ( v0 != 1 )
  {
    dword_632A28 = 0;
    if ( dword_632A04
      && (v1 = (unsigned int *)*((_DWORD *)&InMemData + (dword_632A14 & 1) + 2)) != 0
      && (v2 = (unsigned int *)*((_DWORD *)&InMemData + ((dword_632A14 - 1) & 1) + 2)) != 0 )
    {
      __mrc(15, 0, 13, 0, 3);
      result = IoFillDumpHeader(v2 + 6, 1, 332);
      v2[526] = dword_632A18;
      v2[527] = dword_632A1C;
      v2[10] = *(_DWORD *)(PsInitialSystemProcess + 24);
      __dmb(0xBu);
      do
        v4 = __ldrex(v2);
      while ( __strex(0x5353493Bu, v2) );
      __dmb(0xBu);
      *v1 = v4;
      ++dword_632A14;
    }
    else
    {
      dword_632A28 = -1073741823;
    }
    __dmb(0xBu);
    do
      v5 = __ldrex((unsigned int *)&InMemData);
    while ( __strex(0, (unsigned int *)&InMemData) );
    __dmb(0xBu);
  }
  return result;
}
