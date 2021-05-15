// sub_7BF0CC 
 
void sub_7BF0CC()
{
  int v0; // r4
  int v1; // r5

  EtwWrite(v1, v0, (int)POP_ETW_IO_COALESCING_ON, 0);
  JUMPOUT(0x6A263A);
}
