// CmpSnapshotTxOwnerArray 
 
int __fastcall CmpSnapshotTxOwnerArray(_DWORD *a1, unsigned int *a2, int **a3)
{
  unsigned int v7; // r4
  int v8; // r1
  int *v9; // r0
  unsigned int i; // r8

  if ( !*a1 )
    return -1073741811;
  v7 = *a1 & 0x7FFFFFFF;
  v8 = 4 * *a1;
  *a2 = 0;
  v9 = (int *)ExAllocatePoolWithTag(1, v8, 909397315);
  *a3 = v9;
  if ( !v9 )
    return -1073741670;
  if ( v7 == 1 )
  {
    *v9 = *(_DWORD *)(*(_DWORD *)(a1[1] + 28) + 32);
    ObfReferenceObject(**a3);
  }
  else
  {
    for ( i = 0; i < v7; ++i )
    {
      (*a3)[i] = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1[1] + 4 * i) + 28) + 32);
      ObfReferenceObject((*a3)[i]);
    }
  }
  *a2 = v7;
  return 0;
}
