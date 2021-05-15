// ExGetBigPoolInfo 
 
int __fastcall ExGetBigPoolInfo(_DWORD *a1, unsigned int a2, int a3, unsigned int *a4)
{
  int v4; // r9
  _DWORD *v5; // r2
  unsigned int v6; // r10
  int *v7; // r3
  int v8; // r0
  unsigned int v9; // r1
  int v10; // r5
  int *v11; // r3
  int v12; // r1
  unsigned int v13; // r5
  int *i; // r2
  int v16; // r1
  unsigned int v17; // r3
  int v18; // r4
  int v19; // r2
  int v20; // r3
  unsigned int v21; // r5
  int v22; // r5
  unsigned int v23; // r1
  int v24; // r0
  unsigned int v25; // r1
  unsigned int v26; // r1
  int v27; // [sp+0h] [bp-60h]
  unsigned int v28; // [sp+4h] [bp-5Ch]
  int *v29; // [sp+10h] [bp-50h]
  int v30; // [sp+18h] [bp-48h]
  int v31; // [sp+1Ch] [bp-44h]
  _DWORD *v32; // [sp+24h] [bp-3Ch]
  unsigned int *v33; // [sp+2Ch] [bp-34h]
  unsigned int v34; // [sp+30h] [bp-30h]
  unsigned int v35; // [sp+38h] [bp-28h]
  int vars4; // [sp+64h] [bp+4h]
  _DWORD *varg_r0; // [sp+68h] [bp+8h]

  varg_r0 = a1;
  v33 = a4;
  v31 = a3;
  v34 = a2;
  v4 = 0;
  v28 = 0;
  v30 = 0;
  v35 = 0;
  if ( a3 == 1 )
  {
    v5 = a1;
    v6 = 4;
    v7 = a1 + 1;
  }
  else
  {
    v5 = a1 + 2;
    v6 = 12;
    v7 = a1 + 3;
  }
  v29 = v7;
  v32 = v5;
  if ( a2 )
    *v5 = 0;
  v27 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&ExpLargePoolTableLock);
  }
  else
  {
    v8 = 0;
    do
      v9 = __ldrex((unsigned __int8 *)&ExpLargePoolTableLock + 3);
    while ( __strex(v9 | 0x80, (unsigned __int8 *)&ExpLargePoolTableLock + 3) );
    __dmb(0xBu);
    if ( v9 >> 7 )
      v8 = ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&ExpLargePoolTableLock);
    while ( 1 )
    {
      v10 = ExpLargePoolTableLock;
      if ( (ExpLargePoolTableLock & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (ExpLargePoolTableLock & 0x40000000) == 0 )
      {
        do
          v26 = __ldrex((unsigned int *)&ExpLargePoolTableLock);
        while ( v26 == v10 && __strex(v10 | 0x40000000, (unsigned int *)&ExpLargePoolTableLock) );
        __dmb(0xBu);
      }
      ++v8;
      __dmb(0xAu);
      __yield();
    }
  }
  while ( 1 )
  {
    v11 = &PoolBigPageTableSize;
    if ( v31 == 1 )
    {
      v12 = PoolBigPageTable;
    }
    else
    {
      v12 = *(_DWORD *)(MmSessionSpace + 8380);
      v11 = (int *)(MmSessionSpace + 8384);
    }
    v13 = *v11;
    if ( !v12 )
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&ExpLargePoolTableLock, vars4);
      }
      else
      {
        __dmb(0xBu);
        ExpLargePoolTableLock = 0;
      }
      KfLowerIrql(v27);
      if ( v4 )
        MiFreePoolPages(v4, v28);
      *v33 = 0;
      return 0;
    }
    if ( v4 && v35 >= v13 )
      break;
    v35 = *v11;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&ExpLargePoolTableLock, vars4);
    }
    else
    {
      __dmb(0xBu);
      ExpLargePoolTableLock = 0;
    }
    KfLowerIrql(v27);
    v21 = 16 * v13;
    if ( v4 )
      MiFreePoolPages(v4, v28);
    v4 = MiAllocatePoolPages(512, v21, v19, v20);
    if ( !v4 )
      return -1073741670;
    v28 = v21;
    v22 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&ExpLargePoolTableLock);
    }
    else
    {
      do
        v23 = __ldrex((unsigned __int8 *)&ExpLargePoolTableLock + 3);
      while ( __strex(v23 | 0x80, (unsigned __int8 *)&ExpLargePoolTableLock + 3) );
      __dmb(0xBu);
      if ( v23 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&ExpLargePoolTableLock);
      while ( 1 )
      {
        v24 = ExpLargePoolTableLock;
        if ( (ExpLargePoolTableLock & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (ExpLargePoolTableLock & 0x40000000) == 0 )
        {
          do
            v25 = __ldrex((unsigned int *)&ExpLargePoolTableLock);
          while ( v25 == v24 && __strex(v24 | 0x40000000, (unsigned int *)&ExpLargePoolTableLock) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    v27 = v22;
  }
  memmove(v4, v12, 16 * v13);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&ExpLargePoolTableLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    ExpLargePoolTableLock = 0;
  }
  KfLowerIrql(v27);
  for ( i = (int *)v4; (unsigned int)i < v4 + 16 * v13; i += 4 )
  {
    v16 = *i;
    if ( (*i & 1) == 0 )
    {
      v17 = v34;
      if ( v34 )
      {
        ++*v32;
        v17 = v34;
      }
      v6 += 12;
      if ( v6 < 0xC )
      {
        v18 = -1073741675;
        goto LABEL_44;
      }
      if ( v6 <= v17 )
      {
        if ( v17 )
        {
          *v29 = v16;
          if ( v31 == 1 && (i[2] & 0x100) == 0 )
            *v29 = v16 | 1;
          v29[2] = i[1] & 0x7FFFFFFF;
          v29[1] = i[3];
          v29 += 3;
        }
      }
      else
      {
        v30 = -1073741820;
      }
    }
  }
  v18 = v30;
LABEL_44:
  MiFreePoolPages(v4, v28);
  *v33 = v6;
  return v18;
}
