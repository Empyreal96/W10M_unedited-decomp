// AuthzBasepCompareOctetStringOperands 
 
int __fastcall AuthzBasepCompareOctetStringOperands(int a1, _DWORD *a2)
{
  unsigned int *v3; // r0
  int v4; // r5
  unsigned int v5; // r3
  unsigned int *v6; // r2
  unsigned int v7; // r5
  unsigned int v8; // r6
  int v9; // r2
  int result; // r0
  unsigned int v11; // [sp+0h] [bp-20h] BYREF
  unsigned int v12; // [sp+4h] [bp-1Ch]
  unsigned int v13; // [sp+8h] [bp-18h]
  unsigned int v14; // [sp+Ch] [bp-14h]

  v3 = &v11;
  v4 = 2;
  do
  {
    if ( a2[3] == 1 )
    {
      *v3 = a2[6];
      v5 = a2[5];
    }
    else
    {
      v6 = *(unsigned int **)(a2[4] + 24);
      *v3 = *v6;
      v5 = v6[1];
    }
    v3[1] = v5;
    v3 += 2;
    a2 += 7;
    --v4;
  }
  while ( v4 );
  v7 = v12;
  v8 = v14;
  v9 = v12;
  if ( v12 >= v14 )
    v9 = v14;
  result = memcmp(v11, v13, v9);
  if ( !result )
  {
    if ( v7 <= v8 )
    {
      if ( v7 < v8 )
        result = -1;
    }
    else
    {
      result = 1;
    }
  }
  switch ( a1 )
  {
    case 128:
      return !result;
    case 129:
      return result != 0;
    case 130:
      return result < 0;
    case 131:
      return result <= 0;
    case 132:
      return result > 0;
  }
  if ( a1 != 133 )
    return result;
  return result >= 0;
}
