// AlpcpExposeAttributes 
 
int __fastcall AlpcpExposeAttributes(int a1, int a2, int a3, int *a4)
{
  int v5; // r5
  unsigned int v7; // r3
  int v9; // r2
  int v10; // r2
  int v11; // r2
  int v12; // [sp+0h] [bp-20h]

  v5 = *a4;
  v7 = *a4 & 0x80000000;
  v12 = a1;
  a4[1] = 0;
  if ( v7 )
    return sub_7F45F4();
  if ( (v5 & 0x40000000) != 0 )
  {
    AlpcpExposeViewAttribute(a1, a3, a4 + 2, a4 + 1);
    a1 = v12;
  }
  if ( (v5 & 0x20000000) != 0 )
  {
    v9 = 2;
    if ( (v5 & 0x80000000) != 0 )
      v9 = 5;
    if ( (v5 & 0x40000000) != 0 )
      v9 += 4;
    a1 = AlpcpExposeContextAttribute(a1, a3, &a4[v9], a4 + 1);
  }
  if ( (v5 & 0x10000000) != 0 )
  {
    v10 = 2;
    if ( (v5 & 0x80000000) != 0 )
      v10 = 5;
    if ( (v5 & 0x40000000) != 0 )
      v10 += 4;
    if ( (v5 & 0x20000000) != 0 )
      v10 += 5;
    AlpcpExposeHandleAttribute(a1, a3, &a4[v10], a4 + 1);
  }
  if ( (v5 & 0x8000000) != 0 )
  {
    v11 = 2;
    if ( (v5 & 0x80000000) != 0 )
      v11 = 5;
    if ( (v5 & 0x40000000) != 0 )
      v11 += 4;
    if ( (v5 & 0x20000000) != 0 )
      v11 += 5;
    if ( (v5 & 0x10000000) != 0 )
      v11 += 4;
    AlpcpExposeTokenAttribute(v12, a3, &a4[v11], a4 + 1);
  }
  return 0;
}
