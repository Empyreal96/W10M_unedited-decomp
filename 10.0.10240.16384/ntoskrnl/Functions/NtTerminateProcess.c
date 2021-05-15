// NtTerminateProcess 
 
int __fastcall NtTerminateProcess(int a1, int a2)
{
  int v3; // r5
  _DWORD *v4; // r7
  int v5; // r8
  int v6; // r10
  signed int v7; // r6
  int v8; // r4
  int v9; // r3
  int v10; // r0
  unsigned int *v11; // r2
  unsigned int v12; // r0
  int v13; // r0
  int v14; // r3
  unsigned int v15; // r1
  int v16; // r3
  int v18; // r0
  int v19; // r4
  unsigned int v20; // r2
  unsigned int *v21; // r2
  unsigned int v22; // r4
  unsigned int v23; // r1
  int v24; // r0
  __int16 v25; // r3
  int v26; // [sp+10h] [bp-48h] BYREF
  _DWORD v27[17]; // [sp+14h] [bp-44h] BYREF

  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(_DWORD **)(v3 + 0x74);
  v5 = *(char *)(v3 + 0x15A);
  v6 = 0;
  if ( a1 )
  {
    v7 = ObReferenceObjectByHandleWithTag(a1, 1, PsProcessType, v5, 1700033360, &v26, 0);
    if ( v7 >= 0 )
    {
      if ( !v5 )
        v6 = 1;
      v8 = v26;
      v9 = *(_DWORD *)(v26 + 176);
      --*(_WORD *)(v3 + 308);
      v26 = v9;
      v7 = PspTerminateProcess(v8, v3, a2, v6);
      v10 = ObfDereferenceObjectWithTag(v8);
      if ( (_DWORD *)v8 == v4 )
      {
        if ( v5 == 1 )
        {
          __dmb(0xBu);
          v11 = (unsigned int *)(v3 + 960);
          do
            v12 = __ldrex(v11);
          while ( __strex(v12 | 1, v11) );
          __dmb(0xBu);
          v13 = KeForceResumeThread(v3);
          v14 = (__int16)(*(_WORD *)(v3 + 308) + 1);
          *(_WORD *)(v3 + 308) = v14;
          if ( !v14 )
            return sub_7C2604(v13);
          PspExitThread(a2);
LABEL_11:
          *(_DWORD *)(v3 + 964) |= 0x10u;
          if ( v4[158] == 259 )
            v4[158] = a2;
          __dmb(0xBu);
          do
            v15 = __ldrex((unsigned int *)v7);
          while ( __strex(v15 - 1, (unsigned int *)v7) );
          if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)v7);
          KeAbPostRelease(v7);
          v10 = PspTerminateAllThreads(v4, v3, a2, 0);
          v7 = v10;
          goto LABEL_17;
        }
      }
      else
      {
        v27[0] = v7;
        v27[1] = &v26;
        v27[2] = 0;
        v27[3] = 4;
        v27[4] = 0;
        v27[5] = v27;
        v27[6] = 0;
        v27[7] = 4;
        v27[8] = 0;
        v10 = EtwWrite(EtwApiCallsProvRegHandle, dword_61A654, (int)KERNEL_AUDIT_API_TERMINATEPROCESS, 0);
      }
LABEL_17:
      v16 = (__int16)(*(_WORD *)(v3 + 308) + 1);
      *(_WORD *)(v3 + 308) = v16;
      if ( !v16 && *(_DWORD *)(v3 + 100) != v3 + 100 && !*(_WORD *)(v3 + 310) )
        KiCheckForKernelApcDelivery(v10);
      return v7;
    }
  }
  else
  {
    if ( v5 == 1 && (v4[184] & 1) == 0 )
    {
      --*(_WORD *)(v3 + 308);
      v7 = (signed int)(v4 + 42);
      v18 = KeAbPreAcquire((unsigned int)(v4 + 42), 0, 0);
      v19 = v18;
      do
        v20 = __ldrex((unsigned __int8 *)v7);
      while ( __strex(v20 | 1, (unsigned __int8 *)v7) );
      __dmb(0xBu);
      if ( (v20 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v4 + 42, v18, (unsigned int)(v4 + 42));
      if ( v19 )
        *(_BYTE *)(v19 + 14) |= 1u;
      __dmb(0xBu);
      v21 = v4 + 48;
      do
        v22 = __ldrex(v21);
      while ( __strex(v22 | 0x40000000, v21) );
      __dmb(0xBu);
      if ( (v22 & 0x40000008) != 0 )
      {
        __dmb(0xBu);
        do
          v23 = __ldrex((unsigned int *)v7);
        while ( __strex(v23 - 1, (unsigned int *)v7) );
        if ( (v23 & 2) != 0 && (v23 & 4) == 0 )
          ExfTryToWakePushLock(v4 + 42);
        v24 = KeAbPostRelease((unsigned int)(v4 + 42));
        v25 = *(_WORD *)(v3 + 308) + 1;
        *(_WORD *)(v3 + 308) = v25;
        if ( !v25 && *(_DWORD *)(v3 + 100) != v3 + 100 && !*(_WORD *)(v3 + 310) )
          KiCheckForKernelApcDelivery(v24);
        PspTerminateThreadByPointer(v3, a2, 1);
        return 0;
      }
      goto LABEL_11;
    }
    v7 = -1073741637;
  }
  return v7;
}
