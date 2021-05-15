// sub_6E3298 
 
int __fastcall sub_6E3298(int a1, _DWORD *a2, int a3, unsigned int a4, _DWORD *a5)
{
  unsigned int v8; // r0
  unsigned __int16 *v10; // r1
  unsigned int v11; // r2

  v8 = bsearch(a1, (unsigned int)&byte_922C48, dword_922C3C, 8, (int (*)(void))sub_6C7BFC);
  if ( !v8 )
    return -1073741772;
  v10 = *(unsigned __int16 **)(v8 + 4);
  *a5 = v10[3];
  if ( a2 )
    *a2 = v10[2];
  v11 = v10[3];
  if ( v11 > a4 )
    return -1073741789;
  if ( a3 )
    memmove(a3, (int)v10 + v10[1] + 16, v11);
  return 0;
}
