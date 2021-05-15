// RtlpTraceDatabaseAllocate 
 
int __fastcall RtlpTraceDatabaseAllocate(int a1, char a2)
{
  int v4; // r0

  if ( (a2 & 4) == 0 )
    v4 = 1;
  else
    v4 = 512;
  return ExAllocatePoolWithTag(v4, a1);
}
