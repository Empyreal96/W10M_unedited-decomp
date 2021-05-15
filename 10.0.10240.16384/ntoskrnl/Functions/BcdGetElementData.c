// BcdGetElementData 
 
int __fastcall BcdGetElementData(int a1, unsigned int a2, int a3, _DWORD *a4)
{
  return BcdGetElementDataWithFlags(a1, a2, a3, a3, a4);
}
