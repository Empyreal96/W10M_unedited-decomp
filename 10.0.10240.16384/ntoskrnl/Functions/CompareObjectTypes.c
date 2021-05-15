// CompareObjectTypes 
 
int __fastcall CompareObjectTypes(int a1, int a2)
{
  return *(_DWORD *)(a1 + 20) - *(_DWORD *)(a2 + 20);
}
