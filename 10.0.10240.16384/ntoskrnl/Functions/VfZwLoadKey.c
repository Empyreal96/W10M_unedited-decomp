// VfZwLoadKey 
 
int __fastcall VfZwLoadKey(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckObjectAttributes(a1);
    ViZwCheckObjectAttributes(a2);
  }
  return pXdvZwLoadKey(a1, a2);
}
