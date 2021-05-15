// PsReferenceProcessFilePointer 
 
int __fastcall PsReferenceProcessFilePointer(int a1, int *a2)
{
  unsigned int *v2; // r6
  unsigned int v4; // r5
  unsigned int v5; // r4
  int v7; // r0
  int v8; // r0
  int v9; // r0
  int v10; // r5
  unsigned int v11; // r4
  unsigned int v12; // r1
  unsigned int v13; // r4
  unsigned int v14; // r1

  v2 = (unsigned int *)(a1 + 172);
  __pld((void *)(a1 + 172));
  v4 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
  do
    v5 = __ldrex(v2);
  while ( v5 == v4 && __strex(v4 + 2, v2) );
  __dmb(0xBu);
  if ( v5 != v4 )
    return sub_7F64E4();
  v7 = *(_DWORD *)(a1 + 292);
  if ( !v7 )
  {
    __pld(v2);
    v13 = *v2 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v14 = __ldrex(v2);
    while ( v14 == v13 && __strex(v13 - 2, v2) );
    if ( v14 == v13 )
      JUMPOUT(0x7F64F8);
    JUMPOUT(0x7F64F2);
  }
  v8 = MiSectionControlArea(v7);
  v9 = MI_REFERENCE_CONTROL_AREA_FILE(v8);
  __pld(v2);
  v10 = v9;
  v11 = *v2 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v12 = __ldrex(v2);
  while ( v12 == v11 && __strex(v11 - 2, v2) );
  if ( v12 != v11 )
    ExfReleaseRundownProtection((unsigned __int8 *)v2);
  *a2 = v10;
  return 0;
}
