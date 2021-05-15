// PiDqQueryGetNextIoctlInfo 
 
_DWORD *__fastcall PiDqQueryGetNextIoctlInfo(_DWORD *result, unsigned int a2, unsigned int a3, _DWORD *a4)
{
  int v6; // r3
  int v7; // r2
  unsigned int v8; // r3

  if ( !result[24] && (_DWORD *)result[25] == result + 25 && (result[29] & 0x20) != 0 )
  {
    if ( (*(_DWORD *)(result[3] + 32) & 1) != 0 )
    {
      v6 = 16;
      *a4 = 4653064;
    }
    else
    {
      v6 = 0;
      *a4 = 0;
    }
    a4[1] = v6;
  }
  else
  {
    *a4 = 4653063;
    if ( (result[29] & 0x20) != 0 )
    {
      v7 = result[27];
      if ( result[24] )
        ++v7;
    }
    else
    {
      v7 = 4;
    }
    if ( a3 )
      v8 = v7 * a3 + 16;
    else
      v8 = v7 << 10;
    a4[1] = v8;
    if ( v8 > 0x10000 )
      a4[1] = 0x10000;
    if ( a4[1] < a3 )
      a4[1] = a3;
    if ( a4[1] < a2 )
      a4[1] = a2;
  }
  return result;
}
