// sub_552F40 
 
void sub_552F40()
{
  int v0; // r5
  unsigned int v1; // r6

  ExFreePoolWithTag(v0);
  MiReturnSystemVa(v1, v1 + 4096, 8, 0);
  JUMPOUT(0x4F2E2C);
}
