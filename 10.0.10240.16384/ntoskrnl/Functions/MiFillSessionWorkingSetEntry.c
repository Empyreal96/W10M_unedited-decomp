// MiFillSessionWorkingSetEntry 
 
_DWORD *__fastcall MiFillSessionWorkingSetEntry(_DWORD *result, _DWORD *a2)
{
  unsigned int v2; // r3
  unsigned int v3; // r2
  unsigned int v4; // r2
  unsigned int v5; // r3
  unsigned int v6; // r2

  *result = a2[2];
  result[4] = a2[826];
  result[1] = a2[825];
  v2 = a2[811];
  result[3] = v2;
  v3 = a2[8];
  result[2] = v3;
  if ( v2 >= v3 )
    v2 = v3;
  v4 = result[1];
  result[3] = v2;
  v5 = result[4];
  if ( v5 >= v4 )
    v5 = v4;
  v6 = result[2];
  result[4] = v5;
  if ( v5 >= v6 )
    v5 = v6;
  result[4] = v5;
  return result;
}
