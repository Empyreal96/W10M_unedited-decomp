// ObFastReferenceObjectLocked 
 
unsigned int __fastcall ObFastReferenceObjectLocked(_DWORD *a1)
{
  unsigned int v1; // r4

  v1 = *a1 & 0xFFFFFFF8;
  if ( v1 )
    ObfReferenceObject(*a1 & 0xFFFFFFF8);
  return v1;
}
