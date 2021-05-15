// ExInterlockedAddLargeInteger 
 
_DWORD *__fastcall ExInterlockedAddLargeInteger(_DWORD *result, _DWORD *a2, int a3, int a4, unsigned int *a5)
{
  int v6; // r4
  unsigned int v7; // r2
  int v8; // r3
  int v9; // r1
  _DWORD *varg_r0; // [sp+18h] [bp+8h]
  _DWORD *varg_r1; // [sp+1Ch] [bp+Ch]

  varg_r0 = result;
  varg_r1 = a2;
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v6 = 0;
  }
  else
  {
    __disable_irq();
    v6 = 1;
  }
  do
    v7 = __ldrex(a5);
  while ( __strex(1u, a5) );
  __dmb(0xBu);
  if ( v7 )
    return (_DWORD *)sub_5237F8();
  *result = *a2;
  v8 = a2[1];
  v9 = *result;
  result[1] = v8;
  *a2 = a3 + v9;
  a2[1] = v8 + __CFADD__(a3, v9) + a4;
  __dmb(0xBu);
  *a5 = 0;
  if ( v6 )
    __enable_irq();
  return result;
}
