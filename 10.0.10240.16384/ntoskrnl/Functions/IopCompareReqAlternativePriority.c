// IopCompareReqAlternativePriority 
 
int __fastcall IopCompareReqAlternativePriority(_DWORD **a1, _DWORD **a2)
{
  _DWORD *v2; // r0
  _DWORD *v3; // r1

  v2 = *a1;
  v3 = *a2;
  if ( *v2 == *v3 )
  {
    if ( v2[1] <= v3[1] )
      return sub_81B7E8();
  }
  else if ( *v2 <= *v3 )
  {
    return -1;
  }
  return 1;
}
