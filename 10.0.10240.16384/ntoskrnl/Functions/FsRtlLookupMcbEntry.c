// FsRtlLookupMcbEntry 
 
int __fastcall FsRtlLookupMcbEntry(unsigned int **a1, int a2, int *a3, _DWORD *a4, int a5)
{
  int *v7; // r5
  int result; // r0
  int v9; // r3
  int v10[2]; // [sp+18h] [bp-20h] BYREF
  int v11[6]; // [sp+20h] [bp-18h] BYREF

  v10[0] = 0;
  v10[1] = 0;
  if ( a4 )
    v7 = v10;
  else
    v7 = 0;
  result = FsRtlLookupLargeMcbEntry(a1, a2, a2, 0, (int)v11, (int)v7, 0, 0, a5);
  if ( result )
  {
    v9 = v11[0];
    if ( v11[0] == -1 )
      v9 = 0;
    *a3 = v9;
    if ( a4 )
      *a4 = v10[0];
  }
  return result;
}
