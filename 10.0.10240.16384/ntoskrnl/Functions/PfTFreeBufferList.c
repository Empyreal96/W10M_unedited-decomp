// PfTFreeBufferList 
 
_BYTE *__fastcall PfTFreeBufferList(_BYTE *result)
{
  _BYTE *v1; // r5
  unsigned int v2; // r7
  _DWORD *v3; // r6
  __int64 *v4; // r4
  __int64 v5; // kr00_8

  v1 = result;
  v2 = *(_DWORD *)result;
  v3 = result + 16;
  while ( *v3 != v3[1] )
  {
    v4 = (__int64 *)v3[1];
    v5 = *v4;
    if ( *(_DWORD **)v4 != v3 || *(__int64 **)HIDWORD(v5) != v4 )
      __fastfail(3u);
    v3[1] = HIDWORD(v5);
    *(_DWORD *)HIDWORD(v5) = v3;
    if ( (*(_DWORD *)v1 & 0xF) != 0 )
    {
      result = memset(v4, 0, v2 >> 4);
      *(_DWORD *)v4 = v4;
      *((_DWORD *)v4 + 1) = v4;
      *((_DWORD *)v4 + 6) = 2048;
    }
    else
    {
      result = (_BYTE *)PfTLbInitialize(v4, v2 >> 4, 1);
    }
    *(_DWORD *)v4 = *((_DWORD *)v1 + 3);
    *((_DWORD *)v1 + 3) = v4;
    ++*((_WORD *)v1 + 5);
  }
  if ( (*(_DWORD *)v1 & 0xF) == 0 )
    result = (_BYTE *)PfTLbInitialize(*((_DWORD *)v1 + 4), v2 >> 4, 1);
  return result;
}
