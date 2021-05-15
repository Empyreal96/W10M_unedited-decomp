// PfpUpdateRepurposedByPrefetch 
 
int __fastcall PfpUpdateRepurposedByPrefetch(int a1, unsigned int a2, int a3)
{
  int v5; // r4
  unsigned int v6; // r1
  unsigned int v7; // r4
  unsigned int v9; // r0
  int v10; // [sp-4h] [bp-70h] BYREF
  char v11[52]; // [sp+4h] [bp-68h] BYREF
  char v12[52]; // [sp+38h] [bp-34h] BYREF

  MmQueryMemoryListInformation((int)v11, 0x58u, a3, &v10);
  v5 = PfpGetPageListCount((int)v12, 0, 7u);
  v7 = v5 - PfpGetPageListCount(a1 + 52, v6, 7u);
  if ( v7 > a2 )
    v7 = a2;
  if ( v7 )
  {
    __dmb(0xBu);
    do
      v9 = __ldrex((unsigned int *)&dword_637368);
    while ( __strex(v9 + v7, (unsigned int *)&dword_637368) );
    __dmb(0xBu);
  }
  return memmove(a1, (int)v11, 0x58u);
}
