// RtlQueryInformationAcl 
 
int __fastcall RtlQueryInformationAcl(unsigned __int8 *a1, unsigned int *a2, unsigned int a3, int a4)
{
  unsigned int v6; // r1
  int v7; // r2
  int v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v6 = *a1;
  if ( v6 < 2 || v6 > 4 )
    return -1073741811;
  if ( a4 != 2 )
  {
    if ( a4 != 1 )
      return -1073741821;
    if ( a3 >= 4 )
    {
      *a2 = v6;
      return 0;
    }
    return -1073741789;
  }
  if ( a3 < 0xC )
    return -1073741789;
  if ( !RtlFirstFreeAce(a1, v9) )
    return -1073741811;
  *a2 = *((unsigned __int16 *)a1 + 2);
  if ( !v9[0] )
    return sub_7C5298();
  v7 = v9[0] - (_DWORD)a1;
  a2[1] = v9[0] - (_DWORD)a1;
  a2[2] = *((unsigned __int16 *)a1 + 1) - v7;
  return 0;
}
