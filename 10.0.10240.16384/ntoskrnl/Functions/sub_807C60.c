// sub_807C60 
 
void sub_807C60()
{
  int v0; // r5
  int v1; // r6
  int v2; // r8
  unsigned int *v3; // r2
  unsigned int v4; // r7

  __dmb(0xBu);
  v3 = (unsigned int *)(*(_DWORD *)(v0 + 344) + 36 * v2);
  do
    v4 = __ldrex(v3);
  while ( __strex(0, v3) );
  __dmb(0xBu);
  EtwpUpdateSchematizedFilterData(*(_DWORD *)(v0 + 344) + 36 * v2, 0, 0, v1);
  if ( (v4 & 0x80000004) == -2147483644 )
    EtwpUpdatePidFilterData(*(_DWORD *)(v0 + 344) + 36 * v2, 0, v1);
  if ( (v4 & 0x80000008) == -2147483640 )
    EtwpUpdateStringFilterData(*(_DWORD *)(v0 + 344) + 36 * v2 + 8, 0, v1);
  if ( (v4 & 0x80000010) == -2147483632 )
    EtwpUpdateStringFilterData(*(_DWORD *)(v0 + 344) + 36 * v2 + 12, 0, v1);
  if ( (v4 & 0x80000020) == -2147483616 )
    EtwpUpdateStringFilterData(*(_DWORD *)(v0 + 344) + 36 * v2 + 16, 0, v1);
  if ( (v4 & 0x80001000) == -2147479552 )
    EtwpUpdatePerfectHashFunction(*(_DWORD *)(v0 + 344) + 36 * v2 + 20, 0, v1);
  if ( (v4 & 0x80000200) == -2147483136 )
    EtwpUpdatePerfectHashFunction(*(_DWORD *)(v0 + 344) + 36 * v2 + 24, 0, v1);
  if ( (v4 & 0x80000100) == -2147483392 )
    EtwpUpdatePerfectHashFunction(*(_DWORD *)(v0 + 344) + 36 * v2 + 28, 0, v1);
  JUMPOUT(0x759F8C);
}
