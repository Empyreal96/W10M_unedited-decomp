// MxComputeFreeNodeDescriptorRequirements 
 
int __fastcall MxComputeFreeNodeDescriptorRequirements(int a1, _BYTE *a2)
{
  int *v4; // r5
  int v5; // r2
  int v6; // r1
  int v7; // r8
  int v8; // r3
  __int64 v9; // r6
  int v10; // r5
  int v11; // r9
  int v12; // r0
  int result; // r0
  int v14; // [sp+0h] [bp-30h]
  int v15; // [sp+4h] [bp-2Ch]
  int *v16; // [sp+8h] [bp-28h]

  memset(a2, 0, 64);
  v4 = *(int **)(a1 + 24);
  v5 = -1;
  v6 = -1;
  v15 = -1;
  v16 = v4;
  v14 = -1;
  v7 = -1;
  if ( v4 != (int *)(a1 + 24) )
  {
    do
    {
      v8 = v4[2];
      if ( v8 != 6 && v8 != 32 && v8 != 31 && v8 != 30 && v8 != 23 && v8 != 3 && v8 != 22 )
      {
        v9 = *(_QWORD *)(v4 + 3);
        if ( HIDWORD(v9) )
        {
          v10 = v15;
          do
          {
            v11 = MiRestrictRangeToNode(v9, HIDWORD(v9));
            v12 = MiPageToNode();
            if ( v10 == -1 )
            {
              v5 = v9;
              v14 = v9;
            }
            else
            {
              if ( v12 != v7
                || (((unsigned int)(24 * v10) >> 20) & 0xFFC) - 1070596092 < (((unsigned int)(24 * v9) >> 20) & 0xFFC)
                                                                           - 1070596096 )
              {
                return sub_96B6F8();
              }
              v5 = v14;
            }
            HIDWORD(v9) -= v11;
            v10 = v11 + v9;
            v7 = v12;
            LODWORD(v9) = v9 + v11;
          }
          while ( HIDWORD(v9) );
          v15 = v10;
          v4 = v16;
        }
      }
      v4 = (int *)*v4;
      v16 = v4;
    }
    while ( v4 != (int *)(a1 + 24) );
    v6 = v15;
  }
  result = MxComputePfnPagesNeeded(v5, v6);
  *(_DWORD *)&a2[4 * v7] += result;
  return result;
}
