// MmAdjustWorkingSetSizeEx 
 
void __fastcall MmAdjustWorkingSetSizeEx(unsigned int a1, unsigned int a2, int a3, int a4, int a5, _BYTE *a6)
{
  int v9; // r2
  _DWORD *v10; // r9
  int v11; // r5
  unsigned __int8 *v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r3
  unsigned int v16; // r3
  int v17; // r2
  unsigned int v18; // r3
  unsigned int v19; // r10
  unsigned int v20; // r7
  unsigned int v21; // r3
  unsigned int v22; // r9
  char v23; // r3
  int v24; // r0
  unsigned int *v25; // r1
  int *v26; // r0
  char v27; // r3
  int v28; // r1
  unsigned int v29; // r0
  int v30; // r1
  unsigned int v31; // r0
  unsigned int *v32; // r2
  unsigned int v33; // r0
  unsigned int v34; // r1
  unsigned int v35; // r0
  int v36; // r4
  int v37; // r0
  int v38; // r1
  unsigned int v39; // r0
  unsigned int v40; // [sp+8h] [bp-40h] BYREF
  unsigned int v41; // [sp+Ch] [bp-3Ch] BYREF
  _DWORD *v42; // [sp+10h] [bp-38h]
  int v43; // [sp+14h] [bp-34h]
  int v44; // [sp+18h] [bp-30h]
  int v45; // [sp+1Ch] [bp-2Ch]
  int var28[12]; // [sp+20h] [bp-28h] BYREF

  v44 = a4;
  *a6 = 0;
  v9 = __mrc(15, 0, 13, 0, 3);
  v42 = 0;
  if ( a3 )
  {
    sub_510084();
    return;
  }
  v10 = *(_DWORD **)((v9 & 0xFFFFFFC0) + 0x74);
  v42 = v10;
  v11 = (int)(v10 + 123);
  if ( a1 != -1 || a2 != -1 )
  {
    v45 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v10 + 123);
    }
    else
    {
      v12 = (unsigned __int8 *)v10 + 495;
      do
        v13 = __ldrex(v12);
      while ( __strex(v13 | 0x80, v12) );
      __dmb(0xBu);
      if ( v13 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v10 + 123);
      while ( 1 )
      {
        v14 = *(_DWORD *)v11;
        if ( (*(_DWORD *)v11 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v14 & 0x40000000) == 0 )
        {
          do
            v34 = __ldrex((unsigned int *)v11);
          while ( v34 == v14 && __strex(v14 | 0x40000000, (unsigned int *)v11) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    if ( (v10[48] & 0x20) != 0 )
      goto LABEL_32;
    v15 = a1 ? a1 >> 12 : v10[135];
    v40 = v15;
    v16 = a2 ? a2 >> 12 : v10[140];
    v41 = v16;
    if ( (MiCheckWsLimits((int)(v10 + 123), &v40, &v41, a5, 0) & 0xC0000000) == -1073741824 )
      goto LABEL_32;
    v17 = v10[146];
    v18 = v10[135];
    v19 = v40;
    v43 = v17;
    if ( v40 <= v18 )
    {
      v20 = v18 - v40;
      if ( v40 < *(_DWORD *)(v17 + 4) )
        goto LABEL_32;
LABEL_18:
      v21 = v10[136];
      v22 = v41;
      if ( v41 < v21 && v41 < *(_DWORD *)(v17 + 16) )
      {
        if ( *(_DWORD *)(v17 + 4) + 4 >= v41 )
        {
          if ( *a6 == 1 )
          {
            v36 = *(_DWORD *)(v11 + 48);
            *(_DWORD *)(v11 + 48) = v19;
            MiChargeWsles(v11, -v20, 1);
            v37 = (int)v42;
            *(_DWORD *)(v11 + 48) = v36;
            PsReturnProcessQuota(v37, v38, v20);
            MiReturnResidentAvailable(v20);
            do
              v39 = __ldrex(&dword_634A2C[2]);
            while ( __strex(v39 + v20, &dword_634A2C[2]) );
          }
          goto LABEL_32;
        }
        *(_BYTE *)(v11 + 115) |= 0x20u;
      }
      if ( v20 && !*a6 )
      {
        MiChargeWsles(v11, -v20, 1);
        PsReturnProcessQuota((int)v42, v28, v20);
        MiReturnResidentAvailable(v20);
        do
          v29 = __ldrex(&dword_634A2C[3]);
        while ( __strex(v29 + v20, &dword_634A2C[3]) );
      }
      *(_DWORD *)(v11 + 68) = v22;
      *(_DWORD *)(v11 + 48) = v19;
      if ( !a5 )
        goto LABEL_32;
      KeAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)&dword_634980, var28);
      if ( (a5 & 4) != 0 )
      {
        v27 = *(_BYTE *)(v11 + 112) | 0x80;
      }
      else
      {
        if ( (a5 & 8) == 0 )
          goto LABEL_23;
        v27 = *(_BYTE *)(v11 + 112) & 0x7F;
      }
      *(_BYTE *)(v11 + 112) = v27;
LABEL_23:
      if ( (a5 & 1) != 0 )
      {
        v23 = *(_BYTE *)(v11 + 112) | 0x40;
      }
      else
      {
        if ( (a5 & 2) == 0 )
        {
LABEL_26:
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseQueuedSpinLockInstrumented(var28, var28[11]);
          }
          else
          {
            v24 = var28[0];
            if ( !var28[0] )
            {
              v25 = (unsigned int *)var28[1];
              __dmb(0xBu);
              do
                v26 = (int *)__ldrex(v25);
              while ( v26 == var28 && __strex(0, v25) );
              if ( v26 == var28 )
                goto LABEL_32;
              v24 = KxWaitForLockChainValid(var28);
            }
            var28[0] = 0;
            __dmb(0xBu);
            v32 = (unsigned int *)(v24 + 4);
            do
              v33 = __ldrex(v32);
            while ( __strex(v33 ^ 1, v32) );
          }
LABEL_32:
          MiUnlockWorkingSetExclusive(v11, v45);
          return;
        }
        v23 = *(_BYTE *)(v11 + 112) & 0xBF;
      }
      *(_BYTE *)(v11 + 112) = v23;
      goto LABEL_26;
    }
    v20 = v40 - v18;
    *a6 = 1;
    if ( !v44 || PsChargeProcessQuota((int)v10, 1, v20) < 0 )
      goto LABEL_32;
    if ( MiChargeResident(MiSystemPartition, v20, 512) )
    {
      do
        v31 = __ldrex(dword_634A2C);
      while ( __strex(v31 + v20, dword_634A2C) );
      if ( MiChargeWsles((int)(v10 + 123), v20, 1) )
      {
        v17 = v43;
        goto LABEL_18;
      }
      MiReturnResidentAvailable(v20);
      do
      {
        v35 = __ldrex(&dword_634A2C[1]);
        v30 = v35 + v20;
      }
      while ( __strex(v35 + v20, &dword_634A2C[1]) );
    }
    PsReturnProcessQuota((int)v10, v30, v20);
    goto LABEL_32;
  }
  MiEmptyWorkingSet(v10 + 123, 17, 0);
}
