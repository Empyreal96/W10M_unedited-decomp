// IoRaiseInformationalHardError 
 
int __fastcall IoRaiseInformationalHardError(int a1, unsigned __int16 *a2, int a3)
{
  int v6; // r3
  _BYTE *v7; // r0
  int v8; // r5
  int v9; // r0
  __int16 v11; // r3
  int v12; // r0
  int v13; // r7
  int v14; // r0
  unsigned int v15; // r1
  int v16; // r8
  unsigned int v17; // r1
  unsigned int v18; // r0
  int v19; // r2
  int v20; // r6
  int v21; // r9
  unsigned int v22; // r0
  int v23; // r2
  int **v24; // r1
  int vars4; // [sp+2Ch] [bp+4h]

  if ( !IopInitSystemCompletedEnoughForReInitRoutines )
    return 0;
  v6 = a3 ? *(_DWORD *)(a3 + 960) : *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C0);
  if ( (v6 & 0x10) != 0 || a1 == -1073741283 || a1 == -1073741500 || a1 == 1073741848 || !a3 && dword_631A40 >= 25 )
    return 0;
  if ( dword_631A54 > 25 )
    return 0;
  v7 = (_BYTE *)ExAllocatePoolWithTag(512, 20);
  v8 = (int)v7;
  if ( !v7 )
    return 0;
  memset(v7, 0, 20);
  *(_DWORD *)(v8 + 8) = a1;
  if ( a2 && *a2 )
  {
    v9 = ExAllocatePoolWithTag(512, *a2);
    if ( !v9 )
    {
LABEL_15:
      ExFreePoolWithTag(v8);
      return 0;
    }
    *(_WORD *)(v8 + 12) = *a2;
    v11 = *a2;
    *(_DWORD *)(v8 + 16) = v9;
    *(_WORD *)(v8 + 14) = v11;
    memmove(v9, *((_DWORD *)a2 + 1), *a2);
  }
  if ( !a3 )
  {
    v16 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&dword_631A38);
    }
    else
    {
      do
        v17 = __ldrex((unsigned int *)&dword_631A38);
      while ( __strex(1u, (unsigned int *)&dword_631A38) );
      __dmb(0xBu);
      if ( v17 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&dword_631A38);
    }
    if ( dword_631A40 < 25 )
    {
      if ( !IopCurrentHardError
        || *(_DWORD *)(v8 + 8) != *(_DWORD *)(IopCurrentHardError + 8)
        || ((v18 = *(_DWORD *)(v8 + 16)) != 0 || *(_DWORD *)(IopCurrentHardError + 16))
        && ((v19 = *(unsigned __int16 *)(v8 + 12), v19 != *(unsigned __int16 *)(IopCurrentHardError + 12))
         || memcmp(v18, *(_DWORD *)(IopCurrentHardError + 16), v19)) )
      {
        v20 = dword_631A30;
        if ( (int *)dword_631A30 == &dword_631A30 )
        {
LABEL_50:
          v24 = (int **)dword_631A34;
          *(_DWORD *)v8 = &dword_631A30;
          *(_DWORD *)(v8 + 4) = v24;
          if ( *v24 != &dword_631A30 )
            __fastfail(3u);
          *v24 = (int *)v8;
          dword_631A34 = v8;
          KeReleaseSemaphore((int)algn_631A3C, 0, 1);
          if ( !byte_631A50 )
          {
            byte_631A50 = 1;
            ExQueueWorkItem(&IopHardError, 1);
          }
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented(&dword_631A38, vars4);
          }
          else
          {
            __dmb(0xBu);
            dword_631A38 = 0;
          }
          KfLowerIrql(v16);
          return 1;
        }
        v21 = *(_DWORD *)(v8 + 8);
        while ( 1 )
        {
          if ( v21 == *(_DWORD *)(v20 + 8) )
          {
            v22 = *(_DWORD *)(v8 + 16);
            if ( !v22 && !*(_DWORD *)(v20 + 16) )
              break;
            v23 = *(unsigned __int16 *)(v8 + 12);
            if ( v23 == *(unsigned __int16 *)(v20 + 12) && !memcmp(v22, *(_DWORD *)(v20 + 16), v23) )
              break;
          }
          v20 = *(_DWORD *)v20;
          if ( (int *)v20 == &dword_631A30 )
            goto LABEL_50;
        }
      }
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&dword_631A38, vars4);
    }
    else
    {
      __dmb(0xBu);
      dword_631A38 = 0;
    }
    KfLowerIrql(v16);
    goto LABEL_21;
  }
  v12 = ExAllocatePoolWithTag(512, 48);
  v13 = v12;
  if ( !v12 )
  {
LABEL_21:
    v14 = *(_DWORD *)(v8 + 16);
    if ( v14 )
      ExFreePoolWithTag(v14);
    goto LABEL_15;
  }
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)&dword_631A54);
  while ( __strex(v15 + 1, (unsigned int *)&dword_631A54) );
  __dmb(0xBu);
  KeInitializeApc(v12, a3, 0, (int)RtlpSysVolFree, 0, (int)IopRaiseInformationalHardError, 0, v8);
  KeInsertQueueApc(v13, 0, 0, 0);
  return 1;
}
