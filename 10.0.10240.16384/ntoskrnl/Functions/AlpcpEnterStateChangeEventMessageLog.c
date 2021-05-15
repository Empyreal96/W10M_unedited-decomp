// AlpcpEnterStateChangeEventMessageLog 
 
unsigned int __fastcall AlpcpEnterStateChangeEventMessageLog(_DWORD *a1)
{
  int v2; // r0
  int v3; // r4
  unsigned int v4; // r2
  int v5; // r0
  int v6; // r5
  int v7; // r9
  _DWORD *v8; // r4
  int *v9; // r0
  int **v10; // r1
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r3
  int **v15; // r2
  unsigned int v16; // r1
  int vars4; // [sp+1Ch] [bp+4h]

  v2 = KeAbPreAcquire((unsigned int)&AlpcpMessageLogLock, 0, 0);
  v3 = v2;
  do
    v4 = __ldrex((unsigned __int8 *)&AlpcpMessageLogLock);
  while ( __strex(v4 | 1, (unsigned __int8 *)&AlpcpMessageLogLock) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&AlpcpMessageLogLock, v2, (unsigned int)&AlpcpMessageLogLock);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v5 = AlpcpLocateMessageLog(a1[34]);
  v6 = v5;
  if ( v5 )
  {
    v7 = v5 + 28;
    if ( *(_DWORD *)(v5 + 28) == v5 + 28
      || (v8 = *(_DWORD **)(v5 + 32)) == 0
      || v8[2] != a1[5]
      || v8[4] != a1[3]
      || v8[5] != a1[2]
      || v8[7] != a1[4]
      || v8[6] != a1[9]
      || v8[8] != a1[14]
      || v8[9] != a1[15]
      || memcmp((unsigned int)(v8 + 12), (unsigned int)(a1 + 30), 24) )
    {
      v9 = (int *)AlpcpAllocateSnapshotMessageLog();
      if ( *(_DWORD *)(v6 + 24) )
      {
        v9[2] = a1[5];
        v9[4] = a1[3];
        v9[5] = a1[2];
        v9[6] = a1[9];
        v9[7] = a1[4];
        v9[8] = a1[14];
        v9[9] = a1[15];
        v9[10] = vars4;
        v9[3] = 0;
        v11 = a1[31];
        v12 = a1[32];
        v13 = a1[33];
        v9[12] = a1[30];
        v9[13] = v11;
        v9[14] = v12;
        v9[15] = v13;
        v14 = a1[35];
        v9[16] = a1[34];
        v9[17] = v14;
        v15 = *(int ***)(v7 + 4);
        *v9 = v7;
        v9[1] = (int)v15;
        if ( *v15 != (int *)v7 )
          __fastfail(3u);
        *v15 = v9;
        *(_DWORD *)(v7 + 4) = v9;
      }
      else
      {
        v10 = (int **)dword_6212CC;
        *v9 = (int)&AlpcpFreeMessageSnapshotListHead;
        v9[1] = (int)v10;
        if ( *v10 != &AlpcpFreeMessageSnapshotListHead )
          __fastfail(3u);
        *v10 = v9;
        dword_6212CC = (int)v9;
      }
    }
  }
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)&AlpcpMessageLogLock);
  while ( __strex(v16 - 1, (unsigned int *)&AlpcpMessageLogLock) );
  if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&AlpcpMessageLogLock);
  return KeAbPostRelease((unsigned int)&AlpcpMessageLogLock);
}
