// _CmSetDeviceRegPropWorker 
 
int __fastcall CmSetDeviceRegPropWorker(int a1, int a2, int a3, int a4, int a5, int *a6, unsigned int a7, __int16 a8)
{
  int v8; // r6
  int v9; // r5
  int *v12; // r9
  int v14; // r0
  unsigned __int16 *v15; // r1
  int v16; // r2
  int v17; // r3
  unsigned __int16 *v18; // r1
  int v19; // r0
  int v20; // [sp+10h] [bp-38h] BYREF
  unsigned __int16 *v21; // [sp+14h] [bp-34h]
  int v22; // [sp+18h] [bp-30h]
  char v23[40]; // [sp+20h] [bp-28h] BYREF

  v8 = 0;
  v9 = 0;
  v21 = (unsigned __int16 *)a2;
  v22 = a1;
  v20 = 0;
  if ( a8 )
    return -1073741811;
  if ( a7 )
  {
    v12 = a6;
    if ( !a6 )
      return -1073741811;
  }
  else
  {
    v12 = 0;
  }
  if ( (unsigned int)(a4 - 1) > 0x24 || !*((_BYTE *)DevicePropertyRead + a4) )
    goto LABEL_57;
  if ( !*((_BYTE *)DevicePropertyWrite + a4) )
    return sub_7EF0AC();
  v14 = MapCmDevicePropertyToRegType(a4);
  if ( !v14 )
    return -1073741264;
  if ( a5 != v14 )
    return -1073741811;
  if ( a4 != 11 )
  {
    if ( a4 != 8 )
    {
      if ( a4 == 24 && a7 )
      {
        if ( !RtlValidRelativeSecurityDescriptor((int)v12, a7, 0, v17)
          || (v14 = RtlLengthSecurityDescriptor((int)v12), v14 != a7) )
        {
          v9 = -1073741811;
          goto LABEL_27;
        }
        v8 = v20;
        goto LABEL_41;
      }
LABEL_13:
      if ( !a3 )
      {
        v14 = CmOpenDeviceRegKey(v22, (int)v15, 16, 0, 33554434, 0, (int)&v20, 0);
        v9 = v14;
        v8 = v20;
        if ( v14 < 0 )
          goto LABEL_28;
      }
      if ( a4 == 8 )
        goto LABEL_23;
      v18 = (unsigned __int16 *)MapCmDevicePropertyToRegValue(v14, a4);
      if ( v18 )
      {
        if ( !a7 )
        {
          v9 = RtlInitUnicodeStringEx((int)v23, v18);
          if ( v9 >= 0 )
            v9 = ZwDeleteValueKey();
          if ( v9 == -1073741772 || v9 == -1073741444 )
            v9 = -1073741275;
          goto LABEL_22;
        }
        if ( a3 )
          v8 = a3;
        v19 = RegRtlSetValue(v8, v18);
        if ( v19 != -1073741444 )
        {
          if ( v19 < 0 )
            v9 = v19;
LABEL_22:
          v8 = v20;
LABEL_23:
          if ( v9 < 0 )
            goto LABEL_28;
          if ( !a3 )
            a3 = v8;
          CmRaisePropertyChangeEvent(v22, v21, 1, a3, a4);
          goto LABEL_27;
        }
        v9 = -1073741810;
LABEL_27:
        v8 = v20;
        goto LABEL_28;
      }
LABEL_57:
      v9 = -1073741264;
LABEL_28:
      if ( v8 )
        ZwClose();
      return v9;
    }
    if ( a7 <= 0x40 )
      goto LABEL_13;
    return -1073741811;
  }
  if ( !a7 )
    goto LABEL_13;
  if ( !v12 || a7 != 4 )
    return -1073741811;
  if ( !*v12 )
    goto LABEL_13;
  v14 = CmIsRootDevice(v15, (int)v15, v16, *v12);
  if ( !v14 )
  {
LABEL_41:
    v15 = v21;
    goto LABEL_13;
  }
  return -1073741808;
}
