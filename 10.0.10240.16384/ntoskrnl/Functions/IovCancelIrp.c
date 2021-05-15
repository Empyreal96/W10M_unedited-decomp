// IovCancelIrp 
 
int __fastcall IovCancelIrp(int a1)
{
  int result; // r0
  int v3; // r4

  IovpLogStackTrace(a1);
  result = VfIrpDatabaseEntryFindAndLock(a1);
  v3 = result;
  if ( result )
  {
    if ( *(_DWORD *)(result + 144) )
      ViWdBeforeCancelIrp();
    result = VfIrpDatabaseEntryReleaseLock(v3);
  }
  return result;
}
