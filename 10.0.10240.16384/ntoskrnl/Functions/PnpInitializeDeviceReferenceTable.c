// PnpInitializeDeviceReferenceTable 
 
_BYTE *PnpInitializeDeviceReferenceTable()
{
  PnpDeviceReferenceTableLock = 1;
  dword_630C24 = 0;
  unk_630C28 = 0;
  byte_630C2C = 1;
  byte_630C2D = 0;
  byte_630C2E = 4;
  dword_630C30 = 0;
  dword_630C38 = (int)&dword_630C34;
  dword_630C34 = (int)&dword_630C34;
  return RtlInitializeGenericTableAvl(
           (int)&PnpDeviceReferenceTable,
           (unsigned int)PnpCompareInstancePath,
           (unsigned int)PnpAllocateGenericTableEntry,
           (int)CMFFreeFn,
           0);
}
