// KeBugCheckUnicodeToAnsi 
 
_BYTE *__fastcall KeBugCheckUnicodeToAnsi(unsigned __int16 *a1, _BYTE *a2, unsigned int a3)
{
  unsigned int v3; // r3
  __int16 *v4; // r0
  unsigned int v5; // r4
  _BYTE *i; // r2
  __int16 v7; // t1

  v3 = *a1;
  v4 = (__int16 *)*((_DWORD *)a1 + 1);
  v5 = v3 >> 1;
  if ( v3 >> 1 >= a3 )
    v5 = a3 - 1;
  for ( i = a2; v5; ++i )
  {
    v7 = *v4++;
    --v5;
    *i = v7;
  }
  *i = 0;
  return a2;
}
