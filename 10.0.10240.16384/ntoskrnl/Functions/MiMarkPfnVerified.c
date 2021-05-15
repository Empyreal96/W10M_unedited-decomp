// MiMarkPfnVerified 
 
int __fastcall MiMarkPfnVerified(int result, char a2)
{
  int v2; // r5
  unsigned int v4; // r9
  int v5; // r6
  unsigned __int8 *v6; // r1
  unsigned int v7; // r2
  unsigned int v8; // r1
  char v9; // r4
  unsigned int *v10; // r2
  unsigned int v11; // r0
  int v12[10]; // [sp+8h] [bp-28h] BYREF

  v2 = result;
  v4 = (int)((unsigned __int64)(715827883i64 * (result - MmPfnDatabase)) >> 32) >> 2;
  if ( (a2 & 4) != 0 )
  {
    v5 = 17;
  }
  else
  {
    result = KfRaiseIrql(2);
    v5 = result;
    v6 = (unsigned __int8 *)(v2 + 15);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 | 0x80, v6) );
    __dmb(0xBu);
    if ( v7 >> 7 )
      return sub_5211A8();
  }
  v8 = *(_DWORD *)(v2 + 20);
  v9 = BYTE2(MiFlags);
  if ( (HIBYTE(v8) & 7) != 3 )
  {
    if ( (a2 & 2) != 0 && (MiFlags & 0x30000) != 0 )
    {
      v12[1] = 0;
      if ( (BYTE2(MiFlags) & 3) == 1 )
        v12[0] = *(_DWORD *)(v2 + 4) << 10;
      result = KeSetPagePrivilege();
      if ( result < 0 )
        KeBugCheckEx(26, 333068, v4 + (v4 >> 31));
    }
    *(_DWORD *)(v2 + 20) = v8 & 0xF8FFFFFF | 0x3000000;
    v9 = BYTE2(MiFlags);
  }
  if ( (a2 & 1) != 0 && (v9 & 3) != 0 )
    result = MiGetPagePrivilege(v2, 1, v12);
  if ( v5 != 17 )
  {
    __dmb(0xBu);
    v10 = (unsigned int *)(v2 + 12);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 & 0x7FFFFFFF, v10) );
    result = KfLowerIrql(v5);
  }
  return result;
}
