// MiUpdateClaimDistribution 
 
int __fastcall MiUpdateClaimDistribution(int result, unsigned int *a2)
{
  char v2; // r4
  unsigned int v3; // r3
  unsigned int v4; // r2
  unsigned int v5; // r3
  unsigned int v6; // r2
  unsigned int v7; // r3
  unsigned int v8; // r2
  unsigned int v9; // r3
  unsigned int v10; // r2
  unsigned int v11; // r3
  unsigned int v12; // r2
  unsigned int v13; // r3
  unsigned int v14; // r2
  unsigned int v15; // r3

  if ( *(_BYTE *)(result + 114) == 2 )
    v2 = 3;
  else
    v2 = 1;
  v3 = (*(_DWORD *)(result + 20) >> v2) + *a2;
  if ( v3 < *a2 )
    *a2 = -1;
  else
    *a2 = v3;
  v4 = a2[1];
  v5 = (*(_DWORD *)(result + 24) >> v2) + v4;
  if ( v5 < v4 )
    a2[1] = -1;
  else
    a2[1] = v5;
  v6 = a2[2];
  v7 = (*(_DWORD *)(result + 28) >> v2) + v6;
  if ( v7 < v6 )
    a2[2] = -1;
  else
    a2[2] = v7;
  v8 = a2[3];
  v9 = (*(_DWORD *)(result + 32) >> v2) + v8;
  if ( v9 < v8 )
    a2[3] = -1;
  else
    a2[3] = v9;
  v10 = a2[4];
  v11 = (*(_DWORD *)(result + 36) >> v2) + v10;
  if ( v11 < v10 )
    a2[4] = -1;
  else
    a2[4] = v11;
  v12 = a2[5];
  v13 = (*(_DWORD *)(result + 40) >> v2) + v12;
  if ( v13 < v12 )
    a2[5] = -1;
  else
    a2[5] = v13;
  v14 = a2[6];
  v15 = (*(_DWORD *)(result + 44) >> v2) + v14;
  if ( v15 < v14 )
    a2[6] = -1;
  else
    a2[6] = v15;
  return result;
}
