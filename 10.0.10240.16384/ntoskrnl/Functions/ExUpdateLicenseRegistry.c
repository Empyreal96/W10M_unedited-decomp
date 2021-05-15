// ExUpdateLicenseRegistry 
 
int __fastcall ExUpdateLicenseRegistry(int a1)
{
  int v2; // r6
  unsigned int v3; // r2
  int v4; // r0
  unsigned int v5; // r2
  int v7; // r0
  unsigned int v8; // r1
  __int16 v9; // r3
  unsigned int v10; // r2

  v2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = KeAbPreAcquire((unsigned int)&dword_922C40, 0, 0);
  do
    v5 = __ldrex((unsigned int *)&dword_922C40);
  while ( !v5 && __strex(0x11u, (unsigned int *)&dword_922C40) );
  __dmb(0xBu);
  if ( v5 )
    return sub_7EBAB4(v4, 17);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  if ( dword_922C44 )
    v2 = NtSetValueKey(a1, (int)&dword_8C8260, 0, 3, dword_922C44, *(_DWORD *)dword_922C44);
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)&dword_922C40);
  while ( v10 == 17 && __strex(0, (unsigned int *)&dword_922C40) );
  if ( v10 != 17 )
    ExfReleasePushLockShared(&dword_922C40);
  v7 = KeAbPostRelease((unsigned int)&dword_922C40);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x134) + 1;
  *(_WORD *)(v8 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    KiCheckForKernelApcDelivery(v7);
  return v2;
}
