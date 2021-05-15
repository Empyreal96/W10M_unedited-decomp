// PopPepCancelActivities 
 
int __fastcall PopPepCancelActivities(int result, int a2, int a3)
{
  int v4; // r3
  int v5; // r6
  int v6; // r4

  v4 = *(_DWORD *)&ActivityAttributes[124 * a3 + 4];
  v5 = result;
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      v6 = result + 72;
      PopPepCancelActivityRange(result + 48, a3, 0, 0, result + 72);
      result = PopPepCancelActivityRange(v5 + 48, a3, 4, 5, v6);
    }
    else if ( v4 == 2 )
    {
      result = PopPepCancelActivityRange(a2 + 48, a3, 0, 5, a2 + 72);
    }
  }
  return result;
}
