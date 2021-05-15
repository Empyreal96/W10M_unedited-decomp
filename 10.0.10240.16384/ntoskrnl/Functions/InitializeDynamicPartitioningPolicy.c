// InitializeDynamicPartitioningPolicy 
 
int InitializeDynamicPartitioningPolicy()
{
  int result; // r0
  int v1; // [sp+8h] [bp-20h]
  int v2; // [sp+Ch] [bp-1Ch]
  int v3; // [sp+10h] [bp-18h]
  char v4[16]; // [sp+18h] [bp-10h] BYREF

  RtlInitUnicodeString((unsigned int)v4, L"Kernel-DynamicPartitioningSupported");
  if ( ZwQueryLicenseValue() >= 0 )
    return sub_970578();
  RtlInitUnicodeString((unsigned int)v4, L"Kernel-PhysicalMemoryAddAllowed");
  result = ZwQueryLicenseValue();
  if ( result >= 0 && v1 == 4 && v2 == 4 )
  {
    if ( v3 )
      MmDynamicMemorySupported = 1;
  }
  return result;
}
