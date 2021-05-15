// KsepApplyShimsToDriver 
 
int __fastcall KsepApplyShimsToDriver(_DWORD *a1, int a2, int a3, unsigned int a4)
{
  int v6; // r6
  unsigned int v8; // r8
  int v9; // r2
  int v10; // r4
  void (__fastcall *v11)(int, _DWORD, _DWORD, _DWORD); // r4
  int v12; // r0
  unsigned int v13; // r2
  unsigned int v14; // r2
  char *v15; // r3
  unsigned int v16; // r2
  unsigned int v17; // r2
  char *v18; // r3
  unsigned int v19; // r1
  unsigned int v20; // r1
  _WORD *v21; // r3
  int v23; // [sp+0h] [bp-28h]

  v23 = a2;
  v6 = a3;
  if ( !a1 || !a2 || !a3 )
    return -1073741811;
  v8 = 0;
  if ( !a4 )
  {
LABEL_17:
    __dmb(0xBu);
    do
    {
      v16 = __ldrex(KsepHistoryMessagesIndex);
      v17 = v16 + 1;
    }
    while ( __strex(v17, KsepHistoryMessagesIndex) );
    __dmb(0xBu);
    v18 = (char *)&KsepHistoryMessages + 8 * (v17 & 0x3F);
    *((_DWORD *)v18 + 1) = 0;
    *((_WORD *)v18 + 1) = 7;
    *(_WORD *)v18 = 668;
    if ( (KsepDebugFlag & 1) != 0 )
      KsepDebugPrint(8, (int)"KSE: Successfully applied shims to driver [%ws]\n");
    KsepLogInfo(8, (int)"KSE: Successfully applied shims to driver [%ws]\n", *(_DWORD *)(a2 + 4));
    return 0;
  }
  while ( 1 )
  {
    v9 = *(_DWORD *)(v6 + 48);
    if ( (*(_DWORD *)(v9 + 16) & 4) == 0 )
      break;
LABEL_16:
    ++v8;
    v6 += 52;
    if ( v8 >= a4 )
      goto LABEL_17;
  }
  v10 = KsepPatchDriverImportsTable(a1, *(_DWORD *)(v9 + 8));
  if ( v10 >= 0 )
  {
    v11 = *(void (__fastcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)(*(_DWORD *)(v6 + 48) + 8) + 20);
    if ( v11 )
    {
      v23 = a1[16];
      v11(a2, a1[6], a1[8], a1[22]);
    }
    v12 = *(_DWORD *)(*(_DWORD *)(v6 + 48) + 20);
    if ( v12 )
      ObfReferenceObject(v12);
    __dmb(0xBu);
    do
    {
      v13 = __ldrex(KsepHistoryMessagesIndex);
      v14 = v13 + 1;
    }
    while ( __strex(v14, KsepHistoryMessagesIndex) );
    __dmb(0xBu);
    v15 = (char *)&KsepHistoryMessages + 8 * (v14 & 0x3F);
    *((_DWORD *)v15 + 1) = 0;
    *((_WORD *)v15 + 1) = 7;
    *(_WORD *)v15 = 664;
    if ( (KsepDebugFlag & 1) != 0 )
      KsepDebugPrint(8, (int)"KSE: Applied shim [0x%08X] to driver [%ws]\n");
    KsepLogInfo(
      8,
      (int)"KSE: Applied shim [0x%08X] to driver [%ws]\n",
      **(_DWORD **)(*(_DWORD *)(*(_DWORD *)(v6 + 48) + 8) + 4),
      *(_DWORD *)(a2 + 4),
      v23);
    goto LABEL_16;
  }
  __dmb(0xBu);
  do
  {
    v19 = __ldrex(&KsepHistoryErrorsIndex);
    v20 = v19 + 1;
  }
  while ( __strex(v20, &KsepHistoryErrorsIndex) );
  __dmb(0xBu);
  v21 = &KsepHistoryErrors[4 * (v20 & 0x3F)];
  *((_DWORD *)v21 + 1) = v10;
  v21[1] = 7;
  *v21 = 625;
  if ( (KsepDebugFlag & 2) != 0 )
    KsepDebugPrint(8, (int)"KSE: Failed to patch driver [%ws]: 0x%x\n");
  KsepLogError(8, (int)"KSE: Failed to patch driver [%ws]: 0x%x\n", *(_DWORD *)(a2 + 4), v10, v23);
  return v10;
}
