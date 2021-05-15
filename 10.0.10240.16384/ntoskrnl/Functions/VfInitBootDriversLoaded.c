// VfInitBootDriversLoaded 
 
int __fastcall VfInitBootDriversLoaded(int a1)
{
  int v2; // r0
  int v3; // r0
  int v4; // r0
  int result; // r0

  VfBugcheckTmpDataLock = 0;
  v2 = VfThunkInit();
  v3 = VfAvlInit(v2);
  VfTargetDriversInit(v3);
  if ( ViVerifierDriverAddedThunkListHead )
    VfObjectContextInit();
  v4 = VfThunkFindExportAddressAllTables(a1);
  if ( ViVerifierDriverAddedThunkListHead )
    result = sub_9698E4(v4);
  else
    result = VfDriverLoadBootDrivers(a1 + 16);
  return result;
}
