// sub_7CEB9C 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall sub_7CEB9C(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v5; // r5
  int v6; // r7
  int v7; // r8
  unsigned int v8; // r2
  int v9; // r6
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r8
  int v13; // r6
  int v14; // r2
  void (__fastcall *v15)(_DWORD); // r3
  unsigned int v16; // r7
  int v17; // r8
  _DWORD *v18; // r6
  unsigned int v19; // r2
  unsigned int v20; // r2
  int v21; // r1
  _WORD *v22; // r2
  int v23; // r2
  int v24; // r3
  int v25; // r1 OVERLAPPED
  _DWORD *v26; // r2 OVERLAPPED
  int v27; // r1 OVERLAPPED
  _DWORD *v28; // r2 OVERLAPPED
  unsigned int *v29; // r2
  unsigned int v30; // r0
  int v31; // r0
  unsigned int v32; // r1
  __int16 v33; // r3
  unsigned int v34; // r7
  int v35; // r6
  _DWORD *v36; // r5
  int v37; // r0
  unsigned int v38; // r1
  unsigned int v39; // r1
  char *v40; // r3
  unsigned int v41; // r2
  unsigned int v42; // r2
  char *v43; // r3

  if ( a5 )
  {
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v8 + 308);
    v9 = KeAbPreAcquire(v5 + 28, 0, 0);
    v10 = (unsigned __int8 *)(v5 + 28);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | 1, v10) );
    __dmb(0xBu);
    if ( (v11 & v7) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v5 + 28), v9, v5 + 28);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= v7;
    v12 = 0;
    if ( a5[3] )
    {
      v13 = 0;
      do
      {
        v14 = *(_DWORD *)(a5[4] + v13 + 48);
        if ( (*(_DWORD *)(v14 + 16) & 4) == 0 )
        {
          v15 = *(void (__fastcall **)(_DWORD))(*(_DWORD *)(v14 + 8) + 16);
          if ( v15 )
            v15(*(_DWORD *)(v6 + 24));
        }
        ++v12;
        v13 += 52;
      }
      while ( v12 < a5[3] );
    }
    v16 = 0;
    if ( a5[3] )
    {
      v17 = 0;
      do
      {
        v18 = *(_DWORD **)(a5[4] + v17 + 48);
        if ( !v18[3] )
        {
          __dmb(0xBu);
          do
          {
            v19 = __ldrex(&KsepHistoryErrorsIndex);
            v20 = v19 + 1;
          }
          while ( __strex(v20, &KsepHistoryErrorsIndex) );
          __dmb(0xBu);
          v21 = v20 & 0x3F;
          v22 = &KsepHistoryErrors[4 * v21];
          v22[1] = 7;
          *v22 = 1398;
          *((_DWORD *)v22 + 1) = -1073740768;
          if ( (KsepDebugFlag & 4) != 0 )
            RtlAssert((int)"RegisteredShim->RefCount > 0", (int)"minkernel\\ntos\\kshim\\kseloader.c", 1398, 0);
        }
        v23 = v18[3] - 1;
        v24 = v18[4];
        v18[3] = v23;
        if ( (v24 & 4) != 0 && !v23 )
        {
          *(_QWORD *)&v25 = *(_QWORD *)v18;
          if ( *(_DWORD **)(*v18 + 4) != v18 || (_DWORD *)*v26 != v18 )
            __fastfail(3u);
          *v26 = v25;
          *(_DWORD *)(v25 + 4) = v26;
        }
        ++v16;
        v17 += 52;
      }
      while ( v16 < a5[3] );
    }
    *(_QWORD *)&v27 = *(_QWORD *)a5;
    if ( *(_DWORD **)(*a5 + 4) != a5 || (_DWORD *)*v28 != a5 )
      __fastfail(3u);
    *v28 = v27;
    *(_DWORD *)(v27 + 4) = v28;
    __dmb(0xBu);
    v29 = (unsigned int *)(v5 + 28);
    do
      v30 = __ldrex(v29);
    while ( __strex(v30 - 1, v29) );
    if ( (v30 & 2) != 0 && (v30 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v5 + 28));
    v31 = KeAbPostRelease(v5 + 28);
    v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v33 = *(_WORD *)(v32 + 0x134) + 1;
    *(_WORD *)(v32 + 308) = v33;
    if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 && !*(_WORD *)(v32 + 310) )
      KiCheckForKernelApcDelivery(v31);
    v34 = 0;
    if ( a5[3] )
    {
      v35 = 0;
      do
      {
        v36 = *(_DWORD **)(a5[4] + v35 + 48);
        v37 = v36[5];
        if ( v37 )
          ObfDereferenceObject(v37);
        if ( (v36[4] & 4) != 0 && !v36[3] )
        {
          KsepPoolFreePaged((int)v36);
          __dmb(0xBu);
          do
          {
            v38 = __ldrex(KsepHistoryMessagesIndex);
            v39 = v38 + 1;
          }
          while ( __strex(v39, KsepHistoryMessagesIndex) );
          __dmb(0xBu);
          v40 = (char *)&KsepHistoryMessages + 8 * (v39 & 0x3F);
          *((_DWORD *)v40 + 1) = 0;
          *((_WORD *)v40 + 1) = 7;
          *(_WORD *)v40 = 1455;
          if ( (KsepDebugFlag & 1) != 0 )
            KsepDebugPrint(5, (int)"KSE: Cleaned up dangling shim object [0x%08X] (unregistered while refcount >0)\n");
          KsepLogInfo(5, (int)"KSE: Cleaned up dangling shim object [0x%08X] (unregistered while refcount >0)\n", v36);
        }
        ++v34;
        v35 += 52;
      }
      while ( v34 < a5[3] );
    }
    KsepDbFreeDriverShims(a5[4]);
    KsepPoolFreePaged((int)a5);
    __dmb(0xBu);
    do
    {
      v41 = __ldrex(KsepHistoryMessagesIndex);
      v42 = v41 + 1;
    }
    while ( __strex(v42, KsepHistoryMessagesIndex) );
    __dmb(0xBu);
    v43 = (char *)&KsepHistoryMessages + 8 * (v42 & 0x3F);
    *((_DWORD *)v43 + 1) = 0;
    *((_WORD *)v43 + 1) = 7;
    *(_WORD *)v43 = 1463;
    if ( (KsepDebugFlag & 1) != 0 )
      KsepDebugPrint(5, (int)"KSE: Shimmed driver unload notification processed\n");
    KsepLogInfo(5, (int)"KSE: Shimmed driver unload notification processed\n");
  }
  JUMPOUT(0x7740FC);
}
