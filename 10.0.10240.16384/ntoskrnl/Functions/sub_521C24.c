// sub_521C24 
 
void __fastcall sub_521C24(int a1, int a2, int a3)
{
  int *v3; // r6
  int v4; // r8
  int v5; // r1
  __int16 v6; // r7
  int *v7; // r2
  int v8; // r1
  int v9; // t1

  v5 = *(_DWORD *)(a1 + 20);
  v6 = *(_WORD *)(a1 + 4) - 4;
  *(_WORD *)(a1 + 4) = v6;
  if ( (v5 & 0xFFF) != 0 )
    *(_DWORD *)(a1 + 20) = v5 & 0xFFFFF000;
  else
    *(_DWORD *)(a1 + 20) = v5 - 4096;
  v7 = (int *)(a3 - 4);
  v8 = 0;
  if ( v7 != v3 )
  {
    do
    {
      v9 = *v7--;
      if ( v9 != *(_DWORD *)(v4 + 7804) )
        break;
      ++v8;
    }
    while ( v7 != v3 );
    if ( v8 )
    {
      *(_WORD *)(a1 + 4) = v6 - 4 * v8;
      *(_DWORD *)(a1 + 20) -= v8 << 12;
    }
  }
  JUMPOUT(0x4561B8);
}
