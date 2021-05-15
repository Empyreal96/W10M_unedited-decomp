// MiUpdateLargePageSectionPfn 
 
int __fastcall MiUpdateLargePageSectionPfn(_DWORD *a1, int a2, int a3, int a4)
{
  int v6; // r7
  unsigned __int8 *v7; // r5
  unsigned int v8; // r2
  int v9; // r3
  int v10; // r2
  unsigned int *v11; // r2
  unsigned int v12; // r0
  _DWORD *varg_r0; // [sp+18h] [bp+8h]
  int varg_r1; // [sp+1Ch] [bp+Ch]

  varg_r0 = a1;
  varg_r1 = a2;
  v6 = KfRaiseIrql(2);
  v7 = (unsigned __int8 *)a1 + 15;
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 | 0x80, v7) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v8 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v9 = a1[3];
      __dmb(0xBu);
    }
    while ( v9 < 0 );
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | 0x80, v7) );
  }
  v10 = a1[5];
  a1[1] = a2;
  a1[2] = a3;
  a1[5] = v10 | 0x80FFFFF;
  a1[3] &= 0xBFFFFFFF;
  __dmb(0xBu);
  v11 = a1 + 3;
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 & 0x7FFFFFFF, v11) );
  return KfLowerIrql(v6);
}
