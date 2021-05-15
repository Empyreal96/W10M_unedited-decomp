// CmpCleanUpKcbCacheWithLock 
 
_DWORD *__fastcall CmpCleanUpKcbCacheWithLock(_DWORD *result, int a2)
{
  _DWORD *v2; // r4
  int v4; // r1
  int v5; // r2
  int v6; // r5
  int v7; // r3

  v2 = result;
  if ( !*result )
  {
    if ( CmpTraceRoutine )
    {
      result = (_DWORD *)sub_804E2C();
    }
    else
    {
      CmpCleanUpKcbValueCache(result);
      result = (_DWORD *)CmpDereferenceNameControlBlockWithLock(v2[11]);
      if ( (v2[1] & 4) != 0 )
        result = (_DWORD *)ExFreePoolWithTag(v2[15]);
      v6 = v2[10];
      if ( (v2[1] & 0x20000) != 0 )
      {
        if ( v2[4] != -1 )
        {
          CmpLockDeletedHashEntryExclusiveByKcb((int)v2);
          CmpRemoveKeyHashFromDeletedKcbTable(v2[5], v2 + 3);
          result = (_DWORD *)CmpUnlockDeletedHashEntryByKcb((int)v2);
        }
      }
      else
      {
        result = (_DWORD *)CmpRemoveKeyHash(v2[5], v2 + 3);
      }
      v7 = v2[1] | 0x80000;
      v2[1] = v7;
      if ( v6 )
      {
        if ( a2 )
          result = (_DWORD *)CmpDereferenceKeyControlBlockWithLock(v6, a2);
        else
          result = (_DWORD *)CmpDelayDerefKeyControlBlock(v6, v4, v5, v7);
      }
    }
  }
  return result;
}
