// AlpcpReplyLegacySynchronousRequest 
 
int __fastcall AlpcpReplyLegacySynchronousRequest(int a1, unsigned int a2, int a3, int a4)
{
  int *v4; // r10
  _DWORD *v5; // r6
  unsigned int v6; // r9
  int v7; // r5
  int v8; // r1
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r3
  _DWORD *v13; // r4
  int v14; // r1
  _DWORD *v15; // r2
  _DWORD *v16; // r3
  unsigned int *v17; // r8
  int v18; // r0
  int v19; // r5
  unsigned int v20; // r2
  int v21; // r3
  _DWORD *v22; // r2
  _DWORD *v23; // r3
  int v24; // r5
  unsigned int *v25; // r6
  unsigned int v26; // r2
  _DWORD *v27; // r3
  int v28; // r9
  unsigned int *v29; // r8
  unsigned int v30; // r1
  unsigned int *v31; // r2
  unsigned int v32; // r0
  int v33; // r0
  _DWORD *v34; // r9
  unsigned __int8 *v35; // r10
  int v36; // r0
  int v37; // r6
  unsigned int v38; // r2
  unsigned int v39; // r1
  int v40; // r3
  int v41; // r1
  unsigned int v42; // r3
  unsigned int *v43; // r9
  int v44; // r0
  int v45; // r10
  unsigned int v46; // r2
  int v47; // r3
  int v48; // r3
  unsigned int v49; // r2
  int v50; // r9
  unsigned int *v51; // r8
  unsigned int v52; // r1
  unsigned int *v53; // r2
  unsigned int v54; // r0
  int v55; // r0
  int v56; // r9
  unsigned int *v57; // r6
  unsigned int v58; // r1
  unsigned int *v59; // r2
  unsigned int v60; // r0
  int v61; // r0
  int v62; // r6
  unsigned int *v63; // r8
  unsigned int v64; // r1
  unsigned int *v65; // r2
  unsigned int v66; // r0
  int v67; // r0
  _DWORD *v70; // [sp+10h] [bp-48h]
  _DWORD *v71; // [sp+14h] [bp-44h] BYREF
  _DWORD *v72; // [sp+18h] [bp-40h]
  int v73; // [sp+20h] [bp-38h] BYREF
  int v74; // [sp+24h] [bp-34h]
  int v75; // [sp+28h] [bp-30h]
  int v76; // [sp+2Ch] [bp-2Ch]
  int v77; // [sp+30h] [bp-28h]
  int v78; // [sp+34h] [bp-24h]
  int varg_r0; // [sp+60h] [bp+8h]
  unsigned int varg_r1; // [sp+64h] [bp+Ch]
  int varg_r2; // [sp+68h] [bp+10h]
  int varg_r3; // [sp+6Ch] [bp+14h]

  varg_r2 = a3;
  varg_r3 = a4;
  v4 = (int *)a2;
  varg_r1 = a2;
  varg_r0 = a1;
  v5 = *(_DWORD **)a1;
  v71 = *(_DWORD **)a1;
  if ( !(_BYTE)a3 )
  {
    v9 = *(_DWORD *)(a2 + 4);
    v10 = v4[2];
    v11 = v4[3];
    v73 = *v4;
    v74 = v9;
    v75 = v10;
    v76 = v11;
    v12 = v4[5];
    v77 = v4[4];
    v78 = v12;
    v8 = 0;
    v6 = (__int16)v73;
    if ( (unsigned __int16)v73 >= (unsigned int)(unsigned __int16)(v73 + 24)
      || (unsigned int)(unsigned __int16)v73 + 24 > HIWORD(v73) )
    {
      v7 = -1073741811;
    }
    else
    {
      HIWORD(v73) = v73 + 24;
      v7 = 0;
    }
    if ( v7 < 0 )
      return v7;
LABEL_17:
    v7 = AlpcpLookupMessage(v5, v77, v8, &v71);
    if ( v7 < 0 )
      return v7;
    v13 = v71;
    v14 = v71[5];
    if ( (v14 & 0x80) != 0 )
    {
      AlpcpCancelMessage(v5, (int)v71, 0x10000);
      return -1073741769;
    }
    if ( (v14 & 0x200) != 0 || !v71[4] )
    {
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v71);
      v62 = 0;
      if ( (*(_BYTE *)(v13 - 4) & 1) != 0 )
      {
        v62 = 0x10000 - *((__int16 *)v13 - 7);
        *((_BYTE *)v13 - 16) &= 0xFEu;
        *((_WORD *)v13 - 7) = 0;
      }
      v63 = v13 - 1;
      __dmb(0xBu);
      do
        v64 = __ldrex(v63);
      while ( __strex(v64 - 1, v63) );
      if ( (v64 & 2) != 0 && (v64 & 4) == 0 )
        ExfTryToWakePushLock(v13 - 1);
      KeAbPostRelease((unsigned int)(v13 - 1));
      if ( v62 <= 0 )
        return -1073741790;
      __dmb(0xBu);
      v65 = v13 - 3;
      do
      {
        v66 = __ldrex(v65);
        v67 = v66 - v62;
      }
      while ( __strex(v67, v65) );
      __dmb(0xBu);
      if ( v67 > 0 )
        return -1073741790;
      if ( v67 )
        KeBugCheckEx(24, 0, (int)v13, 40, v67);
      goto LABEL_154;
    }
    v15 = (_DWORD *)v71[2];
    if ( v15 != v5 )
    {
      if ( !v15 )
      {
        v16 = (_DWORD *)v71[3];
        v72 = v16;
        if ( v16 )
        {
          v70 = (_DWORD *)v16[2];
          v17 = v70 - 1;
          v18 = KeAbPreAcquire((unsigned int)(v70 - 1), 0, 0);
          v19 = v18;
          do
            v20 = __ldrex(v17);
          while ( !v20 && __strex(0x11u, v17) );
          __dmb(0xBu);
          if ( v20 )
            ExfAcquirePushLockSharedEx(v17, v18, (unsigned int)v17);
          if ( v19 )
            *(_BYTE *)(v19 + 14) |= 1u;
          v21 = (v72[61] >> 1) & 3;
          if ( v21 == 1 || v21 != 2 )
          {
            v22 = v70;
            v23 = (_DWORD *)v70[2];
          }
          else
          {
            v22 = v70;
            if ( (_DWORD *)*v70 == v5 )
              goto LABEL_38;
            v23 = (_DWORD *)v70[1];
          }
          if ( v23 != v5 )
          {
            v24 = 0;
LABEL_40:
            v25 = v22 - 1;
            __dmb(0xBu);
            do
              v26 = __ldrex(v25);
            while ( v26 == 17 && __strex(0, v25) );
            if ( v26 != 17 )
              ExfReleasePushLockShared(v25);
            KeAbPostRelease((unsigned int)v25);
LABEL_51:
            if ( v24 )
            {
              if ( v6 >= 0x100 )
              {
                v7 = AlpcpCaptureMessageData(v13, v6, v4 + 6);
              }
              else
              {
                memmove((int)(v13 + 36), (int)(v4 + 6), v6);
                v7 = 0;
              }
              if ( v7 >= 0 )
              {
                v13[5] |= 0x10000u;
                __dmb(0xFu);
                v34 = (_DWORD *)v13[3];
                if ( v34 )
                {
                  if ( (v13[5] & 0x1000) != 0 )
                    ObfDereferenceObject(v13[3]);
                  v13[3] = 0;
                }
                v72 = (_DWORD *)v13[2];
                v35 = (unsigned __int8 *)(v72 + 28);
                v36 = KeAbPreAcquire((unsigned int)(v72 + 28), 0, 0);
                v37 = v36;
                do
                  v38 = __ldrex(v35);
                while ( __strex(v38 | 1, v35) );
                __dmb(0xBu);
                if ( (v38 & 1) != 0 )
                  ExfAcquirePushLockExclusiveEx(v35, v36, (unsigned int)v35);
                if ( v37 )
                  *(_BYTE *)(v37 + 14) |= 1u;
                --v72[67];
                v13[5] &= 0xFFFFFFF8;
                v13[2] = 0;
                *(_DWORD *)v13[1] = *v13;
                *(_DWORD *)(*v13 + 4) = v13[1];
                __dmb(0xBu);
                do
                  v39 = __ldrex((unsigned int *)v35);
                while ( __strex(v39 - 1, (unsigned int *)v35) );
                if ( (v39 & 2) != 0 && (v39 & 4) == 0 )
                  ExfTryToWakePushLock((unsigned int *)v35);
                KeAbPostRelease((unsigned int)v35);
                --*((_WORD *)v13 - 7);
                v13[30] = v73;
                *((_WORD *)v13 + 62) = 2;
                v40 = __mrc(15, 0, 13, 0, 3);
                v13[32] = *(_DWORD *)((v40 & 0xFFFFFFC0) + 0x36C);
                v13[33] = *(_DWORD *)((v40 & 0xFFFFFFC0) + 0x370);
                v41 = v13[5] | 0x200;
                v13[5] = v41;
                v42 = v41 & 0xFFFFFF87 | (4 * (v34[61] & 6));
                v13[5] = v42;
                if ( ((v42 >> 3) & 0xF) == 1 )
                {
                  v72 = (_DWORD *)v34[2];
                  v43 = v72 - 1;
                  v44 = KeAbPreAcquire((unsigned int)(v72 - 1), 0, 0);
                  v45 = v44;
                  do
                    v46 = __ldrex(v43);
                  while ( !v46 && __strex(0x11u, v43) );
                  __dmb(0xBu);
                  if ( v46 )
                    ExfAcquirePushLockSharedEx(v43, v44, (unsigned int)v43);
                  if ( v45 )
                    *(_BYTE *)(v45 + 14) |= 1u;
                  v47 = v72[1];
                  if ( v47 )
                    v48 = *(_DWORD *)(v47 + 28);
                  else
                    v48 = 0;
                  v13[16] = v48;
                  __dmb(0xBu);
                  do
                    v49 = __ldrex(v43);
                  while ( v49 == 17 && __strex(0, v43) );
                  if ( v49 != 17 )
                    ExfReleasePushLockShared(v43);
                  KeAbPostRelease((unsigned int)v43);
                }
                else
                {
                  v13[16] = v34[7];
                }
                v71 = (_DWORD *)v13[4];
                v13[4] = 0;
                --*((_WORD *)v13 - 7);
                v13[5] = v13[5] & 0xFFFEFFFF | 0x100;
                if ( AlpcpMessageLogEnabled )
                  AlpcpEnterStateChangeEventMessageLog(v13);
                v50 = 0;
                if ( (*(_BYTE *)(v13 - 4) & 1) != 0 )
                {
                  v50 = 0x10000 - *((__int16 *)v13 - 7);
                  *((_BYTE *)v13 - 16) &= 0xFEu;
                  *((_WORD *)v13 - 7) = 0;
                }
                v51 = v13 - 1;
                __dmb(0xBu);
                do
                  v52 = __ldrex(v51);
                while ( __strex(v52 - 1, v51) );
                if ( (v52 & 2) != 0 && (v52 & 4) == 0 )
                  ExfTryToWakePushLock(v13 - 1);
                KeAbPostRelease((unsigned int)(v13 - 1));
                if ( v50 > 0 )
                {
                  __dmb(0xBu);
                  v53 = v13 - 3;
                  do
                  {
                    v54 = __ldrex(v53);
                    v55 = v54 - v50;
                  }
                  while ( __strex(v55, v53) );
                  __dmb(0xBu);
                  if ( v55 <= 0 )
                  {
                    if ( v55 )
                      KeBugCheckEx(24, 0, (int)v13, 40, v55);
                    AlpcpDestroyBlob(v13);
                  }
                }
                if ( (*(_DWORD *)(a1 + 24) & 4) != 0 )
                  *(_DWORD *)(a1 + 12) = v71;
                else
                  KeReleaseSemaphoreEx((int)(v71 + 221), 1, 1, (int)v71, 2);
              }
              else
              {
                if ( AlpcpMessageLogEnabled )
                  AlpcpEnterStateChangeEventMessageLog(v13);
                v28 = 0;
                if ( (*(_BYTE *)(v13 - 4) & 1) != 0 )
                {
                  v28 = 0x10000 - *((__int16 *)v13 - 7);
                  *((_BYTE *)v13 - 16) &= 0xFEu;
                  *((_WORD *)v13 - 7) = 0;
                }
                v29 = v13 - 1;
                __dmb(0xBu);
                do
                  v30 = __ldrex(v29);
                while ( __strex(v30 - 1, v29) );
                if ( (v30 & 2) != 0 && (v30 & 4) == 0 )
                  ExfTryToWakePushLock(v13 - 1);
                KeAbPostRelease((unsigned int)(v13 - 1));
                if ( v28 > 0 )
                {
                  __dmb(0xBu);
                  v31 = v13 - 3;
                  do
                  {
                    v32 = __ldrex(v31);
                    v33 = v32 - v28;
                  }
                  while ( __strex(v33, v31) );
                  __dmb(0xBu);
                  if ( v33 <= 0 )
                  {
                    if ( v33 )
                      KeBugCheckEx(24, 0, (int)v13, 40, v33);
                    AlpcpDestroyBlob(v13);
                  }
                }
              }
              return v7;
            }
            goto LABEL_124;
          }
LABEL_38:
          v24 = 1;
          goto LABEL_40;
        }
LABEL_124:
        if ( AlpcpMessageLogEnabled )
          AlpcpEnterStateChangeEventMessageLog(v13);
        v56 = 0;
        if ( (*(_BYTE *)(v13 - 4) & 1) != 0 )
        {
          v56 = 0x10000 - *((__int16 *)v13 - 7);
          *((_BYTE *)v13 - 16) &= 0xFEu;
          *((_WORD *)v13 - 7) = 0;
        }
        v57 = v13 - 1;
        __dmb(0xBu);
        do
          v58 = __ldrex(v57);
        while ( __strex(v58 - 1, v57) );
        if ( (v58 & 2) != 0 && (v58 & 4) == 0 )
          ExfTryToWakePushLock(v13 - 1);
        KeAbPostRelease((unsigned int)(v13 - 1));
        if ( v56 <= 0 )
          return -1073741790;
        __dmb(0xBu);
        v59 = v13 - 3;
        do
        {
          v60 = __ldrex(v59);
          v61 = v60 - v56;
        }
        while ( __strex(v61, v59) );
        __dmb(0xBu);
        if ( v61 > 0 )
          return -1073741790;
        if ( v61 )
          KeBugCheckEx(24, 0, (int)v13, 40, v61);
LABEL_154:
        AlpcpDestroyBlob(v13);
        return -1073741790;
      }
      if ( (v5[61] & 6) != 6 )
        goto LABEL_124;
      v27 = (_DWORD *)v5[2];
      if ( !v27 || (_DWORD *)*v27 != v15 )
        goto LABEL_124;
    }
    if ( (v71[5] & 7) == 3 )
    {
      v24 = 1;
      goto LABEL_51;
    }
    goto LABEL_124;
  }
  if ( a2 >= MmUserProbeAddress )
    a2 = MmUserProbeAddress;
  memmove((int)&v73, a2, 0x18u);
  v6 = (__int16)v73;
  if ( (unsigned __int16)v73 >= (unsigned int)(unsigned __int16)(v73 + 24)
    || (unsigned int)(unsigned __int16)v73 + 24 > HIWORD(v73) )
  {
    v7 = -1073741811;
  }
  else
  {
    HIWORD(v73) = v73 + 24;
    v7 = 0;
  }
  if ( v7 >= 0 )
  {
    if ( !HIWORD(v74) || (v7 = AlpcpValidateDataInformation(v4, &v73), v7 >= 0) )
    {
      v8 = v78;
      goto LABEL_17;
    }
  }
  return v7;
}
