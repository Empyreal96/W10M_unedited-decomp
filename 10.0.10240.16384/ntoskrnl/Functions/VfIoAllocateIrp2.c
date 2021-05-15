// VfIoAllocateIrp2 
 
_DWORD *__fastcall VfIoAllocateIrp2(_DWORD *result, int *a2)
{
  _DWORD *v3; // r6
  int v4; // r3
  _DWORD *v5; // r5
  unsigned int *v6; // r2
  unsigned int v7; // r4
  int v8; // r0
  int v9; // r1
  int v10; // r2
  int v11; // r3
  _DWORD *v12; // r7
  int v13; // r1
  int v14; // r2
  int v15; // r3

  v3 = result;
  v4 = VfIoDisabled;
  __dmb(0xBu);
  if ( !v4 )
  {
    result = (_DWORD *)VfPacketCreateAndLock(result);
    v5 = result;
    if ( result )
    {
      __dmb(0xBu);
      v6 = result + 3;
      do
        v7 = __ldrex(v6);
      while ( __strex(v7 + 1, v6) );
      __dmb(0xBu);
      ++result[4];
      result[9] |= 0x200000u;
      v3[2] |= 0x40000000u;
      if ( a2 )
      {
        v8 = *a2;
        v9 = a2[1];
        v10 = a2[2];
        v11 = a2[3];
        v12 = a2 + 4;
        v5[19] = v8;
        v5[20] = v9;
        v5[21] = v10;
        v5[22] = v11;
        v13 = v12[1];
        v14 = v12[2];
        v15 = v12[3];
        v5[23] = *v12;
        v5[24] = v13;
        v5[25] = v14;
        v5[26] = v15;
      }
      else
      {
        result[19] = 0;
      }
      result = (_DWORD *)VfIrpDatabaseEntryReleaseLock(v5);
    }
  }
  return result;
}
