// MmUpdateMdlTracker 
 
int __fastcall MmUpdateMdlTracker(unsigned int a1, int a2, int a3, int a4)
{
  int v5; // r3
  int v8; // r4
  int result; // r0
  _DWORD *v10; // r4
  int v11; // r0
  _DWORD *v12; // r3
  _DWORD v13[8]; // [sp+0h] [bp-20h] BYREF

  v13[0] = a1;
  v13[1] = a2;
  v13[2] = a3;
  v13[3] = a4;
  v5 = *(_DWORD *)(a1 + 8);
  if ( !v5 )
    v5 = PsInitialSystemProcess;
  v8 = *(_DWORD *)(v5 + 424);
  if ( !v8 )
    goto LABEL_4;
  KeAcquireInStackQueuedSpinLock((unsigned int *)(v8 + 8), (unsigned int)v13);
  v10 = *(_DWORD **)v8;
  if ( v10 )
  {
    do
    {
      v11 = MiLockTrackerCompare(a1, (int)v10);
      if ( v11 >= 0 )
      {
        if ( v11 <= 0 )
          break;
        v10 = (_DWORD *)v10[1];
      }
      else
      {
        v10 = (_DWORD *)*v10;
      }
    }
    while ( v10 );
    if ( v10 && (a2 || a3) )
    {
      v12 = v10 + 11;
      v10[9] = a2;
      v10[10] = a3;
      do
        *v12++ = 0;
      while ( v12 != v10 + 17 );
    }
  }
  KeReleaseInStackQueuedSpinLock((int)v13);
  if ( v10 )
    result = 1;
  else
LABEL_4:
    result = 0;
  return result;
}
