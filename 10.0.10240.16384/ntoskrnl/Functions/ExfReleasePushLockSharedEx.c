// ExfReleasePushLockSharedEx 
 
int __fastcall ExfReleasePushLockSharedEx(_DWORD *a1, int a2)
{
  unsigned int v4; // r0
  unsigned int v5; // r1
  unsigned int v6; // r2
  unsigned int i; // r3
  int v8; // r2
  unsigned int *v9; // r2
  unsigned int v10; // r1
  signed int v11; // r1
  int v12; // r2
  int v13; // r3
  unsigned int v14; // r4
  unsigned int v15; // r1
  _DWORD *v16; // [sp+0h] [bp-28h]

  v16 = a1;
  if ( a2 )
    return sub_51E6FC();
  __pld(a1);
  v4 = *a1;
  if ( (*a1 & 2) == 0 )
  {
    do
    {
      v5 = v4 - 16;
      if ( (v4 & 0xFFFFFFF0) == 16 )
        v5 = 0;
      __dmb(0xBu);
      do
        v6 = __ldrex(a1);
      while ( v6 == v4 && __strex(v5, a1) );
      __dmb(0xBu);
      if ( v6 == v4 )
        return (int)v16;
      v4 = v6;
    }
    while ( (v6 & 2) == 0 );
  }
  if ( (v4 & 8) == 0 )
  {
    v12 = -1;
LABEL_21:
    while ( 1 )
    {
      v13 = (v4 & 4) != 0 || (v4 & 2) == 0 ? v12 : v12 + 4;
      v14 = v13 + v4;
      __dmb(0xBu);
      do
        v15 = __ldrex(a1);
      while ( v15 == v4 && __strex(v14, a1) );
      __dmb(0xBu);
      if ( v15 == v4 )
        break;
      v4 = v15;
    }
    if ( (v4 & 4) == 0 && (v4 & 2) != 0 )
      ExpWakePushLock(a1, v14);
    return (int)v16;
  }
  for ( i = v4 & 0xFFFFFFF0; ; i = *(_DWORD *)(i + 16) )
  {
    v8 = *(_DWORD *)(i + 20);
    if ( v8 )
      break;
  }
  __dmb(0xBu);
  v9 = (unsigned int *)(v8 + 28);
  do
  {
    v10 = __ldrex(v9);
    v11 = v10 - 1;
  }
  while ( __strex(v11, v9) );
  __dmb(0xBu);
  if ( v11 <= 0 )
  {
    v12 = -9;
    goto LABEL_21;
  }
  return (int)v16;
}
