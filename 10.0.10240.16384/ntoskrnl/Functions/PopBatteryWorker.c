// PopBatteryWorker 
 
// local variable allocation has failed, the output may be wrong!
int PopBatteryWorker()
{
  unsigned int v0; // r2
  int v1; // r0
  unsigned int v2; // r2
  int result; // r0
  int *v4; // r4
  int v5; // r8
  int *v6; // r0
  int v7; // r9
  unsigned int v8; // r10
  int *v9; // r4
  int *v10; // r5
  int *j; // r4
  int *v12; // r7
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r1
  int v17; // r0
  int v18; // r8
  unsigned int v19; // r4
  unsigned int v20; // r0
  int v21; // r5
  int v22; // r9
  int *k; // r1
  int v24; // r2
  int v25; // r3
  unsigned int v26; // r3
  int v27; // r3
  int v28; // r4
  int *v29; // r4
  int v30; // r7
  unsigned int v31; // r0
  int v32; // r10
  unsigned int v33; // r2
  __int64 v34; // r0
  int v35; // r2
  int *m; // r4
  int v37; // r3
  int v38; // r1
  unsigned int v39; // r0
  unsigned int v40; // r2
  unsigned int v41; // r1
  __int16 v42; // r3
  int v43; // r3
  __int64 v44; // r0
  int *v45; // r1 OVERLAPPED
  int **v46; // r2 OVERLAPPED
  __int64 v47; // r0
  unsigned int v48; // r4
  unsigned int v49; // r5
  int *l; // r4
  int v51; // r0
  int v52; // [sp+0h] [bp-C8h]
  int v53; // [sp+18h] [bp-B0h]
  int i; // [sp+1Ch] [bp-ACh]
  int v55; // [sp+20h] [bp-A8h] BYREF
  int v56; // [sp+24h] [bp-A4h]
  unsigned int v57; // [sp+28h] [bp-A0h]
  unsigned int v58; // [sp+2Ch] [bp-9Ch]
  int v59; // [sp+30h] [bp-98h]
  int v60; // [sp+38h] [bp-90h]
  int v61; // [sp+3Ch] [bp-8Ch]
  __int64 v62; // [sp+40h] [bp-88h]
  int v63; // [sp+48h] [bp-80h]
  int v64; // [sp+4Ch] [bp-7Ch]
  _DWORD v65[2]; // [sp+50h] [bp-78h] BYREF
  unsigned int v66; // [sp+58h] [bp-70h]
  int v67; // [sp+60h] [bp-68h]
  int v68; // [sp+64h] [bp-64h]
  int v69; // [sp+68h] [bp-60h]
  int v70; // [sp+6Ch] [bp-5Ch]
  char v71[36]; // [sp+70h] [bp-58h] BYREF
  int v72; // [sp+94h] [bp-34h]
  int v73; // [sp+98h] [bp-30h]
  int v74; // [sp+9Ch] [bp-2Ch]
  int v75; // [sp+A0h] [bp-28h]
  int v76; // [sp+A4h] [bp-24h]

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&PopPolicyDeviceLock, 0, 0);
  do
    v2 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
  while ( !v2 && __strex(0x11u, (unsigned int *)&PopPolicyDeviceLock) );
  __dmb(0xBu);
  if ( v2 )
    return sub_7F3830(v1, 17);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  PopBatteryAcquireExclusiveLock();
  v53 = PopGetDischargeStartStatus();
  v4 = (int *)dword_61ED7C;
  if ( (int *)dword_61ED7C != &dword_61ED7C )
  {
    do
    {
      IoCancelIrp(*(v4 - 1));
      v4 = (int *)*v4;
    }
    while ( v4 != &dword_61ED7C );
    v4 = (int *)dword_61ED7C;
  }
  for ( ; v4 != &dword_61ED7C; v4 = (int *)*v4 )
    KeWaitForSingleObject((unsigned int)(v4 + 2), 0, 0, 0, 0);
  v59 = 0;
  v5 = 0;
  for ( i = 0; ; v5 = i )
  {
    v6 = &dword_61ED7C;
    v7 = 0;
    __dmb(0xBu);
    do
      v8 = __ldrex((unsigned int *)&PopBatteryWorkRequests);
    while ( __strex(0x80000000, (unsigned int *)&PopBatteryWorkRequests) );
    v66 = v8;
    __dmb(0xBu);
    if ( (v8 & 2) != 0 )
      v7 = 1;
    v9 = (int *)dword_61ED7C;
    if ( (int *)dword_61ED7C != &dword_61ED7C )
    {
      do
      {
        v10 = (int *)*v9;
        if ( v9[6] == 2 )
        {
          *(_QWORD *)&v45 = *(_QWORD *)v9;
          if ( *(int **)(*v9 + 4) != v9 || *v46 != v9 )
            __fastfail(3u);
          *v46 = v45;
          v45[1] = (int)v46;
          *v9 = 0;
          --dword_61ED6C;
          ++dword_61EDBC;
          byte_61ED70 = 1;
          v6 = (int *)PopBatteryReadTag(v9 - 8);
          if ( (int)v6 < 0 )
            v6 = (int *)PopBatteryWaitTag(v9 - 8);
          v7 = 1;
        }
        v9 = v10;
      }
      while ( v10 != &dword_61ED7C );
    }
    for ( j = (int *)dword_61ED74; j != &dword_61ED74; j = (int *)*j )
    {
      if ( j[14] == 1 )
      {
        KeWaitForSingleObject((unsigned int)(j + 10), 0, 0, 0, 0);
        v6 = (int *)PopBatteryInitialize(j);
        if ( (int)v6 < 0 )
          v6 = (int *)PopBatteryWaitTag(j);
        else
          v7 = 1;
      }
    }
    v12 = (int *)dword_61ED7C;
    if ( (int *)dword_61ED7C != &dword_61ED7C )
    {
      do
      {
        v13 = v12[18];
        v14 = v12[19];
        v15 = v12[20];
        v67 = v12[17];
        v68 = v13;
        v69 = v14;
        v70 = v15;
        if ( PopBatteryQueryStatus(v12 - 8, 1) < 0 )
        {
          v12[6] = 2;
          v6 = (int *)PopBatteryQueueWork(1);
        }
        else
        {
          v16 = v12[17];
          if ( ((v67 ^ v16) & 7) != 0 )
          {
            i = 1;
          }
          else if ( v68 != v12[18] || v70 != v12[20] )
          {
            v59 = 1;
          }
          v17 = -1;
          if ( (v16 & 2) != 0 )
            v17 = PopBatteryQueryEstimatedTime(v12 - 8, 0);
          v12[21] = v17;
          v52 = v12[17];
          v6 = (int *)DbgPrintEx(
                        146,
                        3,
                        (int)"\n"
                             "Battery Status [%p]\n"
                             "|-- PowerState = 0x%08x\n"
                             "|-- Capacity   = %u\n"
                             "|-- Voltage    = %u\n"
                             "|-- Rate       = %d\n"
                             "|-- Est Time   = %u\n",
                        (int)(v12 - 8));
        }
        v12 = (int *)*v12;
      }
      while ( v12 != &dword_61ED7C );
      LOBYTE(v8) = v66;
      v5 = i;
    }
    if ( v7 )
    {
      PopBatteryUpdateCompositeInformation(v6);
      v5 = 1;
      PopMaxChargeRate = 0;
      dword_63294C = 0;
      i = 1;
    }
    if ( (v8 & 4) != 0 || v5 )
    {
      v43 = PopEstimateSpoilerMask;
      __dmb(0xBu);
      if ( v43 )
      {
        PopEstimateSpoiledUntilTime = -1i64;
      }
      else
      {
        LODWORD(v44) = KeQueryInterruptTime();
        PopEstimateSpoiledUntilTime = v44 + 300000000;
      }
    }
    v18 = 0;
    v55 = 0;
    v56 = -1;
    v19 = 0x80000000;
    v57 = -1;
    v58 = 0x80000000;
    v20 = -1;
    v21 = -1;
    v62 = -1i64;
    v22 = -1;
    if ( dword_61ED6C )
    {
      for ( k = (int *)dword_61ED7C; k != &dword_61ED7C; k = (int *)*k )
      {
        v24 = k[17];
        v18 |= v24 & 7;
        v55 = v18;
        if ( (v24 & 0xA) == 10 )
        {
          v18 |= 8u;
          v55 = v18;
        }
        v25 = k[18];
        if ( v25 != -1 )
        {
          if ( v21 == -1 )
            v21 = 0;
          v21 += v25;
          v56 = v21;
        }
        v26 = k[19];
        if ( v26 != -1 )
        {
          if ( v20 == -1 )
          {
            v20 = 0;
            v57 = 0;
          }
          if ( v26 > v20 )
          {
            v20 = v26;
            v57 = v26;
          }
        }
        v27 = k[20];
        if ( v27 != 0x80000000 )
        {
          if ( v19 == 0x80000000 )
            v19 = 0;
          v19 += v27;
          v58 = v19;
        }
      }
      if ( PopBatteryChargingInProgress )
      {
        v28 = v18 & 4;
        if ( (v18 & 4) == 0 )
          v20 = KeCancelTimer2((int)PopBatteryWakeTimer);
      }
      else
      {
        v28 = v18 & 4;
        if ( (v18 & 4) != 0 )
          v20 = KeSetTimer2(PopBatteryWakeTimer, -50000000i64, 50000000i64, 0);
      }
      PopBatteryChargingInProgress = v28 != 0;
      if ( (v18 & 2) != 0 )
      {
        v18 &= 0xFFFFFFFB;
        v55 = v18;
      }
      if ( (v18 & 1) != 0 )
      {
        if ( (v18 & 4) != 0 )
          v62 = PopEstimateChargeTime(v20);
        v32 = v53;
      }
      else
      {
        v29 = (int *)dword_61ED7C;
        v30 = 0;
        if ( (int *)dword_61ED7C != &dword_61ED7C )
        {
          do
          {
            v31 = v29[21];
            if ( v31 != -1 && v31 )
              v30 -= 3600 * v29[18] / v31;
            v29 = (int *)*v29;
          }
          while ( v29 != &dword_61ED7C );
          if ( v30 )
          {
            for ( l = (int *)dword_61ED7C; l != &dword_61ED7C; l = (int *)*l )
            {
              v51 = PopBatteryQueryEstimatedTime(l - 8, v30);
              if ( v51 != -1 )
              {
                if ( v22 == -1 )
                  v22 = 0;
                v22 += v51;
              }
            }
          }
        }
        v32 = v53;
      }
    }
    else
    {
      v32 = v53;
      LOBYTE(v18) = 1;
      v55 = 1;
      if ( v53 == 3 )
      {
        do
        {
          v47 = MEMORY[0xFFFF93B0];
          while ( 1 )
          {
            v48 = MEMORY[0xFFFF900C];
            __dmb(0xBu);
            v49 = MEMORY[0xFFFF9008];
            __dmb(0xBu);
            if ( v48 == MEMORY[0xFFFF9010] )
              break;
            __dmb(0xAu);
            __yield();
          }
        }
        while ( v47 != MEMORY[0xFFFF93B0] );
        if ( __PAIR64__(v48, v49) - v47 >= 0x11E1A300 )
        {
          v32 = 1;
          v53 = 1;
        }
      }
    }
    if ( v32 == 2 && (v18 & 1) == 0 || (v18 & 1) != 0 && v32 == 3 )
    {
      v32 = 1;
      v53 = 1;
    }
    PopBatteryApplyCompositeState(&v55, v22);
    __dmb(0xBu);
    do
      v33 = __ldrex((unsigned int *)&PopBatteryWorkRequests);
    while ( v33 == 0x80000000 && __strex(0, (unsigned int *)&PopBatteryWorkRequests) );
    __dmb(0xBu);
    if ( v33 == 0x80000000 )
      break;
  }
  LODWORD(v34) = KeQueryInterruptTime();
  qword_61EE80 = v34;
  __dmb(0xFu);
  if ( dword_61EE88 )
    LODWORD(v34) = ExfUnblockPushLock((int)&dword_61EE88, 0);
  for ( m = (int *)dword_61ED7C; m != &dword_61ED7C; m = (int *)*m )
    LODWORD(v34) = PopBatteryQueryStatus(m - 8, 0);
  v37 = v59 | i;
  if ( v59 | i )
  {
    memmove((int)v71, (int)&dword_61ED98, 0x24u);
    v72 = dword_61ED84;
    v73 = dword_61ED88;
    v74 = dword_61ED8C;
    v75 = dword_61ED90;
    v76 = dword_61ED6C;
    ZwUpdateWnfStateData();
    if ( v32 == 1 )
    {
      if ( (v18 & 1) != 0 )
      {
        v65[0] = 0;
        v65[1] = 0;
      }
      else
      {
        KeQuerySystemTime(v65);
      }
      ZwUpdateWnfStateData();
    }
    v52 = 0;
    LODWORD(v34) = ZwUpdateWnfStateData();
    v37 = PopUserBatteryDischargeEstimator;
    if ( !PopUserBatteryDischargeEstimator )
    {
      if ( v22 == -1 || PopBatteryEstimatesSpoiled(v34) )
      {
        v60 = -1;
        v61 = -1;
      }
      else
      {
        v60 = v22;
        v61 = 0;
      }
      v52 = 0;
      LODWORD(v34) = ZwUpdateWnfStateData();
    }
    if ( i )
    {
      v63 = 0;
      v64 = -1;
      v52 = 0;
      LODWORD(v34) = ZwUpdateWnfStateData();
    }
  }
  PopBatteryReleaseLock(v34, HIDWORD(v34), v35, v37, v52);
  dword_61E614 = 0;
  __pld(&PopPolicyDeviceLock);
  v38 = PopPolicyDeviceLock;
  if ( (PopPolicyDeviceLock & 0xFFFFFFF0) <= 0x10 )
    v39 = 0;
  else
    v39 = PopPolicyDeviceLock - 16;
  if ( (PopPolicyDeviceLock & 2) != 0 )
    goto LABEL_94;
  __dmb(0xBu);
  do
    v40 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
  while ( v40 == v38 && __strex(v39, (unsigned int *)&PopPolicyDeviceLock) );
  if ( v40 != v38 )
LABEL_94:
    ExfReleasePushLock(&PopPolicyDeviceLock, v38);
  result = KeAbPostRelease((unsigned int)&PopPolicyDeviceLock);
  v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v42 = *(_WORD *)(v41 + 0x134) + 1;
  *(_WORD *)(v41 + 308) = v42;
  if ( !v42 && *(_DWORD *)(v41 + 100) != v41 + 100 && !*(_WORD *)(v41 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
