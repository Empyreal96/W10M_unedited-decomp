// VfZwDeleteFile 
 
int __fastcall VfZwDeleteFile(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckObjectAttributes(a1);
  return pXdvZwDeleteFile(a1);
}
