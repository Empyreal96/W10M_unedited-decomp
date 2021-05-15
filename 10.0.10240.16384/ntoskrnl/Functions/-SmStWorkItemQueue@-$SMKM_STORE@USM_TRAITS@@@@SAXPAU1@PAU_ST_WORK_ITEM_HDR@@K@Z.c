// -SmStWorkItemQueue@-$SMKM_STORE@USM_TRAITS@@@@SAXPAU1@PAU_ST_WORK_ITEM_HDR@@K@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStWorkItemQueue(int a1, int a2, char a3)
{
  int v6; // r9
  int *v7; // r10
  int result; // r0
  unsigned int *v9; // r4
  int v10; // r8
  unsigned int v11; // r2
  char v12; // r3
  unsigned int *v13; // r2
  unsigned int v14; // r1
  int v15; // r4
  unsigned int *v16; // r7
  unsigned int v17; // r2
  unsigned int v18; // r3
  int v19; // r1
  int v20; // r3
  int v21; // r3
  int v22; // r3
  int v23; // r3
  int i; // r2
  int v25; // r1
  int v26; // r2
  int v27; // r6
  int v28; // r4
  int v29; // r2
  int v30; // r3
  int v31; // r6
  unsigned int *v32; // r2
  unsigned int v33; // r1
  int v34; // [sp+0h] [bp-28h]
  int v35; // [sp+4h] [bp-24h]
  int vars4; // [sp+2Ch] [bp+4h]

  v6 = *(_DWORD *)a2 & 7;
  v7 = (int *)(a1 + 3572);
  if ( v6 == 2 && (*(_BYTE *)(a1 + 3517) & 4) != 0 )
  {
    result = SMKM_STORE<SM_TRAITS>::SmStDirectRead(a1, (int *)a2);
    if ( !result )
    {
      v9 = (unsigned int *)(a1 + 3856);
      v10 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(a1 + 3856);
      }
      else
      {
        do
          v11 = __ldrex(v9);
        while ( __strex(1u, v9) );
        __dmb(0xBu);
        if ( v11 )
          KxWaitForSpinLockAndAcquire((unsigned int *)(a1 + 3856));
      }
      *(_DWORD *)a2 = *(_DWORD *)a2 & 7 | (8 * ((**(_DWORD **)(a1 + 3852) >> 3) + 1));
      **(_DWORD **)(a1 + 3852) = **(_DWORD **)(a1 + 3852) & 7 | a2;
      *(_DWORD *)(a1 + 3852) = a2;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented((_DWORD *)(a1 + 3856), vars4);
      }
      else
      {
        __dmb(0xBu);
        *v9 = 0;
      }
      KfLowerIrql(v10);
      result = KeSetEvent(a1 + 3832, 0, 0);
    }
  }
  else
  {
    v12 = *(_BYTE *)(a1 + 3517);
    result = 1;
    if ( (v12 & 1) == 0 )
    {
      v35 = a3 & 4;
      if ( (a3 & 4) == 0 )
      {
        __dmb(0xBu);
        v13 = (unsigned int *)(a1 + 3952);
        do
          v14 = __ldrex(v13);
        while ( __strex(v14 + 1, v13) );
        __dmb(0xBu);
      }
      if ( (a3 & 1) != 0 )
      {
        v15 = a1 + 3560;
      }
      else if ( v6 != 2 || (*(_BYTE *)(a2 + 7) & 1) != 0 )
      {
        v15 = a1 + 3552;
      }
      else
      {
        v15 = a1 + 3544;
        v7 = (int *)(a1 + 3568);
      }
      v16 = (unsigned int *)(a1 + 3536);
      v34 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(a1 + 3536);
      }
      else
      {
        do
          v17 = __ldrex(v16);
        while ( __strex(1u, v16) );
        __dmb(0xBu);
        if ( v17 )
          KxWaitForSpinLockAndAcquire((unsigned int *)(a1 + 3536));
      }
      v18 = **(_DWORD **)(v15 + 4);
      if ( (a3 & 2) != 0 )
      {
        v19 = (v18 >> 3) + 1;
        *(_DWORD *)a2 = *(_DWORD *)v15 | *(_DWORD *)a2 & 7;
        v20 = *(_DWORD *)(v15 + 4);
        *(_DWORD *)v15 = a2;
        if ( v20 == v15 )
          *(_DWORD *)(v15 + 4) = a2;
        **(_DWORD **)(v15 + 4) = **(_DWORD **)(v15 + 4) & 7 | (8 * v19);
      }
      else
      {
        *(_DWORD *)a2 = *(_DWORD *)a2 & 7 | (8 * ((v18 >> 3) + 1));
        **(_DWORD **)(v15 + 4) = **(_DWORD **)(v15 + 4) & 7 | a2;
        *(_DWORD *)(v15 + 4) = a2;
      }
      v21 = *(_DWORD *)(a1 + 3572);
      __dmb(0xBu);
      if ( !v21 )
      {
        v22 = *(_DWORD *)(a1 + 3568);
        __dmb(0xBu);
        if ( !v22 )
          KeQueryTickCount((int *)(a1 + 3584));
      }
      v23 = *v7 + 1;
      __dmb(0xBu);
      *v7 = v23;
      if ( v6 == 2 && *(_BYTE *)(a1 + 3516) )
      {
        for ( i = *(_DWORD *)(*(_DWORD *)(a1 + 1592) + 16); *(_DWORD *)i < *(unsigned __int8 *)(a2 + 4) << 12; i += 32 )
          ;
        *(_WORD *)(i + 4) = 0;
        *(_QWORD *)(a1 + 3592) += *(_QWORD *)(i + 8);
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented((_DWORD *)(a1 + 3536), vars4);
      }
      else
      {
        __dmb(0xBu);
        *v16 = 0;
      }
      result = KfLowerIrql(v34);
      v25 = __mrc(15, 0, 13, 0, 3);
      if ( !v35 )
      {
        v26 = *(unsigned __int8 *)(a1 + 3518);
        if ( v26 == 4 )
          v27 = *(_DWORD *)(a1 + 3948);
        else
          v27 = `SMKM_STORE<SM_TRAITS>::SmStGetDesiredStoreWorkerPriority'::`2'::PriorityByMemoryCondition[v26];
        if ( (a3 & 1) != 0 )
        {
          v28 = 12;
        }
        else
        {
          if ( v6 != 2 )
            goto LABEL_60;
          if ( (__get_CPSR() & 0x80) != 0 )
          {
            v29 = 0;
          }
          else
          {
            __disable_irq();
            v29 = 1;
          }
          v30 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
          if ( v29 )
            __enable_irq();
          if ( (v30 & 0x10001) != 0 )
LABEL_60:
            v28 = v27;
          else
            v28 = KeQueryPriorityThread(v25 & 0xFFFFFFC0);
        }
        if ( v28 <= v27 )
          v28 = v27;
        v31 = *(_DWORD *)(a1 + 3648);
        if ( v28 > KeQueryPriorityThread(v31) )
          KeSetActualBasePriorityThread(v31, v28);
        result = KeSetEvent(a1 + 3600, 0, 0);
        __dmb(0xBu);
        v32 = (unsigned int *)(a1 + 3952);
        do
          v33 = __ldrex(v32);
        while ( __strex(v33 - 1, v32) );
        __dmb(0xBu);
      }
    }
  }
  return result;
}
