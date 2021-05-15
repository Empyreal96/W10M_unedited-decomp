// PopPepInitializeVetoMasks 
 
int __fastcall PopPepInitializeVetoMasks(int result, unsigned int a2)
{
  int v2; // r9
  unsigned int *v4; // r6
  int v5; // r3
  unsigned int *v6; // r7
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r0
  int v10; // r5
  int v11; // r4
  unsigned int v12; // r2
  int v13; // lr
  unsigned int *v14; // r1
  unsigned int v15; // r7
  int v16; // r10
  _DWORD *v17; // r9
  unsigned int v18; // r0
  unsigned int v19; // r2
  _DWORD *v20; // r1
  unsigned int v21; // r3
  unsigned int v22; // r10
  int v23; // r4
  int v24; // r4
  unsigned int v25; // r2
  int v26; // r9
  int v27; // r2
  __int64 v28; // kr00_8
  unsigned int *v29; // r0
  int v30; // lr
  unsigned int v31; // r9
  int v32; // r1
  _DWORD *v33; // r2
  unsigned int v34; // r2
  int v35; // r1
  __int64 v36; // r0
  __int64 v37; // r0
  int v38; // r3
  unsigned int v39; // r2
  unsigned int v40; // r1
  unsigned int v41; // r2
  int v42; // [sp+8h] [bp-148h]
  _DWORD *v43; // [sp+8h] [bp-148h]
  int v44; // [sp+Ch] [bp-144h]
  int v45; // [sp+10h] [bp-140h]
  unsigned int *v46; // [sp+14h] [bp-13Ch]
  _DWORD *v47; // [sp+14h] [bp-13Ch]
  int v48; // [sp+18h] [bp-138h]
  int v49; // [sp+1Ch] [bp-134h]
  int v50; // [sp+20h] [bp-130h]
  unsigned int *v51; // [sp+24h] [bp-12Ch]
  int v52; // [sp+28h] [bp-128h] BYREF
  int v53; // [sp+2Ch] [bp-124h]
  int v54; // [sp+30h] [bp-120h]
  unsigned int v55; // [sp+34h] [bp-11Ch] BYREF
  unsigned int v56; // [sp+38h] [bp-118h] BYREF
  _DWORD v57[20]; // [sp+40h] [bp-110h] BYREF
  _DWORD v58[48]; // [sp+90h] [bp-C0h] BYREF

  v2 = *(_DWORD *)(result + 24);
  v4 = (unsigned int *)result;
  v5 = *(_DWORD *)(v2 + 28);
  v45 = v2;
  if ( v5 )
  {
    v53 = *(_DWORD *)(v5 + 16);
    PopFxActivateDevice(v53, 0);
    RtlFillMemoryUlong(v58, 0x80u, 1);
    v6 = v4 + 11;
    v54 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      JUMPOUT(0x5511FA);
    v7 = (unsigned __int8 *)v4 + 47;
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | 0x80, v7) );
    __dmb(0xBu);
    if ( v8 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v4 + 11);
    while ( 1 )
    {
      v9 = *v6;
      if ( (*v6 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v9 & 0x40000000) == 0 )
      {
        do
          v40 = __ldrex(v6);
        while ( v40 == v9 && __strex(v9 | 0x40000000, v6) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    v44 = 0;
    v48 = dword_635500;
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)&PopFxDeviceAccountingLevel);
    while ( !v10 && __strex(0, (unsigned int *)&PopFxDeviceAccountingLevel) );
    __dmb(0xBu);
    v11 = v2 + 344;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v2 + 344);
    }
    else
    {
      do
        v12 = __ldrex((unsigned int *)v11);
      while ( __strex(1u, (unsigned int *)v11) );
      __dmb(0xBu);
      if ( v12 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(v2 + 344));
    }
    *(_DWORD *)(v2 + 376) = 0;
    *(_DWORD *)(v2 + 380) = 0;
    *(_DWORD *)(v2 + 368) = 0;
    *(_DWORD *)(v2 + 372) = 0;
    *(_DWORD *)(v2 + 360) = 0;
    *(_DWORD *)(v2 + 364) = 0;
    *(_BYTE *)(v2 + 348) = 0;
    if ( PopPluginRequestDeviceIdleConstraints(v4[6], v58, a2) )
    {
      v44 = 0;
      __dmb(0xBu);
      do
        v10 = __ldrex((unsigned int *)&PopFxDeviceAccountingLevel);
      while ( !v10 && __strex(0, (unsigned int *)&PopFxDeviceAccountingLevel) );
      __dmb(0xBu);
      if ( v10 && v10 >= 0 )
      {
        __dmb(0xBu);
        do
          v39 = __ldrex((unsigned int *)&PopFxDeviceAccountingLevel);
        while ( v39 == v10 && __strex(v10 | 0x80000000, (unsigned int *)&PopFxDeviceAccountingLevel) );
        __dmb(0xBu);
        if ( v39 == v10 )
          v44 = 1;
        v10 |= 0x80000000;
      }
      v13 = 1;
      v14 = v58;
      v15 = 0;
      v42 = 1;
      if ( a2 )
      {
        v16 = 0;
        v17 = v58;
        while ( 1 )
        {
          if ( !*((_BYTE *)PopPepPlatformState + v16 + 29) && *v17 != 1 )
            PopFxBugCheck(1568, v45, v15, 0);
          v18 = *v14;
          v19 = 1;
          v46 = v14 + 1;
          v20 = v4 + 1;
          do
          {
            if ( v19 >= v18 )
              break;
            ++v19;
            v20[23] |= v13;
            ++v20;
          }
          while ( v19 <= 3 );
          if ( v48 != -1 && v15 == v48 && v18 > 1 )
          {
            *(_DWORD *)(v11 + 8) = v18;
            LODWORD(v37) = KeQueryInterruptTime();
            v13 = v42;
            *(_BYTE *)(v11 + 4) = 1;
            *(_QWORD *)(v11 + 16) = v37;
          }
          v13 *= 2;
          ++v15;
          v42 = v13;
          v16 += 256;
          ++v17;
          if ( v15 >= a2 )
            break;
          v14 = v46;
        }
        v2 = v45;
      }
      v6 = v4 + 11;
    }
    *(_DWORD *)(v11 + 12) = v10;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v11);
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)v11 = 0;
    }
    v21 = v4[27];
    if ( v21 != 4 )
      PopPepUpdateIdleStateRefCount(0, v4[v21 + 23], 1);
    v22 = 0;
    if ( v4[30] )
    {
      v43 = v4 + 32;
      while ( 1 )
      {
        v23 = *(_DWORD *)(*(_DWORD *)(v2 + 392) + 4 * v22);
        memset(v58, 0, 128);
        v24 = v23 + 144;
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented(v24);
        }
        else
        {
          do
            v25 = __ldrex((unsigned int *)v24);
          while ( __strex(1u, (unsigned int *)v24) );
          __dmb(0xBu);
          if ( v25 )
            KxWaitForSpinLockAndAcquire((unsigned int *)v24);
        }
        *(_DWORD *)(v24 + 24) = 0;
        *(_DWORD *)(v24 + 28) = 0;
        *(_DWORD *)(v24 + 32) = 0;
        *(_DWORD *)(v24 + 36) = 0;
        *(_DWORD *)(v24 + 16) = 0;
        *(_DWORD *)(v24 + 20) = 0;
        *(_BYTE *)(v24 + 4) = 0;
        v26 = v4[6];
        v27 = *(_DWORD *)(v26 + 36);
        if ( v27 == PopFxProcessorPlugin )
        {
          v57[0] = *(_DWORD *)(v26 + 40);
          v57[1] = v22;
          v57[2] = v58;
          v57[3] = a2;
          if ( (*(int (__fastcall **)(int, _DWORD *))(v27 + 64))(27, v57) )
          {
            v55 = a2;
            v56 = v22;
            v52 = v26;
            if ( PopDiagHandleRegistered )
            {
              v28 = *(_QWORD *)&PopDiagHandle;
              if ( EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_COMPONENT_IDLE_CONSTRAINTS) )
              {
                v57[4] = &v52;
                v57[5] = 0;
                v57[6] = 4;
                v57[7] = 0;
                v57[8] = &v56;
                v57[9] = 0;
                v57[10] = 4;
                v57[11] = 0;
                v57[12] = &v55;
                v57[13] = 0;
                v57[14] = 4;
                v57[15] = 0;
                v57[16] = v58;
                v57[17] = 0;
                v57[18] = 4 * a2;
                v57[19] = 0;
                EtwWrite(v28, SHIDWORD(v28), (int)POP_ETW_EVENT_COMPONENT_IDLE_CONSTRAINTS, 0);
              }
            }
            v44 = 0;
            __dmb(0xBu);
            do
              v10 = __ldrex((unsigned int *)&PopFxDeviceAccountingLevel);
            while ( !v10 && __strex(0, (unsigned int *)&PopFxDeviceAccountingLevel) );
            __dmb(0xBu);
            if ( v10 && v10 >= 0 )
            {
              __dmb(0xBu);
              do
                v41 = __ldrex((unsigned int *)&PopFxDeviceAccountingLevel);
              while ( v41 == v10 && __strex(v10 | 0x80000000, (unsigned int *)&PopFxDeviceAccountingLevel) );
              __dmb(0xBu);
              if ( v41 == v10 )
                v44 = 1;
              v10 |= 0x80000000;
            }
            v29 = v58;
            v30 = 1;
            v50 = 1;
            v51 = v58;
            v31 = 0;
            if ( a2 )
            {
              v32 = 0;
              v33 = v58;
              v47 = v58;
              v49 = 0;
              do
              {
                if ( !*((_BYTE *)PopPepPlatformState + v32 + 29) && *v33 )
                  PopFxBugCheck(1569, v45, v22, v31);
                v34 = 0;
                v35 = v43[40];
                if ( v43[39] )
                {
                  do
                  {
                    if ( v34 >= *v29 )
                      break;
                    ++v34;
                    *(_DWORD *)(v35 + 16) |= v30;
                    v35 += 24;
                  }
                  while ( v34 < v43[39] );
                  v6 = v4 + 11;
                }
                if ( v48 != -1 && v31 == v48 && *v29 )
                {
                  *(_DWORD *)(v24 + 8) = *v29;
                  LODWORD(v36) = KeQueryInterruptTime();
                  v30 = v50;
                  *(_QWORD *)(v24 + 16) = v36;
                  v29 = v51;
                  *(_BYTE *)(v24 + 4) = 1;
                }
                ++v29;
                v32 = v49 + 256;
                v33 = v47 + 1;
                v30 *= 2;
                ++v31;
                v49 += 256;
                v50 = v30;
                ++v47;
                v51 = v29;
              }
              while ( v31 < a2 );
            }
          }
        }
        *(_DWORD *)(v24 + 12) = v10;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v24);
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v24 = 0;
        }
        PopPepUpdateIdleStateRefCount(0, *(_DWORD *)(v43[40] + 24 * v43[36] + 16), 1);
        ++v22;
        v43 += 42;
        if ( v22 >= v4[30] )
          break;
        v2 = v45;
      }
    }
    v4[28] = 2;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v6);
    }
    else
    {
      __dmb(0xBu);
      *v6 = 0;
    }
    KfLowerIrql(v54);
    result = PoFxIdleDevice(v53);
    if ( v44 )
      result = PopPepResetDeviceAccountingLevel(result);
  }
  else
  {
    v38 = *(_DWORD *)(v2 + 384);
    __dmb(0xBu);
    if ( (v38 & 2) != 0 && *(_DWORD *)(PpmPlatformStates + 4) )
      result = sub_551198();
  }
  return result;
}
