// ExDupHandleTable 
 
int __fastcall ExDupHandleTable(int a1, unsigned int *a2, unsigned int a3, _DWORD *a4, unsigned int **a5)
{
  unsigned int **v5; // r6
  unsigned int v6; // r7
  unsigned int v8; // r4
  int *v9; // r1
  int v10; // r2
  int v11; // t1
  unsigned int *v12; // r0
  int v13; // r2
  unsigned int i; // r3
  unsigned int v16; // r3

  v5 = a5;
  *a5 = 0;
  v6 = *a2;
  __dmb(0xBu);
  if ( !a3 )
  {
    if ( !v6 )
      goto LABEL_21;
    do
    {
      v8 = v6 - 2048;
      v9 = (int *)(ExpLookupHandleTableEntry(a2, v6 - 2048) + 4088);
      v10 = 511;
      do
      {
        v11 = *v9;
        v9 -= 2;
        if ( (v11 & 2) != 0 )
          break;
        --v10;
      }
      while ( v10 );
      if ( v10 )
        break;
      v6 -= 2048;
    }
    while ( v8 );
    v5 = a5;
LABEL_8:
    if ( v6 )
    {
      v12 = (unsigned int *)ExpAllocateHandleTable(a1, 0);
      *v5 = v12;
      if ( v12 )
      {
        for ( i = *v12; i < v6; i = **v5 )
        {
          if ( !ExpAllocateHandleTableEntrySlow((int *)*v5, 0, v13, i) )
            JUMPOUT(0x7DDDB2);
        }
        JUMPOUT(0x7DDDBE);
      }
      JUMPOUT(0x7DDDBA);
    }
LABEL_21:
    JUMPOUT(0x7DDDA2);
  }
  if ( (*a4 & 3) == 0 )
  {
    if ( a3 > 1 )
      JUMPOUT(0x7DDD84);
    v16 = a4[a3 - 1];
    if ( v16 < v6 )
    {
      v6 = v16 + 4;
      goto LABEL_8;
    }
  }
  return sub_7DDD80();
}
