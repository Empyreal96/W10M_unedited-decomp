// MiSignalNonPagedPoolWatchers 
 
int __fastcall MiSignalNonPagedPoolWatchers(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r5
  unsigned int v5; // r6
  int v7; // r3
  _DWORD v8[6]; // [sp+0h] [bp-18h] BYREF

  v8[0] = a2;
  v8[1] = a3;
  v8[2] = a4;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_640280, (unsigned int)v8);
  if ( dword_63F7D0 )
  {
    v4 = dword_632A90;
    v5 = MiFreePoolPagesLeft(5) + v4;
    if ( v4 >= v5 - 5120 )
      return sub_50EAF8();
    if ( !*(_DWORD *)(dword_63F7D0 + 4) )
      KeSetEvent(dword_63F7D0, 0, 0);
    v7 = *(_DWORD *)(dword_63F7CC + 4);
    if ( v4 >= v5 - 2048 )
    {
      if ( !v7 )
        KeSetEvent(dword_63F7CC, 0, 0);
    }
    else if ( v7 )
    {
      KeResetEvent(dword_63F7CC);
    }
  }
  return KeReleaseInStackQueuedSpinLock((int)v8);
}
