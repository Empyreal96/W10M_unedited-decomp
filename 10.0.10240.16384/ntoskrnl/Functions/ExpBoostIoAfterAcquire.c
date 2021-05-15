// ExpBoostIoAfterAcquire 
 
int __fastcall ExpBoostIoAfterAcquire(int result, int a2)
{
  int v2; // r5
  __int16 v3; // r3
  int v5; // r2
  int v6; // r6
  int v7; // r0
  int v8; // r5
  char v9[32]; // [sp+8h] [bp-20h] BYREF

  v2 = result;
  v3 = *(_WORD *)(result + 14);
  if ( (v3 & 8) == 0 && (v3 & 4) != 0 )
  {
    v5 = (*(_DWORD *)(a2 + 960) >> 9) & 7;
    if ( (*(_DWORD *)(*(_DWORD *)(a2 + 336) + 192) & 0x100000) != 0 )
      v5 = 0;
    if ( v5 < 2 )
    {
      v6 = 0;
      ExpLockResource(result, v9);
      v7 = ExpFindCurrentThread(v2, a2, v9, 0, 1);
      v8 = v7;
      if ( (*(_DWORD *)(v7 + 4) & 1) == 0 )
      {
        v7 = PsBoostThreadIoEx(a2, 0, 0);
        *(_DWORD *)(v8 + 4) |= 1u;
        v6 = 1;
      }
      result = ExpUnlockResource(v7, v9);
      if ( v6 )
        result = IoBoostThreadIoPriority(a2, 2, 0);
    }
  }
  return result;
}
