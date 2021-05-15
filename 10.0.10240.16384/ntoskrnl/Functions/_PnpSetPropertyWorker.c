// _PnpSetPropertyWorker 
 
int __fastcall PnpSetPropertyWorker(int *a1, int a2, char *a3, int a4, int a5, int a6, unsigned int a7)
{
  int v12; // r4
  int v13; // r0
  int v14; // r0
  int v15; // r0
  int v16; // r0
  int v17; // r3
  int v18; // [sp+4h] [bp-DCh]
  int v19; // [sp+38h] [bp-A8h] BYREF
  int v20; // [sp+3Ch] [bp-A4h] BYREF
  int v21; // [sp+40h] [bp-A0h] BYREF
  int v22; // [sp+44h] [bp-9Ch] BYREF
  int v23; // [sp+48h] [bp-98h] BYREF
  int v24; // [sp+4Ch] [bp-94h]
  int v25; // [sp+50h] [bp-90h] BYREF
  unsigned __int16 v26[12]; // [sp+58h] [bp-88h] BYREF
  unsigned __int16 v27[56]; // [sp+70h] [bp-70h] BYREF

  v24 = a6;
  v22 = 0;
  v23 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  if ( a7 > 0x7FFFFFFF )
    return sub_7C83EC();
  if ( !a3 || (v12 = RtlUnalignedStringCchLengthW((unsigned __int16 *)a3, 85, &v25), v12 >= 0) )
  {
    if ( a5 == 25 && !IsNeutralLocale(a3) )
      return sub_7C83EC();
    if ( RtlStringCchPrintfExW((int)v27, 39, 0, 0, 2048, L"{%08lx-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}") < 0 )
      goto LABEL_27;
    swprintf_s((int)v26, 9, (int)L"%04lX", *(_DWORD *)(a4 + 16));
    v12 = PnpOpenPropertiesKey(a1, a2, 0, 4, 1u, v18, &v19);
    if ( v12 < 0 )
    {
      v16 = 0;
      v19 = 0;
      goto LABEL_15;
    }
    v13 = PnpCtxRegCreateKey(a1, v19, v27, 4, 4, 0, (int)&v20, (int)&v22);
    if ( v13 == -1073741444 )
      goto LABEL_27;
    if ( v13 < 0 )
    {
      v17 = 0;
      v12 = v13;
      v16 = v19;
      v20 = 0;
      goto LABEL_16;
    }
    v14 = PnpCtxRegCreateKey(a1, v20, v26, 65542, 65542, 0, (int)&v21, (int)&v23);
    if ( v14 == -1073741444 )
      goto LABEL_27;
    if ( v14 < 0 )
    {
      v21 = 0;
      v12 = v14;
      goto LABEL_18;
    }
    v15 = RegRtlSetValue(v21, a3, a5 | 0xFFFF0000, v24, a7);
    if ( v15 == -1073741444 )
    {
LABEL_27:
      v12 = -1073741595;
    }
    else if ( v15 < 0 )
    {
      v12 = v15;
    }
    v16 = v19;
LABEL_15:
    v17 = v20;
LABEL_16:
    if ( !v21 )
    {
LABEL_19:
      if ( v17 )
      {
        ZwClose();
        if ( v12 < 0 && v22 == 1 )
          PnpCtxRegDeleteTree(a1, v19, v27);
        v16 = v19;
      }
      if ( v16 )
        ZwClose();
      return v12;
    }
    ZwClose();
    if ( v12 < 0 && v23 == 1 )
      PnpCtxRegDeleteTree(a1, v20, v26);
LABEL_18:
    v16 = v19;
    v17 = v20;
    goto LABEL_19;
  }
  return v12;
}
