// PopGetSettingNotificationName 
 
int __fastcall PopGetSettingNotificationName(unsigned int a1, _DWORD *a2)
{
  int v3; // r4
  int v4; // r5
  unsigned int v5; // r2
  int v6; // r10
  int v7; // r5
  int v8; // r4
  int v9; // r8
  int v10; // r3
  int v11; // r0
  int v12; // r8
  _DWORD *v13; // r0
  _DWORD *v14; // r5
  unsigned __int8 v15; // r4
  unsigned int v16; // r1
  unsigned __int8 v17; // r5
  unsigned int v18; // r1
  int v21; // [sp+10h] [bp-28h] BYREF
  int v22; // [sp+14h] [bp-24h]

  v3 = KeAbPreAcquire((unsigned int)&PopSettingLock, 0, 0);
  v4 = KfRaiseIrql(1);
  do
    v5 = __ldrex((unsigned __int8 *)&PopSettingLock);
  while ( __strex(v5 & 0xFE, (unsigned __int8 *)&PopSettingLock) );
  __dmb(0xBu);
  if ( (v5 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PopSettingLock, v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  dword_61F324 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_61F33C = v4;
  v6 = 1;
  if ( a1 )
  {
    v7 = *(_DWORD *)(a1 + 16);
  }
  else
  {
    a1 = 0;
    v7 = -1;
  }
  if ( !a1 )
  {
    if ( !PopPopPowerSettingSetChangeNotification && !dword_641D98 )
    {
      v8 = PopCreateNotificationName(&v21);
      v9 = 0;
      if ( v8 < 0 )
        goto LABEL_45;
      PopPopPowerSettingSetChangeNotification = v21;
      dword_641D98 = v22;
      goto LABEL_38;
    }
    v21 = PopPopPowerSettingSetChangeNotification;
    v10 = dword_641D98;
    goto LABEL_37;
  }
  if ( PopStateIsSessionSpecific(a1) )
  {
    v11 = PsGetProcessSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
    v12 = v11;
    if ( v7 == -1 || v7 == v11 )
    {
      if ( !v11 || v11 == -1 )
      {
        v8 = -1073741811;
        goto LABEL_44;
      }
      v7 = v11;
    }
    else
    {
      v8 = PopValidateContextMembership(SeLocalSystemSid);
      if ( v8 < 0 )
      {
        if ( v12 )
          goto LABEL_44;
        v8 = PopValidateContextMembership(*(_DWORD *)(SeExports + 296));
        if ( v8 < 0 )
          goto LABEL_44;
      }
    }
  }
  else
  {
    v7 = -1;
  }
  v13 = PopFindPowerSettingConfiguration(a1, v7);
  v14 = v13;
  if ( !v13 )
  {
    v8 = -1073741275;
    goto LABEL_44;
  }
  if ( !v13[10] && !v13[11] )
  {
    v8 = PopCreateNotificationName(&v21);
    if ( v8 >= 0 )
    {
      if ( !memcmp(a1, (unsigned int)&GUID_ACDC_POWER_SOURCE, 16) )
        v14[9] |= 8u;
      v14[10] = v21;
      v14[11] = v22;
      v14[9] |= 1u;
      v9 = 1;
      goto LABEL_38;
    }
LABEL_44:
    v9 = 0;
    goto LABEL_45;
  }
  v21 = v13[10];
  v10 = v13[11];
LABEL_37:
  v9 = 0;
  v22 = v10;
LABEL_38:
  dword_61F324 = 0;
  v15 = dword_61F33C;
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)&PopSettingLock);
  while ( !v16 && __strex(1u, (unsigned int *)&PopSettingLock) );
  if ( v16 )
    ExpReleaseFastMutexContended((unsigned int *)&PopSettingLock, v16);
  KfLowerIrql(v15);
  KeAbPostRelease((unsigned int)&PopSettingLock);
  v6 = 0;
  *a2 = v21;
  a2[1] = v22;
  v8 = 0;
LABEL_45:
  if ( v6 )
  {
    dword_61F324 = 0;
    v17 = dword_61F33C;
    __dmb(0xBu);
    do
      v18 = __ldrex((unsigned int *)&PopSettingLock);
    while ( !v18 && __strex(1u, (unsigned int *)&PopSettingLock) );
    if ( v18 )
      ExpReleaseFastMutexContended((unsigned int *)&PopSettingLock, v18);
    KfLowerIrql(v17);
    KeAbPostRelease((unsigned int)&PopSettingLock);
  }
  if ( v9 )
    PopSetNotificationWork(128);
  return v8;
}
