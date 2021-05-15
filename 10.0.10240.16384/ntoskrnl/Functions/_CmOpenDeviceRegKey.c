// _CmOpenDeviceRegKey 
 
int __fastcall CmOpenDeviceRegKey(int a1, int a2, int a3, int a4, int a5, unsigned __int8 a6, int a7, _DWORD *a8)
{
  int v9; // r7
  int (__fastcall *v13)(int, int, int, int, int, int *); // r5
  int v14; // r3
  int v15; // r2
  int v17; // r4
  int v18; // [sp+10h] [bp-50h] BYREF
  int v19[19]; // [sp+14h] [bp-4Ch] BYREF

  v9 = a7;
  v18 = 0;
  memset(v19, 0, 40);
  v13 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 160);
  v14 = a5;
  v15 = a6;
  v19[2] = a4;
  v19[3] = a5;
  LOBYTE(v19[4]) = a6;
  v19[1] = a3;
  v19[5] = a7;
  if ( v13 )
  {
    if ( v13(a1, a2, 1, 11, 1, &v18) != -1073741822 )
      return sub_7C6214();
    a3 = v19[1];
    a4 = v19[2];
    v14 = v19[3];
    v15 = LOBYTE(v19[4]);
    v9 = v19[5];
  }
  v17 = CmOpenDeviceRegKeyWorker(a1, a2, a3, a4, v14, v15, v9, &v19[6], v18);
  if ( a8 )
  {
    if ( v17 >= 0 )
      *a8 = v19[6];
  }
  return v17;
}
