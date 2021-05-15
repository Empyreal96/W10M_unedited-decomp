// _CmOpenDeviceInterfaceRegKey 
 
int __fastcall CmOpenDeviceInterfaceRegKey(int *a1, unsigned __int16 *a2, int a3, int a4, int a5, char a6, int a7, _DWORD *a8)
{
  int v8; // r7
  int (__fastcall *v12)(int *, unsigned __int16 *, int, int, int, int *); // r5
  int v13; // r2
  char v14; // r6
  int v15; // r3
  int v17; // r4
  int v18; // [sp+10h] [bp-50h] BYREF
  int v19[19]; // [sp+14h] [bp-4Ch] BYREF

  v8 = a7;
  v18 = 0;
  memset(v19, 0, 40);
  v12 = (int (__fastcall *)(int *, unsigned __int16 *, int, int, int, int *))a1[40];
  v13 = a5;
  v14 = a6;
  v15 = 0;
  v19[2] = 0;
  v19[3] = a5;
  LOBYTE(v19[4]) = a6;
  v19[1] = a3;
  v19[5] = a7;
  if ( v12 )
  {
    if ( v12(a1, a2, 3, 11, 1, &v18) != -1073741822 )
      return sub_7C7110();
    a3 = v19[1];
    v15 = v19[2];
    v13 = v19[3];
    v14 = v19[4];
    v8 = v19[5];
  }
  v17 = CmOpenDeviceInterfaceRegKeyWorker(a1, a2, a3, v15, v13, v14, v8, &v19[6]);
  if ( a8 )
  {
    if ( v17 >= 0 )
      *a8 = v19[6];
  }
  return v17;
}
