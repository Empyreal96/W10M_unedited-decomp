// IoRaiseHardError 
 
int __fastcall IoRaiseHardError(int a1, int a2, int a3, int a4)
{
  int v5; // r9
  BOOL v7; // r0
  _DWORD *v8; // r8
  int v10; // r0
  int v11; // r4
  int v12; // r9
  unsigned int *v13; // r0
  unsigned int v14; // r4
  unsigned int v15; // r1
  int v16; // r6
  int v17; // r0
  int v18; // r4
  unsigned int *v19; // r0
  unsigned int v20; // r4
  unsigned int v21; // r1
  _DWORD *v22; // r0
  _DWORD _20[20]; // [sp+20h] [bp-38h] BYREF

  _20[16] = a1;
  _20[19] = a4;
  _20[18] = a3;
  v5 = a2;
  _20[17] = a2;
  v7 = 0;
  v8 = *(_DWORD **)(a1 + 80);
  if ( (v8[240] & 0x10) != 0 )
  {
    if ( (*(_DWORD *)(a1 + 8) & 0x40) != 0 )
      *(_DWORD *)(a1 + 28) = 0;
    return pIofCompleteRequest(a1, 1);
  }
  if ( (*(_DWORD *)(a1 + 8) & 0x3FF1FFFF) != 67 && **(_BYTE **)(a1 + 96) != 18 )
  {
    v7 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) != 0;
    if ( !v7 )
    {
      v10 = ExAllocatePoolWithTag(512, 48);
      v11 = v10;
      if ( v10 )
      {
        KeInitializeApc(
          v10,
          (int)v8,
          *(char *)(a1 + 38),
          (int)RtlpSysVolFree,
          (int)IopAbortRequest,
          (int)IopRaiseHardError,
          0,
          a1);
        return KeInsertQueueApc(v11, v5, a3, 0);
      }
      return pIofCompleteRequest(a1, 1);
    }
  }
  if ( v7 && (v8[19] & 0x400) == 0 )
  {
    v12 = 1;
    v13 = v8 + 235;
    __pld(v8 + 235);
    v14 = v8[235] & 0xFFFFFFFE;
    do
      v15 = __ldrex(v13);
    while ( v15 == v14 && __strex(v14 + 2, v13) );
    __dmb(0xBu);
    if ( v15 == v14 || ExfAcquireRundownProtection(v13) )
    {
      v16 = v8[39];
      v17 = v8[84];
      if ( v17 == *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) )
      {
        v18 = 0;
      }
      else
      {
        v18 = 1;
        KiStackAttachProcess(v17, 0, (int)_20);
      }
      if ( (*(_DWORD *)(v16 + 3880) & 0x10) == 0 )
        v12 = 0;
      if ( v18 )
        KiUnstackDetachProcess((unsigned int)_20, 0);
      v19 = v8 + 235;
      __pld(v8 + 235);
      v20 = v8[235] & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v21 = __ldrex(v19);
      while ( v21 == v20 && __strex(v20 - 2, v19) );
      if ( v21 != v20 )
        ExfReleaseRundownProtection((unsigned __int8 *)v19);
    }
    if ( v12 )
    {
      *(_DWORD *)(a1 + 28) = 0;
      return pIofCompleteRequest(a1, 1);
    }
    v5 = a2;
  }
  v22 = (_DWORD *)ExAllocatePoolWithTag(512, 28);
  if ( !v22 )
    return pIofCompleteRequest(a1, 1);
  v22[2] = IopStartApcHardError;
  v22[3] = v22;
  *v22 = 0;
  v22[4] = a1;
  v22[5] = v5;
  v22[6] = a3;
  return ExQueueWorkItem(v22, 0);
}
