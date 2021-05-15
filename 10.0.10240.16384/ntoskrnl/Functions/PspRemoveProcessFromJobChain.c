// PspRemoveProcessFromJobChain 
 
int __fastcall PspRemoveProcessFromJobChain(_DWORD *a1, _DWORD *a2, int a3, int a4)
{
  int v4; // r10
  _BYTE *v7; // r0
  unsigned int v8; // r6
  unsigned __int8 *v9; // r3
  unsigned int v10; // r5
  _DWORD *v11; // r3
  int v12; // r3
  int v13; // r2
  _DWORD *v14; // r2
  _DWORD *v15; // r3
  _DWORD *v16; // r3
  int v17; // r2
  int v18; // r3
  _DWORD *v19; // r3
  int v20; // r2
  int v21; // r3
  _QWORD *v22; // r1
  int v23; // r8
  _DWORD *v24; // r4
  int v25; // r5
  char v26; // r6
  int v27; // r2
  int *v28; // r1
  int v29; // r3
  _DWORD *v30; // t1
  int v31; // r2
  int *v32; // r1
  _DWORD *v33; // t1
  int v34; // r5
  int v35; // r7
  int v36; // r2
  int *v37; // r1
  int v38; // r3
  int v39; // t1
  int v40; // r2
  int *v41; // r1
  int v42; // t1
  int v43; // r0
  __int16 v44; // r3
  int result; // r0
  __int16 v46; // r3
  unsigned int *v47; // r7
  unsigned int v48; // r4
  int v49; // r2
  int *v50; // r1
  int v51; // r3
  int v52; // t1
  int v53; // r2
  int *v54; // r1
  int v55; // t1
  int v56; // r3
  int v57; // r0
  __int16 v58; // r3
  unsigned int v59; // r0
  unsigned int v60; // r1
  _DWORD *v61; // [sp+0h] [bp-98h]
  int v62; // [sp+4h] [bp-94h] BYREF
  int v63; // [sp+8h] [bp-90h]
  int v64; // [sp+Ch] [bp-8Ch]
  int v65; // [sp+10h] [bp-88h]
  int v66; // [sp+14h] [bp-84h]
  int v67; // [sp+18h] [bp-80h]
  _DWORD *v68; // [sp+1Ch] [bp-7Ch]
  unsigned int v69; // [sp+20h] [bp-78h]
  char v70[112]; // [sp+28h] [bp-70h] BYREF

  v4 = a3;
  v66 = a3;
  v68 = a2;
  v7 = memset(v70, 0, 80);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v69 = v8;
  __dmb(0xBu);
  v9 = (unsigned __int8 *)(a1 + 47);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 | 1, v9) );
  __dmb(0xBu);
  if ( (v10 & 1) == 0 )
    return sub_7C19D8(v7);
  v67 = 0;
  v65 = 0;
  if ( (v4 & 2) != 0 && (a1[48] & 0x4000000) != 0 && (a1[184] & 0x100) == 0 )
  {
    PsTerminateProcess((int)a1, a4);
    v67 = 1;
  }
  v64 = 1;
  v11 = (_DWORD *)a1[72];
  __dmb(0xBu);
  v61 = v11;
  __dmb(0xBu);
  while ( 1 )
  {
    v12 = v11[144];
    __dmb(0xBu);
    v63 = v12;
    v13 = v12;
    __dmb(0xBu);
    if ( v8 )
    {
      v12 = *(__int16 *)(v8 + 310) - 1;
      *(_WORD *)(v8 + 310) = v12;
    }
    ExAcquireResourceExclusiveLite(v13 + 32, 1, v13, v12);
    v14 = v61;
    __dmb(0xBu);
    v15 = (_DWORD *)a1[72];
    __dmb(0xBu);
    if ( v14 == v15 )
    {
      v16 = v61;
      __dmb(0xBu);
      v17 = v63;
      __dmb(0xBu);
      v18 = v16[144];
      __dmb(0xBu);
      if ( v17 == v18 )
        break;
    }
    v56 = v63;
    __dmb(0xBu);
    v57 = ExReleaseResourceLite(v56 + 32);
    if ( v8 )
    {
      v58 = *(_WORD *)(v8 + 310) + 1;
      *(_WORD *)(v8 + 310) = v58;
      if ( !v58 && *(_DWORD *)(v8 + 100) != v8 + 100 )
        KiCheckForKernelApcDelivery(v57);
    }
    v11 = (_DWORD *)a1[72];
    __dmb(0xBu);
    v61 = v11;
    __dmb(0xBu);
  }
  v34 = (int)v61;
  __dmb(0xBu);
  v35 = v63;
  v62 = v63;
  __dmb(0xBu);
  if ( (PerfGlobalGroupMask & 0x80000) != 0 )
    EtwTraceJobRemoveProcess(a1, v4, a4);
  if ( (v4 & 4) != 0 )
    v23 = PspGetProcessAccountingInformation(a1, v70);
  else
    v23 = 0;
  v24 = v61;
  if ( v61 )
  {
    v25 = v65;
    v26 = v66;
    do
    {
      v27 = 0;
      v28 = &v62;
      while ( 1 )
      {
        v30 = (_DWORD *)*v28++;
        v29 = (int)v30;
        if ( v24 == v30 )
          break;
        if ( ++v27 )
        {
          ExAcquireResourceExclusiveLite((int)(v24 + 8), 1, v27, v29);
          break;
        }
      }
      if ( v25 )
      {
        --v24[36];
        if ( (a1[184] & 0x80) != 0 )
          --v24[171];
      }
      if ( (v26 & 8) != 0 && v25 )
        ++v24[37];
      if ( v68 && (!*v68 || (_DWORD *)*v68 == v24) && v24[53] && ((1 << v68[1]) & v24[107]) != 0 )
        PspSendJobNotification((int)v24);
      if ( v23 )
      {
        PspFoldProcessAccountingIntoJob(v24, a1, v70);
        v19 = (_DWORD *)a1[72];
        __dmb(0xBu);
        if ( v24 == v19 && (v20 = PspEnforcementSequenceNumber, __dmb(0xBu), v24[172] != v20) )
        {
          v21 = 0;
          v64 = 0;
        }
        else
        {
          v21 = v64;
        }
        if ( v21 == 1 )
        {
          v22 = v24 + 150;
          if ( v24 + 150 < v24 + 170 )
          {
            while ( !*v22 )
            {
              if ( ++v22 >= (_QWORD *)v24 + 85 )
                goto LABEL_32;
            }
            PspSubtractAccountingValues(v24 + 150, v70);
            v64 = 2;
          }
        }
      }
LABEL_32:
      v31 = 0;
      v32 = &v62;
      while ( 1 )
      {
        v33 = (_DWORD *)*v32++;
        if ( v24 == v33 )
          break;
        if ( ++v31 )
        {
          ExReleaseResourceLite((int)(v24 + 8));
          break;
        }
      }
      v24 = (_DWORD *)v24[143];
    }
    while ( v24 );
    v34 = (int)v61;
    v35 = v62;
    v8 = v69;
    LOBYTE(v4) = v66;
  }
  if ( (v4 & 1) != 0 )
  {
    v49 = 0;
    v50 = &v62;
    while ( 1 )
    {
      v52 = *v50++;
      v51 = v52;
      if ( v34 == v52 )
        break;
      if ( ++v49 )
      {
        ExAcquireResourceExclusiveLite(v34 + 32, 1, v49, v51);
        break;
      }
    }
    PspUnlinkJobProcess(v34, (int)a1);
    v53 = 0;
    v54 = &v62;
    while ( 1 )
    {
      v55 = *v54++;
      if ( v34 == v55 )
        break;
      if ( ++v53 )
      {
        ExReleaseResourceLite(v34 + 32);
        break;
      }
    }
  }
  v36 = 0;
  v37 = &v62;
  while ( 1 )
  {
    v39 = *v37++;
    v38 = v39;
    if ( v34 == v39 )
      break;
    if ( ++v36 )
    {
      ExAcquireResourceExclusiveLite(v34 + 32, 1, v36, v38);
      break;
    }
  }
  if ( v65 && (a1[47] & 4) != 0 && !v67 )
  {
    v47 = a1 + 47;
    v48 = a1[47];
    __dmb(0xBu);
    do
    {
      v59 = v48;
      __dmb(0xBu);
      do
        v60 = __ldrex(v47);
      while ( v60 == v48 && __strex(v48 & 0xCFFFFFFF, v47) );
      v48 = v60;
      __dmb(0xBu);
    }
    while ( v60 != v59 );
    v35 = v62;
  }
  v40 = 0;
  v41 = &v62;
  while ( 1 )
  {
    v42 = *v41++;
    if ( v34 == v42 )
      break;
    if ( ++v40 )
    {
      ExReleaseResourceLite(v34 + 32);
      break;
    }
  }
  v43 = ExReleaseResourceLite(v35 + 32);
  if ( v8 )
  {
    v44 = *(_WORD *)(v8 + 310) + 1;
    *(_WORD *)(v8 + 310) = v44;
    if ( !v44 && *(_DWORD *)(v8 + 100) != v8 + 100 )
      KiCheckForKernelApcDelivery(v43);
  }
  --*(_WORD *)(v8 + 308);
  result = PspChangeProcessExecutionState(a1);
  v46 = *(_WORD *)(v8 + 308) + 1;
  *(_WORD *)(v8 + 308) = v46;
  if ( !v46 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
