// sub_551B98 
 
void __fastcall sub_551B98(int a1, int a2)
{
  unsigned int v2; // r4
  unsigned int v3; // r6
  int v4; // r7
  int v5; // r8
  int v6; // lr
  int v7; // r5
  int v8; // r2

  v7 = 0;
  do
  {
    if ( *(_DWORD *)(a2 + 8) == -1 )
    {
      v8 = *(_DWORD *)(v6 + (*(_DWORD *)(*(_DWORD *)(v4 + 232) + v7 + 4) << 8) + 172);
      if ( (v8 & v5) == v8 )
        break;
    }
    ++v2;
    a2 += 4;
    v7 += 16;
  }
  while ( v2 < v3 );
  JUMPOUT(0x4EFBF6);
}
