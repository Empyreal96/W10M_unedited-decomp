// RtlEnumerateGenericTableAvl 
 
int __fastcall RtlEnumerateGenericTableAvl(int a1, int a2)
{
  if ( a2 )
    *(_DWORD *)(a1 + 32) = 0;
  return RtlEnumerateGenericTableWithoutSplayingAvl(a1, a1 + 32);
}
