// IopQueryConflictFillString 
 
int __fastcall IopQueryConflictFillString(_DWORD *a1, int a2, unsigned int *a3, int *a4)
{
  unsigned int v4; // r7
  int v5; // r5
  unsigned int v9; // r10
  int v10; // r3
  unsigned __int16 *v11; // r4
  int v12; // r3
  int v13; // r2
  unsigned int v14; // r2

  v4 = 0;
  v5 = 0;
  v9 = 0;
  if ( a3 )
    v9 = *a3;
  if ( a4 )
    v5 = *a4;
  if ( a1 )
  {
    if ( (a1[7] & 0x1000) == 0 )
    {
      v10 = a1[2];
LABEL_8:
      if ( !v10 )
        goto LABEL_20;
      v11 = (unsigned __int16 *)(v10 + 28);
      v5 |= 1u;
      goto LABEL_15;
    }
    v12 = a1[44];
    if ( !v12 )
      goto LABEL_20;
    v13 = *(_DWORD *)(v12 + 20);
    if ( !v13 )
      goto LABEL_20;
    if ( v13 == IopRootDeviceNode )
    {
      v5 |= 2u;
    }
    else if ( !*(_DWORD *)(v13 + 8) )
    {
      v10 = *(_DWORD *)(v13 + 292);
      goto LABEL_8;
    }
    v11 = (unsigned __int16 *)(v13 + 20);
LABEL_15:
    if ( v11 )
    {
      if ( a2 )
      {
        v14 = *v11;
        if ( 2 * v9 > v14 )
          memmove(a2, *((_DWORD *)v11 + 1), v14);
      }
      v4 = *v11 >> 1;
    }
  }
LABEL_20:
  if ( a2 && v9 > v4 )
    *(_WORD *)(a2 + 2 * v4) = 0;
  if ( a3 )
    *a3 = v4 + 1;
  if ( a4 )
    *a4 = v5;
  return 0;
}
