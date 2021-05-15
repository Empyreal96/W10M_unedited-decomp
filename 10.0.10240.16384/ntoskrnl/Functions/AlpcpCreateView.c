// AlpcpCreateView 
 
int __fastcall AlpcpCreateView(_DWORD *a1, _DWORD *a2, int *a3)
{
  int v3; // r10
  int v5; // r7
  unsigned __int8 *v6; // r8
  int v8; // r0
  unsigned int v9; // r4
  int v11; // r10
  unsigned int v12; // r2
  _BYTE *v13; // r0
  int v14; // r4
  int v15; // r0
  int v16; // r5
  int v17; // r5
  bool v18; // zf
  unsigned int *v19; // lr
  int v20; // r0
  int v21; // r1
  __int64 v22; // r2
  unsigned __int8 *v23; // r8
  _DWORD *v24; // r10
  int v25; // r0
  int v26; // r5
  unsigned int v27; // r2
  _DWORD *v28; // r1
  unsigned int v29; // r1
  int v30; // r5
  bool v31; // zf
  unsigned int *v32; // r6
  int v33; // r0
  int v34; // r1
  unsigned int *v35; // r8
  int v36; // r6
  unsigned int *v37; // r4
  unsigned int v38; // r1
  unsigned int *v39; // r2
  unsigned int v40; // r0
  int v41; // r0
  unsigned int *v42; // r1
  unsigned int v43; // r0
  int v44; // r0
  int v45; // r0
  int v46; // r4
  unsigned int v47; // r2
  unsigned int v48; // r2
  unsigned int *v49; // r2
  unsigned int v50; // r1
  int v51; // r1
  int v52; // r9
  unsigned __int8 *v53; // r5
  int v54; // r0
  int v55; // r8
  unsigned int v56; // r2
  __int64 v57; // r2
  unsigned int v58; // r1
  _DWORD *v59; // [sp+20h] [bp-40h]
  int v60; // [sp+24h] [bp-3Ch] BYREF
  int v61; // [sp+28h] [bp-38h] BYREF
  int v62; // [sp+2Ch] [bp-34h]
  int *v63; // [sp+30h] [bp-30h]
  unsigned int *v64; // [sp+34h] [bp-2Ch]
  int v65[10]; // [sp+38h] [bp-28h] BYREF

  v3 = a1[2];
  v5 = v3 - 24;
  v6 = (unsigned __int8 *)(v3 - 4);
  v63 = a3;
  *a3 = 0;
  v59 = (_DWORD *)v3;
  v8 = KeAbPreAcquire(v3 - 4, 0, 0);
  do
    v9 = __ldrex(v6);
  while ( __strex(v9 | 1, v6) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    return sub_7F618C(v8);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  *(_BYTE *)(v3 - 16) |= 1u;
  __dmb(0xBu);
  v42 = (unsigned int *)(v3 - 12);
  do
  {
    v43 = __ldrex(v42);
    v44 = v43 + 0x10000;
  }
  while ( __strex(v44, v42) );
  __dmb(0xBu);
  if ( v44 <= 0 )
    KeBugCheckEx(24, 0, v3, 38, v44);
  v35 = a2 + 52;
  v64 = a2 + 52;
  v45 = KeAbPreAcquire((unsigned int)(a2 + 52), 0, 0);
  v46 = v45;
  do
    v47 = __ldrex(v35);
  while ( !v47 && __strex(0x11u, v35) );
  __dmb(0xBu);
  if ( v47 )
    ExfAcquirePushLockSharedEx(a2 + 52, v45, (unsigned int)(a2 + 52));
  if ( v46 )
    *(_BYTE *)(v46 + 14) |= 1u;
  if ( (a2[61] & 0x20) != 0 )
  {
    v16 = -1073741769;
  }
  else
  {
    v11 = a2[3];
    v12 = a2[46];
    v62 = v11;
    if ( v12 && v12 < a1[5] )
    {
      v16 = -1073741756;
    }
    else if ( (a1[6] & 1) != 0 && (a1[7] >= 2u || a1[11]) )
    {
      v16 = -1073741790;
    }
    else
    {
      v13 = (_BYTE *)AlpcpAllocateBlob(AlpcViewType, 52, 0);
      v14 = (int)v13;
      if ( v13 )
      {
        memset(v13, 0, 52);
        v65[0] = a1[3];
        v65[1] = 0;
        v61 = a1[5];
        v60 = 0;
        if ( (v59[6] & 2) != 0 )
          v15 = MiMapViewOfSection(*v59, v11, &v60, 0, 0, v65, &v61, 2, 0, 4, 2, v14 + 28);
        else
          v15 = MmMapViewOfSection(*(_DWORD *)a1[2], v11, &v60, 0, 0, v65, &v61, 2, 0, 4);
        v16 = v15;
        if ( v15 >= 0 )
        {
          *(_DWORD *)(v14 + 20) = v60;
          *(_DWORD *)(v14 + 24) = v61;
          *(_DWORD *)(v14 + 36) |= 1u;
          ObfReferenceObjectWithTag(v11);
          *(_DWORD *)(v14 + 16) = v11;
          ObfReferenceObject((int)a2);
          *(_DWORD *)(v14 + 12) = a2;
          v17 = *(a1 - 3);
          v18 = v17 == 0;
          if ( v17 <= 0 )
          {
LABEL_85:
            if ( !v18 )
              KeBugCheckEx(24, 0, (int)a1, 32, v17);
          }
          else
          {
            v19 = a1 - 3;
            while ( 1 )
            {
              v20 = v17;
              __dmb(0xBu);
              do
                v21 = __ldrex(v19);
              while ( v21 == v17 && __strex(v17 + 1, v19) );
              v17 = v21;
              __dmb(0xBu);
              if ( v21 == v20 )
                break;
              if ( v21 <= 0 )
              {
                v18 = v21 == 0;
                goto LABEL_85;
              }
            }
          }
          LODWORD(v22) = a1 + 8;
          *(_DWORD *)(v14 + 8) = a1;
          HIDWORD(v22) = a1[9];
          *(_QWORD *)v14 = v22;
          v23 = (unsigned __int8 *)(a2 + 49);
          *(_DWORD *)a1[9] = v14;
          a1[9] = v14;
          v24 = (_DWORD *)(v14 - 24);
          ++a1[7];
          v25 = KeAbPreAcquire((unsigned int)(a2 + 49), 0, 0);
          v26 = v25;
          do
            v27 = __ldrex(v23);
          while ( __strex(v27 | 1, v23) );
          __dmb(0xBu);
          if ( (v27 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(a2 + 49, v25, (unsigned int)(a2 + 49));
          if ( v26 )
            *(_BYTE *)(v26 + 14) |= 1u;
          v28 = (_DWORD *)a2[51];
          *v24 = a2 + 50;
          *(_DWORD *)(v14 - 20) = v28;
          if ( (_DWORD *)*v28 != a2 + 50 )
            __fastfail(3u);
          *v28 = v24;
          a2[51] = v24;
          __dmb(0xBu);
          do
            v29 = __ldrex((unsigned int *)v23);
          while ( __strex(v29 - 1, (unsigned int *)v23) );
          if ( (v29 & 2) != 0 && (v29 & 4) == 0 )
            ExfTryToWakePushLock(a2 + 49);
          KeAbPostRelease((unsigned int)(a2 + 49));
          v52 = v62;
          v53 = (unsigned __int8 *)(v62 + 656);
          v54 = KeAbPreAcquire(v62 + 656, 0, 0);
          v55 = v54;
          do
            v56 = __ldrex(v53);
          while ( __strex(v56 | 1, v53) );
          __dmb(0xBu);
          if ( (v56 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(v53, v54, (unsigned int)v53);
          if ( v55 )
            *(_BYTE *)(v55 + 14) |= 1u;
          LODWORD(v57) = v52 + 660;
          HIDWORD(v57) = *(_DWORD *)(v52 + 664);
          *(_QWORD *)(v14 + 44) = v57;
          **(_DWORD **)(v52 + 664) = v14 + 44;
          *(_DWORD *)(v52 + 664) = v14 + 44;
          __dmb(0xBu);
          do
            v58 = __ldrex((unsigned int *)v53);
          while ( __strex(v58 - 1, (unsigned int *)v53) );
          if ( (v58 & 2) != 0 && (v58 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)v53);
          KeAbPostRelease((unsigned int)v53);
          if ( (a1[6] & 1) != 0 )
            a1[11] = v14;
          v30 = *(_DWORD *)(v14 - 12);
          v31 = v30 == 0;
          if ( v30 <= 0 )
          {
LABEL_103:
            if ( !v31 )
              KeBugCheckEx(24, 0, v14, 32, v30);
          }
          else
          {
            v32 = (unsigned int *)(v14 - 12);
            while ( 1 )
            {
              v33 = v30;
              __dmb(0xBu);
              do
                v34 = __ldrex(v32);
              while ( v34 == v30 && __strex(v30 + 1, v32) );
              v30 = v34;
              __dmb(0xBu);
              if ( v34 == v33 )
                break;
              if ( v34 <= 0 )
              {
                v31 = v34 == 0;
                goto LABEL_103;
              }
            }
          }
          v35 = v64;
          v3 = (int)v59;
          v16 = 0;
          *v63 = v14;
          goto LABEL_70;
        }
        __dmb(0xBu);
        v49 = (unsigned int *)(v14 - 12);
        do
        {
          v50 = __ldrex(v49);
          v51 = v50 - 1;
        }
        while ( __strex(v51, v49) );
        __dmb(0xBu);
        if ( v51 <= 0 )
        {
          if ( v51 )
            KeBugCheckEx(24, 0, v14, 33, v51);
          AlpcpDestroyBlob(v14);
        }
      }
      else
      {
        v16 = -1073741670;
      }
    }
    v3 = (int)v59;
  }
LABEL_70:
  __dmb(0xBu);
  do
    v48 = __ldrex(v35);
  while ( v48 == 17 && __strex(0, v35) );
  if ( v48 != 17 )
    ExfReleasePushLockShared(v35);
  KeAbPostRelease((unsigned int)v35);
  v36 = 0;
  if ( (*(_BYTE *)(v5 + 8) & 1) != 0 )
  {
    v36 = 0x10000 - *(__int16 *)(v5 + 10);
    *(_BYTE *)(v5 + 8) &= 0xFEu;
    *(_WORD *)(v5 + 10) = 0;
  }
  v37 = (unsigned int *)(v5 + 20);
  __dmb(0xBu);
  do
    v38 = __ldrex(v37);
  while ( __strex(v38 - 1, v37) );
  if ( (v38 & 2) != 0 && (v38 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v5 + 20));
  KeAbPostRelease(v5 + 20);
  if ( v36 > 0 )
  {
    __dmb(0xBu);
    v39 = (unsigned int *)(v5 + 12);
    do
    {
      v40 = __ldrex(v39);
      v41 = v40 - v36;
    }
    while ( __strex(v41, v39) );
    __dmb(0xBu);
    if ( v41 <= 0 )
    {
      if ( v41 )
        KeBugCheckEx(24, 0, v3, 40, v41);
      AlpcpDestroyBlob(v3);
    }
  }
  return v16;
}
