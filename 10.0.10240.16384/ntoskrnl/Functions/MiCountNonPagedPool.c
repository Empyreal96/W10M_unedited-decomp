// MiCountNonPagedPool 
 
unsigned int __fastcall MiCountNonPagedPool(int a1, int a2)
{
  int v2; // r6
  unsigned int v3; // r5
  unsigned int v4; // r5
  unsigned int v5; // r4
  unsigned int v6; // r0

  v2 = a2;
  if ( a2 == 1 )
  {
    do
      v3 = __ldrex((unsigned int *)&dword_632A90);
    while ( __strex(v3 + a1, (unsigned int *)&dword_632A90) );
    v4 = v3 + a1;
  }
  else
  {
    a1 = -a1;
    do
    {
      v4 = __ldrex((unsigned int *)&dword_632A90);
      a2 = v4 + a1;
    }
    while ( __strex(v4 + a1, (unsigned int *)&dword_632A90) );
  }
  MiSignalNonPagedPoolWatchers(a1, a2, (int)&dword_632A90, 0);
  v5 = 0;
  if ( v2 == 1 )
  {
    v6 = MiFreePoolPagesLeft(5);
    if ( v4 < v6 + v4 )
      v5 = v6;
  }
  return v5;
}
