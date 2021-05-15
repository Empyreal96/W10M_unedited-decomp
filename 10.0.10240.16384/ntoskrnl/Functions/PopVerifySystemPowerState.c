// PopVerifySystemPowerState 
 
int *__fastcall PopVerifySystemPowerState(int *result, int a2)
{
  int v2; // r2
  int v3; // r4

  if ( result )
  {
    v2 = *result;
    if ( *result != 1 && v2 && v2 < 6 )
    {
      v3 = 1;
      if ( a2 >= 0 )
      {
        if ( a2 > 1 )
        {
          if ( a2 != 2 )
            goto LABEL_30;
        }
        else
        {
          if ( v2 == 5 )
            return (int *)sub_7F1DA0();
          if ( v2 == 4 )
          {
            if ( byte_61EA45 )
              goto LABEL_30;
            v2 = 3;
          }
          if ( v2 == 3 )
          {
            if ( byte_61EA44 )
              goto LABEL_30;
            v2 = 2;
          }
          if ( v2 == 2 )
          {
            if ( byte_61EA43 )
              goto LABEL_30;
            v2 = 1;
          }
          if ( v2 != 1 || a2 != 1 )
            goto LABEL_30;
          v2 = 2;
          v3 = 0;
        }
        if ( v2 == 2 )
        {
          if ( byte_61EA43 )
            goto LABEL_30;
          v2 = 3;
        }
        if ( v2 == 3 )
        {
          if ( byte_61EA44 )
            goto LABEL_30;
          v2 = 4;
        }
        if ( v2 != 4 )
        {
LABEL_27:
          if ( v2 == 5 && (!v3 || !byte_61EA46 || !byte_61EA48) )
            v2 = 1;
          goto LABEL_30;
        }
        if ( !byte_61EA45 )
        {
          v2 = 5;
          goto LABEL_27;
        }
      }
LABEL_30:
      *result = v2;
      return result;
    }
  }
  return result;
}
