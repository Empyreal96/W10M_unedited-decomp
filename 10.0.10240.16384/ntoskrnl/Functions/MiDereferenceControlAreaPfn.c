// MiDereferenceControlAreaPfn 
 
int __fastcall MiDereferenceControlAreaPfn(unsigned int *a1, int a2, char a3)
{
  int v5; // r9
  int v6; // r5
  unsigned int *v7; // r6
  int v8; // lr
  int result; // r0
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  int v12; // r3
  int v13; // r3
  unsigned int v14; // r1
  unsigned __int8 *v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r1
  unsigned int v18; // r2
  void **v19; // r0
  unsigned int v20; // r1
  int v21; // lr
  unsigned int v22; // r0
  int v23; // [sp+8h] [bp-20h]

  v5 = a2;
  if ( (a1[7] & 0x20) != 0 || !a1[8] )
    v6 = 0;
  else
    v6 = a2;
  v7 = a1 + 9;
  if ( (a3 & 2) != 0 )
  {
    v8 = 17;
    v23 = 17;
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_5382DC();
    v10 = (unsigned __int8 *)a1 + 39;
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | 0x80, v10) );
    __dmb(0xBu);
    if ( v11 >> 7 )
    {
      ExpWaitForSpinLockExclusiveAndAcquire(a1 + 9);
      v8 = 17;
    }
    while ( 1 )
    {
      result = *v7;
      if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (result & 0x40000000) == 0 )
      {
        do
          v14 = __ldrex(v7);
        while ( v14 == result && __strex(result | 0x40000000, v7) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  else
  {
    v8 = KfRaiseIrql(2);
    v23 = v8;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1 + 9);
    }
    else
    {
      v15 = (unsigned __int8 *)a1 + 39;
      do
        v16 = __ldrex(v15);
      while ( __strex(v16 | 0x80, v15) );
      __dmb(0xBu);
      if ( v16 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(a1 + 9);
      while ( 1 )
      {
        result = *v7;
        if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (result & 0x40000000) == 0 )
        {
          do
            v17 = __ldrex(v7);
          while ( v17 == result && __strex(result | 0x40000000, v7) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
  }
  if ( v6 )
  {
    v12 = *(_DWORD *)(v6 + 64) - 1;
    *(_DWORD *)(v6 + 64) = v12;
    if ( !v12 && !*(_DWORD *)(v6 + 60) && (*(_WORD *)(v5 + 18) & 1) == 0 && (*(_WORD *)(v6 + 18) & 8) != 0 )
    {
      MiRemoveUnusedSubsection(v6);
      result = MiInsertUnusedSubsection(v6, 1);
      v8 = v23;
    }
  }
  v13 = a1[4] - 1;
  a1[4] = v13;
  if ( (a3 & 1) != 0 && !v13 && !a1[5] && !a1[3] )
  {
    v18 = a1[7];
    if ( (v18 & 0x101) == 0 )
    {
      a1[7] = v18 | 1;
      MiClearFilePointer(a1);
      MiRemoveUnusedSegment(a1);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_632D80);
      }
      else
      {
        do
          v20 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
        while ( __strex(v20 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
        __dmb(0xBu);
        if ( v20 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632D80);
        while ( 1 )
        {
          v21 = dword_632D80;
          if ( (dword_632D80 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (dword_632D80 & 0x40000000) == 0 )
          {
            do
              v22 = __ldrex((unsigned int *)&dword_632D80);
            while ( v22 == v21 && __strex(v21 | 0x40000000, (unsigned int *)&dword_632D80) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      v19 = (void **)dword_63FA24;
      a1[1] = (unsigned int)&unk_63FA20;
      a1[2] = (unsigned int)v19;
      if ( *v19 != &unk_63FA20 )
        __fastfail(3u);
      *v19 = a1 + 1;
      dword_63FA24 = (int)(a1 + 1);
      a1[7] |= 0x8000000u;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632D80);
      }
      else
      {
        __dmb(0xBu);
        dword_632D80 = 0;
      }
      result = KeReleaseSemaphoreEx((int)&unk_63FA0C, 0, 1, 0, 0);
      v8 = v23;
    }
  }
  if ( v8 == 17 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      result = ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 9);
    }
    else
    {
      __dmb(0xBu);
      *v7 = 0;
    }
  }
  else
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 9);
      v8 = v23;
    }
    else
    {
      __dmb(0xBu);
      *v7 = 0;
    }
    result = KfLowerIrql(v8);
  }
  return result;
}
