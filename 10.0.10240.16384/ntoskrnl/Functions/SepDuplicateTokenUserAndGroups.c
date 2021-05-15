// SepDuplicateTokenUserAndGroups 
 
int __fastcall SepDuplicateTokenUserAndGroups(_DWORD *a1, _DWORD *a2, int a3, int a4)
{
  int v4; // r6
  int v5; // r7
  int result; // r0
  unsigned int *v9; // r2
  unsigned int v10; // r1
  signed int v11; // r1
  unsigned int v12; // r0
  int v13; // r3
  int v14; // r3
  int v15; // r1
  int v16; // r2
  int v17[6]; // [sp+0h] [bp-18h] BYREF

  v17[0] = a3;
  v17[1] = a4;
  v4 = a1[46];
  v5 = 0;
  v17[0] = 0;
  if ( v4 != -1 )
  {
    result = SepDuplicateSid(*(_DWORD *)(a1[37] + 8 * v4), v17);
    v5 = result;
    if ( result < 0 )
      return result;
    a2[162] = v17[0];
  }
  v9 = (unsigned int *)(a1[163] + 4);
  do
  {
    v10 = __ldrex(v9);
    v11 = v10 + 1;
  }
  while ( __strex(v11, v9) );
  if ( v11 <= 1 )
    sub_7C58E8();
  v12 = 0;
  a2[163] = a1[163];
  v13 = a1[31];
  a2[31] = v13;
  if ( v13 )
  {
    do
    {
      if ( v12 == v4 )
        v14 = a2[162];
      else
        v14 = *(_DWORD *)(a1[37] + 8 * v12);
      *(_DWORD *)(a2[37] + 8 * v12) = v14;
      v15 = a1[37] + 8 * v12;
      v16 = a2[37] + 8 * v12++;
      *(_DWORD *)(v16 + 4) = *(_DWORD *)(v15 + 4);
    }
    while ( v12 < a2[31] );
  }
  return v5;
}
