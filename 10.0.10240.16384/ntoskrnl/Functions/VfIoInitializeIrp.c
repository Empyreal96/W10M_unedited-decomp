// VfIoInitializeIrp 
 
int __fastcall VfIoInitializeIrp(int a1, int a2, int a3)
{
  int result; // r0
  int v7; // r5

  result = VfIrpDatabaseEntryFindAndLock(a1);
  v7 = result;
  if ( result )
  {
    if ( *(_DWORD *)(result + 140) )
      VfErrorReport1(784, a2, a1);
    if ( !a3 && (*(_DWORD *)(v7 + 36) & 0x200000) != 0 && (*(_BYTE *)(a1 + 39) & 1) != 0 )
      VfErrorReport1(525, a2, a1);
    if ( (*(_DWORD *)(a1 + 8) & 8) != 0 || (*(_DWORD *)(v7 + 36) & 0x1000) != 0 )
      VfErrorReport1(785, a2, a1);
    result = VfIrpDatabaseEntryReleaseLock(v7);
  }
  return result;
}
