// SeSetTokenTrustLink 
 
int __fastcall SeSetTokenTrustLink(int a1, int a2)
{
  int result; // r0

  result = ObfReferenceObjectWithTag(a2, 1953261124);
  *(_DWORD *)(a1 + 644) = a2;
  return result;
}
