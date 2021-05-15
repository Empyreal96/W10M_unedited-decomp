// FsRtlGetTunnelParameterValue 
 
int __fastcall FsRtlGetTunnelParameterValue(int a1, _DWORD *a2)
{
  int v3; // r5
  __int16 v5[2]; // [sp+10h] [bp-A0h] BYREF
  const __int16 *v6; // [sp+14h] [bp-9Ch]
  int v7; // [sp+20h] [bp-90h]
  int v8; // [sp+24h] [bp-8Ch]
  __int16 *v9; // [sp+28h] [bp-88h]
  int v10; // [sp+2Ch] [bp-84h]
  int v11; // [sp+30h] [bp-80h]
  int v12; // [sp+34h] [bp-7Ch]
  char v13[8]; // [sp+38h] [bp-78h]
  int v14; // [sp+40h] [bp-70h]
  int v15; // [sp+44h] [bp-6Ch]

  v6 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\FileSystem";
  v5[0] = 122;
  v5[1] = 124;
  v7 = 24;
  v8 = 0;
  v10 = 64;
  v9 = v5;
  v11 = 0;
  v12 = 0;
  v3 = ZwOpenKey();
  if ( v3 >= 0 )
  {
    v3 = ZwQueryValueKey();
    if ( v3 == -2147483643 )
      return sub_818DAC();
    ZwClose();
    if ( v3 >= 0 )
    {
      if ( v15 )
        *a2 = *(_DWORD *)&v13[v14];
      else
        v3 = -1073741772;
    }
  }
  return v3;
}
