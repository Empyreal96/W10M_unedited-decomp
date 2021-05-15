// sub_8A115C 
 
int __fastcall sub_8A115C(_DWORD *a1, _DWORD *a2, unsigned int a3, _DWORD *a4, _BYTE *a5)
{
  int result; // r0

  *a5 = 1;
  result = 0;
  *a4 = 16;
  if ( a3 < 0x10 )
    return -1073741789;
  if ( a1 )
    *a1 = 3;
  if ( a2 )
  {
    *a2 = dword_922C28;
    a2[1] = dword_922C2C;
    a2[2] = dword_922C30;
    a2[3] = dword_922C34;
  }
  return result;
}
