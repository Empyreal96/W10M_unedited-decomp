// EtwpCreateLogFile 
 
int __fastcall EtwpCreateLogFile(_DWORD *a1, int a2)
{
  int v4; // r6
  int v5; // r8
  int v6; // r7
  int v7; // r5
  unsigned int *v9; // r2
  unsigned int v10; // r0
  unsigned __int8 *v11; // r5
  int v12; // r0
  int v13; // r6
  unsigned int v14; // r2
  unsigned int v15; // r1
  int v16; // r7
  int v17; // r8
  int v18; // r3
  unsigned int v19; // r9
  unsigned int v20; // r10
  unsigned __int8 *v21; // r6
  int v22; // r0
  int v23; // r5
  unsigned int v24; // r2
  int v25; // r3
  unsigned int v26; // r1
  unsigned __int8 *v27; // r6
  int v28; // r0
  int v29; // r7
  unsigned int v30; // r2
  int v31; // r3
  int v32; // r3
  unsigned int v33; // r1
  char v34[8]; // [sp+8h] [bp-70h] BYREF
  unsigned __int64 v35; // [sp+10h] [bp-68h] BYREF
  int v36; // [sp+18h] [bp-60h] BYREF
  int v37; // [sp+1Ch] [bp-5Ch]
  int v38[2]; // [sp+20h] [bp-58h] BYREF
  int v39[10]; // [sp+30h] [bp-48h] BYREF

  v4 = 0;
  v36 = 0;
  v37 = 0;
  v34[0] = 0;
  v5 = 0;
  v6 = 0;
  RtlInitUnicodeString((unsigned int)&v35, 0);
  if ( (a1[152] & 4) == 0 )
    return 0;
  __dmb(0xBu);
  v9 = a1 + 153;
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 & 0xFFFFFFFC, v9) );
  __dmb(0xBu);
  if ( a1[26] )
  {
    if ( a1[30] )
      JUMPOUT(0x80AB3E);
    if ( (a1[152] & 2) != 0 )
    {
      v11 = (unsigned __int8 *)(a1 + 126);
      v12 = KeAbPreAcquire((unsigned int)(a1 + 126), 0, 0);
      v13 = v12;
      do
        v14 = __ldrex(v11);
      while ( __strex(v14 | 1, v11) );
      __dmb(0xBu);
      if ( (v14 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(a1 + 126, v12, (unsigned int)(a1 + 126));
      if ( v13 )
        *(_BYTE *)(v13 + 14) |= 1u;
      EtwpExpandFileName(0, a1 + 25, a1[55], a1 + 23);
      __dmb(0xBu);
      do
        v15 = __ldrex((unsigned int *)v11);
      while ( __strex(v15 - 1, (unsigned int *)v11) );
      if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
        ExfTryToWakePushLock(a1 + 126);
      KeAbPostRelease((unsigned int)(a1 + 126));
      v4 = 0;
    }
    v38[0] = a1[25];
    v38[1] = a1[26];
    if ( (a1[3] & 4) != 0 )
      v34[0] = 1;
    if ( (a1[152] & 2) != 0 )
      v6 = 1;
    if ( a2 == 1 )
    {
      if ( a1[131] )
      {
        v7 = SeImpersonateClientEx(a1 + 128, 0);
        v5 = 1;
        if ( v7 < 0 )
          goto LABEL_38;
      }
    }
    v7 = ((int (__fastcall *)(int *, int *, char *, int, _DWORD, int))EtwpDelayCreate)(&v36, v38, v34, 1, 0, v6);
    if ( v5 == 1 )
      PsRevertThreadToSelf(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    if ( v7 < 0 )
    {
      v19 = HIDWORD(v35);
      v16 = v36;
      v20 = v35;
    }
    else
    {
      memset(v39, 0, sizeof(v39));
      v16 = v36;
      v39[8] = 0x2000;
      ZwSetInformationFile();
      v17 = a1[148];
      if ( v17 )
      {
        EtwpFinalizeHeader(a1, a1[148], 0);
      }
      else
      {
        v4 = 1;
        v37 = 1;
      }
      v18 = a1[30];
      a1[148] = v16;
      if ( v18 )
      {
        v21 = (unsigned __int8 *)(a1 + 126);
        v22 = KeAbPreAcquire((unsigned int)(a1 + 126), 0, 0);
        v23 = v22;
        do
          v24 = __ldrex(v21);
        while ( __strex(v24 | 1, v21) );
        __dmb(0xBu);
        if ( (v24 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(a1 + 126, v22, (unsigned int)(a1 + 126));
        if ( v23 )
          *(_BYTE *)(v23 + 14) |= 1u;
        v19 = a1[26];
        v20 = a1[25];
        a1[25] = a1[29];
        v25 = a1[30];
        v35 = __PAIR64__(v19, v20);
        a1[26] = v25;
        __dmb(0xBu);
        do
          v26 = __ldrex((unsigned int *)v21);
        while ( __strex(v26 - 1, (unsigned int *)v21) );
        if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
          ExfTryToWakePushLock(a1 + 126);
        KeAbPostRelease((unsigned int)(a1 + 126));
        RtlInitUnicodeString((unsigned int)(a1 + 29), 0);
        v4 = v37;
      }
      else
      {
        v19 = HIDWORD(v35);
        v20 = v35;
      }
      v7 = EtwpUpdateFileHeader(a1, (unsigned __int8)v34[0]);
      if ( v7 < 0 )
      {
        a1[148] = v17;
      }
      else
      {
        if ( !v4 )
          EtwpSendSessionNotification(a1, 1, 0);
        v16 = 0;
        if ( !v17 )
          goto LABEL_38;
        ZwClose();
      }
    }
    if ( v16 )
    {
      ZwClose();
      if ( a1[148] )
      {
        if ( v19 )
        {
          v27 = (unsigned __int8 *)(a1 + 126);
          v28 = KeAbPreAcquire((unsigned int)(a1 + 126), 0, 0);
          v29 = v28;
          do
            v30 = __ldrex(v27);
          while ( __strex(v30 | 1, v27) );
          __dmb(0xBu);
          if ( (v30 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(a1 + 126, v28, (unsigned int)(a1 + 126));
          if ( v29 )
            *(_BYTE *)(v29 + 14) |= 1u;
          v31 = a1[25];
          a1[25] = v20;
          a1[29] = v31;
          v32 = a1[26];
          a1[26] = v19;
          a1[30] = v32;
          __dmb(0xBu);
          do
            v33 = __ldrex((unsigned int *)v27);
          while ( __strex(v33 - 1, (unsigned int *)v27) );
          if ( (v33 & 2) != 0 && (v33 & 4) == 0 )
            ExfTryToWakePushLock(a1 + 126);
          KeAbPostRelease((unsigned int)(a1 + 126));
          RtlInitUnicodeString((unsigned int)&v35, 0);
        }
      }
    }
LABEL_38:
    RtlFreeAnsiString(a1 + 29);
    RtlFreeAnsiString(&v35);
    return v7;
  }
  return sub_80AB38();
}
