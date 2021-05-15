// CmpRefreshHive 
 
int __fastcall CmpRefreshHive(int a1, int a2, int a3, int a4)
{
  int v5; // r2
  int v6; // r5
  int i; // r4
  int v8; // r2
  int v9; // r3
  int v10; // r3
  int *v11; // r1
  int v12; // r3
  int v13; // r7
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r2
  unsigned int v18; // r2
  int v20[6]; // [sp+8h] [bp-18h] BYREF

  v20[1] = a4;
  v20[0] = -1;
  v5 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v5, (int)&SeTcbPrivilege) )
    return -1073741727;
  for ( i = *(_DWORD *)(a1 + 20); ; CmpWaitOnHiveWriteQueue(i, v11, 0) )
  {
    CmpLockRegistryFreezeAware(1);
    ExAcquireResourceExclusiveLite(*(_DWORD *)(i + 1872), 1, v8, v9);
    if ( (*(_DWORD *)(a1 + 4) & 0x20000) != 0 )
    {
      v6 = -1073741535;
      ExReleaseResourceLite(*(_DWORD *)(i + 1872));
      goto LABEL_25;
    }
    v10 = *(_DWORD *)(i + 3312);
    if ( (v10 & 2) != 0 )
    {
      v11 = (int *)(i + 3300);
      continue;
    }
    if ( (v10 & 1) == 0 )
      break;
    v11 = (int *)(i + 3288);
  }
  ExReleaseResourceLite(*(_DWORD *)(i + 1872));
  if ( *(_BYTE *)(i + 2532) == 1 )
  {
    v6 = -1073741431;
    goto LABEL_25;
  }
  if ( (*(_DWORD *)(i + 92) & 2) == 0 )
    goto LABEL_13;
  if ( *(_DWORD *)(i + 1364) )
  {
    v6 = -1073741823;
  }
  else
  {
    if ( (*(_WORD *)(a1 + 106) & 4) == 0 )
    {
LABEL_13:
      v6 = -1073741811;
      goto LABEL_25;
    }
    while ( 1 )
    {
      v12 = *(_DWORD *)(i + 1800);
      if ( !v12 )
        break;
      CmpFlushNotify(*(_DWORD *)(v12 + 20), 1, 0);
    }
    CmpSearchKeyControlBlockTree((int (__fastcall *)(int, int, int))CmpRefreshWorkerRoutine, i, 0);
    v6 = HvRefreshHive(i);
    if ( v6 >= 0 )
    {
      v13 = (*(int (__fastcall **)(int, _DWORD, int *))(i + 4))(i, *(_DWORD *)(*(_DWORD *)(i + 32) + 36), v20);
      if ( v13 )
      {
        CmpCleanUpKcbValueCache(a1);
        *(_DWORD *)(a1 + 52) = *(_DWORD *)(v13 + 36);
        *(_DWORD *)(a1 + 56) = *(_DWORD *)(v13 + 40);
        *(_WORD *)(a1 + 106) = *(_WORD *)(v13 + 2);
        CmpAssignSecurityToKcb(a1, *(_DWORD *)(v13 + 44), 0, 0);
        CmpCleanUpSubKeyInfo((_DWORD *)a1, v14, v15, v16);
        v17 = *(_DWORD *)(a1 + 104);
        *(_DWORD *)(a1 + 88) = *(_DWORD *)(v13 + 4);
        *(_DWORD *)(a1 + 92) = *(_DWORD *)(v13 + 8);
        *(_WORD *)(a1 + 96) = *(_DWORD *)(v13 + 52);
        *(_WORD *)(a1 + 98) = *(_DWORD *)(v13 + 60);
        *(_DWORD *)(a1 + 100) = *(_DWORD *)(v13 + 64);
        v18 = v17 & 0xFFFFFFF0 | *(_WORD *)(v13 + 54) & 0xF;
        *(_DWORD *)(a1 + 104) = v18;
        *(_DWORD *)(a1 + 104) = ((unsigned __int8)*(_WORD *)(v13 + 54) ^ (unsigned __int8)v18) & 0xF0 ^ v18;
        *(_BYTE *)(a1 + 105) = *(_BYTE *)(v13 + 55);
        *(_WORD *)(a1 + 4) = 64;
        (*(void (__fastcall **)(int, int *))(i + 8))(i, v20);
      }
      else
      {
        v6 = -1073741670;
      }
    }
  }
LABEL_25:
  CmpUnlockRegistry();
  return v6;
}
