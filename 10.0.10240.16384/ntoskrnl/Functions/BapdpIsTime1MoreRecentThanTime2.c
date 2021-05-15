// BapdpIsTime1MoreRecentThanTime2 
 
int __fastcall BapdpIsTime1MoreRecentThanTime2(__int16 *a1, __int16 *a2)
{
  int v2; // r3
  int v3; // r2
  int result; // r0
  int v5; // r3
  int v6; // r2
  int v7; // r3
  int v8; // r2
  int v9; // r3
  int v10; // r2
  int v11; // r3
  int v12; // r2
  int v13; // r3
  int v14; // r2

  v2 = *a1;
  v3 = *a2;
  if ( v2 > v3 )
    goto LABEL_2;
  if ( v2 < v3 )
    goto LABEL_15;
  v5 = a1[1];
  v6 = a2[1];
  if ( v5 > v6 )
    goto LABEL_2;
  if ( v5 < v6 )
    goto LABEL_15;
  v7 = a1[2];
  v8 = a2[2];
  if ( v7 > v8
    || v7 >= v8
    && ((v9 = a1[3], v10 = a2[3], v9 > v10)
     || v9 >= v10
     && ((v11 = a1[4], v12 = a2[4], v11 > v12)
      || v11 >= v12 && ((v13 = a1[5], v14 = a2[5], v13 > v14) || v13 >= v14 && a1[6] > a2[6]))) )
  {
LABEL_2:
    result = 1;
  }
  else
  {
LABEL_15:
    result = 0;
  }
  return result;
}
