// MiQueryPfnUnsafe 
 
int __fastcall MiQueryPfnUnsafe(int a1, _DWORD *a2, int a3, int a4)
{
  int v8; // r4
  int v9; // r0
  unsigned __int8 *v10; // r1
  unsigned int v11; // r2
  int v12; // r2
  int v13; // r1
  int v14; // r5
  unsigned int *v15; // r2
  unsigned int v16; // r4
  int v17; // r3
  int varg_r0; // [sp+18h] [bp+8h]
  _DWORD *varg_r1; // [sp+1Ch] [bp+Ch]
  int varg_r3; // [sp+24h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  if ( !MI_IS_PFN(a1) )
    return sub_51CC58();
  v8 = MmPfnDatabase + 24 * a1;
  if ( a2 != (_DWORD *)(*(_DWORD *)(v8 + 4) | 0x80000000) )
    return sub_51CC58();
  v9 = KfRaiseIrql(2);
  v10 = (unsigned __int8 *)(v8 + 15);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 | 0x80, v10) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v11 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v17 = *(_DWORD *)(v8 + 12);
      __dmb(0xBu);
    }
    while ( (v17 & 0x80000000) != 0 );
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | 0x80, v10) );
  }
  if ( (*(_BYTE *)(v8 + 19) & 0x40) == 0 )
    goto LABEL_8;
  if ( *a2 == a3 )
  {
    *(_DWORD *)(a4 + 4) |= 0x80000000;
LABEL_8:
    if ( (*(_BYTE *)(v8 + 19) & 8) != 0 )
      v12 = 5;
    else
      v12 = *(_BYTE *)(v8 + 19) & 7;
    v13 = (*(_DWORD *)(a4 + 4) ^ (v12 << 24)) & 0x7000000 ^ *(_DWORD *)(a4 + 4);
    *(_DWORD *)(a4 + 4) = v13;
    v14 = 1;
    *(_DWORD *)(a4 + 4) = v13 & 0xF77FFFFF | (((*(_BYTE *)(v8 + 18) & 7) == 3) << 27) | 0x400000;
    goto LABEL_11;
  }
  v14 = 0;
LABEL_11:
  __dmb(0xBu);
  v15 = (unsigned int *)(v8 + 12);
  do
    v16 = __ldrex(v15);
  while ( __strex(v16 & 0x7FFFFFFF, v15) );
  KfLowerIrql(v9);
  return v14;
}
