// CcDereferenceVacbArray 
 
int __fastcall CcDereferenceVacbArray(int result, int a2)
{
  int v2; // r3

  if ( !a2 )
    return sub_53DDE4();
  v2 = *(_DWORD *)(result + 4);
  if ( !v2 )
    KeBugCheckEx(52, 329, -1073740768);
  *(_DWORD *)(result + 4) = v2 - 1;
  return result;
}
