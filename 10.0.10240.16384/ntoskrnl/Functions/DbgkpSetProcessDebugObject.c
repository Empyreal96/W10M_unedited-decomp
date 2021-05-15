// DbgkpSetProcessDebugObject 
 
// local variable allocation has failed, the output may be wrong!
int DbgkpSetProcessDebugObject(_DWORD *a1, int a2, int a3, ...)
{
  int v3; // r7
  int v4; // r6
  int v5; // r9
  int v7; // r4
  int v8; // r8
  unsigned int v9; // r2
  _DWORD *v10; // r4
  unsigned __int8 v11; // r6
  unsigned int v12; // r1
  unsigned int v13; // r8
  int v14; // r4
  int v15; // r9
  unsigned int v16; // r2
  unsigned int *v17; // r2
  unsigned int v18; // r0
  int *v19; // r9
  int *v20; // r3
  int *v21; // r4
  int v22; // r2
  int v23; // r0
  unsigned int *v24; // r2
  unsigned int v25; // r0
  int *v26; // r1 OVERLAPPED
  int **v27; // r2 OVERLAPPED
  int **v28; // r1
  unsigned int *v29; // r2
  unsigned int v30; // r0
  int *v31; // r1 OVERLAPPED
  int **v32; // r2 OVERLAPPED
  int v33; // r3
  _DWORD *v34; // r0
  unsigned int v35; // r4
  unsigned int v36; // r1
  int v37; // r4
  unsigned int v38; // r1
  unsigned __int8 v39; // r4
  unsigned int v40; // r1
  int *v41; // r1 OVERLAPPED
  int v45; // [sp+10h] [bp-38h] BYREF
  int v46; // [sp+14h] [bp-34h]
  int v47; // [sp+18h] [bp-30h]
  unsigned int v48; // [sp+1Ch] [bp-2Ch]
  int *v49; // [sp+20h] [bp-28h] BYREF
  int **v50; // [sp+24h] [bp-24h]
  int varg_r3; // [sp+5Ch] [bp+14h] BYREF
  va_list varg_r3a; // [sp+5Ch] [bp+14h]
  va_list va1; // [sp+60h] [bp+18h] BYREF

  va_start(va1, a3);
  va_start(varg_r3a, a3);
  varg_r3 = va_arg(va1, _DWORD);
  v3 = varg_r3;
  v4 = a3;
  v5 = a2;
  v48 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v47 = 1;
  v50 = &v49;
  v46 = 0;
  v49 = (int *)&v49;
  if ( a3 >= 0 )
  {
    v4 = 0;
  }
  else
  {
    v3 = 0;
    varg_r3 = 0;
  }
  if ( v4 >= 0 )
  {
    while ( 1 )
    {
      v46 = 1;
      v7 = KeAbPreAcquire((unsigned int)&DbgkpProcessDebugPortMutex, 0, 0);
      v8 = KfRaiseIrql(1);
      do
        v9 = __ldrex((unsigned __int8 *)&DbgkpProcessDebugPortMutex);
      while ( __strex(v9 & 0xFE, (unsigned __int8 *)&DbgkpProcessDebugPortMutex) );
      __dmb(0xBu);
      if ( (v9 & 1) == 0 )
        ExpAcquireFastMutexContended((int)&DbgkpProcessDebugPortMutex, v7);
      if ( v7 )
        *(_BYTE *)(v7 + 14) |= 1u;
      dword_631F64 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      dword_631F7C = v8;
      if ( a1[85] )
        break;
      a1[85] = v5;
      ObfReferenceObjectWithTag(v3);
      v10 = PsGetNextProcessThread((int)a1, v3);
      if ( !v10 )
        goto LABEL_22;
      a1[85] = 0;
      dword_631F64 = 0;
      v11 = dword_631F7C;
      __dmb(0xBu);
      do
        v12 = __ldrex((unsigned int *)&DbgkpProcessDebugPortMutex);
      while ( !v12 && __strex(1u, (unsigned int *)&DbgkpProcessDebugPortMutex) );
      if ( v12 )
        ExpReleaseFastMutexContended((unsigned int *)&DbgkpProcessDebugPortMutex, v12);
      KfLowerIrql(v11);
      KeAbPostRelease((unsigned int)&DbgkpProcessDebugPortMutex);
      v46 = 0;
      ObfDereferenceObjectWithTag(v3);
      v4 = DbgkpPostFakeThreadMessages((int)a1, v5, (int)v10, &v45, (int *)varg_r3a);
      if ( v4 < 0 )
      {
        v3 = 0;
        goto LABEL_22;
      }
      ObfDereferenceObjectWithTag(v45);
      v3 = varg_r3;
    }
    v4 = -1073741752;
  }
LABEL_22:
  v13 = v5 + 16;
  v14 = KeAbPreAcquire(v5 + 16, 0, 0);
  v15 = KfRaiseIrql(1);
  do
    v16 = __ldrex((unsigned __int8 *)v13);
  while ( __strex(v16 & 0xFE, (unsigned __int8 *)v13) );
  __dmb(0xBu);
  if ( (v16 & 1) == 0 )
    ExpAcquireFastMutexContended(v13, v14);
  if ( v14 )
    *(_BYTE *)(v14 + 14) |= 1u;
  *(_DWORD *)(v13 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v13 + 28) = v15;
  if ( v4 >= 0 )
  {
    if ( (*(_DWORD *)(a2 + 56) & 1) != 0 )
    {
      v4 = -1073740972;
      a1[85] = 0;
    }
    else
    {
      __dmb(0xBu);
      v17 = a1 + 48;
      do
        v18 = __ldrex(v17);
      while ( __strex(v18 | 3, v17) );
      __dmb(0xBu);
      ObfReferenceObject(a2);
    }
  }
  v19 = *(int **)(a2 + 48);
  if ( v19 != (int *)(a2 + 48) )
  {
    v20 = (int *)(a2 + 48);
    while ( 1 )
    {
      v21 = v19;
      v22 = v19[11];
      v19 = (int *)*v19;
      if ( (v22 & 4) != 0 )
        break;
LABEL_62:
      if ( v19 == v20 )
        goto LABEL_63;
    }
    if ( v21[12] != v48 )
    {
LABEL_61:
      v20 = (int *)(a2 + 48);
      goto LABEL_62;
    }
    v23 = v21[9];
    v45 = v23;
    if ( v4 < 0 )
    {
      *(_QWORD *)&v31 = *(_QWORD *)v21;
      if ( *(int **)(*v21 + 4) != v21 || *v32 != v21 )
        __fastfail(3u);
      *v32 = v31;
      v31[1] = (int)v32;
      v28 = v50;
      *v21 = (int)&v49;
      v21[1] = (int)v28;
      if ( *v28 != (int *)&v49 )
        __fastfail(3u);
    }
    else
    {
      if ( (v22 & 0x10) == 0 )
      {
        if ( v47 )
        {
          v21[11] = v22 & 0xFFFFFFFB;
          KeSetEvent(a2, 0, 0);
          v23 = v45;
          v47 = 0;
        }
        v21[12] = 0;
        __dmb(0xBu);
        v29 = (unsigned int *)(v23 + 960);
        do
          v30 = __ldrex(v29);
        while ( __strex(v30 | 0x40, v29) );
        __dmb(0xBu);
        v23 = v45;
        goto LABEL_55;
      }
      __dmb(0xBu);
      v24 = (unsigned int *)(v23 + 960);
      do
        v25 = __ldrex(v24);
      while ( __strex(v25 | 0x80, v24) );
      __dmb(0xBu);
      *(_QWORD *)&v26 = *(_QWORD *)v21;
      if ( *(int **)(*v21 + 4) != v21 || *v27 != v21 )
        __fastfail(3u);
      *v27 = v26;
      v26[1] = (int)v27;
      v28 = v50;
      *v21 = (int)&v49;
      v21[1] = (int)v28;
      if ( *v28 != (int *)&v49 )
        __fastfail(3u);
      v23 = v45;
    }
    *v28 = v21;
    v50 = (int **)v21;
LABEL_55:
    v33 = v21[11];
    if ( (v33 & 8) != 0 )
    {
      v34 = (_DWORD *)(v23 + 940);
      __pld(v34);
      v21[11] = v33 & 0xFFFFFFF7;
      v35 = *v34 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v36 = __ldrex(v34);
      while ( v36 == v35 && __strex(v35 - 2, v34) );
      if ( v36 != v35 )
        ExfReleaseRundownProtection((unsigned __int8 *)v34);
    }
    goto LABEL_61;
  }
LABEL_63:
  v37 = *(_DWORD *)(v13 + 28);
  *(_DWORD *)(v13 + 4) = 0;
  __dmb(0xBu);
  do
    v38 = __ldrex((unsigned int *)v13);
  while ( !v38 && __strex(1u, (unsigned int *)v13) );
  if ( v38 )
    ExpReleaseFastMutexContended((unsigned int *)v13, v38);
  KfLowerIrql((unsigned __int8)v37);
  KeAbPostRelease(v13);
  if ( v46 )
  {
    dword_631F64 = 0;
    v39 = dword_631F7C;
    __dmb(0xBu);
    do
      v40 = __ldrex((unsigned int *)&DbgkpProcessDebugPortMutex);
    while ( !v40 && __strex(1u, (unsigned int *)&DbgkpProcessDebugPortMutex) );
    if ( v40 )
      ExpReleaseFastMutexContended((unsigned int *)&DbgkpProcessDebugPortMutex, v40);
    KfLowerIrql(v39);
    KeAbPostRelease((unsigned int)&DbgkpProcessDebugPortMutex);
  }
  if ( v3 )
    ObfDereferenceObjectWithTag(v3);
  while ( v49 != (int *)&v49 )
  {
    *(_QWORD *)&v41 = *(_QWORD *)v49;
    if ( (int **)v49[1] != &v49 || (int *)v41[1] != v49 )
      __fastfail(3u);
    v49 = v41;
    v41[1] = (int)&v49;
    DbgkpWakeTarget();
  }
  if ( v4 >= 0 )
    DbgkpMarkProcessPeb(a1);
  return v4;
}
