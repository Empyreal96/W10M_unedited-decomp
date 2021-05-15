// ViFreeMapRegistersToFile 
 
int __fastcall ViFreeMapRegistersToFile(int a1, __int16 a2, int a3)
{
  unsigned int v4; // r4
  int *v5; // r6
  int v7; // r3
  unsigned int *v8; // r2
  unsigned int v9; // r1

  if ( a3 )
  {
    v4 = ((a2 & 0xFFFu) + a3 + 4095) >> 12;
    if ( v4 >= *(_DWORD *)(a1 + 20) )
      v4 = *(_DWORD *)(a1 + 20);
  }
  else
  {
    v4 = *(_DWORD *)(a1 + 20);
    if ( v4 > 1 )
      v4 = 1;
  }
  v5 = ViFindMappedRegisterInFile(a1, a2, 0);
  if ( !v5 )
    return 0;
  for ( ; v4; --v4 )
  {
    if ( !*v5 )
      break;
    ViCheckTag((_BYTE *)(v5[3] + (*v5 & 0xFFF) + 4096), v5[1], 1, 3);
    v7 = v5[2];
    *v5 = 0;
    v5[1] = 0;
    v5[2] = v7 & 0xFFFFFFFC;
    __dmb(0xBu);
    v8 = (unsigned int *)(a1 + 20);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 - 1, v8) );
    __dmb(0xBu);
    v5 += 5;
  }
  return 1;
}
