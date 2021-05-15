// PspUpdateSingleProcessAffinity 
 
unsigned int __fastcall PspUpdateSingleProcessAffinity(unsigned int result, _DWORD *a2, __int16 *a3, int a4)
{
  unsigned int *v6; // r9
  unsigned int *v7; // r5
  int v8; // r8
  int v9; // r0
  int v10; // r6
  unsigned int v11; // r4
  int v12; // r3
  unsigned int v13; // r2
  int v14[8]; // [sp+8h] [bp-20h] BYREF

  v14[0] = a4;
  v6 = (unsigned int *)result;
  if ( (a2[47] & 0x80000) != 0 )
  {
    v7 = a2 + 42;
    v14[0] = 0;
    v8 = 0;
    v9 = KeAbPreAcquire((unsigned int)(a2 + 42), 0, 0);
    v10 = v9;
    do
      v11 = __ldrex(v7);
    while ( !v11 && __strex(0x11u, v7) );
    __dmb(0xBu);
    if ( v11 )
      ExfAcquirePushLockSharedEx(v7, v9, (unsigned int)v7);
    if ( v10 )
      *(_BYTE *)(v10 + 14) |= 1u;
    v12 = a2[47];
    __dmb(0xBu);
    if ( (v12 & 0x80000) != 0 )
      v8 = PspSetProcessAffinitySafe((int)a2, 2, a3, 0, v14);
    __dmb(0xBu);
    do
      v13 = __ldrex(v7);
    while ( v13 == 17 && __strex(0, v7) );
    if ( v13 != 17 )
      ExfReleasePushLockShared(v7);
    result = KeAbPostRelease((unsigned int)v7);
    if ( v8 >= 0 )
    {
      if ( v14[0] )
        result = (unsigned int)PspWritePebAffinityInfo(v6, a2);
    }
  }
  return result;
}
