// AlpcpLookupMessage 
 
int __fastcall AlpcpLookupMessage(int a1, int a2, int a3, _DWORD *a4)
{
  _DWORD *v5; // r9
  int v7; // r9
  char v8; // r5
  _DWORD *v9; // r7
  int v10; // r0
  unsigned int v11; // r1
  _DWORD *v12; // r4
  int v13; // r5
  bool v14; // zf
  unsigned int *v15; // lr
  int v16; // r0
  int v17; // r1
  int v18; // r5
  unsigned __int8 *v19; // r0
  unsigned int v20; // r2
  unsigned int *v21; // r0
  unsigned int v22; // r2
  int v23; // r2
  unsigned int v24; // r0
  int result; // r0
  int v26; // r3
  int v27; // r0
  int v28; // r5
  _DWORD *v29; // r5
  unsigned __int8 *v30; // r7
  int v31; // r0
  int v32; // r6
  unsigned int v33; // r2
  unsigned int *v34; // r1
  unsigned int v35; // r2
  int v36; // r2
  unsigned int v37; // r2
  unsigned int v38; // r2
  unsigned int v39; // r1
  int v40; // r6
  unsigned int *v41; // r5
  unsigned int v42; // r1
  unsigned int *v43; // r2
  unsigned int v44; // r0
  int v45; // r0
  int v46; // r6
  unsigned int *v47; // r5
  unsigned int v48; // r1
  unsigned int *v49; // r2
  unsigned int v50; // r0
  int v51; // r0
  int v52; // r6
  unsigned int *v53; // r5
  unsigned int v54; // r1
  unsigned int *v55; // r2
  unsigned int v56; // r0
  int v57; // r0
  int v58; // r6
  unsigned int *v59; // r5
  unsigned int v60; // r1
  unsigned int *v61; // r2
  unsigned int v62; // r0
  int v63; // r0
  int v64; // r6
  unsigned int *v65; // r5
  unsigned int v66; // r1
  unsigned int *v67; // r2
  unsigned int v68; // r0
  int v69; // r0

  v5 = a4;
  if ( a2 >= 0 )
  {
    if ( (a2 & 0xFC000000) != 0 )
    {
      if ( !AlpcpSecondaryMessageTables )
        return -1073740030;
      v7 = *(_DWORD *)(AlpcpSecondaryMessageTables + 4 * ((unsigned int)a2 >> 26));
    }
    else
    {
      v7 = AlpcMessageTable;
    }
    if ( v7 )
    {
      v8 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
      if ( (a2 & 0x7FC) != 0 )
      {
        v9 = (_DWORD *)ExpLookupHandleTableEntry(v7, a2 & 0x3FFFFFF);
        if ( v9 )
        {
          do
          {
            while ( 1 )
            {
              __pld(v9);
              v10 = *v9;
              if ( (*v9 & 1) != 0 )
                break;
              if ( !v10 )
                goto LABEL_49;
              ExpBlockOnLockedHandleEntry(v7, (unsigned __int64 *)v9, *v9);
            }
            do
              v11 = __ldrex(v9);
            while ( v11 == v10 && __strex(v10 - 1, v9) );
            __dmb(0xBu);
          }
          while ( v11 != v10 );
          v12 = (_DWORD *)(*v9 & 0xFFFFFFF8);
          if ( v12[34] == a2 && (!a3 || v12[35] == a3) )
          {
            v13 = *(v12 - 3);
            v14 = v13 == 0;
            if ( v13 > 0 )
            {
              v15 = v12 - 3;
              while ( 1 )
              {
                v16 = v13;
                __dmb(0xBu);
                do
                  v17 = __ldrex(v15);
                while ( v17 == v13 && __strex(v13 + 1, v15) );
                v13 = v17;
                __dmb(0xBu);
                if ( v17 == v16 )
                  break;
                if ( v17 <= 0 )
                {
                  v14 = v17 == 0;
                  goto LABEL_80;
                }
              }
              if ( v17 == -1 )
                goto LABEL_74;
              v18 = KeAbPreAcquire((unsigned int)(v12 - 1), 0, 0);
              v19 = (unsigned __int8 *)(v12 - 1);
              do
                v20 = __ldrex(v19);
              while ( __strex(v20 | 1, v19) );
              __dmb(0xBu);
              if ( (v20 & 1) != 0 )
                ExfAcquirePushLockExclusiveEx(v19, v18, (unsigned int)(v12 - 1));
              if ( v18 )
                *(_BYTE *)(v18 + 14) |= 1u;
              *((_BYTE *)v12 - 16) |= 1u;
              __dmb(0xBu);
              v21 = v12 - 3;
              do
              {
                v22 = __ldrex(v21);
                v23 = v22 + 0x10000;
              }
              while ( __strex(v23, v21) );
              __dmb(0xBu);
              if ( v23 <= 0 )
                KeBugCheckEx(24, 0, (int)v12, 38, v23);
              --*((_WORD *)v12 - 7);
              __dmb(0xBu);
              do
                v24 = __ldrex(v9);
              while ( __strex(v24 + 1, v9) );
              __dmb(0xBu);
              __dmb(0xFu);
              if ( *(_DWORD *)(v7 + 32) )
                ExfUnblockPushLock(v7 + 32, 0);
              if ( v12[34] == a2 )
              {
                if ( !a3 || v12[35] == a3 )
                {
                  if ( !v12[3] && !v12[2] )
                  {
                    if ( AlpcpMessageLogEnabled )
                      AlpcpEnterStateChangeEventMessageLog(v12);
                    v52 = 0;
                    if ( (*(_BYTE *)(v12 - 4) & 1) != 0 )
                    {
                      v52 = 0x10000 - *((__int16 *)v12 - 7);
                      *((_BYTE *)v12 - 16) &= 0xFEu;
                      *((_WORD *)v12 - 7) = 0;
                    }
                    v53 = v12 - 1;
                    __dmb(0xBu);
                    do
                      v54 = __ldrex(v53);
                    while ( __strex(v54 - 1, v53) );
                    if ( (v54 & 2) != 0 && (v54 & 4) == 0 )
                      ExfTryToWakePushLock(v12 - 1);
                    KeAbPostRelease((unsigned int)(v12 - 1));
                    if ( v52 <= 0 )
                      return -1073740030;
                    __dmb(0xBu);
                    v55 = v12 - 3;
                    do
                    {
                      v56 = __ldrex(v55);
                      v57 = v56 - v52;
                    }
                    while ( __strex(v57, v55) );
                    __dmb(0xBu);
                    if ( v57 > 0 )
                      return -1073740030;
                    if ( v57 )
                      KeBugCheckEx(24, 0, (int)v12, 40, v57);
                    goto LABEL_98;
                  }
                  if ( a1 )
                  {
                    if ( v12[23] == *(_DWORD *)(a1 + 8) || v12[24] == a1 )
                    {
LABEL_41:
                      result = 0;
                      *a4 = v12;
                      return result;
                    }
                    if ( AlpcpMessageLogEnabled )
                      AlpcpEnterStateChangeEventMessageLog(v12);
                    v64 = 0;
                    if ( (*(_BYTE *)(v12 - 4) & 1) != 0 )
                    {
                      v64 = 0x10000 - *((__int16 *)v12 - 7);
                      *((_BYTE *)v12 - 16) &= 0xFEu;
                      *((_WORD *)v12 - 7) = 0;
                    }
                    v65 = v12 - 1;
                    __dmb(0xBu);
                    do
                      v66 = __ldrex(v65);
                    while ( __strex(v66 - 1, v65) );
                    if ( (v66 & 2) != 0 && (v66 & 4) == 0 )
                      ExfTryToWakePushLock(v12 - 1);
                    KeAbPostRelease((unsigned int)(v12 - 1));
                    if ( v64 <= 0 )
                      return -1073741790;
                    __dmb(0xBu);
                    v67 = v12 - 3;
                    do
                    {
                      v68 = __ldrex(v67);
                      v69 = v68 - v64;
                    }
                    while ( __strex(v69, v67) );
                    __dmb(0xBu);
                    if ( v69 > 0 )
                      return -1073741790;
                    if ( v69 )
                      KeBugCheckEx(24, 0, (int)v12, 40, v69);
                  }
                  else
                  {
                    if ( v12[2] && *(_DWORD *)(v12[2] + 12) == *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) )
                      goto LABEL_41;
                    if ( AlpcpMessageLogEnabled )
                      AlpcpEnterStateChangeEventMessageLog(v12);
                    v58 = 0;
                    if ( (*(_BYTE *)(v12 - 4) & 1) != 0 )
                    {
                      v58 = 0x10000 - *((__int16 *)v12 - 7);
                      *((_BYTE *)v12 - 16) &= 0xFEu;
                      *((_WORD *)v12 - 7) = 0;
                    }
                    v59 = v12 - 1;
                    __dmb(0xBu);
                    do
                      v60 = __ldrex(v59);
                    while ( __strex(v60 - 1, v59) );
                    if ( (v60 & 2) != 0 && (v60 & 4) == 0 )
                      ExfTryToWakePushLock(v12 - 1);
                    KeAbPostRelease((unsigned int)(v12 - 1));
                    if ( v58 <= 0 )
                      return -1073741790;
                    __dmb(0xBu);
                    v61 = v12 - 3;
                    do
                    {
                      v62 = __ldrex(v61);
                      v63 = v62 - v58;
                    }
                    while ( __strex(v63, v61) );
                    __dmb(0xBu);
                    if ( v63 > 0 )
                      return -1073741790;
                    if ( v63 )
                      KeBugCheckEx(24, 0, (int)v12, 40, v63);
                  }
                  AlpcpDestroyBlob(v12);
                  return -1073741790;
                }
                if ( AlpcpMessageLogEnabled )
                  AlpcpEnterStateChangeEventMessageLog(v12);
                v46 = 0;
                if ( (*(_BYTE *)(v12 - 4) & 1) != 0 )
                {
                  v46 = 0x10000 - *((__int16 *)v12 - 7);
                  *((_BYTE *)v12 - 16) &= 0xFEu;
                  *((_WORD *)v12 - 7) = 0;
                }
                v47 = v12 - 1;
                __dmb(0xBu);
                do
                  v48 = __ldrex(v47);
                while ( __strex(v48 - 1, v47) );
                if ( (v48 & 2) != 0 && (v48 & 4) == 0 )
                  ExfTryToWakePushLock(v12 - 1);
                KeAbPostRelease((unsigned int)(v12 - 1));
                if ( v46 <= 0 )
                  return -1073740030;
                __dmb(0xBu);
                v49 = v12 - 3;
                do
                {
                  v50 = __ldrex(v49);
                  v51 = v50 - v46;
                }
                while ( __strex(v51, v49) );
                __dmb(0xBu);
                if ( v51 > 0 )
                  return -1073740030;
                if ( v51 )
                  KeBugCheckEx(24, 0, (int)v12, 40, v51);
              }
              else
              {
                if ( AlpcpMessageLogEnabled )
                  AlpcpEnterStateChangeEventMessageLog(v12);
                v40 = 0;
                if ( (*(_BYTE *)(v12 - 4) & 1) != 0 )
                {
                  v40 = 0x10000 - *((__int16 *)v12 - 7);
                  *((_BYTE *)v12 - 16) &= 0xFEu;
                  *((_WORD *)v12 - 7) = 0;
                }
                v41 = v12 - 1;
                __dmb(0xBu);
                do
                  v42 = __ldrex(v41);
                while ( __strex(v42 - 1, v41) );
                if ( (v42 & 2) != 0 && (v42 & 4) == 0 )
                  ExfTryToWakePushLock(v12 - 1);
                KeAbPostRelease((unsigned int)(v12 - 1));
                if ( v40 <= 0 )
                  return -1073740030;
                __dmb(0xBu);
                v43 = v12 - 3;
                do
                {
                  v44 = __ldrex(v43);
                  v45 = v44 - v40;
                }
                while ( __strex(v45, v43) );
                __dmb(0xBu);
                if ( v45 > 0 )
                  return -1073740030;
                if ( v45 )
                  KeBugCheckEx(24, 0, (int)v12, 40, v45);
              }
LABEL_98:
              AlpcpDestroyBlob(v12);
              return -1073740030;
            }
LABEL_80:
            if ( !v14 )
              KeBugCheckEx(24, 0, (int)v12, 32, v13);
          }
LABEL_74:
          __dmb(0xBu);
          do
            v39 = __ldrex(v9);
          while ( __strex(v39 + 1, v9) );
          __dmb(0xBu);
          __dmb(0xFu);
          if ( *(_DWORD *)(v7 + 32) )
            ExfUnblockPushLock(v7 + 32, 0);
          return -1073740030;
        }
      }
LABEL_49:
      ExHandleLogBadReference(v7, a2 & 0x3FFFFFF, v8);
    }
    return -1073740030;
  }
  if ( !a1 )
    return -1073740030;
  v26 = *(_DWORD *)(a1 + 8);
  if ( !v26 )
    return -1073741072;
  v27 = AlpcReferenceBlobByHandle((_DWORD *)(v26 + 20), a2 & 0x7FFFFFFF, AlpcReserveType);
  v28 = v27;
  if ( !v27 )
    return -1073741072;
  if ( !AlpcpOpenReserve(v27) )
    return sub_7F94A0();
  v29 = *(_DWORD **)(v28 + 12);
  v30 = (unsigned __int8 *)(v29 - 1);
  v31 = KeAbPreAcquire((unsigned int)(v29 - 1), 0, 0);
  v32 = v31;
  do
    v33 = __ldrex(v30);
  while ( __strex(v33 | 1, v30) );
  __dmb(0xBu);
  if ( (v33 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v29 - 1, v31, (unsigned int)(v29 - 1));
  if ( v32 )
    *(_BYTE *)(v32 + 14) |= 1u;
  *((_BYTE *)v29 - 16) |= 1u;
  __dmb(0xBu);
  v34 = v29 - 3;
  do
  {
    v35 = __ldrex(v34);
    v36 = v35 + 0x10000;
  }
  while ( __strex(v36, v34) );
  __dmb(0xBu);
  if ( v36 <= 0 )
    KeBugCheckEx(24, 0, (int)v29, 38, v36);
  v29[5] |= 0x2000u;
  v29[34] &= 0x7FFFFFFFu;
  do
  {
    __dmb(0xBu);
    do
    {
      v37 = __ldrex(AlpcpNextCallbackId);
      v38 = v37 + 1;
    }
    while ( __strex(v38, AlpcpNextCallbackId) );
    __dmb(0xBu);
  }
  while ( !v38 );
  v29[35] = v38;
  *v5 = v29;
  return 0;
}
