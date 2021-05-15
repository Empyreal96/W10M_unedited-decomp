// IopMergeRelationLists 
 
int __fastcall IopMergeRelationLists(int **a1, int a2, int a3, int a4)
{
  _DWORD *v6; // r4
  int v7; // r2
  int v8; // r6
  unsigned int v9; // r10
  int v10; // r9
  int *v11; // r8
  int v12; // r0
  BOOL v13; // r4
  int v14; // r3
  int v15; // r0
  int v18; // [sp+4h] [bp-24h]
  int v19[8]; // [sp+8h] [bp-20h] BYREF

  v19[0] = a4;
  v6 = *(_DWORD **)a2;
  v7 = **a1;
  v8 = 0;
  v18 = v7;
  v9 = 0;
  if ( **(_DWORD **)a2 )
  {
    v10 = 0;
    while ( 1 )
    {
      v14 = ((v11 = &v6[v10], v12 = PipDeviceObjectListIndexOf((int)*a1, v6[v10 + 4], v7, v19), v13 = v12 >= 0, v12 < 0)
          || a3)
         && (v11[7] & 1) != 0;
      v15 = IopAddRelationToList((int)a1, v11[4], v11[5], v14);
      if ( v13 && v15 == -1073741771 )
        v15 = 0;
      if ( v15 < 0 )
        break;
      v6 = *(_DWORD **)a2;
      ++v9;
      v7 = v18;
      v10 += 4;
      if ( v9 >= **(_DWORD **)a2 )
        goto LABEL_13;
    }
    v8 = v15;
  }
  else
  {
LABEL_13:
    if ( !**a1 )
      *((_BYTE *)a1 + 4) = *(_BYTE *)(a2 + 4);
  }
  return v8;
}
