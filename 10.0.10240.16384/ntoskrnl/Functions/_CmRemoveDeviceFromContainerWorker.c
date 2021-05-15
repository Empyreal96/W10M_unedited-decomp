// _CmRemoveDeviceFromContainerWorker 
 
int __fastcall CmRemoveDeviceFromContainerWorker(int *a1, int a2, int a3, unsigned __int16 *a4, _BYTE *a5)
{
  int v9; // r4
  int v10; // r0
  int v11; // r0
  int v12; // r3
  int v14; // [sp+14h] [bp-34h] BYREF
  int v15; // [sp+18h] [bp-30h]
  int v16; // [sp+1Ch] [bp-2Ch]
  int v17[10]; // [sp+20h] [bp-28h] BYREF

  *a5 = 0;
  v16 = 0;
  v17[0] = 0;
  v14 = 0;
  v15 = 0;
  v9 = PnpCtxGetCachedContextBaseKey(a1, 9, v17);
  if ( v9 >= 0 )
  {
    v9 = PnpCtxRegOpenKey(a1, v17[0], a2, 0);
    if ( v9 >= 0 )
    {
      v9 = PnpCtxRegOpenKey(a1, v16, (int)L"BaseContainers", 0);
      if ( v9 >= 0 )
      {
        v9 = PnpCtxRegOpenKey(a1, v15, a3, 0);
        if ( v9 >= 0 )
        {
          v10 = RtlInitUnicodeStringEx((int)v17, a4);
          if ( v10 >= 0 )
            v10 = ZwDeleteValueKey();
          v11 = PnpCtxRegQueryInfoKey(v10, 0, 0, (int)&v14, (int)&v14);
          v9 = v11;
          if ( v11 >= 0 )
          {
            v12 = v14;
            if ( !v14 )
              v11 = PnpCtxRegDeleteTree(a1, 0, 0);
            v9 = PnpCtxRegQueryInfoKey(v11, v15, (int)&v14, v12, 0);
            if ( v9 >= 0 )
            {
              if ( !v14 )
              {
                v9 = CmDeleteDeviceContainer((int)a1, a2);
                if ( v9 >= 0 )
                  *a5 = 1;
              }
              PnpObjectRaisePropertyChangeEvent((int)a1, (int)a4, 1, 0, 0, (int)DEVPKEY_Device_ContainerId);
            }
          }
        }
      }
    }
  }
  if ( v9 == -1073741772 || v9 == -1073741444 )
    v9 = 0;
  if ( v15 )
    ZwClose();
  if ( v16 )
    ZwClose();
  return v9;
}
