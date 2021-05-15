// MmAdjustWorkingSetSizeEx 
 
int __fastcall MmAdjustWorkingSetSizeEx(unsigned int a1, unsigned int a2, int a3, int a4, int a5, _BYTE *a6)
{
  int v9; // r2
  _DWORD *v11; // r9
  unsigned int *v12; // r5
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r3
  unsigned int v17; // r3
  int v18; // r6
  unsigned int *v19; // r2
  unsigned int v20; // r3
  unsigned int v21; // r10
  unsigned int v22; // r7
  unsigned int v23; // r3
  unsigned int v24; // r9
  unsigned int v25; // r3
  char v26; // r3
  int v27; // r0
  unsigned int *v28; // r1
  int *v29; // r0
  char v30; // r3
  unsigned int v31; // r0
  unsigned int v32; // r0
  unsigned int *v33; // r2
  unsigned int v34; // r0
  unsigned int v35; // r1
  unsigned int v36; // r0
  unsigned int v37; // r4
  int v38; // r0
  unsigned int v39; // r0
  unsigned int v40; // [sp+8h] [bp-40h] BYREF
  unsigned int v41; // [sp+Ch] [bp-3Ch] BYREF
  _DWORD *v42; // [sp+10h] [bp-38h]
  unsigned int *v43; // [sp+14h] [bp-34h]
  int v44; // [sp+18h] [bp-30h]
  int v45; // [sp+1Ch] [bp-2Ch]
  int var28[12]; // [sp+20h] [bp-28h] BYREF

  v44 = a4;
  *a6 = 0;
  v9 = __mrc(15, 0, 13, 0, 3);
  v42 = 0;
  if ( a3 )
    return sub_510084(a1, a2, v9, MiState);
  v11 = *(_DWORD **)((v9 & 0xFFFFFFC0) + 0x74);
  v42 = v11;
  v12 = v11 + 123;
  if ( a1 == -1 && a2 == -1 )
    return MiEmptyWorkingSet(v11 + 123, 17, 0);
  v45 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v11 + 123);
  }
  else
  {
    v13 = (unsigned __int8 *)v11 + 495;
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 | 0x80, v13) );
    __dmb(0xBu);
    if ( v14 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v11 + 123);
    while ( 1 )
    {
      v15 = *v12;
      if ( (*v12 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v15 & 0x40000000) == 0 )
      {
        do
          v35 = __ldrex(v12);
        while ( v35 == v15 && __strex(v15 | 0x40000000, v12) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( (v11[48] & 0x20) != 0 )
  {
    v18 = -1073741558;
    goto LABEL_32;
  }
  if ( a1 )
    v16 = a1 >> 12;
  else
    v16 = v11[135];
  v40 = v16;
  if ( a2 )
    v17 = a2 >> 12;
  else
    v17 = v11[140];
  v41 = v17;
  v18 = MiCheckWsLimits(v11 + 123, &v40, &v41, a5, 0);
  if ( (v18 & 0xC0000000) == -1073741824 )
    goto LABEL_32;
  v19 = (unsigned int *)v11[146];
  v20 = v11[135];
  v21 = v40;
  v43 = v19;
  if ( v40 <= v20 )
  {
    v22 = v20 - v40;
    if ( v40 < v19[1] )
    {
      v18 = -1073741748;
      goto LABEL_32;
    }
LABEL_18:
    v23 = v11[136];
    v24 = v41;
    if ( v41 < v23 && v41 < v19[4] )
    {
      if ( v19[1] + 4 >= v41 )
      {
        v18 = -1073741748;
        if ( *a6 == 1 )
        {
          v37 = v12[12];
          v12[12] = v21;
          MiChargeWsles(v12, -v22, 1);
          v38 = (int)v42;
          v12[12] = v37;
          PsReturnProcessQuota(v38);
          MiReturnResidentAvailable(v22);
          do
            v39 = __ldrex(&dword_634A2C[2]);
          while ( __strex(v39 + v22, &dword_634A2C[2]) );
        }
        goto LABEL_32;
      }
      *((_BYTE *)v12 + 115) |= 0x20u;
    }
    v25 = (unsigned __int8)*a6;
    if ( v22 && !*a6 )
    {
      MiChargeWsles(v12, -v22, 1);
      PsReturnProcessQuota(v42);
      MiReturnResidentAvailable(v22);
      v19 = &dword_634A2C[3];
      do
      {
        v31 = __ldrex(&dword_634A2C[3]);
        v25 = __strex(v31 + v22, &dword_634A2C[3]);
      }
      while ( v25 );
    }
    v12[17] = v24;
    v12[12] = v21;
    if ( !a5 )
      goto LABEL_32;
    KeAcquireInStackQueuedSpinLockAtDpcLevel(&dword_634980, var28, v19, v25);
    if ( (a5 & 4) != 0 )
    {
      v30 = *((_BYTE *)v12 + 112) | 0x80;
    }
    else
    {
      if ( (a5 & 8) == 0 )
        goto LABEL_23;
      v30 = v12[28] & 0x7F;
    }
    *((_BYTE *)v12 + 112) = v30;
LABEL_23:
    if ( (a5 & 1) != 0 )
    {
      v26 = *((_BYTE *)v12 + 112) | 0x40;
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
          v27 = var28[0];
          if ( !var28[0] )
          {
            v28 = (unsigned int *)var28[1];
            __dmb(0xBu);
            do
              v29 = (int *)__ldrex(v28);
            while ( v29 == var28 && __strex(0, v28) );
            if ( v29 == var28 )
              goto LABEL_32;
            v27 = KxWaitForLockChainValid(var28);
          }
          var28[0] = 0;
          __dmb(0xBu);
          v33 = (unsigned int *)(v27 + 4);
          do
            v34 = __ldrex(v33);
          while ( __strex(v34 ^ 1, v33) );
        }
        goto LABEL_32;
      }
      v26 = v12[28] & 0xBF;
    }
    *((_BYTE *)v12 + 112) = v26;
    goto LABEL_26;
  }
  v22 = v40 - v20;
  *a6 = 1;
  if ( !v44 )
  {
    v18 = -1073741727;
    goto LABEL_32;
  }
  v18 = PsChargeProcessQuota(v11, 1, v22);
  if ( v18 >= 0 )
  {
    if ( MiChargeResident(&MiSystemPartition, v22, 512) )
    {
      do
        v32 = __ldrex(dword_634A2C);
      while ( __strex(v32 + v22, dword_634A2C) );
      if ( MiChargeWsles(v11 + 123, v22, 1) )
      {
        v19 = v43;
        goto LABEL_18;
      }
      MiReturnResidentAvailable(v22);
      do
        v36 = __ldrex(&dword_634A2C[1]);
      while ( __strex(v36 + v22, &dword_634A2C[1]) );
    }
    PsReturnProcessQuota(v11);
    v18 = -1073741670;
  }
LABEL_32:
  MiUnlockWorkingSetExclusive(v12, v45);
  return v18;
}
