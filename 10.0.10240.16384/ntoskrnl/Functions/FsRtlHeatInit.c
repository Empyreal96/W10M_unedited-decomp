// FsRtlHeatInit 
 
int __fastcall FsRtlHeatInit(_DWORD *a1, int a2, int a3)
{
  unsigned int v6; // r4
  int v7; // r5
  int v8; // r0
  int v9; // r3
  char v11[4]; // [sp+8h] [bp-90h] BYREF
  char *v12; // [sp+Ch] [bp-8Ch] BYREF
  __int16 v13; // [sp+10h] [bp-88h] BYREF
  __int16 v14; // [sp+12h] [bp-86h]
  const __int16 *v15; // [sp+14h] [bp-84h]
  int v16[2]; // [sp+18h] [bp-80h] BYREF
  __int16 v17[2]; // [sp+20h] [bp-78h] BYREF
  const __int16 *v18; // [sp+24h] [bp-74h]
  char v19; // [sp+28h] [bp-70h] BYREF

  *a1 = 0;
  a1[1] = 0;
  v11[0] = 0;
  v16[0] = 92;
  v12 = &v19;
  v18 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\TieredStorage";
  v17[0] = 128;
  v17[1] = 130;
  v15 = L"Enabled";
  v13 = 14;
  v14 = 16;
  if ( FsRtlpQueryValueKey(v17, &v13, v16, &v12, v11) < 0
    || (v6 = (unsigned int)v12, *(_DWORD *)&v12[*((_DWORD *)v12 + 2)]) )
  {
    v15 = L"MeasuredOperations";
    v13 = 36;
    v14 = 38;
    v8 = FsRtlpQueryValueKey(v17, &v13, v16, &v12, v11);
    v6 = (unsigned int)v12;
    if ( v8 < 0 )
      v9 = a1[1] | 7;
    else
      v9 = a1[1] | *(_DWORD *)&v12[*((_DWORD *)v12 + 2)] & 7;
    a1[1] = v9;
    v7 = FsRtlpHeatRegisterVolume(a2, a3, a1);
  }
  else
  {
    v7 = -1073741823;
  }
  if ( v11[0] )
    ExFreePoolWithTag(v6);
  return v7;
}
