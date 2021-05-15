// PpmParkSteerInterrupts 
 
int PpmParkSteerInterrupts()
{
  int v0; // r4
  unsigned int v1; // r7
  unsigned int v2; // r10
  unsigned int v3; // r1
  unsigned int v4; // r5
  unsigned int v5; // r6
  unsigned int v6; // r8
  int v7; // lr
  unsigned int v8; // r4
  unsigned int v9; // r1
  unsigned int v10; // r2
  bool v11; // cc
  int v12; // r4
  int v13; // r5
  unsigned int v14; // r1
  int v15; // lr
  unsigned int v16; // r2
  bool v17; // cf
  int v18; // r8
  unsigned int v19; // r2
  int v21; // r1
  int v22; // r4
  _BYTE *v23; // r0
  unsigned int v24; // [sp+18h] [bp-78h]
  char v25; // [sp+1Ch] [bp-74h]
  char v26; // [sp+1Ch] [bp-74h]
  __int64 v27; // [sp+20h] [bp-70h] BYREF
  unsigned int v28; // [sp+28h] [bp-68h]
  int v29; // [sp+2Ch] [bp-64h] BYREF
  int v30; // [sp+30h] [bp-60h]
  int v31; // [sp+40h] [bp-50h] BYREF
  int v32; // [sp+44h] [bp-4Ch]
  int v33; // [sp+48h] [bp-48h]
  int v34; // [sp+50h] [bp-40h] BYREF
  int v35; // [sp+54h] [bp-3Ch]
  unsigned int v36; // [sp+58h] [bp-38h]
  __int16 v37[2]; // [sp+60h] [bp-30h] BYREF
  int v38; // [sp+64h] [bp-2Ch]
  int v39; // [sp+68h] [bp-28h]

  if ( PpmIntSteerDisabled || !KiIntTrackRootEnabled )
    return 1;
  if ( !PpmIntSteerTrigger )
  {
    v22 = HalQueryMaximumProcessorCount();
    v23 = (_BYTE *)ExAllocatePoolWithTag(512, 8 * v22, 1802654793);
    PpmIntSteerTrigger = (int)v23;
    if ( v23 )
    {
      memset(v23, 0, 8 * v22);
      goto LABEL_4;
    }
    return 1;
  }
LABEL_4:
  KeIntSteerSnapPerf((int)&v29, (unsigned int *)&v27);
  v0 = dword_616318;
  KeQuerySystemAllowedCpuSetAffinity();
  v30 = 65537;
  v1 = 0;
  v2 = dword_61DB78 & ~v0;
  v34 = 65537;
  v3 = 0;
  v4 = dword_681D78[0];
  v5 = 0;
  v28 = v2;
  v6 = 0;
  v24 = 0;
  v35 = 0;
  v36 = 0;
LABEL_5:
  v7 = PpmIntSteerTrigger;
  while ( v4 )
  {
    v8 = __clz(__rbit(v4));
    v4 &= ~(1 << v8);
    ++v1;
    if ( ((v2 >> v8) & 1) == 0 )
    {
      *(_DWORD *)(v7 + 8 * v8) = 0;
      *(_DWORD *)(v7 + 8 * v8 + 4) = 0;
      v5 = v36;
      goto LABEL_5;
    }
    v24 = v3 + 1;
    if ( !*(_QWORD *)(v7 + 8 * v8) )
    {
      *(_QWORD *)(v7 + 8 * v8) = v27;
      v5 = v36;
      v7 = PpmIntSteerTrigger;
    }
    v9 = (unsigned __int64)(v27 - *(_QWORD *)(v7 + 8 * v8)) >> 32;
    v10 = (unsigned __int64)(10000i64 * *(_QWORD *)&PpmIntSteerTriggerMax) >> 32;
    v2 = v28;
    v17 = v9 >= v10;
    v11 = v9 > v10;
    v3 = v24;
    if ( v17 )
    {
      if ( v11 || (v3 = v24, (int)v27 - *(_DWORD *)(v7 + 8 * v8) >= (unsigned int)(10000 * PpmIntSteerTriggerMax)) )
      {
        v5 |= 1 << v8;
        v3 = v24;
        v36 = v5;
        ++v6;
      }
    }
  }
  if ( v6 )
  {
    v12 = v34;
    v13 = v35;
  }
  else
  {
    if ( !v3 )
      return sub_5412FC(v30, 0, &PpmIntSteerTrigger);
    v13 = 0;
    v34 = v30;
    v35 = 0;
    v12 = v30;
    v5 = v2;
    v36 = v2;
    v6 = v3;
  }
  if ( PpmIntSteerMode >= 1 )
  {
    switch ( PpmIntSteerMode )
    {
      case 1:
        v31 = *(_DWORD *)&KeActiveProcessors;
        v32 = dword_681D74;
        v33 = dword_681D78[0];
        v2 = dword_681D78[0];
        break;
      case 2:
        v31 = v12;
        v32 = v13;
        v2 = v5;
        v33 = v5;
        v1 = v6;
        break;
      case 3:
        v1 = v24;
        v31 = v30;
        v32 = 0;
        v33 = v2;
        break;
      case 5:
      case 6:
        v31 = 65537;
        v32 = 0;
        v2 = 1 << (PpmIntSteerMode - 5);
        v33 = v2;
        v1 = 1;
        break;
      default:
        goto LABEL_19;
    }
  }
  else
  {
LABEL_19:
    v14 = PpmIntSteerLoadMax + v29;
    if ( !PpmIntSteerLoadMax )
      __brkdiv0();
    v1 = v14 / PpmIntSteerLoadMax;
    if ( v14 / PpmIntSteerLoadMax >= v6 )
    {
      v1 = v6;
      v31 = v12;
      v32 = v13;
      v2 = v5;
      v33 = v5;
    }
    else
    {
      v31 = 65537;
      v37[0] = 1;
      v32 = 0;
      v33 = 0;
      v2 = 0;
      v37[1] = 1;
      v38 = 0;
      v39 = 0;
      v15 = 0;
      if ( PpmParkPreferenceHandler )
      {
        PpmParkPreferenceHandler(1, PpmParkPreferenceHandler, PpmCheckTime, dword_61E04C, v1, &v34, 0, v37, &v31);
        v15 = v39;
        v5 = v36;
        v2 = v33;
      }
      v16 = (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + (~v2 >> 24))
                            + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)(~v2 >> 16))
                            + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)v2 >> 8))
                            + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)v2));
      v17 = v16 >= v1;
      if ( v16 > v1 )
      {
        v31 = 65537;
        v16 = 0;
        v32 = 0;
        v33 = 0;
        v2 = 0;
        v17 = v1 == 0;
      }
      if ( !v17 )
      {
        v21 = v5 & ~v15;
        while ( v21 )
        {
          v25 = __clz(__rbit(v21));
          v21 &= ~(1 << v25);
          if ( ((v2 >> v25) & 1) == 0 )
          {
            v2 |= 1 << v25;
            ++v16;
            v33 = v2;
            if ( v16 >= v1 )
              goto LABEL_28;
          }
        }
        if ( v16 < v1 )
        {
          while ( v5 )
          {
            v26 = __clz(__rbit(v5));
            v5 &= ~(1 << v26);
            if ( ((v2 >> v26) & 1) == 0 )
            {
              v2 |= 1 << v26;
              ++v16;
              v33 = v2;
              if ( v16 >= v1 )
                break;
            }
          }
        }
      }
    }
  }
LABEL_28:
  if ( !v2 )
    v33 = 1;
  v18 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(&KiIntTrackSpinlock);
  }
  else
  {
    do
      v19 = __ldrex((unsigned int *)&KiIntTrackSpinlock);
    while ( __strex(1u, (unsigned int *)&KiIntTrackSpinlock) );
    __dmb(0xBu);
    if ( v19 )
      KxWaitForSpinLockAndAcquire(&KiIntTrackSpinlock);
  }
  KiIntSteerCalculateDistribution(&v31, v1);
  *(_DWORD *)&KiIntSteerMask = v31;
  dword_6217F4 = v32;
  dword_6217F8 = v33;
  KiIntSteerMaskCount = v1;
  KiIntSteerLogStatus(0);
  KiIntSteerDistributeInterrupts();
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&KiIntTrackSpinlock);
  }
  else
  {
    __dmb(0xBu);
    KiIntTrackSpinlock = 0;
  }
  KfLowerIrql(v18);
  return 1;
}
