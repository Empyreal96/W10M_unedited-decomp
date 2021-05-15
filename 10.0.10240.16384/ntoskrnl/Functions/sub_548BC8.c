// sub_548BC8 
 
void __fastcall sub_548BC8(int a1)
{
  int v1; // r6
  unsigned int v2; // r7
  int v3; // r9
  char v4; // lr
  int v5; // r9
  unsigned int v6; // r3
  int v7; // r0
  unsigned int v8; // r4
  int v9; // r2
  int v10; // r1
  int v11; // r3

  if ( (v4 & 0x12) == 0 && *(_DWORD *)(v3 + 28) < v2 )
  {
    v5 = *(_DWORD *)(a1 + 3600);
    v6 = *(_DWORD *)(a1 + 3596);
    __dmb(0xBu);
    if ( v6 > 1 )
    {
      v7 = a1 + 4;
      v8 = v6 - 1;
      do
      {
        v9 = *(unsigned __int16 *)(v5 + 96);
        v10 = *(_DWORD *)(v7 + 3600);
        if ( (v9 & v1) != 0 && (*(_WORD *)(v10 + 96) & (unsigned __int16)v1) == 0
          || (v9 & 0x20) != 0 && (*(_WORD *)(v10 + 96) & 0x20) == 0
          || *(_DWORD *)(v10 + 28) > *(_DWORD *)(v5 + 28)
          && (v11 = *(unsigned __int16 *)(v10 + 96), (v11 & v1) == 0)
          && (v11 & 0x20) == 0 )
        {
          v5 = *(_DWORD *)(v7 + 3600);
        }
        v7 += 4;
        --v8;
      }
      while ( v8 );
    }
  }
  JUMPOUT(0x4C9202);
}
