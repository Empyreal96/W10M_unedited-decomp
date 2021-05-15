// _TlgEnableCallback 
 
int __fastcall TlgEnableCallback(int result, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int *a10)
{
  int v10; // r2
  int (__fastcall *v11)(int); // r5

  if ( a10 )
  {
    if ( a2 )
    {
      if ( a2 != 1 )
        goto LABEL_8;
      if ( a3 )
        v10 = a3 + 1;
      else
        v10 = 256;
      a10[2] = a5;
      a10[3] = a6;
      a10[4] = a7;
      a10[5] = a8;
    }
    else
    {
      v10 = 0;
    }
    *a10 = v10;
LABEL_8:
    v11 = (int (__fastcall *)(int))a10[8];
    if ( v11 )
      result = v11(result);
  }
  return result;
}
