// PpmAcquireLock 
 
int __fastcall PpmAcquireLock(unsigned int *a1)
{
  int v2; // r3
  int result; // r0

  v2 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v2 & 0xFFFFFFC0) + 0x136);
  result = KeWaitForSingleObject(a1 + 1, 0, 0);
  *a1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  return result;
}
