// VfThunkRemoveTargetNotify 
 
unsigned int __fastcall VfThunkRemoveTargetNotify(unsigned int result)
{
  unsigned int *v1; // r4

  v1 = (unsigned int *)result;
  if ( (*(_DWORD *)(result + 8) & 1) == 0 )
  {
    ViThunkFreeSharedThunksArray((unsigned int *)(result + 8));
    ViThunkFreeSharedThunksArray(v1 + 3);
    ViThunkFreeSharedThunksArray(v1 + 4);
    result = ViThunkFreeSharedThunksArray(v1 + 5);
  }
  return result;
}
