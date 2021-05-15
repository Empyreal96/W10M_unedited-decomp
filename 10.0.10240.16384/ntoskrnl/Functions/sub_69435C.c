// sub_69435C 
 
void __fastcall sub_69435C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, char a8, char a9)
{
  unsigned int v9; // r5
  int v10; // r6
  int v11; // r9
  unsigned int v12; // r0
  unsigned int v13; // r1
  unsigned int i; // r2
  unsigned int v15; // r3
  unsigned int j; // r1
  unsigned __int8 v17[72]; // [sp+10h] [bp-48h] BYREF

  *(&a9 + v10) = a8;
  if ( v10 + 1 >= v9 )
  {
    v12 = v17[0];
    v13 = 1;
    for ( i = v17[0]; v13 < v9; i = (unsigned __int8)i )
    {
      v15 = v17[v13];
      if ( v12 >= v15 )
        LOBYTE(v12) = v17[v13];
      v12 = (unsigned __int8)v12;
      if ( i <= v15 )
        LOBYTE(i) = v17[v13];
      ++v13;
    }
    if ( v12 != i )
    {
      for ( j = 0; j < v9; ++j )
      {
        if ( v17[j] == v12 )
          *(_DWORD *)(v11 + 8) |= 1 << j;
      }
      JUMPOUT(0x693250);
    }
    JUMPOUT(0x69324E);
  }
  JUMPOUT(0x69320C);
}
