// SepRmDereferenceCap 
 
int __fastcall SepRmDereferenceCap(int a1, int a2)
{
  int result; // r0

  result = *(_DWORD *)(a1 + 16);
  if ( result )
    result = SepRmDereferenceCapTable(result, a2);
  return result;
}
