// _CmAddDeviceToContainerWorker 
 
int __fastcall CmAddDeviceToContainerWorker(int a1, unsigned __int16 *a2, unsigned __int16 *a3, unsigned __int16 *a4, _BYTE *a5)
{
  int v7; // r4
  int v8; // r6
  int v9; // r0
  bool v10; // nf
  char v12[4]; // [sp+10h] [bp-40h] BYREF
  int v13; // [sp+14h] [bp-3Ch] BYREF
  int v14; // [sp+18h] [bp-38h] BYREF
  int v15; // [sp+1Ch] [bp-34h] BYREF
  int v16; // [sp+20h] [bp-30h] BYREF
  int v17; // [sp+24h] [bp-2Ch] BYREF
  unsigned __int16 *v18[10]; // [sp+28h] [bp-28h] BYREF

  *a5 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v12[0] = 0;
  v17 = 0;
  v18[0] = a3;
  v18[1] = a2;
  v7 = CmCreateDeviceContainer(a1, a2, a3, &v16, v12);
  v8 = v16;
  if ( v7 < 0 )
    goto LABEL_10;
  v7 = PnpCtxRegCreateKey((int *)a1, v16, L"BaseContainers", 4, 4, 0, (int)&v15, (int)&v17);
  if ( v7 < 0 )
    goto LABEL_10;
  v9 = PnpCtxRegCreateKey((int *)a1, v15, v18[0], 3, 3, 0, (int)&v14, (int)&v13);
  v7 = v9;
  if ( v9 < 0 )
    goto LABEL_10;
  if ( v13 != 2 )
    goto LABEL_22;
  v18[0] = 0;
  v9 = PnpCtxRegQueryValue(v9, v14, a4, 0, 0, (unsigned int *)v18);
  v7 = v9;
  if ( v9 == -1073741772 || v9 == -1073741444 )
  {
    v7 = 0;
LABEL_22:
    v10 = v7 < 0;
LABEL_23:
    if ( v10 )
      goto LABEL_10;
    goto LABEL_9;
  }
  v10 = v9 < 0;
  if ( v9 )
    goto LABEL_23;
  *a5 = 1;
LABEL_9:
  if ( !*a5 )
  {
    v7 = PnpCtxRegSetValue(v9, v14, (int)a4, 0, 0, 0);
    if ( v7 >= 0 )
    {
      if ( *(_DWORD *)(a1 + 156) )
        PnpDeviceRaisePropertyChangeEventWorker(
          a1,
          (int)a4,
          0,
          0,
          (unsigned int)DEVPKEY_Device_ContainerId,
          *(int (__fastcall **)(int, int, int, int, int))(a1 + 156));
    }
  }
LABEL_10:
  if ( v7 == -1073741444 )
    v7 = -1073741772;
  if ( v7 < 0 )
    return sub_7CB94C();
  if ( v14 )
    ZwClose();
  if ( v15 )
    ZwClose();
  if ( v8 )
    ZwClose();
  return v7;
}
