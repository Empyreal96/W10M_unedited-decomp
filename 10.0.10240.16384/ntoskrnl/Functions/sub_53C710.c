// sub_53C710 
 
void sub_53C710()
{
  if ( !CcIsWriteBehindThreadpoolAtLowPriority() )
    JUMPOUT(0x49FE10);
  JUMPOUT(0x49FE0C);
}
