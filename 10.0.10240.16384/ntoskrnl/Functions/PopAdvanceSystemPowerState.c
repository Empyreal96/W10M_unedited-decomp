// PopAdvanceSystemPowerState 
 
int *__fastcall PopAdvanceSystemPowerState(int *result, int a2, int a3, int a4)
{
  int v6; // r4
  int v7; // r3
  int v8; // r1
  int v9; // r3

  if ( !result )
    return result;
  v6 = *result;
  if ( *result < 2 )
    return result;
  if ( v6 >= 6 )
  {
LABEL_4:
    *result = 1;
    return result;
  }
  switch ( a2 )
  {
    case 0:
      v7 = v6 - 1;
      v8 = 0;
LABEL_13:
      *result = v7;
      result = PopVerifySystemPowerState(result, v8);
      break;
    case 1:
      *result = v6 - 1;
      result = PopVerifySystemPowerState(result, 1);
      if ( *result == v6 )
        *result = 1;
      break;
    case 2:
      if ( v6 == 5 )
        goto LABEL_4;
      v7 = v6 + 1;
      v8 = 2;
      goto LABEL_13;
  }
  v9 = *result;
  if ( *result != 1 && (v9 < a3 || v9 > a4) )
    *result = 1;
  return result;
}
