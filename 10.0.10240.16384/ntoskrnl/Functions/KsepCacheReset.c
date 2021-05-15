// KsepCacheReset 
 
int __fastcall KsepCacheReset(int result)
{
  int v1; // r5
  _DWORD *v2; // r6
  _DWORD *v3; // r4
  _DWORD *v4; // r0
  unsigned int i; // r2
  _DWORD *v6; // r3

  v1 = result;
  v2 = *(_DWORD **)(result + 20);
  v3 = (_DWORD *)(result + 20);
  while ( v2 != v3 )
  {
    v4 = v2 - 3;
    v2 = (_DWORD *)*v2;
    result = (*(int (__fastcall **)(_DWORD *))(v1 + 56))(v4);
  }
  for ( i = 0; i < *(_DWORD *)(v1 + 8); ++i )
  {
    v6 = (_DWORD *)(*(_DWORD *)(v1 + 12) + 8 * i);
    *v6 = v6;
    v6[1] = v6;
  }
  *v3 = v3;
  v3[1] = v3;
  *(_DWORD *)(v1 + 4) = 0;
  return result;
}
