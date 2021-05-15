// PpmInstallNewIdleDomains 
 
int __fastcall PpmInstallNewIdleDomains(int a1, int a2)
{
  int v2; // r4
  int v3; // r2
  unsigned int v4; // r7
  _DWORD *v5; // r5
  int *v6; // r6
  int v7; // r1
  int v8; // r2
  int v9; // r3

  v2 = *(_DWORD *)(a1 + 2944);
  if ( !v2 )
    return -1073741811;
  v3 = *(_DWORD *)(v2 + 28);
  if ( v3 != *(_DWORD *)(a2 + 4) )
    return -1073741811;
  v4 = 0;
  if ( v3 )
  {
    v5 = *(_DWORD **)(a1 + 2944);
    v6 = (int *)(a2 + 20);
    do
    {
      v7 = *v6;
      v8 = v6[1];
      v9 = v6[2];
      v6 += 3;
      v5[63] = v7;
      v5[64] = v8;
      v5[65] = v9;
      ++v4;
      v5 += 16;
    }
    while ( v4 < *(_DWORD *)(v2 + 28) );
  }
  return 0;
}
