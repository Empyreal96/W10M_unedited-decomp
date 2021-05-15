// PopSetPowerSettingValue 
 
int __fastcall PopSetPowerSettingValue(int *a1, int a2, int a3, unsigned int a4, int a5)
{
  _DWORD *v6; // r7
  int v8; // r0
  _DWORD *v9; // r4
  int v10; // r5
  int v12; // r1
  int v13; // r2
  int v14; // r3
  _DWORD *v15; // r6
  int v16; // r8
  int *v17; // r4
  int *v18; // r3
  int v19; // r10
  int v20; // r2
  int *v21; // r8
  int v22; // r4
  int i; // r6
  _DWORD *v24; // r4
  int v25; // r0
  int *j; // r2
  int *v27; // r0
  int *v28; // r5
  _BYTE *v29; // r0
  int v30; // r4
  int v31; // r6
  unsigned int v32; // r2
  int **v33; // r2
  int v34; // r2
  __int64 v35; // kr00_8
  int *v36; // r1
  int v37; // r7
  unsigned __int8 v38; // r4
  unsigned int v39; // r1
  unsigned int v40; // r2
  unsigned int v41; // r2
  int v43; // [sp+14h] [bp-3Ch]
  unsigned int v45; // [sp+1Ch] [bp-34h]
  int *v46; // [sp+20h] [bp-30h]
  int v47; // [sp+24h] [bp-2Ch]
  int v48; // [sp+28h] [bp-28h]
  int v49; // [sp+2Ch] [bp-24h]
  int v50; // [sp+30h] [bp-20h]

  v6 = 0;
  v49 = 0;
  v50 = 0;
  v48 = 0;
  if ( (PoDebug & 0x800) == 0 )
  {
    v8 = ExAllocatePoolWithTag(1, a4, 1952797520);
    v9 = (_DWORD *)v8;
    v45 = v8;
    if ( !v8 )
      return -1073741670;
    memmove(v8, a5, a4);
    PopValidatePowerSettingData((unsigned int)a1, a4, v9);
    v47 = PopStateIsSessionSpecific(a1);
    v30 = KeAbPreAcquire((unsigned int)&PopSettingLock, 0, 0);
    v31 = KfRaiseIrql(1);
    do
      v32 = __ldrex((unsigned __int8 *)&PopSettingLock);
    while ( __strex(v32 & 0xFE, (unsigned __int8 *)&PopSettingLock) );
    __dmb(0xBu);
    if ( (v32 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&PopSettingLock, v30);
    if ( v30 )
      *(_BYTE *)(v30 + 14) |= 1u;
    dword_61F324 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_61F33C = v31;
    v28 = (int *)PopFindPowerSettingConfiguration(a1, a2);
    v46 = v28;
    if ( !v28 )
    {
      if ( (PoDebug & 0x800) != 0 )
        DbgPrint("PopSetPowerSettingValue: Creating new setting with empty values.\n");
      v27 = (int *)ExAllocatePoolWithTag(1, 60, 1952797520);
      v28 = v27;
      v46 = v27;
      if ( !v27 )
        goto LABEL_46;
      memset(v27, 0, 60);
      v12 = a1[1];
      v13 = a1[2];
      v14 = a1[3];
      v28[4] = *a1;
      v28[5] = v12;
      v28[6] = v13;
      v28[7] = v14;
      v15 = v28 + 2;
      v16 = PopGetListHead(a1);
      v28[2] = (int)(v28 + 2);
      v28[3] = (int)(v28 + 2);
      if ( v47 )
      {
        v28[8] = a2;
      }
      else
      {
        v17 = (int *)PopRegisteredPowerSettingCallbacks;
        while ( v17 != &PopRegisteredPowerSettingCallbacks )
        {
          v18 = v17;
          v17 = (int *)*v17;
          if ( !memcmp((unsigned int)(v18 + 5), (unsigned int)a1, 16) )
          {
            v34 = v17[1];
            v35 = *(_QWORD *)v34;
            if ( *(int **)v34 != v17 || *(_DWORD *)HIDWORD(v35) != v34 )
              __fastfail(3u);
            v17[1] = HIDWORD(v35);
            *(_DWORD *)HIDWORD(v35) = v17;
            v36 = (int *)v28[3];
            *(_DWORD *)v34 = v15;
            *(_DWORD *)(v34 + 4) = v36;
            if ( (_DWORD *)*v36 != v15 )
              __fastfail(3u);
            *v36 = v34;
            v28[3] = v34;
          }
        }
        v28[8] = -1;
      }
      v33 = *(int ***)(v16 + 4);
      *v28 = v16;
      v28[1] = (int)v33;
      if ( *v33 != (int *)v16 )
        __fastfail(3u);
      *v33 = v28;
      *(_DWORD *)(v16 + 4) = v28;
      v48 = 1;
      if ( PopPopPowerSettingSetChangeNotification || dword_641D98 )
        v49 = 1;
    }
    v19 = v28[a3 + 12];
    if ( PopArePowerSettingsEqual(v19, v45, a4) )
    {
      if ( (PoDebug & 0x800) != 0 )
        DbgPrint("PopSetPowerSettingValue: Setting value didn't change.\n");
    }
    else
    {
      v20 = 0;
      v21 = v28;
      v22 = a3;
      v43 = 0;
      for ( i = 0; i < 3; ++i )
      {
        if ( i != v22 )
        {
          if ( !v6 )
          {
            v24 = (_DWORD *)v21[12];
            v25 = PopArePowerSettingsEqual(v24, v45, a4);
            v20 = v43;
            if ( v25 )
            {
              v6 = v24;
              ++*v24;
            }
            v22 = a3;
          }
          if ( v21[12] == v19 )
          {
            v20 = 1;
            v43 = 1;
          }
        }
        ++v21;
      }
      if ( !v6 )
      {
        if ( (PoDebug & 0x800) != 0 )
          DbgPrint("PopSetPowerSettingValue: Allocating new value.\n");
        v29 = (_BYTE *)ExAllocatePoolWithTag(1, a4 + 12, 1952797520);
        v6 = v29;
        if ( !v29 )
        {
LABEL_46:
          v10 = -1073741670;
LABEL_78:
          v37 = 0;
          goto LABEL_79;
        }
        memset(v29, 0, a4 + 12);
        *v6 = 1;
        v6[1] = a4;
        do
        {
          __dmb(0xBu);
          do
          {
            v40 = __ldrex(&PopPowerSettingChangeStamp);
            v41 = v40 + 1;
          }
          while ( __strex(v41, &PopPowerSettingChangeStamp) );
          __dmb(0xBu);
        }
        while ( !v41 );
        v6[2] = v41;
        memmove((int)(v6 + 3), v45, a4);
        v20 = v43;
      }
      if ( v19 )
      {
        if ( !v20 )
        {
          for ( j = (int *)v46[2]; j != v46 + 2; j = (int *)*j )
          {
            if ( j[9] == v19 )
              j[9] = 0;
          }
        }
        PopUnreferencePowerSetting(v19);
      }
      v46[v22 + 12] = (int)v6;
      if ( dword_61EC0C == v22 && !v47 )
        v50 = 1;
      if ( v46[10] || v46[11] )
      {
        v37 = 1;
        v46[9] |= 1u;
        v10 = 0;
LABEL_79:
        dword_61F324 = 0;
        v38 = dword_61F33C;
        __dmb(0xBu);
        do
          v39 = __ldrex((unsigned int *)&PopSettingLock);
        while ( !v39 && __strex(1u, (unsigned int *)&PopSettingLock) );
        if ( v39 )
          ExpReleaseFastMutexContended((unsigned int *)&PopSettingLock, v39);
        KfLowerIrql(v38);
        KeAbPostRelease((unsigned int)&PopSettingLock);
        if ( v48 )
          PoRegisterPowerSettingCallback(0, a1, PopTracePowerSettingChange, 0, 0);
        ExFreePoolWithTag(v45);
        if ( (unsigned int)PopOsInitPhase >= 3 )
        {
          if ( v49 )
            ZwUpdateWnfStateData();
          if ( v50 )
            PopSetNotificationWork(32);
          if ( v37 )
            PopSetNotificationWork(128);
        }
        return v10;
      }
    }
    v10 = 0;
    goto LABEL_78;
  }
  return sub_7C3910();
}
