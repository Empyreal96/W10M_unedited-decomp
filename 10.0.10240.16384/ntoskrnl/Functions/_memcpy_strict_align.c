// _memcpy_strict_align 
 
void __fastcall memcpy_strict_align(int result, char *a2, unsigned int a3)
{
  _BYTE *v3; // r3
  char v4; // t1

  __pld(a2);
  if ( a3 >= 8 )
  {
    if ( (((unsigned __int8)result ^ (unsigned __int8)a2) & 3) != 0 )
      _memcpy_forward_large_neon(result, (__int64 *)a2, a3, result);
    else
      ((void (*)(void))*(&off_4236E0 + 2 * (byte_60E000 & 3)))();
  }
  else if ( a3 )
  {
    v3 = (_BYTE *)result;
    do
    {
      --a3;
      v4 = *a2++;
      *v3++ = v4;
    }
    while ( a3 );
  }
}
