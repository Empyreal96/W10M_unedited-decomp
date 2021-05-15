// FsRtlLookupLastMcbEntry 
 
int __fastcall FsRtlLookupLastMcbEntry(unsigned int *a1, _DWORD *a2, int *a3, int a4)
{
  int result; // r0
  int v7; // r3
  int v8[2]; // [sp+0h] [bp-18h] BYREF
  int v9[4]; // [sp+8h] [bp-10h] BYREF

  v8[0] = (int)a1;
  v8[1] = (int)a2;
  v9[0] = (int)a3;
  v9[1] = a4;
  result = FsRtlLookupLastLargeMcbEntry(a1, v8, v9, a4);
  if ( result )
  {
    *a2 = v8[0];
    v7 = v9[0];
    if ( v9[0] == -1 )
      v7 = 0;
    *a3 = v7;
  }
  return result;
}
