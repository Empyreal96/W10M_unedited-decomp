// PfSnFindImageFileName 
 
unsigned int __fastcall PfSnFindImageFileName(unsigned __int16 *a1, _DWORD *a2)
{
  unsigned int v2; // r4
  int v3; // r2
  int v4; // r5
  unsigned __int16 *v5; // r0
  int v6; // t1
  unsigned int result; // r0

  v2 = *((_DWORD *)a1 + 1);
  v3 = 0;
  v4 = *a1 >> 1;
  v5 = (unsigned __int16 *)(v2 + 2 * v4 - 2);
  if ( (unsigned int)v5 < v2 )
    return 0;
  do
  {
    v6 = *v5--;
    if ( v6 == 92 )
      break;
    ++v3;
  }
  while ( (unsigned int)v5 >= v2 );
  if ( !v3 )
    return 0;
  result = v2 + 2 * (v4 - v3);
  *a2 = v3;
  return result;
}
