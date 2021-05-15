// MiDeletePagingFiles 
 
int __fastcall MiDeletePagingFiles(int a1)
{
  int v1; // r6
  int v2; // r4
  int v3; // r5
  unsigned int v4; // r0
  __int16 v5; // r3

  v1 = *(_DWORD *)(a1 + 3596);
  v2 = a1;
  v3 = 0;
  __dmb(0xBu);
  for ( ; v1; --v1 )
  {
    v4 = *(_DWORD *)(v2 + 3600);
    if ( v4 )
    {
      v5 = *(_WORD *)(v4 + 96);
      if ( (v5 & 0x10) == 0 && (v5 & 0x40) == 0 )
        v3 += *(_DWORD *)v4;
      MiDeletePagefile(v4);
    }
    v2 += 4;
  }
  return v3;
}
