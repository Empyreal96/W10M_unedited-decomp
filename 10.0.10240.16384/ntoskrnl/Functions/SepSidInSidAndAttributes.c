// SepSidInSidAndAttributes 
 
int __fastcall SepSidInSidAndAttributes(unsigned __int8 **a1, unsigned int a2, int a3, unsigned __int8 *a4)
{
  unsigned __int8 **v4; // r6
  int v8; // r4
  int v9; // r9
  int v10; // r8
  unsigned int v11; // r1
  unsigned __int8 *v12; // t1

  v4 = a1;
  if ( !a1 )
    return 0;
  v8 = 0;
  v9 = 4 * (a4[1] + 2);
  if ( !a2 )
    return 0;
  v10 = *a4;
  while ( 1 )
  {
    v12 = *v4;
    v4 += 2;
    v11 = (unsigned int)v12;
    if ( v10 == *v12 && v9 == 4 * (*(unsigned __int8 *)(v11 + 1) + 2) && !memcmp((unsigned int)a4, v11, v9) )
      break;
    if ( ++v8 >= a2 )
      return 0;
  }
  return 1;
}
