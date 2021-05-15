// VfRemoveContext 
 
int __fastcall VfRemoveContext(unsigned __int16 *a1)
{
  int v1; // r5
  int v3; // r3
  int v4; // r0
  unsigned int *v5; // r6
  unsigned int v6; // r7
  int v7; // r2
  unsigned int *v8; // r2
  unsigned int v9; // r1
  unsigned int v10; // r1
  unsigned int v11; // r2
  unsigned int *v12; // r2
  unsigned int v13; // r1
  unsigned int v14; // r1
  unsigned int *v15; // r2
  unsigned int v16; // r1
  unsigned int v17; // r1

  v1 = -1073741275;
  if ( !ViVerifierEnabled )
    return -1073741823;
  if ( !ViIsContextIdValid(*a1, a1[1]) )
    return -1073741811;
  v4 = ViGetContextPointer(*((_DWORD *)a1 + 2), v3);
  v5 = (unsigned int *)v4;
  if ( !v4 )
    return -1073741637;
  if ( ViLockContextPointer(v4) )
  {
    v6 = *v5;
    v7 = *v5 + 4 * a1[1];
    if ( *(unsigned __int16 **)(v7 + 8) != a1 )
      goto LABEL_19;
    *(_DWORD *)(v7 + 8) = 0;
    v1 = 0;
    __dmb(0xBu);
    v8 = (unsigned int *)(v6 + 4);
    do
    {
      v9 = __ldrex(v8);
      v10 = v9 - 1;
    }
    while ( __strex(v10, v8) );
    __dmb(0xBu);
    if ( v10 )
    {
LABEL_19:
      ViUnlockContextPointer(v5);
      if ( v1 >= 0 )
      {
        __dmb(0xBu);
        v15 = (unsigned int *)(a1 + 2);
        do
        {
          v16 = __ldrex(v15);
          v17 = v16 - 1;
        }
        while ( __strex(v17, v15) );
        __dmb(0xBu);
        if ( !v17 )
          (*((void (__fastcall **)(unsigned __int16 *))a1 + 3))(a1);
      }
    }
    else
    {
      __dmb(0xBu);
      do
        v11 = __ldrex(v5);
      while ( __strex(0, v5) );
      __dmb(0xBu);
      v12 = (unsigned int *)(a1 + 2);
      do
      {
        v13 = __ldrex(v12);
        v14 = v13 - 1;
      }
      while ( __strex(v14, v12) );
      __dmb(0xBu);
      if ( !v14 )
        (*((void (__fastcall **)(unsigned __int16 *))a1 + 3))(a1);
      ViFreeContextTable(v6);
      v1 = 0;
    }
  }
  return v1;
}
