// KeGetCurrentThread 
 
unsigned int KeGetCurrentThread()
{
  return __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
}
