// DrvDbGetObjectSubKeyList 
 
int __fastcall DrvDbGetObjectSubKeyList(int *a1, int a2, int a3, int a4, _WORD *a5, unsigned int a6, unsigned int *a7, int a8)
{
  int result; // r0
  int v12; // r3
  unsigned int v13; // r3
  int v15[144]; // [sp+8h] [bp-240h] BYREF

  *a7 = 0;
  if ( a6 )
    *a5 = 0;
  memset(v15, 0, 540);
  v15[133] = a6;
  v15[134] = 0;
  v15[0] = a8;
  v15[130] = a3;
  v15[131] = a4;
  v15[132] = (int)a5;
  result = PnpCtxRegEnumKeyWithCallback(a1, a2, (int)DrvDbGetObjectSubKeyCallback, (int)v15);
  if ( result >= 0 )
  {
    v12 = v15[134];
    *a7 = v15[134];
    if ( v12 )
    {
      v13 = v12 + 1;
      *a7 = v13;
      if ( a5 && v13 <= a6 )
        a5[v13 - 1] = 0;
      else
        result = -1073741789;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}
