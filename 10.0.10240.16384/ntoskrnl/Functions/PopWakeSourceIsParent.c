// PopWakeSourceIsParent 
 
int __fastcall PopWakeSourceIsParent(int *a1, unsigned __int16 **a2)
{
  int *v3; // r3
  int *v5; // r4
  int v6; // r7
  int v7; // r8
  unsigned int v8; // r3
  int *v9; // r3

  v3 = (int *)a1[1];
  if ( !v3 )
    return 0;
  do
  {
    v5 = v3;
    v3 = (int *)v3[1];
  }
  while ( v3 );
  v6 = *(unsigned __int16 *)a2;
  v7 = IopRootDeviceNode;
  while ( 1 )
  {
    v8 = *((unsigned __int16 *)v5 + 10);
    if ( v8 == v6 && !wcsncmp((_WORD *)v5[6], a2[1], v8 >> 1) )
      break;
    v9 = (int *)*v5;
    if ( *v5 )
    {
      do
      {
        v5 = v9;
        v9 = (int *)v9[1];
      }
      while ( v9 );
    }
    else
    {
      v5 = (int *)v5[2];
      if ( v5 == (int *)v7 )
        v5 = 0;
      if ( v5 == a1 )
        v5 = 0;
    }
    if ( !v5 )
      return 0;
  }
  return 1;
}
