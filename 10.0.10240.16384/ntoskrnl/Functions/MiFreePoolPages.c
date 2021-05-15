// MiFreePoolPages 
 
int __fastcall MiFreePoolPages(unsigned int a1, unsigned int a2)
{
  int result; // r0
  BOOL v5; // r4
  int v6; // r0
  int v7; // r2

  if ( a1 < dword_63389C
    || *((_BYTE *)&MiState[2423] + ((int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) != 5 )
  {
    return MiFreePagedPoolPages(a1, a2);
  }
  v5 = (a2 & 0xFFF) != 0;
  result = MiInsertNonPagedPoolOnSlist(a1, v5 + (a2 >> 12));
  if ( result != 1 )
  {
    v6 = MiClearNonPagedPtes(a1, v5 + (a2 >> 12));
    if ( v6 )
      MiReturnPhysicalPoolPages(v6);
    result = MiReturnNonPagedPoolVa(a1, v5 + (a2 >> 12), v7);
  }
  return result;
}
