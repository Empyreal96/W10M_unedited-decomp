// PoExecutePerfCheck 
 
void PoExecutePerfCheck()
{
  unsigned int v0; // r5
  unsigned int v1; // r6
  __int64 v2; // r0
  unsigned int v3; // lr
  unsigned int v4; // r7
  unsigned int v5; // r9
  unsigned __int64 v6; // kr00_8
  unsigned __int64 v7; // r2
  unsigned int v8; // r4
  unsigned __int64 v9; // kr18_8

  if ( PpmIdleCheckIdleDurationExpiration )
  {
    sub_541FE0();
  }
  else
  {
    v0 = HIDWORD(PpmCheckLastExecutionTime);
    v1 = PpmCheckLastExecutionTime;
    if ( PpmCheckLastExecutionTime )
    {
      v3 = HIDWORD(PpmCheckPeriod);
      LODWORD(v2) = PpmCheckPeriod;
      if ( PpmCheckPeriod <= (unsigned __int64)(unsigned int)KeTimeIncrement )
      {
        LODWORD(v2) = KeTimeIncrement;
        v3 = 0;
      }
      while ( 1 )
      {
        v4 = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        v5 = MEMORY[0xFFFF9008];
        __dmb(0xBu);
        if ( v4 == MEMORY[0xFFFF9010] )
          break;
        __dmb(0xAu);
        __yield();
      }
      if ( __PAIR64__(v3, v2) + __PAIR64__(v0, v1) <= __PAIR64__(v4, v5) )
      {
        if ( v1 == 1 && !v0 )
          goto LABEL_14;
        if ( __PAIR64__(v3, KeMaximumIncrement) + (unsigned int)v2 + __PAIR64__(v0, v1) > __PAIR64__(v4, v5) )
        {
          v6 = __PAIR64__(v3, v2) + __PAIR64__(v0, v1);
          v4 = HIDWORD(v6);
          v5 = v6;
        }
        v7 = __PAIR64__(v4, v5) - __PAIR64__(v3, v2) - __PAIR64__(v0, v1);
        if ( v7 >= __PAIR64__(v3, v2) )
        {
          HIDWORD(v2) = v3;
          if ( !(_DWORD)v2 && !v3 )
            __brkdiv0();
          v8 = _rt_udiv64(v2, v7);
          if ( v8 >= 0x40 )
            v8 = 64;
        }
        else
        {
LABEL_14:
          v8 = 0;
        }
        __dmb(0xBu);
        do
          v9 = __ldrexd((unsigned __int64 *)&PpmCheckLastExecutionTime);
        while ( __PAIR64__(v9, HIDWORD(v9)) == __PAIR64__(v1, v0)
             && __strexd(__PAIR64__(v4, v5), (unsigned __int64 *)&PpmCheckLastExecutionTime) );
        __dmb(0xBu);
        if ( __PAIR64__(v9, HIDWORD(v9)) == __PAIR64__(v1, v0) )
          KiInsertQueueDpc((int)&PpmCheckStartDpc, v8, 0, 0, 0);
      }
    }
  }
}
