// PopCheckDisabledState 
 
int __fastcall PopCheckDisabledState(int a1)
{
  int result; // r0
  int *i; // r2

  result = 0;
  for ( i = (int *)PowerStateDisableReasonListHead; i != &PowerStateDisableReasonListHead; i = (int *)*i )
  {
    if ( *((_BYTE *)i + a1 + 8) )
      return 1;
  }
  return result;
}
