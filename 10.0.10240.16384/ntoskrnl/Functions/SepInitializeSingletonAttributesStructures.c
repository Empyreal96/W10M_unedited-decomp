// SepInitializeSingletonAttributesStructures 
 
int SepInitializeSingletonAttributesStructures()
{
  int *v0; // r3
  int *v1; // r3
  _DWORD *v2; // r3
  int v3; // r5
  _BYTE *v5; // r0
  _BYTE *v6; // r6
  _DWORD *v7; // r0
  _DWORD *v8; // r3
  char *v9; // r0

  v0 = SepSingletonGlobal;
  __dmb(0xBu);
  *v0 = 0;
  v1 = SepSingletonGlobal;
  SepSingletonGlobal[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
  v2 = SeLuidToIndexMapping;
  *(_DWORD *)SeLuidToIndexMapping = 0;
  v2[1] = 0;
  if ( (SepTokenSingletonAttributesConfig & 3) == 3 )
  {
    v3 = ExAllocatePoolWithTag(1, 8, 1950639443);
    if ( !v3 )
      return sub_96C1B0();
    v5 = (_BYTE *)ExAllocatePoolWithTag(512, 1536, 1950639443);
    v6 = v5;
    if ( !v5 )
      JUMPOUT(0x96C1B4);
    memset(v5, 0, 1536);
    v7 = (_DWORD *)ExAllocatePoolWithTag(512, 4, 1950639443);
    SepSingletonGlobal[2] = (int)v7;
    if ( !v7 || (*v7 = v6, ++SepSingletonGlobal[1], !RtlpCreateHashTable((int *)SeLuidToIndexMapping + 1, 0x80u, 0, 0)) )
      JUMPOUT(0x96C1B8);
    v8 = SeLuidToIndexMapping;
    v9 = (char *)SeLuidToIndexMapping + 8;
    *((_DWORD *)SeLuidToIndexMapping + 2) = 64;
    v8[3] = v3;
    RtlClearAllBits((int)v9);
  }
  return 0;
}
