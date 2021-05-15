// IoGetOplockFullFoExt 
 
int __fastcall IoGetOplockFullFoExt(int a1)
{
  int result; // r0

  if ( a1 )
    result = IopGetFileObjectExtension(a1, 6, 0);
  else
    result = 0;
  return result;
}
