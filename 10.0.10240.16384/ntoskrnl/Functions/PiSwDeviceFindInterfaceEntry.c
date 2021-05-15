// PiSwDeviceFindInterfaceEntry 
 
int *__fastcall PiSwDeviceFindInterfaceEntry(int a1, int a2)
{
  int *v2; // r4
  int v4; // r5
  int *v5; // r6

  v2 = *(int **)(a1 + 100);
  v4 = 0;
  v5 = (int *)(a1 + 100);
  while ( v2 != v5 )
  {
    if ( !wcsicmp(a2, (unsigned __int16 *)v2[2]) )
      return v2;
    v2 = (int *)*v2;
  }
  return (int *)v4;
}
