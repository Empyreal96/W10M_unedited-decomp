// ExpAddTagForBigPages 
 
int __fastcall ExpAddTagForBigPages(unsigned int a1, int a2, int a3, int a4, unsigned __int16 a5, unsigned __int8 a6)
{
  int v6; // r8
  int v7; // r9
  int v9; // r0
  unsigned int v10; // r2
  unsigned int v11; // r1
  int v12; // r0
  unsigned int *v13; // r7
  unsigned int v14; // r6
  unsigned int v15; // r4
  unsigned int v16; // r1
  unsigned int v17; // r2
  unsigned int v18; // r2
  unsigned int v19; // r1
  unsigned int v20; // r2
  unsigned int v21; // r1
  int v22; // r0
  _DWORD *v23; // r4
  _DWORD *v24; // r0
  unsigned int v25; // r1
  int v26; // r0
  int v27; // r4
  _DWORD *v28; // r4
  unsigned int v29; // r1
  _DWORD *v30; // r0
  unsigned int v31; // r1
  unsigned int v32; // r2
  unsigned int v33; // r1
  unsigned int v34; // r2
  unsigned int v35; // r1
  _DWORD *v36; // [sp+4h] [bp-3Ch]
  unsigned int v37; // [sp+8h] [bp-38h]
  int v38; // [sp+Ch] [bp-34h]
  int v39; // [sp+10h] [bp-30h]

  v37 = 0;
  v38 = a4;
  v6 = a4;
  v39 = 162172 * ((a1 >> 12 >> 16) ^ (4 * ((unsigned __int8)(a1 >> 20) ^ (4 * (unsigned __int8)(a1 >> 12)))));
  while ( 1 )
  {
    while ( 1 )
    {
      v7 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
        return sub_546424();
      v9 = ExpLargePoolTableLock & 0x7FFFFFFF;
      v10 = (ExpLargePoolTableLock & 0x7FFFFFFF) + 1;
      do
        v11 = __ldrex((unsigned int *)&ExpLargePoolTableLock);
      while ( v11 == v9 && __strex(v10, (unsigned int *)&ExpLargePoolTableLock) );
      __dmb(0xBu);
      if ( v11 != v9 )
        ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&ExpLargePoolTableLock);
      if ( (v6 & 0x20) != 0 )
      {
        v12 = *(_DWORD *)(MmSessionSpace + 8380);
        v14 = *(_DWORD *)(MmSessionSpace + 8384);
        v13 = (unsigned int *)(MmSessionSpace + 8304);
      }
      else
      {
        v12 = PoolBigPageTable;
        v13 = (unsigned int *)&ExpPoolBigEntriesInUse;
        v14 = PoolBigPageTableSize;
      }
      if ( v12 && *v13 != v14 )
      {
        v15 = v12 + 16 * ((v14 - 1) & (v39 >> 2));
        while ( 1 )
        {
          v16 = *(_DWORD *)v15;
          if ( (*(_DWORD *)v15 & 1) != 0 )
          {
            do
              v17 = __ldrex((unsigned int *)v15);
            while ( v17 == v16 && __strex(a1, (unsigned int *)v15) );
            if ( v17 == v16 )
              break;
          }
          v15 += 16;
          ++v37;
          if ( v15 >= v12 + 16 * v14 )
            v15 = v12;
          if ( v15 == v12 + 16 * ((v14 - 1) & (v39 >> 2)) )
          {
            v6 = v38;
            goto LABEL_43;
          }
        }
        *(_DWORD *)(v15 + 4) = a2;
        *(_BYTE *)(v15 + 8) = a6;
        *(_DWORD *)(v15 + 8) = a6 | ((v38 & 0xFFF | (a5 << 12)) << 8);
        *(_DWORD *)(v15 + 12) = a3;
        do
          v18 = __ldrex(v13);
        while ( __strex(v18 + 1, v13) );
        if ( v37 < 0x10 || *v13 <= v14 >> 2 )
        {
          if ( (dword_682604 & 0x10000) == 0 )
          {
            __dmb(0xBu);
            do
              v19 = __ldrex((unsigned int *)&ExpLargePoolTableLock);
            while ( __strex(v19 & 0xBFFFFFFF, (unsigned int *)&ExpLargePoolTableLock) );
            __dmb(0xBu);
            do
              v20 = __ldrex((unsigned int *)&ExpLargePoolTableLock);
            while ( __strex(v20 - 1, (unsigned int *)&ExpLargePoolTableLock) );
            goto LABEL_30;
          }
        }
        else
        {
          if ( (dword_682604 & 0x210000) != 0 )
          {
            if ( ExpTryConvertSharedSpinLockExclusiveInstrumented(&ExpLargePoolTableLock) == 1 )
            {
LABEL_38:
              ExpResizeBigPageTable(v38);
              if ( (dword_682604 & 0x10000) != 0 )
              {
                ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&ExpLargePoolTableLock);
              }
              else
              {
                __dmb(0xBu);
                ExpLargePoolTableLock = 0;
              }
              KfLowerIrql(v7);
              v23 = v36;
              while ( v23 )
              {
                v24 = v23;
                v23 = (_DWORD *)*v23;
                ExFreePoolWithTag(v24, 0);
              }
              return 1;
            }
          }
          else
          {
            do
              v21 = __ldrex((unsigned __int8 *)&ExpLargePoolTableLock + 3);
            while ( __strex(v21 | 0x80, (unsigned __int8 *)&ExpLargePoolTableLock + 3) );
            __dmb(0xBu);
            if ( !(v21 >> 7) )
            {
              while ( 1 )
              {
                v22 = ExpLargePoolTableLock;
                if ( (ExpLargePoolTableLock & 0xBFFFFFFF) == -2147483647 )
                  break;
                if ( (ExpLargePoolTableLock & 0x40000000) == 0 )
                {
                  do
                    v35 = __ldrex((unsigned int *)&ExpLargePoolTableLock);
                  while ( v35 == v22 && __strex(v22 | 0x40000000, (unsigned int *)&ExpLargePoolTableLock) );
                  __dmb(0xBu);
                }
                __dmb(0xAu);
                __yield();
              }
              goto LABEL_38;
            }
          }
          if ( (dword_682604 & 0x10000) == 0 )
          {
            __dmb(0xBu);
            do
              v33 = __ldrex((unsigned int *)&ExpLargePoolTableLock);
            while ( __strex(v33 & 0xBFFFFFFF, (unsigned int *)&ExpLargePoolTableLock) );
            __dmb(0xBu);
            do
              v34 = __ldrex((unsigned int *)&ExpLargePoolTableLock);
            while ( __strex(v34 - 1, (unsigned int *)&ExpLargePoolTableLock) );
            goto LABEL_30;
          }
        }
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&ExpLargePoolTableLock);
LABEL_30:
        KfLowerIrql(v7);
        return 1;
      }
LABEL_43:
      if ( (dword_682604 & 0x210000) == 0 )
        break;
      if ( ExpTryConvertSharedSpinLockExclusiveInstrumented(&ExpLargePoolTableLock) )
        goto LABEL_47;
LABEL_53:
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&ExpLargePoolTableLock);
      }
      else
      {
        __dmb(0xBu);
        do
          v31 = __ldrex((unsigned int *)&ExpLargePoolTableLock);
        while ( __strex(v31 & 0xBFFFFFFF, (unsigned int *)&ExpLargePoolTableLock) );
        __dmb(0xBu);
        do
          v32 = __ldrex((unsigned int *)&ExpLargePoolTableLock);
        while ( __strex(v32 - 1, (unsigned int *)&ExpLargePoolTableLock) );
      }
      KfLowerIrql(v7);
    }
    do
      v25 = __ldrex((unsigned __int8 *)&ExpLargePoolTableLock + 3);
    while ( __strex(v25 | 0x80, (unsigned __int8 *)&ExpLargePoolTableLock + 3) );
    __dmb(0xBu);
    if ( v25 >> 7 )
      goto LABEL_53;
    while ( 1 )
    {
      v26 = ExpLargePoolTableLock;
      if ( (ExpLargePoolTableLock & 0xBFFFFFFF) == -2147483647 )
        break;
      if ( (ExpLargePoolTableLock & 0x40000000) == 0 )
      {
        do
          v29 = __ldrex((unsigned int *)&ExpLargePoolTableLock);
        while ( v29 == v26 && __strex(v26 | 0x40000000, (unsigned int *)&ExpLargePoolTableLock) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
LABEL_47:
    v27 = ExpResizeBigPageTable(v6);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&ExpLargePoolTableLock);
    }
    else
    {
      __dmb(0xBu);
      ExpLargePoolTableLock = 0;
    }
    KfLowerIrql(v7);
    if ( !v27 )
      break;
    v28 = v36;
    if ( v36 )
    {
      do
      {
        v30 = v28;
        v28 = (_DWORD *)*v28;
        ExFreePoolWithTag(v30, 0);
      }
      while ( v28 );
      v36 = 0;
    }
  }
  ++ExpBigTableExpansionFailed;
  return 0;
}
