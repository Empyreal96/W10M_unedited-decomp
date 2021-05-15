// CmpFindValueByName 
 
int __fastcall CmpFindValueByName(int a1, int a2, int a3, int a4)
{
  int v5[2]; // [sp+8h] [bp-8h] BYREF

  v5[0] = a3;
  v5[1] = a4;
  CmpFindNameInList(a1, a2 + 36, a3, 0, 0, v5);
  return v5[0];
}
