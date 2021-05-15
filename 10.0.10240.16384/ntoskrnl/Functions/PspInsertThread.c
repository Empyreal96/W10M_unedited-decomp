// PspInsertThread 
 
int __fastcall PspInsertThread(_DWORD *a1, _DWORD *a2, int a3, _DWORD *a4, int a5, _BYTE *a6, _DWORD *a7, int a8, int a9, _DWORD *a10, _DWORD *a11)
{
  _DWORD *v11; // lr
  _DWORD *v12; // r10
  _DWORD *v13; // r1
  unsigned int *v14; // r8
  int *v15; // r6
  unsigned int *v16; // r9
  int v17; // r3
  unsigned __int8 *v18; // r5
  int v19; // r4
  unsigned int v20; // r2
  int v21; // r4
  int v22; // r3
  int v23; // r3
  unsigned int v24; // r2
  int v25; // r0
  unsigned int v26; // r2
  int v27; // r3
  int v28; // r3
  int v29; // r3
  unsigned __int8 *v30; // r3
  unsigned int v31; // r2
  unsigned __int8 *v32; // r5
  int v33; // r0
  int v34; // r4
  unsigned int v35; // r2
  _DWORD *v36; // r1
  _DWORD *v37; // r0
  unsigned int v38; // r1
  int v39; // r5
  unsigned __int8 *v40; // r3
  unsigned int v41; // r2
  unsigned int *v42; // r4
  unsigned int v43; // r1
  _DWORD *v44; // r0
  _DWORD *v45; // r8
  int v46; // r2
  int v47; // r4
  _DWORD *v48; // r1
  int v49; // r10
  _DWORD *v50; // r5
  unsigned int *v51; // r2
  unsigned int v52; // r0
  unsigned int *v53; // r4
  unsigned int v54; // r1
  unsigned int *v55; // r4
  unsigned int v56; // r1
  int v57; // r4
  int v58; // r9
  int v59; // lr
  char v60; // r3
  BOOL v61; // r2
  char v62; // r3
  int v63; // r10
  unsigned int v64; // r0
  int v65; // r3
  int v66; // r3
  int *v67; // r9
  unsigned int v68; // r6
  _DWORD *v69; // r4
  int v70; // r0
  unsigned int v71; // r8
  void (__fastcall *v72)(_DWORD, _DWORD, int); // r0
  void (__fastcall *v73)(_DWORD *, _DWORD, int *); // r0
  char v74; // r3
  _DWORD *v75; // r5
  int v76; // r6
  int v77; // r0
  unsigned int v78; // r8
  void (__fastcall *v79)(_DWORD, _DWORD, int); // r0
  int v80; // r1
  int v81; // r1
  unsigned __int8 *v82; // r3
  unsigned int v83; // r2
  unsigned int *v84; // r4
  unsigned int v85; // r1
  unsigned int *v86; // r4
  unsigned int v87; // r0
  int v88; // r2
  int v94; // [sp+20h] [bp-D8h]
  char v95; // [sp+28h] [bp-D0h]
  int v96; // [sp+2Ch] [bp-CCh]
  _DWORD *v97; // [sp+30h] [bp-C8h]
  BOOL v98; // [sp+38h] [bp-C0h]
  int v99; // [sp+3Ch] [bp-BCh]
  unsigned int v100; // [sp+5Ch] [bp-9Ch]
  int v101[7]; // [sp+64h] [bp-94h] BYREF
  int v102; // [sp+80h] [bp-78h] BYREF
  int v103; // [sp+84h] [bp-74h]
  int v104; // [sp+88h] [bp-70h]
  int v105; // [sp+8Ch] [bp-6Ch]
  int v106; // [sp+90h] [bp-68h]
  int v107; // [sp+94h] [bp-64h]
  _DWORD *v108; // [sp+98h] [bp-60h]
  int v109; // [sp+9Ch] [bp-5Ch]
  int v110; // [sp+A0h] [bp-58h]
  _BYTE v111[24]; // [sp+A8h] [bp-50h] BYREF
  _DWORD _C0[20]; // [sp+C0h] [bp-38h] BYREF

  _C0[16] = a1;
  _C0[17] = a2;
  _C0[18] = a3;
  v11 = a4;
  _C0[19] = a4;
  v12 = a2;
  v13 = a1;
  v95 = 0;
  v97 = *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v100 = a1[39];
  v101[3] = v100;
  v14 = 0;
  v15 = 0;
  if ( a7 )
  {
    v16 = (unsigned int *)a7[4];
    v17 = a7[1];
    if ( (v17 & 0x4000) != 0 )
      v14 = a7 + 37;
    if ( (v17 & 0x1000) != 0 )
      v15 = a7 + 48;
  }
  else
  {
    v16 = 0;
  }
  if ( (*v11 & 0x20) == 0 )
  {
    v18 = (unsigned __int8 *)(v12 + 42);
    v19 = KeAbPreAcquire((unsigned int)(v12 + 42), 0, 0);
    do
      v20 = __ldrex(v18);
    while ( __strex(v20 | 1, v18) );
    __dmb(0xBu);
    if ( (v20 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v12 + 42, v19, (unsigned int)(v12 + 42));
    v13 = a1;
    v11 = a4;
    if ( v19 )
      *(_BYTE *)(v19 + 14) |= 1u;
  }
  v21 = v12[72];
  __dmb(0xBu);
  if ( v21 )
  {
    ExAcquireResourceSharedLite(v21 + 32, 1);
    if ( v15 )
    {
      if ( (*(_DWORD *)(v21 + 400) & 0x10) != 0 )
      {
        v22 = *(_DWORD *)(v21 + 4 * *((unsigned __int16 *)v15 + 2) + 356);
        if ( !v22 || (v22 & *v15) != *v15 )
          v95 = 2;
      }
      v13 = a1;
      v11 = a4;
    }
    else
    {
      v13 = a1;
      v11 = a4;
    }
  }
  if ( (v95 & 2) != 0
    || (v23 = a2[48], (v23 & 0x4000000) == 0)
    || (v23 & 8) != 0
    || (v23 & 0x40000000) != 0 && (v13[19] & 0x400) == 0 && (*v11 & 2) == 0 )
  {
    if ( v21 )
      ExReleaseResourceLite(v21 + 32);
    v84 = a2 + 42;
    __dmb(0xBu);
    do
      v85 = __ldrex(v84);
    while ( __strex(v85 - 1, v84) );
    if ( (v85 & 2) != 0 && (v85 & 4) == 0 )
      ExfTryToWakePushLock(a2 + 42);
    KeAbPostRelease((unsigned int)(a2 + 42));
    v86 = a1 + 236;
    __dmb(0xBu);
    do
      v87 = __ldrex(v86);
    while ( __strex(v87 - 1, v86) );
    if ( (v87 & 2) != 0 && (v87 & 4) == 0 )
      ExfTryToWakePushLock(v86);
    KeAbPostRelease((unsigned int)v86);
    MmDeleteKernelStack(a1[10], 4);
    a1[8] = 0;
    if ( a6 )
    {
      if ( v100 )
        MmDeleteTeb((int)a2, v100);
      if ( *a6 )
      {
        KiStackAttachProcess((int)a2, 0, (int)_C0);
        if ( (*a6 & 2) != 0 )
        {
          v101[1] = *(_DWORD *)(a3 + 16);
          v101[5] = 0;
          ZwFreeVirtualMemory();
        }
        KiUnstackDetachProcess((unsigned int)_C0, 0);
      }
    }
    v88 = a2[48];
    __dmb(0xBu);
    if ( (v88 & 0x40000008) != 0 )
      v49 = -1073741558;
    else
      v49 = -1073741823;
    return v49;
  }
  KeStartThread((int)a1, v15, v14);
  if ( v21 )
    ExReleaseResourceLite(v21 + 32);
  if ( (a2[48] & 0x40000000) != 0 && (*a4 & 2) != 0 )
    a1[241] |= 0x10u;
  v24 = a1[240] & 0xFFFFF1FF | (((a2[48] >> 27) & 7) << 9);
  a1[240] = v24;
  a1[240] = v24 & 0xFFFF8FFF | (((a2[47] >> 12) & 7) << 12);
  v25 = a2[101];
  __dmb(0xBu);
  a2[101] = v25 + 1;
  v26 = a2[101];
  __dmb(0xBu);
  if ( v26 > a2[178] )
  {
    v27 = a2[101];
    __dmb(0xBu);
    a2[178] = v27;
  }
  v28 = a2[101];
  __dmb(0xBu);
  if ( v28 == 1 )
  {
    v95 |= 1u;
  }
  else
  {
    v29 = a2[101];
    __dmb(0xBu);
    if ( v29 == 2 && (a2[47] & 0x8000) == 0 )
    {
      __dmb(0xBu);
      v30 = (unsigned __int8 *)a2 + 189;
      do
        v31 = __ldrex(v30);
      while ( __strex(v31 | 0x80, v30) );
      __dmb(0xBu);
    }
  }
  v32 = (unsigned __int8 *)(a2 + 180);
  v33 = KeAbPreAcquire((unsigned int)(a2 + 180), 0, 0);
  v34 = v33;
  do
    v35 = __ldrex(v32);
  while ( __strex(v35 | 1, v32) );
  __dmb(0xBu);
  if ( (v35 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(a2 + 180, v33, (unsigned int)(a2 + 180));
  if ( v34 )
    *(_BYTE *)(v34 + 14) |= 1u;
  v36 = a1 + 233;
  v37 = (_DWORD *)a2[100];
  a1[233] = a2 + 99;
  a1[234] = v37;
  if ( (_DWORD *)*v37 != a2 + 99 )
    __fastfail(3u);
  *v37 = v36;
  a2[100] = v36;
  __dmb(0xBu);
  do
    v38 = __ldrex((unsigned int *)v32);
  while ( __strex(v38 - 1, (unsigned int *)v32) );
  if ( (v38 & 2) != 0 && (v38 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v32);
  KeAbPostRelease((unsigned int)v32);
  if ( a2[40] )
  {
    __dmb(0xBu);
    v39 = (int)a1;
    v40 = (unsigned __int8 *)a1 + 3;
    do
      v41 = __ldrex(v40);
    while ( __strex(v41 | 2, v40) );
    __dmb(0xBu);
  }
  else
  {
    v39 = (int)a1;
  }
  v42 = a2 + 42;
  __dmb(0xBu);
  do
    v43 = __ldrex(v42);
  while ( __strex(v43 - 1, v42) );
  if ( (v43 & 2) != 0 && (v43 & 4) == 0 )
    ExfTryToWakePushLock(a2 + 42);
  KeAbPostRelease((unsigned int)v42);
  ObReferenceObjectExWithTag(v39, 2);
  *(_DWORD *)(v39 + 1048) = 1;
  v44 = a4;
  if ( (*a4 & 1) == 0 )
  {
    v45 = a11;
    goto LABEL_70;
  }
  KeSuspendThread(v39);
  v45 = a11;
  v46 = a9;
  v44 = a4;
  if ( (*(_DWORD *)(v39 + 960) & 1) != 0 )
  {
    KeForceResumeThread(v39);
    v44 = a4;
LABEL_70:
    v46 = a9;
  }
  v47 = 0;
  if ( !*(_BYTE *)(v46 + 316) || (*v44 & 0x10) != 0 )
  {
    v48 = a2;
    v47 = 1;
  }
  else
  {
    v48 = v97;
  }
  v49 = SeCreateAccessStateEx(0, v48, v46, v46 + 116, a5, (_DWORD *)(PsThreadType + 52));
  v96 = v49;
  if ( v49 < 0 )
  {
    v50 = a1;
    ObfDereferenceObject((int)a1);
  }
  else
  {
    v50 = a1;
    v49 = ObInsertObjectEx((int)a1, (char *)a9, a5, 0, v47, 0, 0);
    v96 = v49;
    if ( v49 >= 0 )
    {
      ObfDereferenceObject((int)a1);
      if ( v16 )
        *v16 = v100;
      if ( v45 )
      {
        *v45 = a1[219];
        v45[1] = a1[220];
      }
      __dmb(0xBu);
      v51 = a1 + 240;
      do
        v52 = __ldrex(v51);
      while ( __strex(v52 | 2, v51) );
      v53 = a1 + 236;
      __dmb(0xBu);
      do
        v54 = __ldrex(v53);
      while ( __strex(v54 - 1, v53) );
      if ( (v54 & 2) != 0 && (v54 & 4) == 0 )
        ExfTryToWakePushLock(a1 + 236);
      KeAbPostRelease((unsigned int)(a1 + 236));
      goto LABEL_103;
    }
    SepDeleteAccessState(a9);
    SeReleaseSubjectContext(a9 + 28);
  }
  v55 = v50 + 236;
  __dmb(0xBu);
  do
    v56 = __ldrex(v55);
  while ( __strex(v56 - 1, v55) );
  if ( (v56 & 2) != 0 && (v56 & 4) == 0 )
    ExfTryToWakePushLock(v50 + 236);
  KeAbPostRelease((unsigned int)(v50 + 236));
  if ( (*a4 & 1) != 0 )
    KeForceResumeThread((int)v50);
  if ( a6 && *a6 )
  {
    KiStackAttachProcess((int)a2, 0, (int)v111);
    v57 = a3;
    if ( (*a6 & 2) != 0 )
    {
      v101[4] = *(_DWORD *)(a3 + 16);
      v101[2] = 0;
      ZwFreeVirtualMemory();
    }
    KiUnstackDetachProcess((unsigned int)v111, 0);
    goto LABEL_104;
  }
LABEL_103:
  v57 = a3;
LABEL_104:
  v58 = 0;
  v94 = 0;
  v59 = (int)a2;
  if ( (a2[184] & 1) == 0 )
  {
    if ( (v95 & 1) != 0 )
    {
      if ( (PerfGlobalGroupMask & 1) != 0 )
      {
        EtwTraceProcess((int)a2, (int *)0x301);
        v59 = (int)a2;
      }
      v94 = 0;
      v60 = PspNotifyEnableMask;
      __dmb(0xBu);
      v61 = (v60 & 4) != 0;
      v98 = v61;
      v62 = PspNotifyEnableMask;
      __dmb(0xBu);
      if ( (v62 & 2) != 0 || v61 )
      {
        v63 = 0;
        v101[0] = 0;
        v99 = 0;
        if ( v61 )
        {
          v102 = 36;
          v103 = 0;
          v104 = *(_DWORD *)(v59 + 312);
          v64 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v105 = *(_DWORD *)(v64 + 0x36C);
          v106 = *(_DWORD *)(v64 + 0x370);
          v110 = 0;
          if ( !a7 || (v63 = a7[26]) == 0 )
          {
            v99 = 1;
            PsReferenceProcessFilePointer(v59, v101);
            v63 = v101[0];
          }
          v107 = v63;
          if ( a7 && (a7[1] & 0x20) != 0 )
          {
            v108 = a7 + 34;
            v103 |= 1u;
          }
          else
          {
            v108 = (_DWORD *)(v63 + 48);
          }
          if ( a7 && (v65 = a7[30]) != 0 )
            v66 = v65 + 64;
          else
            v66 = 0;
          v109 = v66;
          v67 = &v102;
        }
        else
        {
          v67 = 0;
        }
        v68 = 0;
        v69 = &PspCreateProcessNotifyRoutine;
        while ( 1 )
        {
          v70 = ExReferenceCallBackBlock(v69);
          v71 = v70;
          if ( v70 )
          {
            if ( ExGetCallBackBlockContext(v70) )
            {
              if ( v98 )
              {
                v73 = (void (__fastcall *)(_DWORD *, _DWORD, int *))KeReadStateSemaphore(v71);
                v73(a2, a2[44], v67);
              }
            }
            else
            {
              v72 = (void (__fastcall *)(_DWORD, _DWORD, int))KeReadStateSemaphore(v71);
              v72(a2[78], a2[44], 1);
            }
            ExDereferenceCallBackBlock(v69, v71);
            if ( v67 )
            {
              if ( v67[8] < 0 )
                break;
            }
          }
          ++v68;
          ++v69;
          if ( v68 >= 0x40 )
            goto LABEL_135;
        }
        v94 = v67[8];
        PsTerminateProcess((int)a2, v94);
LABEL_135:
        if ( v99 )
          ObfDereferenceObject(v63);
        v57 = a3;
        v49 = v96;
      }
    }
    if ( (PerfGlobalGroupMask & 2) != 0 )
      EtwTraceThread((int)a1, v57, 1);
    v74 = PspNotifyEnableMask;
    __dmb(0xBu);
    if ( (v74 & 8) != 0 )
    {
      v75 = &PspCreateThreadNotifyRoutine;
      v76 = 64;
      do
      {
        v77 = ExReferenceCallBackBlock(v75);
        v78 = v77;
        if ( v77 )
        {
          if ( !ExGetCallBackBlockContext(v77) )
          {
            v79 = (void (__fastcall *)(_DWORD, _DWORD, int))KeReadStateSemaphore(v78);
            v79(*(_DWORD *)(a1[84] + 176), a1[220], 1);
          }
          ExDereferenceCallBackBlock(v75, v78);
        }
        ++v75;
        --v76;
      }
      while ( v76 );
      v50 = a1;
      v58 = v94;
    }
    else
    {
      v50 = a1;
      v58 = v94;
    }
  }
  if ( v49 >= 0 )
  {
    if ( v58 < 0 )
      v49 = v58;
    else
      v49 = PspCreateObjectHandle(v50, a9, PsThreadType);
    SepDeleteAccessState(a9);
    SeReleaseSubjectContext(a9 + 28);
    if ( v49 >= 0 )
    {
      if ( a7 )
      {
        v80 = a7[58];
        if ( v80 )
          v49 = PspAssignProcessToJobList(a2, v80, a7[59], *(char *)a7);
      }
      if ( v49 < 0 )
      {
        ObCloseHandle(*(_DWORD *)(a9 + 320));
        if ( a6 && (*a6 & 1) != 0 )
          KeRaiseUserException(v49, v81);
      }
      else
      {
        *a10 = *(_DWORD *)(a9 + 320);
      }
    }
    if ( v49 < 0 )
    {
      if ( (v50[19] & 0x400) != 0 )
      {
        __dmb(0xBu);
        v82 = (unsigned __int8 *)(v50 + 240);
        do
          v83 = __ldrex(v82);
        while ( __strex(v83 | 1, v82) );
        __dmb(0xBu);
        if ( (*a4 & 1) != 0 )
          KeForceResumeThread((int)v50);
      }
      else
      {
        PspTerminateThreadByPointer(v50, v49, 0);
      }
    }
  }
  KeReadyThread((int)v50);
  return v49;
}
