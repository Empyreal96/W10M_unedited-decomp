// DbgkpLkmdSqmStatus 
 
int __fastcall DbgkpLkmdSqmStatus(int a1, int a2, int *a3)
{
  if ( (a3[1] & 2) != 0 )
    DbgkpLkmdSqmIncrementDword(a1, a2, 3297);
  if ( (a3[1] & 8) != 0 )
    DbgkpLkmdSqmIncrementDword(a1, a2, 3298);
  if ( (a3[1] & 0x4000) != 0 )
    DbgkpLkmdSqmIncrementDword(a1, a2, 3294);
  if ( (a3[1] & 0x8000) != 0 )
    DbgkpLkmdSqmIncrementDword(a1, a2, 3295);
  if ( *a3 >= 0 )
    DbgkpLkmdSqmIncrementDword(a1, a2, 3296);
  return DbgkpLkmdSqmIncrementDword(a1, a2, 3293);
}
