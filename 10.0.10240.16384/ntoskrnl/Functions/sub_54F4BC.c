// sub_54F4BC 
 
void sub_54F4BC()
{
  int v0; // r5
  int v1; // r6

  MiLockAndDecrementShareCount(v0, 0);
  MiLockAndDecrementShareCount(v1, 0);
  JUMPOUT(0x4EA13E);
}
