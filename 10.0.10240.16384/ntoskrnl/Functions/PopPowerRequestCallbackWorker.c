// PopPowerRequestCallbackWorker 
 
int PopPowerRequestCallbackWorker()
{
  int v0; // r0
  int v1; // r2
  __int64 v2; // kr00_8
  int v3; // r4
  int v4; // r5
  int v5; // r2
  int v6; // r1
  int v7; // r3
  int result; // r0
  _BYTE v9[16]; // [sp-4h] [bp-38h] BYREF
  char v10[40]; // [sp+Ch] [bp-28h] BYREF

  while ( 1 )
  {
    v0 = KeAcquireInStackQueuedSpinLock(&PopPowerRequestSpinLock, v9);
    if ( (int *)PopPowerRequestCallbacks == &PopPowerRequestCallbacks )
    {
      v3 = 0;
      v4 = 0;
      PopCallbackWorkItemScheduled = 0;
    }
    else
    {
      v1 = dword_61F914;
      v2 = *(_QWORD *)dword_61F914;
      if ( *(int **)dword_61F914 != &PopPowerRequestCallbacks || *(_DWORD *)HIDWORD(v2) != dword_61F914 )
        sub_529A64(v0, HIDWORD(v2));
      dword_61F914 = *(_DWORD *)(dword_61F914 + 4);
      v3 = v1 - 44;
      *(_DWORD *)HIDWORD(v2) = &PopPowerRequestCallbacks;
      v4 = 0;
      v5 = v1 - 44;
      v6 = 5;
      do
      {
        v7 = *(char *)(v5 + 52);
        v10[v5 - v3] = v7;
        if ( v7 )
        {
          *(_BYTE *)(v5 + 52) = 0;
          ++v4;
        }
        ++v5;
        --v6;
      }
      while ( v6 );
      *(_BYTE *)(v3 + 57) = 0;
    }
    result = KeReleaseInStackQueuedSpinLock(v9);
    if ( !v3 )
      break;
    if ( v4 )
      PopPowerRequestExecuteCallbacks(v10, *(_DWORD *)(v3 + 20), *(_DWORD *)(v3 + 8));
    ObfDereferenceObjectWithTag(v3);
  }
  return result;
}
