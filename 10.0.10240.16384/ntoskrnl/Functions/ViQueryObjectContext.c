// ViQueryObjectContext 
 
int __fastcall ViQueryObjectContext(int a1, int a2, int a3)
{
  int v4; // r4
  int *v5; // r0
  unsigned int *v6; // r5
  int v7; // r3
  unsigned int *v8; // r2
  unsigned int v9; // r1
  unsigned int v10; // r1

  v4 = 0;
  v5 = (int *)ViGetContextPointer(a1, a2);
  v6 = (unsigned int *)v5;
  if ( v5 && ViLockContextPointer(v5) )
  {
    v7 = *(_DWORD *)(*v6 + 4 * a3 + 8);
    if ( v7 )
    {
      v4 = *(_DWORD *)(*v6 + 4 * a3 + 8);
      __dmb(0xBu);
      v8 = (unsigned int *)(v7 + 4);
      do
        v9 = __ldrex(v8);
      while ( __strex(v9 + 1, v8) );
      __dmb(0xBu);
    }
    __dmb(0xBu);
    do
      v10 = __ldrex(v6);
    while ( __strex(v10 + 1, v6) );
    __dmb(0xBu);
  }
  return v4;
}
