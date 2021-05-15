// BiTranslateDisplayOrder 
 
int __fastcall BiTranslateDisplayOrder(int a1, int a2, int a3, int *a4)
{
  int v4; // r8
  int v5; // r5
  int result; // r0

  v4 = *a4;
  v5 = 0;
  if ( *a4 )
  {
    while ( BiTranslateObjectIdentifier(a1, a2, a3) >= 0 )
    {
      ++v5;
      a3 += 4;
      a2 += 16;
      if ( !--v4 )
        goto LABEL_5;
    }
    result = sub_8147D0();
  }
  else
  {
LABEL_5:
    *a4 = v5;
    result = 0;
  }
  return result;
}
