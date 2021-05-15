// _CmSetInstallerClassRegPropWorker 
 
int __fastcall CmSetInstallerClassRegPropWorker(int *a1, int a2, int a3, int a4, int a5, int a6, unsigned int a7, __int16 a8)
{
  int v8; // r6
  int v9; // r7
  int v10; // r5
  int v13; // r4
  int v14; // r0
  unsigned __int16 *v15; // r1
  int *v16; // r4
  int v17; // r4
  unsigned __int16 *v18; // r1
  int v19; // r0
  int v21; // [sp+4h] [bp-44h]
  int v22; // [sp+10h] [bp-38h] BYREF
  int v23; // [sp+14h] [bp-34h] BYREF
  int *v24; // [sp+18h] [bp-30h]
  int v25; // [sp+20h] [bp-28h] BYREF
  unsigned __int16 *v26; // [sp+28h] [bp-20h]

  v8 = 0;
  v9 = 0;
  v10 = 0;
  v26 = (unsigned __int16 *)a2;
  v23 = 0;
  v24 = a1;
  v22 = 0;
  if ( a8 )
    return -1073741811;
  if ( a7 )
  {
    v13 = a6;
    v25 = a6;
    if ( !a6 )
      return -1073741811;
  }
  else
  {
    v13 = 0;
    v25 = 0;
  }
  if ( (unsigned int)(a4 - 1) > 0x24 || !*((_BYTE *)ClassPropertyRead + a4) )
    goto LABEL_51;
  if ( !*((_BYTE *)ClassPropertyWrite + a4) )
    return -1073741790;
  v14 = MapCmClassPropertyToRegType(a4);
  if ( !v14 )
    return -1073741264;
  if ( a5 != v14 )
    return -1073741811;
  if ( a4 == 8 )
  {
    if ( a7 <= 0x40 )
      goto LABEL_21;
    return -1073741811;
  }
  if ( a4 == 24 && a7 )
  {
    if ( !RtlValidRelativeSecurityDescriptor(v13, a7, 0, a5) || (v14 = RtlLengthSecurityDescriptor(v13), v14 != a7) )
    {
      v10 = -1073741811;
      goto LABEL_50;
    }
    v8 = v22;
    v9 = v23;
    v15 = v26;
  }
LABEL_21:
  v16 = v24;
  if ( !a3 )
  {
    v14 = CmOpenInstallerClassRegKey(v24, v15, 32, 0, 33554438, 0, (int)&v22, 0);
    v10 = v14;
    if ( v14 < 0 )
      goto LABEL_50;
    v8 = v22;
    v9 = v23;
  }
  if ( a4 == 8 || a4 == 13 || a4 > 17 && a4 <= 19 )
  {
    v17 = v8;
    if ( a3 )
      v17 = a3;
  }
  else
  {
    if ( a3 )
      v8 = a3;
    v14 = PnpOpenPropertiesKey(v16, v8, 0, 2, 1u, v21, &v23);
    v10 = v14;
    if ( v14 < 0 )
      goto LABEL_50;
    v8 = v22;
    v9 = v23;
    v17 = v23;
  }
  if ( v10 >= 0 )
  {
    v18 = (unsigned __int16 *)MapCmClassPropertyToRegValue(v14, a4);
    if ( v18 )
    {
      if ( !a7 )
      {
        v10 = RtlInitUnicodeStringEx((int)&v25, v18);
        if ( v10 >= 0 )
          v10 = ZwDeleteValueKey();
        if ( v10 == -1073741772 || v10 == -1073741444 )
          v10 = -1073741275;
LABEL_46:
        if ( v10 >= 0 )
        {
          if ( !a3 )
            a3 = v22;
          CmRaisePropertyChangeEvent((int)v24, (int)v26, 2, a3, (int (*)[5])a4);
        }
        goto LABEL_50;
      }
      v19 = RegRtlSetValue(v17, v18);
      if ( v19 != -1073741444 )
      {
        if ( v19 < 0 )
          v10 = v19;
        goto LABEL_46;
      }
      v10 = -1073741772;
LABEL_50:
      v8 = v22;
      v9 = v23;
      goto LABEL_52;
    }
LABEL_51:
    v10 = -1073741264;
  }
LABEL_52:
  if ( v9 )
  {
    ZwClose();
    v8 = v22;
  }
  if ( v8 )
    ZwClose();
  return v10;
}
