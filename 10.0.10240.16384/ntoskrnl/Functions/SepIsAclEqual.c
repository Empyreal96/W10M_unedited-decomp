// SepIsAclEqual 
 
int __fastcall SepIsAclEqual(int a1, int a2)
{
  int v3; // r4

  if ( a1 )
  {
    if ( !a2 )
      return 0;
    v3 = *(unsigned __int16 *)(a1 + 2);
    if ( v3 != *(unsigned __int16 *)(a2 + 2)
      || RtlCompareMemory((unsigned __int8 *)a1, a2, *(unsigned __int16 *)(a1 + 2)) != v3 )
    {
      return 0;
    }
  }
  else if ( a2 )
  {
    return 0;
  }
  return 1;
}
