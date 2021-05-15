// CcSetBcbOwnerPointer 
 
int __fastcall CcSetBcbOwnerPointer(int result, int a2)
{
  int v3; // r4
  int i; // r3
  int v5; // t1

  if ( *(_WORD *)result != 762 )
    return ExSetResourceOwnerPointer(result + 56, a2);
  v3 = result + 16;
  for ( i = *(_DWORD *)(result + 16); i; i = v5 )
  {
    result = ExSetResourceOwnerPointer(i + 56, a2);
    v5 = *(_DWORD *)(v3 + 4);
    v3 += 4;
  }
  return result;
}
