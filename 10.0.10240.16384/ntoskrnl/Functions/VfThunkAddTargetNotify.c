// VfThunkAddTargetNotify 
 
int __fastcall VfThunkAddTargetNotify(_DWORD *a1)
{
  int result; // r0

  if ( !ViThunkCreateSharedExportInformation(*a1, &VfRegularThunks, 20, &VfRegularThunksBitMapHeader, a1 + 2)
    || !ViThunkCreateSharedExportInformation(*a1, &VfPoolThunks, 20, &VfPoolThunksBitMapHeader, a1 + 3)
    || !ViThunkCreateSharedExportInformation(
          *a1,
          &VfOrderDependentThunks,
          24,
          &VfOrderDependentThunksBitMapHeader,
          a1 + 4)
    || (result = ViThunkCreateSharedExportInformation(*a1, &VfXdvThunks, 20, &VfXdvThunksBitMapHeader, a1 + 5)) == 0 )
  {
    result = sub_8E5180();
  }
  return result;
}
