// ExUpdateOsPfnInRegistry 
 
int __fastcall ExUpdateOsPfnInRegistry(int a1, int a2, int a3)
{
  unsigned int v5; // r5
  int v6; // r4
  unsigned int v7; // r2
  unsigned int v8; // r2
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3
  char v13; // [sp+10h] [bp-30h]
  int v14; // [sp+18h] [bp-28h]

  v14 = 0;
  v13 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = KeAbPreAcquire((unsigned int)&dword_922C40, 0, 0);
  do
    v7 = __ldrex((unsigned int *)&dword_922C40);
  while ( !v7 && __strex(0x11u, (unsigned int *)&dword_922C40) );
  __dmb(0xBu);
  if ( v7 )
    ExfAcquirePushLockSharedEx(&dword_922C40, v6, (unsigned int)&dword_922C40);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  if ( a1 )
  {
    if ( a3 )
    {
      v14 = ZwCreateKey();
      if ( v14 >= 0 )
      {
        v13 = 1;
        v14 = ZwSetValueKey();
        if ( v14 >= 0 )
          v14 = ZwSetValueKey();
      }
    }
  }
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&dword_922C40);
  while ( v8 == 17 && __strex(0, (unsigned int *)&dword_922C40) );
  if ( v8 != 17 )
    ExfReleasePushLockShared(&dword_922C40);
  v9 = KeAbPostRelease((unsigned int)&dword_922C40);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v9);
  if ( v13 == 1 )
    ZwClose();
  return v14;
}
