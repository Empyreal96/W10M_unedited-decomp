// InbvDetermineFunction 
 
int __fastcall InbvDetermineFunction(int a1)
{
  int result; // r0
  int v3; // r5
  int v4; // r0

  result = dword_6328F8;
  if ( !dword_6328F8 )
  {
    v3 = 1;
    if ( *(_DWORD *)(a1 + 120) )
    {
      v4 = strupr(*(_DWORD *)(a1 + 120));
      if ( strstr(v4, "NOVGA") )
        v3 = 0;
    }
    if ( !*(_DWORD *)(*(_DWORD *)(a1 + 132) + 112) )
      JUMPOUT(0x50B7A0);
    if ( v3 )
    {
      result = sub_50B79C();
    }
    else
    {
      result = 1;
      dword_6328F4 = (int)&off_616268;
      dword_6328F8 = 1;
    }
  }
  return result;
}
