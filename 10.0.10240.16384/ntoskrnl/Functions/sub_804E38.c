// sub_804E38 
 
void __fastcall sub_804E38(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r7
  int v5; // r8
  int v6; // r2
  unsigned int v7; // r6
  int *v8; // r5
  int v9; // r3
  int v10; // t1

  v6 = a3 & ~v4;
  v7 = 0;
  if ( *(_DWORD *)(v3 + 52) )
  {
    v8 = (int *)(v6 + 4);
    do
    {
      v10 = *v8++;
      v9 = v10;
      if ( (v10 & v4) != 0 && v9 != v5 )
        ExFreePoolWithTag(v9 & ~v4);
      ++v7;
    }
    while ( v7 < *(_DWORD *)(v3 + 52) );
  }
  ExFreePoolWithTag(*(_DWORD *)(v3 + 56) & ~v4);
  *(_DWORD *)(v3 + 56) = v5;
  JUMPOUT(0x74E5F4);
}
