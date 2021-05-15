// PopFlushVolumeWorker 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall PopFlushVolumeWorker(int a1)
{
  int v2; // r5
  int v3; // r7
  unsigned int v4; // r2
  int *v5; // r5
  int *v6; // r1 OVERLAPPED
  int **v7; // r2 OVERLAPPED
  int **v8; // r2
  unsigned __int8 v9; // r8
  unsigned int v10; // r1
  int v11; // r5
  int v12; // r8
  unsigned int v13; // r2
  int v14; // r3
  unsigned __int8 v15; // r5
  unsigned int v16; // r1
  int v18; // [sp+20h] [bp-250h]
  char v19[8]; // [sp+28h] [bp-248h] BYREF
  int v20; // [sp+30h] [bp-240h]
  int v21; // [sp+34h] [bp-23Ch]
  char *v22; // [sp+38h] [bp-238h]
  int v23; // [sp+3Ch] [bp-234h]
  int v24; // [sp+40h] [bp-230h]
  int v25; // [sp+44h] [bp-22Ch]
  char v26[8]; // [sp+48h] [bp-228h] BYREF
  char v27[4]; // [sp+50h] [bp-220h] BYREF
  int v28; // [sp+54h] [bp-21Ch]

  v2 = KeAbPreAcquire((unsigned int)&PopVolumeLock, 0, 0);
  v3 = KfRaiseIrql(1);
  do
    v4 = __ldrex((unsigned __int8 *)&PopVolumeLock);
  while ( __strex(v4 & 0xFE, (unsigned __int8 *)&PopVolumeLock) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PopVolumeLock, v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_61EAE4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  for ( dword_61EAFC = v3; ; dword_61EAFC = v12 )
  {
    v5 = *(int **)a1;
    if ( *(_DWORD *)a1 == a1 )
      break;
    *(_QWORD *)&v6 = *(_QWORD *)v5;
    if ( *(int **)(*v5 + 4) != v5 || *v7 != v5 )
      __fastfail(3u);
    *v7 = v6;
    v6[1] = (int)v7;
    v8 = (int **)dword_61E95C;
    *v5 = (int)&PopVolumeDevices;
    v5[1] = (int)v8;
    if ( *v8 != &PopVolumeDevices )
      __fastfail(3u);
    *v8 = v5;
    dword_61EAE4 = 0;
    v9 = dword_61EAFC;
    dword_61E95C = (int)v5;
    __dmb(0xBu);
    do
      v10 = __ldrex(&PopVolumeLock);
    while ( !v10 && __strex(1u, &PopVolumeLock) );
    if ( v10 )
      ExpReleaseFastMutexContended(&PopVolumeLock, v10);
    KfLowerIrql(v9);
    KeAbPostRelease((unsigned int)&PopVolumeLock);
    if ( ObQueryNameString(*(v5 - 7), v27, 512, v26) >= 0 )
    {
      if ( v28 )
      {
        v20 = 24;
        v21 = 0;
        v23 = 576;
        v22 = v27;
        v24 = 0;
        v25 = 0;
        if ( ZwCreateFile() >= 0 )
        {
          if ( *(_BYTE *)(a1 + 28) )
          {
            PopFlushAndHold();
          }
          else if ( *(_BYTE *)(a1 + 29) )
          {
            NtDeviceIoControlFile(v18, 0, 0, 0, v19, 5488644, 0, 0, 0, 0, 0);
          }
          else
          {
            ZwFlushBuffersFile();
          }
          ZwClose();
        }
      }
    }
    v11 = KeAbPreAcquire((unsigned int)&PopVolumeLock, 0, 0);
    v12 = KfRaiseIrql(1);
    do
      v13 = __ldrex((unsigned __int8 *)&PopVolumeLock);
    while ( __strex(v13 & 0xFE, (unsigned __int8 *)&PopVolumeLock) );
    __dmb(0xBu);
    if ( (v13 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&PopVolumeLock, v11);
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    dword_61EAE4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  }
  v14 = *(_DWORD *)(a1 + 8) - 1;
  *(_DWORD *)(a1 + 8) = v14;
  if ( !v14 )
    KeSetEvent(a1 + 12, 0, 0);
  dword_61EAE4 = 0;
  v15 = dword_61EAFC;
  __dmb(0xBu);
  do
    v16 = __ldrex(&PopVolumeLock);
  while ( !v16 && __strex(1u, &PopVolumeLock) );
  if ( v16 )
    ExpReleaseFastMutexContended(&PopVolumeLock, v16);
  KfLowerIrql(v15);
  return KeAbPostRelease((unsigned int)&PopVolumeLock);
}
