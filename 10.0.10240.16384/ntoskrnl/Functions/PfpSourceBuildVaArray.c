// PfpSourceBuildVaArray 
 
int __fastcall PfpSourceBuildVaArray(int a1, _DWORD *a2)
{
  unsigned int v3; // r5
  int result; // r0
  unsigned int v6; // r0
  int v7; // r0
  _DWORD *v8; // r0
  unsigned int v9; // r5
  int v10; // r1
  _DWORD *v11; // r2

  v3 = *(_DWORD *)(a1 + 16);
  if ( !v3 )
    return -1073741275;
  if ( a2[1] < v3 )
  {
    v6 = a2[2];
    if ( v6 )
    {
      ExFreePoolWithTag(v6);
      a2[1] = 0;
      a2[2] = 0;
    }
    if ( v3 >> 29 )
      return -1073741675;
    v7 = ExAllocatePoolWithTag(512, 8 * v3, 1096181328);
    a2[2] = v7;
    if ( !v7 )
      return -1073741670;
    a2[1] = v3;
  }
  v8 = (_DWORD *)a2[2];
  v9 = 0;
  if ( *(_DWORD *)(a1 + 16) )
  {
    v10 = 0;
    do
    {
      ++v9;
      v11 = (_DWORD *)(*(_DWORD *)(a1 + 20) + v10);
      v10 += 16;
      *v8 = *v11;
      v8[1] = v11[2];
      v8 += 2;
    }
    while ( v9 < *(_DWORD *)(a1 + 16) );
  }
  result = 0;
  *a2 = *(_DWORD *)(a1 + 16);
  return result;
}
