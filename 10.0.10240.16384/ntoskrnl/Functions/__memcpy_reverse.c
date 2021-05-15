// __memcpy_reverse 
 
int __fastcall _memcpy_reverse(int result, int a2, unsigned int a3)
{
  unsigned int v3; // r3
  char *v4; // r1
  char v5; // t1

  v3 = result + a3;
  v4 = (char *)(a2 + a3);
  __pld(v4);
  if ( a3 >= 8 )
  {
    if ( result + a3 )
      result = _memcpy_reverse_large_neon();
    else
      result = ((int (*)(void))*(&off_4236E4 + 2 * (byte_60E000 & 3)))();
  }
  else
  {
    for ( ; a3; --v3 )
    {
      --a3;
      v5 = *--v4;
      *(_BYTE *)(v3 - 1) = v5;
    }
  }
  return result;
}
