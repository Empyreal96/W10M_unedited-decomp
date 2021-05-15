// sub_819D3C 
 
void sub_819D3C()
{
  int v0; // r4
  int v1; // r7
  int v2; // r8
  _DWORD *v3; // r0
  _DWORD *v4; // r2
  int v5; // r3

  if ( (*(_DWORD *)(v0 + 8) & v2) == 0 )
  {
    v3 = (_DWORD *)ExAllocatePoolWithTag(1, 28, 1885957463);
    if ( v3 )
    {
      v3[2] = v0;
      v3[3] = v3 + 3;
      v3[4] = v3 + 3;
      v3[5] = v3 + 5;
      v3[6] = v3 + 5;
      v4 = *(_DWORD **)(v1 + 4);
      *v3 = v1;
      v3[1] = v4;
      if ( *v4 != v1 )
        __fastfail(3u);
      *v4 = v3;
      *(_DWORD *)(v1 + 4) = v3;
      v5 = *(_DWORD *)(v0 + 8);
      *(_DWORD *)(v0 + 96) = v3;
      *(_DWORD *)(v0 + 8) = v5 | v2;
    }
  }
  JUMPOUT(0x7B6542);
}
