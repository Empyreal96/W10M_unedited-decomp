// WheapCompressErrorRecord 
 
_BYTE *__fastcall WheapCompressErrorRecord(char a1, int a2)
{
  __int16 v4; // r7
  unsigned int v5; // r6
  int i; // r5
  unsigned int *v7; // r6
  int v8; // r8
  unsigned int v9; // r5
  unsigned int j; // r7
  unsigned int v11; // r3
  _BYTE *result; // r0

  if ( (a1 & 2) != 0 )
  {
    v4 = 0;
    v5 = 0;
    for ( i = a2 + 128; v5 < *(unsigned __int16 *)(a2 + 10); ++v5 )
    {
      if ( !memcmp(i + 16, (unsigned int)WHEA_ERROR_PACKET_SECTION_GUID, 16) )
      {
        if ( *(unsigned __int16 *)(a2 + 10) - v5 != 1 )
          memmove(i, i + 72, 72 * (*(unsigned __int16 *)(a2 + 10) - v5 - 1));
        ++v4;
      }
      else
      {
        i += 72;
      }
    }
    *(_WORD *)(a2 + 10) -= v4;
  }
  v7 = (unsigned int *)(a2 + 128);
  v8 = a1 & 1;
  if ( v8 )
    v9 = 72 * *(unsigned __int16 *)(a2 + 10) + 128;
  else
    v9 = *v7;
  for ( j = 0; j < *(unsigned __int16 *)(a2 + 10); v9 += v11 )
  {
    if ( v9 < *v7 )
    {
      memmove(v9 + a2, *v7 + a2, v7[1]);
      *v7 = v9;
    }
    v11 = v7[1];
    ++j;
    v7 += 18;
  }
  result = memset((_BYTE *)(v9 + a2), 0, *(_DWORD *)(a2 + 20) - v9);
  if ( v8 )
    *(_DWORD *)(a2 + 20) = v9;
  return result;
}
