// ViAllocateContextTable 
 
int __fastcall ViAllocateContextTable(__int16 a1)
{
  int result; // r0

  result = ExAllocateFromNPagedLookasideList((int)&ViObjectContextTableLookaside);
  if ( result )
  {
    *(_WORD *)(result + 2) = 4;
    *(_DWORD *)(result + 4) = 0;
    *(_WORD *)result = a1;
    *(_DWORD *)(result + 8) = 0;
    *(_DWORD *)(result + 12) = 0;
  }
  return result;
}
