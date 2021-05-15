// PnpReleaseResourcesInternal 
 
int __fastcall PnpReleaseResourcesInternal(_DWORD *a1)
{
  unsigned int *v2; // r5
  unsigned int v4; // r9
  int *v5; // r8
  unsigned int v6; // lr
  int v7; // r6
  int v8; // r3
  int v9; // r1
  int v10; // r10
  int v11; // r4
  int v12; // r2
  _DWORD *v13; // r6
  int v14; // r0
  int v15; // r1
  int v16; // r0
  int v17; // r1
  int *j; // r2
  int v19; // r0
  int i; // [sp+8h] [bp-68h]
  int v21; // [sp+Ch] [bp-64h]
  int v22; // [sp+10h] [bp-60h]
  unsigned int v23; // [sp+14h] [bp-5Ch]
  int *v24; // [sp+18h] [bp-58h] BYREF
  int **v25; // [sp+1Ch] [bp-54h]
  int v26; // [sp+20h] [bp-50h]
  int v27; // [sp+24h] [bp-4Ch]
  int v28; // [sp+28h] [bp-48h]
  int v29; // [sp+2Ch] [bp-44h]
  int v30; // [sp+30h] [bp-40h]
  int v31; // [sp+34h] [bp-3Ch]
  int v32; // [sp+44h] [bp-2Ch]

  v25 = &v24;
  v24 = (int *)&v24;
  v26 = 0;
  v27 = 0;
  v2 = (unsigned int *)a1[71];
  v28 = a1[4];
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 4;
  if ( !v2 )
  {
    v2 = (unsigned int *)a1[90];
    if ( !v2 )
      return sub_80D3C8();
  }
  v4 = *v2;
  if ( !*v2 )
    return sub_80D3C8();
  v5 = (int *)(v2 + 1);
  v6 = 0;
  v23 = 0;
  if ( v4 )
  {
    v7 = PnpDefaultInterfaceType;
    v8 = IopRootDeviceNode;
    for ( i = IopRootDeviceNode; ; v8 = i )
    {
      v9 = v5[1];
      v10 = *v5;
      v22 = v9;
      if ( *v5 == -1 )
        v10 = v7;
      if ( a1 == (_DWORD *)v8 )
        v11 = (int)a1;
      else
        v11 = a1[2];
      v12 = 1;
      v21 = 1;
      if ( v11 )
      {
        do
        {
          if ( v11 == v8 && v12 )
          {
            v16 = IopFindLegacyBusDeviceNode(v10, v9);
            v11 = v16;
            if ( v16 == i && !v10 )
              v11 = IopFindLegacyBusDeviceNode(1, 0);
            v21 = 0;
          }
          v13 = *(_DWORD **)(v11 + 328);
          if ( v13 == (_DWORD *)(v11 + 328) )
          {
            v8 = i;
          }
          else
          {
            do
            {
              if ( v13[3] )
              {
                v13[5] = v13 + 5;
                v13[6] = v13 + 5;
                v24 = v13 + 5;
                v25 = (int **)(v13 + 5);
                v21 = 0;
                if ( (_DWORD *)v13[5] != v13 + 5 )
                  __fastfail(3u);
                v13[5] = &v24;
                v13[6] = &v24;
                IopCallArbiter(v13, 0);
                IopCallArbiter(v13, 2);
                v14 = (int)v24;
                v15 = (int)v25;
                if ( (int **)v24[1] != &v24 || *v25 != (int *)&v24 )
                  __fastfail(3u);
                *v25 = v24;
                *(_DWORD *)(v14 + 4) = v15;
                v25 = &v24;
                v24 = (int *)&v24;
              }
              v13 = (_DWORD *)*v13;
            }
            while ( v13 != (_DWORD *)(v11 + 328) );
            v8 = IopRootDeviceNode;
            i = IopRootDeviceNode;
          }
          v11 = *(_DWORD *)(v11 + 8);
          v12 = v21;
          v9 = v22;
        }
        while ( v11 );
        v6 = v23;
        v7 = PnpDefaultInterfaceType;
      }
      if ( v4 > 1 )
      {
        v17 = v5[3];
        for ( j = v5 + 4; v17; --v17 )
        {
          v19 = 0;
          if ( *(_BYTE *)j == 5 )
            v19 = j[1];
          j = (int *)((char *)j + v19 + 16);
        }
        v5 = j;
      }
      v23 = ++v6;
      if ( v6 >= v4 )
        break;
    }
  }
  return IopWriteAllocatedResourcesToRegistry(a1, 0, 0);
}
