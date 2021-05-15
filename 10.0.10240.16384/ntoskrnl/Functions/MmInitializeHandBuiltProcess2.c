// MmInitializeHandBuiltProcess2 
 
int __fastcall MmInitializeHandBuiltProcess2(int a1)
{
  _BYTE v3[48]; // [sp-4h] [bp-30h] BYREF

  MiGetWsAndMakePageTablesNx();
  KiStackAttachProcess(a1, 0, (int)v3);
  if ( (unsigned int)(MmHighestUserAddress - 0x10000) > 0x7FFE0000 )
    return sub_81AEF0();
  KiUnstackDetachProcess((unsigned int)v3, 0);
  if ( (MmTrackLockedPages & 1) != 0 && (MmTrackLockedPages & 0x10000000) == 0 )
    MiInitializeLockedPagesTracking(a1);
  return 0;
}
