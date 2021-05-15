// IopFreeCompletionListPackets 
 
int __fastcall IopFreeCompletionListPackets(int result, int a2)
{
  int v3; // r4
  int v4; // r0
  int v5; // r3

  v3 = result;
  while ( v3 )
  {
    v4 = v3;
    v5 = *(unsigned __int8 *)(v3 + 8);
    v3 = *(_DWORD *)v3;
    if ( !v5 )
      return sub_7E7914();
    if ( v5 == 2 )
      result = IopFreeWaitCompletionPacket(v4, a2);
    else
      result = IopFreeMiniCompletionPacket(v4, a2);
  }
  return result;
}
