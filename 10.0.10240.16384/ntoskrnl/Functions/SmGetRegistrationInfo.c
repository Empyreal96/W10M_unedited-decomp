// SmGetRegistrationInfo 
 
int __fastcall SmGetRegistrationInfo(char a1, int a2)
{
  int v3; // r9
  unsigned int v4; // r2
  int v5; // r0
  unsigned int v6; // r4
  int v8; // r4
  unsigned int v9; // r0
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3

  v3 = a1;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = KeAbPreAcquire((unsigned int)byte_636CB0, 0, 0);
  do
    v6 = __ldrex(byte_636CB0);
  while ( __strex(v6 | 1, byte_636CB0) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    return sub_81A268(v5);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  if ( (dword_636CA8 & 8) != 0 )
  {
    v8 = 0;
  }
  else
  {
    v8 = SmRegistrationCtxStart(&dword_636DFC);
    if ( v8 >= 0 )
      dword_636CA8 |= 8u;
  }
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)byte_636CB0);
  while ( __strex(v9 - 1, (unsigned int *)byte_636CB0) );
  if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)byte_636CB0);
  v10 = KeAbPostRelease((unsigned int)byte_636CB0);
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(v10);
  if ( v8 >= 0 )
  {
    v8 = SmRegistrationInfoFill(&dword_636DFC, v3, a2 + 4);
    if ( v8 >= 0 )
      v8 = 0;
  }
  return v8;
}
