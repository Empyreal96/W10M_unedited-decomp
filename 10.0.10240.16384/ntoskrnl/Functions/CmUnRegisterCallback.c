// CmUnRegisterCallback 
 
int __fastcall CmUnRegisterCallback(int a1, int a2)
{
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r5
  unsigned int v5; // r2
  int v6; // r8
  int v7; // r6
  unsigned int *v8; // r0
  unsigned int v9; // r5
  unsigned int v10; // r3
  unsigned int *v11; // r6
  unsigned int v12; // r1
  int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r2
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  unsigned int v19; // r3
  unsigned int v20; // r2
  int v21; // r0
  int v22; // r6
  unsigned int v23; // r2
  int v24; // r1
  _DWORD *v25; // r2
  int v26; // r1
  unsigned int v27; // r0
  unsigned int v28; // r2
  unsigned int v29; // r1
  unsigned int **v30; // r2
  unsigned int v31; // r0
  int v32; // r0
  unsigned int v33; // r1
  __int16 v34; // r3
  unsigned int v35; // r2
  int v36; // r0
  int v37; // r6
  unsigned int v38; // r2
  unsigned int *i; // r6
  unsigned int *v40; // r8
  unsigned int v41; // r0
  unsigned int *v42; // r1
  unsigned int v43; // r1
  unsigned int **v44; // r2
  int **v45; // r1
  int v46; // r1
  unsigned int v47; // r0
  unsigned int v48; // r2
  int v49; // r0
  unsigned int v50; // r1
  __int16 v51; // r3
  unsigned int v52; // r10
  int *v53; // r1
  int v54; // r0
  unsigned int v55; // r6
  unsigned int v56; // r2
  int v57; // r0
  int v58; // r6
  unsigned int v59; // r2
  unsigned int v60; // r6
  int v61; // r1
  unsigned int v62; // r0
  unsigned int v63; // r2
  int v64; // r0
  unsigned int v65; // r1
  __int16 v66; // r3
  unsigned int v67; // r1
  unsigned int v68; // r1
  int v69; // r9
  _DWORD *v70; // r4
  unsigned int v71; // r0
  unsigned int v72; // r0
  int v73; // r1
  unsigned int v74; // r0
  unsigned int v75; // r2
  int v76; // r0
  unsigned int v77; // r1
  __int16 v78; // r3
  unsigned int v80; // [sp+10h] [bp-40h] BYREF
  int v81; // [sp+14h] [bp-3Ch] BYREF
  unsigned int v82[2]; // [sp+18h] [bp-38h] BYREF
  int *v83; // [sp+20h] [bp-30h] BYREF
  int **v84; // [sp+24h] [bp-2Ch]
  int v85; // [sp+28h] [bp-28h] BYREF
  int v86; // [sp+2Ch] [bp-24h]
  int v87; // [sp+30h] [bp-20h]
  int anonymous7; // [sp+58h] [bp+8h]
  int anonymous8; // [sp+5Ch] [bp+Ch]

  anonymous7 = a1;
  anonymous8 = a2;
  v85 = 0;
  v86 = 0;
  v87 = 0;
  v81 = 0;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&CmpCallbackListLock, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned __int8 *)&CmpCallbackListLock);
  while ( __strex(v5 | 1, (unsigned __int8 *)&CmpCallbackListLock) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&CmpCallbackListLock, v3, (unsigned int)&CmpCallbackListLock);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
LABEL_7:
  v6 = anonymous7;
  v7 = anonymous8;
  while ( 1 )
  {
    v8 = (unsigned int *)CmListGetNextElement(&CallbackListHead, &v81, 0);
    v9 = (unsigned int)v8;
    v82[1] = (unsigned int)v8;
    if ( !v8 )
      break;
    if ( v8[4] == v6 && v8[5] == v7 )
    {
      v10 = v8[2];
      __dmb(0xBu);
      if ( v10 )
      {
        if ( (v10 & 0x80000000) != 0 )
          goto LABEL_7;
        __dmb(0xBu);
        v11 = v8 + 2;
        do
          v12 = __ldrex(v11);
        while ( __strex(v12 | 0x80000000, v11) );
        __dmb(0xBu);
        __pld(&CmpCallbackListLock);
        v13 = CmpCallbackListLock;
        if ( (CmpCallbackListLock & 0xFFFFFFF0) <= 0x10 )
          v14 = 0;
        else
          v14 = CmpCallbackListLock - 16;
        if ( (CmpCallbackListLock & 2) != 0 )
          goto LABEL_23;
        __dmb(0xBu);
        do
          v15 = __ldrex((unsigned int *)&CmpCallbackListLock);
        while ( v15 == v13 && __strex(v14, (unsigned int *)&CmpCallbackListLock) );
        if ( v15 != v13 )
LABEL_23:
          ExfReleasePushLock(&CmpCallbackListLock, v13);
        v16 = KeAbPostRelease((unsigned int)&CmpCallbackListLock);
        v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v18 = *(_WORD *)(v17 + 0x134) + 1;
        *(_WORD *)(v17 + 308) = v18;
        if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
          KiCheckForKernelApcDelivery(v16);
        while ( 1 )
        {
          v19 = *v11;
          v80 = *v11;
          __dmb(0xBu);
          if ( v19 == 0x80000000 )
            break;
          ExBlockOnAddressPushLock((int)&CallbackListDeleteEvent, (unsigned __int64 *)v11, &v80, 4, 0);
        }
        v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v20 + 308);
        v21 = KeAbPreAcquire((unsigned int)&CmpCallbackListLock, 0, 0);
        v22 = v21;
        do
          v23 = __ldrex((unsigned __int8 *)&CmpCallbackListLock);
        while ( __strex(v23 | 1, (unsigned __int8 *)&CmpCallbackListLock) );
        __dmb(0xBu);
        if ( (v23 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(&CmpCallbackListLock, v21, (unsigned int)&CmpCallbackListLock);
        if ( v22 )
          *(_BYTE *)(v22 + 14) |= 1u;
        v24 = *(_DWORD *)v9;
        v25 = *(_DWORD **)(v9 + 4);
        if ( *(_DWORD *)(*(_DWORD *)v9 + 4) != v9 || *v25 != v9 )
          __fastfail(3u);
        *v25 = v24;
        *(_DWORD *)(v24 + 4) = v25;
        __pld(&CmpCallbackListLock);
        v26 = CmpCallbackListLock;
        if ( (CmpCallbackListLock & 0xFFFFFFF0) <= 0x10 )
          v27 = 0;
        else
          v27 = CmpCallbackListLock - 16;
        if ( (CmpCallbackListLock & 2) == 0 )
        {
          __dmb(0xBu);
          do
            v28 = __ldrex((unsigned int *)&CmpCallbackListLock);
          while ( v28 == v26 && __strex(v27, (unsigned int *)&CmpCallbackListLock) );
          goto LABEL_56;
        }
        goto LABEL_57;
      }
      v29 = *v8;
      v30 = (unsigned int **)v8[1];
      if ( *(unsigned int **)(*v8 + 4) != v8 || *v30 != v8 )
        __fastfail(3u);
      *v30 = (unsigned int *)v29;
      *(_DWORD *)(v29 + 4) = v30;
      __pld(&CmpCallbackListLock);
      v26 = CmpCallbackListLock;
      if ( (CmpCallbackListLock & 0xFFFFFFF0) <= 0x10 )
        v31 = 0;
      else
        v31 = CmpCallbackListLock - 16;
      if ( (CmpCallbackListLock & 2) != 0 )
        goto LABEL_57;
      __dmb(0xBu);
      do
        v28 = __ldrex((unsigned int *)&CmpCallbackListLock);
      while ( v28 == v26 && __strex(v31, (unsigned int *)&CmpCallbackListLock) );
LABEL_56:
      if ( v28 != v26 )
LABEL_57:
        ExfReleasePushLock(&CmpCallbackListLock, v26);
      v32 = KeAbPostRelease((unsigned int)&CmpCallbackListLock);
      v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v34 = *(_WORD *)(v33 + 0x134) + 1;
      *(_WORD *)(v33 + 308) = v34;
      if ( !v34 && *(_DWORD *)(v33 + 100) != v33 + 100 && !*(_WORD *)(v33 + 310) )
        KiCheckForKernelApcDelivery(v32);
      v81 = 0;
      v84 = &v83;
      v83 = (int *)&v83;
      v80 = 0;
      v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v35 + 308);
      v36 = KeAbPreAcquire((unsigned int)&CmpContextListLock, 0, 0);
      v37 = v36;
      do
        v38 = __ldrex((unsigned __int8 *)&CmpContextListLock);
      while ( __strex(v38 | 1, (unsigned __int8 *)&CmpContextListLock) );
      __dmb(0xBu);
      if ( (v38 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&CmpContextListLock, v36, (unsigned int)&CmpContextListLock);
      if ( v37 )
        *(_BYTE *)(v37 + 14) |= 1u;
      for ( i = *(unsigned int **)(v9 + 40); i != (unsigned int *)(v9 + 40); i = (unsigned int *)v82[0] )
      {
        v82[0] = *i;
        v40 = i - 2;
        if ( ObReferenceObjectSafe(i[5]) )
        {
          v41 = *i;
          v42 = (unsigned int *)i[1];
          if ( *(unsigned int **)(*i + 4) != i || (unsigned int *)*v42 != i )
            __fastfail(3u);
          *v42 = v41;
          *(_DWORD *)(v41 + 4) = v42;
          v43 = *v40;
          v44 = (unsigned int **)*(i - 1);
          if ( *(unsigned int **)(*v40 + 4) != v40 || *v44 != v40 )
            __fastfail(3u);
          *v44 = (unsigned int *)v43;
          *(_DWORD *)(v43 + 4) = v44;
          v45 = v84;
          *i = (unsigned int)&v83;
          i[1] = (unsigned int)v45;
          if ( *v45 != (int *)&v83 )
            __fastfail(3u);
          *v45 = (int *)i;
          v84 = (int **)i;
        }
        else
        {
          v80 = 1;
        }
      }
      __pld(&CmpContextListLock);
      v46 = CmpContextListLock;
      if ( (CmpContextListLock & 0xFFFFFFF0) <= 0x10 )
        v47 = 0;
      else
        v47 = CmpContextListLock - 16;
      if ( (CmpContextListLock & 2) != 0 )
        goto LABEL_90;
      __dmb(0xBu);
      do
        v48 = __ldrex((unsigned int *)&CmpContextListLock);
      while ( v48 == v46 && __strex(v47, (unsigned int *)&CmpContextListLock) );
      if ( v48 != v46 )
LABEL_90:
        ExfReleasePushLock(&CmpContextListLock, v46);
      v49 = KeAbPostRelease((unsigned int)&CmpContextListLock);
      v50 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v51 = *(_WORD *)(v50 + 0x134) + 1;
      *(_WORD *)(v50 + 308) = v51;
      if ( !v51 && *(_DWORD *)(v50 + 100) != v50 + 100 && !*(_WORD *)(v50 + 310) )
        KiCheckForKernelApcDelivery(v49);
      v52 = v80;
      while ( 1 )
      {
        v53 = v83;
        if ( v83 == (int *)&v83 )
          break;
        v54 = *v83;
        if ( (int **)v83[1] != &v83 || *(int **)(v54 + 4) != v83 )
          __fastfail(3u);
        v83 = (int *)*v83;
        *(_DWORD *)(v54 + 4) = &v83;
        v55 = (unsigned int)(v53 - 2);
        v82[0] = (unsigned int)(v53 - 2);
        v85 = v53[5];
        v86 = v53[6];
        (*(void (__fastcall **)(_DWORD, int, int *))(v9 + 28))(*(_DWORD *)(v9 + 24), 40, &v85);
        ObfDereferenceObject(*(_DWORD *)(v55 + 28));
        ExFreePoolWithTag(v55);
      }
      while ( v52 )
      {
        v56 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v56 + 308);
        v57 = KeAbPreAcquire((unsigned int)&CmpContextListLock, 0, 0);
        v58 = v57;
        do
          v59 = __ldrex((unsigned __int8 *)&CmpContextListLock);
        while ( __strex(v59 | 1, (unsigned __int8 *)&CmpContextListLock) );
        __dmb(0xBu);
        if ( (v59 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(&CmpContextListLock, v57, (unsigned int)&CmpContextListLock);
        if ( v58 )
          *(_BYTE *)(v58 + 14) |= 1u;
        v60 = *(_DWORD *)(v9 + 40);
        v82[0] = v60;
        __pld(&CmpContextListLock);
        v61 = CmpContextListLock;
        if ( (CmpContextListLock & 0xFFFFFFF0) <= 0x10 )
          v62 = 0;
        else
          v62 = CmpContextListLock - 16;
        if ( (CmpContextListLock & 2) != 0 )
          goto LABEL_116;
        __dmb(0xBu);
        do
          v63 = __ldrex((unsigned int *)&CmpContextListLock);
        while ( v63 == v61 && __strex(v62, (unsigned int *)&CmpContextListLock) );
        if ( v63 != v61 )
LABEL_116:
          ExfReleasePushLock(&CmpContextListLock, v61);
        v64 = KeAbPostRelease((unsigned int)&CmpContextListLock);
        v65 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v66 = *(_WORD *)(v65 + 0x134) + 1;
        *(_WORD *)(v65 + 308) = v66;
        if ( !v66 && *(_DWORD *)(v65 + 100) != v65 + 100 && !*(_WORD *)(v65 + 310) )
          KiCheckForKernelApcDelivery(v64);
        if ( v60 == v9 + 40 )
          v52 = 0;
        else
          ExBlockOnAddressPushLock((int)&CallbackListDeleteEvent, (unsigned __int64 *)(v9 + 40), v82, 4, 0);
      }
      __dmb(0xBu);
      do
      {
        v67 = __ldrex((unsigned int *)&CmpCallBackCount);
        v68 = v67 - 1;
      }
      while ( __strex(v68, (unsigned int *)&CmpCallBackCount) );
      __dmb(0xBu);
      v69 = 0;
      if ( !v68 )
      {
        v70 = (_DWORD *)RtlpInterlockedFlushSList((unsigned __int64 *)&CmpCallbackContextSList);
        while ( v70 )
        {
          v71 = (unsigned int)v70;
          v70 = (_DWORD *)*v70;
          ExFreePoolWithTag(v71);
        }
      }
      v72 = *(_DWORD *)(v9 + 36);
      if ( v72 )
        ExFreePoolWithTag(v72);
      ExFreePoolWithTag(v9);
      return v69;
    }
  }
  __pld(&CmpCallbackListLock);
  v73 = CmpCallbackListLock;
  if ( (CmpCallbackListLock & 0xFFFFFFF0) <= 0x10 )
    v74 = 0;
  else
    v74 = CmpCallbackListLock - 16;
  if ( (CmpCallbackListLock & 2) != 0 )
    goto LABEL_142;
  __dmb(0xBu);
  do
    v75 = __ldrex((unsigned int *)&CmpCallbackListLock);
  while ( v75 == v73 && __strex(v74, (unsigned int *)&CmpCallbackListLock) );
  if ( v75 != v73 )
LABEL_142:
    ExfReleasePushLock(&CmpCallbackListLock, v73);
  v76 = KeAbPostRelease((unsigned int)&CmpCallbackListLock);
  v77 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v78 = *(_WORD *)(v77 + 0x134) + 1;
  *(_WORD *)(v77 + 308) = v78;
  if ( !v78 && *(_DWORD *)(v77 + 100) != v77 + 100 && !*(_WORD *)(v77 + 310) )
    KiCheckForKernelApcDelivery(v76);
  return -1073741811;
}
