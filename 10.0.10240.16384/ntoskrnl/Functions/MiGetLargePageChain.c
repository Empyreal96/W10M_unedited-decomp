// MiGetLargePageChain 
 
_DWORD *__fastcall MiGetLargePageChain(int a1, unsigned int a2)
{
  _DWORD *v3; // r4
  unsigned int v4; // r5
  _DWORD *v6; // r0

  v3 = 0;
  v4 = 0;
  if ( a2 )
  {
    while ( 1 )
    {
      v6 = (_DWORD *)MiReplenishFromNodeLargePages(MiSystemPartition, 128, a1, 1);
      if ( !v6 )
        break;
      ++v4;
      *v6 = v3;
      v3 = v6;
      if ( v4 >= a2 )
        return v3;
    }
    MiFreeLargePageChain(v3);
    v3 = 0;
  }
  return v3;
}
