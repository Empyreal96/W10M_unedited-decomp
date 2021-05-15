// sub_54CEB8 
 
// local variable allocation has failed, the output may be wrong!
void sub_54CEB8()
{
  int ***v0; // r8
  unsigned int v1; // r2
  int v2; // r0
  int v3; // r4
  unsigned int v4; // r2
  int **v5; // r3
  int *i; // r5
  int *v7; // r9
  unsigned __int8 *v8; // r4
  unsigned int v9; // r2
  int v10; // r0
  int v11; // r6
  unsigned int v12; // r2
  __int64 v13; // kr00_8
  unsigned int v14; // r6
  int v15; // r3
  int *j; // r1
  int v17; // r3
  unsigned int v18; // r3
  unsigned int v19; // r1
  int v20; // r0
  unsigned int v21; // r1
  int v22; // r3
  int *v23; // r1 OVERLAPPED
  int **v24; // r2 OVERLAPPED
  unsigned int v25; // r1
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  unsigned int v29; // r1
  int v30; // r0
  unsigned int v31; // r1
  int v32; // r3

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 308);
  v2 = KeAbPreAcquire((unsigned int)&LowboxSessionMapLock, 0, 0);
  v3 = v2;
  do
    v4 = __ldrex((unsigned __int8 *)&LowboxSessionMapLock);
  while ( __strex(v4 | 1, (unsigned __int8 *)&LowboxSessionMapLock) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&LowboxSessionMapLock, v2, (unsigned int)&LowboxSessionMapLock);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v5 = *v0;
  for ( i = **v0; ; i = v7 )
  {
    if ( i == (int *)v5 )
    {
      __dmb(0xBu);
      do
        v29 = __ldrex((unsigned int *)&LowboxSessionMapLock);
      while ( __strex(v29 - 1, (unsigned int *)&LowboxSessionMapLock) );
      if ( (v29 & 2) != 0 && (v29 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)&LowboxSessionMapLock);
      v30 = KeAbPostRelease((unsigned int)&LowboxSessionMapLock);
      v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v32 = (__int16)(*(_WORD *)(v31 + 0x134) + 1);
      *(_WORD *)(v31 + 308) = v32;
      if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 && !*(_WORD *)(v31 + 310) )
        KiCheckForKernelApcDelivery(v30);
      JUMPOUT(0x4D6FBE);
    }
    v7 = (int *)*i;
    v8 = (unsigned __int8 *)(i + 3);
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v9 + 308);
    v10 = KeAbPreAcquire((unsigned int)(i + 3), 0, 0);
    v11 = v10;
    do
      v12 = __ldrex(v8);
    while ( __strex(v12 | 1, v8) );
    __dmb(0xBu);
    if ( (v12 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(i + 3, v10, (unsigned int)(i + 3));
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    v13 = *((_QWORD *)i + 2);
    v14 = v13 - 1;
    if ( !(_DWORD)v13 )
      goto LABEL_31;
    v15 = *(_DWORD *)HIDWORD(v13);
    for ( j = (int *)i[5]; ; v15 = *j )
    {
      v17 = ~v15;
      if ( v17 != -1 )
        break;
      if ( (unsigned int)++j > HIDWORD(v13) + 4 * (v14 >> 5) )
        goto LABEL_31;
    }
    v18 = __clz(__rbit(~(_DWORD)v13)) + 32 * (((int)j - HIDWORD(v13)) >> 2);
    if ( v18 > v14 || v18 == -1 )
    {
LABEL_31:
      RtlDeleteHashTable(i[6]);
      ExFreePoolWithTag(i[5], 0);
      *(_QWORD *)&v23 = *(_QWORD *)i;
      if ( *(int **)(*i + 4) != i || *v24 != i )
        __fastfail(3u);
      *v24 = v23;
      v23[1] = (int)v24;
      __dmb(0xBu);
      do
        v25 = __ldrex((unsigned int *)v8);
      while ( __strex(v25 - 1, (unsigned int *)v8) );
      if ( (v25 & 2) != 0 && (v25 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)i + 3);
      v26 = KeAbPostRelease((unsigned int)(i + 3));
      v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v28 = *(_WORD *)(v27 + 0x134) + 1;
      *(_WORD *)(v27 + 308) = v28;
      if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
        KiCheckForKernelApcDelivery(v26);
      ExFreePoolWithTag(i, 0);
    }
    else
    {
      __dmb(0xBu);
      do
        v19 = __ldrex((unsigned int *)v8);
      while ( __strex(v19 - 1, (unsigned int *)v8) );
      if ( (v19 & 2) != 0 && (v19 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)i + 3);
      v20 = KeAbPostRelease((unsigned int)(i + 3));
      v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v22 = (__int16)(*(_WORD *)(v21 + 0x134) + 1);
      *(_WORD *)(v21 + 308) = v22;
      if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
        KiCheckForKernelApcDelivery(v20);
    }
    v5 = *v0;
  }
}
