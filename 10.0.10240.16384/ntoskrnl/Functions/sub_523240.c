// sub_523240 
 
void __fastcall sub_523240(int a1, int a2, int a3)
{
  _DWORD *v3; // r5
  int v4; // r3
  int v5; // r3
  int v6; // r4
  _DWORD *v7; // r6
  int v8; // r2
  _DWORD *v9; // r0
  _DWORD *i; // r1
  _DWORD *v11; // r2
  __int64 v12; // kr00_8
  _DWORD *v13; // r4
  int v14; // r4
  unsigned int v15; // r3
  unsigned int v16; // r6
  _DWORD *v17; // r4

  if ( !v3[7] )
  {
    v4 = v3[3];
    if ( v4 )
    {
      v5 = v4 - 1;
    }
    else
    {
      v5 = v3[4] >> 1;
      v3[4] = v5;
    }
    v6 = a3 - 1;
    v3[3] = v5;
    v7 = (_DWORD *)RtlpGetChainHead((int)v3, a3 - 1, a3);
    v9 = (_DWORD *)RtlpGetChainHead((int)v3, v3[3], v8);
    v3[2] = v6;
    if ( (_DWORD *)*v7 != v7 && (_DWORD *)*v9 != v9 )
      --v3[6];
    for ( i = v9; ; *i = v11 )
    {
      v11 = (_DWORD *)*v7;
      if ( (_DWORD *)*v7 == v7 )
        break;
      v12 = *(_QWORD *)v11;
      if ( (_DWORD *)v11[1] != v7 || *(_DWORD **)(v12 + 4) != v11 )
        __fastfail(3u);
      *v7 = v12;
      *(_DWORD *)(v12 + 4) = v7;
      if ( (_DWORD *)*i != v9 )
      {
        do
        {
          v13 = (_DWORD *)*i;
          if ( *(_DWORD *)(*i + 8) >= v11[2] )
            break;
          i = (_DWORD *)*i;
        }
        while ( (_DWORD *)*v13 != v9 );
      }
      v14 = *i;
      *v11 = *i;
      v11[1] = i;
      if ( *(_DWORD **)(v14 + 4) != i )
        __fastfail(3u);
      *(_DWORD *)(v14 + 4) = v11;
    }
    v15 = v3[2];
    v16 = v15 >> 7;
    if ( (v15 & 0x7F) == 0 )
    {
      v17 = (_DWORD *)v3[8];
      RtlpSecondLevelDirFreeUsingFreeList(v17[v16], i);
      v17[v16] = 0;
      if ( v3[2] == 128 )
      {
        v3[8] = *v17;
        ExFreePoolWithTag(v17, 0);
      }
    }
    JUMPOUT(0x459334);
  }
  JUMPOUT(0x459332);
}
