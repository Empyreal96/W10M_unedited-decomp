// MiScrubNodeLargePageList 
 
int __fastcall MiScrubNodeLargePageList(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r8
  unsigned int *v7; // r10
  int v8; // r7
  int v10; // r9
  int v11; // r6
  int v12; // r0
  int v13; // r4
  unsigned __int8 *v14; // r3
  unsigned int v15; // r1
  int v16; // r0
  unsigned int *v17; // r1
  int *v18; // r0
  unsigned int *v19; // r2
  unsigned int v20; // r0
  unsigned int v21; // r4
  __int64 v22; // r2
  int v23; // r0
  unsigned int *v24; // r1
  int *v25; // r0
  unsigned int *v26; // r2
  unsigned int v27; // r0
  unsigned int *v28; // r2
  unsigned int v29; // r0
  unsigned int v30; // r9
  int v31; // r6
  unsigned int v32; // r7
  int i; // r5
  int v34; // r0
  unsigned int *v35; // r6
  unsigned __int8 *v36; // r1
  int v37; // r8
  unsigned int v38; // r2
  unsigned int v39; // r3
  unsigned int v40; // r1
  int v41; // r5
  unsigned __int8 *v42; // r3
  unsigned int v43; // r1
  unsigned __int8 *v44; // r1
  int v45; // r3
  unsigned int v46; // r2
  unsigned int *v47; // r2
  unsigned int v48; // r0
  unsigned __int8 *v49; // r3
  unsigned int v50; // r1
  unsigned __int8 *v51; // r1
  int v52; // r3
  unsigned int v53; // r2
  int v54; // r0
  unsigned int *v55; // r2
  unsigned int v56; // r0
  unsigned int v57; // r4
  int v58; // r5
  unsigned __int8 *v59; // r3
  unsigned int v60; // r1
  unsigned __int8 *v61; // r1
  int v62; // r3
  unsigned int v63; // r2
  unsigned int *v64; // r2
  unsigned int v65; // r0
  int v66; // r0
  unsigned int *v67; // r1
  int *v68; // r0
  unsigned int *v69; // r2
  unsigned int v70; // r4
  int v72; // [sp+0h] [bp-40h]
  unsigned int *v75; // [sp+Ch] [bp-34h]
  int v77; // [sp+18h] [bp-28h] BYREF
  unsigned int *v78; // [sp+1Ch] [bp-24h]
  int vars4; // [sp+44h] [bp+4h]

  v6 = a4;
  v7 = (unsigned int *)(a1 + 8 * (a3 + 2 * a2 + a4 + 1));
  v8 = a1;
  v75 = v7;
  v10 = 1;
  v11 = KfRaiseIrql(2);
  KeAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)(v8 + 100), &v77);
  v12 = a3;
  v72 = *(_DWORD *)(v8 + 4 * (a3 + 2 * (a2 + 5) + v6));
  if ( v72 )
  {
    v13 = *(_DWORD *)(v8 + 4 * (a3 + 2 * (a2 + 5) + v6));
    while ( 1 )
    {
      if ( (unsigned int *)*v7 == v7 )
      {
LABEL_90:
        v10 = 1;
        goto LABEL_91;
      }
      if ( *(_DWORD *)(a6 + 4) )
      {
        v10 = 0;
        goto LABEL_91;
      }
      v14 = (unsigned __int8 *)(*v7 + 15);
      do
        v15 = __ldrex(v14);
      while ( __strex(v15 | 0x80, v14) );
      __dmb(0xBu);
      if ( v15 >> 7 )
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseQueuedSpinLockInstrumented(&v77, vars4);
        }
        else
        {
          v16 = v77;
          if ( !v77 )
          {
            v17 = v78;
            __dmb(0xBu);
            do
              v18 = (int *)__ldrex(v17);
            while ( v18 == &v77 && __strex(0, v17) );
            if ( v18 == &v77 )
              goto LABEL_18;
            v16 = KxWaitForLockChainValid(&v77);
          }
          v77 = 0;
          __dmb(0xBu);
          v19 = (unsigned int *)(v16 + 4);
          do
            v20 = __ldrex(v19);
          while ( __strex(v20 ^ 1, v19) );
        }
LABEL_18:
        KfLowerIrql(v11);
        v11 = KfRaiseIrql(2);
        KeAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)(v8 + 100), &v77);
        goto LABEL_86;
      }
      v21 = *v7;
      v22 = *(_QWORD *)*v7;
      if ( (unsigned int *)HIDWORD(v22) != v7 || *(_DWORD *)(v22 + 4) != v21 )
        __fastfail(3u);
      *v7 = v22;
      *(_DWORD *)(v22 + 4) = v7;
      MiUnlinkNodeLargePageHelper(v8, v21, v12, a4);
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseQueuedSpinLockInstrumented(&v77, vars4);
        goto LABEL_31;
      }
      v23 = v77;
      if ( v77 )
        goto LABEL_29;
      v24 = v78;
      __dmb(0xBu);
      do
        v25 = (int *)__ldrex(v24);
      while ( v25 == &v77 && __strex(0, v24) );
      if ( v25 != &v77 )
        break;
LABEL_31:
      __dmb(0xBu);
      v28 = (unsigned int *)(v21 + 12);
      do
        v29 = __ldrex(v28);
      while ( __strex(v29 & 0x7FFFFFFF, v28) );
      KfLowerIrql(v11);
      v30 = v21 + 24576;
      v31 = 0;
      --v72;
      v32 = v21;
      if ( v21 >= v21 + 24576 )
      {
LABEL_75:
        v57 = v21 - 24576;
        v58 = KfRaiseIrql(2);
        v59 = (unsigned __int8 *)(v57 + 15);
        do
          v60 = __ldrex(v59);
        while ( __strex(v60 | 0x80, v59) );
        __dmb(0xBu);
        if ( v60 >> 7 )
        {
          v61 = (unsigned __int8 *)(v57 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v62 = *(_DWORD *)(v57 + 12);
              __dmb(0xBu);
            }
            while ( (v62 & 0x80000000) != 0 );
            do
              v63 = __ldrex(v61);
            while ( __strex(v63 | 0x80, v61) );
            __dmb(0xBu);
          }
          while ( v63 >> 7 );
        }
        MiInsertLargePageInNodeList(
          (int)(v57 - MmPfnDatabase) / 24,
          0x400u,
          1,
          (int)((unsigned __int64)(715827883i64 * (int)(v57 - MmPfnDatabase)) >> 32) >> 2);
        __dmb(0xBu);
        v64 = (unsigned int *)(v57 + 12);
        do
          v65 = __ldrex(v64);
        while ( __strex(v65 & 0x7FFFFFFF, v64) );
        KfLowerIrql(v58);
        goto LABEL_85;
      }
      do
      {
        if ( MiScrubPage(a5, 0, v21) >= 0 )
        {
          if ( v31 != 1 )
            goto LABEL_73;
          v41 = KfRaiseIrql(2);
          v49 = (unsigned __int8 *)(v21 + 15);
          do
            v50 = __ldrex(v49);
          while ( __strex(v50 | 0x80, v49) );
          __dmb(0xBu);
          if ( v50 >> 7 )
          {
            v51 = (unsigned __int8 *)(v21 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v52 = *(_DWORD *)(v21 + 12);
                __dmb(0xBu);
              }
              while ( (v52 & 0x80000000) != 0 );
              do
                v53 = __ldrex(v51);
              while ( __strex(v53 | 0x80, v51) );
              __dmb(0xBu);
            }
            while ( v53 >> 7 );
          }
          if ( (*(_BYTE *)(v21 + 19) & 0x40) != 0 )
          {
            MiMakePageBad(v21, 1);
          }
          else
          {
            v54 = (int)(v21 - MmPfnDatabase) / 24;
            *(_DWORD *)(v21 + 20) &= 0xFFF00000;
            MiInsertPageInFreeOrZeroedList(v54, 2);
          }
          __dmb(0xBu);
          v55 = (unsigned int *)(v21 + 12);
          do
            v56 = __ldrex(v55);
          while ( __strex(v56 & 0x7FFFFFFF, v55) );
        }
        else
        {
          if ( !v31 )
          {
            for ( i = (int)(v32 - MmPfnDatabase) / 24; v32 != v21; ++i )
            {
              v34 = KfRaiseIrql(2);
              v35 = (unsigned int *)(v32 + 12);
              v36 = (unsigned __int8 *)(v32 + 15);
              v37 = v34;
              do
                v38 = __ldrex(v36);
              while ( __strex(v38 | 0x80, v36) );
              while ( 1 )
              {
                __dmb(0xBu);
                if ( !(v38 >> 7) )
                  break;
                do
                {
                  __dmb(0xAu);
                  __yield();
                  v39 = *v35;
                  __dmb(0xBu);
                }
                while ( (v39 & 0x80000000) != 0 );
                do
                  v38 = __ldrex(v36);
                while ( __strex(v38 | 0x80, v36) );
              }
              if ( (*(_BYTE *)(v32 + 19) & 0x40) != 0 )
              {
                *(_BYTE *)(v32 + 18) = *(_BYTE *)(v32 + 18) & 0xF8 | 5;
                MiMakePageBad(v32, 1);
              }
              else
              {
                *(_DWORD *)(v32 + 20) &= 0xFFF00000;
                MiInsertPageInFreeOrZeroedList(i, 2);
              }
              __dmb(0xBu);
              do
                v40 = __ldrex(v35);
              while ( __strex(v40 & 0x7FFFFFFF, v35) );
              KfLowerIrql(v37);
              v32 += 24;
            }
          }
          v31 = 1;
          v41 = KfRaiseIrql(2);
          v42 = (unsigned __int8 *)(v21 + 15);
          do
            v43 = __ldrex(v42);
          while ( __strex(v43 | 0x80, v42) );
          __dmb(0xBu);
          if ( v43 >> 7 )
          {
            v44 = (unsigned __int8 *)(v21 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v45 = *(_DWORD *)(v21 + 12);
                __dmb(0xBu);
              }
              while ( (v45 & 0x80000000) != 0 );
              do
                v46 = __ldrex(v44);
              while ( __strex(v46 | 0x80, v44) );
              __dmb(0xBu);
            }
            while ( v46 >> 7 );
          }
          *(_BYTE *)(v21 + 18) = *(_BYTE *)(v21 + 18) & 0xF8 | 5;
          MiMakePageBad(v21, 1);
          __dmb(0xBu);
          v47 = (unsigned int *)(v21 + 12);
          do
            v48 = __ldrex(v47);
          while ( __strex(v48 & 0x7FFFFFFF, v47) );
        }
        KfLowerIrql(v41);
LABEL_73:
        v21 += 24;
      }
      while ( v21 < v30 );
      v7 = v75;
      if ( !v31 )
        goto LABEL_75;
LABEL_85:
      v8 = a1;
      v11 = KfRaiseIrql(2);
      KeAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)(a1 + 100), &v77);
      v13 = v72;
LABEL_86:
      if ( !v13 )
        goto LABEL_90;
      v12 = a3;
    }
    v23 = KxWaitForLockChainValid(&v77);
LABEL_29:
    v77 = 0;
    __dmb(0xBu);
    v26 = (unsigned int *)(v23 + 4);
    do
      v27 = __ldrex(v26);
    while ( __strex(v27 ^ 1, v26) );
    goto LABEL_31;
  }
LABEL_91:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(&v77, vars4);
    goto LABEL_101;
  }
  v66 = v77;
  if ( v77 )
    goto LABEL_99;
  v67 = v78;
  __dmb(0xBu);
  do
    v68 = (int *)__ldrex(v67);
  while ( v68 == &v77 && __strex(0, v67) );
  if ( v68 != &v77 )
  {
    v66 = KxWaitForLockChainValid(&v77);
LABEL_99:
    v77 = 0;
    __dmb(0xBu);
    v69 = (unsigned int *)(v66 + 4);
    do
      v70 = __ldrex(v69);
    while ( __strex(v70 ^ 1, v69) );
  }
LABEL_101:
  KfLowerIrql(v11);
  return v10;
}
