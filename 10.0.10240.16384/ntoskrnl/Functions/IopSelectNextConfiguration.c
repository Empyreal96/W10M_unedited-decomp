// IopSelectNextConfiguration 
 
int __fastcall IopSelectNextConfiguration(int a1, unsigned int a2, _DWORD *a3)
{
  unsigned int v4; // r6
  int v6; // r7
  int v7; // r8
  int v8; // r9
  int v9; // r3
  __int64 v10; // r0
  unsigned int v11; // r4
  unsigned int v12; // r3
  unsigned int i; // r6
  int v15; // r4
  int v16; // r3
  __int64 v17; // r0

  v4 = 0;
  v6 = a1;
  if ( a2 )
  {
    v7 = a1;
    do
    {
      v8 = *(_DWORD *)(v7 + 24);
      v9 = **(_DWORD **)(v8 + 12);
      HIDWORD(v10) = *(_DWORD *)(v9 + 16);
      LODWORD(v10) = v9 + 20;
      IopAddRemoveReqDescs(v10, 0, 0);
      v11 = *(_DWORD *)(v8 + 12) + 4;
      v12 = *(_DWORD *)(v8 + 16);
      *(_DWORD *)(v8 + 12) = v11;
      if ( v11 < v12 )
        break;
      ++v4;
      *(_DWORD *)(v8 + 12) = v8 + 24;
      v7 += 40;
    }
    while ( v4 < a2 );
  }
  if ( v4 == a2 )
    return 0;
  for ( i = 0; i < a2; v6 += 40 )
  {
    v15 = *(_DWORD *)(v6 + 24);
    v16 = **(_DWORD **)(v15 + 12);
    HIDWORD(v17) = *(_DWORD *)(v16 + 16);
    LODWORD(v17) = v16 + 20;
    IopAddRemoveReqDescs(v17, a3, 1);
    if ( *(_DWORD *)(v15 + 12) != v15 + 24 )
      break;
    ++i;
  }
  return 1;
}
