// MiAdvanceFaultList 
 
_DWORD *__fastcall MiAdvanceFaultList(_DWORD *result)
{
  int v1; // r1
  unsigned int v2; // r2
  int v3; // r3
  unsigned int v4; // r2

  v1 = result[3];
  v2 = *(_DWORD *)(result[1] + 8 * v1 + 4) + (*(_DWORD *)(result[1] + 8 * v1) & 0xFFF) + 4095;
  v3 = result[4] + 1;
  result[4] = v3;
  if ( v3 == v2 >> 12 )
  {
    result[4] = 0;
    v4 = result[2];
    result[3] = v1 + 1;
    if ( v1 + 1 < v4 )
      result = (_DWORD *)sub_521194();
  }
  return result;
}
