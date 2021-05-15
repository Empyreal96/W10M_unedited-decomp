// RtlLookupElementGenericTableFullAvl 
 
int __fastcall RtlLookupElementGenericTableFullAvl(int a1, int a2, _DWORD *a3, int *a4)
{
  int v6; // r0
  int result; // r0

  v6 = FindNodeOrParent(a1);
  *a4 = v6;
  if ( v6 == 1 )
    result = *a3 + 16;
  else
    result = 0;
  return result;
}
