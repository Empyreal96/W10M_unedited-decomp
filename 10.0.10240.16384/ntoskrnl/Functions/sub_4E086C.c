// sub_4E086C 
 
int __fastcall sub_4E086C(int a1, int a2, unsigned int a3, _DWORD *a4, int a5)
{
  int i; // r3
  unsigned int v10; // r6
  _DWORD *v11; // r9
  signed int v12; // r0

  for ( i = a1; a3; i = a1 )
  {
    v10 = a3 >> 1;
    v11 = &a4[a3 >> 1];
    v12 = strcmp(i, (unsigned int *)(*v11 + a2));
    if ( !v12 )
      return *(unsigned __int16 *)(a5 + 2 * v10);
    if ( a3 == 1 )
      break;
    if ( v12 >= 0 )
    {
      a5 += 2 * (v10 + 1);
      a3 = a3 - v10 - 1;
      a4 = v11 + 1;
    }
    else
    {
      a3 >>= 1;
    }
  }
  return 0xFFFF;
}
