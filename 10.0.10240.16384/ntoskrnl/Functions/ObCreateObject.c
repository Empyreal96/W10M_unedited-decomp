// ObCreateObject 
 
int __fastcall ObCreateObject(char a1, _DWORD *a2, int a3, char a4, int a5, int a6, int a7, int a8, _DWORD *a9)
{
  int v10; // [sp+0h] [bp-20h]

  return ObCreateObjectEx(a1, a2, a3, a4, v10, a6, a7, a8, a9, 0);
}
