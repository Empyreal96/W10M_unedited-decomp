// KsepGetShimsForDriver 
 
int __fastcall KsepGetShimsForDriver(int a1, int a2, int a3, int a4, int *a5, int *a6)
{
  int v11; // r4
  int v12; // r8
  int v13; // r9
  char *v14; // r0
  char *v15; // r7
  unsigned int v16; // r2
  int v17; // r6
  unsigned int v18; // r1
  char **v19; // r1
  unsigned int v20; // r0
  int v21; // r0
  unsigned int v22; // r1
  __int16 v23; // r3
  unsigned int v24; // r1
  unsigned int v25; // r1
  char *v26; // r3
  int v27; // [sp+8h] [bp-28h] BYREF
  int v28; // [sp+Ch] [bp-24h] BYREF
  int v29[8]; // [sp+10h] [bp-20h] BYREF

  v27 = 0;
  v28 = 0;
  v29[0] = 0;
  *a5 = 0;
  *a6 = 0;
  if ( KsepIsModuleShimmed(&KseEngine, a3, v29) )
    return sub_7CC554();
  v11 = KsepEngineGetShimsFromRegistry(&KseEngine, a1, &v27, &v28);
  if ( v11 == -1073741275 )
    v11 = KsepDbGetDriverShims(a2, a3, a4, &v27, &v28);
  v12 = v27;
  v13 = v28;
  if ( v11 < 0 )
    goto LABEL_6;
  v11 = KsepResolveApplicableShimsForDriver(v27, v28);
  if ( v11 < 0 )
  {
LABEL_12:
    if ( v12 && v13 )
      KsepDbFreeDriverShims(v12, v13);
    goto LABEL_7;
  }
  v14 = (char *)KsepPoolAllocatePaged(20);
  v15 = v14;
  if ( !v14 )
  {
    v11 = -1073741670;
    goto LABEL_12;
  }
  *((_DWORD *)v14 + 3) = v13;
  *((_DWORD *)v14 + 4) = v12;
  *((_DWORD *)v14 + 2) = a3;
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v16 + 308);
  v17 = KeAbPreAcquire((unsigned int)dword_6416EC, 0, 0);
  do
    v18 = __ldrex((unsigned __int8 *)dword_6416EC);
  while ( __strex(v18 | 1, (unsigned __int8 *)dword_6416EC) );
  __dmb(0xBu);
  if ( (v18 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(dword_6416EC, v17, (unsigned int)dword_6416EC);
  if ( v17 )
    *(_BYTE *)(v17 + 14) |= 1u;
  v19 = (char **)dword_6416E8;
  *(_DWORD *)v15 = algn_6416E4;
  *((_DWORD *)v15 + 1) = v19;
  if ( *v19 != algn_6416E4 )
    __fastfail(3u);
  *v19 = v15;
  dword_6416E8 = (int)v15;
  __dmb(0xBu);
  do
    v20 = __ldrex(dword_6416EC);
  while ( __strex(v20 - 1, dword_6416EC) );
  if ( (v20 & 2) != 0 && (v20 & 4) == 0 )
    ExfTryToWakePushLock(dword_6416EC);
  v21 = KeAbPostRelease((unsigned int)dword_6416EC);
  v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v23 = *(_WORD *)(v22 + 0x134) + 1;
  *(_WORD *)(v22 + 308) = v23;
  if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
    KiCheckForKernelApcDelivery(v21);
LABEL_6:
  *a5 = v12;
  *a6 = v13;
LABEL_7:
  if ( v11 >= 0 )
  {
    __dmb(0xBu);
    do
    {
      v24 = __ldrex(KsepHistoryMessagesIndex);
      v25 = v24 + 1;
    }
    while ( __strex(v25, KsepHistoryMessagesIndex) );
    __dmb(0xBu);
    v26 = (char *)&KsepHistoryMessages + 8 * (v25 & 0x3F);
    *((_DWORD *)v26 + 1) = 0;
    *((_WORD *)v26 + 1) = 7;
    *(_WORD *)v26 = 356;
    if ( (KsepDebugFlag & 1) != 0 )
      KsepDebugPrint(7, (int)"KSE: got shim(s) for driver [%ws]\n");
    KsepLogInfo(7, (int)"KSE: got shim(s) for driver [%ws]\n", *(_DWORD *)(a1 + 4));
  }
  return v11;
}
