// EmpParseInfDatabase 
 
int __fastcall EmpParseInfDatabase(int a1, int a2, int a3, int a4)
{
  int v6; // r0
  unsigned int v7; // r2
  _DWORD *v9; // r5
  int v10; // r4
  unsigned int v11; // r1
  int v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[0] = a3;
  v12[1] = a4;
  v6 = KeAbPreAcquire((unsigned int)&EmpParseLock, 0, 0);
  do
    v7 = __ldrex((unsigned __int8 *)&EmpParseLock);
  while ( __strex(v7 | 1, (unsigned __int8 *)&EmpParseLock) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    return sub_96BABC(v6);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  v12[0] = 0;
  v9 = (_DWORD *)CmpParseInfBuffer(a1, a2, v12);
  if ( v9 )
  {
    v10 = EmpParseEntryTypes();
    if ( v10 >= 0 )
    {
      v10 = EmpParseCallbacks(v9);
      if ( v10 >= 0 )
      {
        v10 = EmpParseRules(v9);
        if ( v10 >= 0 )
        {
          v10 = EmpParseStrings(v9);
          if ( v10 >= 0 )
            v10 = EmpParseTargetRules(v9);
        }
      }
    }
    CmpFreeSectionList(*v9);
    ExFreePoolWithTag((unsigned int)v9);
  }
  else
  {
    v10 = -1073741816;
  }
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&EmpParseLock);
  while ( __strex(v11 - 1, (unsigned int *)&EmpParseLock) );
  if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&EmpParseLock);
  KeAbPostRelease((unsigned int)&EmpParseLock);
  return v10;
}
