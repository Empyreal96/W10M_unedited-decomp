// _CmEnumDevicesInContainerWithCallbackWorker 
 
int __fastcall CmEnumDevicesInContainerWithCallbackWorker(int *a1, int a2, int a3, int (__fastcall *a4)(int *, unsigned int, int), int a5, __int16 a6)
{
  unsigned int v6; // r5
  int v7; // r7
  int v10; // r4
  int v11; // r1
  int v12; // r0
  int v13; // r8
  int v14; // r0
  int i; // r6
  unsigned int v17; // [sp+14h] [bp-34h] BYREF
  int v18; // [sp+18h] [bp-30h]
  int v19; // [sp+1Ch] [bp-2Ch] BYREF
  int *v20; // [sp+20h] [bp-28h]
  int (__fastcall *v21)(int *, unsigned int, int); // [sp+24h] [bp-24h]
  char v22[32]; // [sp+28h] [bp-20h] BYREF

  v20 = a1;
  v21 = a4;
  v6 = 0;
  v7 = 0;
  v19 = 0;
  if ( a6 )
    return -1073741811;
  if ( a3 )
    goto LABEL_6;
  v10 = PnpOpenObjectRegKey((int)a1, a2, 5, 1, 0, (int)&v19, 0, 0);
  if ( v10 < 0 )
    goto LABEL_34;
  v11 = v19;
  if ( !v19 )
LABEL_6:
    v11 = a3;
  v10 = PnpCtxRegOpenKey(a1, v11, (int)L"BaseContainers", 0);
  if ( v10 < 0 )
  {
LABEL_34:
    if ( v10 == -1073741444 )
      v10 = -1073741772;
    goto LABEL_36;
  }
  v12 = ExAllocatePoolWithTag(1, 400, 1380994640);
  v6 = v12;
  if ( v12 )
  {
LABEL_10:
    v13 = 0;
    while ( 1 )
    {
      v18 = 0;
      v17 = 200;
      v12 = PnpCtxRegEnumKey(v12, 0, v13, v6, &v17);
      v10 = v12;
      if ( v12 == -2147483622 )
        break;
      if ( v12 != -1073741789 )
      {
        if ( v12 < 0 )
          goto LABEL_34;
        v14 = PnpCtxRegOpenKey(v20, 0, v6, 0);
        v10 = v14;
        if ( v14 < 0 )
          goto LABEL_34;
        for ( i = 0; ; ++i )
        {
          do
          {
            v17 = 200;
            v14 = PnpCtxRegEnumValue(v14, v18, i, v6, (int)&v17, (int)v22, 0, 0);
            v10 = v14;
            if ( v14 == -2147483622 )
            {
              v10 = 0;
              goto LABEL_27;
            }
          }
          while ( v14 == -1073741789 );
          if ( v14 < 0 )
            goto LABEL_27;
          v14 = v21(v20, v6, a5);
          v7 = v14;
          if ( v14 )
            break;
        }
        if ( v14 != 1 && v14 != 2 )
        {
          if ( v14 == 3 )
            v10 = -1073741248;
          else
            v10 = -1073741595;
        }
LABEL_27:
        v12 = v18;
        if ( v18 )
          v12 = ZwClose();
        if ( v10 < 0 || v7 == 2 )
          goto LABEL_34;
        if ( v7 == 1 )
          goto LABEL_10;
        ++v13;
      }
    }
    v10 = 0;
    goto LABEL_34;
  }
  v10 = -1073741801;
LABEL_36:
  if ( v6 )
    ExFreePoolWithTag(v6);
  if ( v19 )
    ZwClose();
  return v10;
}
