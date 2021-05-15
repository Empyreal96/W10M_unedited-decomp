// KiProcessSecondarySignalList 
 
_DWORD *KiProcessSecondarySignalList()
{
  int v0; // r6
  unsigned int v1; // r2
  int **v2; // r0
  int v3; // r2
  int *v5; // [sp+0h] [bp-18h] BYREF
  int **v6; // [sp+4h] [bp-14h]
  int vars4; // [sp+1Ch] [bp+4h]

  v6 = &v5;
  v5 = (int *)&v5;
  v0 = KfRaiseIrql(12);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&KiSecondarySignalListLock);
  }
  else
  {
    do
      v1 = __ldrex((unsigned int *)&KiSecondarySignalListLock);
    while ( __strex(1u, (unsigned int *)&KiSecondarySignalListLock) );
    __dmb(0xBu);
    if ( v1 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&KiSecondarySignalListLock);
  }
  if ( (int *)KiSecondarySignalList != &KiSecondarySignalList )
  {
    v2 = v6;
    if ( (int **)v5[1] != &v5 || *v6 != (int *)&v5 )
      __fastfail(3u);
    if ( *(int **)(KiSecondarySignalList + 4) != &KiSecondarySignalList
      || *(int **)dword_6218C4 != &KiSecondarySignalList )
    {
      __fastfail(3u);
    }
    *v6 = &KiSecondarySignalList;
    v6 = (int **)dword_6218C4;
    *(_DWORD *)dword_6218C4 = &v5;
    dword_6218C4 = (int)v2;
    v3 = KiSecondarySignalList;
    if ( *(int **)(KiSecondarySignalList + 4) != &KiSecondarySignalList || *v2 != &KiSecondarySignalList )
      __fastfail(3u);
    *v2 = (int *)KiSecondarySignalList;
    *(_DWORD *)(v3 + 4) = v2;
    KiSecondarySignalList = (int)&KiSecondarySignalList;
    dword_6218C4 = (int)&KiSecondarySignalList;
  }
  KiSecondarySignalDpcRunning = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&KiSecondarySignalListLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    KiSecondarySignalListLock = 0;
  }
  KfLowerIrql(v0);
  return KiProcessDisconnectList(&v5);
}
