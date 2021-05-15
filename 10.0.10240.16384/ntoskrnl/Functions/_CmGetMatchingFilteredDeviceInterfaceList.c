// _CmGetMatchingFilteredDeviceInterfaceList 
 
int __fastcall CmGetMatchingFilteredDeviceInterfaceList(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v11; // r9
  int v12; // r10
  int (__fastcall *v16)(int, _DWORD, int, int, int, int *); // r5
  int v17; // r1
  int v18; // r3
  int v19; // r2
  int v20; // r0
  int v21; // r0
  int v24; // [sp+20h] [bp-50h] BYREF
  _DWORD v25[10]; // [sp+24h] [bp-4Ch] BYREF

  v11 = a5;
  v12 = a6;
  v24 = 0;
  memset(v25, 0, sizeof(v25));
  v16 = *(int (__fastcall **)(int, _DWORD, int, int, int, int *))(a1 + 160);
  v17 = a9;
  v18 = a7;
  v19 = a8;
  v20 = a10;
  v25[6] = a7;
  v25[7] = a8;
  v25[8] = a9;
  v25[9] = a10;
  v25[1] = a2;
  v25[2] = a3;
  v25[3] = a4;
  v25[4] = a5;
  v25[5] = a6;
  if ( !v16 )
    return CmGetMatchingFilteredDeviceInterfaceListWorker(a1, a2, a3, a4, v11, v12, v18, v19, v17, v20);
  v21 = v16(a1, 0, 3, 17, 1, &v24);
  if ( v21 == -1073741822 )
  {
    v19 = v25[7];
    a2 = v25[1];
    a3 = v25[2];
    a4 = v25[3];
    v11 = v25[4];
    v12 = v25[5];
    v20 = v25[9];
    v17 = v25[8];
    v18 = v25[6];
    return CmGetMatchingFilteredDeviceInterfaceListWorker(a1, a2, a3, a4, v11, v12, v18, v19, v17, v20);
  }
  if ( v21 != -1073741536 )
    return sub_7C89A4();
  return v24;
}
