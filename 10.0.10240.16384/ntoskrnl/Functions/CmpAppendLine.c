// CmpAppendLine 
 
int __fastcall CmpAppendLine(_DWORD *a1, int a2, char a3)
{
  int v6; // r0
  int *v7; // r3

  if ( !a1[1] )
    return 0;
  v6 = ExAllocatePoolWithTag(1, 16, 1768967491);
  if ( !v6 )
    return 0;
  *(_DWORD *)v6 = 0;
  *(_DWORD *)(v6 + 4) = a2;
  *(_DWORD *)(v6 + 8) = 0;
  *(_BYTE *)(v6 + 12) = a3;
  v7 = (int *)a1[2];
  if ( v7 )
    *v7 = v6;
  else
    *(_DWORD *)(a1[1] + 8) = v6;
  a1[2] = v6;
  a1[3] = 0;
  return 1;
}
