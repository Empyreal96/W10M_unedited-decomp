// PnpDequeuePendingSurpriseRemoval 
 
int __fastcall PnpDequeuePendingSurpriseRemoval(int result)
{
  int v1; // r1
  int *v2; // r4
  int **v3; // r2
  int *v4; // r2

  v1 = IopPendingSurpriseRemovals;
  if ( (int *)IopPendingSurpriseRemovals != &IopPendingSurpriseRemovals )
  {
    do
    {
      v2 = *(int **)v1;
      if ( *(_BYTE *)(v1 + 60) )
      {
        if ( *(_DWORD *)(**(_DWORD **)(v1 + 32) + 8) != ***(_DWORD ***)(v1 + 32) )
          return sub_8198A0();
        v3 = *(int ***)(v1 + 4);
        if ( v2[1] != v1 || *v3 != (int *)v1 )
          __fastfail(3u);
        *v3 = v2;
        v2[1] = (int)v3;
        v4 = *(int **)(result + 4);
        *(_DWORD *)v1 = result;
        *(_DWORD *)(v1 + 4) = v4;
        if ( *v4 != result )
          __fastfail(3u);
        *v4 = v1;
        *(_DWORD *)(result + 4) = v1;
      }
      v1 = (int)v2;
    }
    while ( v2 != &IopPendingSurpriseRemovals );
  }
  return result;
}
