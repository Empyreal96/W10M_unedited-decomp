// WheapCommitPolicy 
 
int __fastcall WheapCommitPolicy(int a1, int a2, int a3, int a4)
{
  int v4; // r2
  int v5; // r3
  int v6; // r4
  int v7; // r2
  int v8; // r3
  unsigned __int16 **v9; // r6
  int v10; // r7
  unsigned int v11; // r5

  v6 = RtlCheckRegistryKey(2, (int)L"WHEA\\Policy", a3, a4);
  if ( v6 >= 0
    || (v6 = RtlCreateRegistryKey(2, (int)L"WHEA", v4, v5), v6 >= 0)
    && (v6 = RtlCreateRegistryKey(2, (int)L"WHEA\\Policy", v7, v8), v6 >= 0) )
  {
    v9 = (unsigned __int16 **)&WheaRegPolicyTable;
    v10 = 0;
    v11 = 0;
    while ( 1 )
    {
      if ( WheaRegPolicyTableChanged[v11] )
      {
        v10 = 1;
        v6 = RtlWriteRegistryValue(2, (int)L"WHEA\\Policy", *v9);
        if ( v6 < 0 )
          break;
      }
      ++v11;
      v9 += 4;
      if ( v11 >= 7 )
      {
        if ( v10 )
          WheapPfaReset();
        return v6;
      }
    }
  }
  return v6;
}
