// KiFlushRangeFilter 
 
int __fastcall KiFlushRangeFilter(int a1, unsigned int *a2, _DWORD *a3, _DWORD *a4)
{
  unsigned int v4; // r5
  unsigned int v5; // r6
  unsigned int v6; // r0

  if ( **(_DWORD **)a1 == -1073741819 )
  {
    v4 = *(_DWORD *)(*(_DWORD *)a1 + 24);
    v5 = (v4 + 4096) & 0xFFFFF000;
    v6 = *a3 + *a2;
    if ( v5 > v4 && v5 < v6 )
    {
      *a3 = v6 - v5;
      *a2 = v5;
      *a4 = 1;
    }
  }
  return 1;
}
