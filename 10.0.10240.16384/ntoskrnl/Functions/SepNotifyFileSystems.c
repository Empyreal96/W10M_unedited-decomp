// SepNotifyFileSystems 
 
unsigned int __fastcall SepNotifyFileSystems(unsigned int a1)
{
  unsigned int v2; // r2
  unsigned int v3; // r7
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r2
  void (__fastcall **i)(int); // r4
  void (__fastcall **j)(int, _DWORD); // r4
  unsigned int v9; // r1
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3
  int v13; // r0

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = KeAbPreAcquire((unsigned int)&SepRmNotifyMutex, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex((unsigned __int8 *)&SepRmNotifyMutex);
  while ( __strex(v6 & 0xFE, (unsigned __int8 *)&SepRmNotifyMutex) );
  __dmb(0xBu);
  if ( (v6 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&SepRmNotifyMutex, v4);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  dword_649EF8 = v3;
  for ( i = (void (__fastcall **)(int))SeFileSystemNotifyRoutinesHead; i; i = (void (__fastcall **)(int))*i )
    i[1](a1 + 16);
  for ( j = (void (__fastcall **)(int, _DWORD))SeFileSystemNotifyRoutinesExHead;
        j;
        j = (void (__fastcall **)(int, _DWORD))*j )
  {
    j[1](a1 + 16, *(_DWORD *)(a1 + 24));
  }
  dword_649EF8 = 0;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&SepRmNotifyMutex);
  while ( !v9 && __strex(1u, (unsigned int *)&SepRmNotifyMutex) );
  if ( v9 )
    ExpReleaseFastMutexContended((unsigned int *)&SepRmNotifyMutex, v9);
  v10 = KeAbPostRelease((unsigned int)&SepRmNotifyMutex);
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(v10);
  v13 = *(_DWORD *)(a1 + 24);
  if ( v13 )
    PspDereferenceSiloObject(v13);
  return ExFreePoolWithTag(a1);
}
