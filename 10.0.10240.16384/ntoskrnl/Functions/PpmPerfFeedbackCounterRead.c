// PpmPerfFeedbackCounterRead 
 
int __fastcall PpmPerfFeedbackCounterRead(int a1, int a2, int a3)
{
  int v3; // r3
  int v5; // r0
  int result; // r0

  v3 = *(unsigned __int8 *)(a1 + 33);
  v5 = *(_DWORD *)(a1 + 36);
  if ( v3 )
    result = sub_55367C(v5);
  else
    result = (*(int (__fastcall **)(int, int))a1)(v5, a3);
  return result;
}
