// MiSyncSystemPdes 
 
int __fastcall MiSyncSystemPdes(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  unsigned int *v7; // r2
  unsigned int v8; // r0
  _DWORD v9[8]; // [sp+0h] [bp-20h] BYREF

  v9[0] = a2;
  v9[1] = a3;
  v9[2] = a4;
  v5 = KeAcquireInStackQueuedSpinLock(&dword_634980, v9);
  if ( (*(_DWORD *)(a1 + 192) & 0x800000) != 0 )
    return sub_510748(v5);
  __dmb(0xBu);
  v7 = (unsigned int *)(a1 + 192);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 | 0x800, v7) );
  __dmb(0xBu);
  return KeReleaseInStackQueuedSpinLock(v9);
}
