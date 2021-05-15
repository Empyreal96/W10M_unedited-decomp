// PiDevCfgResetDeviceDriverSettings 
 
int __fastcall PiDevCfgResetDeviceDriverSettings(int a1, _DWORD *a2, unsigned int a3, int a4, unsigned int a5)
{
  int *v5; // r4
  int v8; // r5
  int v9; // t1
  int v11; // r3
  int *v12; // r5
  unsigned int v13; // r4
  int v14; // r6
  int v15; // r4
  _DWORD *v16; // r1
  unsigned __int16 *v17; // r1
  int v18; // r4
  int v19; // r4
  unsigned __int16 *v20; // r1
  int v21; // r0
  int v22; // [sp+4h] [bp-A4h]
  int v23; // [sp+20h] [bp-88h]
  int v24; // [sp+24h] [bp-84h] BYREF
  int v25; // [sp+28h] [bp-80h]
  int v26; // [sp+2Ch] [bp-7Ch] BYREF
  int v27; // [sp+30h] [bp-78h]
  int v28; // [sp+38h] [bp-70h] BYREF
  int v29; // [sp+3Ch] [bp-6Ch]
  int v30; // [sp+40h] [bp-68h]
  char v31[4]; // [sp+44h] [bp-64h] BYREF
  int v32; // [sp+48h] [bp-60h]
  int v33; // [sp+4Ch] [bp-5Ch]
  char *v34; // [sp+50h] [bp-58h]
  int v35; // [sp+54h] [bp-54h]
  int v36; // [sp+58h] [bp-50h]
  int v37; // [sp+5Ch] [bp-4Ch]
  char v38[8]; // [sp+60h] [bp-48h] BYREF
  char v39[8]; // [sp+68h] [bp-40h] BYREF
  char v40[8]; // [sp+70h] [bp-38h] BYREF
  _DWORD v41[12]; // [sp+78h] [bp-30h] BYREF

  v30 = a4;
  v5 = (int *)off_9200A0;
  v24 = 0;
  v25 = a1;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v8 = 8;
  do
  {
    v9 = *v5++;
    PiDevCfgSetObjectProperty(PiPnpRtlCtx, a2, a2[1], 1, a2[2], v22, v9, 0, 0, 0);
    --v8;
  }
  while ( v8 );
  if ( PnpGetObjectProperty(
         PiPnpRtlCtx,
         a2[1],
         1,
         a2[2],
         0,
         (int)DEVPKEY_Device_BusTypeGuid,
         (int)v31,
         (int)v41,
         16,
         (int)v39,
         0) >= 0 )
    return sub_819F0C();
  v41[0] = 0;
  v41[1] = 0;
  v41[2] = 0;
  v41[3] = 0;
  v11 = 2;
  v12 = &dword_8C6DA0;
  v23 = 2;
  do
  {
    v13 = *v12;
    if ( !*v12 )
    {
      v13 = v12[1];
      if ( !v13 )
        goto LABEL_10;
      if ( PnpIsNullGuid((int)v41) )
        goto LABEL_9;
      v16 = v41;
      goto LABEL_23;
    }
    if ( !a3 )
      goto LABEL_21;
    if ( memcmp(*v12, a3, 16) )
    {
      v11 = v23;
LABEL_21:
      if ( !a5 )
        goto LABEL_10;
      v16 = (_DWORD *)a5;
LABEL_23:
      if ( memcmp(v13, (unsigned int)v16, 16) )
        goto LABEL_9;
    }
    if ( CmOpenDeviceRegKey(PiPnpRtlCtx, a2[1], v12[2], 0, 983103, 1u, (int)&v24, 0) >= 0 )
    {
      v17 = (unsigned __int16 *)v12[3];
      if ( v17 )
      {
        RtlInitUnicodeString((unsigned int)v38, v17);
        v27 = 0;
        v32 = 24;
        v33 = v24;
        v35 = 576;
        v34 = v38;
        v36 = 0;
        v37 = 0;
        v18 = ZwOpenKey();
        ZwClose();
        if ( v18 >= 0 )
        {
          v19 = v27;
          v24 = v27;
          goto LABEL_29;
        }
      }
      else
      {
        v19 = v24;
LABEL_29:
        v20 = (unsigned __int16 *)v12[4];
        if ( v20 )
        {
          if ( RtlInitUnicodeStringEx((int)v40, v20) >= 0 )
            ZwDeleteValueKey();
        }
        else if ( v12[3] )
        {
          PnpCtxRegDeleteTree((int *)PiPnpRtlCtx, v19, 0);
        }
        ZwClose();
      }
LABEL_9:
      v11 = v23;
      goto LABEL_10;
    }
    v11 = v23;
LABEL_10:
    v12 += 5;
    v23 = --v11;
  }
  while ( v11 );
  v14 = 0;
  if ( !a5 || a3 && !memcmp(a5, a3, 16) )
  {
    v15 = v25;
LABEL_13:
    if ( a3 && v30 )
      v14 = PiDevCfgResetDeviceKeys(v15, a2, v30);
  }
  else
  {
    v14 = RtlStringFromGUIDEx(a5, (int)&v28, 1);
    if ( v14 >= 0 )
    {
      v21 = PnpOpenObjectRegKey(PiPnpRtlCtx, v29, 2, 131097, 0, (int)&v26, 0, 0);
      v15 = v25;
      if ( v21 < 0 )
        goto LABEL_13;
      v14 = PiDevCfgResetDeviceKeys(v25, a2, v26);
      if ( v14 >= 0 )
        goto LABEL_13;
    }
  }
  RtlFreeAnsiString(&v28);
  if ( v26 )
    ZwClose();
  return v14;
}
