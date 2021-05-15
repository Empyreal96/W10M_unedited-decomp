// strlen 
 
char *__fastcall strlen(unsigned int a1)
{
  unsigned int v1; // r1
  int v5; // t1

  v1 = ~a1;
  if ( (a1 & 3) != 0 )
  {
    while ( *(unsigned __int8 *)a1++ )
    {
      if ( (a1 & 3) == 0 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    _R3 = 16843009;
    do
    {
      v5 = *(_DWORD *)a1;
      a1 += 4;
      _R2 = v5;
      __asm { UQSUB8.W        R2, R3, R2 }
    }
    while ( !_R2 );
    a1 += __clz(bswap32(_R2)) >> 3;
    v1 -= 3;
  }
  return (char *)(a1 + v1);
}
