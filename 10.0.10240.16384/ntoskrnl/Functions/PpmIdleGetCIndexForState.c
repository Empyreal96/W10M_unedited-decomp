// PpmIdleGetCIndexForState 
 
int __fastcall PpmIdleGetCIndexForState(_BYTE *a1)
{
  if ( a1[56] )
    return sub_5295BC();
  if ( !a1[59] )
    return 3;
  if ( a1[60] )
    return 1;
  return 2;
}
