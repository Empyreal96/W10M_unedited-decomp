// KsepShimDbChanged 
 
int KsepShimDbChanged()
{
  unsigned int v0; // r2
  int v1; // r0
  unsigned int v2; // r2
  int v4; // r6
  int v5; // r0
  int v6; // r0
  int v7; // r3
  unsigned int v8; // r1
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3
  unsigned int v12; // r1
  unsigned int v13; // r1
  char *v14; // r3
  const char *v15; // r1
  unsigned int v16; // r1
  unsigned int v17; // r1
  char *v18; // r3
  char v19[8]; // [sp+30h] [bp-48h] BYREF
  __int64 v20; // [sp+48h] [bp-30h]

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&KsepShimDbLock, 0, 0);
  do
    v2 = __ldrex((unsigned __int8 *)&KsepShimDbLock);
  while ( __strex(v2 | 1, (unsigned __int8 *)&KsepShimDbLock) );
  __dmb(0xBu);
  if ( (v2 & 1) != 0 )
    return sub_519200(v1);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  v4 = 0;
  RtlInitUnicodeString((unsigned int)v19, L"\\SystemRoot\\AppPatch\\drvmain.sdb");
  v5 = ZwOpenFile();
  if ( v5 < 0 )
  {
    __dmb(0xBu);
    do
    {
      v12 = __ldrex(&KsepHistoryErrorsIndex);
      v13 = v12 + 1;
    }
    while ( __strex(v13, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v14 = (char *)&KsepHistoryErrors + 8 * (v13 & 0x3F);
    *((_DWORD *)v14 + 1) = v5;
    *((_WORD *)v14 + 1) = 9;
    *(_WORD *)v14 = 717;
    if ( (KsepDebugFlag & 2) != 0 )
      KsepDebugPrint(0, "KSE: ZwOpenFile failed opening DB file!\n");
    v15 = "KSE: ZwOpenFile failed opening DB file!\n";
    goto LABEL_26;
  }
  v6 = ZwQueryInformationFile();
  if ( v6 < 0 )
  {
    __dmb(0xBu);
    do
    {
      v16 = __ldrex(&KsepHistoryErrorsIndex);
      v17 = v16 + 1;
    }
    while ( __strex(v17, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v18 = (char *)&KsepHistoryErrors + 8 * (v17 & 0x3F);
    *((_DWORD *)v18 + 1) = v6;
    *((_WORD *)v18 + 1) = 9;
    *(_WORD *)v18 = 730;
    if ( (KsepDebugFlag & 2) != 0 )
      KsepDebugPrint(0, "KSE: ZwQueryInformationFile failed getting DB file!\n");
    v15 = "KSE: ZwQueryInformationFile failed getting DB file!\n";
LABEL_26:
    KsepLogError(0, v15);
    goto LABEL_11;
  }
  if ( KsepSdbFileTime )
  {
    v7 = HIDWORD(v20);
    if ( v20 == KsepSdbFileTime )
      goto LABEL_11;
    LODWORD(KsepSdbFileTime) = v20;
    v4 = 1;
  }
  else
  {
    v7 = HIDWORD(v20);
    LODWORD(KsepSdbFileTime) = v20;
  }
  HIDWORD(KsepSdbFileTime) = v7;
LABEL_11:
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&KsepShimDbLock);
  while ( __strex(v8 - 1, (unsigned int *)&KsepShimDbLock) );
  if ( (v8 & 2) != 0 && (v8 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&KsepShimDbLock);
  v9 = KeAbPostRelease((unsigned int)&KsepShimDbLock);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v9);
  return v4;
}
