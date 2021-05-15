// RtlInsertElementGenericTable 
 
int __fastcall RtlInsertElementGenericTable(int a1, int a2, int a3, int a4)
{
  int v9[6]; // [sp+8h] [bp-18h] BYREF

  v9[0] = a4;
  sub_44CE2C(a1, a2, v9);
  return RtlInsertElementGenericTableFull(a1, a2, a3, a4);
}
