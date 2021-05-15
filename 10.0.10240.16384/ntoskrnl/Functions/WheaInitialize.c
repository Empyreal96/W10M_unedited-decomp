// WheaInitialize 
 
int __fastcall WheaInitialize(int a1, unsigned int a2)
{
  int v4; // r0
  _BYTE *v5; // r0
  signed int v6; // r0
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r2
  unsigned int v10; // r7
  int v11; // r0
  signed int v12; // r0
  void **v13; // r1
  _DWORD **v14; // r2
  int *i; // r4
  int v16; // r4
  int j; // r8
  int v18; // r3
  unsigned int v19; // r1
  _DWORD *v20; // r0
  int v21; // r0
  int v23; // r0
  int v24; // r0
  signed int v25; // r0
  int *v26; // r4
  unsigned int v27; // r5
  int (__fastcall *v28)(_DWORD, int *, _DWORD); // r3
  signed int v29; // r0
  int v30; // r3
  int (__fastcall *v31)(unsigned int, char *, int); // r3
  int (__fastcall *v32)(unsigned int, int, _DWORD); // r3
  signed int v33; // r0
  unsigned int v34; // [sp+8h] [bp-30h] BYREF
  int *v35; // [sp+Ch] [bp-2Ch] BYREF
  char v36[40]; // [sp+10h] [bp-28h] BYREF

  v34 = 0;
  if ( a2 )
  {
    WheapPrevErrList[0] = WheapPrevErrList;
    WheapPrevErrList[1] = WheapPrevErrList;
    v4 = PshedInitialize(a1, v36);
    if ( v4 < 0 )
      KeBugCheckEx(290, 3, v4, 0, 0);
    v5 = WheapInitializeWorkQueue();
    WheapInitializeEventing(v5);
    v6 = WheapQueryPshedForErrorSources(&v34, &v35);
    if ( v6 < 0 )
      KeBugCheck2(290, 5, v6, a2, 0, 0);
    v7 = KeAbPreAcquire((unsigned int)&WheapConfigTableLock, 0, 0);
    v8 = v7;
    do
      v9 = __ldrex((unsigned __int8 *)&WheapConfigTableLock);
    while ( __strex(v9 | 1, (unsigned __int8 *)&WheapConfigTableLock) );
    __dmb(0xBu);
    if ( (v9 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&WheapConfigTableLock, v7, (unsigned int)&WheapConfigTableLock);
    if ( v8 )
      *(_BYTE *)(v8 + 14) |= 1u;
    v10 = v34;
    v11 = WheapInitializeErrorSourceTable(v34, v35);
    if ( v11 < 0 )
      KeBugCheckEx(290, 7, v11, 0, 0);
    PshedFreeMemory(v35);
    v12 = 0;
    if ( KeNumberProcessors_0 )
    {
      v13 = &KiProcessorBlock;
      if ( !KeNumberProcessors_0 )
      {
        v14 = 0;
        goto LABEL_14;
      }
      do
      {
        v14 = (_DWORD **)*v13;
LABEL_14:
        ++v12;
        ++v13;
        *v14[898] = v10;
        v14[898][2] = WheapWorkQueue;
        v14[898][1] = &WheapErrorSourceTable;
      }
      while ( v12 < (unsigned int)KeNumberProcessors_0 );
    }
    for ( i = (int *)dword_641934; i != &dword_641934; i = (int *)*i )
    {
      if ( *(int *)((char *)i + 81) == 7 )
      {
        v31 = (int (__fastcall *)(unsigned int, char *, int))dword_649F60[7 * i[8]];
        __dmb(0xBu);
        v12 = v31(a2, (char *)i + 73, i[10]);
        if ( v12 < 0 )
          KeBugCheck2(290, 6, v12, a2, *(int *)((char *)i + 81), 0);
        *(int *)((char *)i + 85) = 2;
      }
    }
    if ( (*(_DWORD *)(*(_DWORD *)(a1 + 132) + 2160) & 4) == 0 && PshedIsSystemWheaEnabled(v12, WheapSourceConfiguration) )
      WheapCheckForAndReportErrorsFromPreviousSession();
    v16 = dword_641934;
    for ( j = 0; (int *)v16 != &dword_641934; ++j )
    {
      v18 = *(_DWORD *)(v16 + 81);
      *(_DWORD *)(v16 + 101) = j;
      if ( v18 != 7 && !*(_BYTE *)(v16 + 72) )
      {
        v32 = (int (__fastcall *)(unsigned int, int, _DWORD))dword_649F60[7 * *(_DWORD *)(v16 + 32)];
        __dmb(0xBu);
        v33 = v32(a2, v16 + 73, *(_DWORD *)(v16 + 40));
        if ( v33 < 0 )
          KeBugCheck2(290, 6, v33, a2, *(_DWORD *)(v16 + 81), 0);
        *(_DWORD *)(v16 + 85) = 2;
      }
      v16 = *(_DWORD *)v16;
    }
    WheapLogInitEvent();
    WheapDispatchPtr = (int)WheaWmiDispatch;
    IoWMIRegistrationControl((int)&WheapDispatchPtr, -2147483647);
    __dmb(0xBu);
    WheapInitializationComplete = 1;
    __dmb(0xBu);
    do
      v19 = __ldrex((unsigned int *)&WheapConfigTableLock);
    while ( __strex(v19 - 1, (unsigned int *)&WheapConfigTableLock) );
    if ( (v19 & 2) != 0 && (v19 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&WheapConfigTableLock);
    KeAbPostRelease((unsigned int)&WheapConfigTableLock);
  }
  else
  {
    WheapStatus = 0;
    dword_619894 = 0;
    dword_619898 = 0;
    v20 = KeQuerySystemTime(&WheapErrorRecordId);
    v21 = WheapLoadPolicy(v20);
    if ( (*(_DWORD *)(*(_DWORD *)(a1 + 132) + 68) & 2) == 0 )
      return sub_96618C(v21);
    v23 = PshedInitialize(a1, v36);
    if ( v23 < 0 )
      KeBugCheckEx(290, 3, v23, 0, 0);
    v24 = WheapCreatePerProcessorInfo();
    if ( v24 < 0 )
      KeBugCheckEx(290, 4, v24, 0, 0);
    v25 = WheapQueryPshedForErrorSources(&v34, &v35);
    if ( v25 < 0 )
      KeBugCheck2(290, 5, v25, 0, 0, 0);
    v26 = v35;
    v27 = 0;
    WheapErrorSourceTable = 1279410516;
    dword_641930 = 0;
    dword_641938 = (int)&dword_641934;
    dword_641934 = (int)&dword_641934;
    byte_64193C = 1;
    byte_64193D = 0;
    byte_64193E = 4;
    dword_641940 = 1;
    dword_641948 = (int)&dword_641944;
    dword_641944 = (int)&dword_641944;
    if ( v34 )
    {
      do
      {
        v28 = (int (__fastcall *)(_DWORD, int *, _DWORD))dword_649F60[7 * v26[2]];
        __dmb(0xBu);
        v29 = v28(0, v26, 0);
        if ( v29 < 0 )
          KeBugCheck2(290, 6, v29, 0, v26[2], 0);
        v30 = *v26;
        v26[3] = 2;
        ++v27;
        v26 = (int *)((char *)v26 + v30);
      }
      while ( v27 < v34 );
      v26 = v35;
    }
    PshedFreeMemory(v26);
  }
  return 0;
}
