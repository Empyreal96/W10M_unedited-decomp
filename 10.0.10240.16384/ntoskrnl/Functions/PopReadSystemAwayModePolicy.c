// PopReadSystemAwayModePolicy 
 
int PopReadSystemAwayModePolicy()
{
  char v0; // r4
  int result; // r0
  int v2; // [sp+8h] [bp-30h] BYREF
  char v3[8]; // [sp+10h] [bp-28h] BYREF
  int v4[5]; // [sp+18h] [bp-20h] BYREF

  v0 = 0;
  if ( byte_61EC12 && dword_60E1F0 )
    v0 = 1;
  result = PopOpenPowerKey((int)&v2);
  if ( result >= 0 )
  {
    if ( byte_61EC12 )
    {
      RtlInitUnicodeString((unsigned int)v3, L"AwayModeEnabled");
      memset(v4, 0, sizeof(v4));
      if ( ZwQueryValueKey() >= 0 && v4[1] == 4 && v4[2] == 4 && v4[3] )
        v0 = 1;
    }
    result = ZwClose();
  }
  byte_61EC10 = v0;
  return result;
}
