// _CmDeleteDeviceWorker 
 
int __fastcall CmDeleteDeviceWorker(_DWORD *a1, unsigned __int16 *a2, __int16 a3)
{
  unsigned __int16 *v3; // r7
  int v4; // r5
  unsigned int v5; // r6
  unsigned __int16 *v7; // r10
  unsigned __int16 *v8; // r9
  int v9; // r4
  int v10; // r0
  int v11; // r0
  int v12; // r3
  unsigned __int16 *v13; // r5
  int v14; // r2
  int v15; // r0
  unsigned __int16 *v16; // r5
  int v17; // r5
  int *i; // r3
  int v19; // r2
  int v20; // r0
  int v21; // r0
  unsigned int v22; // r5
  int v23; // r0
  unsigned int v24; // r2
  unsigned int v25; // r6
  unsigned int v26; // r7
  int v27; // r0
  int v29; // [sp+18h] [bp-108h] BYREF
  int v30; // [sp+1Ch] [bp-104h]
  unsigned int v31; // [sp+20h] [bp-100h] BYREF
  int v32; // [sp+24h] [bp-FCh] BYREF
  unsigned int v33; // [sp+28h] [bp-F8h] BYREF
  unsigned __int16 *v34; // [sp+2Ch] [bp-F4h]
  unsigned int v35; // [sp+30h] [bp-F0h] BYREF
  int v36; // [sp+34h] [bp-ECh] BYREF
  char v37[8]; // [sp+38h] [bp-E8h] BYREF
  int v38[8]; // [sp+40h] [bp-E0h] BYREF
  char v39[80]; // [sp+60h] [bp-C0h] BYREF
  _WORD v40[56]; // [sp+B0h] [bp-70h] BYREF

  v32 = 0;
  v33 = 0;
  v29 = 0;
  v35 = 0;
  v3 = a2;
  v4 = 0;
  v5 = 0;
  v34 = a2;
  v7 = 0;
  v8 = 0;
  if ( a3 )
    return -1073741811;
  v9 = CmOpenDeviceRegKey((int)a1, (int)a2, 16, 0, 33619970, 0, (int)&v32, 0);
  if ( v9 >= 0 )
  {
    v36 = 78;
    v10 = CmGetDeviceRegProp((int)a1, (int)v3, v32, 37, (int)v37, (int)v39, (int)&v36);
    if ( v10 < 0 )
    {
      if ( v10 == -1073741275 )
        goto LABEL_10;
      goto LABEL_6;
    }
    v10 = CmGetDeviceContainerIdFromBase(a1, (int)v3, (int)v39, v40);
    if ( v10 < 0 || (v10 = CmRemoveDeviceFromContainer(a1, v40, v39, v3), v10 < 0) )
    {
LABEL_6:
      v9 = v10;
      goto LABEL_84;
    }
    while ( 1 )
    {
LABEL_10:
      v11 = CmGetMatchingFilteredDeviceInterfaceList((int)a1, 0, (int)v3, 0, 0, 0, (int)v7, v4, (int)&v35, 0);
      if ( v11 != -1073741789 )
        goto LABEL_17;
      if ( RtlULongLongToULong(2 * v35, (unsigned __int64)v35 >> 31, &v29) < 0 )
      {
        v11 = -1073741811;
        goto LABEL_18;
      }
      if ( v7 )
        ExFreePoolWithTag((unsigned int)v7);
      v7 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v29, 1380994640);
      if ( !v7 )
        break;
      v4 = v35;
    }
    v11 = -1073741801;
LABEL_17:
    if ( v11 )
    {
LABEL_18:
      v9 = v11;
      goto LABEL_80;
    }
    if ( v35 )
    {
      v12 = *v7;
      v13 = v7;
      while ( v12 )
      {
        CmDeleteDeviceInterface((int)a1, (int)v13, 0);
        v13 += wcslen(v13) + 1;
        v12 = *v13;
      }
    }
    v14 = 0;
    v29 = 0;
    while ( 1 )
    {
      v15 = CmGetMatchingDeviceList((int)a1, (int)CmMatchLastKnownParentCallback, (int)v3, (int)v8, v14, (int)&v33, 0);
      if ( v15 != -1073741789 )
        goto LABEL_32;
      if ( RtlULongLongToULong(2 * v33, (unsigned __int64)v33 >> 31, &v29) < 0 )
      {
        v15 = -1073741811;
        goto LABEL_33;
      }
      if ( v8 )
        ExFreePoolWithTag((unsigned int)v8);
      v8 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v29, 1380994640);
      if ( !v8 )
        break;
      v14 = v33;
    }
    v15 = -1073741801;
LABEL_32:
    if ( v15 )
    {
LABEL_33:
      v9 = v15;
      goto LABEL_78;
    }
    if ( v33 )
    {
      v16 = v8;
      if ( *v8 )
      {
        do
        {
          PnpSetObjectProperty((int)a1, (int)v16, 1, 0, 0, (int)DEVPKEY_Device_LastKnownParent, 0, 0, 0, 0);
          v16 += wcslen(v16) + 1;
        }
        while ( *v16 );
        v3 = v34;
      }
    }
    v38[0] = 786;
    v38[1] = 530;
    v38[2] = 274;
    v38[3] = 18;
    v38[4] = 785;
    v38[5] = 529;
    v38[6] = 273;
    v38[7] = 17;
    v17 = 0;
    for ( i = v38; ; i = (int *)v31 )
    {
      v19 = *i;
      v31 = (unsigned int)(i + 1);
      v20 = CmDeleteDeviceRegKey((int)a1, (int)v3, v19, 0);
      if ( v20 )
      {
        if ( v20 != -1073741772 && v20 != -1073741811 && v20 != -1073741637 )
          break;
      }
      if ( (unsigned int)++v17 >= 8 )
        goto LABEL_47;
    }
    v9 = v20;
LABEL_47:
    if ( v9 < 0 )
    {
      v5 = 0;
      goto LABEL_78;
    }
    v30 = 0;
    v31 = 0;
    v29 = 0;
    v21 = CmGetDeviceMappedPropertyKeys(a1, v3, v32, 1, 0, 0, &v31);
    if ( v21 == -1073741789 )
    {
      while ( 1 )
      {
        v22 = v31;
        if ( RtlULongLongToULong(20 * v31, (20 * (unsigned __int64)v31) >> 32, &v29) < 0 )
          break;
        if ( v30 )
          ExFreePoolWithTag(v30);
        v23 = ExAllocatePoolWithTag(1, v29, 1380994640);
        v24 = v23;
        v30 = v23;
        if ( !v23 )
        {
          v21 = -1073741801;
          goto LABEL_59;
        }
        v21 = CmGetDeviceMappedPropertyKeys(a1, v3, v32, 1, v23, v22, &v31);
        if ( v21 != -1073741789 )
        {
          v24 = v30;
          goto LABEL_58;
        }
      }
      v21 = -1073741811;
    }
    else
    {
      v24 = 0;
LABEL_58:
      v22 = v31;
LABEL_59:
      if ( !v21 || v21 == -1073741275 )
      {
        v25 = 0;
        if ( v22 )
        {
          v26 = v24;
          while ( 1 )
          {
            v27 = CmSetDeviceMappedProperty((int)a1, v34, v32, 0, v26, 0, 0, 0);
            if ( v27 )
            {
              if ( v27 != -1073741275 && v27 != -1073741790 && v27 != -1073741802 && v27 != -1073741637 )
                break;
            }
            ++v25;
            v26 += 20;
            if ( v25 >= v22 )
              goto LABEL_73;
          }
          v9 = v27;
LABEL_73:
          v3 = v34;
        }
        if ( v9 >= 0 )
        {
          v9 = CmDeleteDeviceRegKey((int)a1, (int)v3, 16, 0);
          if ( v9 >= 0 )
            CmRaiseDeleteEvent(a1, v3, 1);
        }
        goto LABEL_62;
      }
    }
    v9 = v21;
LABEL_62:
    v5 = v30;
LABEL_78:
    if ( v8 )
      ExFreePoolWithTag((unsigned int)v8);
LABEL_80:
    if ( v7 )
      ExFreePoolWithTag((unsigned int)v7);
    if ( v5 )
      ExFreePoolWithTag(v5);
  }
LABEL_84:
  if ( v32 )
    ZwClose();
  return v9;
}
