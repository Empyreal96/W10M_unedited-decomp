// PsSetThreadProperty 
 
int __fastcall PsSetThreadProperty(int a1, int a2, int a3)
{
  int result; // r0
  _DWORD *v7; // r0

  result = PspValidateThread();
  if ( result >= 0 )
  {
    v7 = (_DWORD *)(a1 + 1060);
    if ( a3 )
      result = PspInsertProperty(v7, a2, a3);
    else
      result = PspRemoveProperty((int)v7, a2, 0);
  }
  return result;
}
