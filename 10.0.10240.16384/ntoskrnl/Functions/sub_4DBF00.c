// sub_4DBF00 
 
int __fastcall sub_4DBF00(unsigned __int16 *a1, _DWORD *a2, unsigned int *a3)
{
  int result; // r0
  unsigned int v5; // r5
  unsigned int v6; // r4
  int v7; // r3

  result = 0;
  *a2 = 0;
  *a3 = 0;
  if ( !a1 )
    return sub_50AAFC(0);
  v5 = *a1;
  if ( (v5 & 1) != 0 )
    return -1073741811;
  v6 = a1[1];
  if ( (v6 & 1) != 0 )
    return -1073741811;
  if ( v5 > v6 )
    return -1073741811;
  if ( a1[1] == 0xFFFF )
    return -1073741811;
  v7 = *((_DWORD *)a1 + 1);
  if ( !v7 && (*a1 || a1[1]) )
    return -1073741811;
  *a2 = v7;
  *a3 = v6 >> 1;
  return result;
}
