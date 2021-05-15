// NtSetInformationWorkerFactory 
 
int __fastcall NtSetInformationWorkerFactory(int a1, int a2, unsigned int a3, int a4)
{
  _DWORD *v5; // r5
  int v7; // r9
  int v8; // r3
  int v9; // r8
  unsigned int v10; // r4
  int v11; // r2
  int v12; // r0
  _DWORD *v13; // r9
  unsigned int *v14; // lr
  unsigned int v15; // r1
  int v16; // r6
  unsigned int v17; // r3
  unsigned int v18; // r2
  int v19; // r4
  BOOL v20; // r6
  int v21; // r3
  int v22; // r2
  unsigned int v23; // r2
  int v24; // r3
  int v25; // r2
  unsigned int v26; // r3
  unsigned int v27; // r3
  int v28; // r2
  int v29; // r3
  int v30; // r3
  unsigned int v31; // r2
  unsigned int v32; // r0
  int v33; // r0
  unsigned int *v34; // r1
  int *v35; // r0
  unsigned int *v36; // r2
  unsigned int v37; // r0
  unsigned int *v38; // r4
  unsigned int v39; // r1
  signed int v40; // r1
  BOOL v41; // r0
  unsigned int *v42; // r3
  int v44; // [sp+14h] [bp-64h]
  int v45; // [sp+18h] [bp-60h]
  _DWORD *v46; // [sp+20h] [bp-58h] BYREF
  unsigned int *v47; // [sp+24h] [bp-54h]
  int v48; // [sp+28h] [bp-50h]
  unsigned int v49; // [sp+30h] [bp-48h]
  int v50; // [sp+34h] [bp-44h]
  int v51; // [sp+38h] [bp-40h] BYREF
  unsigned int *v52; // [sp+3Ch] [bp-3Ch]
  unsigned __int8 v53; // [sp+40h] [bp-38h]
  int v54; // [sp+48h] [bp-30h]
  int v55; // [sp+4Ch] [bp-2Ch]
  int v56; // [sp+50h] [bp-28h]
  int v57; // [sp+54h] [bp-24h]
  int vars4; // [sp+7Ch] [bp+4h]
  int varg_r0; // [sp+80h] [bp+8h]
  int varg_r1; // [sp+84h] [bp+Ch]
  unsigned int varg_r2; // [sp+88h] [bp+10h]
  int varg_r3; // [sp+8Ch] [bp+14h]

  varg_r3 = a4;
  v5 = (_DWORD *)a3;
  varg_r2 = a3;
  varg_r1 = a2;
  varg_r0 = a1;
  v7 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v49 = 0;
  v50 = 0;
  if ( a2 != 9 )
  {
    switch ( a2 )
    {
      case 2:
      case 10:
        v8 = 8;
        goto LABEL_7;
      case 3:
      case 4:
      case 5:
      case 8:
      case 11:
      case 12:
      case 13:
      case 14:
        break;
      case 6:
        return -1073741822;
      default:
        return -1073741821;
    }
  }
  v8 = 4;
LABEL_7:
  if ( a4 != v8 )
    return -1073741820;
  if ( a2 != 9 )
  {
    switch ( a2 )
    {
      case 2:
      case 6:
      case 7:
      case 9:
        if ( v7 && (a3 & 3) != 0 )
          ExRaiseDatatypeMisalignment(a1);
        goto LABEL_14;
      case 3:
      case 11:
        if ( !v7 )
          goto LABEL_37;
        if ( a3 >= MmUserProbeAddress )
          a3 = MmUserProbeAddress;
        goto LABEL_18;
      case 4:
      case 5:
      case 8:
      case 13:
      case 14:
      case 15:
        if ( v7 )
        {
          if ( a3 < MmUserProbeAddress )
LABEL_18:
            v10 = *(_DWORD *)a3;
          else
            v10 = *(_DWORD *)MmUserProbeAddress;
        }
        else
        {
          v10 = *(_DWORD *)a3;
        }
        goto LABEL_38;
      case 10:
        if ( v7 && (a3 & 3) != 0 )
          ExRaiseDatatypeMisalignment(a1);
LABEL_14:
        v10 = *(_DWORD *)a3;
        v49 = *(_DWORD *)a3;
        v11 = *(_DWORD *)(a3 + 4);
        v50 = v5[1];
        goto LABEL_40;
      case 12:
        if ( v7 )
        {
          if ( a3 >= MmUserProbeAddress )
            a3 = MmUserProbeAddress;
          *(_DWORD *)a3 = *(_DWORD *)a3;
        }
        v10 = v49;
        goto LABEL_39;
    }
  }
  if ( v7 )
  {
    if ( (a3 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a3 + 4 > MmUserProbeAddress || a3 + 4 < a3 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
LABEL_37:
  v10 = *(_DWORD *)a3;
LABEL_38:
  v49 = v10;
LABEL_39:
  v11 = v50;
LABEL_40:
  v44 = v11;
  v9 = ObReferenceObjectByHandle(a1, 4, ExpWorkerFactoryObjectType, v7, &v46, 0);
  if ( v9 >= 0 )
  {
    if ( a2 == 8 )
    {
      v12 = (int)v46;
      if ( !v10 )
        v10 = KeNumberProcessors_0;
      *(_DWORD *)(*(_DWORD *)(v46[1] + 4) + 28) = v10;
      ObfDereferenceObjectWithTag(v12);
      return 0;
    }
    v9 = 0;
    v48 = 0;
    v45 = 0;
    v13 = v46;
    v47 = (unsigned int *)v46[1];
    v52 = v47;
    v51 = 0;
    __dmb(0xBu);
    v53 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireQueuedSpinLockInstrumented(&v51, v47);
    }
    else
    {
      v14 = v47;
      do
        v15 = __ldrex(v14);
      while ( __strex((unsigned int)&v51, v14) );
      __dmb(0xBu);
      if ( v15 )
        KxWaitForLockOwnerShip(&v51);
    }
    if ( a2 == 9 )
    {
LABEL_117:
      switch ( v10 )
      {
        case 0u:
          v28 = v13[16];
          if ( v28 == v13[17] )
            v9 = -1073741823;
          else
            v13[16] = v28 + 1;
          v19 = 1;
          v20 = 0;
          break;
        case 1u:
          goto LABEL_125;
        case 2u:
          v29 = v13[16];
          if ( !v29 )
          {
            v9 = -1073741823;
            goto LABEL_133;
          }
          v30 = v29 - 1;
          v13[16] = v30;
          if ( v30 )
            goto LABEL_130;
LABEL_125:
          v20 = 1;
          v45 = 0;
          v19 = 1;
          break;
        case 3u:
          if ( !v13[16] )
          {
            v9 = -1073741823;
            goto LABEL_133;
          }
          ExpRemoveCurrentThreadFromThreadHistory((unsigned int)v13);
          --v13[16];
          --v13[17];
          if ( v13[16] )
            goto LABEL_130;
          v20 = 1;
          v45 = 0;
          v19 = 1;
          break;
        default:
          goto LABEL_67;
      }
    }
    else
    {
      switch ( a2 )
      {
        case 2:
          v21 = v44;
          if ( v44 < 0 )
          {
            if ( v44 < -1 || (v22 = -10000000, v10 <= 0xFF676980) )
            {
              if ( v44 > -2 )
                goto LABEL_66;
              v22 = -1705032704;
              if ( v44 >= -2 && v10 >= 0x9A5F4400 )
                goto LABEL_66;
              v21 = -2;
            }
            else
            {
              v21 = -1;
            }
            v10 = v22;
LABEL_66:
            v13[12] = v10;
            v13[13] = v21;
            v54 = 0;
            v55 = 0;
            v56 = -1;
            v57 = -1;
            KeSetTimer2(v13 + 26);
            goto LABEL_133;
          }
LABEL_67:
          v9 = -1073741811;
LABEL_133:
          v19 = 1;
LABEL_134:
          v20 = 0;
          break;
        case 3:
          v23 = v13[21];
          if ( (v10 & 0x80000000) != 0 )
          {
            if ( v23 <= -v10 )
              v24 = 0;
            else
              v24 = v23 + v10;
          }
          else
          {
            v24 = v23 + v10;
            if ( v23 >= v23 + v10 )
              v24 = -1;
          }
          v13[21] = v24;
          if ( !v23 )
          {
            if ( v24 && ExpTryEnterWorkerFactoryAwayMode(v13) )
            {
              ExpWorkerFactoryCheckCreate(v13, &v51, 0);
              v19 = 0;
              goto LABEL_134;
            }
            goto LABEL_130;
          }
          if ( v13[21] )
            goto LABEL_130;
          if ( (v13[22] & 0x200) != 0 )
            ExpLeaveWorkerFactoryAwayMode(v13);
          goto LABEL_133;
        case 4:
          if ( *(_BYTE *)(v13[1] + 21) )
            goto LABEL_132;
          v20 = v10 > v13[14];
          v13[14] = v10;
          if ( v13[15] < v10 )
            v13[15] = v10;
          if ( !v20 )
            goto LABEL_131;
          v20 = 0;
          if ( (v13[22] & 0x200) != 0 )
            ExpLeaveWorkerFactoryAwayMode(v13);
          if ( (unsigned int)(v13[18] + v13[16]) >= v13[14] )
            goto LABEL_102;
          while ( 1 )
          {
            ++v13[20];
            KeReleaseInStackQueuedSpinLock(&v51);
            v9 = ExpWorkerFactoryCreateThread(v13);
            KeAcquireInStackQueuedSpinLock(v13[1], &v51);
            if ( v9 < 0 )
              break;
            if ( (unsigned int)(v13[18] + v13[16]) >= v13[14] )
            {
              v19 = 1;
              goto LABEL_135;
            }
          }
          --v13[20];
          v19 = 1;
          break;
        case 5:
          v25 = v13[1];
          if ( *(_BYTE *)(v25 + 21) )
            goto LABEL_132;
          v45 = 1;
          v20 = v10 && (!v13[15] && *(_DWORD *)(v25 + 12) || *(int *)(*(_DWORD *)(v25 + 4) + 4) > 0);
          v13[15] = v10;
          if ( v10 >= v13[14] )
            goto LABEL_131;
          v13[14] = v10;
LABEL_102:
          v19 = 1;
          break;
        case 6:
        case 7:
        case 8:
        case 9:
          goto LABEL_117;
        case 10:
          if ( *(_BYTE *)(v13[1] + 21) )
          {
            v9 = 128;
          }
          else
          {
            v13[7] = v44;
            v13[6] = v10;
          }
          v19 = 1;
          v20 = 0;
          break;
        case 11:
          if ( *(_BYTE *)(v13[1] + 21) )
            v9 = 128;
          v13[23] = v10;
          goto LABEL_133;
        case 12:
          v16 = 0;
          if ( !v13[20] )
          {
            v17 = v13[16];
            v18 = v13[14];
            if ( v17 > v18 )
              v16 = KeTimeOutQueueWaiters(*(_DWORD *)(v13[1] + 4), 0i64, v17 - v18);
          }
          KeReleaseInStackQueuedSpinLock(&v51);
          v19 = 0;
          *v5 = v16;
          v20 = 0;
          break;
        case 13:
          v13[22] ^= ((unsigned __int16)v13[22] ^ (((v10 & 1) != 0) << 11)) & 0x800;
          goto LABEL_133;
        case 14:
          if ( *(_BYTE *)(v13[1] + 21) )
          {
LABEL_132:
            v9 = 128;
            goto LABEL_133;
          }
          v13[19] = v10;
          if ( v10 )
          {
            v26 = v13[14];
            if ( v10 < v26 )
            {
              v13[19] = v26;
              goto LABEL_133;
            }
            v27 = v13[15];
            if ( v10 > v27 )
            {
              v13[19] = v27;
              goto LABEL_133;
            }
          }
LABEL_130:
          v20 = 0;
LABEL_131:
          v19 = 1;
          break;
      }
    }
LABEL_135:
    if ( v20 )
    {
      v31 = v13[16];
      if ( *(_BYTE *)(v13[1] + 21) )
      {
        v9 = 128;
      }
      else
      {
        v32 = v13[15];
        if ( v31 < v32 )
        {
          if ( v13[20] || v13[18] + v31 >= v32 )
            goto LABEL_147;
          if ( (v13[22] & 0x200) != 0 )
            ExpLeaveWorkerFactoryAwayMode(v13);
          ++v13[20];
          KeReleaseInStackQueuedSpinLock(&v51);
          v19 = 0;
          v9 = ExpWorkerFactoryCreateThread(v13);
          if ( v9 < 0 )
          {
            v19 = 1;
            KeAcquireInStackQueuedSpinLock(v13[1], &v51);
            --v13[20];
            if ( v45 )
LABEL_147:
              v9 = 0;
          }
        }
        else if ( !v45 )
        {
          v9 = -1073741527;
        }
      }
    }
    if ( !v19 )
      goto LABEL_160;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(&v51, vars4);
    }
    else
    {
      v33 = v51;
      if ( !v51 )
      {
        v34 = v52;
        __dmb(0xBu);
        do
          v35 = (int *)__ldrex(v34);
        while ( v35 == &v51 && __strex(0, v34) );
        if ( v35 == &v51 )
          goto LABEL_159;
        v33 = KxWaitForLockChainValid(&v51);
      }
      v51 = 0;
      __dmb(0xBu);
      v36 = (unsigned int *)(v33 + 4);
      do
        v37 = __ldrex(v36);
      while ( __strex(v37 ^ 1, v36) );
    }
LABEL_159:
    KfLowerIrql(v53);
LABEL_160:
    v38 = v13 - 6;
    if ( ObpTraceFlags )
      ObpPushStackInfo(v13 - 6, 0, 1, 1953261124);
    __dmb(0xBu);
    do
    {
      v39 = __ldrex(v38);
      v40 = v39 - 1;
    }
    while ( __strex(v40, v38) );
    if ( v40 <= 0 )
    {
      if ( *(v13 - 5) )
        KeBugCheckEx(
          24,
          ObTypeIndexTable[(unsigned __int8)((unsigned __int16)((_WORD)v13 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *((unsigned __int8 *)v13 - 12)],
          v13);
      if ( v40 < 0 )
        KeBugCheckEx(24, 0, v13);
      if ( *(_WORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x136)
        || !(v41 = KeAreInterruptsEnabled())
        || KeGetCurrentIrql(v41) )
      {
        ObpDeferObjectDeletion((unsigned int)(v13 - 6));
      }
      else
      {
        __dmb(0xBu);
        if ( (*((_BYTE *)v13 - 10) & 0x40) != 0 )
        {
          v42 = (unsigned int *)ObpInfoMaskToOffset[*((_BYTE *)v13 - 10) & 0x7F];
          if ( v38 != v42 )
            ObpHandleRevocationBlockRemoveObject((char *)v38 - (char *)v42);
        }
        if ( ObpTraceFlags )
          ObpDeregisterObject(v13 - 6);
        __dmb(0xBu);
        ObpRemoveObjectRoutine(v13 - 6, 0);
      }
    }
  }
  return v9;
}
