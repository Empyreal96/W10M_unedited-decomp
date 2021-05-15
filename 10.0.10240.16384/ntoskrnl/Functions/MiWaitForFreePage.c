// MiWaitForFreePage 
 
int __fastcall MiWaitForFreePage(int a1)
{
  unsigned int v2; // r2
  unsigned int v3; // r5
  int v4; // r3
  int v5; // r6
  int v6; // r7
  char v8[32]; // [sp+8h] [bp-20h] BYREF

  KeAcquireInStackQueuedSpinLock((unsigned int *)(a1 + 2944), (unsigned int)v8);
  v2 = *(_DWORD *)(a1 + 3712);
  if ( v2 >= 0x80 )
    return KeReleaseInStackQueuedSpinLock((int)v8);
  if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C4) & 2) != 0 )
  {
    if ( v2 >= 2 )
      return KeReleaseInStackQueuedSpinLock((int)v8);
    goto LABEL_4;
  }
  if ( (__int16 *)a1 != MiSystemPartition )
  {
LABEL_4:
    v3 = 2;
    v4 = 0;
    goto LABEL_5;
  }
  v3 = 128;
  v4 = 1;
LABEL_5:
  v5 = a1 + 20 * v4;
  v6 = *(_DWORD *)(v5 + 2964);
  do
  {
    KeResetEvent(v5 + 2948);
    KeReleaseInStackQueuedSpinLock((int)v8);
    MiObtainFreePages(a1);
    if ( KeWaitForSingleObject(v5 + 2948, 8, 0, 0, MiSeventySeconds) == 258 && v6 == *(_DWORD *)(v5 + 2964) )
      MiNoPagesLastChance((_DWORD *)a1, v3);
    v6 = *(_DWORD *)(v5 + 2964);
    KeAcquireInStackQueuedSpinLock((unsigned int *)(a1 + 2944), (unsigned int)v8);
  }
  while ( *(_DWORD *)(a1 + 3712) < v3 );
  return KeReleaseInStackQueuedSpinLock((int)v8);
}
