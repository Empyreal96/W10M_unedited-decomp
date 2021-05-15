// MiExpandFlushMdl 
 
int __fastcall MiExpandFlushMdl(int a1, unsigned int a2)
{
  unsigned int v3; // r6
  unsigned int v4; // r5
  int v5; // r0
  int v6; // r4

  v3 = *(_DWORD *)(a1 + 20);
  if ( v3 == 1048574 )
    return 0;
  v4 = 2 * v3;
  if ( 2 * v3 <= v3 || v4 > 0xFFFFE )
    return 0;
  if ( v4 > a2 )
    v4 = a2;
  v5 = ExAllocatePoolWithTag(512, 4 * (v4 + 7), 1816554829);
  v6 = v5;
  if ( !v5 )
    return 0;
  memmove(v5, a1, 4 * (v3 + 7));
  *(_DWORD *)(v6 + 24) = v4;
  return v6;
}
