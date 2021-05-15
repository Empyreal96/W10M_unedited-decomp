// MiSplitReducedCommitClonePage 
 
int __fastcall MiSplitReducedCommitClonePage(int a1, unsigned int **a2)
{
  int v4; // r9
  int v5; // r1
  int v6; // r2
  int v7; // r5
  int v8; // r5
  int v9; // r2
  int **v10; // r1
  int *v11; // t1
  int v12; // r3
  unsigned int *v13; // r8
  unsigned int v14; // r3
  int v15; // r2
  int v16; // r0
  int v17; // r1
  int v18; // r2

  MiUnlockProbePacketWorkingSet(a1);
  *(_BYTE *)(a1 + 32) = 1;
  v4 = __mrc(15, 0, 13, 0, 3);
  LOCK_PAGE_TABLE_COMMITMENT(v4 & 0xFFFFFFC0, *(_DWORD *)(a1 + 40));
  v7 = MiChargeFullProcessCommitment(*(_DWORD *)(a1 + 40), 1);
  if ( v7 >= 0 )
  {
    v8 = 1;
    MiLockProbePacketWorkingSet(a1, v5, v6);
    v9 = 1;
    v10 = (int **)(a2 + 1);
    while ( 1 )
    {
      v11 = *v10--;
      v12 = *v11;
      if ( (*v11 & 2) == 0 )
        break;
      if ( !--v9 )
      {
        if ( (v12 & 0x400) == 0 )
        {
          v13 = *a2;
          v14 = **a2;
          if ( (v14 & 2) != 0 )
          {
            v15 = MmPfnDatabase + 24 * (v14 >> 12);
            if ( (*(_DWORD *)(v15 + 20) & 0x8000000) != 0 && *(int *)(v15 + 4) < 0 )
            {
              v16 = MiLocateCloneAddress(*(_DWORD *)(a1 + 40));
              if ( v16 )
              {
                if ( MEMORY[0xC0402140] > *(_QWORD *)(v16 + 40)
                  && MiCopyOnWriteEx(*(_DWORD *)a1, (unsigned int)v13, -1, *(unsigned __int8 *)(a1 + 44), 0) )
                {
                  v8 = 0;
                }
              }
            }
          }
        }
        break;
      }
    }
    MiUnlockProbePacketWorkingSet(a1);
    if ( v8 )
      MiReturnFullProcessCommitment(*(_DWORD *)(a1 + 40), 1);
    v7 = 0;
  }
  UNLOCK_PAGE_TABLE_COMMITMENT(v4 & 0xFFFFFFC0, *(_DWORD *)(a1 + 40));
  MiLockProbePacketWorkingSet(a1, v17, v18);
  return v7;
}
