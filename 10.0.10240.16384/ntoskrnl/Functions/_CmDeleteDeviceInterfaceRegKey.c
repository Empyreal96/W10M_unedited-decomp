// _CmDeleteDeviceInterfaceRegKey 
 
int __fastcall CmDeleteDeviceInterfaceRegKey(int a1, int a2, int a3, int a4, char a5)
{
  int (__fastcall *v8)(int, int, int, int, int, int *); // r5
  int v9; // r0
  int v10; // r4
  int v11; // r0
  int v13; // [sp+8h] [bp-48h] BYREF
  _DWORD v14[10]; // [sp+Ch] [bp-44h] BYREF

  v13 = 0;
  memset(v14, 0, sizeof(v14));
  v8 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 160);
  LOBYTE(v14[3]) = a5;
  v14[1] = a3;
  v14[2] = 0;
  v14[4] = 0;
  if ( v8 )
  {
    v9 = v8(a1, a2, 3, 12, 1, &v13);
    if ( v9 == -1073741822 )
    {
      v8 = 0;
    }
    else
    {
      if ( v9 == -1073741536 )
        return v13;
      if ( v9 )
        return -1073741595;
    }
    a3 = v14[1];
  }
  v10 = CmDeleteDeviceInterfaceRegKeyWorker(a1, a2, a3);
  if ( !v8 )
    return v10;
  v13 = v10;
  v11 = v8(a1, a2, 3, 12, 2, &v13);
  if ( v11 == -1073741822 )
    return v10;
  if ( v11 == -1073741536 )
    return v13;
  if ( v11 )
    return -1073741595;
  return v10;
}
