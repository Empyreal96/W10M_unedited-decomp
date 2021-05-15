// _CmSetDeviceMappedPropertyFromInstanceKeyRegValue 
 
int __fastcall CmSetDeviceMappedPropertyFromInstanceKeyRegValue(int a1, int a2, int a3, unsigned int a4, int (*a5)[5], char *a6)
{
  int v7; // r3
  int v8; // r4
  int v9; // r7
  int (**v10)[5]; // r9
  unsigned int i; // r8
  int (**v13)[5]; // r6
  unsigned int v14; // r1
  int (*v15)[5]; // t1
  __int64 v16; // kr00_8
  int v17; // r0
  int v19; // [sp+10h] [bp-30h] BYREF
  BOOL v20; // [sp+14h] [bp-2Ch] BYREF
  int v21; // [sp+18h] [bp-28h]
  int v22; // [sp+1Ch] [bp-24h]

  v7 = *(_DWORD *)(a4 + 16);
  v8 = 0;
  v9 = 0;
  v10 = &off_8C94D0;
  v20 = v7;
  v21 = a2;
  v22 = a1;
  v19 = 0;
  for ( i = 0; i < 2; ++i )
  {
    v13 = v10;
    v15 = *v10;
    v10 += 4;
    v14 = (unsigned int)v15;
    if ( v7 == (*v15)[4] )
    {
      if ( !memcmp(a4, v14, 16) )
        break;
      v7 = v20;
    }
    v13 = 0;
  }
  if ( !v13 )
    return -1073741264;
  if ( a5 != v13[1] )
    return -1073741811;
  if ( a3 )
    goto LABEL_13;
  v8 = CmOpenDeviceRegKey(v22, v21, 16, 0, 2, 0, (int)&v19, 0);
  if ( v8 >= 0 )
  {
    v9 = v19;
LABEL_13:
    v16 = *((_QWORD *)v13 + 1);
    if ( *(_DWORD *)(a4 + 16) == 2 && !memcmp(a4, (unsigned int)DEVPKEY_Device_Reported, 16) )
    {
      v20 = *a6 == -1;
      if ( !a3 )
        a3 = v9;
      v17 = PnpCtxRegSetValue(0, a3, v16, SHIDWORD(v16), (int)&v20, 4);
    }
    else
    {
      if ( !a3 )
        a3 = v9;
      v17 = RegRtlSetValue(a3, (unsigned __int16 *)v16);
    }
    if ( v17 == -1073741444 )
    {
      v8 = -1073741810;
    }
    else if ( v17 < 0 )
    {
      v8 = v17;
    }
  }
  if ( v19 )
    ZwClose();
  return v8;
}
