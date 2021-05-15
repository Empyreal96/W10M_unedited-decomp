// CmpDoReDoDeleteKey 
 
int __fastcall CmpDoReDoDeleteKey(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v6; // [sp+0h] [bp-8h] BYREF

  v6 = a4;
  v4 = CmpDoReOpenTransKey(a1, a2 + 32, 0x10000, &v6);
  if ( v4 >= 0 )
  {
    v4 = ZwDeleteKey();
    ZwClose();
  }
  return v4;
}
