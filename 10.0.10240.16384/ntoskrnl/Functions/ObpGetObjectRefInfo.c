// ObpGetObjectRefInfo 
 
int __fastcall ObpGetObjectRefInfo(int a1, unsigned int *a2)
{
  unsigned int v3; // r6
  unsigned int v4; // r9
  unsigned int v5; // r4
  int v6; // r2
  int v7; // r0
  int v8; // r5

  v3 = 0;
  v4 = (((unsigned int)(a1 + 24) >> 4) & 0xFFFFF) % 0x191;
  v5 = *(_DWORD *)(ObpObjectTable + 4 * v4);
  if ( v5 )
  {
    do
    {
      if ( *(_DWORD *)v5 == a1 )
        break;
      v3 = v5;
      v5 = *(_DWORD *)(v5 + 4);
    }
    while ( v5 );
    if ( v5 )
    {
      v6 = *(unsigned __int16 *)(v5 + 26);
      if ( *(unsigned __int16 *)(v5 + 24) == v6 )
      {
        v7 = ExAllocatePoolWithTag(512, 12 * v6 + 6172, 1951556175);
        v8 = v7;
        if ( !v7 )
          return -1073741801;
        memmove(v7, v5, 12 * *(unsigned __int16 *)(v5 + 24) + 28);
        *(_WORD *)(v8 + 26) += 512;
        if ( v3 )
          *(_DWORD *)(v3 + 4) = v8;
        else
          *(_DWORD *)(ObpObjectTable + 4 * v4) = v8;
        ExFreePoolWithTag(v5);
        v5 = v8;
      }
    }
  }
  *a2 = v5;
  return 0;
}
