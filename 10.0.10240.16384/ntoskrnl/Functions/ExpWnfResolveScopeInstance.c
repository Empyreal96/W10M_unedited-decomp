// ExpWnfResolveScopeInstance 
 
int __fastcall ExpWnfResolveScopeInstance(_DWORD *a1, int a2, int a3, int a4, int a5, char a6)
{
  int v9; // r1
  unsigned int *v10; // r5
  int v11; // r2
  unsigned int v12; // r9
  BOOL v13; // r3
  unsigned int *v14; // r3
  _DWORD *v15; // r6
  char *v16; // r5
  int v17; // r4
  int v18; // r3
  int v19; // r7
  int v20; // r0
  unsigned int v21; // r0
  unsigned int v22; // r2
  unsigned int v24; // r1
  unsigned int *v25; // r1
  unsigned int v26; // r2
  int v27; // r3
  unsigned int *v28; // r5
  _DWORD **v29; // r10
  int v30; // r0
  int v31; // r4
  unsigned int v32; // r2
  _DWORD *v33; // r0
  unsigned int *v34; // r0
  unsigned int v35; // r4
  unsigned int v36; // r1
  int v37; // r4
  unsigned int v38; // r2
  unsigned int v39; // r2
  int v40; // r0
  int v41; // r6
  unsigned int v42; // r4
  _DWORD *v43; // r0
  unsigned int *v44; // r4
  unsigned int v45; // r0
  unsigned int v46; // r1
  unsigned int v47; // r1
  unsigned int *v48; // r0
  unsigned int v49; // r4
  unsigned int v50; // r1
  _DWORD *v51; // r1
  _DWORD *v52; // r2
  unsigned int *v53; // r0
  unsigned int v54; // r4
  unsigned int v55; // r1
  int v56; // [sp+8h] [bp-48h] BYREF
  int v57; // [sp+Ch] [bp-44h] BYREF
  unsigned int *v58; // [sp+10h] [bp-40h] BYREF
  _DWORD *v59; // [sp+14h] [bp-3Ch] BYREF
  int v60; // [sp+18h] [bp-38h] BYREF
  unsigned int *v61; // [sp+1Ch] [bp-34h]
  int v62; // [sp+20h] [bp-30h]
  unsigned int v63; // [sp+24h] [bp-2Ch] BYREF
  char v64[4]; // [sp+28h] [bp-28h] BYREF
  _DWORD *v65; // [sp+2Ch] [bp-24h]

  v65 = a1;
  v62 = 0;
  if ( (a6 & 1) != 0 )
    v9 = 0;
  else
    v9 = -1;
  PsGetMonitorContextServerSilo(ExpWnfSiloMonitor, v9, &v58);
  v10 = v58;
  PsDereferenceMonitorContextServerSilo((int)v58);
  if ( !*v10 )
  {
    v17 = ExpWnfAllocateScopeMap(&v63);
    if ( v17 < 0 )
      return v17;
    __dmb(0xBu);
    v21 = v63;
    do
      v22 = __ldrex(v10);
    while ( !v22 && __strex(v21, v10) );
    __dmb(0xBu);
    if ( v22 )
      return sub_7C43E8(v21);
  }
  v11 = *(_DWORD *)(a2 + 724);
  v60 = v11;
  __dmb(0xBu);
  if ( !v11 )
  {
    v17 = ExpWnfCreateProcessContext(a2, &v60);
    if ( v17 < 0 )
      return v17;
    v11 = v60;
  }
  v12 = a5;
  v13 = !a3 && !a5;
  v56 = v13;
  if ( a4 )
  {
    v14 = (unsigned int *)(v11 + 4 * (a4 + 3));
  }
  else
  {
    v14 = (unsigned int *)(*v58 + 4);
    v56 = 1;
  }
  v15 = (_DWORD *)*v14;
  v61 = v14;
  v59 = v15;
  __dmb(0xBu);
  if ( v56 && v15 )
    goto LABEL_112;
  if ( a5 )
  {
    if ( a4 )
    {
      if ( a4 == 1 || a4 != 2 )
        v19 = 4;
      else
        v19 = RtlLengthSid(a5);
    }
    else
    {
      v19 = 0;
    }
    v18 = 0;
    v57 = 0;
    goto LABEL_16;
  }
  v57 = 4;
  v16 = v64;
  v17 = ExpWnfGetCurrentScopeInstance(a2, a3, a4, v64, &v57, &v56);
  if ( v17 != -1073741789 )
  {
LABEL_13:
    if ( v17 < 0 )
      goto LABEL_35;
    v18 = v56;
    v19 = v57;
    v57 = v56;
    if ( v19 )
      v12 = (unsigned int)v16;
LABEL_16:
    if ( !v15 || !v18 )
    {
      v27 = *v58 + 12 * a4;
      v28 = (unsigned int *)(v27 + 8);
      v29 = (_DWORD **)(v27 + 12);
      v30 = KeAbPreAcquire(v27 + 8, 0, 0);
      v31 = v30;
      do
        v32 = __ldrex(v28);
      while ( !v32 && __strex(0x11u, v28) );
      __dmb(0xBu);
      if ( v32 )
        ExfAcquirePushLockSharedEx(v28, v30, (unsigned int)v28);
      if ( v31 )
        *(_BYTE *)(v31 + 14) |= 1u;
      v33 = ExpWnfFindScopeInstance(v29, v12, v19);
      v15 = v33;
      if ( v33 )
      {
        v34 = v33 + 1;
        __pld(v15 + 1);
        v35 = v15[1] & 0xFFFFFFFE;
        do
          v36 = __ldrex(v34);
        while ( v36 == v35 && __strex(v35 + 2, v34) );
        __dmb(0xBu);
        if ( v36 == v35 )
          v37 = 1;
        else
          v37 = ExfAcquireRundownProtection(v34);
        __dmb(0xBu);
        do
          v38 = __ldrex(v28);
        while ( v38 == 17 && __strex(0, v28) );
        if ( v38 != 17 )
          ExfReleasePushLockShared(v28);
        KeAbPostRelease((unsigned int)v28);
      }
      else
      {
        __dmb(0xBu);
        do
          v39 = __ldrex(v28);
        while ( v39 == 17 && __strex(0, v28) );
        if ( v39 != 17 )
          ExfReleasePushLockShared(v28);
        KeAbPostRelease((unsigned int)v28);
        v17 = ExpWnfAllocateScopeInstance(&v59, a4, v12, v19);
        if ( v17 < 0 )
          goto LABEL_35;
        v40 = KeAbPreAcquire((unsigned int)v28, 0, 0);
        v41 = v40;
        do
          v42 = __ldrex((unsigned __int8 *)v28);
        while ( __strex(v42 | 1, (unsigned __int8 *)v28) );
        __dmb(0xBu);
        if ( (v42 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v28, v40, (unsigned int)v28);
        if ( v41 )
          *(_BYTE *)(v41 + 14) |= 1u;
        v43 = ExpWnfFindScopeInstance(v29, v12, v19);
        v15 = v43;
        if ( !v43 )
        {
          v15 = v59;
          v48 = v59 + 1;
          __pld(v59 + 1);
          v49 = *v48 & 0xFFFFFFFE;
          do
            v50 = __ldrex(v48);
          while ( v50 == v49 && __strex(v49 + 2, v48) );
          __dmb(0xBu);
          if ( v50 != v49 )
            ExfAcquireRundownProtection(v48);
          v51 = *v29;
          v52 = v15 + 5;
          v15[5] = *v29;
          v15[6] = v29;
          if ( (_DWORD **)v51[1] != v29 )
            __fastfail(3u);
          v51[1] = v52;
          *v29 = v52;
          __dmb(0xBu);
          do
            v24 = __ldrex(v28);
          while ( __strex(v24 - 1, v28) );
          if ( (v24 & 2) != 0 && (v24 & 4) == 0 )
            ExfTryToWakePushLock(v28);
          KeAbPostRelease((unsigned int)v28);
          if ( v57 )
          {
            __dmb(0xBu);
            v25 = v61;
            do
              v26 = __ldrex(v25);
            while ( !v26 && __strex((unsigned int)v15, v25) );
            __dmb(0xBu);
          }
          goto LABEL_34;
        }
        v44 = v43 + 1;
        __pld(v43 + 1);
        v45 = v43[1] & 0xFFFFFFFE;
        do
          v46 = __ldrex(v44);
        while ( v46 == v45 && __strex(v45 + 2, v44) );
        __dmb(0xBu);
        if ( v46 == v45 )
          v37 = 1;
        else
          v37 = ExfAcquireRundownProtection(v15 + 1);
        __dmb(0xBu);
        do
          v47 = __ldrex(v28);
        while ( __strex(v47 - 1, v28) );
        if ( (v47 & 2) != 0 && (v47 & 4) == 0 )
          ExfTryToWakePushLock(v28);
        KeAbPostRelease((unsigned int)v28);
        ExpWnfFreeScopeInstance(v59, 0);
      }
      if ( !v37 )
      {
LABEL_39:
        v17 = -1073741772;
LABEL_35:
        if ( v62 )
          ExFreePoolWithTag(v62);
        return v17;
      }
LABEL_34:
      v17 = 0;
      *v65 = v15;
      goto LABEL_35;
    }
LABEL_112:
    v53 = v15 + 1;
    __pld(v15 + 1);
    v54 = v15[1] & 0xFFFFFFFE;
    do
      v55 = __ldrex(v53);
    while ( v55 == v54 && __strex(v54 + 2, v53) );
    __dmb(0xBu);
    if ( v55 != v54 && !ExfAcquireRundownProtection(v53) )
      goto LABEL_39;
    goto LABEL_34;
  }
  v20 = ExAllocatePoolWithTag(1, v57, 543583831);
  v62 = v20;
  if ( v20 )
  {
    v16 = (char *)v20;
    v17 = ExpWnfGetCurrentScopeInstance(a2, a3, a4, v20, &v57, &v56);
    goto LABEL_13;
  }
  return -1073741670;
}
