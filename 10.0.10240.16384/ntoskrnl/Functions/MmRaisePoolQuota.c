// MmRaisePoolQuota 
 
int __fastcall MmRaisePoolQuota(int a1, int a2, unsigned int a3, _DWORD *a4)
{
  unsigned int v5; // r4
  unsigned int v7; // r0
  unsigned int v8; // r2
  unsigned int v10; // r0
  unsigned int v11; // r2

  v5 = a3;
  if ( a1 == 1 )
  {
    if ( !a3 )
      v5 = 0x80000;
    v10 = MiFreePoolPagesLeft(6);
    v11 = 0x100000;
    if ( v5 >= 0x100000 )
      v11 = v5;
    if ( v10 > v11 >> 12 && dword_632D58 + v5 >= dword_632D58 )
    {
      dword_632D58 += v5;
      goto LABEL_9;
    }
  }
  else
  {
    if ( !a3 )
      v5 = 0x10000;
    v7 = MiFreePoolPagesLeft(5);
    v8 = 0x100000;
    if ( v5 >= 0x100000 )
      v8 = v5;
    if ( v7 > v8 >> 12 && dword_632D5C + v5 >= dword_632D5C )
    {
      dword_632D5C += v5;
LABEL_9:
      *a4 = a2 + v5;
      return 1;
    }
  }
  return 0;
}
