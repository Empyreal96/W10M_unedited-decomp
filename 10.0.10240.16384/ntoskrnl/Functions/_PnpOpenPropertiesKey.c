// _PnpOpenPropertiesKey 
 
int __fastcall PnpOpenPropertiesKey(int *a1, int a2, unsigned __int16 *a3, int a4, unsigned __int8 a5, int a6, int *a7)
{
  char *v8; // r4
  int v9; // r5
  int v12; // r10
  int result; // r0
  int v14; // r0
  int v15; // r0
  int v16; // r8
  int v17; // r0
  int v18; // r0
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int *v22; // r8
  int v23; // r0
  int v24; // r1
  int v25; // r2
  unsigned int v27; // [sp+14h] [bp-ACh]
  int v28; // [sp+1Ch] [bp-A4h]
  unsigned int v29; // [sp+20h] [bp-A0h] BYREF
  char v30[152]; // [sp+28h] [bp-98h] BYREF

  v8 = 0;
  v28 = a2;
  v9 = 0;
  v27 = 0;
  v12 = 0;
  *a7 = 0;
  if ( a3 )
  {
    result = RtlUnalignedStringCchLengthW(a3, 512, &v29);
    if ( result < 0 )
      return result;
    if ( v29 >= 0x30 )
      return sub_7C6A40();
    v8 = v30;
    v9 = RtlStringCchPrintfExW((int)v30, 59, 0, 0, 2048, L"%s\\%s");
    if ( v9 < 0 )
      goto LABEL_12;
    if ( a1 )
      v14 = *a1;
    else
      v14 = 0;
    v15 = SysCtxRegOpenKey(v14, a2, v30, 0);
    if ( v15 == -1073741444 )
    {
      v9 = -1073741772;
      goto LABEL_12;
    }
    if ( v15 != -1073741772 || (v16 = a5) == 0 )
    {
      v9 = v15;
      goto LABEL_12;
    }
  }
  else
  {
    v16 = a5;
  }
  if ( a1 )
    v17 = *a1;
  else
    v17 = 0;
  v18 = SysCtxRegOpenKey(v17, v28, L"Properties", 0);
  if ( v18 != -1073741772 )
  {
    v22 = a7;
    goto LABEL_23;
  }
  if ( !v16 )
    goto LABEL_29;
  v23 = PnpGetPropertiesSecurityDescriptor(-1073741772, v19, v20, v21);
  v27 = v23;
  if ( v23 )
  {
    if ( !RtlValidSecurityDescriptor(v23, v24, v25, v23) )
    {
      v9 = -1073741595;
      goto LABEL_26;
    }
    v22 = a7;
    v18 = PnpCtxRegCreateKey(a1, v28, L"Properties");
LABEL_23:
    if ( v18 == -1073741444 )
    {
      v9 = -1073741772;
      goto LABEL_26;
    }
    if ( v18 >= 0 )
    {
      if ( !a3 )
        goto LABEL_26;
      v12 = *v22;
      *v22 = 0;
      v18 = PnpCtxRegCreateTree(a1, v12, a3, 0, a4, 0, v22, 0);
      if ( v18 == -1073741444 )
      {
        v9 = -1073741772;
        goto LABEL_26;
      }
      if ( v18 >= 0 )
      {
LABEL_26:
        if ( v27 )
          ExFreePoolWithTag(v27);
        goto LABEL_12;
      }
    }
LABEL_29:
    v9 = v18;
    goto LABEL_26;
  }
  v9 = -1073741595;
LABEL_12:
  if ( v8 && v8 != v30 )
    ExFreePoolWithTag((unsigned int)v8);
  if ( v12 )
    ZwClose();
  return v9;
}
