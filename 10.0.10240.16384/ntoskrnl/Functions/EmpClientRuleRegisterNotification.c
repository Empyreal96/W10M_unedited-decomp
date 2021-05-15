// EmpClientRuleRegisterNotification 
 
int __fastcall EmpClientRuleRegisterNotification(int a1, unsigned int *a2, unsigned int a3, int **a4)
{
  int *v5; // r6
  int v6; // r7
  int v7; // r0
  int v8; // r9
  unsigned int v9; // r5
  unsigned int *v10; // r4
  _BYTE *v11; // r0
  unsigned int v12; // r9
  _DWORD *v13; // r0
  int v14; // r5
  unsigned int *v15; // r0
  int v16; // r1
  _DWORD *v17; // r2
  _DWORD *v18; // r3
  unsigned int v19; // r2
  unsigned int v20; // r2
  int v21; // r4
  unsigned int *v22; // r2
  unsigned int v23; // r0
  unsigned int v24; // r1
  int v27; // [sp+0h] [bp-30h]

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
  if ( a4 )
  {
    if ( a3 )
    {
      v10 = a2;
      if ( a2 )
      {
        v5 = (int *)ExAllocatePoolWithTag(1, 12, 1818447173);
        if ( !v5 )
        {
          v6 = -1073741670;
          goto LABEL_42;
        }
        v11 = (_BYTE *)ExAllocatePoolWithTag(1, 20 * a3, 1818447173);
        v5[1] = (int)v11;
        if ( !v11 )
        {
          v6 = -1073741670;
          goto LABEL_31;
        }
        memset(v11, 0, 20 * a3);
        v5[2] = a3;
        v12 = 0;
        v27 = 0;
        while ( *v10 && v10[1] )
        {
          v13 = EmpSearchRuleDatabase(*v10);
          v14 = (int)v13;
          if ( !v13 || (v15 = EmpSearchTargetRuleList((int)v13)) == 0 )
          {
            v6 = -1073741275;
            goto LABEL_31;
          }
          v16 = v27;
          *(_DWORD *)(v5[1] + v27) = v15;
          *(_DWORD *)(v5[1] + v27 + 4) = v10[1];
          *(_DWORD *)(v5[1] + v27 + 8) = v10[2];
          v17 = (_DWORD *)(v5[1] + v27 + 12);
          v18 = *(_DWORD **)(v14 + 60);
          *v17 = v14 + 56;
          v17[1] = v18;
          if ( *v18 != v14 + 56 )
            __fastfail(3u);
          *v18 = v17;
          *(_DWORD *)(v14 + 60) = v17;
          __dmb(0xBu);
          do
          {
            v19 = __ldrex(v15);
            v20 = v19 + 1;
          }
          while ( __strex(v20, v15) );
          __dmb(0xBu);
          if ( v20 == 1 )
          {
            EmpQueueRuleUpdateState(v14, 0);
            v16 = v27;
          }
          ++v12;
          v10 += 3;
          v27 = v16 + 20;
          if ( v12 >= a3 )
          {
            if ( a1 )
              ObfReferenceObject(a1);
            *v5 = a1;
            *a4 = v5;
            goto LABEL_42;
          }
        }
      }
    }
  }
  v6 = -1073741811;
LABEL_31:
  if ( v5 )
  {
    if ( v5[1] )
    {
      if ( a3 )
      {
        v21 = 0;
        do
        {
          if ( *(_DWORD *)(v21 + v5[1]) )
          {
            __dmb(0xBu);
            v22 = *(unsigned int **)(v21 + v5[1]);
            do
              v23 = __ldrex(v22);
            while ( __strex(v23 - 1, v22) );
            __dmb(0xBu);
          }
          v21 += 20;
          --a3;
        }
        while ( a3 );
      }
      ExFreePoolWithTag(v5[1]);
    }
    ExFreePoolWithTag((unsigned int)v5);
  }
LABEL_42:
  __dmb(0xBu);
  do
    v24 = __ldrex((unsigned int *)&EmpDatabaseLock);
  while ( __strex(v24 - 1, (unsigned int *)&EmpDatabaseLock) );
  if ( (v24 & 2) != 0 && (v24 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&EmpDatabaseLock);
  KeAbPostRelease((unsigned int)&EmpDatabaseLock);
  return v6;
}
