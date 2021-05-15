// MmWriteUnloadedDriverInformation 
 
_DWORD *__fastcall MmWriteUnloadedDriverInformation(_DWORD *result)
{
  unsigned int *v1; // r5
  int v2; // r2
  unsigned __int16 *v3; // r4
  int v4; // r9
  unsigned int v5; // r6
  unsigned int v6; // r7
  _DWORD *v7; // r1
  unsigned int v8; // r2

  v1 = result;
  v2 = dword_634F88;
  if ( dword_634F88 )
  {
    v3 = (unsigned __int16 *)(result + 1);
    v4 = (int)(result + 3);
    v5 = dword_634F84 - 1;
    v6 = 0;
    while ( 1 )
    {
      if ( v5 >= 0x32 )
        v5 = 49;
      v7 = (_DWORD *)(v2 + 24 * v5);
      *(_DWORD *)v3 = *v7;
      *((_DWORD *)v3 + 1) = v7[1];
      if ( !v7[1] )
        break;
      *((_DWORD *)v3 + 8) = v7[2];
      *((_DWORD *)v3 + 9) = v7[3];
      if ( *v3 > 0x18u )
        *v3 = 24;
      if ( v3[1] > 0x18u )
        v3[1] = 24;
      v8 = v3[1];
      *((_DWORD *)v3 + 1) = v4;
      result = (_DWORD *)memmove(v4, v7[1], v8);
      ++v6;
      v3 += 20;
      --v5;
      v4 += 40;
      if ( v6 >= 0x32 )
        break;
      v2 = dword_634F88;
    }
    *v1 = v6;
  }
  else
  {
    *result = 0;
  }
  return result;
}
