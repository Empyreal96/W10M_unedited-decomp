// AlpcpSignal 
 
int __fastcall AlpcpSignal(int result, char a2)
{
  int v2; // r4
  int *v3; // r5
  unsigned int *v5; // r4
  int v6; // r8
  unsigned int v7; // r1
  unsigned int *v8; // r2
  _DWORD *v9; // r7
  unsigned int *v10; // r4
  unsigned int v11; // r2
  int v12; // r2
  int v13; // r3
  int v14; // r0
  int v15; // r3
  int v16; // r3
  _DWORD v17[2]; // [sp+10h] [bp-20h] BYREF
  char v18; // [sp+18h] [bp-18h]

  v2 = result;
  v3 = *(int **)(result + 16);
  if ( v3 )
  {
    if ( *(_BYTE *)(result + 34) )
    {
      v5 = (unsigned int *)v3[6];
      v6 = *(unsigned __int8 *)(result + 35);
      v17[0] = 0;
      v17[1] = v5;
      __dmb(0xBu);
      v18 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
        return sub_52C660();
      do
        v7 = __ldrex(v5);
      while ( __strex((unsigned int)v17, v5) );
      __dmb(0xBu);
      if ( v7 )
        KxWaitForLockOwnerShip(v17);
      if ( v5[2] >= v5[1] )
      {
        v9 = 0;
        if ( v6 )
          ++v5[4];
        else
          ++v5[3];
      }
      else
      {
        v8 = (unsigned int *)v5[6];
        if ( v8 )
          v5[6] = *v8;
        v9 = (_DWORD *)v8[1];
        ++v5[2];
      }
      KeReleaseInStackQueuedSpinLock(v17);
      v10 = (unsigned int *)(v3 + 52);
      __dmb(0xBu);
      do
        v11 = __ldrex(v10);
      while ( v11 == 17 && __strex(0, v10) );
      if ( v11 != 17 )
        ExfReleasePushLockShared(v3 + 52, 0);
      result = KeAbPostRelease(v3 + 52);
      if ( v9 )
      {
        if ( v6 )
          v12 = -1;
        else
          v12 = 0;
        result = IoSetIoCompletionEx2(v3[4], v3[5], v12, 0, 0, 0, v9, a2);
      }
      return result;
    }
    v14 = v3[37];
    return KeReleaseSemaphoreEx(v14, 1, 1);
  }
  v13 = *(_DWORD *)(result + 12);
  if ( v13 )
  {
    v14 = v13 + 884;
    return KeReleaseSemaphoreEx(v14, 1, 1);
  }
  v15 = *(_DWORD *)(result + 20);
  if ( v15 )
  {
    result = KeSetEvent(v15 & 0xFFFFFFFE, 0, a2);
    v16 = *(_DWORD *)(v2 + 20);
    if ( (v16 & 1) != 0 )
      result = ObfDereferenceObject(v16 & 0xFFFFFFFE);
    *(_DWORD *)(v2 + 20) = 0;
  }
  return result;
}
