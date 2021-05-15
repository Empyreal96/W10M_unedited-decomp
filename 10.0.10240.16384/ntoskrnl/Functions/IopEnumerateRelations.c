// IopEnumerateRelations 
 
BOOL __fastcall IopEnumerateRelations(int a1, int *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int v6; // r5
  unsigned int *v7; // r0
  unsigned int v8; // r1
  BOOL result; // r0

  *a3 = 0;
  if ( a4 )
    *a4 = 0;
  if ( a5 )
    *a5 = 0;
  v6 = *a2;
  if ( *a2 && !*(_BYTE *)(a1 + 4) )
    return 0;
  v7 = *(unsigned int **)a1;
  v8 = a2[1];
  if ( v8 >= *v7 || v6 < 0 )
    return 0;
  if ( v6 > 1 )
  {
    if ( v6 == 2 )
    {
      v8 = *v7 - v8 - 1;
      goto LABEL_11;
    }
    return 0;
  }
LABEL_11:
  result = PipDeviceObjectListElementAt(v7, v8, a3, a4, a5) >= 0;
  ++a2[1];
  return result;
}
