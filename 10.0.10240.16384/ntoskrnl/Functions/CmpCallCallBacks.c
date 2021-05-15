// CmpCallCallBacks 
 
int __fastcall CmpCallCallBacks(int a1, _DWORD *a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v6; // r6
  int v7; // r3
  int v8; // r5
  _DWORD *v9; // r10
  int v10; // r2
  unsigned int v11; // r4
  int v12; // r3
  int *v13; // r8
  unsigned int v14; // r2
  int v15; // r0
  int v16; // r4
  unsigned int v17; // r2
  _DWORD *v18; // r9
  unsigned int *v19; // r5
  int v20; // r3
  unsigned int v21; // r2
  int v22; // r1
  unsigned int v23; // r0
  unsigned int v24; // r2
  int v25; // r0
  unsigned int v26; // r1
  __int16 v27; // r3
  _DWORD *v28; // r4
  unsigned int v29; // r2
  unsigned int v30; // r2
  _DWORD *v31; // r2
  int v32; // r1
  _DWORD *v33; // r2
  _DWORD *v34; // r3
  unsigned int v35; // r2
  unsigned int *v36; // r2
  unsigned int v37; // r1
  unsigned int v38; // r1
  unsigned int v39; // r2
  int v40; // r0
  int v41; // r4
  unsigned int v42; // r2
  int v43; // r1
  unsigned int v44; // r0
  unsigned int v45; // r2
  int v46; // r0
  unsigned int v47; // r1
  __int16 v48; // r3
  _DWORD *v50; // r2
  int v51; // r3
  int v52; // lr
  _DWORD *v53; // r4
  _DWORD *v54; // r2
  int v55; // r5
  int v56; // r9
  _DWORD *v57; // r3
  unsigned int v58; // r2
  unsigned int *v59; // r2
  unsigned int v60; // r1
  unsigned int v61; // r1
  int v63; // [sp+4h] [bp-6Ch]
  _DWORD *v64; // [sp+8h] [bp-68h]
  int v65; // [sp+Ch] [bp-64h]
  int v66; // [sp+10h] [bp-60h]
  int v67; // [sp+14h] [bp-5Ch]
  unsigned int v68; // [sp+1Ch] [bp-54h]
  int v69; // [sp+28h] [bp-48h]
  int v70; // [sp+30h] [bp-40h]
  _DWORD _38[18]; // [sp+38h] [bp-38h] BYREF
  int varg_r2; // [sp+80h] [bp+10h]
  int varg_r3; // [sp+84h] [bp+14h]

  varg_r2 = a3;
  v6 = a4;
  v63 = a4;
  varg_r3 = a4;
  v7 = a3;
  v70 = a3;
  LOBYTE(varg_r2) = a3;
  v64 = a2;
  _38[17] = a2;
  v66 = a1;
  _38[16] = a1;
  v8 = 0;
  v67 = 0;
  v9 = 0;
  v10 = 0;
  v65 = 0;
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v68 = v11;
  if ( v7 == 1 )
  {
    v12 = *(_DWORD *)(v11 + 1032);
    if ( v12 )
      v13 = *(int **)(v12 + 4);
    else
      v13 = &CallbackListHead;
    v69 = 1;
    v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v14 + 308);
    v15 = KeAbPreAcquire((unsigned int)&CmpCallbackListLock, 0, 0);
    v16 = v15;
    do
      v17 = __ldrex((unsigned int *)&CmpCallbackListLock);
    while ( !v17 && __strex(0x11u, (unsigned int *)&CmpCallbackListLock) );
    __dmb(0xBu);
    if ( v17 )
      ExfAcquirePushLockSharedEx(&CmpCallbackListLock, v15, (unsigned int)&CmpCallbackListLock);
    if ( v16 )
      *(_BYTE *)(v16 + 14) |= 1u;
    v18 = a6;
    while ( 1 )
    {
      v13 = (int *)*v13;
      if ( v13 == &CallbackListHead )
        break;
      v19 = (unsigned int *)(v13 + 2);
      v20 = v13[2];
      __dmb(0xBu);
      if ( (v20 & 0x80000000) != 0 )
      {
        v8 = v67;
      }
      else
      {
        __dmb(0xBu);
        do
          v21 = __ldrex(v19);
        while ( __strex(v21 + 1, v19) );
        __dmb(0xBu);
        __pld(&CmpCallbackListLock);
        v22 = CmpCallbackListLock;
        if ( (CmpCallbackListLock & 0xFFFFFFF0) <= 0x10 )
          v23 = 0;
        else
          v23 = CmpCallbackListLock - 16;
        if ( (CmpCallbackListLock & 2) != 0 )
          goto LABEL_25;
        __dmb(0xBu);
        do
          v24 = __ldrex((unsigned int *)&CmpCallbackListLock);
        while ( v24 == v22 && __strex(v23, (unsigned int *)&CmpCallbackListLock) );
        if ( v24 != v22 )
LABEL_25:
          ExfReleasePushLock(&CmpCallbackListLock, v22);
        v25 = KeAbPostRelease((unsigned int)&CmpCallbackListLock);
        v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v27 = *(_WORD *)(v26 + 0x134) + 1;
        *(_WORD *)(v26 + 308) = v27;
        if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
          KiCheckForKernelApcDelivery(v25);
        v69 = 0;
        v28 = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)&CmpCallbackContextSList);
        if ( !v28 )
          v28 = (_DWORD *)ExAllocatePoolWithTag(1, 20, 1768115523);
        if ( !v28 )
        {
          __dmb(0xBu);
          do
          {
            v29 = __ldrex(v19);
            v30 = v29 - 1;
          }
          while ( __strex(v30, v19) );
          __dmb(0xBu);
          if ( v30 == 0x80000000 )
          {
            __dmb(0xFu);
            if ( CallbackListDeleteEvent )
              ExfUnblockPushLock((int)&CallbackListDeleteEvent, 0);
          }
          v8 = -1073741670;
          v10 = 1;
LABEL_39:
          v70 = 0;
          v65 = 1;
          goto LABEL_70;
        }
        v28[3] = v13;
        v28[4] = 0;
        v28[2] = *(_DWORD *)(v68 + 1032);
        *(_DWORD *)(v68 + 1032) = v28 + 2;
        v31 = (_DWORD *)a6[1];
        *v28 = a6;
        v28[1] = v31;
        if ( (_DWORD *)*v31 != a6 )
          __fastfail(3u);
        *v31 = v28;
        a6[1] = v28;
        CmpCallbackFillObjectContext(v66, v64, v13 + 4);
        v8 = ((int (__fastcall *)(int, int, _DWORD *))v13[7])(v13[6], v66, v64);
        v67 = v8;
        if ( v66 == 14 )
        {
          v8 = 0;
          v67 = 0;
        }
        if ( v8 < 0 )
        {
          v32 = *v28;
          v33 = (_DWORD *)v28[1];
          if ( *(_DWORD **)(*v28 + 4) != v28 || (_DWORD *)*v33 != v28 )
            __fastfail(3u);
          *v33 = v32;
          *(_DWORD *)(v32 + 4) = v33;
          v34 = *(_DWORD **)(v68 + 1032);
          if ( v34 )
            *(_DWORD *)(v68 + 1032) = *v34;
          v35 = KeNumberProcessors_0 * CmpCallBackCount;
          if ( (unsigned int)(KeNumberProcessors_0 * CmpCallBackCount) > 0x40 )
            v35 = 64;
          if ( (unsigned __int16)word_6324FC >= v35 )
            ExFreePoolWithTag((unsigned int)v28);
          else
            RtlpInterlockedPushEntrySList((unsigned __int64 *)&CmpCallbackContextSList, v28);
          __dmb(0xBu);
          v36 = (unsigned int *)(v13 + 2);
          do
          {
            v37 = __ldrex(v36);
            v38 = v37 - 1;
          }
          while ( __strex(v38, v36) );
          __dmb(0xBu);
          if ( v38 == 0x80000000 )
          {
            __dmb(0xFu);
            if ( CallbackListDeleteEvent )
              ExfUnblockPushLock((int)&CallbackListDeleteEvent, 0);
          }
          v10 = 1;
          goto LABEL_39;
        }
        CmpCallbackFetchCallContext(v66, v64, v28);
        v69 = 1;
        v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v39 + 308);
        v40 = KeAbPreAcquire((unsigned int)&CmpCallbackListLock, 0, 0);
        v41 = v40;
        do
          v42 = __ldrex((unsigned int *)&CmpCallbackListLock);
        while ( !v42 && __strex(0x11u, (unsigned int *)&CmpCallbackListLock) );
        __dmb(0xBu);
        if ( v42 )
          ExfAcquirePushLockSharedEx(&CmpCallbackListLock, v40, (unsigned int)&CmpCallbackListLock);
        if ( v41 )
          *(_BYTE *)(v41 + 14) |= 1u;
      }
    }
    v10 = 0;
LABEL_70:
    if ( v69 )
    {
      __pld(&CmpCallbackListLock);
      v43 = CmpCallbackListLock;
      if ( (CmpCallbackListLock & 0xFFFFFFF0) <= 0x10 )
        v44 = 0;
      else
        v44 = CmpCallbackListLock - 16;
      if ( (CmpCallbackListLock & 2) != 0 )
        goto LABEL_79;
      __dmb(0xBu);
      do
        v45 = __ldrex((unsigned int *)&CmpCallbackListLock);
      while ( v45 == v43 && __strex(v44, (unsigned int *)&CmpCallbackListLock) );
      if ( v45 != v43 )
LABEL_79:
        ExfReleasePushLock(&CmpCallbackListLock, v43);
      v46 = KeAbPostRelease((unsigned int)&CmpCallbackListLock);
      v47 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v48 = *(_WORD *)(v47 + 0x134) + 1;
      *(_WORD *)(v47 + 308) = v48;
      if ( !v48 && *(_DWORD *)(v47 + 100) != v47 + 100 && !*(_WORD *)(v47 + 310) )
        KiCheckForKernelApcDelivery(v46);
      v10 = v65;
    }
    a2 = v64;
    a1 = v66;
    v6 = v63;
  }
  else
  {
    v18 = a6;
  }
  if ( !v70 )
  {
    if ( v10 != 1 )
    {
      v9 = a2;
      v52 = a1;
      v63 = a1;
      varg_r3 = a1;
      goto LABEL_101;
    }
    memset(_38, 0, 28);
    v9 = _38;
    if ( v6 == 27 || v6 == 29 )
    {
      if ( v8 == -1073740541 )
      {
        v50 = v64;
        a5 = *(_DWORD *)v64[10];
        goto LABEL_96;
      }
      a5 = 0;
    }
    v50 = v64;
LABEL_96:
    _38[0] = a5;
    if ( v8 == -1073740541 )
      v51 = 0;
    else
      v51 = v8;
    _38[1] = v51;
    _38[3] = v51;
    _38[2] = v50;
    while ( 1 )
    {
      v52 = v63;
LABEL_101:
      if ( (_DWORD *)*v18 == v18 )
        break;
      v53 = (_DWORD *)v18[1];
      v54 = (_DWORD *)v53[1];
      if ( (_DWORD *)*v53 != v18 || (_DWORD *)*v54 != v53 )
        __fastfail(3u);
      v18[1] = v54;
      *v54 = v18;
      v55 = v53[3];
      v9[4] = v53[4];
      CmpCallbackFillObjectContext(v52, v9, v55 + 16);
      v56 = (*(int (__fastcall **)(_DWORD, int, _DWORD *))(v55 + 28))(*(_DWORD *)(v55 + 24), v63, v9);
      v57 = *(_DWORD **)(v68 + 1032);
      if ( v57 )
        *(_DWORD *)(v68 + 1032) = *v57;
      v58 = KeNumberProcessors_0 * CmpCallBackCount;
      if ( (unsigned int)(KeNumberProcessors_0 * CmpCallBackCount) > 0x40 )
        v58 = 64;
      if ( (unsigned __int16)word_6324FC >= v58 )
        ExFreePoolWithTag((unsigned int)v53);
      else
        RtlpInterlockedPushEntrySList((unsigned __int64 *)&CmpCallbackContextSList, v53);
      __dmb(0xBu);
      v59 = (unsigned int *)(v55 + 8);
      do
      {
        v60 = __ldrex(v59);
        v61 = v60 - 1;
      }
      while ( __strex(v61, v59) );
      __dmb(0xBu);
      if ( v61 == 0x80000000 )
      {
        __dmb(0xFu);
        if ( CallbackListDeleteEvent )
          ExfUnblockPushLock((int)&CallbackListDeleteEvent, 0);
      }
      if ( v56 == -1073740541 )
        v9[1] = v9[3];
      v8 = 0;
      v18 = a6;
    }
    v10 = v65;
  }
  if ( v10 == 1 )
  {
    if ( v9 )
    {
      v8 = v9[3];
      if ( v8 >= 0 )
        v8 = -1073740541;
    }
  }
  return v8;
}
