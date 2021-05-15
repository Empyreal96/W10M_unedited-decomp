// PspReadIFEOMitigationOptions 
 
int __fastcall PspReadIFEOMitigationOptions(int a1, _DWORD *a2, __int64 a3)
{
  int v4; // r0
  int v6; // r5
  int v7; // r1
  __int64 v9; // [sp+8h] [bp-10h] BYREF

  v9 = a3;
  if ( a1 )
  {
    v4 = *(_DWORD *)(a1 + 112);
    if ( v4 )
    {
      if ( RtlQueryImageFileKeyOption(v4, L"MitigationOptions", 11, (int *)&v9, 8u, 0) >= 0 )
      {
        v6 = v9;
        if ( PspValidateMitigationOptions(v9, 0i64) >= 0 )
        {
          *a2 = v6;
          a2[1] = v7;
        }
      }
    }
  }
  return a1;
}
