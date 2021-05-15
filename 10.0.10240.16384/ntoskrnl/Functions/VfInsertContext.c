// VfInsertContext 
 
int __fastcall VfInsertContext(unsigned __int16 *a1)
{
  int v2; // r4
  int v3; // r3
  unsigned int *v4; // r5
  unsigned int v5; // r0
  unsigned int v6; // r2
  unsigned int v7; // r2
  int v8; // r1
  unsigned int *v9; // r2
  unsigned int v10; // r1
  unsigned int *v11; // r2
  unsigned int v12; // r1

  if ( !ViVerifierEnabled )
    return -1073741823;
  if ( !ViIsContextIdValid(*a1, a1[1]) )
    return -1073741811;
  v4 = (unsigned int *)ViGetContextPointer(*((_DWORD *)a1 + 2), v3);
  if ( !v4 )
    return -1073741637;
  while ( !ViLockContextPointer(v4) )
  {
    v5 = ViAllocateContextTable(*a1);
    if ( !v5 )
      return -1073741670;
    do
      v6 = __ldrex(v4);
    while ( !v6 && __strex(v5, v4) );
    __dmb(0xBu);
    if ( !v6 )
      break;
    ViFreeContextTable();
  }
  v7 = *v4;
  v8 = *v4 + 4 * a1[1];
  if ( *(_DWORD *)(v8 + 8) )
  {
    v2 = -1073741270;
  }
  else
  {
    *(_DWORD *)(v8 + 8) = a1;
    __dmb(0xBu);
    v9 = (unsigned int *)(v7 + 4);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 + 1, v9) );
    __dmb(0xBu);
    v11 = (unsigned int *)(a1 + 2);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 + 1, v11) );
    __dmb(0xBu);
    v2 = 0;
  }
  ViUnlockContextPointer(v4);
  return v2;
}
