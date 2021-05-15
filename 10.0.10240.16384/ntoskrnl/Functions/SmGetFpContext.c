// SmGetFpContext 
 
char *__fastcall SmGetFpContext(int a1)
{
  int v1; // r3

  if ( a1 )
    v1 = 6348;
  else
    v1 = 6284;
  return (char *)&SmGlobals + v1;
}
