// PiDevCfgConfigureDeviceInterface 
 
int __fastcall PiDevCfgConfigureDeviceInterface(unsigned __int16 *a1, int a2, int a3)
{
  int v6; // r0
  int v7; // r4
  int v8; // r0
  int v9; // r1
  int v10; // r2
  int v12; // [sp+14h] [bp-44h] BYREF
  char v13[8]; // [sp+18h] [bp-40h] BYREF
  int v14; // [sp+20h] [bp-38h]
  int v15; // [sp+24h] [bp-34h]
  char *v16; // [sp+28h] [bp-30h]
  int v17; // [sp+2Ch] [bp-2Ch]
  int v18; // [sp+30h] [bp-28h]
  int v19; // [sp+34h] [bp-24h]

  v12 = 0;
  RtlInitUnicodeString((unsigned int)v13, L"Device");
  v14 = 24;
  v15 = a2;
  v17 = 576;
  v16 = v13;
  v18 = 0;
  v19 = 0;
  v6 = ZwOpenKey();
  v7 = v6;
  if ( v6 != -1073741772 )
  {
    if ( v6 < 0 )
      goto LABEL_12;
    v7 = CmOpenDeviceInterfaceRegKey((int *)PiPnpRtlCtx, a1, 50, (int)&v12, 983103, 1, (int)&v12, 0);
    if ( v7 < 0 )
      goto LABEL_12;
    v7 = PiDevCfgCopyDeviceKeys(0, v12, 1, a3);
    if ( v7 < 0 )
      goto LABEL_12;
    ZwClose();
    ZwClose();
    v12 = 0;
  }
  RtlInitUnicodeString((unsigned int)v13, L"Properties");
  v14 = 24;
  v15 = a2;
  v17 = 576;
  v16 = v13;
  v18 = 0;
  v19 = 0;
  v8 = ZwOpenKey();
  v7 = v8;
  if ( v8 == -1073741772 )
  {
    v7 = 0;
  }
  else if ( v8 >= 0 )
  {
    v7 = CmOpenDeviceInterfaceRegKey((int *)PiPnpRtlCtx, a1, 48, (int)&v12, 983103, 0, (int)&v12, 0);
    if ( v7 >= 0 )
    {
      v7 = PiDevCfgCopyObjectProperties(PiPnpRtlCtx, v9, v10, a2, (int)a1, 3, v12);
      if ( v7 >= 0 )
        v7 = PiDevCfgCopyDeviceKey(0, v12, (int)a1, 3, 1, 0, a3);
    }
  }
LABEL_12:
  if ( v12 )
    ZwClose();
  return v7;
}
