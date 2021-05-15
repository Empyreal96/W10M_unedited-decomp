// SepGetSidValuesDump 
 
int __fastcall SepGetSidValuesDump(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v2; // r7
  int v4; // r0
  int v5; // r5
  _DWORD *v6; // r9
  int v7; // r10
  int v8; // r8
  unsigned int v9; // r7
  int v10; // r4

  v2 = a2;
  *a2 = 0;
  if ( !a1 )
    return 0;
  if ( !a1[2] )
    return 0;
  v4 = ExAllocatePoolWithTag(1, *a1 - 12);
  v5 = v4;
  if ( !v4 )
    return 0;
  v6 = a1 + 3;
  v7 = v4;
  v8 = 0;
  if ( a1[2] )
  {
    v9 = 0;
    do
    {
      v10 = *((unsigned __int8 *)v6 + 1) + 2;
      RtlCopySid(4 * v10, v7, v6);
      ++v9;
      v7 += 4 * v10;
      v6 = (_DWORD *)((char *)v6 + ((4 * *((unsigned __int8 *)v6 + 1) + 11) & 0xFFFFFFFC));
      v8 += 4 * v10;
    }
    while ( v9 < a1[2] );
    v2 = a2;
  }
  *v2 = v8;
  return v5;
}
