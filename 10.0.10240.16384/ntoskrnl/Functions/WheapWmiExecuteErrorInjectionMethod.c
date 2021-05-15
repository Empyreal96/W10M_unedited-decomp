// WheapWmiExecuteErrorInjectionMethod 
 
int __fastcall WheapWmiExecuteErrorInjectionMethod(int a1, unsigned int a2, int *a3, unsigned int a4, int *a5)
{
  int result; // r0
  int v8; // r5
  int v9; // r0
  int v10; // r2
  int v11; // r0
  int v12[6]; // [sp+18h] [bp-18h] BYREF

  if ( a1 == 1 )
  {
    v12[0] = 0;
    v11 = PshedGetInjectionCapabilities(v12);
    v8 = 8;
    if ( a2 >= 8 )
    {
      if ( v11 >= 0 )
      {
        *a3 = 0;
        result = 0;
        a3[1] = v12[0];
        goto LABEL_14;
      }
      goto LABEL_13;
    }
LABEL_10:
    result = -1073741789;
    goto LABEL_14;
  }
  if ( a1 == 2 )
  {
    if ( a4 < 0x24 )
    {
      result = -1073741811;
      v8 = 0;
      goto LABEL_14;
    }
    v9 = *a3;
    v10 = a3[2];
    v8 = 4;
    if ( a2 >= 4 )
    {
      result = PshedInjectError(v9, PshedInjectError, v10, a3[3], a3[4], a3[5], a3[6], a3[7], a3[8], a3[9]);
      if ( result >= 0 )
      {
        *a3 = 0;
        goto LABEL_14;
      }
LABEL_13:
      result = -1073741823;
      *a3 = -1073741823;
      goto LABEL_14;
    }
    goto LABEL_10;
  }
  result = -1073741161;
  v8 = 0;
LABEL_14:
  *a5 = v8;
  return result;
}
