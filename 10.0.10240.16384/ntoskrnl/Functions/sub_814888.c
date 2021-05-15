// sub_814888 
 
// local variable allocation has failed, the output may be wrong!
int sub_814888()
{
  int v0; // r1
  unsigned int v1; // r2
  BOOL v2; // r6
  int v3; // r2
  int v4; // r1
  int v5; // r3
  char v6; // r3
  int v7; // r2
  int (__fastcall *v8)(int, int, int); // r3
  int v9; // r0
  int v10; // r0
  int v11; // r2
  int v12; // r2
  int v13; // r4 OVERLAPPED
  int v14; // r5
  int v15; // r6
  unsigned int v16; // r7
  _DWORD *v17; // r8
  int v18; // r9
  int v19; // r10
  unsigned int v20; // r2
  int v21; // r7
  int v22; // r9
  int v23; // r7
  unsigned int v24; // r6
  char v25; // r3
  int v26; // r2
  int v27; // r0
  int v28; // r0
  char v29; // r3
  int v30; // r2
  int v31; // r0
  unsigned int v32; // r1
  __int64 v33; // r6
  int v34; // r1
  unsigned int v35; // r0
  unsigned int v36; // r2
  int v37; // r0
  unsigned int v38; // r1
  __int16 v39; // r3
  char v41[4]; // [sp+10h] [bp-40h] BYREF
  __int64 v42; // [sp+14h] [bp-3Ch]
  int v43; // [sp+1Ch] [bp-34h] BYREF
  int v44; // [sp+20h] [bp-30h]
  int v45; // [sp+24h] [bp-2Ch]
  int v46; // [sp+28h] [bp-28h]
  int (__fastcall *v47)(int); // [sp+4Ch] [bp-4h]

  ExfAcquirePushLockExclusiveEx(v17, v14, (unsigned int)v17);
  if ( v14 )
    *(_BYTE *)(v14 + 14) |= 1u;
  v17[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_BYTE *)(v13 + 34) )
  {
    *(_BYTE *)(v13 + 32) = 0;
    if ( (PoDebug & 0x20) != 0 )
      DbgPrint("Thermal Zone %p is being removed\n", (const void *)v13);
    KeSetEvent(v13 + 328, 0, 0);
    goto LABEL_136;
  }
  v11 = *(_DWORD *)(v18 + 24);
  if ( v11 >= 0 )
  {
    v12 = *(unsigned __int8 *)(v13 + 32);
    if ( v12 == 1 )
    {
      if ( (PoDebug & 0x20) != 0 )
        DbgPrint("\n");
      if ( (PoDebug & 0x20) != 0 )
        DbgPrint("Thermal Zone %p (READ_STATE):\n", (const void *)v13);
      if ( (PoDebug & 0x20) != 0 )
        DbgPrint("  Current Temp:   0x%x\n", *(_DWORD *)(v13 + 176));
      if ( (PoDebug & 0x20) != 0 )
        DbgPrint("  Critical Trip:  0x%x\n", *(_DWORD *)(v13 + 188));
      if ( (PoDebug & 0x20) != 0 )
        DbgPrint("  Passive Trip:   0x%x\n", *(_DWORD *)(v13 + 180));
      v24 = 0;
      if ( *(_BYTE *)(v13 + 192) )
      {
        v23 = v13;
        do
        {
          if ( (PoDebug & 0x20) != 0 )
            DbgPrint("  Active Trip %u: 0x%x\n", v24, *(_DWORD *)(v23 + 196));
          ++v24;
          v23 += 4;
        }
        while ( v24 < *(unsigned __int8 *)(v13 + 192) );
        v16 = v42;
      }
      KeQuerySystemTime((_DWORD *)(v13 + 248));
      if ( (*(_BYTE *)(v13 + 33) & 2) == 0 )
      {
        *(_BYTE *)(v13 + 33) |= 2u;
        PopDiagTraceThermalZoneEnumeration(v13 + 160, v19);
      }
      PopCheckThermalPolicy(v13, v0, v16, HIDWORD(v42), v41, &v43);
      KeSetEvent(v13 + 344, 0, 0);
      v21 = (unsigned __int8)v41[0];
      v22 = v43;
LABEL_115:
      v1 = *(_DWORD *)(v13 + 272);
      v2 = v1 < *(unsigned __int8 *)(v13 + 192);
      if ( v1 == *(unsigned __int8 *)(v13 + 37) )
      {
        if ( v1 < *(unsigned __int8 *)(v13 + 192) )
        {
          if ( (*(_BYTE *)(v13 + 33) & 4) != 0 )
          {
LABEL_118:
            v3 = *(_DWORD *)(v13 + 268);
            v4 = *(_DWORD *)(v13 + 48);
            if ( v3 != v4 )
              goto LABEL_70;
            if ( v21 )
            {
              if ( (*(_BYTE *)(v13 + 33) & 1) != 0 )
              {
LABEL_121:
                PopCheckAndHandleThermalConditions(v13);
                v18 = v46;
                v15 = v44;
                goto LABEL_122;
              }
            }
            else if ( (*(_BYTE *)(v13 + 33) & 1) == 0 )
            {
              goto LABEL_121;
            }
            if ( v3 != v4 )
            {
LABEL_70:
              if ( (PoDebug & 0x20) != 0 )
                DbgPrint(
                  "Thermal Zone %p: Thermal constraint updated to %d\n",
                  (const void *)v13,
                  *(_DWORD *)(v13 + 268));
              PopThermalUpdatePassiveTimeTracking(v13 + 368, (unsigned __int8)*(_DWORD *)(v13 + 48));
              v26 = *(_DWORD *)(v13 + 268);
              v27 = *(_DWORD *)(v13 + 176);
              *(_DWORD *)(v13 + 52) = v26;
              v45 = 1;
              PopDiagTraceThermalZoneThrottlePerfTrack(v27, 100 - v26, v19, 1);
            }
            PopDiagTracePassiveCooling(v13 + 160, v19, v21, v22, 0);
            if ( v21 )
            {
              if ( (*(_BYTE *)(v13 + 33) & 1) != 0 )
              {
LABEL_81:
                v29 = *(_BYTE *)(v13 + 33) | 1;
LABEL_83:
                *(_BYTE *)(v13 + 33) = v29;
                goto LABEL_121;
              }
              PopDiagTracePassiveCooling(v13 + 160, v19, 1, v22, 1);
              *(_QWORD *)(v13 + 296) = v42;
              if ( (PoDebug & 0x20) != 0 )
                DbgPrint("Thermal Zone %p: Starting to throttle\n", v13);
            }
            else
            {
              if ( (*(_BYTE *)(v13 + 33) & 1) == 0 )
                goto LABEL_82;
              PopDiagTracePassiveCooling(v13 + 160, v19, 0, v22, 1);
              v28 = _rt_udiv64(10000i64, v42 - *(_QWORD *)(v13 + 296));
              PopDiagTraceThermalZoneThrottleDurationPerfTrack(v28, v19);
              if ( (PoDebug & 0x20) == 0 )
                goto LABEL_82;
              DbgPrint("Thermal Zone %p: Ending throttle\n", v13);
            }
            if ( v21 )
              goto LABEL_81;
LABEL_82:
            v29 = *(_BYTE *)(v13 + 33) & 0xFE;
            goto LABEL_83;
          }
        }
        else if ( (*(_BYTE *)(v13 + 33) & 4) == 0 )
        {
          goto LABEL_118;
        }
      }
      if ( (PoDebug & 0x20) != 0 )
        DbgPrint("Thermal Zone %p: Pending Coooling Point is 0x%x\n", (const void *)v13, *(_DWORD *)(v13 + 272));
      *(_BYTE *)(v13 + 38) = *(_DWORD *)(v13 + 272);
      v44 = 1;
      if ( v2 )
      {
        if ( (*(_BYTE *)(v13 + 33) & 4) != 0 )
          goto LABEL_67;
        PopDiagTraceActiveCooling(v13 + 160, v19, 1, 0);
        PopDiagTraceActiveCooling(v13 + 160, v19, 1, 1);
        *(_QWORD *)(v13 + 288) = v42;
      }
      else
      {
        if ( (*(_BYTE *)(v13 + 33) & 4) == 0 )
          goto LABEL_158;
        PopDiagTraceActiveCooling(v13 + 160, v19, 0, 0);
        PopDiagTraceActiveCooling(v13 + 160, v19, 0, 1);
      }
      if ( !v2 )
      {
LABEL_158:
        v25 = *(_BYTE *)(v13 + 33) & 0xFB;
        goto LABEL_159;
      }
LABEL_67:
      v25 = *(_BYTE *)(v13 + 33) | 4;
LABEL_159:
      *(_BYTE *)(v13 + 33) = v25;
      goto LABEL_118;
    }
    if ( v12 == 3 )
    {
      *(_BYTE *)(v13 + 37) = *(_BYTE *)(v13 + 38);
      if ( (PoDebug & 0x20) != 0 )
        DbgPrint("\n");
      if ( (PoDebug & 0x20) != 0 )
        DbgPrint("Thermal Zone %p (SET_ACTIVE):\n", (const void *)v13);
      if ( (PoDebug & 0x20) != 0 )
        DbgPrint("  New Active cooling point: 0x%x\n", *(unsigned __int8 *)(v13 + 37));
    }
    else if ( v12 == 2 )
    {
      *(_BYTE *)(v13 + 35) = *(_BYTE *)(v13 + 36);
      if ( (PoDebug & 0x20) != 0 )
        DbgPrint("\n");
      if ( (PoDebug & 0x20) != 0 )
        DbgPrint("Thermal Zone %p (SET_MODE):\n", (const void *)v13);
      if ( (PoDebug & 0x20) != 0 )
        DbgPrint("  Cooling mode set to 0x%x\n", *(unsigned __int8 *)(v13 + 35));
      PopDiagTraceThermalCoolingMode();
      if ( WmiThermalPolicyEventEnabled )
        PopFireThermalWmiEvent(*(_BYTE *)(v13 + 35));
      v15 = 1;
    }
    else
    {
      if ( v12 == 6 )
      {
        *(_BYTE *)(v13 + 32) = 7;
        goto LABEL_122;
      }
      if ( v12 != 4 )
      {
        if ( v12 == 7 )
        {
          *(_BYTE *)(v13 + 280) = 1;
          if ( (PoDebug & 0x20) != 0 )
            DbgPrint("Thermal Zone %p: Using policy driver interface.\n", (const void *)v13);
          *(_BYTE *)(v13 + 32) = 8;
        }
        else if ( v12 != 8 )
        {
          PopInternalAddToDumpFile(v18, 112, v19);
          KeBugCheckEx(160, 1280, 5, v18, v19);
        }
        if ( (PoDebug & 0x20) != 0 )
          DbgPrint("\n", 32);
        if ( (PoDebug & 0x20) != 0 )
          DbgPrint("Thermal Zone %p (READ_POLICY):\n", (const void *)v13);
        if ( (PoDebug & 0x20) != 0 )
          DbgPrint("  Activation Reasons: 0x%x\n", *(_DWORD *)(v13 + 264));
        if ( (PoDebug & 0x20) != 0 )
          DbgPrint("  Passive Limit:      %d\n", *(_DWORD *)(v13 + 268));
        if ( (PoDebug & 0x20) != 0 )
          DbgPrint("  Active Level:       %d\n", *(_DWORD *)(v13 + 272));
        if ( (PoDebug & 0x20) != 0 )
          DbgPrint("  Critical:           %x\n", *(unsigned __int8 *)(v13 + 262));
        v20 = *(_DWORD *)(v13 + 268);
        v21 = v20 < 0x64;
        v22 = 10 * (*(_DWORD *)(v13 + 48) - v20);
        if ( (*(_BYTE *)(v13 + 33) & 2) == 0 )
        {
          *(_BYTE *)(v13 + 33) |= 2u;
          PopDiagTraceThermalZoneEnumeration(v13 + 160, v19);
        }
        goto LABEL_115;
      }
      *(_DWORD *)(v13 + 48) = *(_DWORD *)(v13 + 52);
      if ( (PoDebug & 0x20) != 0 )
        DbgPrint("\n");
      if ( (PoDebug & 0x20) != 0 )
        DbgPrint("Thermal Zone %p (SET_PASSIVE):\n", (const void *)v13);
      if ( (PoDebug & 0x20) != 0 )
        DbgPrint("  New throttle: %d%%\n", *(_DWORD *)(v13 + 48));
    }
LABEL_122:
    if ( *(unsigned __int8 *)(v13 + 37) != *(unsigned __int8 *)(v13 + 38) )
      v15 = 1;
    if ( *(_DWORD *)(v13 + 48) == *(_DWORD *)(v13 + 52) )
      v30 = v45;
    else
      v30 = 1;
    v5 = *(unsigned __int8 *)(v13 + 32);
    if ( v5 != 6 )
    {
      if ( v5 != 7 )
      {
        if ( v15 )
        {
          *(_BYTE *)(v13 + 32) = 3;
          PopPrepareIoctl(*(_DWORD *)(v13 + 28), 2719880, 1, v13 + 38, 4, 0);
          if ( (PoDebug & 0x20) != 0 )
            DbgPrint("Thermal Zone %p: Sending Run Cooling Method: 0x%x\n", v13, *(unsigned __int8 *)(v13 + 38));
          goto LABEL_135;
        }
        if ( v30 )
        {
          v31 = *(_DWORD *)(v13 + 28);
          *(_BYTE *)(v13 + 32) = 4;
          PopPrepareIoctl(v31, 2719884, 1, v13 + 52, 4, 0);
          if ( (PoDebug & 0x20) != 0 )
            DbgPrint("Thermal Zone %p: Sending Set Passive Limit: 0x%x\n", v13, *(_DWORD *)(v13 + 48));
          goto LABEL_135;
        }
        if ( *(unsigned __int8 *)(v13 + 35) != PopCoolingMode )
        {
          *(_BYTE *)(v13 + 36) = PopCoolingMode;
          v9 = *(_DWORD *)(v13 + 28);
          *(_BYTE *)(v13 + 32) = 2;
          PopPrepareIoctl(v9, 2719876, 1, v13 + 36, 1, 0);
          if ( (PoDebug & 0x20) != 0 )
            DbgPrint(
              "Thermal Zone %p: Sending Set Cooling Policy: 0x%x\n",
              (const void *)v13,
              *(unsigned __int8 *)(v13 + 36));
          goto LABEL_135;
        }
        if ( !*(_BYTE *)(v13 + 280) )
        {
          v6 = *(_BYTE *)(v13 + 33);
          *(_BYTE *)(v13 + 32) = 1;
          if ( (v6 & 1) != 0 )
          {
            v32 = *(_DWORD *)(v13 + 72);
            if ( v32 )
            {
              v33 = *(_QWORD *)(v13 + 64) + v32;
              if ( v33 <= v42 )
              {
                *(_DWORD *)(v13 + 160) = 0;
              }
              else
              {
                if ( (PoDebug & 0x20) != 0 )
                  DbgPrint(
                    "Thermal Zone %p: Next read in %d sec\n",
                    (const void *)v13,
                    *(_DWORD *)(v13 + 72) / 0x989680u);
                KiSetTimerEx(v13 + 80, 0, v42 - v33, 0, 0, v13 + 128);
              }
            }
          }
          PopPrepareIoctl(*(_DWORD *)(v13 + 28), 2703488, 1, v13 + 160, 88, 88);
          if ( (PoDebug & 0x20) != 0 )
            DbgPrint("Thermal Zone %p: Sending Query Temp - ThermalStamp = 0x%x\n", v13, *(_DWORD *)(v13 + 160));
          goto LABEL_135;
        }
        *(_BYTE *)(v13 + 32) = 8;
        *(_BYTE *)(v13 + 260) = 1;
      }
      v10 = *(_DWORD *)(v13 + 28);
      *(_DWORD *)(v13 + 256) = 1;
      PopPrepareIoctl(v10, 2703508, 0, v13 + 256, 24, 24);
      if ( (PoDebug & 0x20) != 0 )
        DbgPrint("Thermal Zone %p: Sending Query Policy\n", (const void *)v13);
      goto LABEL_135;
    }
    PopPrepareIoctl(*(_DWORD *)(v13 + 28), 2703488, 1, v13 + 160, 88, 88);
LABEL_135:
    v7 = *(_DWORD *)(v18 + 96);
    v8 = PopThermalIrpComplete;
    *(_QWORD *)(v7 - 8) = *(_QWORD *)(&v13 - 1);
    *(_BYTE *)(v7 - 37) = -32;
    IofCallDriver(v19, v18);
    goto LABEL_136;
  }
  if ( v11 == -1073741667 || v11 == -1073741536 )
    goto LABEL_122;
  if ( *(_BYTE *)(v13 + 32) == 7 )
  {
    if ( (PoDebug & 0x20) != 0 )
      DbgPrint("Thermal Zone %p: Using ACPI interface.\n", (const void *)v13);
    *(_BYTE *)(v13 + 32) = 1;
    goto LABEL_122;
  }
  if ( (PoDebug & 1) != 0 )
    DbgPrint("Thermal Zone %p: unexpected error %x\n", (const void *)v13, *(_DWORD *)(v18 + 24));
  *(_BYTE *)(v13 + 32) = 5;
  KeSetEvent(v13 + 328, 0, 0);
LABEL_136:
  if ( v17[1] )
    v17[1] = 0;
  __pld(v17);
  v34 = *v17;
  v35 = *v17 - 16;
  if ( (*v17 & 0xFFFFFFF0) <= 0x10 )
    v35 = 0;
  if ( (v34 & 2) != 0 )
    goto LABEL_105;
  __dmb(0xBu);
  do
    v36 = __ldrex(v17);
  while ( v36 == v34 && __strex(v35, v17) );
  if ( v36 != v34 )
LABEL_105:
    ExfReleasePushLock(v17, v34);
  v37 = KeAbPostRelease((unsigned int)v17);
  v38 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v39 = *(_WORD *)(v38 + 0x134) + 1;
  *(_WORD *)(v38 + 308) = v39;
  if ( !v39 && *(_DWORD *)(v38 + 100) != v38 + 100 && !*(_WORD *)(v38 + 310) )
    v37 = KiCheckForKernelApcDelivery(v37);
  return v47(v37);
}
