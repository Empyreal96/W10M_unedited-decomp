// sub_7F2B68 
 
void __fastcall sub_7F2B68(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int *a9, int a10, int a11, int a12, _DWORD *a13, int a14, int a15, int a16, int *a17, int a18, int a19, int a20, _DWORD *a21, int a22, int a23, int a24)
{
  _DWORD *v24; // r7
  unsigned __int8 v25; // r4
  unsigned int v26; // r1
  int v27; // r3
  int v28; // r10
  __int64 v29; // kr00_8
  __int64 v30; // kr08_8
  int v31; // r4
  int v32; // r9
  unsigned int v33; // r2
  _DWORD *v34; // r3
  _DWORD *v35; // r5
  int v36; // r3
  BOOL v37; // r4

  if ( a2 )
  {
    v35[9] = a2;
    if ( !v35[3] )
    {
      v36 = __mrc(15, 0, 13, 0, 3);
      __dmb(0xBu);
      v35[3] = v36 & 0xFFFFFFC0;
      do
      {
        v24 = (_DWORD *)v35[9];
        ++*v24;
        dword_61F324 = 0;
        v25 = dword_61F33C;
        __dmb(0xBu);
        do
          v26 = __ldrex((unsigned int *)&PopSettingLock);
        while ( !v26 && __strex(1u, (unsigned int *)&PopSettingLock) );
        if ( v26 )
          ExpReleaseFastMutexContended((unsigned int *)&PopSettingLock, v26);
        KfLowerIrql(v25);
        KeAbPostRelease((unsigned int)&PopSettingLock);
        v27 = v35[10];
        v28 = v24[1];
        a7 = v28;
        a8 = v27;
        if ( PopDiagHandleRegistered )
        {
          v29 = *(_QWORD *)&PopDiagHandle;
          if ( EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_POWER_SETTING_CALLBACK_START) )
          {
            a9 = &a8;
            a10 = 0;
            a11 = 4;
            a12 = 0;
            a13 = v35 + 5;
            a14 = 0;
            a15 = 16;
            a16 = 0;
            a17 = &a7;
            a18 = 0;
            a19 = 4;
            a20 = 0;
            a21 = v24 + 3;
            a22 = 0;
            a23 = v28;
            a24 = 0;
            EtwWrite(v29, SHIDWORD(v29), (int)POP_ETW_EVENT_POWER_SETTING_CALLBACK_START, 0);
          }
        }
        ((void (__fastcall *)(_DWORD *, _DWORD *, _DWORD, _DWORD))v35[10])(v35 + 5, v24 + 3, v24[1], v35[11]);
        a7 = v35[10];
        if ( PopDiagHandleRegistered )
        {
          v30 = *(_QWORD *)&PopDiagHandle;
          if ( EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_POWER_SETTING_CALLBACK_STOP) )
          {
            a9 = &a7;
            a10 = 0;
            a11 = 4;
            a12 = 0;
            a13 = v35 + 5;
            a14 = 0;
            a15 = 16;
            a16 = 0;
            EtwWrite(v30, SHIDWORD(v30), (int)POP_ETW_EVENT_POWER_SETTING_CALLBACK_STOP, 0);
          }
        }
        if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) )
          __fastfail(0x20u);
        v31 = KeAbPreAcquire((unsigned int)&PopSettingLock, 0, 0);
        v32 = KfRaiseIrql(1);
        do
          v33 = __ldrex((unsigned __int8 *)&PopSettingLock);
        while ( __strex(v33 & 0xFE, (unsigned __int8 *)&PopSettingLock) );
        __dmb(0xBu);
        if ( (v33 & 1) == 0 )
          ExpAcquireFastMutexContended((int)&PopSettingLock, v31);
        if ( v31 )
          *(_BYTE *)(v31 + 14) |= 1u;
        dword_61F324 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        dword_61F33C = v32;
        v34 = (_DWORD *)v35[9];
        v37 = v24 != v34 && v34;
        PopUnreferencePowerSetting((unsigned int)v24);
      }
      while ( v37 );
      __dmb(0xBu);
      v35[3] = 0;
    }
  }
  JUMPOUT(0x70B32E);
}
