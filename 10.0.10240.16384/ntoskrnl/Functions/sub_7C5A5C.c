// sub_7C5A5C 
 
void __fastcall sub_7C5A5C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  _DWORD *v11; // r5
  int v12; // r8
  int v13; // r9
  int v14; // r10
  int v15; // r3
  BOOL v16; // r4
  BOOL v17; // r3
  int v18; // r3
  int v19; // r2
  int v20; // r3
  unsigned int v21; // r3

  v15 = *(_DWORD *)(a4 + 4);
  v16 = (v15 & 2) != 0 && (v15 & 4) == 0;
  v17 = (v15 & 2) == 0 && (v15 & 4) != 0;
  if ( v16 || v17 )
  {
    v18 = 4 * *(unsigned __int8 *)(a1 + 1) + 11;
    if ( a6 )
    {
      if ( a2 )
      {
        *(_DWORD *)(a2 + 8 * *v11 + 8) = a11;
        *(_DWORD *)(a2 + 8 * *v11 + 4) = v13;
        RtlCopySid(v18 & 0xFFFFFFFC, v13, a1);
      }
      v19 = *(_DWORD *)(v14 + 148) + 8 * v12;
      v20 = *(_DWORD *)(v19 + 4);
      if ( v16 )
        v21 = v20 | 4;
      else
        v21 = v20 & 0xFFFFFFFB;
      *(_DWORD *)(v19 + 4) = v21;
    }
    ++*v11;
    JUMPOUT(0x6C561A);
  }
  JUMPOUT(0x6C5618);
}
