// NtFlushKey 
 
int __fastcall NtFlushKey(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, char a11)
{
  int v11; // r7
  int v13; // r3
  unsigned int v14; // r0
  unsigned int v15; // r2
  unsigned int v16; // r1
  unsigned __int8 *v17; // r0
  int v18; // r1
  int v19; // r5
  unsigned int v20; // r4
  unsigned int v21; // r1
  unsigned int v22; // r1
  __int16 v23; // r3
  int v25; // r0
  int v26; // r0
  unsigned int v27; // r4
  unsigned int v28; // r1
  unsigned int v29; // r1
  int v30; // r3
  unsigned int v31; // r1
  __int16 v32; // r3
  int v33; // r6
  int v34; // r2
  int v35; // r0
  int v36; // r0
  unsigned int *v37; // r4
  int v38; // r0
  unsigned int *v39; // r7
  unsigned int v40; // r0
  unsigned int v41; // r1
  int v42; // r0
  int *v43; // [sp+8h] [bp-50h] BYREF
  int **v44; // [sp+Ch] [bp-4Ch]
  int v45; // [sp+10h] [bp-48h]
  int v46; // [sp+14h] [bp-44h]
  int v47[4]; // [sp+18h] [bp-40h] BYREF
  _DWORD v48[12]; // [sp+28h] [bp-30h] BYREF

  v47[0] = 0;
  v47[1] = 0;
  v47[2] = 0;
  v47[3] = 0;
  v48[0] = 0;
  v48[1] = 0;
  v48[2] = 0;
  v48[3] = 0;
  v11 = 0;
  v45 = 0;
  if ( CmpTraceRoutine )
    return sub_7D1AA4(a1, a2, a3, (int)CmpTraceRoutine, a5, a6, a7, a8, a9, a10, a11);
  v13 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v13 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v14 = CmpShutdownRundown & 0xFFFFFFFE;
  v15 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v16 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v16 == v14 && __strex(v15, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v16 == v14 || ExfAcquireRundownProtection(&CmpShutdownRundown) )
  {
    __mrc(15, 0, 13, 0, 3);
    v17 = (unsigned __int8 *)CmObReferenceObjectByHandle(a1, 0);
    v19 = (int)v17;
    if ( (int)v17 >= 0 )
    {
      v33 = v46;
      if ( CmpTraceRoutine && v46 )
        v45 = *(_DWORD *)(v46 + 4);
      v44 = &v43;
      v43 = (int *)&v43;
      v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v34 + 0x134);
      if ( CmpCallBackCount )
      {
        v17 = (unsigned __int8 *)ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, v18, v34, CmpCallBackCount);
        if ( !v17 )
        {
          v47[0] = v33;
          v17 = (unsigned __int8 *)CmpCallCallBacks(30, v47, 1, 31, v33, &v43);
          v19 = (int)v17;
        }
      }
      if ( v19 < 0 )
      {
        if ( v19 == -1073740541 )
          v19 = 0;
      }
      else
      {
        CmpLockRegistryFreezeAware(0);
        CmpLockKcbShared(*(_DWORD *)(v33 + 4));
        v35 = *(_DWORD *)(v33 + 4);
        if ( (*(_DWORD *)(v35 + 4) & 0x20000) != 0 )
        {
          if ( (*(_DWORD *)(v33 + 24) & 1) != 0 )
            v19 = -1073740763;
          else
            v19 = -1073741444;
          v36 = CmpUnlockKcb(v35);
          CmpUnlockRegistry(v36);
        }
        else
        {
          v37 = *(unsigned int **)(v35 + 20);
          if ( v37 == CmpMasterHive )
          {
            v38 = CmpUnlockKcb(v35);
            CmpUnlockRegistry(v38);
            CmpDoFlushAll(0);
          }
          else
          {
            v39 = v37 + 458;
            __pld(v37 + 458);
            v40 = v37[458] & 0xFFFFFFFE;
            do
              v41 = __ldrex(v39);
            while ( v41 == v40 && __strex(v40 + 2, v39) );
            __dmb(0xBu);
            if ( v41 == v40 || ExfAcquireRundownProtection(v37 + 458) )
            {
              v25 = CmpUnlockKcb(*(_DWORD *)(v33 + 4));
              CmpUnlockRegistry(v25);
              v26 = CmpFlushHive(v37, 0);
              __pld(v39);
              v19 = v26;
              v27 = *v39 & 0xFFFFFFFE;
              __dmb(0xBu);
              do
                v28 = __ldrex(v39);
              while ( v28 == v27 && __strex(v27 - 2, v39) );
              if ( v28 != v27 )
                ExfReleaseRundownProtection((unsigned __int8 *)v39);
              if ( v19 < 0 )
                v19 = -1073741491;
            }
            else
            {
              v42 = CmpUnlockKcb(*(_DWORD *)(v33 + 4));
              CmpUnlockRegistry(v42);
              v19 = -1073740763;
            }
          }
        }
        v17 = (unsigned __int8 *)CmPostCallbackNotification(31, v33, v19, v47, &v43);
        v19 = (int)v17;
      }
      v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v30 = (__int16)(*(_WORD *)(v29 + 0x134) + 1);
      *(_WORD *)(v29 + 308) = v30;
      if ( !v30 && *(_DWORD *)(v29 + 100) != v29 + 100 && !*(_WORD *)(v29 + 310) )
        KiCheckForKernelApcDelivery((int)v17);
      v17 = (unsigned __int8 *)ObfDereferenceObject(v33);
      v11 = v45;
    }
    if ( CmpTraceRoutine )
      v17 = (unsigned __int8 *)((int (__fastcall *)(int, _DWORD *, int, _DWORD, int, _DWORD, int *, int **))CmpTraceRoutine)(
                                 21,
                                 v48,
                                 v19,
                                 0,
                                 v11,
                                 0,
                                 v43,
                                 v44);
    __pld(&CmpShutdownRundown);
    v20 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v21 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v21 == v20 && __strex(v20 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v21 != v20 )
      v17 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v23 = *(_WORD *)(v22 + 0x134) + 1;
    *(_WORD *)(v22 + 308) = v23;
    if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
      KiCheckForKernelApcDelivery((int)v17);
  }
  else
  {
    v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v32 = *(_WORD *)(v31 + 0x134) + 1;
    *(_WORD *)(v31 + 308) = v32;
    if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 && !*(_WORD *)(v31 + 310) )
      KiCheckForKernelApcDelivery(0);
    v19 = -1073741431;
    if ( CmpTraceRoutine )
      ((void (__fastcall *)(int, _DWORD *, int, _DWORD, _DWORD, _DWORD))CmpTraceRoutine)(21, v48, -1073741431, 0, 0, 0);
  }
  return v19;
}
