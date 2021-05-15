// sub_8E5180 
 
void sub_8E5180()
{
  unsigned int *v0; // r4
  unsigned int *v1; // r6

  ViThunkFreeSharedThunksArray(v1);
  ViThunkFreeSharedThunksArray(v0 + 3);
  ViThunkFreeSharedThunksArray(v0 + 4);
  ViThunkFreeSharedThunksArray(v0 + 5);
  v0[2] |= 1u;
  JUMPOUT(0x8E4C72);
}
