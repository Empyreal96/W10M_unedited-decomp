// KeInitializeProfile 
 
_DWORD *__fastcall KeInitializeProfile(_DWORD *result, int a2, int a3, int a4, int a5, int a6, int a7, __int16 a8, int a9)
{
  int v9; // r3
  int v10; // r2
  int v11; // r3
  _DWORD *v12; // r0

  result[7] = a3;
  result[3] = a2;
  result[4] = a4;
  result[5] = a4 + a5;
  *(_WORD *)result = 23;
  result[6] = a6 - 2;
  *((_WORD *)result + 1) = 52;
  result[8] = a7;
  *((_BYTE *)result + 50) = 0;
  *((_WORD *)result + 24) = a8;
  if ( !a9 )
    goto LABEL_5;
  v9 = dword_681D78[0] & *(_DWORD *)(a9 + 8);
  if ( result != (_DWORD *)-36 )
  {
    *((_WORD *)result + 19) = 1;
    *((_WORD *)result + 18) = 1;
    result[10] = 0;
    result[11] = v9;
  }
  if ( !v9 )
  {
LABEL_5:
    v10 = dword_681D74;
    v11 = dword_681D78[0];
    v12 = result + 9;
    *v12 = *(_DWORD *)&KeActiveProcessors;
    v12[1] = v10;
    v12[2] = v11;
    result = v12 + 3;
  }
  return result;
}
