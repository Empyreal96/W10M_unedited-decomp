// PspLookupProcessQuotaBlock 
 
int __fastcall PspLookupProcessQuotaBlock(unsigned __int16 *a1, int a2, int a3, int a4)
{
  int v5; // r9
  int v6; // r0
  unsigned int v7; // r5
  int v8; // r6
  unsigned int *v9; // r4
  int v10; // r0
  int v11; // r7
  unsigned int v12; // r2
  unsigned __int16 *v13; // r3
  unsigned int v14; // r7
  unsigned int v15; // r2
  int v16; // r0
  __int16 v17; // r3
  int v19; // r0
  unsigned int v20; // r2
  unsigned int v21; // r1
  __int64 v22; // r0
  unsigned int *v23; // r2
  unsigned int v24; // r1
  unsigned int **v25; // r0
  int v26; // r2

  v5 = a3;
  v6 = PspHashKeyValue();
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = 0;
  v9 = (unsigned int *)(PspQuotaBlockTable + 12 * v6);
  if ( !a4 )
  {
    --*(_WORD *)(v7 + 308);
    v10 = KeAbPreAcquire((unsigned int)v9, 0, 0);
    v11 = v10;
    do
      v12 = __ldrex(v9);
    while ( !v12 && __strex(0x11u, v9) );
    __dmb(0xBu);
    if ( v12 )
      ExfAcquirePushLockSharedEx(v9, v10, (unsigned int)v9);
    if ( !v11 )
      goto LABEL_9;
    goto LABEL_8;
  }
  --*(_WORD *)(v7 + 308);
  v19 = KeAbPreAcquire((unsigned int)v9, 0, 0);
  v11 = v19;
  do
    v20 = __ldrex((unsigned __int8 *)v9);
  while ( __strex(v20 | 1, (unsigned __int8 *)v9) );
  __dmb(0xBu);
  if ( (v20 & 1) != 0 )
    return sub_7E8484();
  if ( v19 )
LABEL_8:
    *(_BYTE *)(v11 + 14) |= 1u;
LABEL_9:
  v13 = a1;
  if ( a1 )
  {
    v14 = v9[1];
    while ( (unsigned int *)v14 != v9 + 1 )
    {
      if ( RtlEqualSid(v13, (unsigned __int16 *)(v14 + 120)) )
      {
        v5 = a3;
        v8 = v14 - 1032;
        goto LABEL_31;
      }
      v14 = *(_DWORD *)v14;
      v13 = a1;
    }
  }
  else if ( v5 )
  {
    v8 = PspDefaultQuotaBlock;
LABEL_31:
    if ( v8 )
    {
      if ( PspSafeReferenceQuotaBlock(v8) )
      {
        __dmb(0xBu);
        v23 = (unsigned int *)(v8 + 1028);
        do
          v24 = __ldrex(v23);
        while ( __strex(v24 + 1, v23) );
        __dmb(0xBu);
      }
      else
      {
        if ( a4 && !v5 )
        {
          v22 = *(_QWORD *)(v8 + 1032);
          if ( *(_DWORD *)(v22 + 4) != v8 + 1032 || *(_DWORD *)HIDWORD(v22) != v8 + 1032 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v22) = v22;
          *(_DWORD *)(v22 + 4) = HIDWORD(v22);
          *(_DWORD *)(v8 + 1032) = 0;
        }
        v8 = 0;
      }
    }
  }
  if ( a4 )
  {
    if ( !v8 )
    {
      if ( a3 )
      {
        *(_DWORD *)(a4 + 1032) = 1;
        PspDefaultQuotaBlock = a4;
      }
      else
      {
        v25 = (unsigned int **)v9[2];
        v26 = a4 + 1032;
        *(_DWORD *)(a4 + 1032) = v9 + 1;
        *(_DWORD *)(a4 + 1036) = v25;
        if ( *v25 != v9 + 1 )
          __fastfail(3u);
        *v25 = (unsigned int *)v26;
        v9[2] = v26;
      }
    }
    __dmb(0xBu);
    do
      v21 = __ldrex(v9);
    while ( __strex(v21 - 1, v9) );
    if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
      ExfTryToWakePushLock(v9);
  }
  else
  {
    __dmb(0xBu);
    do
      v15 = __ldrex(v9);
    while ( v15 == 17 && __strex(0, v9) );
    if ( v15 != 17 )
      ExfReleasePushLockShared(v9);
  }
  v16 = KeAbPostRelease((unsigned int)v9);
  v17 = *(_WORD *)(v7 + 308) + 1;
  *(_WORD *)(v7 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
    KiCheckForKernelApcDelivery(v16);
  return v8;
}
