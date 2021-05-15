// MiImageUnused 
 
_DWORD *__fastcall MiImageUnused(_DWORD *result, int a2, int a3)
{
  _DWORD *v4; // r3
  int v5; // r3
  unsigned int v6; // r2
  int v7; // r3

  *(_DWORD *)a3 = 0;
  *(_DWORD *)(a3 + 4) = 0;
  *(_DWORD *)(a3 + 8) = 0;
  *(_DWORD *)(a3 + 12) = 0;
  v4 = (_DWORD *)result[14];
  *(_DWORD *)a3 = -1;
  if ( *v4 )
  {
    if ( a2 == 1 )
    {
      v5 = result[12];
      if ( v5 != -1 )
      {
        v6 = result[13];
        *(_DWORD *)a3 = v5;
        *(_DWORD *)(a3 + 4) = (unsigned __int16)v6;
        *(_DWORD *)(a3 + 8) = (v6 >> 29) & 3;
        v7 = result[7];
        if ( (v7 & 0x10000000) != 0 )
        {
          result[7] = v7 & 0xEFFFFFFF;
          *(_BYTE *)(a3 + 13) = (v6 & 0x2000000) != 0;
          *(_BYTE *)(a3 + 12) = 1;
        }
        result[12] = -1;
      }
      result[13] &= 0x7FFFFFFFu;
    }
    else
    {
      result = (_DWORD *)sub_52496C();
    }
  }
  return result;
}
