// NtLockVirtualMemory 
 
int __fastcall NtLockVirtualMemory(int a1, unsigned int *a2, _DWORD *a3)
{
  int v4; // r3
  unsigned int v5; // r9
  unsigned int v6; // r4
  int v7; // r0
  int v8; // r8
  int v9; // r10
  int v10; // r6
  unsigned int v11; // r5
  _DWORD *k; // r2
  unsigned int i; // r1
  _DWORD *v14; // r5
  _DWORD **v15; // r3
  _DWORD *j; // r3
  unsigned int *v17; // r5
  int v18; // r8
  int v19; // r0
  unsigned __int8 *v20; // r3
  unsigned int v21; // r1
  unsigned int v22; // lr
  _DWORD *v23; // r2
  _DWORD **v24; // r3
  _DWORD *v25; // r10
  _DWORD *l; // r3
  int v27; // r5
  int v28; // r3
  unsigned int *v29; // r5
  unsigned __int8 *v30; // r3
  unsigned int v31; // r1
  unsigned int v32; // r0
  unsigned int v33; // r1
  _DWORD *v34; // r8
  unsigned int *v35; // r10
  unsigned int v36; // r9
  int v37; // r5
  int v38; // r10
  int v39; // r3
  int v40; // r3
  unsigned int v41; // r5
  unsigned int v42; // r4
  unsigned int *v43; // r5
  int v44; // r6
  unsigned __int8 *v45; // r3
  unsigned int v46; // r1
  unsigned int v47; // r0
  unsigned int v48; // r1
  unsigned int v49; // r0
  unsigned int v50; // r8
  int v51; // r5
  unsigned __int8 *v52; // r3
  unsigned int v53; // r1
  unsigned int v54; // r0
  unsigned int v55; // r1
  unsigned int v57; // r1
  int v58; // [sp+10h] [bp-C0h]
  int v59; // [sp+14h] [bp-BCh]
  int v60; // [sp+18h] [bp-B8h]
  unsigned int v61; // [sp+20h] [bp-B0h]
  int v62; // [sp+20h] [bp-B0h]
  char v63; // [sp+24h] [bp-ACh]
  _DWORD *v64; // [sp+28h] [bp-A8h]
  int v65; // [sp+2Ch] [bp-A4h]
  int v66; // [sp+2Ch] [bp-A4h]
  int v67; // [sp+30h] [bp-A0h]
  int v68; // [sp+38h] [bp-98h]
  unsigned int v69; // [sp+3Ch] [bp-94h]
  unsigned int v70; // [sp+40h] [bp-90h]
  unsigned int v71; // [sp+48h] [bp-88h]
  unsigned int v72; // [sp+4Ch] [bp-84h]
  _DWORD *v73; // [sp+50h] [bp-80h]
  int v74; // [sp+58h] [bp-78h]
  int v77; // [sp+6Ch] [bp-64h]
  _DWORD v78[4]; // [sp+88h] [bp-48h] BYREF
  _BYTE v79[56]; // [sp+98h] [bp-38h] BYREF

  v63 = 0;
  v4 = MiLockUnlockCommon(a1);
  if ( v4 >= 0 )
  {
    __mrc(15, 0, 13, 0, 3);
    v5 = (v72 + v65 - 1) & 0xFFFFF000;
    v70 = v5;
    v6 = v72 & 0xFFFFF000;
    v61 = 0;
    v7 = ExAllocatePoolWithTag(
           512,
           8
         * ((((((v5 - (v72 & 0xFFFFF000)) >> 12) + 1) & 0x3F) != 0) + ((((v5 - (v72 & 0xFFFFF000)) >> 12) + 1) >> 6)),
           1802267981);
    v8 = v7;
    v67 = v7;
    if ( v7 )
    {
      v78[0] = ((v5 - (v72 & 0xFFFFF000)) >> 12) + 1;
      v78[1] = v7;
      RtlClearAllBits(v78);
      v9 = v59;
      if ( a1 != -1 )
      {
        KiStackAttachProcess(v59, 0);
        v63 = 2;
      }
      v10 = ((v72 >> 10) & 0x3FFFFC) - 0x40000000;
      v71 = v72 & 0xFFFFF000;
      v77 = ((v5 >> 10) & 0x3FFFFC) - 0x40000000;
      v78[2] = v77;
      v11 = MiLockVadRange(v59, v6);
      v69 = v11;
      if ( v11 )
      {
        v64 = (_DWORD *)MiLocateAddress(v6);
        k = v64;
        for ( i = 0; i < v11; ++i )
        {
          if ( ((1 << (k[7] & 7)) & 0x15) == 0 )
          {
            v58 = -1073741747;
            goto LABEL_97;
          }
          v14 = k;
          v15 = (_DWORD **)k[1];
          if ( v15 )
          {
            k = (_DWORD *)k[1];
            for ( j = *v15; j; j = (_DWORD *)*j )
              k = j;
          }
          else
          {
            for ( k = (_DWORD *)(k[2] & 0xFFFFFFFC); k; k = (_DWORD *)(k[2] & 0xFFFFFFFC) )
            {
              if ( (_DWORD *)*k == v14 )
                break;
              v14 = k;
            }
          }
          v11 = v69;
        }
        v74 = MiVadPureReserve(v64);
        v17 = (unsigned int *)(v59 + 492);
        v18 = KfRaiseIrql(2);
        v60 = v18;
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v59 + 492);
        }
        else
        {
          v19 = 0;
          v20 = (unsigned __int8 *)(v59 + 495);
          do
            v21 = __ldrex(v20);
          while ( __strex(v21 | 0x80, v20) );
          __dmb(0xBu);
          if ( v21 >> 7 )
            v19 = ExpWaitForSpinLockExclusiveAndAcquire(v59 + 492);
          while ( 1 )
          {
            v22 = *v17;
            if ( (*v17 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v22 & 0x40000000) == 0 )
            {
              do
                v57 = __ldrex(v17);
              while ( v57 == v22 && __strex(v22 | 0x40000000, v17) );
              __dmb(0xBu);
            }
            ++v19;
            __dmb(0xAu);
            __yield();
          }
        }
        while ( v6 <= v5 )
        {
          if ( v6 >> 12 <= v64[4] )
          {
            v27 = v74;
          }
          else
          {
            v23 = v64;
            v24 = (_DWORD **)v64[1];
            if ( v24 )
            {
              v25 = (_DWORD *)v64[1];
              v64 = v25;
              for ( l = *v24; l; l = (_DWORD *)*l )
              {
                v25 = l;
                v64 = l;
              }
            }
            else
            {
              v25 = (_DWORD *)(v64[2] & 0xFFFFFFFC);
              v64 = v25;
              if ( v25 )
              {
                do
                {
                  if ( (_DWORD *)*v25 == v23 )
                    break;
                  v23 = v25;
                  v25 = (_DWORD *)(v25[2] & 0xFFFFFFFC);
                }
                while ( v25 );
                v64 = v25;
              }
            }
            v27 = MiVadPureReserve(v25);
            v74 = v27;
          }
          if ( v27 )
          {
            if ( MiGetNextPageTable(v10, v77, 0, v18, 1, v78) != v10 )
            {
              v28 = -1073741819;
              goto LABEL_75;
            }
          }
          else
          {
            MiMakeSystemAddressValid(v10, 0);
          }
          if ( (*(_DWORD *)v10 & 2) != 0 )
          {
            v34 = (_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)v10 >> 12));
            v35 = (unsigned int *)(v59 + 492);
            v68 = v59 + 492;
            v36 = MiLocateWsle(v6, v59 + 492, *v34);
            v37 = MEMORY[0xC0402004];
            if ( v36 < MEMORY[0xC0402004] )
            {
              v63 |= 1u;
              v50 = v61;
            }
            else
            {
              v73 = (_DWORD *)(MEMORY[0xC0402024] * MEMORY[0xC0402004] - 1069537344);
              v9 = v59;
              if ( (unsigned int)(MEMORY[0xC0402004] + 4) >= *(_DWORD *)(v59 + 540) )
              {
                v28 = -1073741663;
                v18 = v60;
                goto LABEL_76;
              }
              if ( (v34[5] & 0x8000000) != 0 && !MiLockPageTablePage(v34, 1) )
              {
                v28 = -1073741670;
                v18 = v60;
                goto LABEL_76;
              }
              v38 = 3 * (*(_DWORD *)(((v6 >> 20) & 0xFFC) - 1070596096) >> 12);
              v66 = MmPfnDatabase;
              if ( !MiLockPageTablePage(MmPfnDatabase + 24 * (*(_DWORD *)(((v6 >> 20) & 0xFFC) - 1070596096) >> 12), 0) )
              {
                v39 = v34[5];
                if ( (v39 & 0x8000000) != 0 )
                  MiUnlockPageTableCharges(MmPfnDatabase + 24 * (v39 & 0xFFFFF), 2, 0);
                v28 = -1073741670;
LABEL_74:
                v18 = v60;
LABEL_75:
                v9 = v59;
LABEL_76:
                v58 = v28;
                v41 = v61;
                v42 = v71 + (v61 << 12);
                while ( v41 )
                {
                  v62 = --v41;
                  v42 -= 4096;
                  if ( ((*(_DWORD *)(v67 + 4 * (v41 >> 5)) >> (v41 & 0x1F)) & 1) != 0 )
                    MiUnlockVa(v9 + 492, v42);
                  if ( (v41 & 0xF) == 0 && ExSpinLockIsContended(v9 + 492) || KeShouldYieldProcessor() )
                  {
                    v43 = (unsigned int *)(v9 + 492);
                    MiUnlockWorkingSetExclusive(v9 + 492, v18);
                    v44 = KfRaiseIrql(2);
                    if ( (dword_682604 & 0x210000) != 0 )
                    {
                      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v9 + 492);
                    }
                    else
                    {
                      v45 = (unsigned __int8 *)(v9 + 495);
                      do
                        v46 = __ldrex(v45);
                      while ( __strex(v46 | 0x80, v45) );
                      __dmb(0xBu);
                      if ( v46 >> 7 )
                        ExpWaitForSpinLockExclusiveAndAcquire(v9 + 492);
                      while ( 1 )
                      {
                        v47 = *v43;
                        if ( (*v43 & 0xBFFFFFFF) == 0x80000000 )
                          break;
                        if ( (v47 & 0x40000000) == 0 )
                        {
                          do
                            v48 = __ldrex(v43);
                          while ( v48 == v47 && __strex(v47 | 0x40000000, v43) );
                          __dmb(0xBu);
                        }
                        __dmb(0xAu);
                        __yield();
                      }
                    }
                    v18 = v44;
                    v41 = v62;
                  }
                }
                MiUnlockWorkingSetExclusive(v9 + 492, v18);
                v8 = v67;
                goto LABEL_97;
              }
              v40 = v34[2];
              if ( (v40 & 0x400) != 0 )
              {
                if ( (v34[5] & 0x8000000) != 0 )
                {
                  if ( !MiChargeCommit(MiSystemPartition, 1, 0) )
                  {
                    MiUnlockPageTableCharges(v66 + 8 * v38, 2, 1);
                    MiUnlockPageTableCharges(MmPfnDatabase + 24 * (v34[5] & 0xFFFFF), 2, 0);
                    v28 = -1073741523;
                    goto LABEL_74;
                  }
                  do
                    v49 = __ldrex(dword_640720);
                  while ( __strex(v49 + 1, dword_640720) );
                }
              }
              else if ( (v40 & 0x10) != 0 )
              {
                MiLockPageAndSetDirty(v34, 1);
              }
              v35 = (unsigned int *)(v59 + 492);
              if ( v36 != v37 )
                MiSwapWslEntries(v36, v37, v68);
              MiRemoveEntryWsle(-1069539328, v73);
              ++MEMORY[0xC0402004];
              v50 = v61;
              *(_DWORD *)(v67 + 4 * (v61 >> 5)) |= 1 << (v61 & 0x1F);
              MiUpdateWorkingSetAgeDistribution(v68, (*v73 >> 9) & 7, -1);
            }
            v61 = v50 + 1;
            v10 += 4;
            v6 += 4096;
            if ( (v10 & 0x3C) == 0 && ExSpinLockIsContended(v35) || (v18 = v60, v5 = v70, KeShouldYieldProcessor()) )
            {
              MiUnlockWorkingSetExclusive(v35, v60);
              v51 = KfRaiseIrql(2);
              if ( (dword_682604 & 0x210000) != 0 )
              {
                ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v35);
              }
              else
              {
                v52 = (unsigned __int8 *)v35 + 3;
                do
                  v53 = __ldrex(v52);
                while ( __strex(v53 | 0x80, v52) );
                __dmb(0xBu);
                if ( v53 >> 7 )
                  ExpWaitForSpinLockExclusiveAndAcquire(v35);
                while ( 1 )
                {
                  v54 = *v35;
                  if ( (*v35 & 0xBFFFFFFF) == 0x80000000 )
                    break;
                  if ( (v54 & 0x40000000) == 0 )
                  {
                    do
                      v55 = __ldrex(v35);
                    while ( v55 == v54 && __strex(v54 | 0x40000000, v35) );
                    __dmb(0xBu);
                  }
                  __dmb(0xAu);
                  __yield();
                }
              }
              v18 = v51;
              v60 = v51;
              v5 = v70;
            }
          }
          else
          {
            MiUnlockWorkingSetExclusive(v59 + 492, v18);
            v29 = (unsigned int *)(v59 + 492);
            v18 = KfRaiseIrql(2);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v59 + 492);
            }
            else
            {
              v30 = (unsigned __int8 *)(v59 + 495);
              do
                v31 = __ldrex(v30);
              while ( __strex(v31 | 0x80, v30) );
              __dmb(0xBu);
              if ( v31 >> 7 )
                ExpWaitForSpinLockExclusiveAndAcquire(v59 + 492);
              while ( 1 )
              {
                v32 = *v29;
                if ( (*v29 & 0xBFFFFFFF) == 0x80000000 )
                  break;
                if ( (v32 & 0x40000000) == 0 )
                {
                  do
                    v33 = __ldrex(v29);
                  while ( v33 == v32 && __strex(v32 | 0x40000000, v29) );
                  __dmb(0xBu);
                }
                __dmb(0xAu);
                __yield();
              }
              v5 = v70;
            }
            v60 = v18;
          }
        }
        MiUnlockWorkingSetExclusive(v59 + 492, v18);
        MiUnlockVadRange(v59, v71);
        if ( (v63 & 2) != 0 )
          KiUnstackDetachProcess(v79, 0);
        ObfDereferenceObjectWithTag(v59);
        ExFreePoolWithTag(v67, 0);
        *a3 = v5 - (v72 & 0xFFFFF000) + 4096;
        *a2 = v72 & 0xFFFFF000;
        if ( (v63 & 1) != 0 )
          v4 = 1073741849;
        else
          v4 = 0;
      }
      else
      {
        v58 = -1073741819;
LABEL_97:
        MiUnlockVadRange(v9, v71);
        if ( (v63 & 2) != 0 )
          KiUnstackDetachProcess(v79, 0);
        ObfDereferenceObjectWithTag(v9);
        ExFreePoolWithTag(v8, 0);
        v4 = v58;
      }
    }
    else
    {
      ObfDereferenceObjectWithTag(v59);
      v4 = -1073741670;
    }
  }
  return v4;
}
