// RtlStringCbLengthW 
 
int __fastcall RtlStringCbLengthW(int a1, unsigned int a2, _DWORD *a3)
{
  unsigned int v4; // r1
  int result; // r0

  v4 = a2 >> 1;
  if ( a1 && v4 <= 0x7FFFFFFF )
    result = sub_43E3D8();
  else
    result = -1073741811;
  if ( a3 )
    *a3 = 0;
  return result;
}
