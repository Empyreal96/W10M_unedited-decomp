// PspGetJobProperty 
 
int __fastcall PspGetJobProperty(int a1, int a2, _DWORD *a3)
{
  int result; // r0
  int v6; // [sp+8h] [bp-10h]
  int v7[3]; // [sp+Ch] [bp-Ch] BYREF

  result = -1073741275;
  v6 = a2;
  v7[0] = 0;
  if ( a1 )
  {
    while ( 1 )
    {
      result = PspGetProperty(a1 + 724, a2, v7);
      if ( result >= 0 )
        break;
      a1 = *(_DWORD *)(a1 + 572);
      if ( !a1 )
        return result;
      a2 = v6;
    }
    *a3 = v7[0];
  }
  return result;
}
