// ExQuerySystemLockInformation 
 
int __fastcall ExQuerySystemLockInformation(_DWORD *a1, unsigned int a2, unsigned int *a3)
{
  unsigned int v3; // r7
  int v7; // r5
  int v8; // r0
  int **v9; // r8
  int v10; // r0
  unsigned int v11; // r2
  unsigned int v12; // r1
  int *v13; // r2
  unsigned int v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r2
  int v18; // [sp+0h] [bp-20h]
  int vars4; // [sp+24h] [bp+4h]

  v3 = 4;
  if ( a2 >= 4 )
  {
    v7 = 0;
    v8 = ExPageLockHandle;
    *a1 = 0;
    v9 = (int **)(a1 + 1);
    MmLockPagableSectionByHandle(v8);
    v18 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockSharedAtDpcLevelInstrumented((unsigned int *)&ExpResourceSpinLock);
    }
    else
    {
      v10 = ExpResourceSpinLock & 0x7FFFFFFF;
      v11 = (ExpResourceSpinLock & 0x7FFFFFFF) + 1;
      do
        v12 = __ldrex((unsigned int *)&ExpResourceSpinLock);
      while ( v12 == v10 && __strex(v11, (unsigned int *)&ExpResourceSpinLock) );
      __dmb(0xBu);
      if ( v12 != v10 )
        ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&ExpResourceSpinLock);
    }
    v13 = (int *)ExpSystemResourcesList;
    if ( (int *)ExpSystemResourcesList != &ExpSystemResourcesList )
    {
      while ( 1 )
      {
        v3 += 36;
        ++*a1;
        if ( v3 < 0x24 )
          break;
        if ( a2 >= v3 )
        {
          *((_WORD *)v9 + 2) = 1;
          *v9 = v13;
          *((_WORD *)v9 + 3) = 0;
          if ( (v13[7] & 2) != 0 )
          {
            v14 = v13[6] & 0xFFFFFFFC;
          }
          else
          {
            v14 = v13[6];
            if ( (v14 & 3) != 0 )
              v14 = 0;
          }
          if ( v14 )
            v9[2] = *(int **)(v14 + 880);
          else
            v9[2] = 0;
          v9[3] = (int *)v13[8];
          v9[4] = (int *)v13[9];
          v9[7] = (int *)v13[10];
          v9[8] = (int *)v13[11];
          v9 += 9;
        }
        else
        {
          v7 = -1073741820;
        }
        v13 = (int *)*v13;
        if ( v13 == &ExpSystemResourcesList )
          goto LABEL_25;
      }
      v7 = -1073741675;
    }
LABEL_25:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented((unsigned int *)&ExpResourceSpinLock, vars4);
    }
    else
    {
      __dmb(0xBu);
      do
        v15 = __ldrex((unsigned int *)&ExpResourceSpinLock);
      while ( __strex(v15 & 0xBFFFFFFF, (unsigned int *)&ExpResourceSpinLock) );
      __dmb(0xBu);
      do
        v16 = __ldrex((unsigned int *)&ExpResourceSpinLock);
      while ( __strex(v16 - 1, (unsigned int *)&ExpResourceSpinLock) );
    }
    KfLowerIrql(v18);
    MmUnlockPagableImageSection(ExPageLockHandle);
  }
  else
  {
    v7 = -1073741820;
  }
  if ( a3 )
    *a3 = v3;
  return v7;
}
