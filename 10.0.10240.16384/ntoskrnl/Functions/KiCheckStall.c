// KiCheckStall 
 
int __fastcall KiCheckStall(int a1, int a2)
{
  int v4; // r6
  int result; // r0
  int v6; // r10
  unsigned __int64 v7; // r0
  int v8; // r3
  __int64 v9; // [sp+0h] [bp-30h] BYREF
  __int64 v10[5]; // [sp+8h] [bp-28h] BYREF

  v4 = KiFreezeStallOwner;
  if ( a1 == KiFreezeStallOwner )
  {
    KeQueryPerformanceCounter(&v9, v10);
    v6 = v9;
    if ( !v10[0] )
      __brkdiv0();
    LODWORD(v7) = _rt_udiv64(v10[0], 1000 * (v9 - *(_QWORD *)&KiLastStallTick));
    if ( v7 > 0x1F4 )
    {
      __dsb(0xFu);
      v8 = HIDWORD(v9);
      __sev();
      KiLastStallTick = v6;
      unk_62182C = v8;
    }
  }
  result = ReadTimeStampCounter();
  if ( a2 && v4 && v4 != a1 && KiDebuggerOwner && KiDebuggerOwner != a1 )
  {
    __dmb(0xAu);
    __yield();
    __dsb(0xFu);
    __wfe();
  }
  return result;
}
