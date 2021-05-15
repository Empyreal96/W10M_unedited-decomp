// _CmDeleteDeviceInterfaceWorker 
 
int __fastcall CmDeleteDeviceInterfaceWorker(int a1, int a2, __int16 a3)
{
  int v3; // r7
  int v4; // r4
  int v6; // r3
  int v7; // r5
  int *v8; // r8
  int v9; // r6
  int v10; // t1
  int v11; // r0
  int v12; // r5
  unsigned int v13; // r8
  int v14; // r0
  unsigned int v15; // r6
  unsigned int v16; // r7
  int v17; // r0
  int v18; // r6
  int v21; // [sp+14h] [bp-3Ch] BYREF
  int v22; // [sp+18h] [bp-38h]
  unsigned int v23; // [sp+1Ch] [bp-34h] BYREF
  int v24[12]; // [sp+20h] [bp-30h] BYREF

  v3 = a2;
  v4 = 0;
  v22 = a1;
  if ( a3 )
    return -1073741811;
  v24[0] = 768;
  v24[1] = 512;
  v6 = 256;
  v7 = 0;
  v24[2] = 256;
  v8 = v24;
  while ( 1 )
  {
    v10 = *v8++;
    v9 = v10;
    v11 = CmDeleteDeviceInterfaceRegKey(a1, v3, v10 | 0x30, v6, 1);
    if ( v11 )
    {
      if ( v11 != -1073741772 && v11 != -1073741811 && v11 != -1073741637 )
        break;
    }
    v11 = CmDeleteDeviceInterfaceRegKey(a1, v3, v9 | 0x31, 0, 0);
    if ( v11 )
    {
      v6 = -1073741772;
      if ( v11 != -1073741772 && v11 != -1073741811 )
      {
        v6 = -1073741637;
        if ( v11 != -1073741637 )
        {
          v6 = -1073741535;
          if ( v11 != -1073741535 )
            break;
        }
      }
    }
    if ( (unsigned int)++v7 >= 3 )
      goto LABEL_16;
  }
  v4 = v11;
  if ( v11 < 0 )
    return v4;
LABEL_16:
  v12 = 0;
  v21 = 0;
  v13 = 0;
  v23 = 0;
  do
  {
    v14 = CmGetDeviceInterfaceMappedPropertyKeys(a1, v3, 0, 1, v12, v13, &v23);
    v13 = v23;
    if ( v14 != -1073741789 )
      goto LABEL_23;
    if ( RtlULongLongToULong(20 * v23, (20 * (unsigned __int64)v23) >> 32, &v21) < 0 )
    {
      v14 = -1073741811;
      goto LABEL_25;
    }
    if ( v12 )
      ExFreePoolWithTag(v12);
    v12 = ExAllocatePoolWithTag(1, v21, 1380994640);
  }
  while ( v12 );
  v14 = -1073741801;
LABEL_23:
  if ( v14 && v14 != -1073741275 )
  {
LABEL_25:
    v4 = v14;
    goto LABEL_47;
  }
  v15 = 0;
  if ( v13 )
  {
    v16 = v12;
    while ( 1 )
    {
      v17 = CmSetDeviceInterfaceMappedProperty(v22, a2, 0, 0, v16, 0, 0, 0);
      if ( v17 )
      {
        if ( v17 != -1073741275 && v17 != -1073741790 && v17 != -1073741802 && v17 != -1073741637 )
          break;
      }
      ++v15;
      v16 += 20;
      if ( v15 >= v13 )
        goto LABEL_37;
    }
    v4 = v17;
LABEL_37:
    v3 = a2;
  }
  if ( v4 >= 0 )
  {
    v18 = v22;
    v14 = CmDeleteDeviceInterfaceRegKey(v22, v3, 48, 1, 1);
    if ( v14 && v14 != -1073741772 && v14 != -1073741811 )
      goto LABEL_25;
    v14 = CmDeleteDeviceInterfaceRegKey(v18, v3, 49, 0, 0);
    if ( v14 )
    {
      if ( v14 != -1073741772 && v14 != -1073741811 && v14 != -1073741535 )
        goto LABEL_25;
    }
    CmRaiseDeleteEvent(v18, v3, 3);
  }
LABEL_47:
  if ( v12 )
    ExFreePoolWithTag(v12);
  return v4;
}
