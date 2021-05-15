// BgkpUnlockBgfxCodeSection 
 
int BgkpUnlockBgfxCodeSection()
{
  unsigned int v0; // r2
  int v1; // r0
  unsigned int v2; // r2
  int result; // r0
  unsigned int v4; // r1
  unsigned int v5; // r1
  int v6; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&dword_647478, 0, 0);
  do
    v2 = __ldrex((unsigned __int8 *)&dword_647478);
  while ( __strex(v2 | 1, (unsigned __int8 *)&dword_647478) );
  __dmb(0xBu);
  if ( (v2 & 1) != 0 )
    return sub_8DF3A4(v1);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  if ( !--dword_63760C )
  {
    MmUnlockPagableImageSection(dword_637618);
    dword_637618 = 0;
  }
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)&dword_647478);
  while ( __strex(v4 - 1, (unsigned int *)&dword_647478) );
  if ( (v4 & 2) != 0 && (v4 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&dword_647478);
  result = KeAbPostRelease((unsigned int)&dword_647478);
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = (__int16)(*(_WORD *)(v5 + 0x134) + 1);
  *(_WORD *)(v5 + 308) = v6;
  if ( !v6 && *(_DWORD *)(v5 + 100) != v5 + 100 && !*(_WORD *)(v5 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
