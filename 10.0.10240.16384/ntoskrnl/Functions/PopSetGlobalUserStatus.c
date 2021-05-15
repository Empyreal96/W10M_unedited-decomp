// PopSetGlobalUserStatus 
 
int __fastcall PopSetGlobalUserStatus(unsigned int a1, int a2, int a3, int a4)
{
  int v4; // r6
  unsigned int v5; // r5
  char v7; // r3

  v4 = a2;
  v5 = a1;
  if ( PopMaximumConnectionSessions )
  {
    if ( a1 >= PopMaximumConnectionSessions )
      return sub_7F24FC();
    if ( PopMaximumConnectionSessions )
    {
      a2 = dword_61DE24;
      v7 = a1 & 7;
      if ( v4 )
      {
        a1 >>= 3;
        a3 = 1 << v7;
        *(_BYTE *)((v5 >> 3) + dword_61DE24) &= ~(1 << v7);
      }
      else
      {
        a3 = 1 << v7;
        *(_BYTE *)((a1 >> 3) + dword_61DE24) |= 1 << v7;
      }
    }
  }
  return PopEvaluateGlobalUserStatus(a1, a2, a3, a4);
}
