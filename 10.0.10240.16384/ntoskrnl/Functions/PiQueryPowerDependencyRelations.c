// PiQueryPowerDependencyRelations 
 
int __fastcall PiQueryPowerDependencyRelations(int a1, int a2, int a3, int a4)
{
  _DWORD **v5; // r0
  int v6; // r10
  int *v7; // r7
  int *v8; // r8
  _DWORD **v9; // r6
  int v10; // r9
  _DWORD *v11; // r5
  int v13; // r4
  int *v14; // r2
  int v15; // r0
  int *v16; // r5
  int v17; // r3
  _DWORD *v18; // r4
  int v19; // r3
  int *v20; // r2
  _DWORD *v21; // r2
  _DWORD *v22; // r0
  int v23[8]; // [sp+0h] [bp-20h] BYREF

  v23[0] = a4;
  PnpAcquireDependencyRelationsLock(0, a2);
  v5 = (_DWORD **)PiGetProviderList(*(_DWORD *)(a1 + 16));
  v6 = a1 + 84;
  v7 = *(int **)(a1 + 100);
  v8 = (int *)(a1 + 100);
  v9 = v5;
  v10 = 0;
  while ( v7 != v8 )
  {
    v16 = v7;
    v17 = *((unsigned __int8 *)v7 + 24);
    v7 = (int *)*v7;
    if ( v17 )
    {
      v18 = *v9;
      if ( *v9 == v9 )
        return sub_811850();
      do
      {
        PiEnumerateProviderListEntry(v18, v23, 0);
        if ( v23[0] )
        {
          v19 = *(_DWORD *)(*(_DWORD *)(v23[0] + 176) + 20);
          if ( v19 )
          {
            if ( v16[5] == v19 + 84 )
              break;
          }
        }
        v18 = (_DWORD *)*v18;
      }
      while ( v18 != v9 );
      if ( v18 == v9 )
        return sub_811850();
    }
  }
  v11 = *v9;
  while ( v11 != v9 )
  {
    PiEnumerateProviderListEntry(v11, v23, 0);
    v11 = (_DWORD *)*v11;
    if ( v23[0] )
    {
      v13 = *(_DWORD *)(*(_DWORD *)(v23[0] + 176) + 20);
      if ( v13 )
      {
        if ( *(_DWORD *)(v13 + 8) )
        {
          v14 = *(int **)(v6 + 16);
          if ( v14 == v8 )
            goto LABEL_13;
          do
          {
            if ( v14[5] == v13 + 84 )
              break;
            v14 = (int *)*v14;
          }
          while ( v14 != v8 );
          if ( v14 == v8 )
          {
LABEL_13:
            v15 = ExAllocatePoolWithTag(512, 28, 1920421956);
            if ( !v15 )
            {
              v10 = -1073741670;
              break;
            }
            *(_BYTE *)(v15 + 24) = 1;
            *(_DWORD *)(v15 + 20) = v13 + 84;
            *(_DWORD *)(v15 + 8) = v6;
            v20 = (int *)v8[1];
            *(_DWORD *)v15 = v8;
            *(_DWORD *)(v15 + 4) = v20;
            if ( (int *)*v20 != v8 )
              __fastfail(3u);
            *v20 = v15;
            v8[1] = v15;
            v21 = (_DWORD *)(v15 + 12);
            v22 = *(_DWORD **)(v13 + 96);
            *v21 = v13 + 92;
            v21[1] = v22;
            if ( *v22 != v13 + 92 )
              __fastfail(3u);
            *v22 = v21;
            *(_DWORD *)(v13 + 96) = v21;
          }
        }
      }
    }
  }
  ExReleaseResourceLite((int)&PiDependencyRelationsLock);
  PpDevNodeUnlockTree(0);
  return v10;
}
