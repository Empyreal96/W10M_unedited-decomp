// VfZwDeleteBootEntry 
 
int __fastcall VfZwDeleteBootEntry(int a1, int a2)
{
  ViZwShouldCheck(a1, a2);
  return pXdvZwDeleteBootEntry(a1);
}
