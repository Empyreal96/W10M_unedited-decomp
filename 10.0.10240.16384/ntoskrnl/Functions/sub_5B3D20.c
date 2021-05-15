// sub_5B3D20 
 
int __fastcall sub_5B3D20(unsigned __int16 *a1, _DWORD *a2, unsigned int *a3)
{
  unsigned int v4; // r5
  int result; // r0
  unsigned int v6; // r4
  int v7; // r3

  v4 = *a1;
  result = 0;
  *a2 = 0;
  *a3 = 0;
  if ( (v4 & 1) != 0 )
    return -1073741811;
  v6 = a1[1];
  if ( (v6 & 1) != 0 )
    return -1073741811;
  if ( v4 > v6 )
    return -1073741811;
  if ( a1[1] == 0xFFFF )
    return -1073741811;
  v7 = *((_DWORD *)a1 + 1);
  if ( !v7 && (v4 || a1[1]) )
    return -1073741811;
  *a2 = v7;
  *a3 = v4 >> 1;
  return result;
}
