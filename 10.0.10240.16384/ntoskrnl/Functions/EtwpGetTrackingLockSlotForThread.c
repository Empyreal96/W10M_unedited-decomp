// EtwpGetTrackingLockSlotForThread 
 
_DWORD *__fastcall EtwpGetTrackingLockSlotForThread(int a1, int a2)
{
  unsigned int v4; // r7
  _DWORD *v5; // r4
  _DWORD *v6; // r5
  int v7; // r6
  _BYTE *v8; // r0
  unsigned int *v9; // r2
  _DWORD *v10; // r2
  unsigned int v11; // r1
  int v12; // r0

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (*(_DWORD *)(v4 + 0x3C0) & 1) != 0 )
    return 0;
  v6 = *(_DWORD **)(v4 + 1028);
  v7 = EtwpEthreadSyncTrackingSequence;
  if ( !v6 )
  {
    v8 = (_BYTE *)ExAllocatePoolWithTag(516, 512);
    v5 = v8;
    if ( !v8 )
      return 0;
    memset(v8, 0, 512);
    __dmb(0xBu);
    v9 = (unsigned int *)(v4 + 1028);
    do
      v6 = (_DWORD *)__ldrex(v9);
    while ( !v6 && __strex((unsigned int)v5, v9) );
    __dmb(0xBu);
    if ( !v6 )
    {
      v5[6] = a2;
      v5[7] = 0;
      v5[4] = a1;
      v5[9] = v7;
      return v5;
    }
    ExFreePoolWithTag(v5);
  }
  v10 = 0;
  v11 = 0;
  while ( 1 )
  {
    v12 = v6[6];
    if ( v12 == a2 && v6[4] == a1 && v6[9] == v7 )
      return v6;
    if ( !v10 )
    {
      if ( v12 )
      {
        if ( v6[9] < v7 )
        {
          v10 = v6;
LABEL_22:
          v6 = v10;
          if ( v10 )
          {
            v10[7] = 0;
            v10[8] = 0;
            *v10 = 0;
            v10[1] = 0;
            v10[2] = 0;
            v10[3] = 0;
            *((_WORD *)v10 + 10) = 0;
            *((_BYTE *)v10 + 22) = 0;
            *((_BYTE *)v10 + 23) = 0;
            v10[9] = v7;
            v10[10] = 0;
            v10[4] = a1;
            v10[6] = a2;
          }
          return v6;
        }
      }
      else
      {
        v10 = v6;
      }
    }
    ++v11;
    v6 += 16;
    if ( v11 >= 8 )
      goto LABEL_22;
  }
}
