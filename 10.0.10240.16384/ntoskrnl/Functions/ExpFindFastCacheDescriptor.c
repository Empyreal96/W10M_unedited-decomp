// ExpFindFastCacheDescriptor 
 
int __fastcall ExpFindFastCacheDescriptor(int a1, int a2)
{
  int v2; // r4
  int *v3; // r0
  int v4; // r3
  unsigned int v6; // r2
  unsigned int v7; // r0
  char v8[4]; // [sp+8h] [bp-10h] BYREF
  int v9; // [sp+Ch] [bp-Ch]

  v2 = 0;
  v3 = &dword_920288[10 * a1];
  v4 = v3[1];
  if ( v4 )
  {
    if ( *(_DWORD *)(v4 + 8) )
    {
      v8[0] = 1;
      v6 = v3[3];
      v9 = a2;
      v7 = bsearch((int)v8, v3[2], v6, 8, ExpFastCacheDescriptorCompare);
      if ( v7 )
        v2 = *(_DWORD *)(v7 + 4);
    }
  }
  return v2;
}
