// _vswprintf 
 
int __fastcall vswprintf(int a1, int a2, int a3)
{
  return vswprintf_l(a1, a2, 0, a3);
}
