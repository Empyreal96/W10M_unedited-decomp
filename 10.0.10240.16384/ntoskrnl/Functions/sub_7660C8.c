// sub_7660C8 
 
int sub_7660C8()
{
  unsigned int v0; // r2
  int v1; // r0
  int v2; // r4
  unsigned int v3; // r2
  unsigned int v4; // r2
  int v5; // r0
  unsigned int v6; // r1
  __int16 v7; // r3
  char v9; // [sp+10h] [bp-28h]
  int v10; // [sp+18h] [bp-20h]

  v10 = 0;
  v9 = 0;
  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&dword_922C40, 0, 0);
  v2 = v1;
  do
    v3 = __ldrex((unsigned int *)&dword_922C40);
  while ( !v3 && __strex(0x11u, (unsigned int *)&dword_922C40) );
  __dmb(0xBu);
  if ( v3 )
    ExfAcquirePushLockSharedEx(&dword_922C40, v1, (unsigned int)&dword_922C40);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  if ( dword_922C44 )
  {
    v10 = ZwCreateKey();
    if ( v10 >= 0 )
    {
      v9 = 1;
      v10 = ZwSetValueKey();
    }
  }
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)&dword_922C40);
  while ( v4 == 17 && __strex(0, (unsigned int *)&dword_922C40) );
  if ( v4 != 17 )
    ExfReleasePushLockShared(&dword_922C40);
  v5 = KeAbPostRelease((unsigned int)&dword_922C40);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_WORD *)(v6 + 0x134) + 1;
  *(_WORD *)(v6 + 308) = v7;
  if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    KiCheckForKernelApcDelivery(v5);
  if ( v9 == 1 )
    ZwClose();
  return v10;
}
