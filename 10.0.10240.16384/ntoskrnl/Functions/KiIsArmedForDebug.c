// KiIsArmedForDebug 
 
int __fastcall KiIsArmedForDebug(int *a1, int *a2)
{
  unsigned int v3; // r4
  unsigned int v4; // r1
  int v5; // r2
  int v6; // t1
  unsigned int v7; // r1
  int v8; // r2
  int v9; // t1

  v3 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v4 = *(_DWORD *)(v3 + 2704);
  v5 = 0;
  if ( v4 )
  {
    while ( 1 )
    {
      v6 = *a1++;
      if ( (v6 & 1) != 0 )
        break;
      if ( ++v5 >= v4 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v7 = *(_DWORD *)(v3 + 2708);
    v8 = 0;
    if ( !v7 )
      return 0;
    while ( 1 )
    {
      v9 = *a2++;
      if ( (v9 & 1) != 0 )
        break;
      if ( ++v8 >= v7 )
        return 0;
    }
  }
  return 1;
}
