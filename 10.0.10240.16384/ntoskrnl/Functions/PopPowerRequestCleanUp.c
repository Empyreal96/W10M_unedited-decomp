// PopPowerRequestCleanUp 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall PopPowerRequestCleanUp(int result, int a2, int a3, int a4)
{
  int v5; // r5
  int v6; // r2
  int *v7; // r1
  int *v8; // r6
  int v9; // r1
  int *v10; // r2
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r7
  unsigned int v16; // r1
  int v17; // r0
  int v18; // r1 OVERLAPPED
  _DWORD *v19; // r2 OVERLAPPED
  int v20; // r3
  int v21; // [sp+0h] [bp-20h] BYREF
  int v22; // [sp+4h] [bp-1Ch]
  int v23; // [sp+8h] [bp-18h]
  int v24; // [sp+Ch] [bp-14h]
  int v25; // [sp+10h] [bp-10h]
  int v26; // [sp+14h] [bp-Ch]
  int v27; // [sp+18h] [bp-8h]
  int v28; // [sp+1Ch] [bp-4h]
  __int64 savedregs; // [sp+20h] [bp+0h]

  v21 = a2;
  v22 = a3;
  v23 = a4;
  v5 = *(unsigned __int8 *)(result + 72);
  if ( *(_DWORD *)result )
  {
    PopAcquirePowerRequestPushLock(1);
    v6 = *(_DWORD *)result;
    if ( *(_DWORD *)result )
    {
      v7 = *(int **)(result + 4);
      if ( *(_DWORD *)(v6 + 4) != result || *v7 != result )
        __fastfail(3u);
      *v7 = v6;
      *(_DWORD *)(v6 + 4) = v7;
      *(_DWORD *)result = 0;
      v8 = PopPowerRequestAttributes;
      if ( *(_DWORD *)(result + 36) )
      {
        sub_50F8A0();
      }
      else
      {
        PopDisablePowerExecutionRequest(result, 0, v6, 0, v21);
        *(_DWORD *)(result + 68) = 0;
        if ( v5 )
          v10 = &PopSpecialPowerRequestObjectCount;
        else
          v10 = &PopPowerRequestObjectCount;
        v11 = *(_DWORD *)(result + 20);
        --*v10;
        PopPowerRequestDeleteEntryById(v11, v9, (int)v10);
        PopReleasePowerRequestPushLock();
        PopDiagTracePowerRequestClose(result, v12, v13, v14, v21, v22, v23, v24, v25, v26, v27, v28, savedregs);
        KeAcquireInStackQueuedSpinLock((unsigned int *)&PopPowerRequestSpinLock, (unsigned int)&v21);
        v15 = *(unsigned __int8 *)(result + 57);
        if ( *(_BYTE *)(result + 57) )
        {
          *(_QWORD *)&v18 = *(_QWORD *)(result + 44);
          if ( *(_DWORD *)(v18 + 4) != result + 44 || *v19 != result + 44 )
            __fastfail(3u);
          *v19 = v18;
          *(_DWORD *)(v18 + 4) = v19;
          *(_BYTE *)(result + 57) = 0;
        }
        v16 = 0;
        v17 = result;
        do
        {
          if ( ((1 << v16) & *(_DWORD *)(result + 16)) == 0 )
          {
            if ( *(_DWORD *)(v17 + 24) )
            {
              v20 = *v8 - 1;
              *v8 = v20;
              if ( !v16 || v16 == 3 || !v20 )
                --*(_BYTE *)(v16 + result + 52);
            }
          }
          ++v16;
          v17 += 4;
          v8 += 2;
        }
        while ( v16 < 5 );
        KeReleaseInStackQueuedSpinLock((int)&v21);
        PopPowerRequestExecuteCallbacks(result + 52, *(_DWORD *)(result + 20), *(_DWORD *)(result + 8));
        if ( v15 )
          ObfDereferenceObjectWithTag(result);
        PoDestroyReasonContext(*(_DWORD **)(result + 60));
        if ( !v5 )
          PopUmpoSendPowerRequestOverrideCleanup(result);
      }
    }
    else
    {
      PopReleasePowerRequestPushLock();
    }
  }
}
