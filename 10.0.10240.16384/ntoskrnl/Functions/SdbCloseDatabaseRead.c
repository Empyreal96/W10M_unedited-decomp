// SdbCloseDatabaseRead 
 
unsigned int __fastcall SdbCloseDatabaseRead(unsigned int *a1)
{
  if ( a1[333] )
    return sub_7CE18C();
  AslFileMappingDelete(*a1);
  return ExFreePoolWithTag((unsigned int)a1);
}
