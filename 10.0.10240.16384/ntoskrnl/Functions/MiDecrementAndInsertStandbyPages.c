// MiDecrementAndInsertStandbyPages 
 
int __fastcall MiDecrementAndInsertStandbyPages(_DWORD *a1, int a2, int a3)
{
  int v3; // r4
  _DWORD *v5; // r5
  int *v6; // r7
  int v7; // r8
  int v8; // t1
  int v9; // r3

  v3 = a2;
  v5 = a1;
  if ( a2 )
  {
    v6 = a1;
    v7 = a2;
    do
    {
      v8 = *v6++;
      v9 = *(_DWORD *)(v8 + 12);
      *(_WORD *)(v8 + 16) = 0;
      *(_DWORD *)(v8 + 12) = v9 & 0xC0000000;
      *(_BYTE *)(v8 + 18) = *(_BYTE *)(v8 + 18) & 0xF8 | 2;
      MiMakeProtoTransition(v8);
      --v7;
    }
    while ( v7 );
  }
  return MiInsertAndUnlockStandbyPages(0, v5, v3, a3);
}
