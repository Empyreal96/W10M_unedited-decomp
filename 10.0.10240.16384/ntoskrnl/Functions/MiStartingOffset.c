// MiStartingOffset 
 
int __fastcall MiStartingOffset(_DWORD *a1, unsigned int a2)
{
  unsigned int v4; // r1
  int result; // r0
  int v6; // r3
  int v7; // r0

  if ( (*(_DWORD *)(*a1 + 28) & 0x20) != 0 )
  {
    v4 = a1[1];
    if ( a2 < v4 || a2 >= v4 + 4 * a1[7] )
      result = sub_544C34();
    else
      result = (a1[5] + 8 * ((int)(a2 - v4) >> 2)) << 9;
  }
  else
  {
    v6 = a1[1];
    if ( v6 )
      v7 = (int)(a2 - v6) >> 2 << 12;
    else
      v7 = 0;
    result = v7 + (a1[5] << 12);
  }
  return result;
}
