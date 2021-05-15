// RtlCopySid 
 
int __fastcall RtlCopySid(unsigned int a1, int a2, int a3)
{
  unsigned int v4; // r2

  v4 = 4 * (*(unsigned __int8 *)(a3 + 1) + 2);
  if ( v4 > a1 )
    return -1073741789;
  memmove(a2, a3, v4);
  return 0;
}
