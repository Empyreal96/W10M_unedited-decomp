// EtwpIsGuidAllowed 
 
int __fastcall EtwpIsGuidAllowed(_WORD *a1)
{
  int result; // r0

  if ( *a1 )
    result = sub_808394();
  else
    result = 1;
  return result;
}
