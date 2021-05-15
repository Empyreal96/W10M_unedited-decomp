// KsepEvntLogFlagsApplied 
 
int __fastcall KsepEvntLogFlagsApplied(int result, int a2, int a3, int a4)
{
  int v5; // r7
  __int64 v6; // r4
  int varg_r0; // [sp+68h] [bp+8h]
  int varg_r1; // [sp+6Ch] [bp+Ch]

  varg_r0 = result;
  varg_r1 = a2;
  v5 = result;
  v6 = KseEtwHandle;
  if ( KseEtwHandle )
  {
    result = EtwEventEnabled(KseEtwHandle, SHIDWORD(KseEtwHandle), (int)KseFlagsApplied);
    if ( result )
    {
      if ( v5 )
      {
        if ( a2 )
          result = EtwWrite(v6, SHIDWORD(v6), (int)KseFlagsApplied, 0);
      }
    }
  }
  return result;
}
