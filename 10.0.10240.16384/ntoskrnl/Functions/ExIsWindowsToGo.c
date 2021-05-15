// ExIsWindowsToGo 
 
int __fastcall ExIsWindowsToGo(_DWORD *a1, int a2, int a3, int a4)
{
  int result; // r0
  int v6; // [sp+0h] [bp-8h] BYREF

  v6 = a4;
  result = sub_7A2B64(&v6);
  if ( result >= 0 )
    *a1 = v6 == 1;
  return result;
}
