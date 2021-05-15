// _CmDeleteDeviceRegKey 
 
int __fastcall CmDeleteDeviceRegKey(int a1, int a2, int a3, int a4)
{
  int (__fastcall *v8)(int, int, int, int, int, int *); // r5
  int v9; // r3
  int v11; // [sp+8h] [bp-50h] BYREF
  _DWORD v12[10]; // [sp+Ch] [bp-4Ch] BYREF

  v11 = 0;
  memset(v12, 0, sizeof(v12));
  v8 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 160);
  v9 = 1;
  v12[1] = a3;
  v12[2] = a4;
  LOBYTE(v12[3]) = 1;
  v12[4] = 0;
  if ( v8 )
  {
    if ( v8(a1, a2, 1, 12, 1, &v11) != -1073741822 )
      return sub_81A060();
    a3 = v12[1];
    a4 = v12[2];
    v9 = LOBYTE(v12[3]);
  }
  return CmDeleteDeviceRegKeyWorker(a1, a2, a3, a4, v9);
}
