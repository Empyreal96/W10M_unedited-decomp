// MiArbitraryCodeBlocked 
 
int __fastcall MiArbitraryCodeBlocked(int a1)
{
  if ( (*(_DWORD *)(a1 + 188) & 0x400) != 0 )
    JUMPOUT(0x51D2C6);
  if ( (BYTE2(MiFlags) & 3u) > 1 )
    return sub_51D2BC();
  EtwTraceMemoryAcg(0);
  return 0;
}
