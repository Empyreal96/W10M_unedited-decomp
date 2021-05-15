// PopPowerRequestCleanUp 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopPowerRequestCleanUp(int result, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r5
  int v6; // r0
  int v7; // r2
  _DWORD *v8; // r1
  int *v9; // r6
  int *v10; // r2
  int v11; // r0
  int v12; // r0
  int v13; // r7
  unsigned int v14; // r1
  int v15; // r0
  int v16; // r1 OVERLAPPED
  _DWORD *v17; // r2 OVERLAPPED
  int v18; // r3
  _DWORD v19[8]; // [sp+0h] [bp-20h] BYREF

  v19[0] = a2;
  v19[1] = a3;
  v19[2] = a4;
  v4 = result;
  v5 = *(unsigned __int8 *)(result + 72);
  if ( *(_DWORD *)result )
  {
    v6 = PopAcquirePowerRequestPushLock(1);
    v7 = *(_DWORD *)v4;
    if ( *(_DWORD *)v4 )
    {
      v8 = *(_DWORD **)(v4 + 4);
      if ( *(_DWORD *)(v7 + 4) != v4 || *v8 != v4 )
        __fastfail(3u);
      *v8 = v7;
      *(_DWORD *)(v7 + 4) = v8;
      *(_DWORD *)v4 = 0;
      v9 = &PopPowerRequestAttributes;
      if ( *(_DWORD *)(v4 + 36) )
      {
        result = sub_50F8A0(v6);
      }
      else
      {
        PopDisablePowerExecutionRequest(v4, 0);
        *(_DWORD *)(v4 + 68) = 0;
        if ( v5 )
          v10 = &PopSpecialPowerRequestObjectCount;
        else
          v10 = &PopPowerRequestObjectCount;
        v11 = *(_DWORD *)(v4 + 20);
        --*v10;
        v12 = PopPowerRequestDeleteEntryById(v11);
        PopReleasePowerRequestPushLock(v12);
        PopDiagTracePowerRequestClose(v4);
        KeAcquireInStackQueuedSpinLock(&PopPowerRequestSpinLock, v19);
        v13 = *(unsigned __int8 *)(v4 + 57);
        if ( *(_BYTE *)(v4 + 57) )
        {
          *(_QWORD *)&v16 = *(_QWORD *)(v4 + 44);
          if ( *(_DWORD *)(v16 + 4) != v4 + 44 || *v17 != v4 + 44 )
            __fastfail(3u);
          *v17 = v16;
          *(_DWORD *)(v16 + 4) = v17;
          *(_BYTE *)(v4 + 57) = 0;
        }
        v14 = 0;
        v15 = v4;
        do
        {
          if ( ((1 << v14) & *(_DWORD *)(v4 + 16)) == 0 )
          {
            if ( *(_DWORD *)(v15 + 24) )
            {
              v18 = *v9 - 1;
              *v9 = v18;
              if ( !v14 || v14 == 3 || !v18 )
                --*(_BYTE *)(v14 + v4 + 52);
            }
          }
          ++v14;
          v15 += 4;
          v9 += 2;
        }
        while ( v14 < 5 );
        KeReleaseInStackQueuedSpinLock(v19);
        PopPowerRequestExecuteCallbacks(v4 + 52, *(_DWORD *)(v4 + 20), *(_DWORD *)(v4 + 8));
        if ( v13 )
          ObfDereferenceObjectWithTag(v4, 1953261124);
        result = PoDestroyReasonContext(*(_DWORD *)(v4 + 60));
        if ( !v5 )
          result = PopUmpoSendPowerRequestOverrideCleanup(v4);
      }
    }
    else
    {
      result = PopReleasePowerRequestPushLock(v6);
    }
  }
  return result;
}
