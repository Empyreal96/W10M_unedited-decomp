// sub_7FD214 
 
void __fastcall sub_7FD214(int a1, int a2, int a3, int a4)
{
  int *v4; // r6
  int v5; // r1
  unsigned int v6; // r0
  unsigned int v7; // r2

  if ( *(_DWORD *)(a4 + 3232) == a2 )
  {
    __pld(v4);
    v5 = *v4;
    if ( (*v4 & 0xFFFFFFF0) <= 0x10 )
      v6 = 0;
    else
      v6 = v5 - 16;
    if ( (v5 & 2) != 0 )
      goto LABEL_10;
    __dmb(0xBu);
    do
      v7 = __ldrex((unsigned int *)v4);
    while ( v7 == v5 && __strex(v6, (unsigned int *)v4) );
    if ( v7 != v5 )
LABEL_10:
      ExfReleasePushLock(v4, v5);
    KeAbPostRelease((unsigned int)v4);
    JUMPOUT(0x732D5C);
  }
  JUMPOUT(0x732DB6);
}
