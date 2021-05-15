// ExpUuidGetValues 
 
int __fastcall ExpUuidGetValues(int a1, unsigned int a2, __int64 a3)
{
  int v4; // r3
  int result; // r0
  unsigned int v6; // r0
  unsigned int v7; // r1
  unsigned int v8; // r4
  char v9; // r2
  unsigned int *v10; // r2
  unsigned int v11; // r1
  int v12; // [sp+0h] [bp-18h] BYREF
  unsigned int v13; // [sp+4h] [bp-14h] BYREF
  __int64 v14; // [sp+8h] [bp-10h] BYREF

  v13 = a2;
  v14 = a3;
  v4 = ExpAllocateUuids((int)&v14, &v13, &v12, SHIDWORD(a3), a1);
  result = -1073741267;
  if ( v4 != -1073741267 )
  {
    if ( v4 < 0 )
    {
      result = -1073741801;
    }
    else
    {
      v6 = v13;
      v9 = v12;
      v7 = (unsigned __int64)(v14 + 5748192000000000i64) >> 32;
      v8 = v14 + 1044561920;
      *(_BYTE *)(a1 + 12) = BYTE1(v12) & 0x3F | 0x80;
      *(_BYTE *)(a1 + 13) = v9;
      *(_QWORD *)a1 = __PAIR64__(v7, v6 - 1) + v8;
      __dmb(0xBu);
      v10 = (unsigned int *)(a1 + 8);
      do
        v11 = __ldrex(v10);
      while ( __strex(v6, v10) );
      __dmb(0xBu);
      result = 0;
    }
  }
  return result;
}
