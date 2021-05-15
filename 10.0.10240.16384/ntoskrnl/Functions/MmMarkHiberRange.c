// MmMarkHiberRange 
 
char *__fastcall MmMarkHiberRange(int a1, unsigned int a2, int a3)
{
  return PoSetHiberRange(
           a1,
           2,
           (const void *)(((a2 >> 10) & 0x3FFFFC) - 0x40000000),
           (const void *)((((a2 + a3) >> 10) & 0x3FFFFC) - ((a2 >> 10) & 0x3FFFFC)),
           543519824);
}
