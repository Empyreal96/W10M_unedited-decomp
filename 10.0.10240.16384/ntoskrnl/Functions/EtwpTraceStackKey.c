// EtwpTraceStackKey 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall EtwpTraceStackKey(int a1, int a2, int a3, int a4, unsigned __int16 *a5, unsigned int a6)
{
  int v6; // r6
  int v7; // r5
  unsigned int v8; // r5
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3
  int v12; // r3
  int v13; // r4
  int v14; // r4
  unsigned int v15; // r5
  unsigned int v16; // r6
  unsigned int v17; // r0
  unsigned __int16 *v18; // r1
  int v19; // r2
  int v20; // t1
  unsigned int v21; // r0
  int v22; // r7
  int v23; // r10
  int v24; // r0
  unsigned int *v25; // r8
  BOOL v26; // r0
  unsigned int *v27; // r4
  int v28; // r9
  unsigned int *v29; // r6
  unsigned int v30; // r5
  unsigned int *v31; // r2
  unsigned int v32; // r1
  unsigned int *v33; // r1 OVERLAPPED
  unsigned int **v34; // r2 OVERLAPPED
  unsigned int *v35; // r2
  unsigned int v36; // r2
  unsigned int v37; // r2
  _QWORD *v38; // r10
  __int64 v39; // kr00_8
  __int64 v40; // r2
  int v41; // r5
  unsigned int v42; // r9
  int v43; // r7
  int v44; // r10
  int v45; // r0
  int v46; // r4
  int v47; // r10
  int v48; // r4
  int *v49; // r2
  int *v50; // r0
  int v51; // r0
  unsigned int v52; // r1
  __int16 v53; // r3
  unsigned int v55; // [sp+8h] [bp-50h]
  int v56; // [sp+Ch] [bp-4Ch]
  _DWORD *v57; // [sp+10h] [bp-48h]
  int v58; // [sp+14h] [bp-44h]
  unsigned int *v60; // [sp+1Ch] [bp-3Ch] BYREF
  int v61; // [sp+20h] [bp-38h]
  int v62; // [sp+24h] [bp-34h]
  int *v63; // [sp+28h] [bp-30h]
  int v64; // [sp+2Ch] [bp-2Ch]
  int v65; // [sp+30h] [bp-28h]
  int v66; // [sp+34h] [bp-24h]
  int vars4; // [sp+5Ch] [bp+4h]

  v6 = a1;
  v7 = 0;
  v63 = (int *)a4;
  v64 = a2;
  v65 = a3;
  v61 = 0;
  if ( (unsigned int)KeGetCurrentIrql(a1) < 2 )
  {
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v8 + 308);
    v9 = ExAcquireRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v6], 1);
    if ( !v9 )
    {
LABEL_3:
      v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v11 = *(_WORD *)(v10 + 0x134) + 1;
      *(_WORD *)(v10 + 308) = v11;
      if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
        KiCheckForKernelApcDelivery(v9);
      return 0;
    }
    v7 = 1;
    v61 = 1;
  }
  v12 = WmipLoggerContext[v6];
  v66 = v12;
  if ( (v12 & 1) != 0 )
  {
    if ( v7 )
    {
      v9 = ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v6], 1);
      goto LABEL_3;
    }
    return 0;
  }
  if ( !v12 )
    return 0;
  v14 = *(_DWORD *)(v12 + 624);
  v58 = v14;
  if ( v14 )
  {
    v15 = a6;
    v16 = 0;
    v55 = 0;
    v57 = 0;
    if ( 2 * a6 )
    {
      v17 = ((2 * a6 - 1) >> 1) + 1;
      v18 = a5;
      do
      {
        v19 = v18[1];
        v20 = *v18;
        v18 += 2;
        v16 += v20 ^ v19;
        --v17;
      }
      while ( v17 );
      v55 = v16;
    }
    v21 = *(_DWORD *)(v14 + 4);
    if ( !v21 )
      __brkdiv0();
    v22 = v14 + 12 * (v16 % v21) + 16;
    v62 = v22;
    v23 = 0;
    v24 = KeGetCurrentIrql(v16 / v21);
    v56 = v24;
    if ( v24 < 0 )
      goto LABEL_24;
    if ( v24 <= 1 )
    {
      KfRaiseIrql(2);
    }
    else if ( v24 != 2 )
    {
LABEL_24:
      v25 = (unsigned int *)(v22 + 8);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        v26 = KiTryToAcquireSpinLockInstrumented((unsigned int *)(v22 + 8));
      }
      else
      {
        do
          v37 = __ldrex(v25);
        while ( __strex(1u, v25) );
        __dmb(0xBu);
        v26 = v37 == 0;
        if ( !v37 )
          goto LABEL_29;
        __dmb(0xAu);
        __yield();
      }
      if ( !v26 )
      {
LABEL_50:
        v6 = a1;
        v13 = 0;
        goto LABEL_94;
      }
LABEL_29:
      v27 = *(unsigned int **)v22;
      if ( *(_DWORD *)v22 == v22 )
      {
LABEL_57:
        HIDWORD(v40) = a6;
        v41 = 0;
        v42 = 0;
        if ( a6 )
        {
          v43 = 0;
          while ( 1 )
          {
            v44 = v58;
            v45 = RtlpInterlockedPopEntrySList((unsigned __int64 *)(v58 + 8));
            v46 = v45;
            if ( !v45 )
              break;
            if ( v42 + 32 >= a6 )
              v47 = a6 - v42;
            else
              v47 = 32;
            memmove(v45 + 24, (int)&a5[2 * v42], 4 * v47);
            if ( v42 )
              *(_DWORD *)(v46 + 20) = v47;
            else
              v41 = v46;
            if ( v43 )
              *(_DWORD *)(v43 + 8) = v46;
            v42 += v47;
            v43 = v46;
            *(_DWORD *)(v46 + 8) = 0;
            if ( v42 >= a6 )
            {
              v44 = v58;
              break;
            }
          }
          v22 = v62;
          v25 = (unsigned int *)(v62 + 8);
          if ( v42 < a6 )
          {
            if ( (dword_682604 & 0x10000) != 0 )
            {
              KiReleaseSpinLockInstrumented((_DWORD *)(v62 + 8), vars4);
            }
            else
            {
              __dmb(0xBu);
              *v25 = 0;
            }
            KfLowerIrql(v56);
            if ( v41 )
            {
              do
              {
                v48 = *(_DWORD *)(v41 + 8);
                RtlpInterlockedPushEntrySList((unsigned __int64 *)(v44 + 8), (_DWORD *)v41);
                v41 = v48;
              }
              while ( v48 );
            }
            if ( v57 )
              EtwpDereferenceStackEntry(v57, v44);
            goto LABEL_50;
          }
          HIDWORD(v40) = a6;
        }
        LODWORD(v40) = v55;
        *(_QWORD *)(v41 + 16) = v40;
        *(_DWORD *)(v41 + 12) = 2;
        v49 = *(int **)(v22 + 4);
        *(_DWORD *)v41 = v22;
        *(_DWORD *)(v41 + 4) = v49;
        if ( *v49 != v22 )
          __fastfail(3u);
        *v49 = v41;
        *(_DWORD *)(v22 + 4) = v41;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v25, vars4);
        }
        else
        {
          __dmb(0xBu);
          *v25 = 0;
        }
        KfLowerIrql(v56);
        if ( v57 )
          EtwpDereferenceStackEntry(v57, v58);
        v60 = (unsigned int *)v41;
      }
      else
      {
        while ( 1 )
        {
          ++v23;
          if ( v27[4] == v16 && v27[5] == v15 )
            break;
LABEL_52:
          v27 = (unsigned int *)*v27;
          if ( v27 == (unsigned int *)v22 )
          {
            if ( v23 == 4 )
            {
              v38 = *(_QWORD **)(v22 + 4);
              v39 = *v38;
              v57 = v38;
              if ( *(_DWORD *)v38 != v22 || *(_QWORD **)HIDWORD(v39) != v38 )
                __fastfail(3u);
              *(_DWORD *)(v22 + 4) = HIDWORD(v39);
              *(_DWORD *)HIDWORD(v39) = v22;
            }
            goto LABEL_57;
          }
        }
        v28 = 0;
        v29 = v27;
        do
        {
          v30 = v29[5];
          if ( v30 >= 0x20 )
            v30 = 32;
          if ( RtlCompareMemory((unsigned __int8 *)v29 + 24, (int)&a5[2 * v28], 4 * v30) != 4 * v30 )
          {
            v15 = a6;
            v16 = v55;
            goto LABEL_52;
          }
          v29 = (unsigned int *)v29[2];
          v28 += v30;
        }
        while ( v29 );
        __dmb(0xBu);
        v31 = v27 + 3;
        do
          v32 = __ldrex(v31);
        while ( __strex(v32 + 1, v31) );
        __dmb(0xBu);
        *(_QWORD *)&v33 = *(_QWORD *)v27;
        if ( *(unsigned int **)(*v27 + 4) != v27 || *v34 != v27 )
          __fastfail(3u);
        *v34 = v33;
        v33[1] = (unsigned int)v34;
        v35 = *(unsigned int **)v22;
        *v27 = *(_DWORD *)v22;
        v27[1] = v22;
        if ( v35[1] != v22 )
          __fastfail(3u);
        v35[1] = (unsigned int)v27;
        *(_DWORD *)v22 = v27;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v25, vars4);
        }
        else
        {
          __dmb(0xBu);
          *v25 = 0;
        }
        KfLowerIrql(v56);
        v60 = v27;
      }
      v50 = v63;
      v13 = 1;
      v63[4] = (int)&v60;
      v50[5] = 0;
      v50[6] = 4;
      v50[7] = 0;
      v6 = a1;
      EtwpLogKernelEvent(v50, a1, 2, v65, v64);
      EtwpDereferenceStackEntry(v60, *(_DWORD *)(v66 + 624));
      goto LABEL_94;
    }
    v25 = (unsigned int *)(v22 + 8);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v22 + 8);
    }
    else
    {
      do
        v36 = __ldrex(v25);
      while ( __strex(1u, v25) );
      __dmb(0xBu);
      if ( v36 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(v22 + 8));
    }
    goto LABEL_29;
  }
  v13 = 0;
LABEL_94:
  if ( v61 )
  {
    v51 = ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v6], 1);
    v52 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v53 = *(_WORD *)(v52 + 0x134) + 1;
    *(_WORD *)(v52 + 308) = v53;
    if ( !v53 && *(_DWORD *)(v52 + 100) != v52 + 100 && !*(_WORD *)(v52 + 310) )
      KiCheckForKernelApcDelivery(v51);
  }
  return v13;
}
