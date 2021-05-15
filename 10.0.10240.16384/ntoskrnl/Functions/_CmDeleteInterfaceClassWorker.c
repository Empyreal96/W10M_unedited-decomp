// _CmDeleteInterfaceClassWorker 
 
int __fastcall CmDeleteInterfaceClassWorker(int a1, int a2, __int16 a3)
{
  int v3; // r7
  int v4; // r4
  int v6; // r0
  int v7; // r5
  int *v8; // r6
  int v9; // t1
  int v10; // r0
  int v11; // r5
  unsigned int v12; // r8
  int v13; // r0
  unsigned int v14; // r6
  int v15; // r7
  int v16; // r0
  int v19; // [sp+1Ch] [bp-3Ch] BYREF
  unsigned int v20; // [sp+20h] [bp-38h] BYREF
  int v21; // [sp+24h] [bp-34h] BYREF
  int v22[12]; // [sp+28h] [bp-30h] BYREF

  v21 = 0;
  v3 = a1;
  v4 = 0;
  if ( a3 )
    return -1073741811;
  v6 = CmGetMatchingFilteredDeviceInterfaceList(a1, a2, 0, 0, 0, 0, 0, 0, (int)&v21, 0);
  if ( v6 == -1073741789 )
    return -1073741535;
  if ( v6 )
    return v6;
  v22[0] = 832;
  v22[1] = 576;
  v7 = 0;
  v22[2] = 320;
  v8 = v22;
  while ( 1 )
  {
    v9 = *v8++;
    v10 = CmDeleteInterfaceClassRegKey(v3, a2, v9);
    if ( v10 )
    {
      if ( v10 != -1073741772 && v10 != -1073741811 && v10 != -1073741637 )
        break;
    }
    if ( (unsigned int)++v7 >= 3 )
      goto LABEL_15;
  }
  v4 = v10;
  if ( v10 < 0 )
    return v4;
LABEL_15:
  v11 = 0;
  v19 = 0;
  v20 = 0;
  v12 = 0;
  do
  {
    v13 = CmGetInterfaceClassMappedPropertyKeys(v3, a2, 0, 1, v11, v12, &v20);
    v12 = v20;
    if ( v13 != -1073741789 )
      goto LABEL_22;
    if ( RtlULongLongToULong(20 * v20, (20 * (unsigned __int64)v20) >> 32, &v19) < 0 )
    {
      v13 = -1073741811;
      goto LABEL_24;
    }
    if ( v11 )
      ExFreePoolWithTag(v11);
    v11 = ExAllocatePoolWithTag(1, v19, 1380994640);
  }
  while ( v11 );
  v13 = -1073741801;
LABEL_22:
  if ( v13 && v13 != -1073741275 )
  {
LABEL_24:
    v4 = v13;
    goto LABEL_42;
  }
  v14 = 0;
  if ( v12 )
  {
    v15 = v11;
    while ( 1 )
    {
      v16 = CmSetInterfaceClassMappedProperty(a1, a2, 0, 0, v15, 0, 0, 0);
      if ( v16 )
      {
        if ( v16 != -1073741275 && v16 != -1073741790 && v16 != -1073741802 && v16 != -1073741637 )
          break;
      }
      ++v14;
      v15 += 20;
      if ( v14 >= v12 )
        goto LABEL_36;
    }
    v4 = v16;
LABEL_36:
    v3 = a1;
  }
  if ( v4 >= 0 )
  {
    v13 = CmDeleteInterfaceClassRegKey(v3, a2, 64);
    if ( v13 && v13 != -1073741772 && v13 != -1073741811 )
      goto LABEL_24;
    CmRaiseDeleteEvent(v3, a2, 4);
  }
LABEL_42:
  if ( v11 )
    ExFreePoolWithTag(v11);
  return v4;
}
