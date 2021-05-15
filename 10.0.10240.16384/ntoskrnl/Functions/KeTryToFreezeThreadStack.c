// KeTryToFreezeThreadStack 
 
int __fastcall KeTryToFreezeThreadStack(int a1, _DWORD *a2, int a3, int a4)
{
  unsigned int *v6; // r5
  unsigned int v7; // r2
  int result; // r0
  int v9; // r0
  int v10; // r3
  _DWORD *v11; // r3
  _DWORD *v12; // [sp+0h] [bp-18h] BYREF
  int v13[5]; // [sp+4h] [bp-14h] BYREF

  v12 = a2;
  v13[0] = a3;
  v13[1] = a4;
  if ( *(_UNKNOWN **)(a1 + 336) == &KiInitialProcess )
    return 0;
  v6 = (unsigned int *)(a1 + 44);
  do
    v7 = __ldrex(v6);
  while ( __strex(1u, v6) );
  __dmb(0xBu);
  if ( v7 )
    return sub_51419C();
  v9 = KiAcquireThreadStateLock(a1, &v12, v13);
  if ( v9 < 0 )
    goto LABEL_19;
  if ( v9 <= 4 )
    goto LABEL_10;
  if ( v9 != 5 )
  {
    if ( v9 != 7 && v9 != 9 )
      goto LABEL_19;
    goto LABEL_10;
  }
  if ( !*(_BYTE *)(a1 + 135) || (*(_DWORD *)(a1 + 80) & 0x20) == 0 || *(char *)(a1 + 123) >= 25 || *(_BYTE *)(a1 + 73) )
  {
LABEL_10:
    v10 = (int)v12;
    if ( v12 )
    {
      __dmb(0xBu);
      *(_DWORD *)(v10 + 24) = 0;
    }
    v11 = (_DWORD *)v13[0];
    if ( v13[0] )
    {
      __dmb(0xBu);
      *v11 = 0;
    }
    __dmb(0xBu);
    *v6 = 0;
    return 0;
  }
LABEL_19:
  result = 1;
  *a2 = v12;
  return result;
}
