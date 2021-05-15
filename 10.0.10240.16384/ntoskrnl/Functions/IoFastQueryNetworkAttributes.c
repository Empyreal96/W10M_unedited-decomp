// IoFastQueryNetworkAttributes 
 
int __fastcall IoFastQueryNetworkAttributes(int a1, int a2, int a3, int a4, int a5)
{
  return IopFastQueryNetworkAttributes(a1, a2, *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A), a3, a4, a5);
}
