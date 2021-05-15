// EtwGetProcessorBuffer 
 
int __fastcall EtwGetProcessorBuffer(unsigned int a1, unsigned int a2, unsigned int **a3)
{
  int result; // r0
  int v6; // r2
  int v7; // r3
  int v8; // r3
  unsigned int *v9; // r1
  unsigned int v10; // r3
  unsigned int v11; // r2
  unsigned int v12; // r3

  result = 0;
  if ( !EtwpInitialized )
    return -1073741823;
  if ( a1 >= 0x40 )
    v6 = 1;
  else
    v6 = WmipLoggerContext[a1];
  if ( (v6 & 1) != 0 )
    return -1073741816;
  if ( *(_DWORD *)(v6 + 224) == 1 )
    return -1073741811;
  if ( (*(_DWORD *)(v6 + 12) & 0x10000000) != 0 )
  {
    v7 = *(_DWORD *)(v6 + 88);
  }
  else
  {
    if ( a2 >= KeNumberProcessors_0 )
      v8 = 0;
    else
      v8 = (int)*(&KiProcessorBlock + a2);
    v7 = *(_DWORD *)(*(_DWORD *)(v8 + 3596) + 4 * a1 + 128);
  }
  v9 = (unsigned int *)(v7 & 0xFFFFFFF8);
  if ( (v7 & 0xFFFFFFF8) == 0 )
    return -1073741823;
  v10 = *v9;
  v11 = v9[2];
  *a3 = v9;
  a3[1] = (unsigned int *)v10;
  __dmb(0xBu);
  if ( v11 <= *v9 )
  {
    v12 = v9[2];
    __dmb(0xBu);
  }
  else
  {
    v12 = v9[1];
  }
  a3[2] = (unsigned int *)v12;
  return result;
}
