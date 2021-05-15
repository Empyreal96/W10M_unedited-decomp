// IoGetOplockKeyContext 
 
int __fastcall IoGetOplockKeyContext(int a1)
{
  int v1; // r4
  int v2; // r0

  v1 = 0;
  v2 = IopGetFileObjectExtension(a1, 6, 0);
  if ( v2 && (*(_WORD *)(v2 + 2) & 2) != 0 )
    v1 = v2 + 20;
  return v1;
}
