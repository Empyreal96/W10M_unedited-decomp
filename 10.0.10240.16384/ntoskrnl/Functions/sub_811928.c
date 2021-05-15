// sub_811928 
 
void __fastcall sub_811928(int a1, int a2)
{
  _DWORD *v2; // r5
  int v3; // r7
  int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3
  _DWORD *i; // r8
  _DWORD *v9; // r3
  int v10; // [sp+0h] [bp+0h]

  v4 = PiListEntryToDependencyEdge(v3, a2);
  v10 = v4;
  if ( v5 )
  {
    v6 = v2[5];
    v7 = *(_DWORD *)(v4 + 20);
  }
  else
  {
    v6 = v2[4];
    v7 = *(_DWORD *)(v4 + 16);
  }
  if ( v6 == v7 )
  {
    for ( i = (_DWORD *)v2[7]; i != v2 + 7; v4 = v10 )
    {
      v9 = i;
      i = (_DWORD *)*i;
      PipAddRequestToEdge(v4, v9 + 2);
    }
    PipFreeDependencyEdge((int)v2, v4);
    JUMPOUT(0x7A17AE);
  }
  JUMPOUT(0x7A17DA);
}
