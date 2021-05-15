// PopPowerRequestExecuteCallbacks 
 
int __fastcall PopPowerRequestExecuteCallbacks(int result, int a2, int a3)
{
  int v5; // r7
  int i; // r4
  int v7; // r1

  v5 = result;
  for ( i = 0; i < 5; ++i )
  {
    if ( *(_BYTE *)(i + v5) )
    {
      if ( i == 3 )
      {
        v7 = a2;
      }
      else if ( i == 1 )
      {
        v7 = 1;
      }
      else
      {
        v7 = a3;
      }
      result = ((int (__fastcall *)(bool, int))PopPowerRequestAttributes[2 * i + 1])(*(char *)(i + v5) > 0, v7);
    }
  }
  return result;
}
