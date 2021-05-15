// CmpFileRead 
 
int __fastcall CmpFileRead(int a1, int a2, int *a3, int a4, unsigned int a5)
{
  int result; // r0

  if ( a2 || (*(_BYTE *)(a1 + 72) & 4) == 0 )
    result = CmpFileReadEx(a1, a2, a3, a4, a5) >= 0;
  else
    result = sub_7F3D8C();
  return result;
}
