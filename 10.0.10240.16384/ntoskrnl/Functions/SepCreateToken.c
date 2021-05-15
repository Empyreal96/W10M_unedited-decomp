// SepCreateToken 
 
int __fastcall SepCreateToken(int *a1, int a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8, unsigned __int16 **a9, unsigned int a10, int a11, unsigned int a12, unsigned int a13, int a14, unsigned __int16 *a15, unsigned __int16 *a16, int a17)
{
  return SepCreateTokenEx(
           a1,
           0,
           0,
           a4,
           1,
           0,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           "*SYSTEM*",
           0,
           0,
           0,
           0,
           0,
           1);
}
