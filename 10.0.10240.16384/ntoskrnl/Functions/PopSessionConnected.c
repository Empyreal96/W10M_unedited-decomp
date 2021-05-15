// PopSessionConnected 
 
int __fastcall PopSessionConnected(int a1, int a2, _DWORD *a3, int a4)
{
  int v7; // r0
  int result; // r0
  int v9; // r1
  int v10; // r2

  PopDiagTraceSessionStates((int)POP_ETW_ADPM_SESSION_CONNECTED, a1, a2, a4);
  if ( a2 )
  {
    PopConsoleSession = 1;
    v7 = PopSetSessionDisplayStatus(a1, 1, 0);
    PopConsoleContext = a1;
    if ( MEMORY[0xFFFF9004] >= 0x1000000u )
      result = PopConsoleSessionActiveInput(
                 a1,
                 (__int64)(MEMORY[0xFFFF9320] * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24,
                 (int)a3);
    else
      result = sub_81BAB4(v7);
  }
  else
  {
    PopSetSessionDisplayStatus(a1, 1, 0);
    if ( MEMORY[0xFFFF9004] < 0x1000000u )
    {
      v9 = -27872;
      while ( 1 )
      {
        v10 = MEMORY[0xFFFF9324];
        __dmb(0xBu);
        __dmb(0xBu);
        if ( v10 == MEMORY[0xFFFF9328] )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
    result = PopRemoteSessionActiveInput(a1, v9, a3);
  }
  return result;
}
