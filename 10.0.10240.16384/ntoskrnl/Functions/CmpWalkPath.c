// CmpWalkPath 
 
int __fastcall CmpWalkPath(int a1, int a2, unsigned __int16 *a3)
{
  int v5; // r4
  int v6; // r0
  char v8[4]; // [sp+0h] [bp-30h] BYREF
  int v9; // [sp+4h] [bp-2Ch] BYREF
  int v10; // [sp+8h] [bp-28h] BYREF
  __int16 v11[4]; // [sp+10h] [bp-20h] BYREF
  __int16 v12[12]; // [sp+18h] [bp-18h] BYREF

  v5 = -1;
  v9 = -1;
  RtlInitUnicodeString((unsigned int)v12, a3);
  while ( 1 )
  {
    CmpGetNextName(v12, (int)v11, v8);
    if ( !v11[0] )
      break;
    v6 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, a2, &v9);
    if ( v6 )
    {
      CmpFindSubKeyByNameWithStatus(a1, v6, (int)v11, &v10);
      a2 = v10;
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v9);
      if ( a2 != -1 )
        continue;
    }
    return v5;
  }
  return a2;
}
