// AuthzBasepEvaluateAttribute 
 
int __fastcall AuthzBasepEvaluateAttribute(int a1)
{
  int result; // r0
  unsigned int v3; // r3
  _QWORD *v4; // r3

  result = 0;
  if ( !a1 )
    return -1;
  v3 = *(_DWORD *)(a1 + 20);
  if ( !v3 )
    return 0;
  if ( v3 > 1 )
    goto LABEL_12;
  if ( *(_WORD *)(a1 + 12) )
  {
    if ( *(_WORD *)(a1 + 12) != 6 )
      return sub_517554(0);
    v4 = *(_QWORD **)(a1 + 24);
    if ( v4 )
    {
      if ( *v4 )
LABEL_12:
        result = 1;
    }
  }
  return result;
}
