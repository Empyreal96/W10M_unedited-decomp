// _CmDeleteInstallerClassWorker 
 
int __fastcall CmDeleteInstallerClassWorker(int a1, int a2, __int16 a3)
{
  int v3; // r4
  int v5; // r8
  int v6; // r0
  int v7; // r5
  int *v8; // r6
  int v9; // t1
  int v10; // r0
  unsigned int v11; // r5
  int i; // r0
  unsigned int v13; // r6
  int v14; // r0
  unsigned int v15; // r7
  unsigned int v16; // r8
  int v17; // r0
  unsigned int v19; // [sp+18h] [bp-40h] BYREF
  int v20; // [sp+1Ch] [bp-3Ch]
  int v21; // [sp+20h] [bp-38h] BYREF
  int v22; // [sp+24h] [bp-34h] BYREF
  int v23[12]; // [sp+28h] [bp-30h] BYREF

  v22 = 0;
  v3 = 0;
  v5 = a1;
  v20 = a1;
  if ( a3 )
    return -1073741811;
  v6 = CmGetMatchingFilteredDeviceList(a1, a2, 128, 0, 0, 0, 0, (int)&v22);
  if ( v6 == -1073741789 )
    return -1073741535;
  if ( v6 )
    return v6;
  v23[0] = 800;
  v23[1] = 544;
  v7 = 0;
  v23[2] = 288;
  v8 = v23;
  while ( 1 )
  {
    v9 = *v8++;
    v10 = CmDeleteInstallerClassRegKey(v5, a2, v9);
    if ( v10 )
    {
      if ( v10 != -1073741772 && v10 != -1073741811 && v10 != -1073741637 )
        break;
    }
    if ( (unsigned int)++v7 >= 3 )
      goto LABEL_15;
  }
  v3 = v10;
  if ( v10 < 0 )
    return v3;
LABEL_15:
  v19 = 0;
  v21 = 0;
  v11 = 0;
  for ( i = CmGetInstallerClassMappedPropertyKeys(v5, a2, 0, 1, 0, 0, &v19);
        i == -1073741789;
        i = CmGetInstallerClassMappedPropertyKeys(v5, a2, 0, 1, v14, v13, &v19) )
  {
    v13 = v19;
    if ( RtlULongLongToULong(20 * v19, (20 * (unsigned __int64)v19) >> 32, &v21) < 0 )
    {
      i = -1073741811;
      goto LABEL_25;
    }
    if ( v11 )
      ExFreePoolWithTag(v11);
    v14 = ExAllocatePoolWithTag(1, v21, 1380994640);
    v11 = v14;
    if ( !v14 )
    {
      i = -1073741801;
      goto LABEL_23;
    }
  }
  v13 = v19;
LABEL_23:
  if ( i && i != -1073741275 )
  {
LABEL_25:
    v3 = i;
    goto LABEL_44;
  }
  v15 = 0;
  if ( v13 )
  {
    v16 = v11;
    while ( 1 )
    {
      v17 = CmSetInstallerClassMappedProperty(v20, a2, 0, 0, v16, 0, 0, 0);
      if ( v17 )
      {
        if ( v17 != -1073741275 && v17 != -1073741790 && v17 != -1073741802 && v17 != -1073741637 )
          break;
      }
      ++v15;
      v16 += 20;
      if ( v15 >= v13 )
        goto LABEL_38;
    }
    v3 = v17;
LABEL_38:
    v5 = v20;
  }
  if ( v3 >= 0 )
  {
    i = CmDeleteInstallerClassRegKey(v5, a2, 32);
    if ( i && i != -1073741772 && i != -1073741811 )
      goto LABEL_25;
    CmRaiseDeleteEvent(v5, a2, 2);
  }
LABEL_44:
  if ( v11 )
    ExFreePoolWithTag(v11);
  return v3;
}
