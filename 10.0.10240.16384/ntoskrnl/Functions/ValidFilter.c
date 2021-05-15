// ValidFilter 
 
int __fastcall ValidFilter(unsigned int a1, _DWORD *a2)
{
  unsigned int v4; // r5
  int v6; // [sp+8h] [bp-48h] BYREF
  int v7[2]; // [sp+10h] [bp-40h] BYREF
  int v8; // [sp+18h] [bp-38h] BYREF
  char v9[36]; // [sp+1Ch] [bp-34h] BYREF

  v8 = 0;
  memset(v9, 0, sizeof(v9));
  v6 = 0;
  v7[0] = 1;
  v7[1] = (int)&v8;
  if ( FilterEval(GetPropertyFromPropArray, v7, a1, a2, &v6) == -1073741811 )
    return 0;
  v4 = 0;
  if ( a1 )
  {
    while ( !a2[7] && PnpValidatePropertyData(a2[10], a2[9], a2[8], 0) != 1 )
    {
      ++v4;
      a2 += 11;
      if ( v4 >= a1 )
        return 1;
    }
    return 0;
  }
  return 1;
}
