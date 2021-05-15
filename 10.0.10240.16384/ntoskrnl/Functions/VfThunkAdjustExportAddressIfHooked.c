// VfThunkAdjustExportAddressIfHooked 
 
void __fastcall __spoils<R1,R2,R3,R12> VfThunkAdjustExportAddressIfHooked(int a1, int a2)
{
  int vars8[2]; // [sp+10h] [bp+8h] BYREF

  vars8[1] = a2;
  if ( !ViThunkAdjustExportAddressIfHooked(vars8, a2, &VfRegularThunks, 20)
    && !ViThunkAdjustExportAddressIfHooked(vars8, a2, &VfOrderDependentThunks, 24)
    && !ViThunkAdjustExportAddressIfHooked(vars8, a2, &VfMandatoryThunks, 20)
    && !ViThunkAdjustExportAddressIfHooked(vars8, a2, &VfPoolThunks, 20) )
  {
    ViThunkAdjustExportAddressIfHooked(vars8, a2, &VfXdvThunks, 20);
  }
}
