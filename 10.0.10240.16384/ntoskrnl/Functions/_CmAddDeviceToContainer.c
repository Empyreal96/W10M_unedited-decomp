// _CmAddDeviceToContainer 
 
int __fastcall CmAddDeviceToContainer(int a1, int a2, int a3, int a4, _BYTE *a5)
{
  int (__fastcall *v9)(int, int, int, int, int, int *); // r6
  int v10; // r0
  int v11; // r4
  int v12; // r0
  char v13; // r3
  int v15; // [sp+8h] [bp-50h] BYREF
  _DWORD v16[19]; // [sp+Ch] [bp-4Ch] BYREF

  v15 = 0;
  memset(v16, 0, 40);
  v9 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 160);
  v16[1] = a3;
  v16[2] = a4;
  if ( v9 )
  {
    v10 = v9(a1, a2, 5, 13, 1, &v15);
    if ( v10 == -1073741822 )
    {
      v9 = 0;
    }
    else
    {
      if ( v10 == -1073741536 )
        goto LABEL_18;
      if ( v10 )
        return -1073741595;
    }
    a3 = v16[1];
    a4 = v16[2];
  }
  v11 = CmAddDeviceToContainerWorker(a1, a2, a3, a4, &v16[3]);
  if ( v9 )
  {
    v15 = v11;
    v12 = v9(a1, a2, 5, 13, 2, &v15);
    if ( v12 != -1073741822 )
    {
      if ( v12 != -1073741536 )
      {
        if ( !v12 )
          goto LABEL_10;
        return -1073741595;
      }
LABEL_18:
      v11 = v15;
      goto LABEL_16;
    }
  }
LABEL_10:
  v13 = v16[3];
  if ( !LOBYTE(v16[3]) )
  {
    PnpContainerRaiseDevicesChangedEvent(a1, a2);
LABEL_16:
    v13 = v16[3];
  }
  if ( a5 && v11 >= 0 )
    *a5 = v13;
  return v11;
}
