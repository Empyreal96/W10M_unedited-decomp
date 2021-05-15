// IopRemoveDumpCapsuleSupport 
 
int IopRemoveDumpCapsuleSupport()
{
  if ( CapsuleTriageDumpBlockInitialized == 1 )
  {
    if ( CapsuleTriageDumpBlock )
    {
      ExFreePoolWithTag(CapsuleTriageDumpBlock, 0);
      CapsuleTriageDumpBlock = 0;
    }
    CapsuleTriageDumpBlockInitialized = 0;
  }
  return 0;
}
