// KiSelectProcessorToPreempt 
 
int __fastcall KiSelectProcessorToPreempt(int a1, int a2, int a3, int a4)
{
  int v4; // r6
  int v7; // r9
  int v8; // r3
  unsigned int v9; // r4
  unsigned int v10; // r5
  unsigned int v11; // r0
  int v12; // r4
  int v13; // r1
  unsigned int v14; // r2
  _BYTE v16[64]; // [sp-4h] [bp-40h] BYREF

  v4 = a2;
  v7 = *(_DWORD *)(a2 + 3456) & a3;
  if ( ((v7 - 1) & v7) == 0 )
    return v4;
  v8 = *(_DWORD *)(a2 + 3460);
  v9 = *(unsigned __int8 *)(v8 + 296);
  v10 = *(unsigned __int8 *)(v8 + 297);
  memmove((int)&v16[v10], v8 + 264, v9);
  v11 = v10 + v9;
  v12 = *(char *)(a1 + 123);
  v13 = -1;
  if ( a4 )
  {
    v14 = v10;
    if ( v10 >= v11 )
      goto LABEL_15;
    do
    {
      if ( ((1 << v14) & a4) != 0 && (char)v16[v14] < v12 )
      {
        v12 = (char)v16[v14];
        v13 = v14;
      }
      ++v14;
    }
    while ( v14 < v11 );
    if ( v13 >= 0 )
      return (int)*(&KiProcessorBlock + v13);
  }
  while ( v10 < v11 )
  {
    if ( ((1 << v10) & v7) != 0 && (char)v16[v10] < v12 )
    {
      v12 = (char)v16[v10];
      v13 = v10;
    }
    ++v10;
  }
LABEL_15:
  if ( v13 >= 0 )
    return (int)*(&KiProcessorBlock + v13);
  return v4;
}
