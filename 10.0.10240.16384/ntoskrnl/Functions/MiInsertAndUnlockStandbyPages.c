// MiInsertAndUnlockStandbyPages 
 
int __fastcall MiInsertAndUnlockStandbyPages(int result, int *a2, unsigned int a3, int a4)
{
  int v5; // r7
  __int16 *v6; // r4
  unsigned int v7; // r5
  int *v8; // r9
  int *v9; // r4
  unsigned int v10; // r6
  int v11; // t1
  unsigned int v12; // r6
  int *v13; // r4
  int v14; // t1
  unsigned int *v15; // r2
  int v16; // r3
  unsigned int *v17; // r1
  unsigned int v18; // r3
  unsigned int v19; // r10
  int *v20; // r3
  int v21; // r7
  int v22; // r2
  int v23; // r6
  int v24; // r6
  int v25; // r0
  unsigned int *v26; // r1
  unsigned int *v27; // r2
  int v28; // r0
  unsigned int *v29; // r1
  int *v30; // r0
  unsigned int *v31; // r2
  unsigned int v32; // r4
  int v33; // r0
  unsigned int *v34; // r1
  int *v35; // r0
  unsigned int v36; // r0
  int v37; // [sp+8h] [bp-30h]
  int *v38; // [sp+Ch] [bp-2Ch]
  int v39; // [sp+10h] [bp-28h] BYREF
  unsigned int *v40; // [sp+14h] [bp-24h]
  int v41; // [sp+18h] [bp-20h]

  v5 = result;
  v6 = 0;
  v39 = 0;
  v40 = 0;
  v41 = 0;
  v7 = a3;
  v8 = a2;
  if ( result )
  {
    if ( a3 )
    {
      v9 = a2;
      v10 = a3;
      do
      {
        v11 = *v9++;
        result = MiInsertProtectedStandbyPage(v5, v11);
        --v10;
      }
      while ( v10 );
    }
    goto LABEL_5;
  }
  result = 0xFFFFFF;
  v37 = 0xFFFFFF;
  v19 = 0;
  if ( a3 )
  {
    v20 = a2;
    while ( 1 )
    {
      v21 = *v20;
      v38 = v20 + 1;
      if ( (*(_DWORD *)(*v20 + 12) & 0x3FFFFFFF) != 0
        || (v22 = *(unsigned __int8 *)(v21 + 18), (v22 & 7) == 6)
        || (v22 & 0x10) != 0 )
      {
        KeBugCheckEx(78, 6, (*v20 - MmPfnDatabase) / 24);
      }
      if ( (*(_BYTE *)(v21 + 19) & 0x40) == 0 )
      {
        if ( (*(_BYTE *)(v21 + 19) & 8) != 0 )
          return sub_53B2A8();
        v23 = *(_BYTE *)(v21 + 19) & 7;
        if ( !v6 )
          v6 = MiSystemPartition;
        if ( v23 == result && v6 == MiSystemPartition )
          goto LABEL_30;
        if ( result != 0xFFFFFF )
        {
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseQueuedSpinLockInstrumented(&v39);
          }
          else
          {
            v28 = v39;
            if ( !v39 )
            {
              v29 = v40;
              __dmb(0xBu);
              do
                v30 = (int *)__ldrex(v29);
              while ( v30 == &v39 && __strex(0, v29) );
              if ( v30 == &v39 )
                goto LABEL_44;
              v28 = KxWaitForLockChainValid(&v39);
            }
            v39 = 0;
            __dmb(0xBu);
            v31 = (unsigned int *)(v28 + 4);
            do
              v32 = __ldrex(v31);
            while ( __strex(v32 ^ 1, v31) );
          }
        }
LABEL_44:
        v37 = v23;
        v6 = MiSystemPartition;
        KeAcquireInStackQueuedSpinLockAtDpcLevel((char *)&unk_63FD10 + 20 * v23, &v39, &unk_63FD10, 5 * v23);
LABEL_30:
        result = MiInsertPageInList(v21, 132, v22);
        v24 = v37;
        goto LABEL_31;
      }
      v24 = 0xFFFFFF;
      if ( result == 0xFFFFFF )
      {
        v24 = v37;
        goto LABEL_69;
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseQueuedSpinLockInstrumented(&v39);
      }
      else
      {
        v33 = v39;
        if ( !v39 )
        {
          v34 = v40;
          __dmb(0xBu);
          v22 = (int)&v39;
          do
            v35 = (int *)__ldrex(v34);
          while ( v35 == &v39 && __strex(0, v34) );
          if ( v35 == &v39 )
            goto LABEL_67;
          v33 = KxWaitForLockChainValid(&v39);
        }
        v39 = 0;
        __dmb(0xBu);
        v22 = v33 + 4;
        do
          v36 = __ldrex((unsigned int *)v22);
        while ( __strex(v36 ^ 1, (unsigned int *)v22) );
      }
LABEL_67:
      v37 = 0xFFFFFF;
LABEL_69:
      result = MiInsertPageInList(v21, 4, v22);
LABEL_31:
      ++v19;
      v20 = v38;
      if ( v19 >= v7 )
      {
        if ( v24 != 0xFFFFFF )
        {
          if ( (dword_682604 & 0x10000) != 0 )
          {
            result = KiReleaseQueuedSpinLockInstrumented(&v39);
          }
          else
          {
            v25 = v39;
            if ( v39 )
            {
LABEL_40:
              v39 = 0;
              __dmb(0xBu);
              v27 = (unsigned int *)(v25 + 4);
              do
                result = __ldrex(v27);
              while ( __strex(result ^ 1, v27) );
            }
            else
            {
              v26 = v40;
              __dmb(0xBu);
              do
                result = __ldrex(v26);
              while ( (int *)result == &v39 && __strex(0, v26) );
              if ( (int *)result != &v39 )
              {
                v25 = KxWaitForLockChainValid(&v39);
                goto LABEL_40;
              }
            }
          }
        }
        break;
      }
      result = v37;
    }
  }
LABEL_5:
  if ( a4 != 17 )
    --v7;
  v12 = 0;
  if ( v7 )
  {
    v13 = v8;
    v12 = v7;
    do
    {
      v14 = *v13++;
      __dmb(0xBu);
      v15 = (unsigned int *)(v14 + 12);
      do
        result = __ldrex(v15);
      while ( __strex(result & 0x7FFFFFFF, v15) );
      --v7;
    }
    while ( v7 );
  }
  if ( a4 != 17 )
  {
    v16 = v8[v12];
    __dmb(0xBu);
    v17 = (unsigned int *)(v16 + 12);
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 & 0x7FFFFFFF, v17) );
    result = KfLowerIrql(a4);
  }
  return result;
}
