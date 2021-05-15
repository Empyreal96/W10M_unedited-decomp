// wcslen 
 
unsigned int __fastcall wcslen(unsigned __int16 *a1)
{
  unsigned __int16 *v1; // r1
  int v5; // t1

  v1 = a1 + 1;
  if ( ((unsigned __int8)a1 & 3) != 0 )
  {
    while ( *a1++ )
    {
      if ( ((unsigned __int8)a1 & 3) == 0 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    _R3 = 65537;
    do
    {
      v5 = *(_DWORD *)a1;
      a1 += 2;
      _R2 = v5;
      __asm { UQSUB16.W       R2, R3, R2 }
    }
    while ( !_R2 );
    a1 = (unsigned __int16 *)((char *)a1 + (__clz(bswap32(_R2)) >> 3));
    ++v1;
  }
  return (unsigned int)((char *)a1 - (char *)v1) >> 1;
}
