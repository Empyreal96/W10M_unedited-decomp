// MiCreateLargePageVad 
 
int __fastcall MiCreateLargePageVad(_DWORD *a1, int a2, int a3)
{
  int v3; // r7
  int v5; // r4
  _DWORD *v6; // r9
  _DWORD *v7; // r8
  int v8; // r6
  __int16 *v9; // r10
  unsigned int *v10; // r2
  unsigned int v11; // r4
  _DWORD *v12; // r0
  unsigned int *v13; // r2
  unsigned int v14; // r4

  v3 = *(_DWORD *)(a2 + 32) & 0x7FFFFFFF;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(_DWORD **)(v5 + 116);
  v7 = (_DWORD *)ExAllocatePoolWithTag(512, 24, 1649175885);
  if ( !v7 )
    return -1073741670;
  if ( MiChargeProcessPhysicalPages((int)a1, v3) )
  {
    v9 = MiGetThreadPartition();
    if ( v6 == a1 )
      LOCK_ADDRESS_SPACE_SHARED(v5, (int)a1);
    v8 = MiChargeFullProcessCommitment(a1, v3);
    if ( v6 == a1 )
      UNLOCK_ADDRESS_SPACE_SHARED(v5, (int)a1);
    if ( v8 >= 0 )
    {
      v12 = MiAllocateLargeZeroPages((int)v9, v3, a3);
      if ( v12 )
      {
        v7[2] = v12;
        v7[1] = 16;
        MiInsertVadEvent(a2, v7, 0);
        return 0;
      }
      if ( v6 == a1 )
        LOCK_ADDRESS_SPACE_SHARED(v5, (int)a1);
      MiReturnFullProcessCommitment((int)a1, v3);
      if ( v6 == a1 )
        UNLOCK_ADDRESS_SPACE_SHARED(v5, (int)a1);
      v13 = a1 + 162;
      do
        v14 = __ldrex(v13);
      while ( __strex(v14 - v3, v13) );
      v8 = -1073741670;
    }
    else
    {
      v10 = a1 + 162;
      do
        v11 = __ldrex(v10);
      while ( __strex(v11 - v3, v10) );
    }
  }
  else
  {
    v8 = -1073741523;
  }
  ExFreePoolWithTag((unsigned int)v7);
  return v8;
}
