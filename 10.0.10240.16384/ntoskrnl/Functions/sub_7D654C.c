// sub_7D654C 
 
void sub_7D654C(int a1, int a2, int a3, int a4, ...)
{
  unsigned int *v4; // r5
  int v5; // r7
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r2
  int v10; // r0
  int v11; // r6
  unsigned int v12; // r2
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3
  unsigned int v16; // r2
  int v17; // r0
  int v18; // r4
  unsigned int v19; // r2
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = KeAbPreAcquire((unsigned int)v4, 0, 0);
  v8 = v7;
  do
    v9 = __ldrex(v4);
  while ( !v9 && __strex(0x11u, v4) );
  __dmb(0xBu);
  if ( v9 )
    ExfAcquirePushLockSharedEx(v4, v7, (unsigned int)v4);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v10 = SepGetTokenSessionMapEntry(v5, 0, (int *)va);
  v11 = v10;
  if ( v10 < 0 )
  {
    if ( v10 == -1073741275 )
    {
      __dmb(0xBu);
      do
        v12 = __ldrex(v4);
      while ( v12 == 17 && __strex(0, v4) );
      if ( v12 != 17 )
        ExfReleasePushLockShared(v4);
      v13 = KeAbPostRelease((unsigned int)v4);
      v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v15 = *(_WORD *)(v14 + 0x134) + 1;
      *(_WORD *)(v14 + 308) = v15;
      if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
        KiCheckForKernelApcDelivery(v13);
      v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v16 + 308);
      v17 = KeAbPreAcquire((unsigned int)v4, 0, 0);
      v18 = v17;
      do
        v19 = __ldrex((unsigned __int8 *)v4);
      while ( __strex(v19 | 1, (unsigned __int8 *)v4) );
      __dmb(0xBu);
      if ( (v19 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v4, v17, (unsigned int)v4);
      if ( v18 )
        *(_BYTE *)(v18 + 14) |= 1u;
      v11 = SepGetTokenSessionMapEntry(v5, 1, (int *)va);
    }
    if ( v11 < 0 )
      JUMPOUT(0x6DCA56);
  }
  JUMPOUT(0x6DC9A8);
}
