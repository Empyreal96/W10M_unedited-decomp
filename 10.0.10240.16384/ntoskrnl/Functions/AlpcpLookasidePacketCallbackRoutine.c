// AlpcpLookasidePacketCallbackRoutine 
 
int __fastcall AlpcpLookasidePacketCallbackRoutine(_DWORD *a1, _DWORD *a2)
{
  unsigned int *v3; // r5
  int v4; // r6
  int v6; // r10
  int result; // r0
  _DWORD *v8; // r1
  unsigned int v9; // r3
  unsigned int v10; // r3
  int v11; // r4
  _DWORD v12[2]; // [sp+10h] [bp-28h] BYREF
  char v13; // [sp+18h] [bp-20h]

  v3 = (unsigned int *)a2[2];
  v4 = 0;
  while ( 1 )
  {
    v6 = 0;
    v12[0] = 0;
    v12[1] = v3;
    __dmb(0xBu);
    v13 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_54B5B0();
    do
      v8 = (_DWORD *)__ldrex(v3);
    while ( __strex((unsigned int)v12, v3) );
    __dmb(0xBu);
    if ( v8 )
      KxWaitForLockOwnerShip((int)v12, v8);
    v9 = v3[3];
    if ( v9 )
    {
      v3[3] = v9 - 1;
    }
    else
    {
      v10 = v3[4];
      if ( v10 )
      {
        v3[4] = v10 - 1;
        v6 = -1;
      }
      else
      {
        a1 = 0;
        --v3[2];
        *a2 = v3[6];
        v3[6] = (unsigned int)a2;
        if ( !v3[2] && v3[5] )
          v4 = 1;
      }
    }
    result = KeReleaseInStackQueuedSpinLock((int)v12);
    if ( !a1 )
      break;
    if ( ObReferenceObjectSafeWithTag(v3[7]) )
    {
      v11 = v3[7];
      __dmb(0xBu);
      IoSetIoCompletionEx2(v3[7], v3[8], v6, 0, 0, 0, a1, 0);
      result = ObfDereferenceObjectWithTag(v11);
      break;
    }
  }
  if ( v4 )
    result = AlpcpDeferredFreeCompletionPacketLookaside((int)v3);
  return result;
}
