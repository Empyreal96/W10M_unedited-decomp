// PnpIsDeviceInstanceEnabled 
 
int __fastcall PnpIsDeviceInstanceEnabled(int a1, unsigned __int16 *a2, int a3, int a4)
{
  unsigned int v4; // r6
  int v6; // r5
  int v7; // r0
  int v8; // r7
  _DWORD *v9; // r4
  int v10; // r2
  int v11; // r0
  char v13; // r3
  char v14; // r3
  int v15; // [sp+10h] [bp-30h] BYREF
  unsigned int v16; // [sp+14h] [bp-2Ch] BYREF
  int v17; // [sp+18h] [bp-28h] BYREF
  int v18; // [sp+1Ch] [bp-24h] BYREF
  int v19; // [sp+20h] [bp-20h]
  int varg_r0; // [sp+48h] [bp+8h]
  unsigned __int16 *varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]
  int varg_r3; // [sp+54h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v4 = 0;
  v16 = 0;
  v19 = a3;
  v6 = 1;
  v7 = PnpDeviceObjectFromDeviceInstance((int)a2);
  v8 = v7;
  if ( v7 )
    v9 = *(_DWORD **)(*(_DWORD *)(v7 + 176) + 20);
  else
    v9 = 0;
  if ( v9 && ((v10 = v9[67] & 0x2000) != 0 && v9[69] == 22 || v10 && v9[69] == 29)
    || (v11 = PnpUnicodeStringToWstr((int *)&v16, 0, a2), v4 = v16, v11 < 0) )
  {
    v6 = 0;
  }
  else
  {
    if ( !varg_r0 )
      return sub_7C9B90();
    v15 = 0;
    v17 = 4;
    if ( CmGetDeviceRegProp(PiPnpRtlCtx, v16, varg_r0, 11, (int)&v18, (int)&v15, (int)&v17) < 0 || v18 == 4 && v17 == 4 )
    {
      v13 = v15;
    }
    else
    {
      v13 = 0;
      v15 = 0;
    }
    if ( (v13 & 1) != 0 )
    {
      v14 = 1;
      v15 = 1;
    }
    else
    {
      PnpGetDeviceInstanceCsConfigFlags(a2);
      v14 = v15;
    }
    if ( (v14 & 7) != 0 )
    {
      v6 = 0;
      if ( v19 )
      {
        if ( v9 && v9[43] != 769 )
          PnpDisableDevice(v9, 22);
      }
    }
  }
  if ( v8 )
    ObfDereferenceObject(v8);
  if ( v4 )
    PnpUnicodeStringToWstrFree(v4, (int)a2);
  return v6;
}
