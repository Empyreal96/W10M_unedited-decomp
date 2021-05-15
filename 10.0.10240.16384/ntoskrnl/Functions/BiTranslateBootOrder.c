// BiTranslateBootOrder 
 
int __fastcall BiTranslateBootOrder(int a1, int *a2, int a3, int *a4)
{
  int v4; // r7
  int v5; // r5
  int v10; // t1
  int result; // r0

  v4 = *a4;
  v5 = 0;
  if ( *a4 )
  {
    while ( 1 )
    {
      v10 = *a2++;
      if ( BiTranslateBootEntryId(a1, v10, a3) < 0 )
        break;
      ++v5;
      a3 += 16;
      if ( !--v4 )
        goto LABEL_5;
    }
    result = sub_8147C4();
  }
  else
  {
LABEL_5:
    *a4 = v5;
    result = 0;
  }
  return result;
}
