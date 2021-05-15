// CmpAppendSection 
 
int __fastcall CmpAppendSection(int a1, unsigned __int8 *a2, char a3)
{
  _DWORD *v6; // r4
  unsigned __int8 *v7; // r0
  int v9; // r0
  int v10; // r4

  if ( !a1 || !a2 )
    return 0;
  v6 = *(_DWORD **)a1;
  if ( *(_DWORD *)a1 )
  {
    do
    {
      v7 = (unsigned __int8 *)v6[1];
      if ( v7 && !stricmp(v7, a2) )
        break;
      v6 = (_DWORD *)*v6;
    }
    while ( v6 );
    if ( v6 )
      return sub_96C040();
  }
  v9 = ExAllocatePoolWithTag(1, 16, 1768967491);
  v10 = v9;
  if ( !v9 )
    return 0;
  *(_DWORD *)v9 = 0;
  *(_DWORD *)(v9 + 8) = 0;
  *(_DWORD *)(v9 + 4) = a2;
  *(_BYTE *)(v9 + 12) = a3;
  *(_DWORD *)v9 = *(_DWORD *)a1;
  *(_DWORD *)a1 = v9;
  if ( !strnicmp(a2, "Strings", 7) && (a2[7] == 0) > *(int *)(a1 + 16) )
    *(_DWORD *)(a1 + 20) = v10;
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 4) = v10;
  *(_DWORD *)(a1 + 12) = 0;
  return 1;
}
