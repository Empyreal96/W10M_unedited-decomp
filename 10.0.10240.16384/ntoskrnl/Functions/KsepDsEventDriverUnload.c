// KsepDsEventDriverUnload 
 
int __fastcall KsepDsEventDriverUnload(int result, int a2)
{
  __int64 v2; // r4
  int vars8; // [sp+40h] [bp+8h]

  vars8 = result;
  v2 = KseEtwHandle;
  if ( KseEtwHandle )
  {
    result = EtwEventEnabled(KseEtwHandle, SHIDWORD(KseEtwHandle), (int)KseDsEventDriverUnload);
    if ( result )
      result = EtwWrite(v2, SHIDWORD(v2), (int)KseDsEventDriverUnload, 0);
  }
  return result;
}
