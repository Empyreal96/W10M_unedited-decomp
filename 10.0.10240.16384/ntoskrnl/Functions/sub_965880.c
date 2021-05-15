// sub_965880 
 
void __fastcall sub_965880(int a1)
{
  int v1; // r4
  _DWORD *v2; // r5
  unsigned int *v3; // r6
  __int16 v4; // r7
  int v5; // r8
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
  *(_DWORD *)(v8 + 4) = a1;
  *(_WORD *)(v8 + 2) = v4;
  *(_WORD *)v8 = 241;
  if ( (*v2 & v5) != 0 )
    KsepDebugPrint(12, (int)"Built-in Win7 version lie shims: failed to register.\n");
  KsepLogError(12, (int)"Built-in Win7 version lie shims: failed to register.\n");
  JUMPOUT(0x948664);
}
