// RtlpValidateAsciiStd3AndLength 
 
int __fastcall RtlpValidateAsciiStd3AndLength(unsigned int a1, int a2, int a3, int a4)
{
  char *v5; // r6
  unsigned int v6; // r4
  int v7; // lr
  int v8; // r8
  int v9; // r5
  char *v10; // r9
  unsigned int v11; // r10
  char *i; // r2
  int v14; // r3

  v5 = (char *)(a1 - 2);
  v6 = 46;
  v7 = a4;
  v8 = a3;
  v9 = a2;
  v10 = (char *)(a1 + 2 * a2);
  if ( a3 )
  {
    v7 = a4;
    v11 = a1 + 2 * FindEmailAt(a1, a2);
  }
  else
  {
    v11 = a1 - 2;
  }
  if ( (char *)v11 == v10 || v9 <= 0 )
    return 0;
  for ( i = (char *)a1; i != v10; i += 2 )
  {
    v6 = *(unsigned __int16 *)i;
    if ( v6 >= 0x7F )
      return 0;
    if ( v8 )
      v14 = 64;
    else
      v14 = 46;
    if ( v6 == v14 )
    {
      if ( v8 )
      {
        if ( i == (char *)a1 )
          return 0;
        if ( i == (char *)(v11 - 2) )
          v8 = 0;
      }
      else if ( i == v5 + 2
             || (int)((i - v5) & 0xFFFFFFFE) > 128
             || v7 && (unsigned int)i > a1 && *((_WORD *)i - 1) == 45 )
      {
        return 0;
      }
      v5 = i;
    }
    else if ( v8 )
    {
      if ( !*(_WORD *)i )
        return 0;
    }
    else
    {
      if ( v7 )
      {
        if ( v6 == 45 && i == v5 + 2 || !ValidateStd3Range(*(unsigned __int16 *)i) )
          return 0;
        v7 = a4;
      }
      if ( v6 < 0x20 )
        return 0;
    }
  }
  if ( !v8 )
  {
    if ( (int)((v10 - v5) & 0xFFFFFFFE) > 128 )
      return 0;
    if ( v6 == 46 )
      a2 = 1;
    if ( v6 != 46 )
      a2 = 0;
    if ( (int)&v10[-v11] >> 1 > a2 + 255 || v7 && v6 == 45 )
      return 0;
  }
  return 1;
}
