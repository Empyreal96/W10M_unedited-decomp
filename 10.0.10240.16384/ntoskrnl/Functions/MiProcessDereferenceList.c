// MiProcessDereferenceList 
 
int __fastcall MiProcessDereferenceList(__int16 *a1)
{
  __int16 *v1; // r8
  int v2; // r9
  unsigned int v3; // r1
  unsigned int v4; // r6
  int v5; // r0
  int v6; // r2
  unsigned int v7; // r1
  __int64 **v8; // r8
  _DWORD *v9; // r4
  __int64 v10; // r2
  _DWORD *v11; // r7
  int result; // r0
  unsigned int v13; // r1
  unsigned int *v14; // r4
  int v15; // r0
  unsigned int v16; // r1
  __int64 *v17; // r2
  unsigned int *v18; // t2
  unsigned int *v19; // r8
  unsigned int v20; // r0
  unsigned int v21; // r1
  unsigned int v22; // r4
  unsigned int v23; // r2
  unsigned int v24; // r1
  unsigned int v25; // r1
  int v26; // r4
  unsigned int *v27; // r2
  unsigned int v28; // r0
  unsigned int *v29; // t2
  unsigned int *v30; // r8
  unsigned int v31; // r0
  unsigned int v32; // r1
  unsigned int v33; // r4
  unsigned int v34; // r2
  unsigned int v35; // r1
  unsigned int *v36; // r2
  unsigned int v37; // r1
  unsigned int v38; // r1
  int v39; // r4
  unsigned int *v40; // r2
  unsigned int v41; // r0
  unsigned int v42; // r1
  int v43; // r4
  unsigned int *v44; // r2
  unsigned int v45; // r0
  int v46; // r0
  __int64 **v47; // [sp+0h] [bp-60h]
  char v49[20]; // [sp+8h] [bp-58h] BYREF
  int v50; // [sp+1Ch] [bp-44h]
  _DWORD *v51; // [sp+38h] [bp-28h]
  char v52; // [sp+3Ch] [bp-24h]

  v1 = a1;
  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    v4 = 192;
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_632D80);
  }
  else
  {
    do
      v3 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
    while ( __strex(v3 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
    __dmb(0xBu);
    v4 = 0xC0u;
    if ( v3 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632D80);
    while ( 1 )
    {
      v5 = dword_632D80;
      if ( (dword_632D80 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_632D80 & 0x40000000) == 0 )
      {
        v6 = dword_632D80 | 0x40000000;
        do
          v7 = __ldrex((unsigned int *)&dword_632D80);
        while ( v7 == v5 && __strex(v6, (unsigned int *)&dword_632D80) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v8 = (__int64 **)(v1 + 400);
  v47 = v8;
  while ( *v8 != (__int64 *)v8 )
  {
    v9 = *v8;
    v10 = **v8;
    if ( (__int64 **)HIDWORD(v10) != v8 || *(_DWORD **)(v10 + 4) != v9 )
      __fastfail(3u);
    *v8 = (__int64 *)v10;
    v11 = v9 - 1;
    *(_DWORD *)(v10 + 4) = v8;
    if ( *(v9 - 1) )
    {
      if ( ExTryAcquireSpinLockExclusiveAtDpcLevel(v9 + 8) )
      {
        v9[6] &= 0xF7FFFFFF;
        *v9 = v9;
        v9[1] = v9;
        if ( (dword_682604 & 0x10000) != 0 )
          return sub_53EB98();
        __dmb(0xBu);
        MiState[v4] = 0;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v9 + 8);
        }
        else
        {
          __dmb(0xBu);
          v9[8] = 0;
        }
        KfLowerIrql(v2);
        MiSegmentDelete(v11);
      }
      else
      {
        v17 = *v8;
        *v9 = *v8;
        v9[1] = v8;
        if ( *((__int64 ***)v17 + 1) != v8 )
          __fastfail(3u);
        *((_DWORD *)v17 + 1) = v9;
        *v8 = (__int64 *)v9;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&MiState[v4]);
        }
        else
        {
          __dmb(0xBu);
          MiState[v4] = 0;
        }
        KfLowerIrql(v2);
      }
      v2 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&MiState[v4]);
      }
      else
      {
        do
          v13 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
        while ( __strex(v13 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
        __dmb(0xBu);
        if ( v13 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&MiState[v4]);
        v14 = (unsigned int *)&MiState[v4];
        while ( 1 )
        {
          v15 = MiState[v4];
          if ( (v15 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v15 & 0x40000000) == 0 )
          {
            do
              v16 = __ldrex(v14);
            while ( v16 == v15 && __strex(v15 | 0x40000000, v14) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
    }
    else if ( v9[3] == -1 )
    {
      v18 = (unsigned int *)(a1 + 282);
      __pld(a1 + 282);
      v19 = v18;
      v20 = *v18 & 0xFFFFFFFE;
      do
        v21 = __ldrex(v19);
      while ( v21 == v20 && __strex(v20 + 2, v19) );
      __dmb(0xBu);
      if ( v21 == v20 || ExfAcquireRundownProtection(v19) )
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&MiState[v4]);
        }
        else
        {
          __dmb(0xBu);
          MiState[v4] = 0;
        }
        KfLowerIrql(v2);
        MiAttemptPageFileReduction(v9 - 1);
        __pld(v19);
        v22 = *v19 & 0xFFFFFFFE;
        __dmb(0xBu);
        v23 = v22 - 2;
        do
          v24 = __ldrex(v19);
        while ( v24 == v22 && __strex(v23, v19) );
        if ( v24 != v22 )
          ExfReleaseRundownProtection(v19, v24, v23);
        v2 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&MiState[v4]);
        }
        else
        {
          do
            v25 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
          while ( __strex(v25 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
          __dmb(0xBu);
          if ( v25 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&MiState[v4]);
          while ( 1 )
          {
            v26 = MiState[v4];
            if ( (v26 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v26 & 0x40000000) == 0 )
            {
              v27 = (unsigned int *)&MiState[v4];
              do
                v28 = __ldrex(v27);
              while ( v28 == v26 && __strex(v26 | 0x40000000, v27) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
      }
      v8 = v47;
      if ( !*((_BYTE *)v11 + 53) )
      {
        KeSetEvent((int)(v11 + 6), 0, 0);
        goto LABEL_120;
      }
    }
    else
    {
      memmove((int)v49, (int)(v9 - 1), 0x38u);
      v51 = v9 - 1;
      v9[11] = v49;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&MiState[v4]);
      }
      else
      {
        __dmb(0xBu);
        MiState[v4] = 0;
      }
      KfLowerIrql(v2);
      v29 = (unsigned int *)(a1 + 282);
      __pld(a1 + 282);
      v30 = v29;
      v31 = *v29 & 0xFFFFFFFE;
      do
        v32 = __ldrex(v30);
      while ( v32 == v31 && __strex(v31 + 2, v30) );
      __dmb(0xBu);
      if ( v32 == v31 || ExfAcquireRundownProtection(v30) )
      {
        MiExtendPagingFiles(v49);
        __pld(v30);
        v33 = *v30 & 0xFFFFFFFE;
        __dmb(0xBu);
        v34 = v33 - 2;
        do
          v35 = __ldrex(v30);
        while ( v35 == v33 && __strex(v34, v30) );
        if ( v35 != v33 )
          ExfReleaseRundownProtection(v30, v35, v34);
      }
      if ( v52 == 1 )
      {
        __dmb(0xBu);
        v36 = v11 + 10;
        do
          v37 = __ldrex(v36);
        while ( __strex(0, v36) );
        __dmb(0xBu);
        v2 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&MiState[v4]);
        }
        else
        {
          do
            v38 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
          while ( __strex(v38 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
          __dmb(0xBu);
          if ( v38 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&MiState[v4]);
          while ( 1 )
          {
            v39 = MiState[v4];
            if ( (v39 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v39 & 0x40000000) == 0 )
            {
              v40 = (unsigned int *)&MiState[v4];
              do
                v41 = __ldrex(v40);
              while ( v41 == v39 && __strex(v39 | 0x40000000, v40) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
LABEL_120:
        v8 = v47;
      }
      else
      {
        v2 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&MiState[v4]);
        }
        else
        {
          do
            v42 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
          while ( __strex(v42 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
          __dmb(0xBu);
          if ( v42 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&MiState[v4]);
          while ( 1 )
          {
            v43 = MiState[v4];
            if ( (v43 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v43 & 0x40000000) == 0 )
            {
              v44 = (unsigned int *)&MiState[v4];
              do
                v45 = __ldrex(v44);
              while ( v45 == v43 && __strex(v43 | 0x40000000, v44) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
        v8 = v47;
        if ( v51 )
        {
          v11[5] = v50;
          KeSetEvent((int)(v11 + 6), 0, 0);
          goto LABEL_120;
        }
      }
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&MiState[v4]);
  }
  else
  {
    __dmb(0xBu);
    MiState[v4] = 0;
  }
  result = KfLowerIrql(v2);
  if ( a1 == MiSystemPartition && dword_6337A8 )
  {
    v46 = KeResetEvent((int)algn_6337A4);
    result = MiFreeClonePool(v46);
  }
  return result;
}
