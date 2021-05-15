// AlpcpDispatchNewMessage 
 
int __fastcall AlpcpDispatchNewMessage(__int64 *a1)
{
  __int64 v2; // kr00_8
  int v3; // r3
  _DWORD *v4; // r9
  unsigned int v5; // r10
  int v6; // r6
  int v7; // r8
  __int16 v8; // r0
  int v9; // r3
  bool v10; // zf
  int v11; // r3
  unsigned int v12; // r3
  int v13; // r6
  unsigned int *v14; // r2
  unsigned int v15; // r1
  unsigned int v16; // r1
  int v17; // r3
  int v18; // r3
  unsigned int *v19; // r2
  unsigned int v20; // r1
  __int16 v22; // r3
  int v23; // r3
  char v24; // r2
  int v25; // r7
  int v26; // r3
  unsigned int *v27; // r5
  unsigned int v28; // r1
  unsigned int *v29; // r2
  unsigned int v30; // r0
  int v31; // r0
  char v32; // r2
  int v33; // r6
  int v34; // r3
  unsigned int *v35; // r5
  unsigned int v36; // r1
  unsigned int *v37; // r2
  unsigned int v38; // r0
  int v39; // r0
  int v40; // r0
  int v41; // r0
  int v42; // r6
  unsigned int *v43; // r5
  unsigned int v44; // r1
  unsigned int *v45; // r2
  unsigned int v46; // r0
  int v47; // r0
  int v48; // r6
  unsigned int *v49; // r5
  unsigned int v50; // r1
  unsigned int *v51; // r2
  unsigned int v52; // r0
  int v53; // r0
  int v54; // r6
  unsigned int *v55; // r5
  unsigned int v56; // r1
  unsigned int *v57; // r2
  unsigned int v58; // r0
  int v59; // r0
  unsigned int *v60; // r7
  unsigned int v61; // r2
  int v62; // [sp+8h] [bp-28h] BYREF
  int v63; // [sp+Ch] [bp-24h] BYREF
  int v64; // [sp+10h] [bp-20h]

  v2 = *a1;
  v3 = *((_DWORD *)a1 + 6);
  *((_DWORD *)a1 + 3) = 0;
  *((_DWORD *)a1 + 4) = 0;
  *((_DWORD *)a1 + 5) = 0;
  v4 = *(_DWORD **)(v2 + 8);
  v64 = v3;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = AlpcpReferenceAndLockTargetPortsAndCommunicationInfo(v2, &v63, &v62);
  if ( v6 >= 0 )
  {
    if ( (*(_DWORD *)(v2 + 244) & 0x20) == 0 || (*(_DWORD *)(v2 + 152) & 0x1000) != 0 )
    {
      v7 = v63;
      if ( (*(_DWORD *)(*(_DWORD *)a1 + 152) & 0x800000) != 0
        && (*(_DWORD *)(*((_DWORD *)a1 + 1) + 20) & 0x200) == 0
        && (v40 = *(_DWORD *)(v63 + 12), (v40 & 1) == 0)
        && v40
        && (v41 = PsGetProcessJob(v40)) != 0
        && PsGetJobEffectiveFreezeCount(v41) )
      {
        AlpcpUnlockAndDereferenceTargetPortsAndCommunicationInfo((int)v4, v7, v62);
        if ( AlpcpMessageLogEnabled )
          AlpcpEnterStateChangeEventMessageLog(HIDWORD(v2));
        v42 = 0;
        if ( (*(_BYTE *)(HIDWORD(v2) - 16) & 1) != 0 )
        {
          v42 = 0x10000 - *(__int16 *)(HIDWORD(v2) - 14);
          *(_BYTE *)(HIDWORD(v2) - 16) &= 0xFEu;
          *(_WORD *)(HIDWORD(v2) - 14) = 0;
        }
        v43 = (unsigned int *)(HIDWORD(v2) - 4);
        __dmb(0xBu);
        do
          v44 = __ldrex(v43);
        while ( __strex(v44 - 1, v43) );
        if ( (v44 & 2) != 0 && (v44 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)(HIDWORD(v2) - 4));
        KeAbPostRelease(HIDWORD(v2) - 4);
        if ( v42 > 0 )
        {
          __dmb(0xBu);
          v45 = (unsigned int *)(HIDWORD(v2) - 12);
          do
          {
            v46 = __ldrex(v45);
            v47 = v46 - v42;
          }
          while ( __strex(v47, v45) );
          __dmb(0xBu);
          if ( v47 <= 0 )
          {
            if ( v47 )
              KeBugCheckEx(24, 0, SHIDWORD(v2), 40, v47);
            AlpcpDestroyBlob(HIDWORD(v2));
          }
        }
        v6 = -1073741770;
      }
      else if ( (*(_DWORD *)(v7 + 152) & 0x20000) != 0 )
      {
        if ( (unsigned int)*((unsigned __int16 *)a1 + 14) > *(_DWORD *)(v7 + 168) )
        {
          AlpcpUnlockAndDereferenceTargetPortsAndCommunicationInfo((int)v4, v7, v62);
          if ( AlpcpMessageLogEnabled )
            AlpcpEnterStateChangeEventMessageLog(HIDWORD(v2));
          v54 = 0;
          if ( (*(_BYTE *)(HIDWORD(v2) - 16) & 1) != 0 )
          {
            v54 = 0x10000 - *(__int16 *)(HIDWORD(v2) - 14);
            *(_BYTE *)(HIDWORD(v2) - 16) &= 0xFEu;
            *(_WORD *)(HIDWORD(v2) - 14) = 0;
          }
          v55 = (unsigned int *)(HIDWORD(v2) - 4);
          __dmb(0xBu);
          do
            v56 = __ldrex(v55);
          while ( __strex(v56 - 1, v55) );
          if ( (v56 & 2) != 0 && (v56 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)(HIDWORD(v2) - 4));
          KeAbPostRelease(HIDWORD(v2) - 4);
          if ( v54 > 0 )
          {
            __dmb(0xBu);
            v57 = (unsigned int *)(HIDWORD(v2) - 12);
            do
            {
              v58 = __ldrex(v57);
              v59 = v58 - v54;
            }
            while ( __strex(v59, v57) );
            __dmb(0xBu);
            if ( v59 <= 0 )
            {
              if ( v59 )
                KeBugCheckEx(24, 0, SHIDWORD(v2), 40, v59);
              AlpcpDestroyBlob(HIDWORD(v2));
            }
          }
          v6 = -1073741789;
        }
        else
        {
          *(_DWORD *)(HIDWORD(v2) + 100) = 0;
          *(_WORD *)(HIDWORD(v2) + 122) = *((_WORD *)a1 + 14);
          *(_WORD *)(HIDWORD(v2) + 120) = *((_WORD *)a1 + 14) - 24;
          v8 = *((_WORD *)a1 + 15);
          *(_WORD *)(HIDWORD(v2) + 124) = v8;
          *(_WORD *)(HIDWORD(v2) + 126) = *((_WORD *)a1 + 16);
          v9 = v64;
          *(_DWORD *)(HIDWORD(v2) + 128) = *(_DWORD *)(v5 + 876);
          v10 = (v9 & 0x10000) == 0;
          v11 = *(_DWORD *)(HIDWORD(v2) + 20);
          *(_DWORD *)(HIDWORD(v2) + 132) = *(_DWORD *)(v5 + 880);
          if ( v10 )
          {
            *(_DWORD *)(HIDWORD(v2) + 20) = v11 & 0xFFFFFDFF;
            v22 = v8 | 0x2000;
          }
          else
          {
            *(_DWORD *)(HIDWORD(v2) + 20) = v11 | 0x200;
            v22 = v8 & 0xDFFF;
          }
          *(_WORD *)(HIDWORD(v2) + 124) = v22;
          if ( (*(_DWORD *)(v2 + 244) & 0x2000) != 0 && (v23 = *(_DWORD *)(HIDWORD(v2) + 20), (v23 & 0x200) != 0) )
          {
            v12 = v23 & 0xFFFFEFFF;
          }
          else
          {
            ObfReferenceObject(v2);
            v12 = *(_DWORD *)(HIDWORD(v2) + 20) | 0x1000;
          }
          *(_DWORD *)(HIDWORD(v2) + 20) = v12;
          *(_DWORD *)(HIDWORD(v2) + 12) = v2;
          __dmb(0xBu);
          v13 = v62;
          v14 = (unsigned int *)(v62 + 232);
          do
          {
            v15 = __ldrex(v14);
            v16 = v15 + 1;
          }
          while ( __strex(v16, v14) );
          __dmb(0xBu);
          *(_DWORD *)(HIDWORD(v2) + 24) = v16;
          v17 = *(_DWORD *)(v13 + 28);
          *(_DWORD *)(HIDWORD(v2) + 92) = v4;
          *(_DWORD *)(HIDWORD(v2) + 64) = v17;
          *(_DWORD *)(HIDWORD(v2) + 96) = *v4;
          if ( v13 != v7 )
          {
            v60 = (unsigned int *)(v13 + 208);
            __dmb(0xBu);
            do
              v61 = __ldrex(v60);
            while ( v61 == 17 && __strex(0, v60) );
            if ( v61 != 17 )
              ExfReleasePushLockShared((_DWORD *)(v13 + 208));
            KeAbPostRelease(v13 + 208);
          }
          if ( (v64 & 0x20000) != 0 )
          {
            v18 = *(_DWORD *)(HIDWORD(v2) + 20);
            *(_DWORD *)(HIDWORD(v2) + 16) = v5;
            *(_DWORD *)(HIDWORD(v2) + 20) = v18 & 0xFFFFFEFF;
            *(_WORD *)(HIDWORD(v2) - 14) += 2;
            __dmb(0xBu);
            v19 = (unsigned int *)(v5 + 976);
            do
              v20 = __ldrex(v19);
            while ( __strex(HIDWORD(v2), v19) );
            __dmb(0xBu);
          }
          *((_DWORD *)a1 + 4) = v7;
          *((_DWORD *)a1 + 2) = v4;
          AlpcpCompleteDispatchMessage(a1);
          ObfDereferenceObject(v13);
          v6 = 0;
        }
      }
      else
      {
        AlpcpUnlockAndDereferenceTargetPortsAndCommunicationInfo((int)v4, v7, v62);
        if ( AlpcpMessageLogEnabled )
          AlpcpEnterStateChangeEventMessageLog(HIDWORD(v2));
        v48 = 0;
        if ( (*(_BYTE *)(HIDWORD(v2) - 16) & 1) != 0 )
        {
          v48 = 0x10000 - *(__int16 *)(HIDWORD(v2) - 14);
          *(_BYTE *)(HIDWORD(v2) - 16) &= 0xFEu;
          *(_WORD *)(HIDWORD(v2) - 14) = 0;
        }
        v49 = (unsigned int *)(HIDWORD(v2) - 4);
        __dmb(0xBu);
        do
          v50 = __ldrex(v49);
        while ( __strex(v50 - 1, v49) );
        if ( (v50 & 2) != 0 && (v50 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)(HIDWORD(v2) - 4));
        KeAbPostRelease(HIDWORD(v2) - 4);
        if ( v48 > 0 )
        {
          __dmb(0xBu);
          v51 = (unsigned int *)(HIDWORD(v2) - 12);
          do
          {
            v52 = __ldrex(v51);
            v53 = v52 - v48;
          }
          while ( __strex(v53, v51) );
          __dmb(0xBu);
          if ( v53 <= 0 )
          {
            if ( v53 )
              KeBugCheckEx(24, 0, SHIDWORD(v2), 40, v53);
            AlpcpDestroyBlob(HIDWORD(v2));
          }
        }
        v6 = -1073740025;
      }
    }
    else
    {
      AlpcpUnlockAndDereferenceTargetPortsAndCommunicationInfo((int)v4, v63, v62);
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(HIDWORD(v2));
      v32 = *(_BYTE *)(HIDWORD(v2) - 16);
      v33 = 0;
      if ( (v32 & 1) != 0 )
      {
        v34 = *(__int16 *)(HIDWORD(v2) - 14);
        *(_WORD *)(HIDWORD(v2) - 14) = 0;
        v33 = 0x10000 - v34;
        *(_BYTE *)(HIDWORD(v2) - 16) = v32 & 0xFE;
      }
      v35 = (unsigned int *)(HIDWORD(v2) - 4);
      __dmb(0xBu);
      do
        v36 = __ldrex(v35);
      while ( __strex(v36 - 1, v35) );
      if ( (v36 & 2) != 0 && (v36 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(HIDWORD(v2) - 4));
      KeAbPostRelease(HIDWORD(v2) - 4);
      if ( v33 > 0 )
      {
        __dmb(0xBu);
        v37 = (unsigned int *)(HIDWORD(v2) - 12);
        do
        {
          v38 = __ldrex(v37);
          v39 = v38 - v33;
        }
        while ( __strex(v39, v37) );
        __dmb(0xBu);
        if ( v39 <= 0 )
        {
          if ( v39 )
            KeBugCheckEx(24, 0, SHIDWORD(v2), 40, v39);
          AlpcpDestroyBlob(HIDWORD(v2));
        }
      }
      v6 = -1073741769;
    }
    return v6;
  }
  if ( AlpcpMessageLogEnabled )
    return sub_7BE3A8();
  v24 = *(_BYTE *)(HIDWORD(v2) - 16);
  v25 = 0;
  if ( (v24 & 1) != 0 )
  {
    v26 = *(__int16 *)(HIDWORD(v2) - 14);
    *(_WORD *)(HIDWORD(v2) - 14) = 0;
    v25 = 0x10000 - v26;
    *(_BYTE *)(HIDWORD(v2) - 16) = v24 & 0xFE;
  }
  v27 = (unsigned int *)(HIDWORD(v2) - 4);
  __dmb(0xBu);
  do
    v28 = __ldrex(v27);
  while ( __strex(v28 - 1, v27) );
  if ( (v28 & 2) != 0 && (v28 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(HIDWORD(v2) - 4));
  KeAbPostRelease(HIDWORD(v2) - 4);
  if ( (int)v2 <= 0 )
    return v6;
  __dmb(0xBu);
  v29 = (unsigned int *)(HIDWORD(v2) - 12);
  do
  {
    v30 = __ldrex(v29);
    v31 = v30 - v25;
  }
  while ( __strex(v31, v29) );
  __dmb(0xBu);
  if ( v31 > 0 )
    return v6;
  if ( v31 )
    KeBugCheckEx(24, 0, SHIDWORD(v2), 40, v31);
  AlpcpDestroyBlob(HIDWORD(v2));
  return v6;
}
