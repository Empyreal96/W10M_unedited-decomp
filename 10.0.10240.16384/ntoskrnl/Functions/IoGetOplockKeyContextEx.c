// IoGetOplockKeyContextEx 
 
int __fastcall IoGetOplockKeyContextEx(int a1)
{
  int result; // r0

  if ( IopGetFileObjectExtension(a1, 6, 0) )
    result = sub_526A58();
  else
    result = 0;
  return result;
}
