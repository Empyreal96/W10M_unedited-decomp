// ExpDeleteTimer2 
 
int __fastcall ExpDeleteTimer2(int a1)
{
  return KeDisableTimer2(a1, 1, 1, 0);
}
