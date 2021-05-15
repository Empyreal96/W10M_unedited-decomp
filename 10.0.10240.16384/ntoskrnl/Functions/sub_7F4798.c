// sub_7F4798 
 
void __fastcall sub_7F4798(int a1, int a2, int a3, int a4, int a5, int a6, unsigned int a7)
{
  int v7; // r7
  unsigned int *v8; // r0
  unsigned int v9; // r4
  unsigned int v10; // r1

  v8 = (unsigned int *)(v7 + 172);
  __pld((void *)(v7 + 172));
  v9 = *(_DWORD *)(v7 + 172) & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v10 = __ldrex(v8);
  while ( v10 == v9 && __strex(v9 - 2, v8) );
  if ( v10 != v9 )
    ExfReleaseRundownProtection((unsigned __int8 *)v8);
  if ( a7 )
  {
    ExSweepHandleTable(a7);
    ExpRemoveHandleTable(a7);
    ExpFreeHandleTable(a7);
  }
  JUMPOUT(0x714EC0);
}
