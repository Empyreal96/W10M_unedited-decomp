// CmpAppendValue 
 
int __fastcall CmpAppendValue(int a1, int a2, char a3)
{
  int v6; // r0
  int *v7; // r3

  if ( !*(_DWORD *)(a1 + 8) )
    return 0;
  if ( !a2 )
    return 0;
  v6 = ExAllocatePoolWithTag(1, 12, 1768967491);
  if ( !v6 )
    return 0;
  *(_DWORD *)v6 = 0;
  *(_DWORD *)(v6 + 4) = a2;
  *(_BYTE *)(v6 + 8) = a3;
  v7 = *(int **)(a1 + 12);
  if ( v7 )
    *v7 = v6;
  else
    *(_DWORD *)(*(_DWORD *)(a1 + 8) + 8) = v6;
  *(_DWORD *)(a1 + 12) = v6;
  return 1;
}
