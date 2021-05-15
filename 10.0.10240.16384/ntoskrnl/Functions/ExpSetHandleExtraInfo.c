// ExpSetHandleExtraInfo 
 
int __fastcall ExpSetHandleExtraInfo(int a1, unsigned int a2, int a3)
{
  int v3; // r8
  unsigned int *v6; // r0
  unsigned int *v7; // r5
  unsigned int v9; // r4
  _BYTE *v10; // r0
  unsigned int v11; // r2
  unsigned int *v12; // r2
  unsigned int v13; // r1

  v3 = (a2 >> 2) & 0x1FF;
  v6 = (unsigned int *)ExpLookupHandleTableEntry(a1, a2 & 0xFFFFF803);
  v7 = v6;
  if ( !v6 )
    return -1073741823;
  v9 = *v6;
  if ( !*v6 )
  {
    v10 = ExpAllocateTablePagedPool(*(_DWORD *)(a1 + 12), 2048);
    v9 = (unsigned int)v10;
    if ( !v10 )
      return -1073741670;
    __dmb(0xBu);
    do
      v11 = __ldrex(v7);
    while ( !v11 && __strex((unsigned int)v10, v7) );
    __dmb(0xBu);
    if ( v11 )
    {
      ExpFreeTablePagedPool(*(_DWORD *)(a1 + 12), (unsigned int)v10, 0x800u);
      v9 = *v7;
    }
    else
    {
      __dmb(0xBu);
      v12 = (unsigned int *)(a1 + 4);
      do
        v13 = __ldrex(v12);
      while ( __strex(v13 + 1, v12) );
      __dmb(0xBu);
    }
    if ( !v9 )
      return -1073741670;
  }
  *(_DWORD *)(v9 + 4 * v3) = a3;
  return 0;
}
