// PfpParametersWatcher 
 
int __fastcall PfpParametersWatcher(_DWORD *a1)
{
  unsigned __int8 *v2; // r6
  unsigned int v3; // r2
  int v4; // r0
  int v5; // r5
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r0
  int v9; // r5
  unsigned int v10; // r1
  int result; // r0
  unsigned int v12; // r1
  __int16 v13; // r3
  int v14; // [sp+18h] [bp-48h]
  char v15[8]; // [sp+20h] [bp-40h] BYREF
  int v16; // [sp+28h] [bp-38h]
  int v17; // [sp+2Ch] [bp-34h]
  char *v18; // [sp+30h] [bp-30h]
  int v19; // [sp+34h] [bp-2Ch]
  int v20; // [sp+38h] [bp-28h]
  int v21; // [sp+3Ch] [bp-24h]

  v2 = (unsigned __int8 *)(a1 + 118);
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = KeAbPreAcquire((unsigned int)(a1 + 118), 0, 0);
  v5 = v4;
  do
    v6 = __ldrex(v2);
  while ( __strex(v6 | 1, v2) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v2, v4, (unsigned int)v2);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  if ( a1[1] )
  {
    v7 = ZwNotifyChangeKey();
    if ( v7 >= 0 )
      goto LABEL_14;
    if ( v7 == -1073741444 )
    {
      RtlInitUnicodeString(
        (unsigned int)v15,
        L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\PrefetchParameters");
      v16 = 24;
      v17 = 0;
      v19 = 576;
      v18 = v15;
      v20 = 0;
      v21 = 0;
      if ( ZwCreateKey() >= 0 )
      {
        v8 = a1[1];
        a1[1] = v14;
        if ( v8 )
          ZwClose();
        if ( ZwNotifyChangeKey() >= 0 )
        {
LABEL_14:
          v9 = 0;
          if ( PfpParametersRead(a1) >= 0 )
          {
            PfpParametersPropagate(a1);
            v9 = 1;
          }
          if ( PfSnParametersRead((int)a1) >= 0 )
          {
            PfSnDetermineEnablePrefetcher();
            v9 = 1;
          }
          if ( v9 && *a1 )
            KeSetEvent(*a1, 0, 0);
        }
      }
    }
  }
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)v2);
  while ( __strex(v10 - 1, (unsigned int *)v2) );
  if ( (v10 & 2) != 0 && (v10 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v2);
  result = KeAbPostRelease((unsigned int)v2);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
