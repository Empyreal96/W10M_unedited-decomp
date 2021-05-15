// MiRemoveEntryWsle 
 
_DWORD *__fastcall MiRemoveEntryWsle(_DWORD *result, int a2)
{
  int v2; // r6
  __int64 v3; // kr00_8
  unsigned int v4; // r1
  int v5; // r2
  _DWORD *v6; // r1

  if ( result[9] == 16 )
  {
    v2 = result[63];
    if ( (unsigned int)((a2 - v2) >> 4) >= result[1] )
    {
      v3 = *(_QWORD *)(a2 + 4);
      v4 = *(_DWORD *)a2;
      v5 = 2 * ((v4 >> 9) & 7);
      if ( v4 < 0xC0000000 || v4 > 0xC03FFFFF )
        ++v5;
      v6 = &result[2 * v5];
      if ( HIDWORD(v3) == 0xFFFFF )
      {
        v6[31] = v3;
        if ( (_DWORD)v3 == 0xFFFFF )
          v6[32] = 0xFFFFF;
        else
          *(_DWORD *)(v2 + 16 * v3 + 8) = 0xFFFFF;
        --result[v5 + 15];
      }
      else
      {
        result = (_DWORD *)sub_51A2D0(result, v6);
      }
    }
  }
  return result;
}
