// EtwpReserveTraceBuffer 
 
int __fastcall EtwpReserveTraceBuffer(_DWORD *a1, unsigned int a2, unsigned int *a3, __int64 *a4, int a5)
{
  unsigned int v7; // r2
  unsigned int v8; // lr
  int v9; // r1
  _DWORD *v10; // r10
  _DWORD *v11; // r8
  unsigned int v12; // r0
  unsigned int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r4
  int result; // r0
  unsigned int *v17; // r9
  unsigned int v18; // r5
  int (*v19)(); // r3
  __int64 v20; // r0
  unsigned int *v21; // r2
  unsigned int v22; // r1
  unsigned int *v23; // r9
  unsigned int v24; // r2
  unsigned int v25; // r4
  int v26; // r2
  int v27; // r3
  unsigned __int8 *v28; // r4
  unsigned __int8 v29; // r5
  unsigned int v30; // r0
  unsigned int v31; // r2
  unsigned int v32; // r3
  unsigned int v33; // r5
  int v34; // r3
  int v35; // r3
  __int16 v36; // r3
  unsigned __int8 *v37; // r3
  unsigned int v38; // r2
  int v39; // r2
  int v40; // r1
  unsigned int v41; // r2
  unsigned int *v42; // r2
  unsigned int v43; // r1
  unsigned int v44; // r1
  unsigned int v45; // r0
  unsigned int v46; // r2
  unsigned int v47; // [sp+8h] [bp-50h]
  unsigned int v48; // [sp+Ch] [bp-4Ch]
  unsigned int v49; // [sp+10h] [bp-48h]
  int v51; // [sp+20h] [bp-38h]
  int v52; // [sp+24h] [bp-34h]
  unsigned int v53; // [sp+28h] [bp-30h]
  __int64 v54[5]; // [sp+30h] [bp-28h] BYREF

  if ( (int)a1[4] >= 0 && a2 <= a1[2] )
  {
    v7 = a1[1];
    v8 = (a2 + 7) & 0xFFFFFFF8;
    v9 = *a1 + 32;
    v51 = v9;
    v48 = v7;
    v52 = *a1;
    while ( 1 )
    {
      v10 = *(_DWORD **)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x138C);
      if ( (a1[3] & 0x10000000) != 0 )
        v11 = a1 + 22;
      else
        v11 = &v10[v9];
      v12 = 0;
      __pld(v11);
      v47 = 0;
      v13 = *v11;
      if ( (*v11 & 7) != 0 )
      {
        do
        {
          do
            v14 = __ldrex(v11);
          while ( v14 == v13 && __strex(v13 - 1, v11) );
          __dmb(0xBu);
          if ( v14 == v13 )
            break;
          v13 = v14;
        }
        while ( (v14 & 7) != 0 );
        v12 = 0;
        v7 = v48;
      }
      if ( !v13 )
      {
        v15 = 0;
        goto LABEL_27;
      }
      if ( (v13 & 7) == 0 )
        break;
      v15 = v13 & 0xFFFFFFF8;
      if ( (v13 & 7) == 1 )
        return sub_51808C(0);
LABEL_15:
      if ( v15 )
      {
        v17 = (unsigned int *)(v15 + 8);
        v18 = *(_DWORD *)(v15 + 8);
        __dmb(0xBu);
        if ( v18 <= v7 )
        {
          while ( 1 )
          {
            v19 = (int (*)())a1[8];
            if ( v19 == EtwpGetPerfCounter )
            {
              KeQueryPerformanceCounter(v54, 0);
              v20 = v54[0];
            }
            else
            {
              LODWORD(v20) = ((int (__fastcall *)(unsigned int))v19)(v12);
            }
            *a4 = v20;
            __dmb(0xBu);
            do
              v12 = __ldrex(v17);
            while ( v12 == v18 && __strex(v18 + v8, v17) );
            __dmb(0xBu);
            if ( v18 == v12 )
              break;
            v18 = v12;
            if ( v12 > v48 )
              goto LABEL_27;
          }
          if ( v12 + v8 <= v48 )
          {
            ++*(_QWORD *)&v10[2 * v52 + 96];
            a3[1] = (unsigned int)v11;
            a3[2] = v12;
            result = v12 + v15;
            *a3 = v15;
            return result;
          }
          *(_DWORD *)(v15 + 4) = v12;
        }
      }
LABEL_27:
      if ( EtwpSwitchBuffer(a1, v15, v11, *v10, a5) < 0 )
        goto LABEL_35;
      v7 = v48;
      v9 = v51;
    }
    if ( a1[56] != 1 )
    {
      v12 = KfRaiseIrql(15);
      v47 = v12;
      v23 = a1 + 127;
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(a1 + 127);
        v12 = v47;
      }
      else
      {
        do
          v24 = __ldrex(v23);
        while ( __strex(1u, v23) );
        __dmb(0xBu);
        if ( v24 )
        {
          KxWaitForSpinLockAndAcquire(a1 + 127);
          v12 = v47;
        }
      }
LABEL_83:
      v15 = *v11 & 0xFFFFFFF8;
      if ( v15 )
      {
        __dmb(0xBu);
        v42 = (unsigned int *)(v15 + 12);
        do
          v43 = __ldrex(v42);
        while ( __strex(v43 + 1, v42) );
        __dmb(0xBu);
      }
      if ( a1[56] == 1 )
      {
        __pld(v23);
        v44 = *v23;
        if ( (*v23 & 0xFFFFFFF0) <= 0x10 )
          v45 = 0;
        else
          v45 = v44 - 16;
        if ( (v44 & 2) != 0 )
          goto LABEL_100;
        __dmb(0xBu);
        do
          v46 = __ldrex(v23);
        while ( v46 == v44 && __strex(v45, v23) );
        if ( v46 != v44 )
LABEL_100:
          ExfReleasePushLock(v23);
        v12 = KeAbPostRelease(v23);
      }
      else
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v23);
          v12 = v47;
        }
        else
        {
          __dmb(0xBu);
          *v23 = 0;
        }
        v12 = KfLowerIrql(v12);
      }
      v7 = v48;
      goto LABEL_15;
    }
    v23 = a1 + 127;
    if ( !KiAbEnabled || ((unsigned int)v23 & 0x7FFFFFFC) == 0 )
    {
      v33 = 0;
      do
LABEL_78:
        v41 = __ldrex((unsigned __int8 *)v23);
      while ( __strex(v41 | 1, (unsigned __int8 *)v23) );
      __dmb(0xBu);
      if ( (v41 & 1) != 0 )
      {
        ExfAcquirePushLockExclusiveEx(a1 + 127, v33, a1 + 127);
        v12 = 0;
      }
      if ( v33 )
        *(_BYTE *)(v33 + 14) |= 1u;
      goto LABEL_83;
    }
    v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v49 = v25;
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v26 = 0;
    }
    else
    {
      __disable_irq();
      v26 = 1;
    }
    v27 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v26 )
      __enable_irq();
    if ( (v27 & 0x10001) != 0 )
    {
      KeGetCurrentIrql(0);
      KeBugCheckEx(402, v25, a1 + 127);
    }
    --*(_WORD *)(v25 + 310);
    if ( !*(_BYTE *)(v25 + 484) )
    {
      if ( !*(_BYTE *)(v25 + 810) )
      {
        v33 = 0;
        if ( (dword_682604 & 0x200) != 0 )
        {
          EtwTraceAutoBoostEntryExhaustion(v25, a1 + 127);
          v12 = 0;
        }
        goto LABEL_71;
      }
      v28 = (unsigned __int8 *)(v25 + 810);
      v29 = *v28;
      __dmb(0xBu);
      do
        v30 = __ldrex(v28);
      while ( __strex(v30 & ~v29, v28) );
      __dmb(0xBu);
      v25 = v49;
      v12 = 0;
      *(_BYTE *)(v49 + 484) |= v29;
    }
    v31 = *(unsigned __int8 *)(v25 + 484);
    v53 = __clz(__rbit(v31));
    *(_BYTE *)(v25 + 484) = v31 & ~(unsigned __int8)(1 << v53);
    v32 = v25 + 48 * v53;
    v33 = v32 + 488;
    if ( v32 != -488 )
    {
      if ( (unsigned int)v23 >= dword_63389C
        && ((v34 = *((unsigned __int8 *)&MiState[2423]
                   + ((int)((((unsigned int)v23 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
             v34 == 1)
         || v34 == 11)
        && (v39 = *(_DWORD *)(v25 + 116), (v40 = *(_DWORD *)(v39 + 324)) != 0)
        && v39 != PsInitialSystemProcess )
      {
        v35 = *(_DWORD *)(v40 + 8);
      }
      else
      {
        v35 = -1;
      }
      *(_DWORD *)(v33 + 20) = v35;
      *(_DWORD *)(v33 + 16) = (unsigned int)v23 & 0x7FFFFFFC;
LABEL_66:
      v36 = *(_WORD *)(v25 + 310) + 1;
      *(_WORD *)(v25 + 310) = v36;
      if ( !v36 && *(_DWORD *)(v25 + 100) != v25 + 100 )
      {
        KiCheckForKernelApcDelivery(0);
        v12 = 0;
      }
      goto LABEL_78;
    }
LABEL_71:
    v37 = (unsigned __int8 *)(v25 + 81);
    do
      v38 = __ldrex(v37);
    while ( __strex(v38 | 0x80, v37) );
    goto LABEL_66;
  }
LABEL_35:
  __dmb(0xBu);
  v21 = a1 + 42;
  do
    v22 = __ldrex(v21);
  while ( __strex(v22 + 1, v21) );
  __dmb(0xBu);
  if ( (a1[152] & 8) != 0 )
    a1[88] = 1;
  return 0;
}
