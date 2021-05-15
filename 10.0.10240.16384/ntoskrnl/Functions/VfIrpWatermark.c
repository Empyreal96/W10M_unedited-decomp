// VfIrpWatermark 
 
int __fastcall VfIrpWatermark(int a1, char a2)
{
  int result; // r0

  result = VfIrpDatabaseEntryFindAndLock(a1);
  if ( result )
  {
    if ( (a2 & 1) != 0 )
      *(_DWORD *)(result + 36) |= 0x100000u;
    if ( (a2 & 2) != 0 )
      *(_DWORD *)(result + 36) |= 0x20u;
    result = VfIrpDatabaseEntryReleaseLock(result);
  }
  return result;
}
