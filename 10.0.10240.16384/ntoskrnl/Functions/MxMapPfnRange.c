// MxMapPfnRange 
 
int __fastcall MxMapPfnRange(unsigned int a1, unsigned int a2)
{
  int v3; // r1
  unsigned int v4; // r6
  unsigned int v5; // r5
  int v6; // r10
  int v7; // r5
  int v8; // r3
  int v9; // r9
  int v10; // r0
  unsigned int v11; // r3
  unsigned int v12; // r5
  unsigned int v13; // r9
  int v15; // [sp+4h] [bp-24h]

  v3 = MmPfnDatabase;
  v4 = a1;
  v5 = MmPfnDatabase + 24 * a1;
  if ( v5 == (v5 & 0xFFC00000) )
    v6 = 0;
  else
    v6 = ((v5 >> 20) & 0xFFC) - 1070596096;
  if ( a2 != -1 )
    goto LABEL_12;
  while ( 1 )
  {
    v7 = a2;
    if ( a2 == -1 )
    {
      a2 = 0;
      v8 = v3 + (MxPfnAllocation << 12);
    }
    else
    {
      v7 = MiRestrictRangeToNode(v4, a2);
      a2 -= v7;
      v8 = MmPfnDatabase + 24 * (v7 + v4);
    }
    v9 = v8 - 1;
    v10 = MiPageToNode();
    v3 = MmPfnDatabase;
    v15 = v10;
    v11 = ((MmPfnDatabase + 24 * v4) >> 20) & 0xFFC;
    v4 += v7;
    v12 = v11 - 1070596096;
    v13 = (((((v9 + 0x3FFFFF) & 0xFFC00000) - 1) >> 20) & 0xFFC) - 1070596096;
    if ( v11 - 1070596096 <= v13 )
      break;
LABEL_12:
    if ( !a2 )
      return 1;
  }
  while ( 1 )
  {
    if ( v12 != v6 )
      return sub_96B608();
    if ( !MxMapVa(v12 << 20, v15, 1) )
      return 0;
    v12 += 4;
    if ( v12 > v13 )
    {
      v3 = MmPfnDatabase;
      goto LABEL_12;
    }
  }
}
