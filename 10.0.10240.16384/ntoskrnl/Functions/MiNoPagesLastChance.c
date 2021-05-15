// MiNoPagesLastChance 
 
int __fastcall MiNoPagesLastChance(_DWORD *a1, unsigned int a2)
{
  _DWORD *v2; // r6
  int v3; // r7
  int result; // r0
  unsigned int v5; // lr
  unsigned int v6; // r5
  _DWORD *v7; // r4
  int v8; // r1
  __int16 v9; // r3
  int v10; // r9
  unsigned int v11; // r2
  unsigned int *v12; // r1
  unsigned int v13; // r2
  _DWORD *v14; // r4
  int v15; // r8
  _DWORD *v16; // r7
  int v17; // r0
  int v18; // r1
  _DWORD *v19; // r8
  unsigned __int8 *v20; // r3
  unsigned int v21; // r1
  unsigned int *v22; // r4
  unsigned __int8 *v23; // r3
  unsigned int v24; // r1
  unsigned int v25; // r0
  unsigned int v26; // r1
  unsigned int *v27; // r2
  unsigned int v28; // r0
  int v29; // r0
  unsigned int *v30; // r1
  int *v31; // r0
  unsigned int *v32; // r2
  unsigned int v33; // r4
  unsigned int *v34; // r2
  unsigned int v35; // r0
  int v36; // r0
  unsigned int *v37; // r1
  int *v38; // r0
  unsigned int *v39; // r2
  unsigned int v40; // r4
  unsigned int v41; // r5
  _DWORD *v42; // [sp+10h] [bp-60h]
  int v43; // [sp+14h] [bp-5Ch]
  int v44; // [sp+18h] [bp-58h]
  int v45; // [sp+20h] [bp-50h]
  int v46; // [sp+24h] [bp-4Ch]
  int v47; // [sp+28h] [bp-48h]
  int v48; // [sp+2Ch] [bp-44h]
  int v49; // [sp+30h] [bp-40h]
  unsigned int v51; // [sp+34h] [bp-3Ch]
  int v52; // [sp+38h] [bp-38h]
  unsigned int *v54; // [sp+40h] [bp-30h]
  int v55; // [sp+48h] [bp-28h] BYREF
  unsigned int *v56; // [sp+4Ch] [bp-24h]
  int vars4; // [sp+74h] [bp+4h]

  v45 = 0;
  v2 = a1;
  v3 = 0;
  v43 = 0;
  v44 = a1[1030];
  if ( (int)a1[97] < 0 )
  {
    v3 = 1;
    v43 = 1;
    v45 = a1[97];
  }
  if ( (int)a1[96] < 0 )
  {
    v3 |= 2u;
    v43 = v3;
    v45 = a1[96];
  }
  result = a1[899];
  v5 = 0;
  v6 = 0;
  __dmb(0xBu);
  if ( !result )
    goto LABEL_12;
  v7 = v2;
  do
  {
    v8 = v7[900];
    v9 = *(_WORD *)(v8 + 96);
    if ( (v9 & 0x10) == 0 && (v9 & 0x40) == 0 )
    {
      v5 += *(_DWORD *)(v8 + 4) - *(_DWORD *)v8;
      v6 += *(_DWORD *)(v8 + 12);
    }
    ++v7;
    --result;
  }
  while ( result );
  if ( v6 < 0x400 )
  {
LABEL_12:
    v3 |= 4u;
    v43 = v3;
  }
  if ( v5 < 0x400 )
    v43 = v3 | 8;
  if ( dword_634350 )
  {
    v10 = 243;
  }
  else
  {
    v11 = v2[992];
    if ( v2[1024] < v11 >> 2 )
    {
      if ( v2[1030] < v11 >> 2 )
        v10 = 235;
      else
        v10 = 77;
    }
    else
    {
      v44 = v2[1024];
      v10 = 253;
    }
  }
  if ( KdPitchDebugger || KdDebuggerNotPresent )
  {
    v52 = 0;
  }
  else
  {
    result = DbgPrintEx(
               102,
               0,
               (int)"Without a debugger attached, the following bugcheck would have occurred.\n%4lx %p %p %x %x\n",
               v10);
    if ( (MiFlags & 8) != 0 )
      __debugbreak();
    v52 = 1;
  }
  if ( v2[928] < a2 )
  {
    v12 = v2 + 706;
    v54 = v2 + 706;
    result = 1;
    do
      v13 = __ldrex(v12);
    while ( !v13 && __strex(1u, v12) );
    __dmb(0xBu);
    if ( !v13 )
    {
      v14 = 0;
      v15 = 16;
      v16 = v2;
      v49 = 16;
      v51 = 0;
      v42 = 0;
      while ( 1 )
      {
        v47 = KfRaiseIrql(2);
        KeAcquireInStackQueuedSpinLockAtDpcLevel(v16 + 516, &v55);
        v17 = v16[514];
        v46 = v17;
        if ( v17 == 0xFFFFF )
          goto LABEL_81;
        do
        {
          v18 = MmPfnDatabase + 24 * v17;
          v48 = v18;
          v19 = *(_DWORD **)(*(_DWORD *)(v18 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v18 + 8) & 0x3FC)));
          if ( (v19[7] & 0x28) == 0 && (!v14 || v14 == v19) )
          {
            v20 = (unsigned __int8 *)(v18 + 15);
            do
              v21 = __ldrex(v20);
            while ( __strex(v21 | 0x80, v20) );
            __dmb(0xBu);
            if ( !(v21 >> 7) )
            {
              v22 = v19 + 9;
              if ( (dword_682604 & 0x210000) != 0 )
              {
                ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v19 + 9);
              }
              else
              {
                v23 = (unsigned __int8 *)v19 + 39;
                do
                  v24 = __ldrex(v23);
                while ( __strex(v24 | 0x80, v23) );
                __dmb(0xBu);
                if ( v24 >> 7 )
                  ExpWaitForSpinLockExclusiveAndAcquire(v19 + 9);
                while ( 1 )
                {
                  v25 = *v22;
                  if ( (*v22 & 0xBFFFFFFF) == 0x80000000 )
                    break;
                  if ( (v25 & 0x40000000) == 0 )
                  {
                    do
                      v26 = __ldrex(v22);
                    while ( v26 == v25 && __strex(v25 | 0x40000000, v22) );
                    __dmb(0xBu);
                  }
                  __dmb(0xAu);
                  __yield();
                }
              }
              if ( (v19[7] & 8) != 0 )
              {
                if ( (dword_682604 & 0x10000) != 0 )
                {
                  ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v19 + 9, vars4);
                }
                else
                {
                  __dmb(0xBu);
                  *v22 = 0;
                }
                __dmb(0xBu);
                v27 = (unsigned int *)(v48 + 12);
                do
                  v28 = __ldrex(v27);
                while ( __strex(v28 & 0x7FFFFFFF, v27) );
                v17 = v46;
                goto LABEL_78;
              }
              if ( !v42 )
              {
                v51 = ObFastReferenceObjectLocked(v19 + 8);
                v42 = v19;
              }
              if ( (dword_682604 & 0x10000) != 0 )
              {
                ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v19 + 9, vars4);
              }
              else
              {
                __dmb(0xBu);
                *v22 = 0;
              }
              MiUnlinkPageFromList(v48, 1);
              if ( (dword_682604 & 0x10000) != 0 )
              {
                KiReleaseQueuedSpinLockInstrumented(&v55, vars4);
              }
              else
              {
                v29 = v55;
                if ( !v55 )
                {
                  v30 = v56;
                  __dmb(0xBu);
                  do
                    v31 = (int *)__ldrex(v30);
                  while ( v31 == &v55 && __strex(0, v30) );
                  if ( v31 == &v55 )
                    goto LABEL_75;
                  v29 = KxWaitForLockChainValid(&v55);
                }
                v55 = 0;
                __dmb(0xBu);
                v32 = (unsigned int *)(v29 + 4);
                do
                  v33 = __ldrex(v32);
                while ( __strex(v33 ^ 1, v32) );
              }
LABEL_75:
              *(_DWORD *)(v48 + 12) &= 0xC0000000;
              *(_BYTE *)(v48 + 18) &= 0xEFu;
              MiPfnReferenceCountIsZero(v48, v46);
              __dmb(0xBu);
              v34 = (unsigned int *)(v48 + 12);
              do
                v35 = __ldrex(v34);
              while ( __strex(v35 & 0x7FFFFFFF, v34) );
              KfLowerIrql(v47);
              ++dword_632EE0;
              v47 = KfRaiseIrql(2);
              KeAcquireInStackQueuedSpinLockAtDpcLevel(v16 + 516, &v55);
              v17 = v16[514];
              v46 = v17;
LABEL_78:
              v14 = v42;
              continue;
            }
          }
        }
        while ( v17 != 0xFFFFF );
        v15 = v49;
LABEL_81:
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseQueuedSpinLockInstrumented(&v55, vars4);
          goto LABEL_91;
        }
        v36 = v55;
        if ( v55 )
        {
LABEL_89:
          v55 = 0;
          __dmb(0xBu);
          v39 = (unsigned int *)(v36 + 4);
          do
            v40 = __ldrex(v39);
          while ( __strex(v40 ^ 1, v39) );
        }
        else
        {
          v37 = v56;
          __dmb(0xBu);
          do
            v38 = (int *)__ldrex(v37);
          while ( v38 == &v55 && __strex(0, v37) );
          if ( v38 != &v55 )
          {
            v36 = KxWaitForLockChainValid(&v55);
            goto LABEL_89;
          }
        }
LABEL_91:
        result = KfLowerIrql(v47);
        v16 += 5;
        --v15;
        v14 = v42;
        v49 = v15;
        if ( !v15 )
        {
          if ( v42 )
          {
            a1[704] = v51;
            a1[705] = -1073741566;
            a1[702] = MiLdwPopupWorker;
            a1[703] = a1 + 700;
            a1[700] = 0;
            result = ExQueueWorkItem(a1 + 700, 1);
            ++dword_632EDC;
          }
          else
          {
            __dmb(0xBu);
            do
              v41 = __ldrex(v54);
            while ( __strex(0, v54) );
            if ( !v52 )
              KeBugCheckEx(v10, a1[992], v44, v43, v45);
          }
          return result;
        }
      }
    }
  }
  return result;
}
