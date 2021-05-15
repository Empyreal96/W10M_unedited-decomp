// PspCreateSilo 
 
int __fastcall PspCreateSilo(int a1)
{
  unsigned int v2; // r5
  int v3; // r9
  int v4; // r4
  _DWORD *v5; // r6
  int v6; // r0
  int v7; // r7
  int v8; // r10
  unsigned int v9; // r2
  int **v10; // r0
  unsigned __int8 v11; // r7
  unsigned int v12; // r1
  unsigned int *v13; // r7
  int v14; // r0
  int v15; // r4
  unsigned int v16; // r2
  _DWORD *v17; // r4
  unsigned int v18; // r2
  int v19; // r0
  __int16 v20; // r3
  int v21; // r2
  int v22; // r3
  _DWORD *v23; // r0
  _DWORD *v24; // r2
  int v25; // r3
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  int v29; // r2
  int v30; // r3
  unsigned int *v31; // r2
  unsigned int v32; // r0
  int v33; // r0
  __int16 v34; // r3
  _BYTE *v36; // [sp+18h] [bp-40h] BYREF
  int v37[14]; // [sp+20h] [bp-38h] BYREF

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(_DWORD *)(v2 + 0x74);
  v37[0] = 24;
  v37[1] = 0;
  v37[2] = 0;
  v37[3] = 0;
  v37[4] = 0;
  v37[5] = 0;
  v4 = ObCreateObject(0, (_DWORD *)PsSiloType, (int)v37, 0, 0, 152, 0, 0, &v36);
  if ( v4 >= 0 )
  {
    v5 = v36;
    memset(v36, 0, 152);
    v6 = ExCreateHandleEx(PspSiloIdTable, (int)v5, 0, 0);
    v5[4] = v6;
    if ( v6 )
    {
      v5[26] = v5 + 26;
      v5[27] = v5 + 26;
      v5[28] = v5 + 28;
      v5[29] = v5 + 28;
      v5[30] = v5 + 30;
      v5[31] = v5 + 30;
      KeInitializeEvent((int)v5, 0, 0);
      KeInitializeEvent((int)(v5 + 32), 0, 1);
      ExInitializeResourceLite((int)(v5 + 7));
      v7 = KeAbPreAcquire((unsigned int)&PspSiloListLock, 0, 0);
      v8 = KfRaiseIrql(1);
      do
        v9 = __ldrex((unsigned __int8 *)&PspSiloListLock);
      while ( __strex(v9 & 0xFE, (unsigned __int8 *)&PspSiloListLock) );
      __dmb(0xBu);
      if ( (v9 & 1) == 0 )
        ExpAcquireFastMutexContended((int)&PspSiloListLock, v7);
      if ( v7 )
        *(_BYTE *)(v7 + 14) |= 1u;
      dword_61DA44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v10 = (int **)dword_61DA6C;
      dword_61DA5C = v8;
      v5[5] = &PspSiloList;
      v5[6] = v10;
      if ( *v10 != &PspSiloList )
        __fastfail(3u);
      *v10 = v5 + 5;
      dword_61DA44 = 0;
      v11 = dword_61DA5C;
      dword_61DA6C = (int)(v5 + 5);
      __dmb(0xBu);
      do
        v12 = __ldrex((unsigned int *)&PspSiloListLock);
      while ( !v12 && __strex(1u, (unsigned int *)&PspSiloListLock) );
      if ( v12 )
        ExpReleaseFastMutexContended((unsigned int *)&PspSiloListLock, v12);
      KfLowerIrql(v11);
      KeAbPostRelease((unsigned int)&PspSiloListLock);
      --*(_WORD *)(v2 + 308);
      v13 = (unsigned int *)(v3 + 168);
      v14 = KeAbPreAcquire(v3 + 168, 0, 0);
      v15 = v14;
      do
        v16 = __ldrex(v13);
      while ( !v16 && __strex(0x11u, v13) );
      __dmb(0xBu);
      if ( v16 )
        ExfAcquirePushLockSharedEx((_DWORD *)(v3 + 168), v14, v3 + 168);
      if ( v15 )
        *(_BYTE *)(v15 + 14) |= 1u;
      v17 = *(_DWORD **)(v3 + 804);
      if ( v17 )
        PspReferenceSiloObject(*(_DWORD *)(v3 + 804));
      __dmb(0xBu);
      do
        v18 = __ldrex(v13);
      while ( v18 == 17 && __strex(0, v13) );
      if ( v18 != 17 )
        ExfReleasePushLockShared((_DWORD *)(v3 + 168));
      v19 = KeAbPostRelease(v3 + 168);
      v20 = *(_WORD *)(v2 + 308) + 1;
      *(_WORD *)(v2 + 308) = v20;
      if ( !v20 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
        KiCheckForKernelApcDelivery(v19);
      v5[21] = v17;
      if ( v17 )
      {
        v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v22 = *(__int16 *)(v21 + 0x136) - 1;
        *(_WORD *)(v21 + 310) = v22;
        ExAcquireResourceExclusiveLite((int)(v17 + 7), 1, v21, v22);
        v23 = (_DWORD *)v17[29];
        v24 = v5 + 22;
        v5[22] = v17 + 28;
        v5[23] = v23;
        if ( (_DWORD *)*v23 != v17 + 28 )
          __fastfail(3u);
        *v23 = v24;
        v17[29] = v24;
        v25 = v17[24];
        v17[24] = v25 + 1;
        if ( !v25 )
        {
          KeResetEvent((int)v17);
          if ( v17[36] )
          {
            if ( !v17[25] )
              KeResetEvent((int)(v17 + 32));
          }
        }
        v26 = ExReleaseResourceLite((int)(v17 + 7));
        v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v28 = *(_WORD *)(v27 + 0x136) + 1;
        *(_WORD *)(v27 + 310) = v28;
        if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 )
          KiCheckForKernelApcDelivery(v26);
      }
      v4 = ObInsertObject((int)v5, 0, 0, 0, 0, 0);
      if ( v4 >= 0 )
      {
        v30 = *(__int16 *)(v2 + 310) - 1;
        *(_WORD *)(v2 + 310) = v30;
        ExAcquireResourceExclusiveLite(a1 + 32, 1, v29, v30);
        if ( *(_DWORD *)(a1 + 720) )
        {
          v4 = -1073740536;
        }
        else
        {
          *(_DWORD *)(a1 + 720) = v5;
          __dmb(0xBu);
          v31 = v5 + 37;
          do
            v32 = __ldrex(v31);
          while ( __strex(v32 | 1, v31) );
          __dmb(0xBu);
          v4 = 0;
        }
        v33 = ExReleaseResourceLite(a1 + 32);
        v34 = *(_WORD *)(v2 + 310) + 1;
        *(_WORD *)(v2 + 310) = v34;
        if ( !v34 && *(_DWORD *)(v2 + 100) != v2 + 100 )
          KiCheckForKernelApcDelivery(v33);
        if ( v4 < 0 )
          ObfDereferenceObject((int)v5);
      }
    }
    else
    {
      PspDereferenceSiloObject((int)v5);
      v4 = -1073741670;
    }
  }
  return v4;
}
