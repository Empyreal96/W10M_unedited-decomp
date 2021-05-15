// InbvDriverInitialize 
 
int __fastcall InbvDriverInitialize(int a1, int a2, int a3)
{
  int v6; // r4
  char *v8; // r0
  char *v9; // r0

  v6 = 1;
  if ( InbvDetermineFunction(a2) != 2 )
  {
    if ( BgkInitialize(a2, a1) < 0 )
      return sub_9675FC();
    BvgaSetDisplayOwnership(0);
    InbvSetFunction();
  }
  v8 = *(char **)(a2 + 120);
  if ( !v8 || (v9 = strupr(v8), !strstr(v9, "NOVGA")) )
    v6 = BvgaDriverInitialize(a1, a2, a3);
  return v6;
}
