// PiDevCfgEnumDeviceKeys 
 
int __fastcall PiDevCfgEnumDeviceKeys(int a1, int a2, int a3, int a4, unsigned __int8 a5, int (__fastcall *a6)(int, int, __int16 **, int, int, int), int a7)
{
  int v7; // lr
  int v8; // r5
  int v9; // r4
  int v10; // r0
  __int16 **v11; // r6
  unsigned int v12; // r8
  int v14; // r0
  int v16; // r2
  int v17; // r4
  unsigned __int16 *v18; // r1
  int v19; // [sp+10h] [bp-C0h] BYREF
  int v20; // [sp+14h] [bp-BCh]
  int v21; // [sp+18h] [bp-B8h]
  int v22; // [sp+1Ch] [bp-B4h]
  int v23; // [sp+20h] [bp-B0h]
  int v24; // [sp+24h] [bp-ACh]
  char *v25; // [sp+28h] [bp-A8h]
  int v26; // [sp+2Ch] [bp-A4h]
  int v27; // [sp+30h] [bp-A0h]
  int v28; // [sp+34h] [bp-9Ch]
  char v29[12]; // [sp+40h] [bp-90h] BYREF
  int v30; // [sp+4Ch] [bp-84h]
  int v31; // [sp+50h] [bp-80h]
  int v32; // [sp+54h] [bp-7Ch]
  int (__fastcall *v33)(int, int, __int16 **, int, int, int); // [sp+58h] [bp-78h]

  v7 = a4;
  v22 = a4;
  v30 = a3;
  v31 = a1;
  v8 = 0;
  v33 = a6;
  v9 = 0;
  v10 = 0;
  v32 = a7;
  v11 = &off_8C6DC8;
  v20 = 0;
  v21 = 0;
  v12 = 0;
  v19 = 0;
  while ( ((unsigned int)v11[1] & v7) == 0 )
  {
LABEL_7:
    ++v12;
    v11 += 5;
    if ( v12 >= 7 )
      goto LABEL_8;
  }
  RtlInitUnicodeString((unsigned int)v29, (unsigned __int16 *)*v11);
  v20 = 0;
  v23 = 24;
  v24 = v30;
  v26 = 576;
  v25 = v29;
  v27 = 0;
  v28 = 0;
  v14 = ZwOpenKey();
  if ( v14 == -1073741772 )
  {
    v9 = v20;
LABEL_5:
    v10 = v19;
LABEL_6:
    v7 = v22;
    goto LABEL_7;
  }
  if ( v14 < 0 )
    goto LABEL_28;
  v16 = (int)v11[3];
  if ( v16 )
  {
    v17 = CmOpenDeviceRegKey(PiPnpRtlCtx, *(_DWORD *)(a2 + 4), v16, 0, 983103, a5, (int)&v19, 0);
LABEL_16:
    v10 = v19;
    goto LABEL_17;
  }
  v17 = PnpCtxOpenContextBaseKey((int *)PiPnpRtlCtx, (int)v11[2], (int)&PiPnpRtlCtx, 983103);
  if ( v17 < 0 )
    goto LABEL_16;
  if ( v11[2] == (__int16 *)7 )
    return sub_7E4854();
  v10 = v19;
  v18 = (unsigned __int16 *)v11[4];
  if ( v18 )
  {
    RtlInitUnicodeString((unsigned int)v29, v18);
    v21 = 0;
    v23 = 24;
    v24 = v19;
    v26 = 576;
    v25 = v29;
    v27 = 0;
    v28 = 0;
    v17 = ZwOpenKey();
    ZwClose();
    if ( v17 < 0 )
      goto LABEL_16;
    v10 = v21;
    v19 = v21;
  }
LABEL_17:
  if ( v17 == -1073741772 )
  {
    ZwClose();
    v9 = 0;
    v20 = 0;
    goto LABEL_5;
  }
  if ( v17 < 0 )
  {
    v8 = v17;
    goto LABEL_33;
  }
  v14 = v33(v31, a2, v11, v20, v10, v32);
  if ( v14 == -1073741248 )
    goto LABEL_29;
  if ( v14 >= 0 )
  {
    ZwClose();
    v20 = 0;
    ZwClose();
    v10 = 0;
    v9 = v20;
    v19 = 0;
    goto LABEL_6;
  }
LABEL_28:
  v8 = v14;
LABEL_29:
  v10 = v19;
LABEL_33:
  v9 = v20;
LABEL_8:
  if ( v9 )
  {
    ZwClose();
    v10 = v19;
  }
  if ( v10 )
    ZwClose();
  return v8;
}
