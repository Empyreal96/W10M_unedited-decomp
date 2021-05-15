// VfIoFreeIrp 
 
int __fastcall VfIoFreeIrp(unsigned int a1, int a2)
{
  int v4; // r4
  _DWORD *v5; // r0
  _DWORD *v6; // r5
  int v7; // r3

  if ( (*(_BYTE *)(a1 + 39) & 0x21) == 33 )
    return 0;
  v5 = (_DWORD *)VfIrpDatabaseEntryFindAndLock(a1);
  v6 = v5;
  if ( !v5 )
    return 0;
  if ( *(_DWORD *)(a1 + 16) != a1 + 16 )
  {
    VfErrorReport1(524, a2, a1);
    VfIrpDatabaseEntryReleaseLock(v6);
    return 1;
  }
  v7 = v5[9];
  if ( v5[35] )
  {
    if ( (v7 & 0x400000) == 0 )
      VfErrorReport1(523, a2, a1);
    v4 = 1;
  }
  else
  {
    if ( (v7 & 0x200000) != 0 )
    {
      if ( (v7 & 8) != 0 )
      {
        *(_WORD *)a1 = 0;
        if ( (*(_BYTE *)(a1 + 39) & 1) != 0 )
        {
          PsReturnProcessNonPagedPoolQuota(v5[15], v5[14]);
          ObfDereferenceObjectWithTag(v6[15]);
        }
        VfIrpDatabaseEntryDereference(v6, 1);
        VfIrpDatabaseEntryReleaseLock(v6);
        ExFreePoolWithTag(a1);
        return 1;
      }
      VfIrpDatabaseEntryDereference(v5, 1);
    }
    v4 = 0;
  }
  VfIrpDatabaseEntryReleaseLock(v6);
  return v4;
}
