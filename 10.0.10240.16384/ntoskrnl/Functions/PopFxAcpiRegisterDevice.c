// PopFxAcpiRegisterDevice 
 
int __fastcall PopFxAcpiRegisterDevice(int a1, int a2, int a3, int *a4, _DWORD *a5)
{
  int v6; // r0
  int v7; // r8
  int v8; // r9
  int v9; // r5
  int v10; // r7
  int v11; // r3
  int v12; // r4
  int v13; // r0
  int v14; // r1
  int v15; // r3
  int v17; // [sp+8h] [bp-40h] BYREF
  _DWORD *v18; // [sp+Ch] [bp-3Ch]
  int v19; // [sp+10h] [bp-38h]
  _DWORD v20[3]; // [sp+18h] [bp-30h] BYREF
  int v21; // [sp+24h] [bp-24h]
  int v22; // [sp+28h] [bp-20h]

  v17 = 0;
  v18 = (_DWORD *)a3;
  v19 = a2;
  v6 = PopFxCreateDeviceCommon(a1, a2, a3, 4, &v17);
  v7 = v17;
  v8 = v6;
  if ( v6 < 0 )
    goto LABEL_7;
  v9 = v18[1];
  v10 = v18[3];
  v11 = v18[4];
  v20[0] = *v18;
  v20[1] = v9;
  v21 = v10;
  v12 = v19;
  v22 = v11;
  v20[2] = v17;
  v13 = PopPluginAcpiNotificationStrict(v19, 3, v20);
  if ( !v21 )
    goto LABEL_5;
  PopFxInsertAcpiDevice(v13, v14, v7);
  if ( v21 )
  {
    *(_DWORD *)(v7 + 44) = v12;
    v15 = v21;
    *a4 = v7;
    *(_DWORD *)(v7 + 48) = v15;
    *a5 = v21;
  }
  else
  {
LABEL_5:
    v8 = -1073741823;
    *a5 = 0;
    *a4 = 0;
  }
  if ( v8 < 0 )
  {
LABEL_7:
    if ( v7 )
    {
      *(_DWORD *)(v7 + 44) = 0;
      *(_DWORD *)(v7 + 48) = 0;
      PopFxDestroyDeviceCommon(v7);
    }
  }
  return v8;
}
