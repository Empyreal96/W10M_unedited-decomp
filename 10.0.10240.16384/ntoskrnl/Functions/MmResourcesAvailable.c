// MmResourcesAvailable 
 
int __fastcall MmResourcesAvailable(char a1, unsigned int a2, int a3)
{
  unsigned int v5; // r7
  int v6; // r10
  int v7; // r0
  int v8; // r0
  unsigned int v9; // r1
  unsigned int v10; // r3

  v5 = ((a2 & 0xFFF) != 0) + (a2 >> 12);
  v6 = a1 & 1;
  if ( (a1 & 1) == 0 )
  {
    v7 = 5;
LABEL_3:
    v8 = MiFreePoolPagesLeft(v7);
    goto LABEL_4;
  }
  if ( (a1 & 0x20) == 0 )
  {
    v7 = 6;
    goto LABEL_3;
  }
  v8 = MI_FREE_PAGED_SESSION_POOL_PAGES_LEFT(a1);
LABEL_4:
  v9 = v8 << 12;
  if ( a3 == 16 )
    v10 = a2 + 0x80000;
  else
    v10 = a2 + 0x200000;
  if ( v10 > v9 )
    JUMPOUT(0x546134);
  if ( v6 && v5 > MiMaximumCommitmentAvailable() )
    return sub_546118();
  if ( a2 + 10485760 >= v9 )
    JUMPOUT(0x546124);
  return 1;
}
