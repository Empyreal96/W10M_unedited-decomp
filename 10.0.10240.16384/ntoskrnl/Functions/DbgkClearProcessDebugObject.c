// DbgkClearProcessDebugObject 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall DbgkClearProcessDebugObject(int a1, int *a2, int a3, int a4)
{
  int v6; // r5
  int v7; // r6
  unsigned int v8; // r2
  unsigned int *v9; // r5
  int v10; // r7
  unsigned int v11; // r1
  unsigned __int8 *v12; // r4
  int v13; // r6
  int v14; // r9
  unsigned int v15; // r2
  unsigned int *v16; // r0
  int *v17; // r1
  unsigned int v18; // r3
  __int64 v19; // kr00_8
  int **v20; // r6
  unsigned int v21; // r6
  unsigned int v22; // r1
  int *v23; // r0
  int *v24; // r1 OVERLAPPED
  int *v26; // [sp+0h] [bp-28h] BYREF
  int **v27; // [sp+4h] [bp-24h]
  int v28; // [sp+8h] [bp-20h]

  v26 = a2;
  v27 = (int **)a3;
  v28 = a4;
  v6 = KeAbPreAcquire((unsigned int)&DbgkpProcessDebugPortMutex, 0, 0);
  v7 = KfRaiseIrql(1);
  do
    v8 = __ldrex((unsigned __int8 *)&DbgkpProcessDebugPortMutex);
  while ( __strex(v8 & 0xFE, (unsigned __int8 *)&DbgkpProcessDebugPortMutex) );
  __dmb(0xBu);
  if ( (v8 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&DbgkpProcessDebugPortMutex, v6);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  dword_631F64 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_631F7C = v7;
  v9 = *(unsigned int **)(a1 + 340);
  if ( v9 && (v9 == (unsigned int *)a2 || !a2) )
  {
    *(_DWORD *)(a1 + 340) = 0;
    LOBYTE(v7) = dword_631F7C;
    v10 = 0;
  }
  else
  {
    v10 = -1073740973;
    v9 = 0;
  }
  dword_631F64 = 0;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&DbgkpProcessDebugPortMutex);
  while ( !v11 && __strex(1u, (unsigned int *)&DbgkpProcessDebugPortMutex) );
  if ( v11 )
    ExpReleaseFastMutexContended((unsigned int *)&DbgkpProcessDebugPortMutex, v11);
  KfLowerIrql((unsigned __int8)v7);
  KeAbPostRelease((unsigned int)&DbgkpProcessDebugPortMutex);
  if ( v10 >= 0 )
    DbgkpMarkProcessPeb(a1);
  if ( v9 )
  {
    v27 = &v26;
    v12 = (unsigned __int8 *)(v9 + 4);
    v26 = (int *)&v26;
    v13 = KeAbPreAcquire((unsigned int)(v9 + 4), 0, 0);
    v14 = KfRaiseIrql(1);
    do
      v15 = __ldrex(v12);
    while ( __strex(v15 & 0xFE, v12) );
    __dmb(0xBu);
    if ( (v15 & 1) == 0 )
      ExpAcquireFastMutexContended((int)(v9 + 4), v13);
    if ( v13 )
      *(_BYTE *)(v13 + 14) |= 1u;
    v9[5] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v9[11] = v14;
    v16 = (unsigned int *)v9[12];
    while ( v16 != v9 + 12 )
    {
      v17 = (int *)v16;
      v18 = v16[8];
      v16 = (unsigned int *)*v16;
      if ( v18 == a1 )
      {
        v19 = *(_QWORD *)v17;
        if ( *(int **)(*v17 + 4) != v17 || *(int **)HIDWORD(v19) != v17 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v19) = v19;
        *(_DWORD *)(v19 + 4) = HIDWORD(v19);
        v20 = v27;
        *v17 = (int)&v26;
        v17[1] = (int)v20;
        if ( *v20 != (int *)&v26 )
          __fastfail(3u);
        *v20 = v17;
        v27 = (int **)v17;
      }
    }
    v21 = v9[11];
    v9[5] = 0;
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)v12);
    while ( !v22 && __strex(1u, (unsigned int *)v12) );
    if ( v22 )
      ExpReleaseFastMutexContended(v9 + 4, v22);
    KfLowerIrql((unsigned __int8)v21);
    KeAbPostRelease((unsigned int)(v9 + 4));
    ObfDereferenceObject((int)v9);
    while ( 1 )
    {
      v23 = v26;
      if ( v26 == (int *)&v26 )
        break;
      *(_QWORD *)&v24 = *(_QWORD *)v26;
      if ( (int **)v26[1] != &v26 || (int *)v24[1] != v26 )
        __fastfail(3u);
      v26 = v24;
      v24[1] = (int)&v26;
      v23[10] = -1073740972;
      DbgkpWakeTarget();
    }
  }
  return v10;
}
