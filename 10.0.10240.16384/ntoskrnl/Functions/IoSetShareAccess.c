// IoSetShareAccess 
 
int __fastcall IoSetShareAccess(int a1, char a2, int a3, _DWORD *a4)
{
  return IoSetShareAccessEx(a1, a2, a3, a4, 0);
}
