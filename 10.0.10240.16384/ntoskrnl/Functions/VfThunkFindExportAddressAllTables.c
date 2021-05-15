// VfThunkFindExportAddressAllTables 
 
int __fastcall VfThunkFindExportAddressAllTables(int a1)
{
  ViThunkFindAllExportAddresses(a1, &VfRegularThunks, 20, &VfRegularThunksBitMapHeader);
  ViThunkFindAllExportAddresses(a1, &VfOrderDependentThunks, 24, &VfOrderDependentThunksBitMapHeader);
  ViThunkFindAllExportAddresses(a1, &VfPoolThunks, 20, VfPoolThunksBitMapHeader);
  ViThunkFindAllExportAddresses(a1, &VfMandatoryThunks, 20, 0);
  return ViThunkFindAllExportAddresses(a1, &VfXdvThunks, 20, &VfXdvThunksBitMapHeader);
}
