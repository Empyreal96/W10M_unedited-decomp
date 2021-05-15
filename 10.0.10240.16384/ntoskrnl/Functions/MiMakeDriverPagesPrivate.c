// MiMakeDriverPagesPrivate 
 
int __fastcall MiMakeDriverPagesPrivate(int a1, unsigned int a2, unsigned int a3, int a4, char a5)
{
  int v5; // lr
  int v6; // r8
  char v7; // r0
  unsigned int v8; // r7
  int v9; // r9
  int v10; // r3
  unsigned int *v11; // r5
  int v12; // r1
  int v13; // r4
  int v14; // r8
  unsigned int v15; // r1
  unsigned __int8 *v17; // r3
  unsigned int v18; // r1
  unsigned int v19; // r0
  unsigned int v20; // r3
  int v21; // r9
  unsigned int v22; // r4
  int v23; // r6
  int v24; // r0
  unsigned __int8 *v25; // r3
  unsigned int v26; // r0
  unsigned int v27; // r2
  unsigned int v28; // r0
  char v29; // r3
  int v30; // r4
  unsigned int v31; // r1
  unsigned __int8 *v32; // r3
  unsigned int v33; // r1
  unsigned __int8 *v34; // r1
  int v35; // r3
  unsigned int v36; // r2
  unsigned int *v37; // r2
  unsigned int v38; // r0
  unsigned __int8 *v39; // r3
  unsigned int v40; // r1
  unsigned __int8 *v41; // r1
  int v42; // r3
  unsigned int v43; // r2
  unsigned int *v44; // r2
  unsigned int v45; // r0
  unsigned __int8 *v46; // r3
  unsigned int v47; // r1
  unsigned __int8 *v48; // r1
  int v49; // r3
  unsigned int v50; // r2
  unsigned int *v51; // r2
  unsigned int v52; // r0
  int v53; // [sp+8h] [bp-E0h]
  char v55; // [sp+10h] [bp-D8h]
  int v57; // [sp+18h] [bp-D0h]
  char v58; // [sp+1Ch] [bp-CCh]
  int v59; // [sp+20h] [bp-C8h]
  int v60; // [sp+28h] [bp-C0h]
  int v61; // [sp+30h] [bp-B8h] BYREF
  char v62; // [sp+34h] [bp-B4h]
  char v63; // [sp+35h] [bp-B3h]
  int v64; // [sp+38h] [bp-B0h]
  int v65; // [sp+3Ch] [bp-ACh]
  int v66; // [sp+40h] [bp-A8h]
  int v67; // [sp+44h] [bp-A4h]

  v5 = a4;
  v53 = a4;
  v6 = a1;
  v7 = 0;
  v59 = 0;
  v55 = 0;
  v8 = a2;
  v9 = 0;
  if ( a4 == 17 )
  {
    v7 = 1;
    v55 = 1;
  }
  if ( a2 << 10 >= dword_63389C
    && ((v10 = *((unsigned __int8 *)&MiState[2423]
               + ((int)(((a2 << 10 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
         v10 == 11)
     || v10 == 1) )
  {
    v12 = 2;
    v57 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
    v11 = (unsigned int *)(v57 + 3248);
  }
  else
  {
    v57 = 0;
    v11 = (unsigned int *)&dword_634F00;
    v12 = 0;
  }
  v13 = ((*(_DWORD *)(v6 + 24) >> 10) & 0x3FFFFC) - 0x40000000;
  v58 = 0;
  v60 = *(_DWORD *)(v6 + 136);
  if ( (a5 & 4) != 0 )
    v58 = 1;
  v65 = 0;
  v66 = 0;
  v62 = 0;
  v63 = 0;
  v64 = 33;
  v61 = v12;
  v67 = 0;
  v14 = -1;
  v15 = 0x80000000;
  if ( (v7 & 1) != 0 )
  {
    v53 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_518E84();
    v17 = (unsigned __int8 *)v11 + 3;
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 | 0x80, v17) );
    __dmb(0xBu);
    if ( v18 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v11);
    v15 = 0x80000000;
    while ( 1 )
    {
      v19 = *v11;
      if ( (*v11 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v19 & 0x40000000) == 0 )
      {
        do
          v31 = __ldrex(v11);
        while ( v31 == v19 && __strex(v19 | 0x40000000, v11) );
        __dmb(0xBu);
        v15 = 0x80000000;
      }
      __dmb(0xAu);
      __yield();
    }
    v5 = v53;
  }
  v20 = a3;
  if ( v8 > a3 )
    goto LABEL_53;
  v21 = v8 - v13;
  while ( 1 )
  {
    v22 = *(_DWORD *)v8;
    if ( !*(_DWORD *)v8 )
      goto LABEL_25;
    if ( (v22 & 2) == 0 )
    {
      if ( (v22 & 0x400) == 0 )
        goto LABEL_25;
      MiFlushTbList((unsigned int)&v61, 0x80000000);
      MiUnlockWorkingSetExclusive((int)v11, v53);
      if ( MmAccessFault(0, v8 << 10, 0, 0) < 0 )
        KeBugCheckEx(26, 12288, v8 << 10);
      v53 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v11);
      }
      else
      {
        v15 = (unsigned int)v11 + 3;
        do
          v27 = __ldrex((unsigned __int8 *)v15);
        while ( __strex(v27 | 0x80, (unsigned __int8 *)v15) );
        __dmb(0xBu);
        if ( v27 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(v11);
        while ( 1 )
        {
          v28 = *v11;
          if ( (*v11 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v28 & 0x40000000) == 0 )
          {
            do
              v15 = __ldrex(v11);
            while ( v15 == v28 && __strex(v28 | 0x40000000, v11) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      goto LABEL_51;
    }
    v23 = MmPfnDatabase + 24 * (v22 >> 12);
    if ( (*(_DWORD *)(v23 + 20) & 0x8000000) == 0 || (*(_DWORD *)(v23 + 4) & 0x80000000) == 0 )
      goto LABEL_24;
    if ( (MiFlags & 0x30000) != 0 && (v57 || (a5 & 2) != 0) && (*(_DWORD *)(v23 + 8) & 0x40) != 0 )
    {
      v9 = -1073741755;
      goto LABEL_53;
    }
    if ( (a5 & 4) != 0 && (*(_DWORD *)(a1 + 112) & 3) == 0 && (*(_BYTE *)(v23 + 19) & 8) != 0
      || (a5 & 1) != 0 && ((v22 & 0x80) != 0 || (v22 & 0x100) == 0) )
    {
      goto LABEL_24;
    }
    if ( v14 != -1 )
    {
      MiFlushTbList((unsigned int)&v61, 0x80000000);
      MiCopyOnWriteEx(v8 << 10, v8, v14, v53, v58);
      if ( !v57 || v59 )
      {
        v29 = v55;
      }
      else
      {
        v59 = MiSessionLookupImage(*(_DWORD *)(a1 + 24));
        v29 = v55;
        if ( *(_BYTE *)(v59 + 36) )
        {
          v29 = v55 | 2;
          v55 |= 2u;
        }
      }
      if ( (v29 & 2) != 0 && MiDriverPageMustStayResident(a1, v8, 2) )
      {
        v32 = (unsigned __int8 *)(v23 + 15);
        do
          v33 = __ldrex(v32);
        while ( __strex(v33 | 0x80, v32) );
        __dmb(0xBu);
        if ( v33 >> 7 )
        {
          v34 = (unsigned __int8 *)(v23 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v35 = *(_DWORD *)(v23 + 12);
              __dmb(0xBu);
            }
            while ( (v35 & 0x80000000) != 0 );
            do
              v36 = __ldrex(v34);
            while ( __strex(v36 | 0x80, v34) );
            __dmb(0xBu);
          }
          while ( v36 >> 7 );
        }
        MiRemoveLockedPageChargeAndDecRef(v23);
        __dmb(0xBu);
        v37 = (unsigned int *)(v23 + 12);
        do
          v38 = __ldrex(v37);
        while ( __strex(v38 & 0x7FFFFFFF, v37) );
        v30 = MmPfnDatabase + 24 * v14;
        v39 = (unsigned __int8 *)(v30 + 15);
        do
          v40 = __ldrex(v39);
        while ( __strex(v40 | 0x80, v39) );
        __dmb(0xBu);
        if ( v40 >> 7 )
        {
          v41 = (unsigned __int8 *)(v30 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v42 = *(_DWORD *)(v30 + 12);
              __dmb(0xBu);
            }
            while ( (v42 & 0x80000000) != 0 );
            do
              v43 = __ldrex(v41);
            while ( __strex(v43 | 0x80, v41) );
            __dmb(0xBu);
          }
          while ( v43 >> 7 );
        }
        MiAddLockedPageCharge(v30, 1);
        __dmb(0xBu);
        v44 = (unsigned int *)(v30 + 12);
        do
        {
          v45 = __ldrex(v44);
          v15 = v45 & 0x7FFFFFFF;
        }
        while ( __strex(v45 & 0x7FFFFFFF, v44) );
      }
      else
      {
        v30 = MmPfnDatabase + 24 * v14;
      }
      v14 = -1;
      if ( (MiFlags & 0x30000) != 0 && (*(_BYTE *)(v30 + 23) & 7) == 3 )
      {
        v15 = *(_DWORD *)(v60 + 4);
        *(_BYTE *)(((unsigned int)(v21 >> 2) >> 3) + v15) |= 1 << ((v21 >> 2) & 7);
        if ( *(_DWORD *)v30 )
        {
          if ( (*(_BYTE *)(v30 + 19) & 8) == 0 )
          {
            v46 = (unsigned __int8 *)(v30 + 15);
            do
              v47 = __ldrex(v46);
            while ( __strex(v47 | 0x80, v46) );
            __dmb(0xBu);
            if ( v47 >> 7 )
            {
              v48 = (unsigned __int8 *)(v30 + 15);
              do
              {
                do
                {
                  __dmb(0xAu);
                  __yield();
                  v49 = *(_DWORD *)(v30 + 12);
                  __dmb(0xBu);
                }
                while ( (v49 & 0x80000000) != 0 );
                do
                  v50 = __ldrex(v48);
                while ( __strex(v50 | 0x80, v48) );
                __dmb(0xBu);
              }
              while ( v50 >> 7 );
            }
            MiRemoveImagePageFromSystemWorkingSet(v11, v8, v30);
            __dmb(0xBu);
            v51 = (unsigned int *)(v30 + 12);
            do
            {
              v52 = __ldrex(v51);
              v15 = v52 & 0x7FFFFFFF;
            }
            while ( __strex(v52 & 0x7FFFFFFF, v51) );
          }
        }
      }
LABEL_24:
      v20 = a3;
LABEL_25:
      v8 += 4;
      v21 += 4;
      goto LABEL_26;
    }
    v24 = MiUnlockWorkingSetExclusive((int)v11, v5);
    v14 = MiAllocateDriverPage(v24);
    v53 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v11);
    }
    else
    {
      v25 = (unsigned __int8 *)v11 + 3;
      do
        v15 = __ldrex(v25);
      while ( __strex(v15 | 0x80, v25) );
      __dmb(0xBu);
      if ( v15 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v11);
      while ( 1 )
      {
        v26 = *v11;
        if ( (*v11 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v26 & 0x40000000) == 0 )
        {
          do
            v15 = __ldrex(v11);
          while ( v15 == v26 && __strex(v26 | 0x40000000, v11) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    if ( v14 == -1 )
      break;
LABEL_51:
    v20 = a3;
LABEL_26:
    if ( v8 > v20 )
    {
      v9 = 0;
      goto LABEL_53;
    }
    v5 = v53;
    v15 = 0x80000000;
  }
  v9 = -1073741801;
LABEL_53:
  MiFlushTbList((unsigned int)&v61, v15);
  if ( (v55 & 1) != 0 )
    MiUnlockWorkingSetExclusive((int)v11, v53);
  if ( v14 != -1 )
    MiReleaseFreshPage(MmPfnDatabase + 24 * v14);
  return v9;
}
