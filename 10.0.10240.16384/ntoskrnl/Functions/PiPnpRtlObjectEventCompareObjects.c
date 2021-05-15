// PiPnpRtlObjectEventCompareObjects 
 
int __fastcall PiPnpRtlObjectEventCompareObjects(int a1, int *a2, int *a3)
{
  int v3; // r3
  int v4; // r2
  _DWORD *v5; // r1
  _DWORD *v6; // r0
  unsigned int v7; // r2
  unsigned int v8; // r3
  int v9; // r3
  int v10; // r2
  unsigned __int16 *v11; // r1
  int v12; // r0
  int v13; // r0

  v3 = *a2;
  v4 = *a3;
  if ( *a2 == v4 )
    return 2;
  v5 = *(_DWORD **)(v4 + 8);
  v6 = *(_DWORD **)(v3 + 8);
  v7 = v5[4];
  v8 = v6[4];
  if ( v8 < v7 )
    return 0;
  if ( v8 <= v7 )
  {
    v9 = v6[5];
    v10 = v5[5];
    if ( v9 < v10 )
      return 0;
    if ( v9 <= v10 )
    {
      if ( v9 == 3 )
      {
        v11 = (unsigned __int16 *)(v5[3] + 8);
        v12 = v6[3] + 8;
      }
      else
      {
        v11 = (unsigned __int16 *)v5[3];
        v12 = v6[3];
      }
      v13 = wcsicmp(v12, v11);
      if ( v13 >= 0 )
      {
        if ( v13 <= 0 )
          return 2;
        return 1;
      }
      return 0;
    }
  }
  return 1;
}
