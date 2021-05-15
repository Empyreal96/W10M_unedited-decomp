// EmProviderRegisterEntry 
 
int __fastcall EmProviderRegisterEntry(_DWORD *a1, unsigned int a2, int *a3, _DWORD *a4)
{
  _DWORD *v5; // r7
  int v6; // r6
  int v7; // r0
  int v8; // r8
  unsigned int v9; // r5
  _DWORD *v10; // r5
  unsigned int v11; // r4
  unsigned int v12; // r8
  unsigned int *v13; // r3
  unsigned int v14; // r4
  unsigned int v15; // r0
  _DWORD *v17; // r0
  int v18; // r1
  int v19; // r0
  _DWORD *v20; // r2
  _DWORD *v21; // r0
  _DWORD *v22; // r0
  _DWORD *v23; // r2
  _DWORD *v24; // r4
  unsigned int *v28; // [sp+Ch] [bp-24h]

  v5 = 0;
  v6 = 0;
  v7 = KeAbPreAcquire((unsigned int)&EmpDatabaseLock, 0, 0);
  v8 = v7;
  do
    v9 = __ldrex((unsigned __int8 *)&EmpDatabaseLock);
  while ( __strex(v9 | 1, (unsigned __int8 *)&EmpDatabaseLock) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&EmpDatabaseLock, v7, (unsigned int)&EmpDatabaseLock);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  if ( !a2 || !a1 || !a3 || !a4 || !*a3 || !a3[1] )
    goto LABEL_19;
  v10 = EmpSearchEntryDatabase(a2);
  if ( !v10 )
  {
    v6 = -1073741275;
    goto LABEL_20;
  }
  v11 = 0;
  v12 = a1[2];
  if ( !v12 )
  {
LABEL_19:
    v6 = -1073741811;
    goto LABEL_20;
  }
  v13 = (unsigned int *)a1[1];
  while ( 1 )
  {
    v28 = v13 + 1;
    if ( !memcmp(*v13, a2, 16) )
      break;
    ++v11;
    v13 = v28;
    if ( v11 >= v12 )
      goto LABEL_19;
  }
  v17 = (_DWORD *)ExAllocatePoolWithTag(1, 28, 1919962437);
  v5 = v17;
  if ( v17
    && (*v17 = v10, v18 = a3[1], v17[2] = v18, v19 = ExAllocatePoolWithTag(1, v18, 1919962437), (v5[1] = v19) != 0) )
  {
    memmove(v19, *a3, v5[2]);
    v20 = v5 + 5;
    v21 = (_DWORD *)a1[8];
    v5[5] = a1 + 7;
    v5[6] = v21;
    if ( (_DWORD *)*v21 != a1 + 7 )
      __fastfail(3u);
    *v21 = v20;
    a1[8] = v20;
    v22 = (_DWORD *)v10[8];
    v23 = v5 + 3;
    v5[3] = v10 + 7;
    v5[4] = v22;
    if ( (_DWORD *)*v22 != v10 + 7 )
      __fastfail(3u);
    *v22 = v23;
    v10[8] = v23;
    v24 = (_DWORD *)v10[11];
    v10[6] = v23;
    while ( v24 )
    {
      EmpQueueRuleUpdateState(*(v24 - 1), (int)v10);
      v24 = (_DWORD *)*v24;
    }
    *a4 = v5;
  }
  else
  {
    v6 = -1073741670;
  }
LABEL_20:
  __dmb(0xBu);
  do
    v14 = __ldrex((unsigned int *)&EmpDatabaseLock);
  while ( __strex(v14 - 1, (unsigned int *)&EmpDatabaseLock) );
  if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&EmpDatabaseLock);
  KeAbPostRelease((unsigned int)&EmpDatabaseLock);
  if ( v6 < 0 && v5 )
  {
    v15 = v5[1];
    if ( v15 )
      ExFreePoolWithTag(v15);
    ExFreePoolWithTag((unsigned int)v5);
  }
  return v6;
}
