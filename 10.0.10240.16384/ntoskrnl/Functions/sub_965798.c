// sub_965798 
 
void sub_965798()
{
  int v0; // r4
  int v1; // r5
  _DWORD *v2; // r6
  unsigned int *v3; // r7
  __int16 v4; // r8
  int v5; // r9
  unsigned int v6; // r2
  unsigned int v7; // r2
  int v8; // r3

  __dmb(0xBu);
  do
  {
    v6 = __ldrex(v3);
    v7 = v6 + 1;
  }
  while ( __strex(v7, v3) );
  __dmb(0xBu);
  v8 = v1 + 8 * (v7 & 0x3F);
  *(_DWORD *)(v8 + 4) = v0;
  *(_WORD *)(v8 + 2) = v4;
  *(_WORD *)v8 = 156;
  if ( (*v2 & v5) != 0 )
    KsepDebugPrint(0, (int)"KSE: KsepMatchInitAcpiOemInfo failed [0x%08x]\n");
  KsepLogError(0, (int)"KSE: KsepMatchInitAcpiOemInfo failed [0x%08x]\n", v0);
  JUMPOUT(0x9483A6);
}
