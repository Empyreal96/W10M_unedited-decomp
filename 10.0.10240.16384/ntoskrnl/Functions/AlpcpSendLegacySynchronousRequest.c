// AlpcpSendLegacySynchronousRequest 
 
int __fastcall AlpcpSendLegacySynchronousRequest(_DWORD *a1, int a2, unsigned int a3, int a4)
{
  int *v4; // r6
  int v7; // r1
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r3
  int v12; // r2
  int v13; // r4
  unsigned int v14; // r8
  unsigned int *v15; // r2
  unsigned int v16; // r5
  unsigned __int8 *v17; // r9
  int v18; // r4
  unsigned int v19; // r2
  unsigned int *v20; // r1
  unsigned int v21; // r0
  int v22; // r0
  int v23; // r4
  unsigned int v24; // r2
  unsigned int v25; // r2
  _DWORD *v26; // r2
  unsigned int *v27; // r8
  int v28; // r0
  int v29; // r6
  unsigned int v30; // r2
  unsigned int *v31; // r2
  unsigned int *v32; // r6
  int v33; // r0
  int v34; // r8
  unsigned int v35; // r2
  unsigned int v36; // r2
  unsigned int v37; // r2
  unsigned int *v38; // r8
  int v39; // r6
  unsigned int *v40; // r0
  unsigned int v41; // r2
  _DWORD *v42; // r0
  unsigned int *v43; // r2
  unsigned int v44; // r1
  unsigned int *v45; // r3
  _DWORD *v46; // r2
  int v47; // r6
  unsigned __int8 *v48; // r0
  unsigned int v49; // r2
  unsigned __int8 *v50; // r10
  int v51; // r0
  int v52; // r6
  unsigned int v53; // r2
  unsigned int v54; // r1
  unsigned int *v55; // r6
  _DWORD *v56; // lr
  int v57; // r0
  _DWORD *v58; // r1
  unsigned int *v59; // r0
  unsigned int v60; // r1
  int v61; // r3
  unsigned int *v62; // r1
  unsigned __int8 *v63; // r0
  unsigned int v64; // r2
  unsigned int *v65; // r1
  unsigned int v66; // r1
  int v67; // r2
  char v68; // r2
  unsigned int *v69; // r9
  unsigned int v70; // r1
  unsigned int *v71; // r3
  unsigned int *v72; // r2
  unsigned int v73; // r0
  int v74; // r0
  unsigned int *v75; // r9
  unsigned int v76; // r2
  unsigned int *v77; // r9
  unsigned int v78; // r2
  char v79; // r2
  unsigned int *v80; // r6
  unsigned int v81; // r1
  unsigned int *v82; // r3
  unsigned int *v83; // r2
  unsigned int v84; // r0
  int v85; // r0
  unsigned int *v87; // [sp+8h] [bp-58h] BYREF
  int v88; // [sp+Ch] [bp-54h]
  unsigned int *v89; // [sp+10h] [bp-50h]
  _DWORD *v90; // [sp+14h] [bp-4Ch]
  int v91; // [sp+18h] [bp-48h]
  unsigned int *v92; // [sp+1Ch] [bp-44h]
  unsigned int *v93; // [sp+20h] [bp-40h]
  unsigned int *v94; // [sp+24h] [bp-3Ch]
  int v95; // [sp+28h] [bp-38h] BYREF
  int v96; // [sp+2Ch] [bp-34h]
  int v97; // [sp+30h] [bp-30h]
  int v98; // [sp+34h] [bp-2Ch]
  int v99; // [sp+38h] [bp-28h]
  int v100; // [sp+3Ch] [bp-24h]
  _DWORD *varg_r0; // [sp+68h] [bp+8h]
  int varg_r1; // [sp+6Ch] [bp+Ch]
  unsigned int varg_r2; // [sp+70h] [bp+10h]
  int varg_r3; // [sp+74h] [bp+14h]

  varg_r3 = a4;
  v89 = (unsigned int *)(char)a4;
  LOBYTE(varg_r3) = a4;
  v4 = (int *)a3;
  varg_r2 = a3;
  v88 = a2;
  varg_r1 = a2;
  varg_r0 = a1;
  v87 = 0;
  if ( (_BYTE)a4 )
  {
    v7 = a3;
    if ( a3 >= MmUserProbeAddress )
      v7 = MmUserProbeAddress;
    memmove((int)&v95, v7, 0x18u);
  }
  else
  {
    v8 = *(_DWORD *)(a3 + 4);
    v9 = *(_DWORD *)(a3 + 8);
    v10 = v4[3];
    v95 = *v4;
    v96 = v8;
    v97 = v9;
    v98 = v10;
    v11 = v4[5];
    v99 = v4[4];
    v100 = v11;
  }
  if ( v99 )
    return AlpcpSendMessage(a2, v4);
  v12 = a1[61];
  if ( (v12 & 0x2000) == 0 || (a1[61] & 6) != 4 || (v12 & 0x38) != 0 || HIWORD(v96) )
    return AlpcpSendMessage(a2, v4);
  if ( (unsigned int)HIWORD(v95) > a1[42] )
    return -1073741777;
  v14 = (__int16)v95;
  if ( (unsigned __int16)v95 >= (unsigned int)(unsigned __int16)(v95 + 24)
    || (unsigned int)(unsigned __int16)v95 + 24 > HIWORD(v95) )
  {
    return -1073741811;
  }
  HIWORD(v95) = v95 + 24;
  __dmb(0xBu);
  v15 = a1 + 64;
  do
    v16 = __ldrex(v15);
  while ( __strex(0, v15) );
  v87 = (unsigned int *)v16;
  __dmb(0xBu);
  if ( v16 )
  {
    v17 = (unsigned __int8 *)(v16 - 4);
    v92 = (unsigned int *)(v16 - 4);
    v18 = KeAbPreAcquire(v16 - 4, 0, 0);
    do
      v19 = __ldrex(v17);
    while ( __strex(v19 | 1, v17) );
    __dmb(0xBu);
    if ( (v19 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v92, v18, (unsigned int)v92);
    if ( v18 )
      *(_BYTE *)(v18 + 14) |= 1u;
    *(_BYTE *)(v16 - 16) |= 1u;
    __dmb(0xBu);
    v20 = (unsigned int *)(v16 - 12);
    do
    {
      v21 = __ldrex(v20);
      v22 = v21 + 0x10000;
    }
    while ( __strex(v22, v20) );
    __dmb(0xBu);
    if ( v22 <= 0 )
      KeBugCheckEx(24, 0, v16, 38, v22);
    --*(_WORD *)(v16 - 14);
    v23 = *(_DWORD *)(v16 + 136) & 0x7FFFFFFF;
    memset((_BYTE *)v16, 0, 144);
    *(_DWORD *)(v16 + 136) = v23;
    do
    {
      __dmb(0xBu);
      do
      {
        v24 = __ldrex(AlpcpNextCallbackId);
        v25 = v24 + 1;
      }
      while ( __strex(v25, AlpcpNextCallbackId) );
      __dmb(0xBu);
    }
    while ( !v25 );
    *(_DWORD *)(v16 + 140) = v25;
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterAllocationEventMessageLog(v16);
  }
  else
  {
    v13 = AlpcpAllocateMessage(&v87, 0, 0);
    if ( v13 < 0 )
      return v13;
    v16 = (unsigned int)v87;
  }
  v26 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v90 = v26;
  v92 = v26;
  *(_DWORD *)(v16 + 128) = v26[219];
  *(_DWORD *)(v16 + 132) = v26[220];
  *(_DWORD *)(v16 + 120) = v95;
  *(_WORD *)(v16 + 124) = 8193;
  if ( v89 )
  {
    if ( v14 >= 0x100 )
    {
      v13 = AlpcpCaptureMessageData(v16, v14, v4 + 6);
    }
    else
    {
      memmove(v16 + 144, (int)(v4 + 6), v14);
      v13 = 0;
    }
    v91 = v13;
  }
  else if ( v14 >= 0x100 )
  {
    v13 = AlpcpCaptureMessageData(v16, v14, v4 + 6);
  }
  else
  {
    memmove(v16 + 144, (int)(v4 + 6), v14);
    v13 = 0;
  }
  if ( v13 >= 0 )
  {
    v89 = (unsigned int *)a1[2];
    v27 = v89 - 1;
    v94 = v89 - 1;
    v28 = KeAbPreAcquire((unsigned int)(v89 - 1), 0, 0);
    v29 = v28;
    do
      v30 = __ldrex(v27);
    while ( !v30 && __strex(0x11u, v27) );
    __dmb(0xBu);
    if ( v30 )
      ExfAcquirePushLockSharedEx(v27, v28, (unsigned int)v27);
    if ( v29 )
      *(_BYTE *)(v29 + 14) |= 1u;
    v87 = (unsigned int *)a1[62];
    v31 = (unsigned int *)a1[63];
    v92 = v31;
    if ( v87 && v31 )
    {
      v32 = v31 + 52;
      v33 = KeAbPreAcquire((unsigned int)(v31 + 52), 0, 0);
      v34 = v33;
      do
        v35 = __ldrex(v32);
      while ( !v35 && __strex(0x11u, v32) );
      __dmb(0xBu);
      if ( v35 )
        ExfAcquirePushLockSharedEx(v32, v33, (unsigned int)v32);
      if ( v34 )
        *(_BYTE *)(v34 + 14) |= 1u;
      if ( (v92[61] & 0x20) != 0 )
      {
        v13 = -1073741769;
        __dmb(0xBu);
        do
          v36 = __ldrex(v32);
        while ( v36 == 17 && __strex(0, v32) );
        if ( v36 != 17 )
          ExfReleasePushLockShared(v32);
        KeAbPostRelease((unsigned int)v32);
      }
      else
      {
        *(_DWORD *)(v16 + 64) = v92[7];
        __dmb(0xBu);
        do
          v37 = __ldrex(v32);
        while ( v37 == 17 && __strex(0, v32) );
        if ( v37 != 17 )
          ExfReleasePushLockShared(v32);
        KeAbPostRelease((unsigned int)v32);
        v38 = v87;
        v93 = v87 + 52;
        v39 = KeAbPreAcquire((unsigned int)(v87 + 52), 0, 0);
        v40 = v38 + 52;
        do
          v41 = __ldrex(v40);
        while ( !v41 && __strex(0x11u, v40) );
        __dmb(0xBu);
        if ( v41 )
          ExfAcquirePushLockSharedEx(v40, v39, (unsigned int)(v38 + 52));
        if ( v39 )
          *(_BYTE *)(v39 + 14) |= 1u;
        if ( (v38[61] & 0x20) != 0 )
        {
          v13 = -1073741769;
        }
        else
        {
          *(_WORD *)(v16 - 14) += 3;
          __dmb(0xBu);
          v42 = v90;
          v43 = v90 + 244;
          do
            v44 = __ldrex(v43);
          while ( __strex(v16, v43) );
          __dmb(0xBu);
          *(_DWORD *)(v16 + 16) = v42;
          *(_DWORD *)(v16 + 12) = a1;
          *(_DWORD *)(v16 + 20) &= 0xFFFFEFFF;
          v45 = v89;
          *(_DWORD *)(v16 + 92) = v89;
          *(_DWORD *)(v16 + 96) = *v45;
          *(_DWORD *)(v88 + 4) = v16;
          if ( AlpcpLogEnabled )
          {
            AlpcpLogSendMessage(v16, v44);
            if ( AlpcpLogEnabled )
              AlpcpLogWaitForReply(v16);
          }
          v46 = 0;
          v90 = 0;
          if ( (unsigned int *)v38[35] != v38 + 35 )
          {
            v92 = v38 + 34;
            v47 = KeAbPreAcquire((unsigned int)(v38 + 34), 0, 0);
            v48 = (unsigned __int8 *)(v38 + 34);
            do
              v49 = __ldrex(v48);
            while ( __strex(v49 | 1, v48) );
            __dmb(0xBu);
            if ( (v49 & 1) != 0 )
              ExfAcquirePushLockExclusiveEx(v48, v47, (unsigned int)(v38 + 34));
            if ( v47 )
              *(_BYTE *)(v47 + 14) |= 1u;
            if ( (unsigned int *)v38[35] != v38 + 35 )
            {
              v90 = (_DWORD *)(v38[35] - 988);
              v90[245] = v16;
              ++*(_WORD *)(v16 - 14);
              *(_DWORD *)(v16 + 20) |= 0x4000u;
              v50 = (unsigned __int8 *)(v38 + 28);
              v89 = v38 + 28;
              v51 = KeAbPreAcquire((unsigned int)(v38 + 28), 0, 0);
              v52 = v51;
              do
                v53 = __ldrex(v50);
              while ( __strex(v53 | 1, v50) );
              __dmb(0xBu);
              if ( (v53 & 1) != 0 )
                ExfAcquirePushLockExclusiveEx(v38 + 28, v51, (unsigned int)(v38 + 28));
              if ( v52 )
                *(_BYTE *)(v52 + 14) |= 1u;
              *(_DWORD *)(v16 + 8) = v38;
              *(_DWORD *)(v16 + 20) = *(_DWORD *)(v16 + 20) & 0xFFFFFF83 | (4 * (v38[61] & 6)) | 3;
              *(_DWORD *)(v16 + 4) = v38[30];
              *(_DWORD *)v16 = v38 + 29;
              *(_DWORD *)v38[30] = v16;
              v38[30] = v16;
              ++v38[67];
              __dmb(0xBu);
              do
                v54 = __ldrex((unsigned int *)v50);
              while ( __strex(v54 - 1, (unsigned int *)v50) );
              v55 = v89;
              if ( (v54 & 2) != 0 && (v54 & 4) == 0 )
                ExfTryToWakePushLock(v89);
              KeAbPostRelease((unsigned int)v55);
              v56 = v90;
              v57 = v90[247];
              v58 = (_DWORD *)v90[248];
              if ( *(_DWORD **)(v57 + 4) != v90 + 247 || (_DWORD *)*v58 != v90 + 247 )
                __fastfail(3u);
              *v58 = v57;
              *(_DWORD *)(v57 + 4) = v58;
              v56[247] = 0;
            }
            __dmb(0xBu);
            v59 = v92;
            do
              v60 = __ldrex(v59);
            while ( __strex(v60 - 1, v59) );
            if ( (v60 & 2) != 0 && (v60 & 4) == 0 )
            {
              ExfTryToWakePushLock(v59);
              v59 = v92;
            }
            KeAbPostRelease((unsigned int)v59);
            v46 = v90;
          }
          v61 = v88;
          *(_DWORD *)(v88 + 16) = 0;
          *(_DWORD *)(v61 + 12) = 0;
          *(_DWORD *)(v61 + 20) = 0;
          if ( v46 )
          {
            *(_DWORD *)(v61 + 12) = v46;
          }
          else
          {
            v90 = v87 + 23;
            v62 = (unsigned int *)KeAbPreAcquire((unsigned int)(v87 + 23), 0, 0);
            v92 = v62;
            v63 = (unsigned __int8 *)v90;
            do
              v64 = __ldrex(v63);
            while ( __strex(v64 | 1, v63) );
            __dmb(0xBu);
            if ( (v64 & 1) != 0 )
            {
              ExfAcquirePushLockExclusiveEx(v63, (int)v62, (unsigned int)v63);
              v62 = v92;
              v63 = (unsigned __int8 *)v90;
            }
            if ( v62 )
              *((_BYTE *)v62 + 14) |= 1u;
            v65 = v87;
            *(_DWORD *)(v16 + 8) = v87;
            *(_DWORD *)(v16 + 20) = *(_DWORD *)(v16 + 20) & 0xFFFFFF81 | (4 * (v65[61] & 6)) | 1;
            *(_DWORD *)(v16 + 4) = v65[25];
            *(_DWORD *)v16 = v65 + 24;
            *(_DWORD *)v65[25] = v16;
            v65[25] = v16;
            ++v65[65];
            __dmb(0xBu);
            do
              v66 = __ldrex((unsigned int *)v63);
            while ( __strex(v66 - 1, (unsigned int *)v63) );
            if ( (v66 & 2) != 0 && (v66 & 4) == 0 )
            {
              ExfTryToWakePushLock((unsigned int *)v63);
              v63 = (unsigned __int8 *)v90;
            }
            KeAbPostRelease((unsigned int)v63);
            if ( (v87[61] & 0x200) != 0 )
            {
              ObfReferenceObject((int)v87);
              v67 = v88;
              *(_DWORD *)(v88 + 16) = v87;
              *(_BYTE *)(v67 + 34) = 0;
            }
          }
          if ( AlpcpMessageLogEnabled )
            AlpcpEnterStateChangeEventMessageLog(v16);
          v92 = 0;
          v68 = *(_BYTE *)(v16 - 16);
          if ( (v68 & 1) != 0 )
          {
            v92 = (unsigned int *)(0x10000 - *(__int16 *)(v16 - 14));
            *(_BYTE *)(v16 - 16) = v68 & 0xFE;
            *(_WORD *)(v16 - 14) = 0;
          }
          v69 = (unsigned int *)(v16 - 4);
          __dmb(0xBu);
          do
            v70 = __ldrex(v69);
          while ( __strex(v70 - 1, v69) );
          if ( (v70 & 2) != 0 && (v70 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)(v16 - 4));
          KeAbPostRelease(v16 - 4);
          v71 = v92;
          if ( (int)v92 > 0 )
          {
            __dmb(0xBu);
            v72 = (unsigned int *)(v16 - 12);
            do
            {
              v73 = __ldrex(v72);
              v74 = v73 - (_DWORD)v71;
            }
            while ( __strex(v74, v72) );
            __dmb(0xBu);
            if ( v74 <= 0 )
            {
              if ( v74 )
                KeBugCheckEx(24, 0, v16, 40, v74);
              AlpcpDestroyBlob(v16);
            }
          }
        }
        __dmb(0xBu);
        v75 = v93;
        do
          v76 = __ldrex(v75);
        while ( v76 == 17 && __strex(0, v75) );
        if ( v76 != 17 )
          ExfReleasePushLockShared(v75);
        KeAbPostRelease((unsigned int)v75);
      }
    }
    else
    {
      v13 = -1073741769;
    }
    __dmb(0xBu);
    v77 = v94;
    do
      v78 = __ldrex(v77);
    while ( v78 == 17 && __strex(0, v77) );
    if ( v78 != 17 )
      ExfReleasePushLockShared(v77);
    KeAbPostRelease((unsigned int)v77);
  }
  if ( v13 < 0 && v16 )
  {
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v16);
    v92 = 0;
    v79 = *(_BYTE *)(v16 - 16);
    if ( (v79 & 1) != 0 )
    {
      v92 = (unsigned int *)(0x10000 - *(__int16 *)(v16 - 14));
      *(_BYTE *)(v16 - 16) = v79 & 0xFE;
      *(_WORD *)(v16 - 14) = 0;
    }
    v80 = (unsigned int *)(v16 - 4);
    __dmb(0xBu);
    do
      v81 = __ldrex(v80);
    while ( __strex(v81 - 1, v80) );
    if ( (v81 & 2) != 0 && (v81 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v16 - 4));
    KeAbPostRelease(v16 - 4);
    v82 = v92;
    if ( (int)v92 > 0 )
    {
      __dmb(0xBu);
      v83 = (unsigned int *)(v16 - 12);
      do
      {
        v84 = __ldrex(v83);
        v85 = v84 - (_DWORD)v82;
      }
      while ( __strex(v85, v83) );
      __dmb(0xBu);
      if ( v85 <= 0 )
      {
        if ( v85 )
          KeBugCheckEx(24, 0, v16, 40, v85);
        AlpcpDestroyBlob(v16);
      }
    }
  }
  return v13;
}
