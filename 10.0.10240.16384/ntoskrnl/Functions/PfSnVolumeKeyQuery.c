// PfSnVolumeKeyQuery 
 
int __fastcall PfSnVolumeKeyQuery(_DWORD *a1, int a2, int a3)
{
  unsigned int v4; // r6
  int *v5; // r0
  int *v8; // r5
  int v9; // t1
  int result; // r0
  int v11; // r0

  v4 = a1[102];
  v5 = (int *)a1[100];
  v8 = &v5[v4];
  while ( v5 < v8 )
  {
    v9 = *v5++;
    if ( v9 == a2 )
      return 0;
  }
  if ( !PfSnArrayGrow(v4, a2, a3, a1 + 101, a1 + 100) )
    return sub_8014CC();
  *(_DWORD *)(a1[100] + 4 * a1[102]) = a2;
  v11 = a1[66];
  ++a1[102];
  result = (*(int (__fastcall **)(int, int))(dword_637348 + 12))(v11, a3);
  if ( result >= 0 )
    return 0;
  return result;
}
