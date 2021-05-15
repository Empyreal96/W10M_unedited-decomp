// ExQueryFastCacheDevLicense 
 
int ExQueryFastCacheDevLicense()
{
  int v0; // r0
  BOOL v1; // r6
  unsigned int v3; // r2
  int v4; // r4
  int v5; // r0
  unsigned int v6; // r1
  unsigned int v7; // r1
  int v8; // r0
  unsigned int v9; // r1
  int v10; // r3
  int v11; // r1
  bool v12; // [sp+0h] [bp-20h] BYREF
  __int16 v13[2]; // [sp+8h] [bp-18h] BYREF
  const __int16 *v14; // [sp+Ch] [bp-14h]

  v12 = 0;
  v13[0] = 66;
  v13[1] = 68;
  v14 = L"AllowDevelopmentWithoutDevLicense";
  v0 = KIsUnlockSettingEnabled((int)v13, &v12);
  v1 = v12;
  if ( v0 >= 0 && v12 )
    return v1;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = KeAbPreAcquire((unsigned int)&ExpFastCacheLock, 0, 0);
  v5 = 17;
  do
    v6 = __ldrex(&ExpFastCacheLock);
  while ( !v6 && __strex(0x11u, &ExpFastCacheLock) );
  __dmb(0xBu);
  if ( !v6 )
  {
    if ( v4 )
      *(_BYTE *)(v4 + 14) |= 1u;
    if ( !dword_920314 )
    {
      if ( !dword_92030C )
        goto LABEL_13;
      v11 = *((_DWORD *)off_920308 + 1);
      if ( (unsigned __int64)qword_922C10 <= *(_QWORD *)(v11 + 32) )
      {
        if ( *(_DWORD *)(v11 + 40) == 16 && *(_DWORD *)(v11 + 44) == 1 )
          v1 = 1;
        goto LABEL_13;
      }
      v5 = sub_76601C(8444);
    }
    ExpTriggerFastCacheReeval(v5);
LABEL_13:
    __dmb(0xBu);
    do
      v7 = __ldrex(&ExpFastCacheLock);
    while ( v7 == 17 && __strex(0, &ExpFastCacheLock) );
    if ( v7 != 17 )
      ExfReleasePushLockShared(&ExpFastCacheLock);
    v8 = KeAbPostRelease((unsigned int)&ExpFastCacheLock);
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = (__int16)(*(_WORD *)(v9 + 0x134) + 1);
    *(_WORD *)(v9 + 308) = v10;
    if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
      KiCheckForKernelApcDelivery(v8);
    return v1;
  }
  return sub_7EA2F8(17);
}
