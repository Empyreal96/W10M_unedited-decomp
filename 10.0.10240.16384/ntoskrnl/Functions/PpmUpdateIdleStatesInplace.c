// PpmUpdateIdleStatesInplace 
 
int __fastcall PpmUpdateIdleStatesInplace(int a1, _DWORD *a2)
{
  int v2; // r0
  int v4; // r2
  int *v5; // r4
  int v6; // r1
  int v7; // t1

  v2 = *(_DWORD *)(a1 + 2944);
  if ( !v2 )
    return -1073741637;
  v4 = a2[15];
  if ( v4 != *(_DWORD *)(v2 + 28) )
    return -1073741811;
  *(_DWORD *)(v2 + 120) = a2[2];
  if ( v4 )
  {
    v5 = a2 + 16;
    v6 = v2 + 252;
    do
    {
      *(_BYTE *)(v6 + 63) = (*v5 & 0x40000000) != 0;
      *(_DWORD *)(v6 + 20) = v5[1];
      *(_DWORD *)(v6 + 28) = v5[3];
      *(_DWORD *)(v6 + 24) = v5[2];
      *(_BYTE *)(v6 + 57) = *v5 < 0;
      v7 = *v5;
      v5 += 6;
      *(_DWORD *)(v6 + 32) = v7 < 0;
      v6 += 64;
      --v4;
    }
    while ( v4 );
  }
  return 0;
}
