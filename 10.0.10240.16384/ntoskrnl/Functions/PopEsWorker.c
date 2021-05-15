// PopEsWorker 
 
int PopEsWorker()
{
  int v0; // r6
  int result; // r0
  int v2; // r1
  int v3; // r7
  unsigned int v4; // r2
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r4
  unsigned int v8; // r2
  unsigned int v9; // r2
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r2
  unsigned int v13; // r2
  unsigned int v14; // r6
  unsigned __int64 v15; // kr00_8
  int v16; // r2
  int v17; // r1
  unsigned int v18; // r0
  unsigned int v19; // r2
  unsigned int v20; // r1
  int v21; // r3
  unsigned int v22; // r0
  unsigned int v23; // r2
  int v24; // r0
  int v25; // r4
  unsigned int v26; // r2
  unsigned int v27; // r1
  int v28; // r1
  unsigned int v29; // r0
  unsigned int v30; // r2
  int v31; // r0
  unsigned int v32; // r1
  __int16 v33; // r3
  int v34; // [sp+18h] [bp-48h]
  char v35[12]; // [sp+20h] [bp-40h] BYREF
  int v36; // [sp+2Ch] [bp-34h]

  while ( 1 )
  {
    v0 = 0;
    __dmb(0xBu);
    do
      result = __ldrex(&PopEsWorkItemDue);
    while ( __strex(result, &PopEsWorkItemDue) );
    __dmb(0xBu);
    v2 = 1 << __clz(__rbit(result));
    v3 = result & ~v2;
    if ( (v3 & 8) != 0 )
      break;
LABEL_4:
    if ( v2 == 2 )
      v3 &= 0xFFFFFFFB;
    __dmb(0xBu);
    do
      v4 = __ldrex(&PopEsWorkItemDue);
    while ( v4 == result && __strex(v3, &PopEsWorkItemDue) );
    __dmb(0xBu);
    if ( v4 != result )
      goto LABEL_19;
    switch ( v2 )
    {
      case 1:
        v34 = (v34 | 1) & 0x800001 | (2 * (PopEsState == 1));
        ZwUpdateWnfStateData();
        PopSetPowerSettingValueAcDc((int *)&GUID_POWER_SAVING_STATUS, 4u, (int)&PopEsState);
        v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v23 + 308);
        v24 = KeAbPreAcquire((unsigned int)&PopEsLock, 0, 0);
        v25 = v24;
        do
          v26 = __ldrex((unsigned __int8 *)&PopEsLock);
        while ( __strex(v26 | 1, (unsigned __int8 *)&PopEsLock) );
        __dmb(0xBu);
        if ( (v26 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(&PopEsLock, v24, (unsigned int)&PopEsLock);
        if ( v25 )
          *(_BYTE *)(v25 + 14) |= 1u;
        dword_61DED4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v27 = MEMORY[0xFFFF9004];
        while ( 1 )
        {
          v13 = MEMORY[0xFFFF9324];
          __dmb(0xBu);
          v14 = MEMORY[0xFFFF9320];
          __dmb(0xBu);
          if ( v13 == MEMORY[0xFFFF9328] )
            break;
          __dmb(0xAu);
          __yield();
        }
        v15 = ((v14 * (unsigned __int64)v27) >> 24) + ((v13 * (unsigned __int64)v27) << 8);
        PopCurrentPowerState(v35);
        v16 = 0;
        if ( v35[1] )
          v16 = v36;
        PopEsLastStateChangeTimeStamp = v15;
        PopEsAcOnline = v35[0];
        PopEsLastBatteryCharge = v16;
        PopEsLastBatteryThreshold = dword_61EC50;
        PopEsLastUserAwaySetting = byte_61EC54;
        dword_61DED4 = 0;
        __pld(&PopEsLock);
        v28 = PopEsLock;
        if ( (PopEsLock & 0xFFFFFFF0) <= 0x10 )
          v29 = 0;
        else
          v29 = PopEsLock - 16;
        if ( (PopEsLock & 2) != 0 )
          goto LABEL_72;
        __dmb(0xBu);
        do
          v30 = __ldrex((unsigned int *)&PopEsLock);
        while ( v30 == v28 && __strex(v29, (unsigned int *)&PopEsLock) );
        if ( v30 != v28 )
LABEL_72:
          ExfReleasePushLock(&PopEsLock, v28);
        v31 = KeAbPostRelease((unsigned int)&PopEsLock);
        v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v33 = *(_WORD *)(v32 + 0x134) + 1;
        *(_WORD *)(v32 + 308) = v33;
        if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 && !*(_WORD *)(v32 + 310) )
          KiCheckForKernelApcDelivery(v31);
        result = ExSubscribeWnfStateChange(
                   &PopEsWnfSubscriptionOverride,
                   WNF_PO_ENERGY_SAVER_OVERRIDE,
                   1,
                   0,
                   PopEsWnfSubscriptionOverrideCallback,
                   0,
                   0);
        break;
      case 2:
        v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v9 + 308);
        v10 = KeAbPreAcquire((unsigned int)&PopEsLock, 0, 0);
        v11 = v10;
        do
          v12 = __ldrex((unsigned __int8 *)&PopEsLock);
        while ( __strex(v12 | 1, (unsigned __int8 *)&PopEsLock) );
        __dmb(0xBu);
        if ( (v12 & 1) != 0 )
          v10 = ExfAcquirePushLockExclusiveEx(&PopEsLock, v10, (unsigned int)&PopEsLock);
        if ( v11 )
          *(_BYTE *)(v11 + 14) |= 1u;
        dword_61DED4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        PopEsUpdateSetting(v10, 1);
        PopEsUpdateState(v0);
        dword_61DED4 = 0;
        __pld(&PopEsLock);
        v17 = PopEsLock;
        if ( (PopEsLock & 0xFFFFFFF0) <= 0x10 )
          v22 = 0;
        else
          v22 = PopEsLock - 16;
        if ( (PopEsLock & 2) != 0 )
          goto LABEL_46;
        __dmb(0xBu);
        do
          v19 = __ldrex((unsigned int *)&PopEsLock);
        while ( v19 == v17 && __strex(v22, (unsigned int *)&PopEsLock) );
LABEL_45:
        if ( v19 != v17 )
LABEL_46:
          ExfReleasePushLock(&PopEsLock, v17);
        result = KeAbPostRelease((unsigned int)&PopEsLock);
        v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v21 = (__int16)(*(_WORD *)(v20 + 0x134) + 1);
        *(_WORD *)(v20 + 308) = v21;
        if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
          result = KiCheckForKernelApcDelivery(result);
        break;
      case 4:
        v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v5 + 308);
        v6 = KeAbPreAcquire((unsigned int)&PopEsLock, 0, 0);
        v7 = v6;
        do
          v8 = __ldrex((unsigned __int8 *)&PopEsLock);
        while ( __strex(v8 | 1, (unsigned __int8 *)&PopEsLock) );
        __dmb(0xBu);
        if ( (v8 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(&PopEsLock, v6, (unsigned int)&PopEsLock);
        if ( v7 )
          *(_BYTE *)(v7 + 14) |= 1u;
        dword_61DED4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        PopEsUpdateState(v0);
        dword_61DED4 = 0;
        __pld(&PopEsLock);
        v17 = PopEsLock;
        if ( (PopEsLock & 0xFFFFFFF0) <= 0x10 )
          v18 = 0;
        else
          v18 = PopEsLock - 16;
        if ( (PopEsLock & 2) == 0 )
        {
          __dmb(0xBu);
          do
            v19 = __ldrex((unsigned int *)&PopEsLock);
          while ( v19 == v17 && __strex(v18, (unsigned int *)&PopEsLock) );
          goto LABEL_45;
        }
        goto LABEL_46;
    }
LABEL_19:
    if ( !v3 )
      return result;
  }
  if ( v2 == 4 )
  {
    v0 = 1;
    v3 &= 0xFFFFFFF7;
    goto LABEL_4;
  }
  return sub_7F26F0();
}
