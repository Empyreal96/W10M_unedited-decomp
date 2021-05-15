// _CmOpenDeviceContainerRegKey 
 
int __fastcall CmOpenDeviceContainerRegKey(int a1, int a2, int a3, int a4, int a5, char a6, int a7, _DWORD *a8)
{
  int (__fastcall *v11)(int, int, int, int, int, int *); // r5
  int v13; // r4
  int v14; // [sp+10h] [bp-50h] BYREF
  int v15[10]; // [sp+14h] [bp-4Ch] BYREF

  v14 = 0;
  memset(v15, 0, sizeof(v15));
  v11 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 160);
  v15[2] = 0;
  v15[3] = a5;
  LOBYTE(v15[4]) = a6;
  v15[1] = a3;
  v15[5] = a7;
  if ( v11 )
  {
    if ( v11(a1, a2, 5, 11, 1, &v14) != -1073741822 )
      return sub_7CBAF8();
    a3 = v15[1];
  }
  v13 = CmOpenDeviceContainerRegKeyWorker(a1, a2, a3);
  if ( v13 >= 0 )
  {
    if ( a8 )
      *a8 = v15[6];
  }
  return v13;
}
