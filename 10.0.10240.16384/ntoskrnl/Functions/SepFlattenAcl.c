// SepFlattenAcl 
 
int __fastcall SepFlattenAcl(int a1, int *a2, _DWORD *a3, _WORD *a4)
{
  int v4; // lr
  int v5; // r7
  int v6; // r5
  unsigned __int8 *v8; // r6
  unsigned int v9; // r4
  int v10; // r0
  int v11; // r6
  int result; // r0
  _DWORD *v13; // r9
  unsigned __int8 *v14; // r4
  unsigned int i; // r8
  unsigned int v16; // r3
  int v17; // r2
  int v18; // r3

  v4 = *(unsigned __int16 *)(a1 + 4);
  v5 = 0;
  v6 = 0;
  *a2 = 0;
  *a3 = 0;
  v8 = (unsigned __int8 *)(a1 + 8);
  if ( !v4 )
    return -1073741275;
  do
  {
    v9 = *v8;
    v6 += 12;
    if ( v9 <= 3 )
    {
      v6 += 4 * (v8[9] + 2);
LABEL_7:
      v5 = (unsigned __int16)(v5 + 1);
      goto LABEL_8;
    }
    if ( v9 == 17 || v9 == 20 )
    {
      v6 += 4 * (v8[9] + 2);
      goto LABEL_7;
    }
LABEL_8:
    v8 += *((unsigned __int16 *)v8 + 1);
    --v4;
  }
  while ( v4 );
  if ( !v5 )
    return -1073741275;
  v10 = ExAllocatePoolWithTag(1, v6);
  v11 = v10;
  if ( !v10 )
    return -1073741801;
  v13 = (_DWORD *)v10;
  v14 = (unsigned __int8 *)(a1 + 8);
  for ( i = 0; i < *(unsigned __int16 *)(a1 + 4); v14 += *((unsigned __int16 *)v14 + 1) )
  {
    v16 = *v14;
    if ( v16 <= 3 || v16 == 17 || v16 == 20 )
    {
      v17 = *((_DWORD *)v14 + 1);
      v13[1] = v14[1];
      v18 = *v14;
      v13[2] = v17;
      *v13 = v18;
      memmove((int)(v13 + 3), (int)(v14 + 8), 4 * (v14[9] + 2));
      v13 += v14[9] + 5;
    }
    ++i;
  }
  result = 0;
  *a2 = v11;
  *a3 = v6;
  *a4 = v5;
  return result;
}
