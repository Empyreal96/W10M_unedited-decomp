// PfpMemoryListQuery 
 
int __fastcall PfpMemoryListQuery(int a1, char a2, _DWORD *a3)
{
  int v4; // r9
  int v6; // r4
  _DWORD *v7; // r8
  int v8; // r2
  _DWORD v10[2]; // [sp-4h] [bp-80h] BYREF
  _DWORD v11[30]; // [sp+4h] [bp-78h] BYREF

  v4 = a2;
  v10[1] = a3;
  if ( *(_DWORD *)(a1 + 16) >= 0x40u )
  {
    MmQueryMemoryListInformation((int)v11, 0x58u, (int)a3, v10);
    v7 = *(_DWORD **)(a1 + 12);
    if ( v4 )
      ProbeForWrite(*(_DWORD *)(a1 + 12), *(_DWORD *)(a1 + 16), 8);
    *v7 = 1;
    v7[1] = 64;
    v7[2] = 1;
    v8 = v7[5];
    v7[4] &= 0xFFFFFF00;
    v7[5] = v8;
    v7[6] = v11[8] + v11[9] + v11[5] + v11[6] + v11[7];
    v7[7] = 0;
    v7[8] = v11[10];
    v7[9] = 0;
    v7[10] = v11[11] + v11[12];
    v7[11] = 0;
    v7[12] = v11[0] + v11[1];
    v7[13] = 0;
    v7[14] = v11[2] + v11[3];
    v7[15] = 0;
    *a3 = 64;
    v6 = 0;
  }
  else
  {
    v6 = -1073741789;
    *a3 = 64;
  }
  return v6;
}
