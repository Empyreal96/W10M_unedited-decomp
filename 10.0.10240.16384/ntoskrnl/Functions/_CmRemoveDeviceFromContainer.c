// _CmRemoveDeviceFromContainer 
 
int __fastcall CmRemoveDeviceFromContainer(int a1, int a2, int a3, int a4)
{
  int (__fastcall *v8)(int, int, int, int, int, int *); // r6
  int v9; // r0
  int v10; // r4
  int v11; // r0
  int v13; // [sp+8h] [bp-50h] BYREF
  _DWORD v14[19]; // [sp+Ch] [bp-4Ch] BYREF

  v13 = 0;
  memset(v14, 0, 40);
  v8 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 160);
  v14[1] = a3;
  v14[2] = a4;
  if ( v8 )
  {
    v9 = v8(a1, a2, 5, 14, 1, &v13);
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
    a4 = v14[2];
  }
  v10 = CmRemoveDeviceFromContainerWorker(a1, a2, a3, a4, &v14[3]);
  if ( v8 )
  {
    v13 = v10;
    v11 = v8(a1, a2, 5, 14, 2, &v13);
    if ( v11 != -1073741822 )
    {
      if ( v11 != -1073741536 )
      {
        if ( !v11 )
          goto LABEL_9;
        return -1073741595;
      }
      return v13;
    }
  }
LABEL_9:
  if ( !LOBYTE(v14[3]) )
    PnpContainerRaiseDevicesChangedEvent(a1, a2);
  return v10;
}
