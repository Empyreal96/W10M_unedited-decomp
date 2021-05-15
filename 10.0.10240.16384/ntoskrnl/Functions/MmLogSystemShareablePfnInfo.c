// MmLogSystemShareablePfnInfo 
 
int __fastcall MmLogSystemShareablePfnInfo(int a1)
{
  unsigned int v1; // r4
  unsigned int v2; // r9
  unsigned int v3; // r10
  unsigned int *v4; // r8
  unsigned int v5; // r5
  int *v6; // r6
  int v7; // r3
  int result; // r0
  int v9; // r0
  int v10; // r3
  int v11; // [sp+0h] [bp-38h]
  _DWORD v13[12]; // [sp+8h] [bp-30h] BYREF

  v13[0] = 2;
  v13[1] = 3;
  v13[2] = 4;
  v11 = 0;
  v1 = 0;
  v2 = 0;
  v3 = 0;
  v4 = dword_634E00;
  if ( (unsigned int)dword_634E3C <= unk_634E40 )
    v5 = 64;
  else
    v5 = dword_634E3C - unk_634E40 + 64;
  v6 = v13;
  do
  {
    v7 = *v6;
    if ( *v6 == 2 )
    {
      v4 = dword_634E00;
    }
    else if ( v7 == 3 )
    {
      v4 = (unsigned int *)&dword_634E80;
    }
    else if ( v7 == 4 )
    {
      v4 = dword_634F00;
    }
    if ( v3 < v5 )
    {
      if ( v1 )
        ExFreePoolWithTag(v1);
      v11 = 24 * v5 + 8;
      result = ExAllocatePoolWithTag(512, v11, 1299674181);
      v1 = result;
      if ( !result )
        return result;
      v3 = v5;
    }
    memset((_BYTE *)v1, 0, v11);
    v9 = MiGetWorkingSetInfoEx((int)v4, (unsigned int *)v1, v11, 0);
    v10 = *(_DWORD *)(v1 + 4);
    if ( v9 >= 0 )
    {
      if ( v10 )
        EtwLogPfnInfoRundown(0, a1, v1);
      ++v2;
      ++v6;
    }
    else
    {
      v5 = v10 + 64;
    }
  }
  while ( v2 < 3 );
  return ExFreePoolWithTag(v1);
}
