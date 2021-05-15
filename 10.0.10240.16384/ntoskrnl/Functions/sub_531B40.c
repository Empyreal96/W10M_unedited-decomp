// sub_531B40 
 
void sub_531B40()
{
  int *v0; // r6
  int v1; // r10

  KeFlushMultipleRangeCurrentTb(v1, v0 + 5, *v0);
  JUMPOUT(0x48A23C);
}
