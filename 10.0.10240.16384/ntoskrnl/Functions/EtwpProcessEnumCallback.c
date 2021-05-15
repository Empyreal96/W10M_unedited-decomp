// EtwpProcessEnumCallback 
 
int __fastcall EtwpProcessEnumCallback(int a1, int a2)
{
  int v3; // r4
  int *v4; // r6
  char v6; // r10
  char v8; // r9
  int v9; // r2
  unsigned int v10; // r9
  void **v11; // r4
  _DWORD *v12; // r3
  unsigned int *v13; // r0
  unsigned int v14; // r4
  unsigned int v15; // r1
  unsigned int v16; // r9
  void **v17; // r4
  _DWORD *i; // r3
  unsigned int *v19; // r0
  unsigned int v20; // r4
  unsigned int v21; // r1
  int v22; // [sp+0h] [bp-48h]
  int v23; // [sp+4h] [bp-44h]
  int v24; // [sp+8h] [bp-40h]
  char v25[56]; // [sp+10h] [bp-38h] BYREF

  v3 = *(_DWORD *)(a2 + 16);
  v4 = *(int **)a2;
  v22 = v3;
  v23 = 0;
  v24 = *(unsigned __int8 *)(a2 + 36);
  v6 = 0;
  *(_BYTE *)(a2 + 37) = 0;
  if ( EtwpIsProcessZombie() )
    return sub_7CF8E8();
  v8 = 1;
  if ( a1 == PsIdleProcess )
  {
    v8 = 0;
    v6 = 1;
  }
  else if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) != a1 )
  {
    v13 = (unsigned int *)(a1 + 172);
    __pld((void *)(a1 + 172));
    v14 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
    do
      v15 = __ldrex(v13);
    while ( v15 == v14 && __strex(v14 + 2, v13) );
    __dmb(0xBu);
    if ( v15 == v14 || ExfAcquireRundownProtection(v13) )
    {
      KiStackAttachProcess(a1, 0, (int)v25);
      v23 = 1;
    }
    else
    {
      v8 = 0;
    }
    v3 = v22;
  }
  *(_BYTE *)(a2 + 39) = v6;
  *(_BYTE *)(a2 + 37) = v8;
  if ( v24 )
  {
    if ( v4 )
    {
      if ( (*v4 & 1) != 0 )
        EtwpTraceProcessRundown(a1, v3, 771, a2);
      if ( (*v4 & 2) != 0 )
      {
        if ( a1 == PsIdleProcess )
        {
          v10 = 0;
          if ( KeNumberProcessors_0 )
          {
            v11 = &KiProcessorBlock;
            if ( !KeNumberProcessors_0 )
            {
              v12 = 0;
              goto LABEL_24;
            }
            do
            {
              v12 = *v11;
LABEL_24:
              EtwpThreadEnumCallback(a1, v12[3], a2);
              ++v10;
              ++v11;
            }
            while ( v10 < KeNumberProcessors_0 );
          }
        }
        else
        {
          PsEnumProcessThreads(a1, EtwpThreadEnumCallback, a2);
        }
      }
      v9 = *v4;
      if ( (*v4 & 0xC004) != 0 )
        EtwpEnumerateAddressSpace(a1, a2, (int)v4);
      if ( (*v4 & 4) != 0 && a1 == PsInitialSystemProcess )
        EtwpSysModuleRunDown(v22, v24);
      if ( (v4[1] & 0x8000000) != 0 )
        EtwpEnumerateWorkingSet(a1, a2, v9);
    }
  }
  else if ( v4 )
  {
    if ( (v4[1] & 0x8000000) != 0 )
      EtwpEnumerateWorkingSet(a1, a2, 1);
    if ( (*v4 & 4) != 0 && a1 == PsInitialSystemProcess )
      EtwpSysModuleRunDown(v3, 0);
    if ( (*v4 & 0xC004) != 0 )
      EtwpEnumerateAddressSpace(a1, a2, (int)v4);
    if ( (v4[4] & 0x40) != 0 && a1 != PsIdleProcess )
      EtwpObjectHandleRundown(a1, a2);
    if ( (*v4 & 2) != 0 )
    {
      if ( a1 == PsIdleProcess )
      {
        v16 = 0;
        if ( KeNumberProcessors_0 )
        {
          v17 = &KiProcessorBlock;
          if ( KeNumberProcessors_0 )
            goto LABEL_53;
          for ( i = 0; ; i = *v17 )
          {
            EtwpThreadEnumCallback(a1, i[3], a2);
            ++v16;
            ++v17;
            if ( v16 >= KeNumberProcessors_0 )
              break;
LABEL_53:
            ;
          }
        }
      }
      else
      {
        PsEnumProcessThreads(a1, EtwpThreadEnumCallback, a2);
      }
    }
    if ( (*v4 & 8) != 0 )
      EtwpProcessPerfCtrsRundown(a1, v22);
    if ( (*v4 & 1) != 0 )
      EtwpTraceProcessRundown(a1, v22, 772, a2);
  }
  if ( v23 )
  {
    KiUnstackDetachProcess((unsigned int)v25, 0);
    v19 = (unsigned int *)(a1 + 172);
    __pld((void *)(a1 + 172));
    v20 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v21 = __ldrex(v19);
    while ( v21 == v20 && __strex(v20 - 2, v19) );
    if ( v21 != v20 )
      ExfReleaseRundownProtection((unsigned __int8 *)v19);
  }
  return 0;
}
