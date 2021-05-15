// SdbInitDatabaseInMemory 
 
int __fastcall SdbInitDatabaseInMemory(int a1, int a2)
{
  _DWORD *v4; // r7
  int v6; // r0
  int v7; // r2
  int v8; // r3
  int v9; // r4

  v4 = AslAlloc(a1, 628);
  if ( !v4 )
    return sub_7CE1CC();
  v6 = SdbpOpenDatabaseInMemory(a1, a2);
  v4[1] = v6;
  if ( !v6 )
  {
    AslLogCallPrintf(1, "SdbInitDatabaseInMemory", 658, "Unable to open main database");
    if ( !v4[1] )
      JUMPOUT(0x7CE1E0);
    JUMPOUT(0x7CE1DC);
  }
  v4[3] = 1;
  v4[4] = 1;
  v4[10] = 2;
  v4[9] = v4[1];
  v7 = *(_DWORD *)(v4[1] + 24);
  v8 = *(_DWORD *)(v4[1] + 28);
  v9 = *(_DWORD *)(v4[1] + 32);
  v4[5] = *(_DWORD *)(v4[1] + 20);
  v4[6] = v7;
  v4[7] = v8;
  v4[8] = v9;
  SdbpInitializeMatchers(v4);
  return (int)v4;
}
