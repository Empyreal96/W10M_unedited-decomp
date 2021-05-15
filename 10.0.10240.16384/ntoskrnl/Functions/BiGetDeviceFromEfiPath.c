// BiGetDeviceFromEfiPath 
 
int __fastcall BiGetDeviceFromEfiPath(_BYTE *a1, int a2, _DWORD *a3, int a4)
{
  unsigned __int8 *v6; // r1
  int v7; // r2
  int v9; // r5
  _DWORD *v10; // r0
  unsigned int v11; // r8
  _BYTE *v12; // r3
  int v13; // r4
  unsigned int v14; // r6
  int v15; // r9
  _BYTE *v16; // r0
  _DWORD *v17; // r5
  _DWORD *v18; // r3
  unsigned int v19; // [sp+0h] [bp-28h] BYREF
  _DWORD *v20; // [sp+4h] [bp-24h]
  int v21; // [sp+8h] [bp-20h]

  v21 = a4;
  v19 = 0;
  v20 = (_DWORD *)a2;
  if ( (*a1 & 0x7F) == 127 )
    return -1073741766;
  v6 = &a1[(unsigned __int8)a1[2] | ((unsigned __int8)a1[3] << 8)];
  v7 = *v6;
  if ( (v7 & 0x7F) != 127 && (v7 != 4 || v6[1] != 4) )
    return sub_813614();
  v9 = (unsigned __int8)a1[2] | ((unsigned __int8)a1[3] << 8);
  v10 = (_DWORD *)ExAllocatePoolWithTag(1, v9 + 16, 1262764866);
  v11 = (unsigned int)v10;
  if ( !v10 )
    return -1073741670;
  v10[1] = v9 + 16;
  v10[2] = 4;
  *v10 = 1;
  memmove((int)(v10 + 3), (int)a1, v9);
  v12 = (_BYTE *)(v9 + v11);
  v12[13] = -1;
  v12[12] = 127;
  v12[15] = 0;
  v12[14] = 4;
  v13 = BiTranslateFilePath(v11, 3, &v19);
  v14 = v19;
  if ( v13 >= 0 )
  {
    v15 = *(_DWORD *)(v19 + 4);
    v16 = (_BYTE *)ExAllocatePoolWithTag(1, v15 + 8, 1262764866);
    v17 = v16;
    if ( v16 )
    {
      memset(v16, 0, v15 + 8);
      *v17 = 2;
      memmove((int)(v17 + 5), v14 + 12, v15 - 12);
      v18 = v20;
      *a3 = v15 + 8;
      *v18 = v17;
    }
    else
    {
      v13 = -1073741670;
    }
  }
  if ( v14 )
    ExFreePoolWithTag(v14);
  ExFreePoolWithTag(v11);
  return v13;
}
