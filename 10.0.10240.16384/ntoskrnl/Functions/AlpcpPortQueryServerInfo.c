// AlpcpPortQueryServerInfo 
 
int __fastcall AlpcpPortQueryServerInfo(int a1, int a2, unsigned int a3, unsigned int *a4, char a5)
{
  int v6; // r4
  int v7; // r0
  unsigned int v8; // r10
  int v9; // r6
  int v10; // r0
  int *v11; // r9
  int *v12; // r8
  int v13; // r6
  unsigned __int8 *v14; // r0
  unsigned int v15; // r2
  unsigned int *v16; // r1
  unsigned int v17; // r0
  int v18; // r0
  int v19; // r3
  int *v20; // r3
  int v21; // r6
  int *v22; // r1
  unsigned int *v23; // r0
  unsigned int v24; // r2
  char v25; // r2
  unsigned int *v26; // r6
  unsigned int v27; // r1
  unsigned int *v28; // r2
  unsigned int v29; // r0
  int v30; // r0
  int *v31; // r8
  int v32; // r9
  int v33; // r3
  int v34; // r6
  unsigned int *v35; // r8
  unsigned int v36; // r2
  int v37; // r8
  unsigned int *v38; // r0
  unsigned int v39; // r2
  int v40; // r8
  unsigned int *v41; // r1
  unsigned int v42; // r2
  int v43; // r3
  char v44; // r2
  unsigned int *v45; // r8
  unsigned int v46; // r1
  int *v47; // r3
  unsigned int *v48; // r2
  unsigned int v49; // r0
  int v50; // r0
  unsigned int v51; // r6
  unsigned int v53; // [sp+8h] [bp-50h] BYREF
  unsigned int v54; // [sp+Ch] [bp-4Ch] BYREF
  int *v55; // [sp+10h] [bp-48h]
  int v56; // [sp+14h] [bp-44h] BYREF
  unsigned int v57; // [sp+18h] [bp-40h]
  unsigned int v58; // [sp+1Ch] [bp-3Ch]
  int v59; // [sp+24h] [bp-34h]
  int *v60; // [sp+28h] [bp-30h] BYREF
  int v61; // [sp+2Ch] [bp-2Ch]
  int v62; // [sp+30h] [bp-28h]
  unsigned int *v63; // [sp+34h] [bp-24h]
  int v64; // [sp+38h] [bp-20h]
  int varg_r0; // [sp+60h] [bp+8h]
  int varg_r1; // [sp+64h] [bp+Ch]
  unsigned int varg_r2; // [sp+68h] [bp+10h]
  unsigned int *varg_r3; // [sp+6Ch] [bp+14h]

  varg_r0 = a1;
  v63 = a4;
  varg_r3 = a4;
  v58 = a3;
  varg_r2 = a3;
  varg_r1 = a2;
  if ( a1 || a3 < 4 )
    return -1073741811;
  if ( a5 )
  {
    if ( (a2 & 3) != 0 )
      ExRaiseDatatypeMisalignment(0);
    v7 = *(_DWORD *)a2;
    v59 = *(_DWORD *)a2;
  }
  else
  {
    v7 = *(_DWORD *)a2;
  }
  v6 = ObReferenceObjectByHandle(v7, 64, PsThreadType, a5, (int)&v56, 0);
  if ( v6 >= 0 )
  {
    v8 = 0;
    v54 = 0;
    v57 = 0;
    v53 = 0;
    v61 = 0;
    v62 = 0;
    v9 = v56;
    v10 = AlpcpReferenceMessageByWaitingThread(v56, &v60);
    v6 = v10;
    if ( v10 == -1073741275 )
    {
      v11 = 0;
      v6 = 0;
LABEL_97:
      if ( v11 )
      {
        if ( AlpcpMessageLogEnabled )
          AlpcpEnterStateChangeEventMessageLog(v11);
        v60 = 0;
        v44 = *((_BYTE *)v11 - 16);
        if ( (v44 & 1) != 0 )
        {
          v60 = (int *)(0x10000 - *((__int16 *)v11 - 7));
          *((_BYTE *)v11 - 16) = v44 & 0xFE;
          *((_WORD *)v11 - 7) = 0;
        }
        v45 = (unsigned int *)(v11 - 1);
        __dmb(0xBu);
        do
          v46 = __ldrex(v45);
        while ( __strex(v46 - 1, v45) );
        if ( (v46 & 2) != 0 && (v46 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)v11 - 1);
        KeAbPostRelease((unsigned int)(v11 - 1));
        v47 = v60;
        if ( (int)v60 > 0 )
        {
          __dmb(0xBu);
          v48 = (unsigned int *)(v11 - 3);
          do
          {
            v49 = __ldrex(v48);
            v50 = v49 - (_DWORD)v47;
          }
          while ( __strex(v50, v48) );
          __dmb(0xBu);
          if ( v50 <= 0 )
          {
            if ( v50 )
              KeBugCheckEx(24, 0, (int)v11, 40, v50);
            AlpcpDestroyBlob((int)v11);
          }
        }
      }
      ObfDereferenceObject(v56);
      v51 = 16;
      if ( v8 )
      {
        v51 = *(unsigned __int16 *)(v8 + 2) + 16;
      }
      else if ( v6 == -1073741820 )
      {
        v51 = v57 + 8;
      }
      if ( v58 < v51 )
        v6 = -1073741820;
      if ( v6 >= 0 )
      {
        *(_BYTE *)a2 = v61;
        *(_DWORD *)(a2 + 4) = v62;
        if ( v8 )
        {
          *(_WORD *)(a2 + 8) = *(_WORD *)v8;
          *(_WORD *)(a2 + 10) = *(_WORD *)(v8 + 2);
          *(_DWORD *)(a2 + 12) = a2 + 16;
          memmove(a2 + 16, *(_DWORD *)(v8 + 4), *(unsigned __int16 *)(v8 + 2));
        }
        else
        {
          *(_WORD *)(a2 + 10) = 0;
          *(_WORD *)(a2 + 8) = 0;
          *(_DWORD *)(a2 + 12) = 0;
        }
      }
      if ( v63 && (v6 >= 0 || v6 == -1073741820) )
        *v63 = v51;
      if ( v8 )
        ExFreePoolWithTag(v8);
      return v6;
    }
    if ( v10 < 0 )
    {
      ObfDereferenceObject(v9);
      return v6;
    }
    v11 = v60;
    v12 = v60 - 6;
    v13 = KeAbPreAcquire((unsigned int)(v60 - 1), 0, 0);
    v14 = (unsigned __int8 *)(v11 - 1);
    do
      v15 = __ldrex(v14);
    while ( __strex(v15 | 1, v14) );
    __dmb(0xBu);
    if ( (v15 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v14, v13, (unsigned int)(v12 + 5));
    if ( v13 )
      *(_BYTE *)(v13 + 14) |= 1u;
    *((_BYTE *)v11 - 16) |= 1u;
    __dmb(0xBu);
    v16 = (unsigned int *)(v11 - 3);
    do
    {
      v17 = __ldrex(v16);
      v18 = v17 + 0x10000;
    }
    while ( __strex(v18, v16) );
    __dmb(0xBu);
    if ( v18 <= 0 )
      KeBugCheckEx(24, 0, (int)v11, 38, v18);
    --*((_WORD *)v11 - 7);
    if ( v11 != *(int **)(v56 + 976) )
      goto LABEL_97;
    v19 = v11[3];
    v64 = v19;
    if ( !v19 )
      goto LABEL_97;
    v20 = *(int **)(v19 + 8);
    v60 = v20;
    if ( !v20 )
      goto LABEL_97;
    v21 = KeAbPreAcquire((unsigned int)(v20 - 1), 0, 0);
    v22 = v60;
    v23 = (unsigned int *)(v60 - 1);
    do
      v24 = __ldrex(v23);
    while ( !v24 && __strex(0x11u, v23) );
    __dmb(0xBu);
    if ( v24 )
      ExfAcquirePushLockSharedEx(v23, v21, (unsigned int)(v22 - 1));
    if ( v21 )
      *(_BYTE *)(v21 + 14) |= 1u;
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v11);
    v55 = 0;
    v25 = *((_BYTE *)v11 - 16);
    if ( (v25 & 1) != 0 )
    {
      v55 = (int *)(0x10000 - *((__int16 *)v11 - 7));
      *((_BYTE *)v11 - 16) = v25 & 0xFE;
      *((_WORD *)v11 - 7) = 0;
    }
    v26 = (unsigned int *)(v11 - 1);
    __dmb(0xBu);
    do
      v27 = __ldrex(v26);
    while ( __strex(v27 - 1, v26) );
    if ( (v27 & 2) != 0 && (v27 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v12 + 5);
    KeAbPostRelease((unsigned int)(v12 + 5));
    if ( (int)v55 > 0 )
    {
      __dmb(0xBu);
      v28 = (unsigned int *)(v11 - 3);
      do
      {
        v29 = __ldrex(v28);
        v30 = v29 - (_DWORD)v55;
      }
      while ( __strex(v30, v28) );
      __dmb(0xBu);
      if ( v30 <= 0 )
      {
        if ( v30 )
          KeBugCheckEx(24, 0, (int)v11, 40, v30);
        AlpcpDestroyBlob((int)v11);
      }
    }
    v55 = 0;
    v31 = v60;
    v32 = *v60;
    if ( !*v60 )
      goto LABEL_61;
    if ( !ObReferenceObjectSafe(*v60) )
      v32 = 0;
    if ( !v32
      || ((v33 = (*(_DWORD *)(v64 + 244) >> 1) & 3, v33 == 1) || v33 == 2 ? (v34 = *v31) : (v34 = v31[2]),
          v34 && v34 != v32 && !ObReferenceObjectSafe(v34)) )
    {
LABEL_61:
      v34 = 0;
    }
    v35 = (unsigned int *)(v31 - 1);
    __dmb(0xBu);
    do
      v36 = __ldrex(v35);
    while ( v36 == 17 && __strex(0, v35) );
    if ( v36 != 17 )
      ExfReleasePushLockShared(v35);
    KeAbPostRelease((unsigned int)v35);
    if ( v34 )
    {
      if ( !v32 )
      {
LABEL_93:
        if ( v34 && v34 != v32 )
          ObfDereferenceObject(v34);
        v11 = v55;
        goto LABEL_97;
      }
      v37 = KeAbPreAcquire(v34 + 208, 0, 0);
      v38 = (unsigned int *)(v34 + 208);
      do
        v39 = __ldrex(v38);
      while ( !v39 && __strex(0x11u, v38) );
      __dmb(0xBu);
      if ( v39 )
        ExfAcquirePushLockSharedEx(v38, v37, v34 + 208);
      if ( v37 )
        *(_BYTE *)(v37 + 14) |= 1u;
      v40 = *(_DWORD *)(v34 + 12);
      if ( (v40 & 1) != 0 )
        v40 = 0;
      if ( v40 )
        ObfReferenceObjectWithTag(v40);
      __dmb(0xBu);
      v41 = (unsigned int *)(v34 + 208);
      do
        v42 = __ldrex(v41);
      while ( v42 == 17 && __strex(0, v41) );
      if ( v42 != 17 )
      {
        ExfReleasePushLockShared((_DWORD *)(v34 + 208));
        v41 = (unsigned int *)(v34 + 208);
      }
      KeAbPostRelease((unsigned int)v41);
      if ( v40 )
      {
        v62 = *(_DWORD *)(v40 + 176);
        ObfDereferenceObjectWithTag(v40);
        v43 = v58;
        if ( v58 > 8 )
        {
          v43 = v58 - 8;
          v53 = v58 - 8;
        }
        v6 = AlpcpGetPortNameInformation(v32, &v54, (int *)&v53, v43);
        v8 = v54;
        if ( v6 >= 0 )
          v61 = 1;
        v57 = v53;
      }
    }
    if ( v32 )
      ObfDereferenceObject(v32);
    goto LABEL_93;
  }
  return v6;
}
