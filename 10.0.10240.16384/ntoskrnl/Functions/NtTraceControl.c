// NtTraceControl 
 
int __fastcall NtTraceControl(int a1, unsigned int a2, int a3, int a4, unsigned int a5, unsigned int a6)
{
  int v7; // r0
  int v8; // r6
  unsigned int v9; // r10
  unsigned int v10; // r2
  unsigned int v11; // r8
  _DWORD *v12; // r4
  unsigned int *v13; // r9
  _DWORD *v14; // r2
  int *v15; // r1
  unsigned int v16; // r1
  int v17; // r2
  unsigned int v18; // r1
  int v19; // r0
  unsigned int v21; // [sp+4h] [bp-3Ch] BYREF
  unsigned int v22; // [sp+8h] [bp-38h]
  int v23; // [sp+Ch] [bp-34h]
  int *v24; // [sp+10h] [bp-30h] BYREF
  int v25; // [sp+14h] [bp-2Ch]
  int v26; // [sp+18h] [bp-28h]
  int varg_r0; // [sp+48h] [bp+8h]
  unsigned int varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]
  int varg_r3; // [sp+54h] [bp+14h]

  v23 = a4;
  varg_r3 = a4;
  v22 = a3;
  varg_r2 = a3;
  v24 = (int *)a2;
  varg_r1 = a2;
  varg_r0 = a1;
  v7 = 0;
  v8 = 0;
  v25 = 0;
  v9 = 0;
  v21 = 0;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    if ( a2 )
    {
      if ( a3 )
      {
        v10 = a2 + a3;
        if ( v10 > MmUserProbeAddress || v10 < a2 )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
    }
    else
    {
      v22 = 0;
      varg_r2 = 0;
    }
    if ( a4 )
    {
      v11 = a5;
      v7 = ProbeForWrite(v23, a5, 1);
    }
    else
    {
      v11 = 0;
    }
    v12 = (_DWORD *)a6;
    if ( !a6 )
    {
      v8 = -1073741811;
      v13 = 0;
      goto LABEL_125;
    }
    v14 = (_DWORD *)a6;
    if ( a6 >= MmUserProbeAddress )
      v14 = (_DWORD *)MmUserProbeAddress;
    *v14 = *v14;
    v13 = 0;
    v15 = v24;
  }
  else
  {
    v12 = (_DWORD *)a6;
    v11 = a5;
    v13 = 0;
    v15 = v24;
  }
  if ( a1 != 27 && a1 != 14 && a1 != 12 && (v22 || v11) )
  {
    if ( v22 <= v11 )
      v16 = v11;
    else
      v16 = v22;
    v7 = ExAllocatePoolWithQuotaTag(9u, v16, 1350005829);
    v13 = (unsigned int *)v7;
    v25 = v7;
    if ( !v7 )
    {
      v8 = -1073741801;
      goto LABEL_125;
    }
    if ( v24 )
    {
      v7 = memmove(v7, (int)v24, v22);
      v15 = v24;
    }
    else
    {
      v15 = 0;
    }
  }
  v17 = a1 - 1;
  switch ( a1 )
  {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      if ( v22 < 0xB0 || v11 < 0xB0 )
        goto LABEL_36;
      v8 = EtwpValidateLoggerInfo(v13);
      if ( v8 >= 0 )
      {
        if ( *v13 > v18 )
LABEL_36:
          v8 = -1073741306;
        else
          v8 = 0;
      }
      if ( v8 >= 0 )
      {
        if ( a1 == 3 )
        {
          v19 = EtwpQueryTrace(v13);
LABEL_45:
          v8 = v19;
        }
        else
        {
          switch ( v17 )
          {
            case 0:
              v19 = EtwpStartTrace(v13);
              goto LABEL_45;
            case 1:
              v19 = EtwpStopTrace(v13, 0);
              goto LABEL_45;
            case 3:
              v19 = EtwpUpdateTrace(v13);
              goto LABEL_45;
            case 4:
              v19 = EtwpFlushTrace(v13);
              goto LABEL_45;
            default:
              break;
          }
        }
        v9 = 176;
      }
LABEL_110:
      if ( v8 >= 0 )
      {
        if ( v9 )
          memmove(v23, (int)v13, v9);
        *v12 = v9;
      }
      if ( v8 == -1073741789 && (a1 == 16 || a1 == 15 || a1 == 21 || a1 == 22)
        || a1 == 23
        || a1 == 19
        || a1 == 32
        || a1 == 33
        || a1 == 34 )
      {
        *v12 = v9;
      }
LABEL_125:
      if ( v13 )
        ExFreePoolWithTag((unsigned int)v13);
      return v8;
    case 11:
      if ( v22 != 96 || v11 != 96 )
        goto LABEL_74;
      v8 = EtwpRealtimeConnect(v13, v15);
      v9 = 96;
      goto LABEL_110;
    case 12:
      if ( v11 != 16 )
        goto LABEL_74;
      v8 = 0;
      EtwpCreateActivityId(v23);
      goto LABEL_110;
    case 13:
      if ( v22 != 48 || v11 )
        goto LABEL_74;
      v8 = WdiDispatchControl(v13, v15);
      goto LABEL_110;
    case 14:
      if ( v22 != 8 || v11 )
        goto LABEL_74;
      v26 = *v15;
      v8 = EtwpRealtimeDisconnectConsumerByHandle();
      goto LABEL_110;
    case 15:
      if ( v22 != 160 || v11 - 160 > 0xFF60 )
        goto LABEL_74;
      v8 = EtwpRegisterUMGuid(v13, v11, &v21);
      v9 = v21;
      goto LABEL_110;
    case 16:
      if ( v22 || v11 - 72 > 0xFFB8 )
        goto LABEL_74;
      v8 = EtwpReceiveNotification(v13, v11, &v21);
      v9 = v21;
      goto LABEL_110;
    case 17:
      if ( v22 < 0x48 || v11 != 72 || v13[1] != v22 )
        goto LABEL_74;
      if ( *v13 == 3 )
      {
        if ( v22 < 0x78 )
          goto LABEL_74;
        v8 = EtwpEnableGuid(v13, 1);
        v9 = 72;
      }
      else
      {
        v8 = EtwpNotifyGuid(v13, 1);
        v9 = 72;
      }
      goto LABEL_110;
    case 18:
      if ( v22 < 0x48 || v13[1] != v22 )
        goto LABEL_74;
      v13[9] = PsGetCurrentThreadProcessId();
      v8 = EtwpSendReplyDataBlock(v13);
      goto LABEL_110;
    case 19:
      if ( v22 != 8 )
        goto LABEL_74;
      v8 = EtwpReceiveReplyDataBlock(v13, v11, &v24);
      v9 = (unsigned int)v24;
      goto LABEL_110;
    case 20:
      if ( v22 || v11 )
        goto LABEL_74;
      v8 = WdiUpdateSem();
      goto LABEL_110;
    case 21:
      v21 = v11;
      v8 = EtwpGetTraceGuidList(v13, &v21);
      v9 = v21;
      goto LABEL_110;
    case 22:
      if ( v22 != 16 )
        goto LABEL_74;
      v21 = v11;
      v8 = EtwpGetTraceGuidInfo(v13, v13, &v21);
      v9 = v21;
      goto LABEL_110;
    case 23:
      v21 = v11;
      v8 = EtwpEnumerateTraceGuids(v13, &v21);
      v9 = v21;
      goto LABEL_110;
    case 24:
      if ( v22 || v11 )
        goto LABEL_74;
      v8 = EtwpRegisterSecurityProvider(v7, v15);
      goto LABEL_110;
    case 25:
      if ( v22 != 4 || v11 != 16 )
        goto LABEL_74;
      v8 = EtwpQueryReferenceTime(*v13, v13);
      v9 = 16;
      goto LABEL_110;
    case 26:
      if ( v22 != 8 )
        goto LABEL_74;
      v8 = EtwpTrackProviderBinary(v13, v15);
      v9 = 0;
      goto LABEL_110;
    case 27:
      if ( v22 != 4 )
        goto LABEL_74;
      if ( !*v15 )
        goto LABEL_74;
      v8 = EtwpAddNotificationEvent();
      goto LABEL_110;
    case 28:
      if ( v22 < 8 || 16 * v13[1] + 8 != v22 )
        goto LABEL_74;
      EtwpUpdateDisallowList(*v13);
      goto LABEL_110;
    case 30:
      if ( v22 != 24 || v11 - 120 > 0xFF88 )
        goto LABEL_74;
      v8 = EtwpSetProviderTraitsUm(v13, v11, &v21);
      v9 = v21;
      goto LABEL_110;
    case 31:
      if ( v22 != 16 || v11 )
        goto LABEL_74;
      v8 = EtwpUseDescriptorTypeUm(v13, v15);
      goto LABEL_110;
    case 32:
      v21 = v11;
      v8 = EtwpGetTraceGroupList(v13, &v21);
      v9 = v21;
      goto LABEL_110;
    case 33:
      if ( v22 != 16 )
        goto LABEL_74;
      v21 = v11;
      v8 = EtwpGetTraceGroupInfo(v13, v13, &v21);
      v9 = v21;
      goto LABEL_110;
    case 34:
      if ( v22 == 8 )
      {
        v21 = v11;
        v8 = EtwpGetDisallowList(v13, v13, &v21);
        v9 = v21;
      }
      else
      {
LABEL_74:
        v8 = -1073741811;
      }
      goto LABEL_110;
    default:
      v8 = -1073741808;
      goto LABEL_110;
  }
}
