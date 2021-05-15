// MmSessionSetUnloadAddress 
 
void __fastcall __spoils<R2,R3,R12> MmSessionSetUnloadAddress(int a1, int a2, int a3, int a4)
{
  int v4; // r3
  int v5; // r4
  int v6; // r5
  _DWORD v7[6]; // [sp+0h] [bp-18h] BYREF

  v7[2] = a3;
  v7[3] = a4;
  v4 = __mrc(15, 0, 13, 0, 3);
  v5 = *(_DWORD *)(a1 + 52);
  v6 = *(_DWORD *)(*(_DWORD *)((v4 & 0xFFFFFFC0) + 0x74) + 324);
  if ( !v5 )
    v5 = 1;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634980, (unsigned int)v7);
  if ( !*(_DWORD *)(v6 + 3380) )
    *(_DWORD *)(v6 + 3380) = v5;
  KeReleaseInStackQueuedSpinLock((int)v7);
}
