// SeAccessCheckFromStateEx 
 
int __fastcall SeAccessCheckFromStateEx(int a1, int a2, int a3, unsigned int a4, int a5, _DWORD *a6, int a7, char a8, _DWORD *a9, int *a10)
{
  int result; // r0
  int v11[6]; // [sp+20h] [bp-18h] BYREF

  v11[1] = 0;
  v11[2] = a2;
  v11[3] = 0;
  v11[0] = 0;
  if ( a3 )
    result = sub_54B5F0();
  else
    result = SeAccessCheckWithHint(a1, 0, v11, 1, a4, a5, a6, a7, a8, a9, a10);
  return result;
}
