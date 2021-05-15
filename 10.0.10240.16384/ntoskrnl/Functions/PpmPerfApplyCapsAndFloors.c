// PpmPerfApplyCapsAndFloors 
 
int __fastcall PpmPerfApplyCapsAndFloors(unsigned int *a1, unsigned int *a2, unsigned int *a3, int a4)
{
  int v4; // r5
  int v6; // r8
  _DWORD *v7; // r4
  int v8; // r7
  unsigned int v10; // r2
  unsigned int v11; // r2
  unsigned int v12; // r2
  unsigned int v13; // r2

  v4 = *(_DWORD *)(a4 + 24);
  v6 = 0;
  if ( !v4 )
    return 0;
  v7 = *(_DWORD **)(a4 + 32);
  v8 = *(unsigned __int8 *)(a4 + 113);
  do
  {
    if ( v8 )
      return sub_51F42C();
    v10 = v7[5];
    if ( *a1 > v10 )
    {
      v6 = 1;
      *a1 = v10;
    }
    v11 = v7[2];
    if ( *a1 > v11 )
    {
      v6 = 1;
      *a1 = v11;
    }
    v12 = v7[3];
    if ( *a2 < v12 )
      *a2 = v12;
    v13 = v7[4];
    if ( *a3 > v13 )
      *a3 = v13;
    v7 += 20;
    --v4;
  }
  while ( v4 );
  return v6;
}
