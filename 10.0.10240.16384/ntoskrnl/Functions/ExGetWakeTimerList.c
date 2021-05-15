// ExGetWakeTimerList 
 
int __fastcall ExGetWakeTimerList(_DWORD *a1, int a2)
{
  unsigned int *v2; // r9
  unsigned int v3; // r8
  unsigned int v4; // r7
  __int16 v5; // r3
  int v6; // r0
  int v7; // r5
  unsigned int v8; // r2
  int *v9; // r5
  _DWORD *v10; // r0
  unsigned int v11; // r1
  _DWORD *v12; // r0
  _DWORD *v13; // r4
  int v14; // r6
  unsigned int *v15; // r3
  unsigned int v16; // r2
  int *v17; // r9
  unsigned int v18; // r7
  unsigned int *v19; // r1
  unsigned int v20; // r2
  int v21; // r3
  __int64 v22; // r0
  int v23; // lr
  unsigned int v24; // r0
  int v25; // r2
  unsigned int v26; // r1
  bool v27; // cf
  unsigned int v28; // r3
  unsigned int *v29; // r1
  _DWORD *v30; // r0
  unsigned int *v31; // r3
  _DWORD *v32; // r3
  unsigned int v33; // r1
  int v34; // r0
  __int16 v35; // r3
  unsigned int v37; // [sp+0h] [bp-48h] BYREF
  unsigned int v38; // [sp+4h] [bp-44h]
  unsigned int *v39; // [sp+8h] [bp-40h]
  unsigned int *v40; // [sp+Ch] [bp-3Ch]
  unsigned int v41; // [sp+10h] [bp-38h]
  int v42; // [sp+14h] [bp-34h]
  int v43; // [sp+18h] [bp-30h]
  unsigned int v44; // [sp+1Ch] [bp-2Ch]
  _DWORD *v45; // [sp+20h] [bp-28h]
  _DWORD *v46; // [sp+24h] [bp-24h]
  int vars4; // [sp+4Ch] [bp+4h]

  v2 = (unsigned int *)a2;
  v39 = (unsigned int *)a2;
  v46 = a1;
  v3 = 0;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(_WORD *)(v4 + 0x134);
  v38 = v4;
  *(_WORD *)(v4 + 308) = v5 - 1;
  v6 = KeAbPreAcquire((unsigned int)&ExpWakeTimerLock, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex((unsigned __int8 *)&ExpWakeTimerLock);
  while ( __strex(v8 | 1, (unsigned __int8 *)&ExpWakeTimerLock) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&ExpWakeTimerLock, v6, (unsigned int)&ExpWakeTimerLock);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v9 = (int *)ExpWakeTimerList;
  if ( (int *)ExpWakeTimerList == &ExpWakeTimerList )
    goto LABEL_13;
  do
  {
    v10 = (_DWORD *)*(v9 - 1);
    if ( v10 )
    {
      v37 = 0;
      PoStoreDiagnosticContext(v10, 0, &v37, 0);
      v3 = (v37 + v3 + 27) & 0xFFFFFFF8;
    }
    v9 = (int *)*v9;
  }
  while ( v9 != &ExpWakeTimerList );
  if ( !v3 )
LABEL_13:
    v11 = 48;
  else
    v11 = v3;
  v12 = (_DWORD *)ExAllocatePoolWithQuotaTag(9u, v11, 1934388055);
  v13 = v12;
  if ( v12 )
  {
    v15 = v12;
    v14 = 0;
    v40 = v12;
    if ( v3 )
    {
      v16 = v3;
      v17 = (int *)ExpWakeTimerList;
      v18 = 0;
      v41 = v3;
      while ( v17 != &ExpWakeTimerList )
      {
        if ( v16 < 0x30 )
          goto LABEL_56;
        v43 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented((int)(v17 - 26));
        }
        else
        {
          v19 = (unsigned int *)(v17 - 26);
          do
            v20 = __ldrex(v19);
          while ( __strex(1u, v19) );
          __dmb(0xBu);
          if ( v20 )
            KxWaitForSpinLockAndAcquire((unsigned int *)v17 - 26);
        }
        v21 = *(v17 - 1);
        v44 = *(v17 - 3);
        v45 = (_DWORD *)v21;
        if ( v21 )
        {
          v22 = KeQueryTimerDueTime((int)(v17 - 38));
          v42 = HIDWORD(v22);
          v37 = v22;
        }
        else
        {
          v37 = 0;
          v42 = 0;
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v17 - 26, vars4);
        }
        else
        {
          __dmb(0xBu);
          *(v17 - 26) = 0;
        }
        KfLowerIrql(v43);
        v23 = v42;
        v24 = v37;
        if ( v37 | v42 )
        {
          while ( 1 )
          {
            v25 = MEMORY[0xFFFF900C];
            __dmb(0xBu);
            v26 = MEMORY[0xFFFF9008];
            __dmb(0xBu);
            if ( v25 == MEMORY[0xFFFF9010] )
              break;
            __dmb(0xAu);
            __yield();
          }
          v27 = v24 >= v26;
          v28 = v24 - v26;
          v29 = v40;
          v30 = v45;
          v40[2] = v28;
          v29[3] = v23 - (v25 + !v27);
          v29[4] = v44;
          v37 = v41 - 20;
          v14 = PoStoreDiagnosticContext(v30, (int)(v29 + 5), &v37, v41 - 20);
          if ( v14 < 0 )
            goto LABEL_43;
          v18 = (v37 + 27) & 0xFFFFFFF8;
          if ( v41 < v18 )
          {
LABEL_56:
            v14 = -1073741789;
            goto LABEL_43;
          }
          v31 = v40;
          v16 = v41 - v18;
          v41 -= v18;
          *v40 = v18;
          v15 = (unsigned int *)((char *)v31 + v18);
          v40 = v15;
        }
        else
        {
          v15 = v40;
          v16 = v41;
        }
        v17 = (int *)*v17;
      }
      v32 = (unsigned int *)((char *)v15 - v18);
      *v32 = 0;
      if ( !v18 )
      {
        v32[2] = 0;
        v32[3] = 0;
      }
LABEL_43:
      v4 = v38;
      v2 = v39;
    }
    else
    {
      v12[2] = 0;
      v12[3] = 0;
      *v12 = 0;
      v3 = 48;
    }
  }
  else
  {
    v14 = -1073741670;
  }
  __dmb(0xBu);
  do
    v33 = __ldrex((unsigned int *)&ExpWakeTimerLock);
  while ( __strex(v33 - 1, (unsigned int *)&ExpWakeTimerLock) );
  if ( (v33 & 2) != 0 && (v33 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&ExpWakeTimerLock);
  v34 = KeAbPostRelease((unsigned int)&ExpWakeTimerLock);
  v35 = *(_WORD *)(v4 + 308) + 1;
  *(_WORD *)(v4 + 308) = v35;
  if ( !v35 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
    KiCheckForKernelApcDelivery(v34);
  if ( v14 >= 0 )
  {
    *v46 = v13;
    *v2 = v3;
  }
  else if ( v13 )
  {
    ExFreePoolWithTag(v13);
  }
  return v14;
}
