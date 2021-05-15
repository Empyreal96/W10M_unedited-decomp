// HvpFillFileName 
 
_BYTE *__fastcall HvpFillFileName(int a1, unsigned __int16 *a2)
{
  _BYTE *result; // r0
  unsigned int v5; // r2
  unsigned int v6; // r4

  result = memset((_BYTE *)(a1 + 48), 0, 64);
  if ( a2 )
  {
    v5 = *a2;
    if ( v5 < 0x40 )
    {
      v6 = 0;
    }
    else
    {
      v6 = v5 - 62;
      v5 = 62;
    }
    result = (_BYTE *)memmove(a1 + 48, *((_DWORD *)a2 + 1) + v6, v5);
  }
  return result;
}
