// MmQuerySystemVaInformation 
 
int __fastcall MmQuerySystemVaInformation(int a1, unsigned int a2, _DWORD *a3)
{
  int v5; // r4
  int v6; // r2
  int *v7; // r1
  int v8; // r0
  int *v9; // r1
  int *v10; // r0
  int v11; // r4
  int v12; // t1
  int *v13; // r2
  int v15[5]; // [sp+Ch] [bp-8Ch] BYREF
  _DWORD v16[4]; // [sp+20h] [bp-78h] BYREF
  int v17; // [sp+30h] [bp-68h] BYREF

  v15[0] = 5;
  v15[1] = 6;
  v15[2] = 8;
  v15[3] = 9;
  v15[4] = 1;
  *a3 = 0;
  if ( a2 < 0x60 )
    return -1073741820;
  v16[0] = -dword_63389C - dword_635310;
  v16[1] = -dword_63389C - dword_633888;
  v16[2] = 0;
  v6 = 0;
  v7 = &dword_632A84;
  v8 = 14;
  do
  {
    v6 += v7[2551];
    ++v7;
    --v8;
  }
  while ( v8 );
  v16[3] = v6;
  v9 = &v17;
  v10 = v15;
  v11 = 5;
  do
  {
    v12 = *v10++;
    v13 = &MiState[v12];
    *v9 = v13[2408] << 22;
    v9[1] = v13[2581] << 22;
    v9[2] = v13[2566] << 22;
    v9[3] = v13[2551];
    v9 += 4;
    --v11;
  }
  while ( v11 );
  v5 = 0;
  memmove(a1, (int)v16, 0x60u);
  *a3 = 96;
  return v5;
}
