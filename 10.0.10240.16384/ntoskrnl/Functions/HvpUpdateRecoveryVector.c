// HvpUpdateRecoveryVector 
 
_BYTE *__fastcall HvpUpdateRecoveryVector(_BYTE *result, unsigned int a2, _BYTE *a3)
{
  _DWORD *v5; // r5
  unsigned int i; // r8
  unsigned int v7; // r4
  unsigned int v8; // r1
  unsigned int v9; // r2

  v5 = result;
  for ( i = 0; i < a2; v5 += 2 )
  {
    v7 = *(_DWORD *)a3;
    v8 = *v5 >> 9;
    v9 = v5[1] >> 9;
    if ( v8 >= *(_DWORD *)a3 )
      break;
    if ( v9 + v8 > v7 )
      v9 = v7 - v8;
    result = RtlSetBits(a3, v8, v9);
    ++i;
  }
  return result;
}
