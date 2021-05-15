// CmNotifyRunDown 
 
int __fastcall CmNotifyRunDown(int result, int a2)
{
  int v2; // r6
  unsigned int v3; // r8
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r2
  int v7; // r1
  _DWORD *v8; // r2
  int *v9; // r3
  _DWORD *v10; // r1
  int v11; // r4
  _DWORD *v12; // r4
  int v13; // r3
  _DWORD *v14; // r1
  _DWORD *v15; // r1
  int v16; // r0
  int v17; // r1
  _DWORD *v18; // r2
  _DWORD *v19; // r0
  unsigned int v20; // r1
  unsigned int v21; // r0
  int v22; // [sp+4h] [bp-24h]
  int vars8; // [sp+30h] [bp+8h]

  v2 = result;
  vars8 = result;
  if ( *(_DWORD *)(result + 852) && *(_DWORD *)(result + 852) != result + 852 )
  {
    CmpLockRegistry(result, a2);
    v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v4 = KeAbPreAcquire((unsigned int)&CmpPostLock, 0, 0);
    v5 = v4;
    do
      v6 = __ldrex((unsigned __int8 *)&CmpPostLock);
    while ( __strex(v6 & 0xFE, (unsigned __int8 *)&CmpPostLock) );
    __dmb(0xBu);
    if ( (v6 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&CmpPostLock, v4);
    if ( v5 )
      *(_BYTE *)(v5 + 14) |= 1u;
    dword_632444 = v3;
    v7 = KfRaiseIrql(1);
    v22 = v7;
    if ( *(_DWORD *)(v2 + 852) )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v8 = (_DWORD *)(v2 + 852);
          v9 = *(int **)(v2 + 852);
          if ( v9 == (int *)(v2 + 852) )
          {
            v7 = v22;
            goto LABEL_39;
          }
          v10 = *(_DWORD **)(v2 + 852);
          v11 = *v9;
          if ( (_DWORD *)v9[1] != v8 || *(_DWORD **)(v11 + 4) != v10 )
            __fastfail(3u);
          *v8 = v11;
          *(_DWORD *)(v11 + 4) = v8;
          v12 = v10 - 2;
          v13 = v10[5];
          if ( (v13 & 0x10000) != 0 )
            break;
          v19 = *(_DWORD **)(v2 + 856);
          *v10 = v8;
          v10[1] = v19;
          if ( (_DWORD *)*v19 != v8 )
            __fastfail(3u);
          *v19 = v10;
          *(_DWORD *)(v2 + 856) = v10;
        }
        if ( (unsigned __int16)v13 != 2 )
          break;
        v14 = (_DWORD *)v10[6];
        if ( (_DWORD *)v14[14] == v14 + 14 )
        {
          DbgPrint("IoStatusBlock pointing onto itself AsyncUser = %p\n", v14);
          if ( KdDebuggerEnabled )
          {
            if ( !KdDebuggerNotPresent )
              __debugbreak();
          }
        }
        **(_DWORD **)(v12[8] + 56) = 267;
        *(_DWORD *)(*(_DWORD *)(v12[8] + 56) + 4) = 0;
        v15 = (_DWORD *)v12[8];
        if ( (_DWORD *)v15[14] == v15 + 14 )
        {
          DbgPrint("IoStatusBlock pointing onto itself AsyncUser = %p\n", v15);
          if ( KdDebuggerEnabled )
          {
            if ( !KdDebuggerNotPresent )
              __debugbreak();
          }
        }
        v16 = *(_DWORD *)(v12[8] + 4);
        if ( v16 )
        {
          KeSetEvent(v16, 0, 0);
          ObfDereferenceObject(*(_DWORD *)(v12[8] + 4));
        }
        if ( !KeRemoveQueueApc(v12[8] + 8) )
        {
          v17 = *v12;
          v18 = (_DWORD *)v12[1];
          if ( *(_DWORD **)(*v12 + 4) != v12 || (_DWORD *)*v18 != v12 )
            __fastfail(3u);
LABEL_31:
          *v18 = v17;
          *(_DWORD *)(v17 + 4) = v18;
          CmpCancelSubordinatePost(v12, 0);
        }
        CmpFreeSubordinatePost(v12);
        CmpFreePostBlock(v12);
      }
      v17 = *v12;
      v18 = (_DWORD *)v12[1];
      if ( *(_DWORD **)(*v12 + 4) != v12 || (_DWORD *)*v18 != v12 )
        __fastfail(3u);
      goto LABEL_31;
    }
LABEL_39:
    KfLowerIrql(v7);
    dword_632444 = 0;
    __dmb(0xBu);
    do
      v20 = __ldrex((unsigned int *)&CmpPostLock);
    while ( !v20 && __strex(1u, (unsigned int *)&CmpPostLock) );
    if ( v20 )
      ExpReleaseFastMutexContended((unsigned int *)&CmpPostLock, v20);
    v21 = KeAbPostRelease((unsigned int)&CmpPostLock);
    result = CmpUnlockRegistry(v21);
  }
  return result;
}
