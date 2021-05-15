// PfpFileSetupObjectAttributes 
 
int __fastcall PfpFileSetupObjectAttributes(int result, _DWORD *a2, int a3, int a4, _DWORD *a5, int *a6)
{
  int v6; // r6
  int v8; // r3
  int v9; // r3
  int v10; // r3
  int v11; // r3

  v6 = *a2;
  if ( (*a2 & 2) != 0 )
    v8 = 16417;
  else
    v8 = 96;
  *a6 = v8;
  v9 = a2[6];
  if ( !v9 || (v6 & 4) != 0 )
    return sub_80EE3C();
  *(_DWORD *)(a4 + 4) = v9 + 2;
  v10 = 2 * (a2[7] + 0xFFFF);
  *(_WORD *)a4 = 2 * (*((_WORD *)a2 + 14) - 1);
  *(_WORD *)(a4 + 2) = v10 + 2;
  v11 = *(_DWORD *)(*(_DWORD *)(result + 8) + 40 * a3 + 20);
  *a5 = 24;
  a5[1] = v11;
  a5[2] = a4;
  a5[3] = 576;
  a5[4] = 0;
  a5[5] = 0;
  return result;
}
