// EtwpInitLoggerContext 
 
int __fastcall EtwpInitLoggerContext(unsigned __int16 *a1, int a2)
{
  int v2; // r6
  int v4; // r7
  unsigned int v6; // r0
  _BYTE *v7; // r0
  int v8; // r4
  _BYTE *v9; // r0
  void *v11; // r3
  int v12; // r3
  unsigned int v13; // r0
  int v14; // r1
  unsigned int v15; // r3
  int v16; // r3
  int v17; // r3
  int v18; // r3

  v2 = 0;
  v4 = *a1 + 658;
  if ( (a2 & 0x10000000) == 0 )
  {
    v6 = KeQueryMaximumProcessorCountEx(0xFFFFu, a2);
    if ( v6 > 0x20 )
      v2 = 4 * v6;
  }
  v7 = (_BYTE *)ExAllocatePoolWithTag(516, v2 + v4, 1282896965);
  v8 = (int)v7;
  if ( v7 )
  {
    v9 = memset(v7, 0, v2 + v4);
    if ( v2 )
      return sub_809F18(v9);
    memmove(v8 + 656, *((_DWORD *)a1 + 1), *a1);
    RtlInitUnicodeString(v8 + 92, (unsigned __int16 *)(v8 + 656));
    *(_DWORD *)(v8 + 12) = a2;
    *(_DWORD *)(v8 + 24) = -1072889856;
    *(_DWORD *)(v8 + 28) = 0xFFFF;
    *(_DWORD *)(v8 + 20) = -1072562176;
    if ( (a2 & 0x1000000) != 0 )
      *(_DWORD *)(v8 + 224) = 1;
    else
      *(_DWORD *)(v8 + 224) = 512;
    if ( a2 < 0 )
    {
      v12 = *(_DWORD *)(v8 + 12);
      if ( (v12 & 0x1000000) != 0 )
        *(_DWORD *)(v8 + 12) = v12 & 0x7FFFFFFF;
    }
    if ( EtwpFileSystemReady )
      *(_DWORD *)(v8 + 608) |= 4u;
    if ( (a2 & 0x8000) != 0 )
    {
      v11 = (void *)(v8 + 196);
    }
    else
    {
      if ( (a2 & 0x4000) == 0 )
        goto LABEL_22;
      v11 = &EtwpGlobalSequence;
    }
    *(_DWORD *)(v8 + 192) = v11;
LABEL_22:
    *(_DWORD *)(v8 + 248) = 1;
    v13 = MmGetNumberOfPhysicalPages(0);
    v15 = (v13 >> 8) & 0xFFF | (v13 >> 20 << 12);
    if ( v15 > 0x200 )
    {
      if ( v15 <= 0x400 )
      {
        *(_DWORD *)(v8 + 4) = v14;
LABEL_28:
        if ( (*(_DWORD *)(v8 + 12) & 0x10000000) != 0 )
          v17 = 1;
        else
          v17 = KeNumberProcessors_0;
        v18 = 2 * v17;
        *(_DWORD *)(v8 + 152) = v18;
        *(_DWORD *)(v8 + 164) = v18 + 22;
        KeQuerySystemTimePrecise((__int64 *)(v8 + 584));
        KeInitializeMutex(v8 + 472);
        *(_DWORD *)(v8 + 504) = 0;
        *(_DWORD *)(v8 + 256) = v8 + 256;
        *(_DWORD *)(v8 + 260) = v8 + 256;
        *(_DWORD *)(v8 + 48) = v8 + 56;
        *(_DWORD *)(v8 + 52) = v8 + 56;
        *(_DWORD *)(v8 + 60) = v8 + 68;
        *(_DWORD *)(v8 + 64) = v8 + 68;
        *(_DWORD *)(v8 + 72) = v8 + 72;
        *(_DWORD *)(v8 + 76) = v8 + 72;
        *(_DWORD *)(v8 + 80) = v8 + 80;
        *(_DWORD *)(v8 + 84) = v8 + 80;
        *(_DWORD *)(v8 + 632) = v8 + 632;
        *(_DWORD *)(v8 + 636) = v8 + 632;
        *(_WORD *)(v8 + 644) = 0;
        *(_DWORD *)(v8 + 648) = 0;
        *(_DWORD *)(v8 + 508) = 0;
        KeInitializeEvent(v8 + 356, 0, 0);
        KeInitializeEvent(v8 + 372, 1, 0);
        KeInitializeTimerEx((_DWORD *)(v8 + 392), 1);
        KeInitializeDpc(v8 + 440, (int)EtwpLoggerDpc, v8);
        *(_BYTE *)(v8 + 441) = 3;
        *(_DWORD *)(v8 + 652) = PsGetCurrentServerSilo();
        return v8;
      }
      v16 = 0x10000;
    }
    else
    {
      v16 = 0x2000;
    }
    *(_DWORD *)(v8 + 4) = v16;
    goto LABEL_28;
  }
  return 0;
}
