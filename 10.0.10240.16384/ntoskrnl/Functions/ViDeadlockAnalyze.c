// ViDeadlockAnalyze 
 
int __fastcall ViDeadlockAnalyze(int a1, int a2, int a3, unsigned int a4, int a5)
{
  unsigned int v5; // r4
  int v7; // r10
  _DWORD *v8; // r7
  int v9; // r4
  _DWORD *v10; // r1
  int v11; // r2
  int v12; // r4
  int v13; // r2
  unsigned int v14; // r3
  unsigned int v15; // r2
  int *v16; // r0
  _DWORD *v17; // r5
  int v18; // r2
  int v19; // r0
  _DWORD *v20; // r9
  _DWORD *v21; // r10
  _DWORD *v22; // r7
  int v23; // r1
  unsigned int v24; // r3
  int v25; // r7
  unsigned int v26; // r2
  int v28; // [sp+0h] [bp-30h]

  v5 = a4;
  v7 = a1;
  if ( a3 )
  {
    v8 = (_DWORD *)ViDeadlockGlobals;
    v9 = *(_DWORD *)(ViDeadlockGlobals + 16420);
    *(_DWORD *)(ViDeadlockGlobals + 16412) = 0;
    v8[4117] = 0;
    v8[4118] = 0;
    v8[4105] = v9 + 1;
    if ( v9 == 1073741821 )
      ViDeadlockState |= 8u;
    KeQueryCurrentStackInformation(v8 + 4152, v8 + 4153, v8 + 4154, 16608);
    v5 = a4;
  }
  v10 = (_DWORD *)ViDeadlockGlobals;
  v11 = *(_DWORD *)(ViDeadlockGlobals + 16420);
  if ( *(_DWORD *)(a2 + 36) >> 3 == v11 )
    return 0;
  ++*(_DWORD *)(ViDeadlockGlobals + 16412);
  *(_DWORD *)(a2 + 36) = *(_DWORD *)(a2 + 36) & 7 | (8 * v11);
  if ( v5 > v10[4106] )
  {
    v13 = 4108;
LABEL_9:
    ++v10[v13];
    return 0;
  }
  v14 = v10[4107];
  v15 = v10[4103];
  if ( v15 >= v14 )
  {
    v13 = 4109;
    goto LABEL_9;
  }
  v16 = KeGetCurrentStackPointer(16412, (int)v10, v15, v14, v28);
  v17 = (_DWORD *)ViDeadlockGlobals;
  if ( (unsigned int)v16 - *(_DWORD *)(ViDeadlockGlobals + 16612) <= 0x8D0 )
  {
    ++*(_DWORD *)(ViDeadlockGlobals + 16440);
    return 0;
  }
  v18 = *(_DWORD *)(a2 + 28);
  v19 = a5;
  if ( v7 == *(_DWORD *)(v18 + 8) && (*(_DWORD *)(a2 + 36) & 4) == 0 )
  {
    v12 = 1;
    ViDeadlockAddParticipant(a2);
    goto LABEL_30;
  }
  v20 = *(_DWORD **)(v18 + 16);
  v21 = (_DWORD *)(v18 + 16);
  v12 = 0;
  if ( v20 == (_DWORD *)(v18 + 16) )
    goto LABEL_34;
  while ( 1 )
  {
    v22 = v20 - 5;
    v23 = *(v20 - 5);
    v20[4] = v20[4] & 7 | (8 * v17[4105]);
    if ( v23 )
      break;
LABEL_23:
    v20 = (_DWORD *)*v20;
    if ( v20 == v21 )
      goto LABEL_28;
  }
  v24 = a4;
  if ( v22 != (_DWORD *)a2 )
    v24 = a4 + 1;
  v12 = ViDeadlockAnalyze(a1, v23, 0, v24, v19);
  if ( !v12 )
  {
    v17 = (_DWORD *)ViDeadlockGlobals;
    v19 = a5;
    goto LABEL_23;
  }
  ViDeadlockAddParticipant((int)(v20 - 5));
  if ( v22 != (_DWORD *)a2 )
    ViDeadlockAddParticipant(a2);
  v17 = (_DWORD *)ViDeadlockGlobals;
LABEL_28:
  if ( !v12 )
  {
LABEL_34:
    v25 = a3;
    goto LABEL_35;
  }
  v7 = a1;
LABEL_30:
  v25 = a3;
  if ( a3 )
  {
    if ( ViDeadlockCertify(a5, a2) )
    {
      v17[4117] = v7;
      ViDeadlockPreprocessOptions(
        &dword_6187F4,
        "Type !deadlock in the debugger for more information.",
        4097,
        v7,
        a2,
        0);
      VfReportIssueWithOptions(196, 4097, v7, a2, 0, &dword_6187F4);
      return 0;
    }
    v12 = 0;
LABEL_35:
    if ( v25 )
    {
      v26 = v17[4103];
      if ( v26 > v17[4104] )
        v17[4104] = v26;
    }
  }
  return v12;
}
