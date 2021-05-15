// iswdigit 
 
int __fastcall iswdigit(int a1)
{
  return iswctype(a1, 4);
}
