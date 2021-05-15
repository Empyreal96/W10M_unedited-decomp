// PopThermalWriteShutdownToRegistry 
 
int PopThermalWriteShutdownToRegistry()
{
  int result; // r0
  int v1; // r4
  int v2; // [sp+Ch] [bp-14h] BYREF
  char v3[16]; // [sp+10h] [bp-10h] BYREF

  result = PopOpenKey(&v2, L"Control\\Session Manager\\Power");
  if ( result >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v3, L"ThermalShutdownOccurred");
    v1 = v2;
    result = ZwSetValueKey();
    if ( v1 )
      result = ZwClose();
  }
  return result;
}
