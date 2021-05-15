// PopThermalHandlePreviousShutdown 
 
int PopThermalHandlePreviousShutdown()
{
  int result; // r0
  int v1; // r4
  int v2; // [sp+10h] [bp-38h] BYREF
  char v3[8]; // [sp+18h] [bp-30h] BYREF
  char v4[20]; // [sp+28h] [bp-20h] BYREF

  result = PopOpenPowerKey((int)&v2);
  if ( result >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v3, L"ThermalShutdownOccurred");
    memset(v4, 0, sizeof(v4));
    v1 = v2;
    result = ZwQueryValueKey();
    if ( result < 0 )
    {
      if ( v1 )
        result = ZwClose();
    }
    else
    {
      result = sub_7F1CE4();
    }
  }
  return result;
}
