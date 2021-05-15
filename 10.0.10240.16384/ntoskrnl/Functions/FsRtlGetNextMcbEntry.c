// FsRtlGetNextMcbEntry 
 
int __fastcall FsRtlGetNextMcbEntry(unsigned int **a1, int a2, _DWORD *a3, int *a4, int *a5)
{
  int result; // r0
  int v8; // r2
  int v9; // r3
  int v10; // [sp+8h] [bp-28h] BYREF
  int v11; // [sp+10h] [bp-20h] BYREF
  int v12[6]; // [sp+18h] [bp-18h] BYREF

  result = FsRtlGetNextLargeMcbEntry(a1, a2, (int)&v10, (int)&v11, (int)v12);
  if ( result )
  {
    v8 = v11;
    v9 = v12[0];
    if ( v11 == -1 )
      v8 = 0;
    *a3 = v10;
    *a4 = v8;
    *a5 = v9;
  }
  return result;
}
