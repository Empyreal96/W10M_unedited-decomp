// vsprintf 
 
int __fastcall vsprintf(_BYTE *a1, int a2, int a3)
{
  return vsprintf_l(a1, a2, 0, a3);
}
