// RtlpPopulateContext 
 
_DWORD *__fastcall RtlpPopulateContext(_DWORD *a1, _DWORD *a2, unsigned int a3)
{
  _DWORD *result; // r0
  _DWORD *v6; // r3
  _DWORD *v7; // r2
  _DWORD *v8; // r3
  unsigned int v9; // r1

  if ( (a1[4] & ((69069 * (a3 >> a1[1]) + 1) & 0xFFFF0000 | ((1103515245 * (a3 >> a1[1]) + 12345) >> 16))) < a1[3] )
    return (_DWORD *)sub_52AFAC();
  result = (_DWORD *)RtlpGetChainHead();
  v6 = (_DWORD *)*result;
  v7 = result;
  while ( v6 != result )
  {
    v8 = (_DWORD *)*v7;
    v9 = *(_DWORD *)(*v7 + 8);
    if ( v9 >= a3 )
    {
      if ( v9 )
        break;
    }
    v7 = (_DWORD *)*v7;
    v6 = (_DWORD *)*v8;
  }
  *a2 = result;
  a2[1] = v7;
  a2[2] = a3;
  return result;
}
