// EtwpRealtimeFlushSavedBuffers 
 
int __fastcall EtwpRealtimeFlushSavedBuffers(int a1)
{
  int v2; // r4
  _BYTE *v4; // r0
  unsigned int v5; // r7
  __int64 v6; // r4
  int v7; // r2
  int v8; // r4
  unsigned int v9; // r3
  unsigned int v10; // r1
  bool v11; // cf
  int v12; // r3

  if ( *(_DWORD *)(a1 + 328) && *(_DWORD *)(a1 + 264) )
  {
    v4 = (_BYTE *)ExAllocatePoolWithTag(1, *(_DWORD *)(a1 + 4), 1350005829);
    v5 = (unsigned int)v4;
    if ( !v4 )
      return -1073741801;
    memset(v4, 0, *(_DWORD *)(a1 + 4));
    if ( *(_DWORD *)(a1 + 328) )
    {
      while ( *(_DWORD *)(a1 + 264) )
      {
        v6 = *(_QWORD *)(a1 + 296);
        if ( EtwpRealtimeRestoreBuffer(a1, v5) < 0 )
        {
          v2 = -1073741566;
          *(_DWORD *)(a1 + 188) += *(_DWORD *)(a1 + 328);
          *(_DWORD *)(a1 + 352) = 3;
          *(_DWORD *)(a1 + 328) = 0;
          *(_DWORD *)(a1 + 312) = 0;
          *(_DWORD *)(a1 + 316) = 0;
          EtwpSendSessionNotification((_DWORD *)a1, 4, -1073741566);
          EtwpRealtimeZeroTruncateLogfile(a1);
          ExFreePoolWithTag(v5);
          if ( (*(_DWORD *)(a1 + 608) & 1) != 0 )
            EtwpRealtimeResetReferenceTime(a1);
          return v2;
        }
        if ( EtwpRealtimeDeliverBuffer(a1, v5) < 0 )
        {
          *(_QWORD *)(a1 + 296) = v6;
          break;
        }
        if ( (*(_DWORD *)(a1 + 608) & 1) != 0 && *(_WORD *)(v5 + 54) == 3 )
          return sub_809D68();
        v7 = *(_DWORD *)(a1 + 316);
        v8 = *(_DWORD *)(a1 + 328) - 1;
        v9 = *(_DWORD *)(a1 + 312);
        *(_DWORD *)(a1 + 328) = v8;
        v10 = *(_DWORD *)(v5 + 48);
        v11 = v9 >= v10;
        *(_DWORD *)(a1 + 312) = v9 - v10;
        v12 = *(_DWORD *)(a1 + 16);
        *(_DWORD *)(a1 + 316) = v7 - !v11;
        if ( v12 < 0 && EtwpIsRealtimeLogfileSpaceAvailable(a1) == 1 )
          *(_DWORD *)(a1 + 16) = 0;
        if ( !v8 )
          break;
      }
      if ( *(_DWORD *)(a1 + 328) )
        goto LABEL_17;
    }
    EtwpRealtimeZeroTruncateLogfile(a1);
LABEL_17:
    ExFreePoolWithTag(v5);
  }
  return 0;
}
