// MiRemoveLowestPriorityStandbyPage 
 
int __fastcall MiRemoveLowestPriorityStandbyPage(int a1, int a2)
{
  unsigned int v2; // r10
  _DWORD *v3; // r5
  unsigned int *v5; // r4
  unsigned int v6; // r9
  int v7; // r0
  _DWORD *v9; // r1
  int *v10; // lr
  int v11; // r6
  unsigned __int8 *v12; // r1
  unsigned int v13; // r2
  int v14; // r1
  int v15; // r4
  unsigned int *v16; // r5
  unsigned int v17; // r0
  unsigned int v18; // r4
  int v19; // r0
  unsigned int *v20; // r1
  int *v21; // r0
  unsigned int *v22; // r2
  unsigned int v23; // r4
  unsigned int v24; // r4
  unsigned int v25; // r1
  int v26; // r3
  char v27; // r1
  unsigned int v28; // r2
  unsigned int *v29; // r2
  unsigned int v30; // r0
  unsigned int *v31; // r2
  unsigned int v32; // r1
  unsigned int *v33; // r2
  unsigned int v34; // r0
  int v35; // r1
  int v36; // r0
  unsigned int *v37; // r2
  unsigned int v38; // r0
  unsigned int *v39; // r1
  int *v40; // r0
  unsigned __int8 *v41; // r1
  unsigned int v42; // r2
  unsigned __int8 *v43; // r1
  int v44; // r3
  unsigned int v45; // r2
  unsigned int *v46; // r2
  unsigned int v47; // r0
  int v48; // r0
  int v49; // r0
  unsigned int *v50; // r1
  int *v51; // r0
  unsigned int *v52; // r2
  unsigned int v53; // r0
  int v54; // r0
  unsigned int *v55; // r1
  int *v56; // r0
  unsigned int *v57; // r2
  unsigned int v58; // r0
  int v59; // r3
  int v60; // r0
  unsigned int *v61; // r1
  int *v62; // r0
  unsigned int *v63; // r2
  unsigned int v64; // r0
  unsigned int *v65; // r2
  unsigned int v66; // r0
  unsigned int v67; // r1
  unsigned int *v68; // lr
  int v69; // r2
  int v70; // r2
  unsigned int v71; // r0
  int v72; // r4
  int v73; // r2
  unsigned int v74; // r0
  unsigned int v75; // r3
  unsigned int v76; // r0
  unsigned int v77; // r0
  unsigned int v78; // r1
  int v79; // r3
  int v80; // [sp+8h] [bp-38h]
  int v81; // [sp+Ch] [bp-34h]
  int v82; // [sp+10h] [bp-30h]
  int v83; // [sp+18h] [bp-28h] BYREF
  unsigned int *v84; // [sp+1Ch] [bp-24h]

  v2 = a1 + 20 * a2 + 1536;
  v3 = (_DWORD *)(a1 + 1536);
  if ( a1 + 1536 < v2 )
  {
    v5 = (unsigned int *)(a1 + 1552);
    while ( v3[2] == 0xFFFFF )
    {
LABEL_4:
      v3 += 5;
      v5 += 5;
      if ( (unsigned int)v3 >= v2 )
        return -1;
    }
    v7 = KfRaiseIrql(2);
    v83 = 0;
    v84 = v5;
    v80 = v7;
    __dmb(0xBu);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_53DF58();
    do
      v9 = (_DWORD *)__ldrex(v5);
    while ( __strex((unsigned int)&v83, v5) );
    __dmb(0xBu);
    if ( v9 )
      KxWaitForLockOwnerShip((int)&v83, v9);
    v6 = v3[2];
    if ( v6 != 0xFFFFF )
    {
      v10 = MiState;
      v11 = MmPfnDatabase + 24 * v6;
      if ( v6 < dword_634690 || v6 >= dword_634690 + 2048 )
      {
        v10 = MiState;
        v81 = 0;
        v82 = 0xFFFFF;
      }
      else
      {
        v48 = MmPfnDatabase + 24 * v6;
        v6 = *(_DWORD *)(v11 + 8) >> 12;
        v11 = MmPfnDatabase + 24 * v6;
        v81 = v48;
        v82 = v3[2];
        if ( v6 == v82 )
        {
          MiUnlinkPageFromList(v48, 1);
          *(_BYTE *)(v81 + 19) &= 0xF7u;
          MiRemoveDecayClusterTimer(v81);
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseQueuedSpinLockInstrumented(&v83);
          }
          else
          {
            v49 = v83;
            if ( !v83 )
            {
              v50 = v84;
              __dmb(0xBu);
              do
                v51 = (int *)__ldrex(v50);
              while ( v51 == &v83 && __strex(0, v50) );
              if ( v51 == &v83 )
                goto LABEL_74;
              v49 = KxWaitForLockChainValid(&v83);
            }
            v83 = 0;
            __dmb(0xBu);
            v52 = (unsigned int *)(v49 + 4);
            do
              v53 = __ldrex(v52);
            while ( __strex(v53 ^ 1, v52) );
          }
LABEL_74:
          KfLowerIrql(v80);
          v3 -= 5;
          v5 -= 5;
          goto LABEL_4;
        }
      }
      v12 = (unsigned __int8 *)(v11 + 15);
      do
        v13 = __ldrex(v12);
      while ( __strex(v13 | 0x80, v12) );
      __dmb(0xBu);
      if ( !(v13 >> 7) )
        goto LABEL_17;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseQueuedSpinLockInstrumented(&v83);
        goto LABEL_64;
      }
      v54 = v83;
      if ( v83 )
      {
LABEL_97:
        v83 = 0;
        __dmb(0xBu);
        v57 = (unsigned int *)(v54 + 4);
        do
          v58 = __ldrex(v57);
        while ( __strex(v58 ^ 1, v57) );
      }
      else
      {
        v55 = v84;
        __dmb(0xBu);
        do
          v56 = (int *)__ldrex(v55);
        while ( v56 == &v83 && __strex(0, v55) );
        if ( v56 != &v83 )
        {
          v54 = KxWaitForLockChainValid(&v83);
          goto LABEL_97;
        }
      }
LABEL_64:
      v41 = (unsigned __int8 *)(v11 + 15);
      do
        v42 = __ldrex(v41);
      while ( __strex(v42 | 0x80, v41) );
      __dmb(0xBu);
      if ( v42 >> 7 )
      {
        v43 = (unsigned __int8 *)(v11 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v44 = *(_DWORD *)(v11 + 12);
            __dmb(0xBu);
          }
          while ( v44 < 0 );
          do
            v45 = __ldrex(v43);
          while ( __strex(v45 | 0x80, v43) );
          __dmb(0xBu);
        }
        while ( v45 >> 7 );
      }
      if ( (*(_BYTE *)(v11 + 18) & 7) != 2 || MiSystemPartition != (__int16 *)a1 )
      {
        __dmb(0xBu);
        v46 = (unsigned int *)(v11 + 12);
        do
          v47 = __ldrex(v46);
        while ( __strex(v47 & 0x7FFFFFFF, v46) );
        goto LABEL_74;
      }
      KeAcquireInStackQueuedSpinLockAtDpcLevel(v5, &v83);
      v59 = v3[2];
      if ( v81 )
      {
        if ( v82 == v59 && v6 == *(_DWORD *)(v81 + 8) >> 12 )
        {
LABEL_120:
          v10 = MiState;
LABEL_17:
          if ( !*v3 )
            KeBugCheckEx(78, 1, v3);
          --*v3;
          if ( v10[1600] == 1 )
          {
            LOBYTE(v67) = 1;
            v68 = (unsigned int *)(*(_DWORD *)(v10[1602] + 4) + 4 * (v6 >> 5));
            v69 = v6 & 0x1F;
            if ( (unsigned int)(v69 + 1) > 0x20 )
            {
              if ( (v6 & 0x1F) != 0 )
              {
                v72 = 32 - v69;
                __dmb(0xBu);
                v73 = ((1 << (32 - v69)) - 1) << v69;
                do
                  v74 = __ldrex(v68);
                while ( __strex(v74 | v73, v68) );
                __dmb(0xBu);
                v67 = 1 - v72;
                ++v68;
                if ( (unsigned int)(1 - v72) >= 0x20 )
                {
                  v75 = v67 >> 5;
                  do
                  {
                    v67 -= 32;
                    --v75;
                    *v68++ = -1;
                  }
                  while ( v75 );
                }
                if ( !v67 )
                  goto LABEL_19;
              }
              __dmb(0xBu);
              do
                v76 = __ldrex(v68);
              while ( __strex(v76 | ((1 << v67) - 1), v68) );
            }
            else
            {
              __dmb(0xBu);
              v70 = 1 << v69;
              do
                v71 = __ldrex(v68);
              while ( __strex(v71 | v70, v68) );
            }
            __dmb(0xBu);
          }
LABEL_19:
          v14 = *(_DWORD *)v11;
          v15 = *(_DWORD *)(v11 + 12) & 0xFFFFF;
          if ( (*(_BYTE *)(v11 + 19) & 8) != 0 )
          {
            if ( MI_IS_DECAY_PFN(*(_DWORD *)(v11 + 12) & 0xFFFFF) && v35 == v15 )
            {
              MiDeleteParentDecayNode(v11);
            }
            else
            {
              *(_DWORD *)(MmPfnDatabase + 24 * v15 + 8) = *(_DWORD *)(MmPfnDatabase + 24 * v15 + 8) & 0xFFF | (v35 << 12);
              MiSetPfnBlink(MmPfnDatabase + 24 * v35, v15, 0);
            }
            *(_BYTE *)(v11 + 19) &= 0xF7u;
          }
          else
          {
            v3[2] = v14;
            if ( v14 == 0xFFFFF )
            {
              v3[3] = 0xFFFFF;
            }
            else
            {
              v16 = (unsigned int *)(MmPfnDatabase + 24 * v14 + 12);
              v17 = *v16;
              do
                v18 = __ldrex(v16);
              while ( v18 == v17 && __strex(v17 | 0xFFFFF, v16) );
              if ( v17 != v18 )
              {
                do
                {
                  v77 = v18;
                  do
                    v78 = __ldrex(v16);
                  while ( v78 == v18 && __strex(v18 | 0xFFFFF, v16) );
                  v18 = v78;
                }
                while ( v77 != v78 );
              }
            }
          }
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseQueuedSpinLockInstrumented(&v83);
            goto LABEL_31;
          }
          v19 = v83;
          if ( !v83 )
          {
            v20 = v84;
            __dmb(0xBu);
            do
              v21 = (int *)__ldrex(v20);
            while ( v21 == &v83 && __strex(0, v20) );
            if ( v21 == &v83 )
            {
LABEL_31:
              v22 = (unsigned int *)(a1 + 3712);
              do
              {
                v23 = __ldrex(v22);
                v24 = v23 - 1;
              }
              while ( __strex(v24, v22) );
              if ( v24 == *(_DWORD *)(a1 + 2988) || v24 == *(_DWORD *)(a1 + 2992) )
                MiUpdateAvailableEvents(a1);
              if ( v24 <= 0x400 )
              {
                v79 = *(_DWORD *)(a1 + 3512);
                if ( !v79 || !*(_BYTE *)(v79 + 44) )
                  MiObtainFreePages(a1);
              }
              *(_DWORD *)(v11 + 12) &= 0xFFF00000;
              MiRestoreTransitionPte(v11, 1);
              if ( (*(_DWORD *)(v11 + 20) & 0x8000000) != 0 )
              {
                do
                  v25 = __ldrex((unsigned int *)&dword_634680);
                while ( __strex(v25 - 1, (unsigned int *)&dword_634680) );
              }
              else
              {
                v31 = (unsigned int *)(a1 + 3072);
                do
                  v32 = __ldrex(v31);
                while ( __strex(v32 - 1, v31) );
              }
              v26 = *(_DWORD *)(v11 + 20);
              v27 = *(_BYTE *)(v11 + 19);
              *(_DWORD *)v11 = 0;
              v28 = v26 & 0xF7FFFFFF;
              LOBYTE(v26) = *(_BYTE *)(v11 + 18);
              *(_DWORD *)(v11 + 20) = v28;
              *(_BYTE *)(v11 + 19) = v27 & 0xDF;
              *(_BYTE *)(v11 + 18) = v26 & 0xC0 | 5;
              *(_DWORD *)(v11 + 8) = 128;
              __dmb(0xBu);
              v29 = (unsigned int *)(v11 + 12);
              do
                v30 = __ldrex(v29);
              while ( __strex(v30 & 0x7FFFFFFF, v29) );
              KfLowerIrql(v80);
              return v6;
            }
            v19 = KxWaitForLockChainValid(&v83);
          }
          v83 = 0;
          __dmb(0xBu);
          v33 = (unsigned int *)(v19 + 4);
          do
            v34 = __ldrex(v33);
          while ( __strex(v34 ^ 1, v33) );
          goto LABEL_31;
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
LABEL_105:
          KiReleaseQueuedSpinLockInstrumented(&v83);
          goto LABEL_114;
        }
      }
      else
      {
        if ( v6 == v59 )
          goto LABEL_120;
        if ( (dword_682604 & 0x10000) != 0 )
          goto LABEL_105;
      }
      v60 = v83;
      if ( !v83 )
      {
        v61 = v84;
        __dmb(0xBu);
        do
          v62 = (int *)__ldrex(v61);
        while ( v62 == &v83 && __strex(0, v61) );
        if ( v62 == &v83 )
          goto LABEL_114;
        v60 = KxWaitForLockChainValid(&v83);
      }
      v83 = 0;
      __dmb(0xBu);
      v63 = (unsigned int *)(v60 + 4);
      do
        v64 = __ldrex(v63);
      while ( __strex(v64 ^ 1, v63) );
LABEL_114:
      __dmb(0xBu);
      v65 = (unsigned int *)(v11 + 12);
      do
        v66 = __ldrex(v65);
      while ( __strex(v66 & 0x7FFFFFFF, v65) );
      goto LABEL_74;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(&v83);
    }
    else
    {
      v36 = v83;
      if ( !v83 )
      {
        v39 = v84;
        __dmb(0xBu);
        do
          v40 = (int *)__ldrex(v39);
        while ( v40 == &v83 && __strex(0, v39) );
        if ( v40 == &v83 )
          goto LABEL_58;
        v36 = KxWaitForLockChainValid(&v83);
      }
      v83 = 0;
      __dmb(0xBu);
      v37 = (unsigned int *)(v36 + 4);
      do
        v38 = __ldrex(v37);
      while ( __strex(v38 ^ 1, v37) );
    }
LABEL_58:
    KfLowerIrql(v80);
    goto LABEL_4;
  }
  return -1;
}
