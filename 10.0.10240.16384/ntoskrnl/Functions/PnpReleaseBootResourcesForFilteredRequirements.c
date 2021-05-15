// PnpReleaseBootResourcesForFilteredRequirements 
 
int __fastcall PnpReleaseBootResourcesForFilteredRequirements(int *a1)
{
  int v2; // r5
  _BYTE *v3; // r0
  int v4; // r4
  int v5; // r6
  int v6; // r1
  int v7; // r4
  int v8; // r0
  int v10; // r10
  unsigned int v11; // r9
  int v12; // r2
  int v13; // r8
  int v14; // r6
  unsigned int v15; // r0
  unsigned int v16; // r1
  int v17; // r7
  int v18; // r3
  int **v19; // r1
  int v20; // r0
  int v21; // r1
  int v22; // [sp+8h] [bp-88h]
  int v23[10]; // [sp+10h] [bp-80h] BYREF
  int *v24; // [sp+38h] [bp-58h] BYREF
  int **v25; // [sp+3Ch] [bp-54h]
  int v26; // [sp+40h] [bp-50h]
  int v27; // [sp+44h] [bp-4Ch]
  int v28; // [sp+48h] [bp-48h]
  int v29; // [sp+4Ch] [bp-44h]
  int v30; // [sp+50h] [bp-40h]
  int v31; // [sp+54h] [bp-3Ch]
  int v32; // [sp+64h] [bp-2Ch]

  v2 = 0;
  v3 = memset(v23, 0, sizeof(v23));
  v4 = *a1;
  if ( *a1 )
    v5 = *(_DWORD *)(*(_DWORD *)(v4 + 176) + 20);
  else
    v5 = 0;
  v6 = *(_DWORD *)(v5 + 360);
  if ( !v6 || (v2 = PnpCmResourcesToIoResources(v3, v6, 1)) == 0 )
  {
    v7 = -1073741823;
LABEL_6:
    v8 = v23[6];
    goto LABEL_7;
  }
  v23[2] = 4;
  v23[5] = v2;
  v23[0] = v4;
  v7 = IopResourceRequirementsListToReqList(v23, &v23[6]);
  if ( v7 < 0 )
    goto LABEL_6;
  v8 = v23[6];
  if ( !v23[6] )
    goto LABEL_9;
  v10 = *(_DWORD *)(v23[6] + 24);
  v7 = 0;
  v11 = 0;
  v12 = **(_DWORD **)(a1[6] + 12);
  v26 = 0;
  v27 = 0;
  v22 = v12;
  v28 = *(_DWORD *)(v5 + 16);
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 4;
  if ( *(_DWORD *)(v10 + 16) )
  {
    v13 = v10;
    while ( 1 )
    {
      v14 = *(_DWORD *)(*(_DWORD *)(v13 + 20) + 176);
      if ( v14 )
      {
        v15 = *(_DWORD *)(v12 + 16);
        v16 = 0;
        if ( v15 )
        {
          v17 = v12;
          do
          {
            v18 = *(_DWORD *)(*(_DWORD *)(v17 + 20) + 176);
            if ( v18 && *(unsigned __int8 *)(v14 + 8) == *(unsigned __int8 *)(v18 + 8) )
              break;
            ++v16;
            v17 += 4;
          }
          while ( v16 < v15 );
        }
        if ( v16 == v15 )
        {
          v25 = &v24;
          v24 = (int *)&v24;
          v19 = *(int ***)(v14 + 24);
          v24 = (int *)(v14 + 20);
          v25 = v19;
          if ( *v19 != (int *)(v14 + 20) )
            __fastfail(3u);
          *v19 = (int *)&v24;
          *(_DWORD *)(v14 + 24) = &v24;
          v7 = IopCallArbiter(v14, 0);
          v20 = (int)v24;
          v21 = (int)v25;
          if ( (int **)v24[1] != &v24 || *v25 != (int *)&v24 )
            __fastfail(3u);
          *v25 = v24;
          *(_DWORD *)(v20 + 4) = v21;
          if ( v7 < 0 )
            break;
          v7 = IopCallArbiter(v14, 2);
          if ( v7 < 0 )
            break;
        }
      }
      ++v11;
      v13 += 4;
      if ( v11 >= *(_DWORD *)(v10 + 16) )
        break;
      v12 = v22;
    }
    goto LABEL_6;
  }
LABEL_7:
  if ( v8 )
    IopFreeReqList();
LABEL_9:
  if ( v2 )
    ExFreePoolWithTag(v2);
  return v7;
}
