// AlpcpCreateReserve 
 
int __fastcall AlpcpCreateReserve(_DWORD *a1, unsigned int a2, _DWORD *a3)
{
  _BYTE *v6; // r0
  _DWORD *v7; // r4
  int v8; // r8
  unsigned int *v9; // r7
  unsigned int v10; // r0
  int v11; // r5
  int v12; // r7
  char v13; // r2
  int v14; // r9
  int v15; // r3
  unsigned int *v16; // r8
  unsigned int v17; // r1
  unsigned int *v18; // r2
  unsigned int v19; // r6
  int v20; // r6
  unsigned int *v21; // r5
  int v22; // r0
  int v23; // r6
  unsigned int v24; // r2
  _DWORD *v25; // r7
  int v26; // r6
  bool v27; // zf
  unsigned int *v28; // lr
  int v29; // r0
  int v30; // r1
  int v31; // r3
  int v32; // r0
  unsigned __int8 *v33; // r6
  int v34; // r0
  int v35; // r8
  unsigned int v36; // r2
  _DWORD *v37; // r1
  unsigned int v38; // r1
  unsigned int v39; // r2
  unsigned int *v40; // r2
  unsigned int v41; // r1
  int v42; // r1
  unsigned int v43; // r1
  unsigned int *v44; // r2
  unsigned int v45; // r1
  int v46; // r1
  unsigned int v47; // r3
  unsigned int v48; // r2
  unsigned int *v49; // r2
  unsigned int v50; // r1
  int v51; // r1
  unsigned int *v52; // r2
  unsigned int v53; // r1
  int v54; // r1
  unsigned int v55; // r2
  unsigned int *v56; // r2
  unsigned int v57; // r1
  int v58; // r1
  unsigned int v59; // r2
  unsigned int *v60; // r2
  unsigned int v61; // r1
  int v62; // r1
  int v63; // [sp+8h] [bp-28h] BYREF
  _DWORD *v64; // [sp+Ch] [bp-24h] BYREF
  _DWORD *v65; // [sp+10h] [bp-20h]

  v65 = a3;
  if ( a2 > 0xFFD7 )
    return sub_7DDB0C();
  v6 = (_BYTE *)AlpcpAllocateBlob(AlpcReserveType, 20, 1);
  v7 = v6;
  if ( v6 )
  {
    memset(v6, 0, 20);
    v8 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v9 = (unsigned int *)(v8 + 668);
    __pld((void *)(v8 + 668));
    v10 = *(_DWORD *)(v8 + 668);
    __dmb(0xBu);
    while ( 1 )
    {
      if ( v10 < 0x190 )
      {
        v11 = PsChargeProcessPagedPoolQuota(v8, 400);
        goto LABEL_7;
      }
      __dmb(0xBu);
      do
        v43 = __ldrex(v9);
      while ( v43 == v10 && __strex(v10 - 400, v9) );
      __dmb(0xBu);
      if ( v43 == v10 )
        break;
      v10 = *v9;
      __dmb(0xBu);
    }
    v11 = 0;
LABEL_7:
    if ( v11 < 0 )
    {
      __dmb(0xBu);
      v44 = v7 - 3;
      do
      {
        v45 = __ldrex(v44);
        v46 = v45 - 1;
      }
      while ( __strex(v46, v44) );
      __dmb(0xBu);
      if ( v46 > 0 )
        return v11;
      if ( v46 )
        KeBugCheckEx(24, 0, (int)v7, 33, v46);
    }
    else
    {
      v11 = AlpcpAllocateMessage(&v63, a2, 1);
      if ( v11 < 0 )
      {
        v47 = *v9;
        __dmb(0xBu);
        if ( v47 + 400 >= 0x1000 )
        {
          PsReturnProcessPagedPoolQuota(v8, 0x190u);
        }
        else
        {
          __dmb(0xBu);
          do
            v48 = __ldrex(v9);
          while ( __strex(v48 + 400, v9) );
          __dmb(0xBu);
        }
        __dmb(0xBu);
        v49 = v7 - 3;
        do
        {
          v50 = __ldrex(v49);
          v51 = v50 - 1;
        }
        while ( __strex(v51, v49) );
        __dmb(0xBu);
        if ( v51 > 0 )
          return v11;
        if ( v51 )
          KeBugCheckEx(24, 0, (int)v7, 33, v51);
      }
      else
      {
        ObfReferenceObjectWithTag(v8);
        v12 = v63;
        *(_DWORD *)(v63 + 28) = v8;
        v7[3] = v12;
        *(_DWORD *)(v12 + 52) = v7;
        v11 = AlpcpCaptureMessageData(v7[3], a2, 0);
        if ( AlpcpMessageLogEnabled )
          AlpcpEnterStateChangeEventMessageLog(v12);
        v13 = *(_BYTE *)(v12 - 16);
        v14 = 0;
        if ( (v13 & 1) != 0 )
        {
          v15 = *(__int16 *)(v12 - 14);
          *(_WORD *)(v12 - 14) = 0;
          v14 = 0x10000 - v15;
          *(_BYTE *)(v12 - 16) = v13 & 0xFE;
        }
        v16 = (unsigned int *)(v12 - 4);
        __dmb(0xBu);
        do
          v17 = __ldrex(v16);
        while ( __strex(v17 - 1, v16) );
        if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)(v12 - 4));
        KeAbPostRelease(v12 - 4);
        if ( v14 > 0 )
        {
          __dmb(0xBu);
          v18 = (unsigned int *)(v12 - 12);
          do
          {
            v19 = __ldrex(v18);
            v20 = v19 - v14;
          }
          while ( __strex(v20, v18) );
          __dmb(0xBu);
          if ( v20 <= 0 )
          {
            if ( v20 )
              KeBugCheckEx(24, 0, v12, 40, v20);
            AlpcpDestroyBlob(v12);
          }
        }
        if ( v11 >= 0 )
        {
          v21 = a1 + 52;
          v22 = KeAbPreAcquire((unsigned int)(a1 + 52), 0, 0);
          v23 = v22;
          do
            v24 = __ldrex(v21);
          while ( !v24 && __strex(0x11u, v21) );
          __dmb(0xBu);
          if ( v24 )
            ExfAcquirePushLockSharedEx(a1 + 52, v22, (unsigned int)(a1 + 52));
          if ( v23 )
            *(_BYTE *)(v23 + 14) |= 1u;
          if ( (a1[61] & 0x20) != 0 )
          {
            __dmb(0xBu);
            do
              v55 = __ldrex(v21);
            while ( v55 == 17 && __strex(0, v21) );
            if ( v55 != 17 )
              ExfReleasePushLockShared(a1 + 52);
            KeAbPostRelease((unsigned int)(a1 + 52));
            __dmb(0xBu);
            v56 = v7 - 3;
            do
            {
              v57 = __ldrex(v56);
              v58 = v57 - 1;
            }
            while ( __strex(v58, v56) );
            __dmb(0xBu);
            if ( v58 <= 0 )
            {
              if ( v58 )
                KeBugCheckEx(24, 0, (int)v7, 33, v58);
              AlpcpDestroyBlob(v7);
            }
            return -1073741769;
          }
          v25 = v7 - 6;
          v26 = *(v7 - 3);
          v27 = v26 == 0;
          if ( v26 <= 0 )
          {
LABEL_104:
            if ( !v27 )
              KeBugCheckEx(24, 0, (int)v7, 32, v26);
          }
          else
          {
            v28 = v7 - 3;
            while ( 1 )
            {
              v29 = v26;
              __dmb(0xBu);
              do
                v30 = __ldrex(v28);
              while ( v30 == v26 && __strex(v26 + 1, v28) );
              v26 = v30;
              __dmb(0xBu);
              if ( v30 == v29 )
                break;
              if ( v30 <= 0 )
              {
                v27 = v30 == 0;
                goto LABEL_104;
              }
            }
          }
          AlpcpStartInitialization(v7);
          v31 = a1[2];
          v64 = v7;
          v7[1] = v31 + 20;
          v32 = AlpcAddHandleTableEntry(a1[2] + 20, &v64);
          v7[2] = v32;
          if ( v32 != -1 )
          {
            *v7 = a1;
            ObfReferenceObject((int)a1);
            v33 = (unsigned __int8 *)(a1 + 49);
            v34 = KeAbPreAcquire((unsigned int)(a1 + 49), 0, 0);
            v35 = v34;
            do
              v36 = __ldrex(v33);
            while ( __strex(v36 | 1, v33) );
            __dmb(0xBu);
            if ( (v36 & 1) != 0 )
              ExfAcquirePushLockExclusiveEx(a1 + 49, v34, (unsigned int)(a1 + 49));
            if ( v35 )
              *(_BYTE *)(v35 + 14) |= 1u;
            v37 = (_DWORD *)a1[51];
            *v25 = a1 + 50;
            *(v7 - 5) = v37;
            if ( (_DWORD *)*v37 != a1 + 50 )
              __fastfail(3u);
            *v37 = v25;
            a1[51] = v25;
            __dmb(0xBu);
            do
              v38 = __ldrex((unsigned int *)v33);
            while ( __strex(v38 - 1, (unsigned int *)v33) );
            if ( (v38 & 2) != 0 && (v38 & 4) == 0 )
              ExfTryToWakePushLock(a1 + 49);
            KeAbPostRelease((unsigned int)(a1 + 49));
            __dmb(0xBu);
            do
              v39 = __ldrex(v21);
            while ( v39 == 17 && __strex(0, v21) );
            if ( v39 != 17 )
              ExfReleasePushLockShared(a1 + 52);
            KeAbPostRelease((unsigned int)(a1 + 52));
            *v65 = v7[2];
            AlpcpEndInitialization(v7);
            __dmb(0xBu);
            v40 = v7 - 3;
            do
            {
              v41 = __ldrex(v40);
              v42 = v41 - 1;
            }
            while ( __strex(v42, v40) );
            __dmb(0xBu);
            if ( v42 <= 0 )
            {
              if ( v42 )
                KeBugCheckEx(24, 0, (int)v7, 33, v42);
              AlpcpDestroyBlob(v7);
            }
            return 0;
          }
          __dmb(0xBu);
          do
            v59 = __ldrex(v21);
          while ( v59 == 17 && __strex(0, v21) );
          if ( v59 != 17 )
            ExfReleasePushLockShared(a1 + 52);
          KeAbPostRelease((unsigned int)(a1 + 52));
          v7[1] = 0;
          AlpcpEndInitialization(v7);
          __dmb(0xBu);
          v60 = v7 - 3;
          do
          {
            v61 = __ldrex(v60);
            v62 = v61 - 2;
          }
          while ( __strex(v62, v60) );
          __dmb(0xBu);
          if ( v62 <= 0 )
          {
            if ( v62 )
              KeBugCheckEx(24, 0, (int)v7, 33, v62);
            AlpcpDestroyBlob(v7);
          }
          return -1073741670;
        }
        __dmb(0xBu);
        v52 = v7 - 3;
        do
        {
          v53 = __ldrex(v52);
          v54 = v53 - 1;
        }
        while ( __strex(v54, v52) );
        __dmb(0xBu);
        if ( v54 > 0 )
          return v11;
        if ( v54 )
          KeBugCheckEx(24, 0, (int)v7, 33, v54);
      }
    }
    AlpcpDestroyBlob(v7);
    return v11;
  }
  return -1073741670;
}
