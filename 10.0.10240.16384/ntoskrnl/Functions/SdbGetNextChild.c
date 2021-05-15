// SdbGetNextChild 
 
unsigned int __fastcall SdbGetNextChild(int a1, int a2, int a3)
{
  unsigned int result; // r0
  unsigned int v7; // r5

  if ( a2 )
  {
    if ( (SdbGetTagFromTagID(a1, a2) & 0xF000) != 28672 )
      return sub_7CCC20();
    v7 = SdbpGetNextTagId(a1, a2);
  }
  else
  {
    v7 = *(_DWORD *)(a1 + 12);
  }
  result = SdbpGetNextTagId(a1, a3);
  if ( result >= v7 )
    result = 0;
  return result;
}
