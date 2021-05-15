// MiFreeMdlTracker 
 
int __fastcall MiFreeMdlTracker(int a1, int a2)
{
  int v3; // r5
  int v5; // r6
  _DWORD *v6; // r8
  int v7; // r2
  _DWORD *v8; // r4
  int v9; // r0
  int v10; // r3
  int v11; // r3
  int v12; // r2
  char v14[40]; // [sp+8h] [bp-28h] BYREF

  v3 = *(_DWORD *)(a1 + 8);
  if ( !v3 )
    v3 = PsInitialSystemProcess;
  v5 = *(_DWORD *)(v3 + 424);
  if ( v5 )
  {
    v6 = 0;
    KeAcquireInStackQueuedSpinLock((unsigned int *)(v5 + 8), (unsigned int)v14);
    v8 = *(_DWORD **)v5;
    if ( *(_DWORD *)v5 )
    {
      do
      {
        v9 = MiLockTrackerCompare(a1, v8, v7);
        if ( v9 >= 0 )
        {
          if ( v9 <= 0 )
            break;
          v8 = (_DWORD *)v8[1];
        }
        else
        {
          v8 = (_DWORD *)*v8;
        }
      }
      while ( v8 );
      if ( v8 )
      {
        v10 = v8[5];
        v6 = v8;
        if ( v10 != a2 )
          KeBugCheckEx(118, 5, a1, (int)v8, a2 | (v10 << 16));
        v11 = *(_DWORD *)(a1 + 28);
        v12 = v8[8];
        if ( v12 != v11 )
          KeBugCheckEx(118, 6, a1, (int)v8, v11 | (v12 << 16));
        RtlAvlRemoveNode(v5, (int)v8);
        *(_DWORD *)(v5 + 4) -= a2;
      }
    }
    KeReleaseInStackQueuedSpinLock((int)v14);
    if ( v6 )
    {
      ExFreeToNPagedLookasideList((int)&unk_634780, v6);
    }
    else if ( *(_DWORD *)(v5 + 12) )
    {
      KeBugCheckEx(118, 1, a1, *(_DWORD *)(v3 + 280), *(_DWORD *)(v3 + 424));
    }
  }
  return 1;
}
