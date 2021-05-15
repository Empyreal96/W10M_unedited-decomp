// PfTGenerateTrace 
 
int __fastcall PfTGenerateTrace(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  __int64 v5; // kr00_8
  int v6; // r7
  int v7; // lr
  int v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v4 = PfTCreateTraceDump(v9);
  if ( v4 >= 0 )
  {
    ++dword_643B28;
    do
    {
      v5 = MEMORY[0xFFFF93B0];
      while ( 1 )
      {
        v6 = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        v7 = MEMORY[0xFFFF9008];
        __dmb(0xBu);
        if ( v6 == MEMORY[0xFFFF9010] )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
    while ( v5 != MEMORY[0xFFFF93B0] );
    qword_643978 = v7 - v5;
    MEMORY[0x64397C] = v7 - v5;
    PfTTraceListAdd(v9[0], -27728);
  }
  return v4;
}
