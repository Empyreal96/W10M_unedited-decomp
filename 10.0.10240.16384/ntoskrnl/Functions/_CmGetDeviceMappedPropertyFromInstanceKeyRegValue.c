// _CmGetDeviceMappedPropertyFromInstanceKeyRegValue 
 
int __fastcall CmGetDeviceMappedPropertyFromInstanceKeyRegValue(int a1, int a2, int a3, unsigned int a4, _DWORD *a5, _BYTE *a6, unsigned int a7, _DWORD *a8)
{
  int v8; // r4
  int v9; // r9
  int (**v11)[5]; // r10
  unsigned int v12; // r8
  int v13; // r2
  int (**v14)[5]; // r7
  unsigned int v15; // r1
  int (*v16)[5]; // t1
  int v17; // r5
  unsigned __int16 *v18; // r8
  int v19; // r3
  int v20; // r0
  unsigned int v21; // [sp+10h] [bp-40h] BYREF
  _BYTE *v22; // [sp+14h] [bp-3Ch]
  int v23; // [sp+18h] [bp-38h] BYREF
  int v24; // [sp+1Ch] [bp-34h] BYREF
  int v25; // [sp+20h] [bp-30h] BYREF
  int v26; // [sp+24h] [bp-2Ch]
  int v27; // [sp+28h] [bp-28h]
  int v28; // [sp+2Ch] [bp-24h]

  v21 = a4;
  v23 = 0;
  v26 = a3;
  v27 = a2;
  *a5 = 0;
  v8 = 0;
  v28 = a1;
  *a8 = 0;
  v9 = 0;
  v24 = 0;
  v22 = a6;
  if ( !a6 )
    return sub_7E1450();
  if ( !a7 )
    v22 = 0;
  v11 = &off_8C94D0;
  v12 = 0;
  v13 = *(_DWORD *)(v21 + 16);
  v25 = v13;
  do
  {
    v14 = v11;
    v16 = *v11;
    v11 += 4;
    v15 = (unsigned int)v16;
    if ( v13 == (*v16)[4] )
    {
      a1 = memcmp(v21, v15, 16);
      if ( !a1 )
        break;
      v13 = v25;
    }
    ++v12;
    v14 = 0;
  }
  while ( v12 < 2 );
  v17 = v26;
  if ( v14 )
  {
    if ( !v26 )
    {
      a1 = CmOpenDeviceRegKey(v28, v27, 16, 0, 1, 0, (int)&v24, 0);
      v8 = a1;
      if ( a1 < 0 )
        goto LABEL_23;
      v9 = v24;
    }
    v18 = (unsigned __int16 *)v14[2];
    if ( *(_DWORD *)(v21 + 16) != 2 || (a1 = memcmp(v21, (unsigned int)DEVPKEY_Device_Reported, 16)) != 0 )
    {
      v21 = a7;
      if ( !v17 )
        v17 = v9;
      v20 = PnpCtxRegQueryValue(a1, v17, v18, &v23, (int)v22, &v21);
      if ( v20 != -1073741772 && v20 != -1073741444 )
      {
        if ( !v20 || v20 == -1073741789 )
        {
          *a8 = v21;
          *a5 = v14[1];
          if ( v20 || !a7 )
            v8 = -1073741789;
        }
        else
        {
          v8 = v20;
        }
        goto LABEL_23;
      }
    }
    else
    {
      v25 = 0;
      v21 = 4;
      if ( !v17 )
        v17 = v9;
      if ( PnpCtxRegQueryValue(0, v17, v18, &v23, (int)&v25, &v21) >= 0 && v23 == 4 && v21 == 4 )
        v19 = v25;
      else
        v19 = 0;
      if ( v19 )
      {
        *a8 = 1;
        *a5 = 17;
        if ( a7 )
          *v22 = -1;
        else
          v8 = -1073741789;
        goto LABEL_23;
      }
    }
    v8 = -1073741275;
LABEL_23:
    if ( v24 )
      ZwClose();
    return v8;
  }
  return -1073741264;
}
