// IovpCheckIrpForCriticalTracking 
 
int __fastcall IovpCheckIrpForCriticalTracking(int a1)
{
  int v2; // r0
  int v3; // r3
  int v4; // r4

  if ( (*(_DWORD *)(a1 + 8) & 0xC0000000) == 0 )
  {
    v2 = VfIrpDatabaseEntryFindAndLock(a1);
    v3 = *(_DWORD *)(a1 + 8);
    if ( v2 )
    {
      *(_DWORD *)(a1 + 8) = v3 | 0x40000000;
      goto LABEL_6;
    }
    *(_DWORD *)(a1 + 8) = v3 | 0x80000000;
    return 0;
  }
  if ( (*(_DWORD *)(a1 + 8) & 0xC0000000) != 0x40000000 )
    return 0;
  v2 = VfIrpDatabaseEntryFindAndLock(a1);
LABEL_6:
  if ( *(_DWORD *)(v2 + 140) )
  {
    v4 = 1;
  }
  else
  {
    v4 = 0;
    *(_DWORD *)(v2 + 36) |= 0x80000u;
  }
  VfIrpDatabaseEntryReleaseLock(v2);
  return v4;
}
