// PopSetWin32kInputTimeout 
 
int __fastcall PopSetWin32kInputTimeout(int a1, int a2)
{
  int result; // r0
  int v3; // [sp-4h] [bp-28h] BYREF
  int v4; // [sp+0h] [bp-24h]
  int v5; // [sp+4h] [bp-20h]
  int v6; // [sp+8h] [bp-1Ch]
  int v7; // [sp+Ch] [bp-18h]

  v7 = a2;
  if ( (!a1 || a1 == -1) && (a1 || MEMORY[0xFFFF92D8]) )
  {
    v3 = -2053986314;
    v4 = 1329725996;
    v5 = 1960280460;
    v6 = 547982431;
    result = PopBroadcastSessionInfo(-2053986314, 1329725996, (int)&v3);
  }
  else
  {
    v3 = 883313723;
    v4 = 1097958167;
    v5 = -1314662229;
    v6 = 826490606;
    result = PopSendSessionInfo(a1);
  }
  return result;
}
