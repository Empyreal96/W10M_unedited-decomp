// PopPepCountReadyActivities 
 
int __fastcall PopPepCountReadyActivities(int a1, int a2, int a3)
{
  int v3; // r4
  int result; // r0
  int i; // r2
  int v6; // r3

  v3 = a1;
  if ( !a3 )
    return 0;
  result = *(_DWORD *)(a1 + 72);
  if ( a3 == 2 )
    return sub_54B524(result);
  if ( a3 == 3 )
  {
    for ( i = *(_DWORD *)(v3 + 120); i; --i )
    {
      v6 = *(_DWORD *)(v3 + 200);
      v3 += 168;
      result += v6;
    }
  }
  return result;
}
