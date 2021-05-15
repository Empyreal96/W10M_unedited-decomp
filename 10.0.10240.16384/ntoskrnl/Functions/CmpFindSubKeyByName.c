// CmpFindSubKeyByName 
 
int __fastcall CmpFindSubKeyByName(int a1, int a2, int a3, int a4)
{
  int v5[2]; // [sp+0h] [bp-8h] BYREF

  v5[0] = a3;
  v5[1] = a4;
  CmpFindSubKeyByNameWithStatus(a1, a2, a3, v5);
  return v5[0];
}
