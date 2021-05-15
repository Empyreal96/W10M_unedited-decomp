// MmMdlPagesAreZero 
 
int __fastcall MmMdlPagesAreZero(int a1)
{
  int *v1; // r1
  unsigned int v2; // r4
  int v3; // r2
  int v4; // t1

  if ( (*(_WORD *)(a1 + 6) & 0x4002) == 16386 )
  {
    v1 = (int *)(a1 + 28);
    v2 = (*(_DWORD *)(a1 + 20)
        + (((unsigned __int16)*(_DWORD *)(a1 + 24) + (unsigned __int16)*(_DWORD *)(a1 + 16)) & 0xFFFu)
        + 4095) >> 12;
    v3 = 0;
    if ( !v2 )
      return 1;
    while ( 1 )
    {
      v4 = *v1++;
      if ( v4 != dword_634900 )
        break;
      if ( ++v3 >= v2 )
        return 1;
    }
  }
  return 0;
}
