// SmArrayGrow 
 
int __fastcall SmArrayGrow(unsigned int a1, unsigned int a2, unsigned int *a3, int *a4)
{
  unsigned int v7; // r4
  int v9; // r9
  int v10; // r0
  int v11; // r5
  unsigned int v12; // r8
  int v13[8]; // [sp+0h] [bp-20h] BYREF

  v13[0] = (int)a3;
  v13[1] = (int)a4;
  if ( a1 >= *a3 )
  {
    v7 = 2 * *a3;
    if ( v7 < 8 )
      v7 = 8;
    if ( a1 >= v7 )
    {
      v7 = a1 + 8;
      if ( a1 + 8 < a1 )
        return 0;
    }
    if ( ULongLongToULong(v7 * a2, (v7 * (unsigned __int64)a2) >> 32, v13) < 0 )
      return 0;
    v9 = v13[0];
    v10 = ExAllocatePoolWithTag(512, v13[0]);
    v11 = v10;
    if ( !v10 )
      return 0;
    v12 = *a3 * a2;
    memset((_BYTE *)(v10 + v12), 0, v9 - v12);
    if ( v12 )
    {
      memmove(v11, *a4, v12);
      ExFreePoolWithTag(*a4);
    }
    *a4 = v11;
    *a3 = v7;
  }
  return 1;
}
