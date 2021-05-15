// PsShutdownSystem 
 
int PsShutdownSystem()
{
  int v0; // r8
  int v1; // r3
  unsigned int v2; // r1
  int v3; // r7
  unsigned int v4; // r5
  int *v5; // r4
  unsigned int *v6; // r6
  int v7; // r0
  int v8; // r9
  int *v9; // r4
  unsigned int v10; // r6
  int v11; // t1
  int v12; // r0
  unsigned int **v13; // r4
  int v14; // r5
  unsigned int v15; // r1
  int v16; // r0
  void *v18; // [sp+10h] [bp-40h]
  int v19[2]; // [sp+18h] [bp-38h] BYREF
  unsigned int v20[12]; // [sp+20h] [bp-30h] BYREF

  v0 = 1;
  v19[0] = -1000000000;
  v19[1] = -1;
  v18 = PsGetServerSiloGlobals(0);
  v1 = __mrc(15, 0, 13, 0, 3);
  __dmb(0xBu);
  do
    v2 = __ldrex(&PspShutdownThread);
  while ( !v2 && __strex(v1 & 0xFFFFFFC0, &PspShutdownThread) );
  __dmb(0xBu);
  if ( v2 )
    return 0;
  PsEnumProcesses((int (__fastcall *)(int *, int))PspFreezeProcessWorker, 0);
  v3 = 0;
  while ( 1 )
  {
    v4 = 0;
    v5 = PsGetNextProcess(0);
    if ( v5 )
    {
      v6 = v20;
      do
      {
        if ( v5 != (int *)PsInitialSystemProcess && v5 != (int *)PsIdleProcess && v5 != *((int **)v18 + 5) )
        {
          v7 = PsTerminateProcess((int)v5, -1073741077);
          if ( (v5[48] & 4) == 0 && v7 != 290 && v4 < 3 )
          {
            ObfReferenceObject((int)v5);
            *v6 = (unsigned int)v5;
            ++v4;
            ++v6;
          }
        }
        v5 = PsGetNextProcess((int)v5);
      }
      while ( v5 );
      v0 = 1;
      if ( v4 )
      {
        v8 = KeWaitForMultipleObjects(v4, v20, 1, 0, 0, 0, v19, 0);
        v9 = (int *)v20;
        v10 = v4;
        do
        {
          v11 = *v9++;
          ObfDereferenceObject(v11);
          --v10;
        }
        while ( v10 );
        if ( v8 == 258 )
          break;
      }
    }
    v3 = 0;
LABEL_38:
    if ( !v4 )
      goto LABEL_24;
  }
  if ( (unsigned int)++v3 <= 0xA || PsContinueWaiting )
    goto LABEL_38;
  v0 = 0;
LABEL_24:
  if ( PopShutdownCleanly )
  {
    v12 = *((_DWORD *)v18 + 5);
    if ( v12 )
    {
      PsTerminateProcess(v12, -1073741077);
      PspWaitForUsermodeExit(*((_DWORD *)v18 + 5));
    }
  }
  v13 = (unsigned int **)&PspSystemDlls;
  v14 = 2;
  do
  {
    if ( *v13 )
    {
      v15 = (*v13)[5];
      if ( v15 )
        MiUnmapViewOfSection(PsInitialSystemProcess, v15, 0);
      PspSwapSystemDll(*v13);
    }
    ++v13;
    --v14;
  }
  while ( v14 );
  ZwClose();
  PspInitialSystemProcessHandle = 0;
  v16 = *(_DWORD *)(PsInitialSystemProcess + 376);
  if ( v16 && v16 != 1 )
  {
    ObfDereferenceObject(v16);
    *(_DWORD *)(PsInitialSystemProcess + 376) = 1;
  }
  return v0;
}
