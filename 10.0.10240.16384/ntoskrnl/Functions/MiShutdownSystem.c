// MiShutdownSystem 
 
int MiShutdownSystem()
{
  __int16 *v0; // r5
  int v1; // r0
  int v2; // r4
  int v3; // r0
  int v4; // r0
  unsigned int i; // r4
  int v6; // r10
  int *j; // r4
  unsigned int v8; // r6
  int v9; // r0
  int v10; // r9
  unsigned int v11; // r0
  int v12; // r6
  int v13; // r4
  int v14; // r0
  int v16; // [sp+0h] [bp-20h]

  v0 = MiSystemPartition;
  if ( !dword_634350 )
  {
    v1 = CcNotifyWriteBehind(2);
    v2 = MmZeroPageFileAtShutdown(v1);
    MmFlushAllFilesystemPages(0);
    dword_634350 = 1;
    v3 = KeSetEvent((int)&unk_63F778, 0, 0);
    if ( v2 == 1 )
    {
      if ( (MiFlags & 4) == 0 )
        v3 = MmLockPagableSectionByHandle(ExPageLockHandle);
      MiZeroAllPageFiles(v3);
      if ( (MiFlags & 4) == 0 )
        MmUnlockPagableImageSection(ExPageLockHandle);
    }
  }
  if ( PopShutdownCleanly )
  {
    dword_632E18 = -1;
    v4 = KeSetEvent((int)&unk_63F9F8, 0, 0);
    for ( i = 0; i < 0x1F4; ++i )
    {
      if ( (int *)dword_63FA68 == &dword_63FA68 )
        break;
      v4 = KeDelayExecutionThread(0, 0, (unsigned int *)MiShortTime);
      if ( !dword_632E18 )
      {
        dword_632E18 = -1;
        v4 = KeSetEvent((int)&unk_63F9F8, 0, 0);
      }
    }
    v6 = MmAcquireLoadLock(v4);
    for ( j = (int *)PsLoadedModuleList; j != &PsLoadedModuleList; j = (int *)*j )
    {
      v8 = j[19];
      if ( v8 != 1 && v8 != -2 && (v8 & 1) == 0 )
      {
        v16 = *(_DWORD *)v8 + 1;
        v9 = ExAllocatePoolWithTag(512, 4 * v16, 1413770573);
        v10 = v9;
        if ( !v9 )
        {
          PopShutdownCleanly = 0;
          break;
        }
        memmove(v9, v8, 4 * v16);
        ExFreePoolWithTag(v8);
        j[19] = v10;
      }
      v11 = j[10];
      if ( v11 )
      {
        ExFreePoolWithTag(v11);
        j[10] = 0;
      }
    }
    MmReleaseLoadLock(v6);
    v12 = dword_64050C;
    __dmb(0xBu);
    for ( ; v12; --v12 )
    {
      v13 = *((_DWORD *)v0 + 900);
      if ( (*(_WORD *)(v13 + 96) & 0x40) == 0 )
      {
        ExFreePoolWithTag(*(_DWORD *)(v13 + 60));
        v14 = *(_DWORD *)(v13 + 112);
        *(_DWORD *)(v13 + 60) = 0;
        ObCloseHandle(v14);
      }
      v0 += 2;
    }
  }
  return 1;
}
