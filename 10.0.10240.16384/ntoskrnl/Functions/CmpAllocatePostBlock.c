// CmpAllocatePostBlock 
 
int __fastcall CmpAllocatePostBlock(int a1, int a2, int a3, int a4)
{
  _DWORD *v8; // r0
  _DWORD *v9; // r4
  int v10; // r3
  _DWORD *v11; // r0
  int v13; // r0
  _DWORD *v14; // r3

  v8 = (_DWORD *)ExAllocatePoolWithQuotaTag(9u, 0x24u, 1651526979);
  v9 = v8;
  if ( !v8 )
    JUMPOUT(0x806B2C);
  v8[7] = a1 | a2;
  if ( ((a1 | a2) & 0x10000) != 0 )
  {
    v8[6] = 0;
    if ( a1 == 4 || a1 == 3 )
      v10 = 1;
    else
      v10 = 512;
    v11 = (_DWORD *)ExAllocatePoolWithQuotaTag(v10 | 8, 0x3Cu, 875842883);
    v9[8] = v11;
    if ( !v11 )
      return sub_806B24();
    if ( a1 == 1 )
    {
      KeInitializeEvent((int)v11, 1, 0);
    }
    else if ( a1 == 3 )
    {
      *v11 = 0;
      v11[1] = 0;
      v11[2] = 0;
    }
  }
  else
  {
    v8[8] = *(_DWORD *)(a4 + 32);
    v13 = ExAllocatePoolWithQuotaTag(0x109u, 0xCu, 892620099);
    v9[6] = v13;
    if ( !v13 )
      return sub_806B24();
    *(_DWORD *)(v13 + 8) = a3;
    v14 = (_DWORD *)v9[6];
    *v14 = v14;
    v14[1] = v14;
  }
  return (int)v9;
}
