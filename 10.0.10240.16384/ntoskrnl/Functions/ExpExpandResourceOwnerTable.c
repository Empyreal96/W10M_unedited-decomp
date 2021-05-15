// ExpExpandResourceOwnerTable 
 
int __fastcall ExpExpandResourceOwnerTable(int result, int a2, int a3, int a4)
{
  int v4; // r5
  int v6; // r9
  unsigned int v7; // r4
  int v8; // r6
  int v9; // r8
  int v10; // r0
  int v11; // r8
  int v12; // r0
  int v13; // r0
  int v14[8]; // [sp+0h] [bp-20h] BYREF

  v14[0] = a3;
  v14[1] = a4;
  v4 = *(_DWORD *)(result + 8);
  v6 = result;
  if ( v4 )
  {
    v7 = *(_DWORD *)(v4 + 4);
    v8 = v7 + 4;
    if ( v7 + 4 < v7 )
      return result;
    result = RtlULongLongToULong(8 * v8, (unsigned __int64)(unsigned int)v8 >> 29, v14);
    if ( result < 0 )
      return result;
    v9 = v14[0];
  }
  else
  {
    v7 = 0;
    v8 = 3;
    v9 = 24;
  }
  ExpUnlockResource(result, a2);
  v10 = ExAllocatePoolWithTag(512, v9, 1632920914);
  v11 = v10;
  if ( !v10 )
    return sub_54A854();
  memset((_BYTE *)(v10 + 8 * v7), 0, 8 * (v8 - v7));
  v12 = ExpLockResource(v6, a2);
  if ( v4 == *(_DWORD *)(v6 + 8) && (!v4 || v7 == *(_DWORD *)(v4 + 4)) )
  {
    v13 = memmove(v11, v4, 8 * v7);
    *(_DWORD *)(v11 + 4) = v8;
    *(_DWORD *)(v6 + 8) = v11;
    ExpUnlockResource(v13, a2);
    if ( v4 )
      ExFreePoolWithTag(v4, 0);
    if ( !v7 )
      LOBYTE(v7) = 1;
  }
  else
  {
    ExpUnlockResource(v12, a2);
    ExFreePoolWithTag(v11, 0);
  }
  *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x191) = v7;
  return ExpLockResource(v6, a2);
}
