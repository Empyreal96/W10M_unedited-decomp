// RtlSetBits 
 
_BYTE *__fastcall RtlSetBits(_BYTE *result, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // r4
  int v4; // r2
  _BYTE *v5; // r5
  int v6; // r2

  v3 = a3;
  if ( a3 )
  {
    v4 = a2 & 7;
    v5 = (_BYTE *)(*((_DWORD *)result + 1) + (a2 >> 3));
    if ( v4 + v3 <= 8 )
    {
      v6 = *((unsigned __int8 *)dword_409D88 + v3) << v4;
LABEL_4:
      *v5 |= v6;
      return result;
    }
    if ( v4 )
    {
      v3 = v4 + v3 - 8;
      *v5++ |= *((_BYTE *)dword_409D94 + v4);
    }
    if ( v3 > 8 )
    {
      result = memset(v5, 255, v3 >> 3);
      v5 += v3 >> 3;
      v3 &= 7u;
    }
    if ( v3 )
    {
      LOBYTE(v6) = *((_BYTE *)dword_409D88 + v3);
      goto LABEL_4;
    }
  }
  return result;
}
