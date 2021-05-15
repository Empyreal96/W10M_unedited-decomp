// PnpDisableUserModeNotifications 
 
unsigned int __fastcall PnpDisableUserModeNotifications(int a1, int a2)
{
  int v2; // r5
  int v3; // r6
  unsigned int v4; // r2
  int v5; // r9
  int *v6; // r6
  int v7; // r5
  unsigned int v8; // r8
  int v9; // r7
  int v10; // r10
  unsigned int v11; // r2
  unsigned int *v12; // r7
  unsigned int v13; // r8
  unsigned int v14; // r1
  unsigned __int8 v15; // r5
  unsigned int v16; // r1
  int v18; // [sp+0h] [bp-28h]

  v2 = KeAbPreAcquire((unsigned int)&PiUEventClientRegistrationListLock, 0, 0);
  v3 = KfRaiseIrql(1);
  do
    v4 = __ldrex((unsigned __int8 *)&PiUEventClientRegistrationListLock);
  while ( __strex(v4 & 0xFE, (unsigned __int8 *)&PiUEventClientRegistrationListLock) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PiUEventClientRegistrationListLock, v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_6308E4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = 14;
  dword_6308FC = v3;
  v6 = &PiUEventDevHandleClientList;
  v18 = 14;
  do
  {
    v7 = *v6;
    if ( (int *)*v6 != v6 )
    {
      do
      {
        v8 = *(_DWORD *)(v7 + 8);
        v9 = KeAbPreAcquire(v8, 0, 0);
        v10 = KfRaiseIrql(1);
        do
          v11 = __ldrex((unsigned __int8 *)v8);
        while ( __strex(v11 & 0xFE, (unsigned __int8 *)v8) );
        __dmb(0xBu);
        if ( (v11 & 1) == 0 )
          ExpAcquireFastMutexContended(v8, v9);
        if ( v9 )
          *(_BYTE *)(v9 + 14) |= 1u;
        *(_DWORD *)(v8 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        *(_DWORD *)(v8 + 28) = v10;
        if ( *(_DWORD *)(v7 + 28) == *(_DWORD *)(a2 + 176) && *(_DWORD *)(v7 + 16) == a1 )
          *(_BYTE *)(v7 + 20) = 1;
        v12 = *(unsigned int **)(v7 + 8);
        v13 = v12[7];
        v12[1] = 0;
        __dmb(0xBu);
        do
          v14 = __ldrex(v12);
        while ( !v14 && __strex(1u, v12) );
        if ( v14 )
          ExpReleaseFastMutexContended(v12, v14);
        KfLowerIrql((unsigned __int8)v13);
        KeAbPostRelease((unsigned int)v12);
        v7 = *(_DWORD *)v7;
      }
      while ( (int *)v7 != v6 );
      v5 = v18;
    }
    v6 += 2;
    v18 = --v5;
  }
  while ( v5 );
  dword_6308E4 = 0;
  v15 = dword_6308FC;
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)&PiUEventClientRegistrationListLock);
  while ( !v16 && __strex(1u, (unsigned int *)&PiUEventClientRegistrationListLock) );
  if ( v16 )
    ExpReleaseFastMutexContended((unsigned int *)&PiUEventClientRegistrationListLock, v16);
  KfLowerIrql(v15);
  return KeAbPostRelease((unsigned int)&PiUEventClientRegistrationListLock);
}
