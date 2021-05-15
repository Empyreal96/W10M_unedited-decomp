// _ObReferenceObjectByHandle 
 
int __fastcall ObReferenceObjectByHandle(int a1, int a2, int a3, int a4, _DWORD *a5, int a6)
{
  int result; // r0
  int v7; // [sp+8h] [bp-8h] BYREF

  v7 = a4;
  result = ObReferenceObjectByHandle(a1, a2, a3, (char)a4, &v7, a6);
  *a5 = v7;
  return result;
}
