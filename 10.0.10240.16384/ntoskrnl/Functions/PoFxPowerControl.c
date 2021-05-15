// PoFxPowerControl 
 
int __fastcall PoFxPowerControl(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  unsigned int *v8; // r0
  unsigned int v9; // r5
  int v11; // r4
  unsigned int *v12; // r2
  unsigned int v13; // r1
  unsigned int v14; // r1

  __dmb(0xBu);
  v8 = (unsigned int *)(a1 + 112);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 + 1, v8) );
  __dmb(0xBu);
  if ( *(_BYTE *)(a1 + 108) )
    return sub_51EE68();
  v11 = PopPepPowerControlRequest(*(_DWORD *)(a1 + 32), a2, a3, a4, a5, a6, a7, a4);
  __dmb(0xBu);
  v12 = (unsigned int *)(a1 + 112);
  do
  {
    v13 = __ldrex(v12);
    v14 = v13 - 1;
  }
  while ( __strex(v14, v12) );
  __dmb(0xBu);
  if ( !v14 )
    KeSetEvent(a1 + 116, 0, 0);
  return v11;
}
