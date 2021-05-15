// sub_80117C 
 
void sub_80117C()
{
  int v0; // r4
  int v1; // r8
  _DWORD *v2; // r6
  int v3; // r0
  int v4; // lr
  unsigned int v5; // r1
  unsigned int i; // r3
  unsigned int v7; // r7
  int v8; // r6
  unsigned int v9; // r2

  v2 = (_DWORD *)(v0 + 68);
  v3 = ObFastReferenceObject((_DWORD *)(v0 + 68));
  if ( !v3 )
    v3 = CcSlowReferenceSharedCacheMapFileObject(v0);
  v4 = *(_DWORD *)(v3 + 12);
  __pld(v2);
  v5 = *v2;
  for ( i = *v2 ^ v3; i < 7; i = v7 ^ v3 )
  {
    __dmb(0xBu);
    do
      v7 = __ldrex(v2);
    while ( v7 == v5 && __strex(v5 + 1, v2) );
    if ( v7 == v5 )
      goto LABEL_11;
    v5 = v7;
  }
  ObDereferenceObjectDeferDelete(v3);
LABEL_11:
  v8 = *(__int64 *)(v0 + 8) >> 12;
  v9 = ((*(__int64 *)(v1 + 8) >> 12) & 0xFFFFFFC0) + 64;
  if ( (unsigned int)((*(_DWORD *)(v0 + 8) & 0xFFF) != 0) + v8 < v9 )
    v9 = ((*(_DWORD *)(v0 + 8) & 0xFFF) != 0) + v8;
  if ( v9 <= 1 )
    v9 = 1;
  PfCheckDeprioritizeFile(*(_DWORD *)(v0 + 360), v4, v9);
  JUMPOUT(0x73E2E4);
}
