// PipCheckComputerSupported 
 
BOOL __fastcall PipCheckComputerSupported(unsigned __int16 *a1)
{
  int v2; // r4
  __int16 v4[2]; // [sp+10h] [bp-48h] BYREF
  const __int16 *v5; // [sp+14h] [bp-44h]
  int v6; // [sp+18h] [bp-40h]
  int v7; // [sp+20h] [bp-38h]
  int v8; // [sp+24h] [bp-34h]
  __int16 *v9; // [sp+28h] [bp-30h]
  int v10; // [sp+2Ch] [bp-2Ch]
  int v11; // [sp+30h] [bp-28h]
  int v12; // [sp+34h] [bp-24h]

  v6 = 0;
  v4[1] = 120;
  v4[0] = 118;
  v5 = L"\\Registry\\Machine\\System\\HardwareConfig\\Current\\ComputerIds";
  v7 = 24;
  v8 = 0;
  v10 = 576;
  v9 = v4;
  v11 = 0;
  v12 = 0;
  v2 = ZwOpenKey();
  if ( v2 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v4, a1);
    v2 = ZwQueryValueKey();
    if ( v2 == -2147483643 )
      v2 = 0;
  }
  return v2 >= 0;
}
