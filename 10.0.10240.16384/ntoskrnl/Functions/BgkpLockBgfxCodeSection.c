// BgkpLockBgfxCodeSection 
 
int BgkpLockBgfxCodeSection()
{
  unsigned int v0; // r2
  int v1; // r0
  unsigned int v2; // r2
  int result; // r0
  int v4; // r3
  unsigned int v5; // r1
  unsigned int v6; // r1
  int v7; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&dword_647478, 0, 0);
  do
    v2 = __ldrex((unsigned __int8 *)&dword_647478);
  while ( __strex(v2 | 1, (unsigned __int8 *)&dword_647478) );
  __dmb(0xBu);
  if ( (v2 & 1) != 0 )
    return sub_8DED94(v1);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  v4 = dword_63760C;
  if ( !dword_63760C )
  {
    dword_637618 = MmLockPagableDataSection((unsigned int)BgkpLockBgfxCodeSection);
    v4 = dword_63760C;
  }
  dword_63760C = v4 + 1;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)&dword_647478);
  while ( __strex(v5 - 1, (unsigned int *)&dword_647478) );
  if ( (v5 & 2) != 0 && (v5 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&dword_647478);
  result = KeAbPostRelease((unsigned int)&dword_647478);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = (__int16)(*(_WORD *)(v6 + 0x134) + 1);
  *(_WORD *)(v6 + 308) = v7;
  if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
