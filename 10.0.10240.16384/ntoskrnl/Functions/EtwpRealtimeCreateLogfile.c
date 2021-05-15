// EtwpRealtimeCreateLogfile 
 
int __fastcall EtwpRealtimeCreateLogfile(int a1)
{
  int v2; // r5
  unsigned int v4; // r6
  unsigned __int16 *v5; // r0
  unsigned __int16 *v6; // r5
  int v7; // r3
  unsigned __int16 *v8; // r2
  unsigned int v9; // r3
  int v10; // t1
  int v11; // r3
  char v12[8]; // [sp+8h] [bp-20h] BYREF
  _DWORD v13[6]; // [sp+10h] [bp-18h] BYREF

  if ( *(_DWORD *)(a1 + 272) )
    return 0;
  RtlInitUnicodeString((unsigned int)v13, 0);
  if ( *(_WORD *)(a1 + 276) )
  {
LABEL_23:
    v12[0] = (*(_DWORD *)(a1 + 608) & 1) != 0;
    v2 = ((int (__fastcall *)(int, int, char *, _DWORD, int, int))EtwpDelayCreate)(a1 + 272, a1 + 276, v12, 0, 1, 1);
    if ( v2 >= 0 )
    {
      *(_DWORD *)(a1 + 296) = 72;
      *(_DWORD *)(a1 + 288) = 72;
      *(_DWORD *)(a1 + 304) = 72;
      v11 = *(_DWORD *)(a1 + 608);
      *(_DWORD *)(a1 + 300) = 0;
      *(_DWORD *)(a1 + 292) = 0;
      *(_DWORD *)(a1 + 308) = 0;
      if ( (v11 & 1) != 0 )
      {
        v2 = EtwpRealtimeRestoreState(a1);
        if ( v2 < 0 )
          goto LABEL_33;
        if ( *(_DWORD *)(a1 + 328) )
          v2 = EtwpRealtimeUpdateReferenceTime(a1, a1 + 232);
        if ( v2 < 0 )
        {
LABEL_33:
          EtwpRealtimeZeroTruncateLogfile(a1);
          EtwpRealtimeResetReferenceTime(a1);
          *(_DWORD *)(a1 + 188) += *(_DWORD *)(a1 + 328);
          *(_DWORD *)(a1 + 352) = 3;
          *(_DWORD *)(a1 + 328) = 0;
          EtwpSendSessionNotification((_DWORD *)a1, 4, -1073741566);
          v2 = 0;
        }
      }
    }
    goto LABEL_25;
  }
  v4 = wcslen(*(unsigned __int16 **)(a1 + 96)) + 10;
  v5 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 2 * v4, 1350005829);
  v6 = v5;
  if ( !v5 )
    return sub_809E28();
  if ( RtlStringCbPrintfW(v5, 2 * v4, (int)L"EtwRT%ws.etl", *(_DWORD *)(a1 + 96)) )
  {
    ExFreePoolWithTag((unsigned int)v6);
    return -1073741811;
  }
  v7 = *v6;
  v8 = v6;
  while ( v7 )
  {
    v9 = *v8;
    if ( v9 <= 0x3C )
    {
      if ( v9 == 60 || v9 == 34 || v9 == 47 || v9 == 58 )
      {
LABEL_20:
        *v8 = 95;
        goto LABEL_15;
      }
    }
    else if ( *v8 >= 0x3Eu && (*v8 <= 0x3Fu || v9 == 92 || v9 == 124) )
    {
      goto LABEL_20;
    }
LABEL_15:
    v10 = v8[1];
    ++v8;
    v7 = v10;
  }
  if ( RtlCreateUnicodeString(a1 + 276, (unsigned __int16 *)EtwpRTBacklogFileRoot) )
  {
    RtlInitUnicodeString((unsigned int)v13, v6);
    v2 = EtwpExpandFileName(1, a1 + 276, 0, v13);
    if ( v2 >= 0 )
      goto LABEL_23;
  }
  else
  {
    v2 = -1073741801;
  }
LABEL_25:
  RtlFreeAnsiString(v13);
  return v2;
}
