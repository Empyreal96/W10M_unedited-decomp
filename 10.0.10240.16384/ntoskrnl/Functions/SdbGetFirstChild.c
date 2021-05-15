// SdbGetFirstChild 
 
unsigned int __fastcall SdbGetFirstChild(int a1, int a2, int a3, int a4)
{
  unsigned int v6; // r3
  unsigned int result; // r0

  if ( a2 )
  {
    if ( (SdbGetTagFromTagID(a1, a2, a3, a4) & 0xF000) != 28672 )
      return 0;
    v6 = SdbpGetNextTagId(a1, a2);
    result = a2 + 6;
  }
  else
  {
    v6 = *(_DWORD *)(a1 + 12);
    result = 12;
  }
  if ( result >= v6 )
    return 0;
  return result;
}
