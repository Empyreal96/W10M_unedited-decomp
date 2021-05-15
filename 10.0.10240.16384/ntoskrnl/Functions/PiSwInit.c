// PiSwInit 
 
int PiSwInit()
{
  int result; // r0
  int v1[4]; // [sp+8h] [bp-10h] BYREF

  RtlInitializeGenericTableAvl(
    (int)&PiSwDeviceInstanceTable,
    (unsigned int)PiSwDeviceCompareObjects,
    (unsigned int)PiSwAllocateGenericTableEntry,
    (int)PiSwFreeGenericTableEntry,
    0);
  RtlInitializeGenericTableAvl(
    (int)&PiSwBusRelationsTable,
    (unsigned int)PiSwBusRelationsCompareInstancePath,
    (unsigned int)PiSwAllocateGenericTableEntry,
    (int)PiSwFreeGenericTableEntry,
    0);
  result = ExInitializeResourceLite((int)&PiSwLockObj);
  if ( result >= 0 )
  {
    v1[0] = 3014700;
    v1[1] = (int)L"\\Driver\\SoftwareDevice";
    result = IoCreateDriver(v1, (int (__fastcall *)(_BYTE *, _DWORD))PiSwPdoDriverEntry);
  }
  return result;
}
