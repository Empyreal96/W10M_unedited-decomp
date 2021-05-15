// PopPepUpdateIdleState 
 
int __fastcall PopPepUpdateIdleState(int a1, _DWORD *a2, int a3)
{
  int result; // r0

  result = PopPepGetComponentPreferedIdleState(a2);
  if ( result != a2[36] )
  {
    if ( a3 )
      result |= 0x80000000;
    result = PopPepTriggerActivity(a1, (int)a2, 1, result);
  }
  return result;
}
